///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra\xF0tija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas LithUSS.cpp
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "LithuanianTTS.h"

#include "../include/LithUSS_Error.h"
#include "../TextNormalization/TextNormalization.h"
#include "../Transcription/Transcription.h"
#include "../UnitSelection/UnitSelection.h"
#include "../RateChange/RateChange.h"

#include "fv2id.h"
#include "ilgiai.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TEXTBUFSIZE 10000
#define RULES2USE 75
#define MAX_FONEMU_SKAICIUS 170000 //did\xFEiausias galimas fonem\xF8 skai\xE8ius gars\xF8 baz\xEBje

char dbfv[MAX_FONEMU_SKAICIUS][4];
int dbilg[MAX_FONEMU_SKAICIUS];
long dbadr[MAX_FONEMU_SKAICIUS];
short *wholeinput;
char katLoaded[200];

void unloadLibraries()
{
	unloadTextNorm();
	unloadRateChange();
}

extern bool loadLUSS()
{
	wholeinput = NULL;
	katLoaded[0] = 0; // tuscia eilute ""

	return true;
}

extern void unloadLUSS()
{
	unloadLibraries();
}

extern int initLUSS(const char * szDataDirectory, const char *katVoice)
{
	if (katLoaded[0] == 0)
	{
		CHECK(initTextNorm(szDataDirectory, "rules.txt"));
	}

	//balsui specifiniu biblioteku perkrovimas
	if (strcmp(katLoaded, katVoice) != 0)
	{
		unloadRateChange();
		CHECK(initTranscrLUSS(katVoice)); // klaidu kodai -35...-36
		CHECK(initFaktoriai(katVoice)); // klaidu kodai -37...-38
		CHECK(initUnitSel(katVoice));

		loadRateChange();
		CHECK(initRateChange(katVoice, dbfv, dbilg, dbadr, &wholeinput)); // klaidu kodai -60...-79
	}

FINALLY:
	if (CHECK_FAILED){
		unloadLibraries();
		katLoaded[0] = 0;
	} else {
		strcpy(katLoaded, katVoice);
	}

	return CHECK_result;
}

//////////Funkcijos SAPI5 sasajai//////////////////////////////////////////////////////////////////////////////////////
extern int normalizeText1(char *text, char *normtextbuf, int bufsize, int *letPos)
{
	return normalizeText(text, normtextbuf, bufsize, letPos);
}

int spellText1(char *text, char *normtextbuf, int bufsize, int *letPos)
{
	return spellText(text, normtextbuf, bufsize, letPos);
}

extern int stressTranscr(char *sakinys, char *TrSakinys, int bufsize, unsigned short *unitsR, unsigned short *unitsRNextSep,
						 int *unitsLet, int *letPos)
{
	int rules2use = 1155 * RULES2USE / 100; //default 75% total_auto_rules
	if (strcmp(sakinys, " ") == 0)
		sakinys[0] = 0; //jei eilute tuscia arba tik neskaitytini simboliai

	int n = KircTranskr(sakinys, TrSakinys, bufsize, unitsR, unitsRNextSep, unitsLet, letPos, rules2use);
	return n;
}

extern int findUnits(unsigned short *unitsRows, unsigned short *unitsRowsNextSeparators,
					 int unitsRowsLength, unsigned int *retUnits, unsigned short *unitsDurr)
{
	//garsu id masyvas, skirtuku masyvas, masyvo dydis
	ilgiai(unitsRows, unitsRowsNextSeparators, unitsRowsLength, unitsDurr);

	unsigned int currentCost;
	int ret = selectUnits(unitsRows, unitsRowsNextSeparators, unitsDurr, unitsRowsLength, (int *)retUnits, (int *)&currentCost); //TODO: Check consistency
	if (ret != 0)
	{
		return -8;
	}

	return 0;
}

extern int synthesizePhoneme(int greicioKoef, int tonas, unsigned short unitsDurr, unsigned int retUnit, short *phoneme, unsigned int naujo_signalo_masyvo_ilgis)
{
	int ilgis = change_phoneme_rate(greicioKoef * unitsDurr * 22050 / 1000 / dbilg[retUnit], tonas, retUnit, phoneme, naujo_signalo_masyvo_ilgis);
	return ilgis;
}

////////////Pagrindine sintezavimo funkcija////////////////////////////////////////////////////////////////////////////////
//struct event {short Id; short phonviz; int charOffset; long signOffset;};

