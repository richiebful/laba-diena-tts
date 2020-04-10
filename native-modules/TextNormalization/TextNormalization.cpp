///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra�tija.lt)
// Sintezatoriaus komponentas TextNormalization.dll
// Failas TextNormalization.cpp
// Autorius dr. Tomas Anbinderis
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "TextNormalization.h"
#include "stringWithLetterPosition.h"
#include "../include/LithUSS_Error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***abbLists;
char ***abbListsSubstitutions;
unsigned short **abbListsIsWithSep;
int *abbSizes;
int totalFileBuffers = 0;

extern BOOL loadTextNorm(char*)
{
	return TRUE;
}

extern void unloadTextNorm()
{
	for(int i=0; i<totalFileBuffers; i++)
	{
		for(int j=0; j<2048; j++)
		{
			delete[] abbLists[i][j];
			delete[] abbListsSubstitutions[i][j];
		}
		delete[] abbLists[i];
		delete[] abbListsSubstitutions[i];
		delete[] abbListsIsWithSep[i];
	}
	delete[] abbLists;
	delete[] abbListsSubstitutions;
	delete[] abbListsIsWithSep;
	delete[] abbSizes;
}

#define MAX_RULES 4*1024
string rulesArray[MAX_RULES];
int totalRules;

const char* SimbPavad(char Simb)
{
	switch (Simb)
	{
		case '!' : return "�AUKTU`KAS";
		case '\"': return "KABU`T�S";
		case '#' : return "NU`MERIS";
		case '$' : return "DO^LERIS";
		case '%' : return "PRO`CENTAS";
		case '&' : return "A^MPERSENDAS";
		case '\'': return "APOSTRO`FAS";
		case '(' : return "SKLIAU~STAI ATSIDA~RO";
		case ')' : return "SKLIAU~STAI U�SIDA~RO";
		case '*' : return "�VAIG�DU`T�";
		case '+' : return "PLIU`S";
		case ',' : return "KABLE~LIS";
		case '-' : return "MI`NUS";
		case '.' : return "TA~�KAS";
		case '/' : return "��AMBU`S";
		case '0' : return "NU`LIS";
		case '1' : return "VI^ENAS";
		case '2' : return "DU`";
		case '3' : return "TRY~S";
		case '4' : return "KETURI`";
		case '5' : return "PENKI`";
		case '6' : return "�E�I`";
		case '7' : return "SEPTYNI`";
		case '8' : return "A�TUONI`";
		case '9' : return "DEVYNI`";
		case ':' : return "DVI`TA�KIS";
		case ';' : return "KABLIA~TA�KIS";
		case '<' : return "MA�IAU~";
		case '=' : return "LY^GU";
		case '>' : return "DAUGIAU~";
		case '?' : return "KLAUSTU`KAS";
		case '@' : return "ETA`";
		case 'A' : return "�~";
		case 'B' : return "B�~";
		case 'C' : return "C�~";
		case 'D' : return "D�~";
		case 'E' : return "�~";
		case 'F' : return "E`F";
		case 'G' : return "G�~";
		case 'H' : return "H�~";
		case 'I' : return "I`";
		case 'J' : return "JO`T";
		case 'K' : return "K�~";
		case 'L' : return "E`L";
		case 'M' : return "E`M";
		case 'N' : return "E`N";
		case 'O' : return "O~";
		case 'P' : return "P�~";
		case 'Q' : return "K�~";
		case 'R' : return "E`R";
		case 'S' : return "E`S";
		case 'T' : return "T�~";
		case 'U' : return "U`";
		case 'V' : return "V�~";
		case 'W' : return "DVI`GUBA V�~";
		case 'X' : return "I`KS";
		case 'Y' : return "Y~ ILGO^JI";
		case 'Z' : return "Z�~";
		case '[' : return "LAU�TI`NIAI ATSIDA~RO";
		case '\\': return "A~TVIRK��IAS ��AMBU`S";
		case ']' : return "LAU�TI`NIAI U�SIDA~RO";
		case '^' : return "STOGE~LIS";
		case '_' : return "PABRAUKI`MAS";
		case '`' : return "KIR~TIS";
		case 'a' : return "�~";
		case 'b' : return "B�~";
		case 'c' : return "C�~";
		case 'd' : return "D�~";
		case 'e' : return "�~";
		case 'f' : return "E`F";
		case 'g' : return "G�~";
		case 'h' : return "H�~";
		case 'i' : return "I`";
		case 'j' : return "JO`T";
		case 'k' : return "K�~";
		case 'l' : return "E`L";
		case 'm' : return "E`M";
		case 'n' : return "E`N";
		case 'o' : return "O~";
		case 'p' : return "P�~";
		case 'q' : return "K�~";
		case 'r' : return "E`R";
		case 's' : return "E`S";
		case 't' : return "T�~";
		case 'u' : return "U`";
		case 'v' : return "V�~";
		case 'w' : return "DVI`GUBA V�~";
		case 'x' : return "I`KS";
		case 'y' : return "Y~ ILGO^JI";
		case 'z' : return "Z�~";
		case '{' : return "RIESTI`NIAI ATSIDA~RO";
		case '|' : return "VERTIKA~L�";
		case '}' : return "RIESTI`NIAI U�SIDA~RO";
		case '~' : return "TIL~D�";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "��~";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "�~";
		case '�' : return "Y~ NO^SIN�";
		case '�' : return "E`�";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "�~ ILGO^JI";
		case '�' : return "��~";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "��~";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "�~";
		case '�' : return "Y~ NO^SIN�";
		case '�' : return "E`�";
		case '�' : return "�~ NO^SIN�";
		case '�' : return "�~ ILGO^JI";
		case '�' : return "��~";
		case '\x80' : return "EU~RAS";
		case '\x84' : return "KABU`T�S ATSIDA~RO";
		case '\x8B' : return "LAU�TI`N�S ATSIDA~RO";
		case '\x93' : return "KABU`T�S U�SIDA~RO";
		case '\x96' : return "BR�K�NY~S";
		case '\x97' : return "I`LGAS BR�K�NY~S";
		case '\x9B' : return "LAU�TI`N�S U�SIDA~RO";
		case '\xA2' : return "CEN~TAS";		 //�
		case '\xA3' : return "SVA~RAS";		 //�
		case '\xA4' : return "VALIUTA`";	 //�
		case '\xA5' : return "JENA`";
		case '\xA6' : return "VERTIKA~L� SU TARPELIU`"; //�
		case '\xA7' : return "PARAGRA~FAS";	 //�
		case '\xA9' : return "A^UTORI� TE^IS�S"; //�
		case '\xAB' : return "DVI`GUBOS LAU�TI`N�S ATSIDA~RO";
		case '\xAE' : return "REGISTRU^OTA"; //�
		case '\xB0' : return "LA^IPSNIS";	 //�
		case '\xB1' : return "PLIU`S MI`NUS"; //�
		case '\xB6' : return "PASTRA^IPA";
		case '\xBB' : return "DVI`GUBOS LAU�TI`N�S U�SIDA~RO";
		case '\xBC' : return "VIENA` KETVIRTO^JI";	//�
		case '\xBD' : return "VIENA` ANTRO^JI";		//�
		case '\xBE' : return "TRY~S KETVIR~TOSIOS"; //�
		case '\xD7' : return "DA^UGINTI";	 //�
		case '\xF7' : return "DALI`NTI";	 //�

		default  : return "";
	}
}

