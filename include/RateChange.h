#ifndef RATECHANGE_H_INCLUDED
#define RATECHANGE_H_INCLUDED

extern int change_DB_rate(char *katVardas, int greitis, int tono_aukscio_pokytis, char dbfv1[][4], int *dbilg1, long *dbadr1, short ** wholeinputt1);
extern int initRateChange(const char *katVardas, char dbfv1[][4], int *dbilg1, long *dbadr1, short ** wholeinput1);
extern int change_phoneme_rate(int greitis, int tono_aukscio_pokytis, unsigned int fonemos_nr, short * naujas_signalas, unsigned int naujo_signalo_masyvo_ilgis);

extern void loadRateChange();
extern void unloadRateChange();
extern void getData(int * pIlgis, short ** ppData, int * pFonemuSkaicius, int ** ppFonemuIlgiai, char *** pppFonemos);

#endif // !RATECHANGE_H_INCLUDED