extern int synthesizeWholeText(char *tekstas, short *signbuf, unsigned int *signbufsize, event *evarr, int *evarrsize, int greitis, int tonas)
{
	int greitisM = greitis;
	if (greitisM > 300)
		greitisM = 300;
	if (greitisM < 30)
		greitisM = 30;

	int tonasM = tonas;
	if (tonasM > 133)
		tonasM = 133;
	if (tonasM < 75)
		tonasM = 75;

	int bufsize = TEXTBUFSIZE;
	char *normtextbuf = NULL;
	int *letPos = NULL;
	int lll = strlen(tekstas) + 1;
	if (bufsize < lll)
		bufsize = lll + 1;
	unsigned int ib = 0;
	int evnr = 0;
	int hr = NO_ERR;

	if (hr == NO_ERR)
	{
		normtextbuf = (char *)malloc(bufsize);
		if (normtextbuf == NULL)
		{
			hr = ERROR_LITHUSS_MEMORY_ALLOCATION;
		}
	}

	if (hr == NO_ERR)
	{
		letPos = (int *)malloc(bufsize * sizeof(int));
		if (letPos == NULL)
		{
			hr = ERROR_LITHUSS_MEMORY_ALLOCATION;
		}
	}

	if (hr == NO_ERR)
	{
		int retval = -1;
		int itcount = 0;
		while ((retval != NO_ERR) && (itcount < 5) && (hr == NO_ERR))
		{
			for (int jj = 0; jj < lll; jj++)
				letPos[jj] = jj;
			letPos[lll] = 0;

			retval = normalizeText(tekstas, normtextbuf, bufsize, letPos);
			if (retval != NO_ERR)
			{
				bufsize = bufsize * 2;
				normtextbuf = (char *)realloc(normtextbuf, bufsize);
				letPos = (int *)realloc(letPos, bufsize * sizeof(int));
				if ((normtextbuf == NULL) || (letPos == NULL))
				{
					//				spausdinti_loga("Nepavyko padidinti atminties normalizuotam tekstui arba raidziu poziciju masyvui");
					hr = ERROR_LITHUSS_MEMORY_REALLOCATION;
				}
				itcount++;
			}
		}
		if (itcount >= 5)
			hr = retval;
	}

	if (hr == NO_ERR)
	{
		char *pos = normtextbuf;
		char sakinys[200], TrSakinys[500];
		int n;

		while ((pos != (char *)1) && (hr == NO_ERR))
		{
			int hr2 = 0;
			int lp = (int)(pos - normtextbuf);
			n = sscanf(pos, "%[^\n]", sakinys);
			pos = strchr(pos, '\n') + 1;
			if (n < 0)
				break;
			if (n == 0)
				sakinys[0] = 0; //arba if(n == 0) continue; apsauga nuo tusciu eiluciu \n

			unsigned short unitsRows[128];
			unsigned short unitsRowsNextSeparators[128];
			int unitsLet[128];
			for (int ii = 0; ii < 128; ii++)
			{
				unitsRows[ii] = 0;
				unitsRowsNextSeparators[ii] = 0;
				unitsLet[ii] = 0;
			}

			int rules2use = 1155 * 75 / 100; //75% total_auto_rules
			if (strcmp(sakinys, " ") == 0)
				sakinys[0] = 0; //jei eilute tuscia arba tik neskaitytini simboliai

			int unitsRowsLength = KircTranskr(sakinys, TrSakinys, 500, unitsRows, unitsRowsNextSeparators, unitsLet, &letPos[lp], rules2use);
			hr2 = (unitsRowsLength <= 2);

			//cia galim modifikuoti TrSakinys

			unsigned int retUnits[128];
			unsigned int currentCost;
			unsigned short unitsDurr[128];

			if (hr2 == 0)
			{
				ilgiai(unitsRows, unitsRowsNextSeparators, unitsRowsLength, unitsDurr);

				hr2 = selectUnits(unitsRows, unitsRowsNextSeparators, unitsDurr, unitsRowsLength, (int *)retUnits, (int *)&currentCost); //TODO: Check consistency
				if (hr2 != NO_ERR)
					hr = hr2;
			}

			if ((hr2 == 0) && (evnr == 0))
			{
				//Pirmojo sakinio pradzia
				evarr[evnr].Id = 1;
				evarr[evnr].phonviz = unitsRows[0];
				evarr[evnr].charOffset = unitsLet[0];
				evarr[evnr].signOffset = ib;
				evnr++;
				if (evnr >= *evarrsize)
				{
					hr = ERROR_LITHUSS_EVENTS_ARRAY_OVERFLOW;
					break;
				}
			}

			if (hr2 == 0)
			{
				for (int i = 0; i < unitsRowsLength; i++)
				{
					int ilgis = synthesizePhoneme(greitisM, tonasM, unitsDurr[i], retUnits[i], &signbuf[ib], *signbufsize - ib);

					if (ilgis < 0)
					{
						//				Sintezuotas signalas netilpo i buferi
						hr = ilgis;
						hr2 = -1;
						break;
					}

					//			signbuf[ib-1]=16000; //pakeiciam viena taska, kad matytusi garsu ribos signale

					//Fonema
					evarr[evnr].Id = 4;
					evarr[evnr].phonviz = unitsRows[i];
					evarr[evnr].charOffset = unitsLet[i];
					evarr[evnr].signOffset = ib;
					evnr++;
					if (evnr >= *evarrsize)
					{
						hr = ERROR_LITHUSS_EVENTS_ARRAY_OVERFLOW;
						hr2 = -1;
						break;
					}

					ib += ilgis;

					if (unitsRowsNextSeparators[i] == '+')
					{
						//Zodzio riba
						evarr[evnr].Id = 2;
						evarr[evnr].phonviz = unitsRows[i + 1];
						evarr[evnr].charOffset = unitsLet[i + 1];
						evarr[evnr].signOffset = ib;
						evnr++;
						if (evnr >= *evarrsize)
						{
							hr = ERROR_LITHUSS_EVENTS_ARRAY_OVERFLOW;
							hr2 = -1;
							break;
						}
					}
				} //for pabaiga
			}
			if (hr2 == 0)
			{
				//Sakinio riba
				evarr[evnr].Id = 1;
				evarr[evnr].phonviz = unitsRows[unitsRowsLength - 1];
				evarr[evnr].charOffset = unitsLet[unitsRowsLength - 1];
				evarr[evnr].signOffset = ib;
				evnr++;
				if (evnr >= *evarrsize)
				{
					hr = ERROR_LITHUSS_EVENTS_ARRAY_OVERFLOW;
				}
			}
		} //while pabaiga
	}	 //if(hr == 0) pabaiga

	if (hr == NO_ERR)
	{
		*signbufsize = ib;
		*evarrsize = evnr;
	}

	if (normtextbuf != NULL)
	{
		free(normtextbuf);
		normtextbuf = NULL;
	}
	if (letPos != NULL)
	{
		free(letPos);
		letPos = NULL;
	}

	return hr;
}