char* Skaitmuo(char Sk)
{
  switch (Sk)
    {
      case '0' : return " NU`LIS";
      case '1' : return " VI^ENAS";
      case '2' : return " DU`";
      case '3' : return " TRY~S";
      case '4' : return " KETURI`";
      case '5' : return " PENKI`";
      case '6' : return " �E�I`";
      case '7' : return " SEPTYNI`";
      case '8' : return " A�TUONI`";
      case '9' : return " DEVYNI`";
      default : return "";
    }
}

int TrizSk(char TrSk[], char Eil[])
  {
  int J;
  if((TrSk[0]=='0')&&(TrSk[1]=='0')&&(TrSk[2]=='0')) return -1;

  if((TrSk[0]=='0')&&(TrSk[1]=='0')&&(TrSk[2]=='1')) return 3; //1000 tukstantis
  if((TrSk[1]=='1')||(TrSk[2]=='0')) J=2;                      //12000, 20000 tukstanciu
  else if(TrSk[2]=='1') J=0;                                   //21000 tukstantis
  else J=1;                                                    //22000 tukstanciai

  if (TrSk[0] == '1')
    strcat(Eil, " �IM~TAS");
  else
    if (TrSk[0] != '0')
      {
      strcat(Eil, Skaitmuo(TrSk[0]));
      strcat(Eil, " �IMTAI~");
      }
  if (TrSk[1] == '1')
    {
    switch (TrSk[2])
      {
	  case '0' : { strcat(Eil, " DE~�IMT");break;}
	  case '1' : { strcat(Eil, " VIENU^OLIKA");break;}
	  case '2' : { strcat(Eil, " DVY^LIKA");break;}
	  case '3' : { strcat(Eil, " TRY^LIKA");break;}
	  case '4' : { strcat(Eil, " KETURIO^LIKA");break;}
	  case '5' : { strcat(Eil, " PENKIO^LIKA");break;}
	  case '6' : { strcat(Eil, " �E�IO^LIKA");break;}
	  case '7' : { strcat(Eil, " SEPTYNIO^LIKA");break;}
	  case '8' : { strcat(Eil, " A�TUONIO^LIKA");break;}
	  case '9' : { strcat(Eil, " DEVYNIO^LIKA");}
	  }
    }
  else
    {
    switch (TrSk[1])
      {
	  case '2' : { strcat(Eil, " DVI`DE�IMT");break;}
	  case '3' : { strcat(Eil, " TRI`SDE�IMT");break;}
	  case '4' : { strcat(Eil, " KE~TURIASDE�IMT");break;}
	  case '5' : { strcat(Eil, " PEN~KIASDE�IMT");break;}
	  case '6' : { strcat(Eil, " �E~�IASDE�IMT");break;}
	  case '7' : { strcat(Eil, " SEPTY^NIASDE�IMT");break;}
	  case '8' : { strcat(Eil, " A�TU^ONIASDE�IMT");break;}
	  case '9' : { strcat(Eil, " DEVY^NIASDE�IMT");}
      }
    if (TrSk[2] != '0') strcat(Eil, Skaitmuo(TrSk[2]));
    }
return J;
}

int IsverstiSkEil(char Sk[], char ZodzEil[], int bufs)
{
  int J, Posl, PrIlgis, i;
  char Skaic[100];
  strcpy(&Skaic[2], Sk);
  Skaic[0] = '0';  Skaic[1] = '0';
  PrIlgis = strlen(Skaic);
  if (PrIlgis > 14)
    {
    for(i=2; i<PrIlgis; i++)
		if(strlen(ZodzEil)<bufs-20) {strcat(ZodzEil, Skaitmuo(Skaic[i]));}
		else {return 1;}
    switch (Skaic[PrIlgis-1])
      {
      case '0' : return 2;
      case '1' : return 0;
      default : return 1;
      }
    }
  Posl = PrIlgis % 3;

while (Posl < PrIlgis)
  {
  J = TrizSk(&Skaic[Posl], ZodzEil);
  switch (PrIlgis - Posl)
    {
      case 3 : {
       if(J==3) strcat(ZodzEil, " VI^ENAS");
		   if (ZodzEil[0] == ' ')
		     strcpy(ZodzEil, &ZodzEil[1]);
		 if(J==-1) return 2; else return J;
	       }
      case 6 : {
         switch (J)
           {
	       case 0 : case 3 : { strcat(ZodzEil, " T�^KSTANTIS");break;}
	       case 1 : { strcat(ZodzEil, " T�^KSTAN�IAI");break;}
	       case 2 : { strcat(ZodzEil, " T�^KSTAN�I�");}
           }
		 break;
	       }
      case 9 : {
         switch (J)
           {
	       case 0 : case 3 : { strcat(ZodzEil, " MILIJO~NAS");break;}
	       case 1 : { strcat(ZodzEil, " MILIJO~NAI");break;}
	       case 2 : { strcat(ZodzEil, " MILIJO~N�");}
           }
		 break;
	       }
     case 12 : {
         switch (J)
           {
	       case 0 : case 3 : { strcat(ZodzEil, " MILIJA^RDAS");break;}
	       case 1 : { strcat(ZodzEil, " MILIJA^RDAI");break;}
	       case 2 : { strcat(ZodzEil, " MILIJA^RD�");}
           }
	       }
    }
  Posl += 3;
  }
return 1;
}

int VisasSkaicius(char Sk[], char ZodzEil[], int bufsize)
{
  ZodzEil[0]=0;
  int i=0;
  int J, Jfinal=1;
  int ilg=strlen(Sk);
  char skaicius[100];
  do
  {
  if(Sk[i]=='+') {strcat(ZodzEil, " PLIUS"); i++;}
  else if(Sk[i]=='-') {if(isdigit(Sk[i+1])) strcat(ZodzEil, " MI`NUS"); i++;}

  while(Sk[i]=='0') {strcat(ZodzEil, " NU`LIS"); i++; if(Jfinal!=4) Jfinal=2;}
  int j=0;
  while(isdigit(Sk[i])) {skaicius[j]=Sk[i]; j++; i++;}
  if(j>0)
    {
    skaicius[j]=0;
    J=IsverstiSkEil(skaicius, ZodzEil, bufsize);
    if(Jfinal!=4) Jfinal=J;
    }
  if(Sk[i]==',') {strcat(ZodzEil, " KABLE~LIS"); i++; Jfinal=4;}
  else if(Sk[i]=='%')
	{
    switch (Jfinal)
      {
      case 0 : case 3 : { strcat(ZodzEil, " PRO`CENTAS");break;}
      case 2 : { strcat(ZodzEil, " PRO`CENT�");break;}
      case 4 : { strcat(ZodzEil, " PRO`CENTO");break;}
      default : { strcat(ZodzEil, " PRO`CENTAI");}
      }
	i++;
    }
  else if(Sk[i]=='$')
	{
    switch (Jfinal)
      {
      case 0 : case 3 : { strcat(ZodzEil, " DO^LERIS");break;}
      case 2 : { strcat(ZodzEil, " DO^LERI�");break;}
      case 4 : { strcat(ZodzEil, " DO^LERIO");break;}
      default : { strcat(ZodzEil, " DO^LERIAI");}
      }
	i++;
    }
  else if(Sk[i]=='\x80')
	{
    switch (Jfinal)
      {
      case 0 : case 3 : { strcat(ZodzEil, " EU~RAS");break;}
      case 2 : { strcat(ZodzEil, " EU~R�");break;}
      case 4 : { strcat(ZodzEil, " EU~RO");break;}
      default : { strcat(ZodzEil, " EU~RAI");}
      }
	i++;
    }
  else if(Sk[i]=='\xA3')
	{
    switch (Jfinal)
      {
      case 0 : case 3 : { strcat(ZodzEil, " SVA~RAS");break;}
      case 2 : { strcat(ZodzEil, " SVA~R�");break;}
      case 4 : { strcat(ZodzEil, " SVA~RO");break;}
      default : { strcat(ZodzEil, " SVA~RAI");}
      }
	i++;
    }
  if(Jfinal!=4) Jfinal=1;
  }
  while(i<ilg);

return strlen(ZodzEil);
}

	string years[] = {
		"PIRM�~",
		"ANTR�~",
		"TRE�I�~",
		"KETVIRT�~",
		"PENKT�~",
		"�E�T�~",
		"SEPTINT�~",
		"A�TUNT�~",
		"DEVINT�~",
		"DE�IMT�~",
		"VIENU^OLIKT�",
		"DVY^LIKT�",
		"TRY^LIKT�",
		"KETURIO^LIKT�",
		"PENKIO^LIKT�",
		"�E�IO^LKT�",
		"SEPTYNIO^LIKT�",
		"A�TUONIO^LIKT�",
		"DEVYNIO^LIKT�"
	};
	string months[] = {
		"SAUSIO",
		"VASARIO",
		"KOVO",
		"BALAND�IO",
		"GEGU��S",
		"BIR�ELIO",
		"LIEPOS",
		"RUGPJ��IO",
		"RUGS�JO",
		"SPALIO",
		"LAPKRI�IO",
		"GRUOD�IO"
	};
	string days[] = {
		"PIRMA`",
		"ANTRA`",
		"TRE�IA`",
		"KETVIRTA`",
		"PENKTA`",
		"�E�TA`",
		"SEPTINTA`", 
		"A�TUNTA`",
		"DEVINTA`", 
		"DE�IMTA`",
		"VIENU^OLIKTA",
		"DVY^LIKTA",
		"TRY^LIKTA",
		"KETURIO^LIKTA",
		"PENKIO^LIKTA",
		"�E�IO^LIKTA",
		"SEPTYNIO^LIKTA",
		"A�TUONIO^LIKTA",
		"DEVYNIO^LIKTA",
		"DVIDE�IMTA`",
		"DVI`DE�IMT PIRMA`",
		"DVI`DE�IMT ANTRA`",
		"DVI`DE�IMT TRE�IA`",
		"DVI`DE�IMT KETVIRTA`",
		"DVI`DE�IMT PENKTA`",
		"DVI`DE�IMT �E�TA`",
		"DVI`DE�IMT SEPTINTA`", 
		"DVI`DE�IMT A�TUNTA`",
		"DVI`DE�IMT DEVINTA`", 
		"TRISDE�IMTA`",
		"TRI`SDE�IMT PIRMA`"
	};
	

	
int expandDate(int yearNumber, int monthNumber, int dayNumber, int mode, char returnText[])
{
	char resTmp[256];
	char inputTmp[256];
	sprintf(inputTmp, "%d", yearNumber);
	VisasSkaicius(inputTmp, resTmp, 256);
	string yearsString = resTmp;

	int findResult = -1;

	if (yearNumber == 0)
	{
		yearsString = "NULINI�";
	}
	else if ((yearNumber % 1000) == 0)
	{
		if (yearNumber == 1000)
		{
			findResult = yearsString.rfind("T�^KSTANTIS");//1000
			if (findResult != -1) yearsString.replace(findResult, strlen("T�^KSTANTIS"), "T�KSTANT�~J�");
			else return -1;
		}
		else //2000,3000,... 
		{
			findResult = yearsString.rfind("T�^KSTAN�IAI");
			if (findResult != -1) yearsString.replace(findResult, strlen("T�^KSTAN�IAI"), "T�KSTANT�~J�");
			else return -1;
		}
	}
	else if ((yearNumber % 100) == 0)
	{
		findResult = yearsString.rfind("�IM~TAS"); //100,1100,2100,...
		if (findResult != -1) yearsString.replace(findResult, strlen("�IM~TAS"), "�IMT�~J�");
		else
		{
			findResult = yearsString.rfind("�IMTAI~"); //200,300,...,800,900,1200,...,1800,1900,2200,...
			if (findResult != -1) yearsString.replace(findResult, strlen("�IMTAI~"), "�IMT�~J�");
			else return -1;
		}
	}
	else if ((yearNumber % 10) == 0)
	{
		findResult = yearsString.rfind("�IMT"); //10,20,...,90,...,1980,1990,2010,2020,...
		if (findResult != -1) yearsString.replace(findResult, strlen("�IMT"), "�IMT�~J�");					
		else return -1;

	}
	else if ((yearNumber % 100) < 20) //...,1901,1902,...1919,2001,...
	{
		int SkTmp = yearNumber - (yearNumber % 100);
		sprintf(inputTmp, "%d", SkTmp);
		VisasSkaicius(inputTmp, resTmp, 256);
		string yearsString2 = resTmp;
		yearsString = yearsString2 + " " + years[(yearNumber % 100)-1];
	}
	else if ((yearNumber % 100) > 20) //...,1921,1922,...1999,2021,...
	{
		int SkTmp = yearNumber - (yearNumber % 10);
		sprintf(inputTmp, "%d", SkTmp);
		VisasSkaicius(inputTmp, resTmp, 256);
		string yearsString2 = resTmp;
		yearsString = yearsString2 + " " + years[(yearNumber % 10)-1];		
	}
	else return -1;

	string returnTextStringTmp;
	if (mode == 0)
		returnTextStringTmp = yearsString + " " + months[monthNumber-1] + " " + days[dayNumber-1];
	else 
		returnTextStringTmp = yearsString + " ME~T� " + months[monthNumber-1] + " " + days[dayNumber-1] + " DIENA`";
	sprintf(returnText, "%s", returnTextStringTmp.c_str());

	return 0;
}

extern int initTextNorm(const char * szRulesFilesDirectory, const char * szRulesFileName)
{
	char buffer_temp[1024];	

	totalRules = 0;
	totalFileBuffers = 0;
	sprintf(buffer_temp, "%s%s", szRulesFilesDirectory, szRulesFileName);
	FILE * file = fopen (buffer_temp, "r");
	if (file == NULL)
		return ERROR_TEXTNORMALIZATION_OPENING_RULES_FILE;
	while (fgets(buffer_temp , 1024 , file) != NULL)
	{
		if (buffer_temp[0] != '/')
		{
			rulesArray[totalRules].assign(buffer_temp);
			totalRules++;

			// File buffers
			if (strstr(buffer_temp, "AbbSeparateWord:") != NULL || strstr(buffer_temp, "ReplaceWithFile:") != NULL)
				totalFileBuffers++;
		}
	}
	fclose(file);
	
	// File buffers
	if (totalFileBuffers > 0)
	{
		abbLists = new char**[totalFileBuffers];
		abbListsSubstitutions = new char**[totalFileBuffers];
		abbListsIsWithSep = new unsigned short*[totalFileBuffers];
		abbSizes = new int[totalFileBuffers];
		for(int i=0; i<totalFileBuffers; i++)
		{
		   abbLists[i] = new char*[2048];
		   abbListsSubstitutions[i] = new char*[2048];
		   abbListsIsWithSep[i] = new unsigned short[2048];
		   for(int j=0; j<2048; j++)
		   {
			   abbLists[i][j] = new char[64];
			   abbListsSubstitutions[i][j] = new char[256];
		   }
		}

		int currentFileBuffer = 0;
		sprintf(buffer_temp, "%s%s", szRulesFilesDirectory, szRulesFileName);
		file = fopen (buffer_temp, "r");
		if (file == NULL) 
			return  ERROR_TEXTNORMALIZATION_OPENING_RULES_FILE;
		while (fgets(buffer_temp , 1024 , file) != NULL)
		{
			if (buffer_temp[0] != '/')
			{			
				if (strstr(buffer_temp, "AbbSeparateWord:") != NULL || strstr(buffer_temp, "ReplaceWithFile:") != NULL)
				{
					char * fileName = strstr(buffer_temp, ":") + 1;
					memset(strstr(fileName, "@"), 0, 1);
					abbSizes[currentFileBuffer] = 0;
					char fileNameTemp[128];	
					strcpy(fileNameTemp, fileName);	
					sprintf(buffer_temp, "%s%s", szRulesFilesDirectory, fileNameTemp);
					FILE * fileAbb = fopen (buffer_temp, "r");
					if (fileAbb == NULL) 
					{
						fclose(file);
						return ERROR_TEXTNORMALIZATION_OPENING_FILE_SPECIFIED_IN_RULES_FILE;
					}
					while (fgets(buffer_temp, 1024, fileAbb) != NULL)
					{
						sscanf(buffer_temp, "%63[^@]@%255[^@]", 
							abbLists[currentFileBuffer][abbSizes[currentFileBuffer]], 
							abbListsSubstitutions[currentFileBuffer][abbSizes[currentFileBuffer]]);
						if (abbLists[currentFileBuffer][abbSizes[currentFileBuffer]][strlen(abbLists[currentFileBuffer][abbSizes[currentFileBuffer]])-1] == '.')
							abbListsIsWithSep[currentFileBuffer][abbSizes[currentFileBuffer]] = 1;
						else
							abbListsIsWithSep[currentFileBuffer][abbSizes[currentFileBuffer]] = 0;
						abbSizes[currentFileBuffer]++;
					}
					fclose(fileAbb);

					currentFileBuffer++;
				}
			}
		}		
	}
	fclose(file);

	return NO_ERR;
}

int applyPhrasesFilter(stringWithLetterPosition * bufferString)
{			
	char bruks = '�';
	string wordSeparatorsList = "\t [{(\"��']}).?!;:,-\r\n=";
	wordSeparatorsList.append(1, bruks);
	string phraseSeparatorsList = ".?!;:\r\n,";
	phraseSeparatorsList.append(1, bruks);
	string leadAndTrailSymbolsList = "[{()}]\"'";


	int phraseStartIndex = 0;
	int phraseEndIndex = bufferString->find_first_of(phraseSeparatorsList, phraseStartIndex);
	while (phraseEndIndex != -1)
	{
		if ( ((bufferString->at(phraseEndIndex) != bruks) && (bufferString->at(phraseEndIndex) != ',')) || 

			 ((bufferString->at(phraseEndIndex) == ',') && (((phraseEndIndex - phraseStartIndex) >= 25) && ((phraseEndIndex - phraseStartIndex) <= 120))) ||

			 ((bufferString->at(phraseEndIndex) == bruks) && 
			 (phraseEndIndex > 0) && 
			 (phraseEndIndex < (bufferString->length()-1)) && 
			 (bufferString->at(phraseEndIndex+1) == ' ') && 
			 (bufferString->at(phraseEndIndex-1) == ' ') && 
			 (((phraseEndIndex - phraseStartIndex) >= 25) && ((phraseEndIndex - phraseStartIndex) <= 120)))
			)
		{
			if ( (bufferString->at(phraseEndIndex) != '\n') && 
				 ((phraseEndIndex >= (bufferString->length()-1)) || (bufferString->at(phraseEndIndex+1) != '\n'))
				)
			{
				bufferString->insert(phraseEndIndex+1, "\n");
				phraseEndIndex+=1;					
			}
		}
		else
		{

			bufferString->erase(phraseEndIndex, 1);
			phraseEndIndex-=1;
		}

		if ((phraseEndIndex - phraseStartIndex) > 120)
		{
			string phraseSecondarySeparatorsList = "[{(]})\"'";
			int r = bufferString->find_first_of(phraseSecondarySeparatorsList, phraseStartIndex+25);
			if ((r != -1) && (r <= phraseStartIndex+120))
			{
				bufferString->insert(r+1, "\n");
				phraseEndIndex=r+1;		
			}
			else
			{
				string phraseTertiarySeparatorsList[] = {"ir","bei","ar","arba"};
				int r = -1;
				int bestR = bufferString->length();
				int bestI = -1;
				for (int i = 0; i < 4; i++)
				{
					r = bufferString->find(phraseTertiarySeparatorsList[i], phraseStartIndex+55);
					if ((r != -1) && (r < bestR) && (r <= phraseStartIndex+120))
					{
						bool isSeparateWord = true;

						if (((r-1) >= 0) && 
							(wordSeparatorsList.find(bufferString->at(r-1)) == -1))
								isSeparateWord = false;

						if (((r + phraseTertiarySeparatorsList[i].length()) <= (bufferString->length()-1)) && 
							(wordSeparatorsList.find(bufferString->at(r+phraseTertiarySeparatorsList[i].length())) == -1))
								isSeparateWord = false;

						if (isSeparateWord == true)
						{
							bestR = r;
							bestI = i;
						}
					}
				}
				if (bestR != bufferString->length())
				{
					bufferString->insert(bestR, "\n");
					phraseEndIndex=bestR;
				}
				else
				{
					bool isDone = false;
					int r = bufferString->rfind(' ', phraseStartIndex+120);
					while (r != -1)
					{
						if ( ( r > 0 ) && ( r < ( bufferString->length() - 1) ) && 
							 ( bufferString->letPos[r-1] != bufferString->letPos[r+1] ) )
						{
							bufferString->insert(r+1, "\n");
							phraseEndIndex=r+1;
							isDone = true;
							break;
						}
						r = bufferString->rfind(' ', r-1);
					}

					if ( ! isDone )
					{
						bufferString->insert(phraseStartIndex+120, "\n");
						phraseEndIndex=phraseStartIndex+120;	
					}
				}
			}				
		}

		phraseStartIndex = phraseEndIndex+1;
		phraseEndIndex = bufferString->find_first_of(phraseSeparatorsList, phraseStartIndex);
	}

	int findResult = bufferString->find_first_of(leadAndTrailSymbolsList, 0);
	while (findResult != -1)
	{
		bufferString->erase(findResult, 1);
		findResult = bufferString->find_first_of(leadAndTrailSymbolsList, 0);
	}

	return NO_ERR;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int spellText(char * buffer, char * retBuffer, int bufferSize, int * letPos)
{
	stringWithLetterPosition bufferString(buffer, letPos, bufferSize);
	if (bufferString.at(bufferString.length()-1) != '\n') bufferString.append("\n");

	// Spelling
	int currentIndex = 0;
	while (bufferString.at(currentIndex) != '\n')
	{
		const char * symbolText = SimbPavad(bufferString.at(currentIndex));
		int symbolTextLength = strlen(symbolText);
		bufferString.replace(currentIndex, 1, symbolText);
		currentIndex += symbolTextLength;
		if (bufferString.at(currentIndex) != ' ')
			bufferString.insert(currentIndex, 1, ' ');

		currentIndex += 1;
	}

	// Phrases
	applyPhrasesFilter(&bufferString);

	// Checking if buffer is OK
	int currentSize = bufferString.length();
	if(currentSize > bufferSize) return ERROR_TEXTNORMALIZATION_BUFFER_OVERFLOW;

	// Filling return buffer
	memcpy(retBuffer, bufferString.c_str(), currentSize);	
	retBuffer[currentSize] = '\0';

	return NO_ERR;
}

int normalizeText(char * buffer, char * retBuffer, int bufferSize, int * letPos) 
{
		stringWithLetterPosition bufferString(buffer, letPos, bufferSize);

		if (bufferString.at(bufferString.length()-1) != '\n') bufferString.append("\n");

		char bruks = '�';

		string wordSeparatorsList = "\t [{(\"��']}).?!;:,-\r\n=";
		wordSeparatorsList.append(1, bruks);
		string leadAndTrailSymbolsList = "[{()}]\"'";
		string digitsList = "1234567890";
		string smallLettersList = "a�bc�de��fghi�yjklmnoprs�tu��vz�xwq";
		string capitalLettersList = "A�BC�DE��FGHI�YJKLMNOPRS�TU��VZ�XWQ";
		string lettersList = smallLettersList + capitalLettersList;
		string phraseSeparatorsList = ".?!;:\r\n,";
		phraseSeparatorsList.append(1, bruks);

		int currentFileBuffer = 0;

		for (int rn = 0; rn < totalRules; rn++)
		{
			string rulesBufferString = rulesArray[rn];

			int findResult = -1;

			findResult = rulesBufferString.find("\\r", 0);
			while (findResult != -1) 
			{
				rulesBufferString.replace(findResult, 2, "\r"); 
				findResult = rulesBufferString.find("\\r", 0); 
			}
			findResult = rulesBufferString.find("\\n", 0);
			while (findResult != -1) 
			{ 
				rulesBufferString.replace(findResult, 2, "\n"); 
				findResult = rulesBufferString.find("\\n", 0); 
			}

            findResult = rulesBufferString.find("\\t", 0);
            while (findResult != -1)
            {
            	rulesBufferString.replace(findResult, 2, "\t");
            	findResult = rulesBufferString.find("\\t", 0);
            }

			int paramCounter = 0;
			int functionNameIndex = rulesBufferString.find(':');
			string functionName = rulesBufferString.substr(0, functionNameIndex);
			int param1Index = rulesBufferString.find('@', functionNameIndex+1);
			int param2Index = rulesBufferString.find('@', param1Index+1);
			string param1Text, param2Text;
			if (param1Index != -1) {
				param1Text = rulesBufferString.substr(functionNameIndex+1, (param1Index-functionNameIndex-1));
				if (param1Text != "")
					paramCounter++;
			}
			if ((param1Index != -1) && (param2Index != -1)) {
				param2Text = rulesBufferString.substr(param1Index+1, (param2Index-param1Index-1));
				paramCounter++;
			}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (functionName == "Replace" && paramCounter == 2) 
			{			
				findResult = bufferString.find(param1Text);
				while (findResult != -1) 
				{
					bufferString.replace(findResult, param1Text.length(), param2Text); 
					findResult = bufferString.find(param1Text);
				}			
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (functionName == "ReplaceWithFile" && paramCounter == 1)
			{	
				for (int g = 0; g < abbSizes[currentFileBuffer]; g++)
				{					
					findResult = bufferString.find(abbLists[currentFileBuffer][g]);
					while (findResult != -1) 
					{
						bufferString.replace(findResult, strlen(abbLists[currentFileBuffer][g]), abbListsSubstitutions[currentFileBuffer][g]); 
						findResult = bufferString.find(abbLists[currentFileBuffer][g]);
					}		
					
				}
				currentFileBuffer++;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "RomanNumerals" && paramCounter == 2)
			{
				findResult = bufferString.find(param1Text);
				while (findResult != -1) 
				{
					int findResult2 = bufferString.find(param2Text);
					if (findResult2 != -1)
					{
						string strToReplace = "\nPIRMAS";
						int findResultDif = findResult2-findResult;
						if (param1Text[1] == 'V')
						{
							findResultDif = findResult-findResult2;
							strToReplace = "\nPENKTAS";
						}

						if ((findResultDif < 500) && (findResultDif > 0))
						{
							bufferString.replace(findResult, param1Text.length(), strToReplace); 
						}
					}
					findResult = bufferString.find(param1Text, findResult+1);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "DigitsPattern" && (paramCounter == 1 || paramCounter == 2)) 
			{				
				findResult = param1Text.find('(');
				string patternSeed = param1Text.substr(0, findResult);				
				int patternSeedLength = patternSeed.length();
				int patternFinish = 0;
				int patternStart = bufferString.find(patternSeed, patternFinish);
				while (patternStart != -1)
				{					
					string patternString = param1Text.substr(patternSeedLength);
					patternFinish = patternStart+patternSeedLength;
					string filledPattern = "";
					//bool isPatternFits = true;
					int foundSymbolsNum = 0;
					for (int z = patternStart+patternSeedLength; z < bufferString.length(); z++)
					{
						if (patternString == "")
							break;

							int currentGroupFinish = patternString.find(')');
							string currentGroupString = patternString.substr(1, currentGroupFinish-1);
							patternString = patternString.substr(currentGroupFinish+1);
							int maxSymbolsNumStart = currentGroupString.find('[');
							bool isFound = false;
							for (int u = 0; u < maxSymbolsNumStart; u++)
							{
								if (((currentGroupString[u] == 'D') || (currentGroupString[u] == 'd')) && (digitsList.find(bufferString.at(z)) != -1))
								{
									isFound = true;
									filledPattern += currentGroupString[u];
									break;
								}
								else if (((currentGroupString[u] == 'L') || (currentGroupString[u] == 'l')) && (lettersList.find(bufferString.at(z)) != -1))
								{
									isFound = true;
									filledPattern += currentGroupString[u];
									break;
								}
								else if (bufferString.at(z) == currentGroupString[u])
								{
									isFound = true;
									filledPattern += currentGroupString[u];
									break;
								}
							}
							if (isFound == true)
							{
								foundSymbolsNum++;
								patternFinish = z;
								int minSymbolsNum, maxSymbolsNum;
								string tmpBuf = currentGroupString.substr(maxSymbolsNumStart+1, currentGroupString.length()-maxSymbolsNumStart-2);
								sscanf(tmpBuf.c_str(), "%d-%d", &minSymbolsNum, &maxSymbolsNum);
								maxSymbolsNum--;
								if (maxSymbolsNum > 0)
								{
									tmpBuf = currentGroupString.substr(0, maxSymbolsNumStart);
									char tmpBufChar[256];
									sprintf(tmpBufChar, "(%s[%d-%d])", tmpBuf.c_str(), minSymbolsNum, maxSymbolsNum);
									patternString = tmpBufChar + patternString;
								}
								else
									foundSymbolsNum = 0;
							}
							else
							{
								int minSymbolsNum, maxSymbolsNum;
								string tmpBuf = currentGroupString.substr(maxSymbolsNumStart+1, currentGroupString.length()-maxSymbolsNumStart-2);
								sscanf(tmpBuf.c_str(), "%d-%d", &minSymbolsNum, &maxSymbolsNum);

								if (foundSymbolsNum >= minSymbolsNum)
								{
									z--;
									continue;
								}
								else
									break;
							}
					}

					//Read by letter from patternStart to patternFinish
					if ((patternFinish - (patternStart+patternSeedLength)) > 0)
					{
						bool addPauses = false;
						
						if (param2Text == "addPauses")
							addPauses = true;

						int wordStartIndex = (patternStart+patternSeedLength);
						int wordEndIndex = patternFinish;
						int patternIndex = 0;
						for (int w = wordStartIndex; w <= wordEndIndex; w++)
						{								
							if ((addPauses == true) && (bufferString.at(w) == ' '))
							{
								bufferString.replace(w-1, 1, 1, '.');
							}

							if ((filledPattern[patternIndex] == 'L') || (filledPattern[patternIndex] == 'D'))
							{
								const char * symbolText = SimbPavad(bufferString.at(w));
								int symbolTextLength = strlen(symbolText);
								if (symbolTextLength != 0)
								{
									if ((w > 0) && (bufferString.at(w-1) != ' '))
									{
										bufferString.insert(w, 1, ' ');
										wordEndIndex++;
										w++;
									}
									bufferString.replace(w, 1, symbolText);
									wordEndIndex += (symbolTextLength-1);
									w += (symbolTextLength-1);
									if (w < (wordEndIndex-1))
									{
										bufferString.insert(w+1, " ");
										wordEndIndex++;
										w++;
									}
								}
								else
								{
									bufferString.erase(w, 1);
									wordEndIndex--;
									w--;
								}
							}
							patternIndex++;
						}							
					}

					patternStart = bufferString.find(patternSeed, patternFinish);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "ReadByLetter" && (paramCounter == 1 || paramCounter == 2))
			{
				
				if (param1Text.find("Num[") != -1)
				{
					string patternString = param1Text;
					string patternStringParams = param1Text;
					int numParams = 0;
					int minRange[32];
					int maxRange[32];

					findResult = patternString.find("Num[");
					while (findResult != -1)
					{
						int findResultEnd = patternString.find("]", findResult);
						string range = patternString.substr(findResult+4, (findResultEnd-findResult-4));
						int digitsNum = range.find("-", 0);
						patternString.replace(findResult, (findResultEnd-findResult+1), digitsNum, 'D');
						patternStringParams.replace(findResult, (findResultEnd-findResult+1), digitsNum, numParams);

						minRange[numParams] = atoi(range.substr(0, digitsNum).c_str());
						maxRange[numParams] = atoi(range.substr(digitsNum+1, range.length()-digitsNum).c_str());
						numParams++;

						findResult = patternString.find("Num[");
					}

					for (int k = 0; k < bufferString.length(); k++)
					{
						int patternLength = patternString.length();
						string str = bufferString.substr(k, patternLength);
						bool is_pattern_found = true;
						string paramsText[32];
						for (int i = 0; i < patternString.length(); i++)
						{
							if (patternString[i] == 'D')
							{
								if ((str[i] < 0x30) || (str[i] > 0x39)) {is_pattern_found = false; break; }
								paramsText[patternStringParams[i]] += str[i];
							}
							else if (patternString[i] == '?')
							{
								if (lettersList.find(str[i]) == -1) {is_pattern_found = false; break; }
							}
							else if (patternString[i] == '*') {} //Do nothing 
							else if (patternString[i] != str[i]) {is_pattern_found = false; break; }
						}
						
						if (is_pattern_found == true)
						{
							for (int asd = 0; asd < numParams; asd++)
							{
								if (paramsText[asd] == "") {is_pattern_found = false; break; }

								int ppp = atoi(paramsText[asd].c_str());
								if (ppp < minRange[asd]) {is_pattern_found = false; break; }
								if (ppp > maxRange[asd]) {is_pattern_found = false; break; }
							}
						}

						if (is_pattern_found == true)
						{
							bool addPauses = false;
							
							if (param2Text == "addPauses")
								addPauses = true;


							int wordStartIndex = k;
							int wordEndIndex = k + patternLength;
							for (int w = wordStartIndex; w < wordEndIndex; w++)
							{								
								if ((addPauses == true) && (bufferString.at(w) == ' '))
								{
									bufferString.replace(w-1, 1, 1, '.');
									wordEndIndex++;
									continue;
								}


								if (digitsList.find(bufferString.at(w))!=-1)
								{
									const char * symbolText = SimbPavad(bufferString.at(w));
									int symbolTextLength = strlen(symbolText);
									if (symbolTextLength != 0)
									{
										if ((w > 0) && (bufferString.at(w-1) != ' '))
										{
											bufferString.insert(w, 1, ' ');
											w++;
										}
										bufferString.replace(w, 1, symbolText);
										wordEndIndex += (symbolTextLength-1);
										w += (symbolTextLength-1);
										if (w < (wordEndIndex-1))
										{
											bufferString.insert(w+1, " ");
											wordEndIndex++;
											w++;
										}
									}
									else
									{
										bufferString.erase(w, 1);
										wordEndIndex--;
										w--;
									}
								}
							}
						}
					}
				}
				else if ((param1Text[0] == '{') && (param1Text[param1Text.length()-1] == '}'))//Stress symbols (~^`)
				{					
					string readByLetterSymbolsList = param1Text.substr(1, param1Text.length()-2);//"~^`";
					findResult = bufferString.find_first_of(readByLetterSymbolsList, 0);
					while (findResult != -1)
					{
						bool isToBeSkipped = false;
						if (param2Text == "checkForNoSpaceAfter")
						{
							if (
								(findResult == (bufferString.length()-1)) || 
								(bufferString.at(findResult+1) == ' ') || 
								(bufferString.at(findResult+1) == '\r') || 
								(bufferString.at(findResult+1) == '\n')	
							   )
							{
								isToBeSkipped = true;
								findResult++;
							}
						}
						
						if (isToBeSkipped == false)
						{
							const char * symbolText = SimbPavad(bufferString.at(findResult));
							int symbolTextLength = strlen(symbolText);
												
							if ((findResult > 0) && (bufferString.at(findResult-1) != ' '))
							{
								bufferString.insert(findResult, " ");
								findResult++;
							}
							if ((findResult < (bufferString.length()-1)) && (bufferString.at(findResult+1) != ' '))
								bufferString.insert(findResult+1, " ");

							if ((param2Text == "") || (param2Text == "checkForNoSpaceAfter"))
							{
								if (symbolTextLength != 0)
								{
									bufferString.replace(findResult, 1, symbolText);
									findResult+=symbolTextLength;
								}
								else bufferString.erase(findResult, 1);
							}
							else if (param2Text == "LeaveOriginalDup")
							{
								if (symbolTextLength != 0)
								{
									bufferString.insert(findResult+1, (char*) symbolText);
									findResult++;
									findResult+=symbolTextLength;
								}
							}
						}

						findResult = bufferString.find_first_of(readByLetterSymbolsList, findResult);
					}
				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				else if (param1Text == "WordNoVowels")
				{
					int wordStartIndex = 0;
					int wordEndIndex = bufferString.find_first_of(wordSeparatorsList, wordStartIndex);
					string vowelsList = "aeiyou������AEIYOU������";

					while (wordEndIndex != -1)
					{
						int wordLength = (wordEndIndex-wordStartIndex);
						if (wordLength > 0)
						{
							bool isWordNoVowels = true;
							for (int w = wordStartIndex; w < wordEndIndex; w++)
							{
								if (vowelsList.find(bufferString.at(w)) != -1)
								{
									isWordNoVowels = false;
									break;
								}
							}

							if (isWordNoVowels == true)
							{
								for (int w = wordStartIndex; w < wordEndIndex; w++)
								{
									const char * symbolText = SimbPavad(bufferString.at(w));
									int symbolTextLength = strlen(symbolText);
									if (symbolTextLength != 0)
									{
										bufferString.replace(w, 1, symbolText);
										wordEndIndex += (symbolTextLength-1);
										w += (symbolTextLength-1);
										if (w < (wordEndIndex-1))
										{
											bufferString.insert(w+1, "-"); //santrumpas skaidom skiemenimis
											wordEndIndex++;
											w++;
										}
									}
									else
									{
										bufferString.erase(w, 1);
										wordEndIndex--;
										w--;
									}
								}
							}
						}
						wordStartIndex = wordEndIndex+1;
						wordEndIndex = bufferString.find_first_of(wordSeparatorsList, wordStartIndex);
					}
				}
			}			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "Date" && paramCounter == 1)
			{
				int MonthVar = 1;
				if (param1Text.find("{MONTHS}") != -1)
				{
					MonthVar = 12;
				}
				for (int mv = 0; mv < MonthVar; mv++)
				{
					string patternString = param1Text;
					int zxc;
					if (MonthVar == 12)
					{
						zxc = patternString.find("{MONTHS}");
						if (zxc != -1)
							patternString.replace(zxc, 8, months[mv]); 
					}
					for (int k = 0; k < bufferString.length(); k++)
					{
						int patternLength = patternString.length();
						string str = bufferString.substr(k, patternLength);
						if (str.length() != patternLength) break;
								string strNormalized = str;
								if (MonthVar == 12)
								{
									for (int ss = zxc; ss < zxc+months[mv].length(); ss++)
									{
										switch (strNormalized[ss])
										{
										case '�':
										case '�':
										case '�':
										case '�':
										case '�':
										case '�':
										case '�':
										case '�':
										case '�':
											strNormalized[ss]-=0x20;
											break;
										default:
											strNormalized[ss] = toupper(strNormalized[ss]);
											break;
										}
									}
								}
						bool is_pattern_found = true;
						string yearStr, monthStr, dayStr;
						for (int i = 0; i < patternString.length(); i++)
						{
							if (patternString[i] == 'Y')
							{
								if ((strNormalized[i] < 0x30) || (strNormalized[i] > 0x39)) {is_pattern_found = false; break; }
								yearStr += strNormalized[i];
							}
							else if (patternString[i] == 'M')
							{
								if ((strNormalized[i] < 0x30) || (strNormalized[i] > 0x39)) {is_pattern_found = false; break; }
								monthStr += strNormalized[i];
							}
							else if (patternString[i] == 'D')
							{
								if ((strNormalized[i] < 0x30) || (strNormalized[i] > 0x39)) {is_pattern_found = false; break; }
								dayStr += strNormalized[i];
							}
							else if (patternString[i] == '?')
							{
								if (isalpha(strNormalized[i]) == 0) {is_pattern_found = false; break; }
							}
							else if (patternString[i] == '*') {} //Do nothing 
							else if (patternString[i] != strNormalized[i]) {is_pattern_found = false; break; }
						}
						int y = 0; int m = 0; int d = 0;					
						if (is_pattern_found == true)
						{
							y = atoi(yearStr.c_str());
							if (MonthVar == 12)
							{
								m = mv+1;
							}
							else
								m = atoi(monthStr.c_str());
							d = atoi(dayStr.c_str());
							if (y <= 0) is_pattern_found = false;
							else if ((m <= 0) || (m >= 13)) is_pattern_found = false;
							else if ((d <= 0) || (d >= 32)) is_pattern_found = false;
						}
						if (is_pattern_found == true)
						{
							int mode = 0;
							if (str.find(" m.") != -1)
								mode = 1;
							char bufferTmp[256];
							if (expandDate(y,m,d, mode, bufferTmp) == -1)
							{
							}
							else
							{

								if ( (k > 0) && (wordSeparatorsList.find(bufferString.at(k-1)) == -1) )
								{
									bufferString.insert(k, " ");
									k++;
								}
								if ( ((k+patternLength) < bufferString.length()) && (wordSeparatorsList.find(bufferString.at((k+patternLength))) == -1) )
								{
									bufferString.insert((k+patternLength), " ");
								}

								bufferString.replace(k, patternLength, bufferTmp);
							}
						}
					}
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "AbbSeparateWord" && paramCounter == 1)
			{
				for (int g = 0; g < abbSizes[currentFileBuffer]; g++)
				{
					findResult = bufferString.find(abbLists[currentFileBuffer][g], 0);
					while (findResult != -1)
					{						
						bool isSeparateWord = true;

						if (((findResult-1) >= 0) && 
							(wordSeparatorsList.find(bufferString.at(findResult-1)) == -1))
								isSeparateWord = false;

						if (((findResult + strlen(abbLists[currentFileBuffer][g])) <= (bufferString.length()-1)) && 
							(wordSeparatorsList.find(bufferString.at(findResult+strlen(abbLists[currentFileBuffer][g]))) == -1))
								isSeparateWord = false;

						int abbLength = strlen(abbLists[currentFileBuffer][g]);
						if (isSeparateWord == true)
						{
							bool isLeaveSep = false;
							if (abbListsIsWithSep[currentFileBuffer][g] == 1)
							{
								if (((findResult+abbLength+1) < bufferString.length()) && 
									(bufferString.at(findResult+abbLength) == ' ') &&
									(capitalLettersList.find(bufferString.at(findResult+abbLength+1))!=-1))
								{
									isLeaveSep = true;
								}
							}

							if (isLeaveSep == true)
							{
								bufferString.replace(findResult, strlen(abbLists[currentFileBuffer][g])-1, abbListsSubstitutions[currentFileBuffer][g]);
								abbLength = strlen(abbListsSubstitutions[currentFileBuffer][g]) + 1;
							}
							else
							{
								bufferString.replace(findResult, strlen(abbLists[currentFileBuffer][g]), abbListsSubstitutions[currentFileBuffer][g]);
								abbLength = strlen(abbListsSubstitutions[currentFileBuffer][g]);
							}
						}
						findResult = bufferString.find(abbLists[currentFileBuffer][g], findResult+abbLength+1);				
					}			
				}
				currentFileBuffer++;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "Numbers" && paramCounter == 0)
			{
				//Digits	
//{+-}{1234567890}{,}{1234567890}{%$\x80\xA3} \x80 - euras, \xA3 - svaras
//ilgiausias skaicius +777777777777,777777777777% uzima 444 simb.
//ilgesni skaiciai sakomi po skaitmeni, o ilgiausio skaitmens ilgis 9. 
//440 turetu pakakti 44 zenklu skaiciui, imkim 512

				int lastDigitIndex = bufferString.find_first_of(digitsList, 0);
				while (lastDigitIndex != -1)
				{
					int digitsWordStartIndex = lastDigitIndex-1;
					int digitsWordEndIndex = lastDigitIndex+1;
					if ((digitsWordStartIndex >= 0) && ((bufferString.at(digitsWordStartIndex) == '+') || (bufferString.at(digitsWordStartIndex) == '+')))
						digitsWordStartIndex--;
					while ((digitsWordEndIndex < bufferString.length()) && (digitsList.find(bufferString.at(digitsWordEndIndex)) != -1))
						digitsWordEndIndex++;
					if ((digitsWordEndIndex < bufferString.length() - 1) && (bufferString.at(digitsWordEndIndex) == ',') && (digitsList.find(bufferString.at(digitsWordEndIndex + 1)) != -1))
						digitsWordEndIndex += 2;
					while ((digitsWordEndIndex < bufferString.length()) && (digitsList.find(bufferString.at(digitsWordEndIndex)) != -1))
						digitsWordEndIndex++;
					if ((digitsWordEndIndex < bufferString.length()) && ((bufferString.at(digitsWordEndIndex) == '%') || (bufferString.at(digitsWordEndIndex) == '$')
						|| (bufferString.at(digitsWordEndIndex) == '\x80') || (bufferString.at(digitsWordEndIndex) == '\xA3')))
						digitsWordEndIndex++;
					if(digitsWordEndIndex > digitsWordStartIndex + 44) digitsWordEndIndex = digitsWordStartIndex + 44; //apsauga kad tilptu

					string singleWord = bufferString.substr(digitsWordStartIndex+1, (digitsWordEndIndex-digitsWordStartIndex-1));

					char bufferTmp[512];
					VisasSkaicius(&singleWord[0], bufferTmp, 512);
					
					bufferString.replace(digitsWordStartIndex+1, (digitsWordEndIndex-digitsWordStartIndex-1), bufferTmp);
					digitsWordEndIndex += (strlen(bufferTmp)-(digitsWordEndIndex-digitsWordStartIndex-1));

					if ( (digitsWordStartIndex > 0) && (wordSeparatorsList.find(bufferString.at(digitsWordStartIndex)) == -1) )
					{
						bufferString.insert(digitsWordStartIndex+1, " ");
						digitsWordEndIndex++;
					}
					if ( (digitsWordEndIndex < (bufferString.length()-1)) && (wordSeparatorsList.find(bufferString.at(digitsWordEndIndex)) == -1) )
					{
						bufferString.insert(digitsWordEndIndex, " ");
						digitsWordEndIndex++;
					}
							
					lastDigitIndex = bufferString.find_first_of(digitsList, digitsWordEndIndex);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "Phrases" && paramCounter == 0)//Phrase boundaries			
			{			
				

				int phraseStartIndex = 0;
				int phraseEndIndex = bufferString.find_first_of(phraseSeparatorsList, phraseStartIndex);
				while (phraseEndIndex != -1)
				{
					if ( ((bufferString.at(phraseEndIndex) != bruks) && (bufferString.at(phraseEndIndex) != ',')) || 

						 ((bufferString.at(phraseEndIndex) == ',') && (((phraseEndIndex - phraseStartIndex) >= 25) && ((phraseEndIndex - phraseStartIndex) <= 120))) ||

						 ((bufferString.at(phraseEndIndex) == bruks) && 
						 (phraseEndIndex > 0) && 
						 (phraseEndIndex < (bufferString.length()-1)) && 
						 (bufferString.at(phraseEndIndex+1) == ' ') && 
						 (bufferString.at(phraseEndIndex-1) == ' ') && 
						 (((phraseEndIndex - phraseStartIndex) >= 25) && ((phraseEndIndex - phraseStartIndex) <= 120)))
						)
					{
						if ( (bufferString.at(phraseEndIndex) != '\n') && 
							 ((phraseEndIndex >= (bufferString.length()-1)) || (bufferString.at(phraseEndIndex+1) != '\n'))
							)
						{
							bufferString.insert(phraseEndIndex+1, "\n");
							phraseEndIndex+=1;					
						}
					}
					else
					{

						bufferString.erase(phraseEndIndex, 1);
						phraseEndIndex-=1;
					}

					if ((phraseEndIndex - phraseStartIndex) >= 120)
					{
						string phraseSecondarySeparatorsList = "[{(]})\"'";
						int r = bufferString.find_first_of(phraseSecondarySeparatorsList, phraseStartIndex+25);
						if ((r != -1) && (r <= phraseStartIndex+120))
						{
							bufferString.insert(r+1, "\n");
							phraseEndIndex=r+1;		
						}
						else
						{
							string phraseTertiarySeparatorsList[] = {"ir","bei","ar","arba"};
							int r = -1;
							int bestR = bufferString.length();
							int bestI = -1;
							for (int i = 0; i < 4; i++)
							{
								r = bufferString.find(phraseTertiarySeparatorsList[i], phraseStartIndex+55);
								if ((r != -1) && (r < bestR) && (r <= phraseStartIndex+120))
								{
									bool isSeparateWord = true;

									if (((r-1) >= 0) && 
										(wordSeparatorsList.find(bufferString.at(r-1)) == -1))
											isSeparateWord = false;

									if (((r + phraseTertiarySeparatorsList[i].length()) <= (bufferString.length()-1)) && 
										(wordSeparatorsList.find(bufferString.at(r+phraseTertiarySeparatorsList[i].length())) == -1))
											isSeparateWord = false;

									if (isSeparateWord == true)
									{
										bestR = r;
										bestI = i;
									}
								}
							}
							if (bestR != bufferString.length())
							{
								bufferString.insert(bestR, "\n");
								phraseEndIndex=bestR; 
							}
							else
							{
								int r = bufferString.rfind(' ', phraseStartIndex+120);
								if (r != -1)
								{
									bufferString.insert(r+1, "\n");
									phraseEndIndex=r+1;	
								}
								else
								{
									bufferString.insert(phraseStartIndex+120, "\n");
									phraseEndIndex=phraseStartIndex+120;	
								}
							}
						}
					}

					phraseStartIndex = phraseEndIndex+1;
					phraseEndIndex = bufferString.find_first_of(phraseSeparatorsList, phraseStartIndex);
				}

				findResult = bufferString.find_first_of(leadAndTrailSymbolsList, 0);
				while (findResult != -1)
				{
					bufferString.erase(findResult, 1);
					findResult = bufferString.find_first_of(leadAndTrailSymbolsList, 0);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (functionName == "ToUPPERCASE" && paramCounter == 0)
			{
				//ToUPPERCASE
				int s = bufferString.length();
				for (int g = 0; g < s; g++)
				{
					switch (bufferString.at(g))
					{
					case '�':
					case '�':
					case '�':
					case '�':
					case '�':
					case '�':
					case '�':
					case '�':
					case '�':
						bufferString.set_at(g, bufferString.at(g)-0x20);
						break;
					default:
						bufferString.set_at(g, toupper(bufferString.at(g)));
						break;
					}
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		int retBufferSize = bufferString.length();

		if(retBufferSize > bufferSize) return ERROR_TEXTNORMALIZATION_BUFFER_OVERFLOW; 

		memcpy(retBuffer, bufferString.c_str(), retBufferSize);	
		retBuffer[retBufferSize] = '\0';
	
	return NO_ERR;
}

