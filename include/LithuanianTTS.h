
#ifndef LITHUSS_H_INCLUDED
#define LITHUSS_H_INCLUDED

struct event {short Id; short phonviz; int charOffset; long signOffset;};

extern int initLUSS(const char * szDataDirectory, const char *katVoice);
extern int normalizeText1(char *text, char *normtextbuf, int bufsize, int * letPos);
extern int stressTranscr(char *sakinys, char *TrSakinys, int bufsize, unsigned short* unitsR, unsigned short* unitsRNextSep, int* unitsLet, int* letPos);
extern int findUnits(unsigned short *unitsRows, unsigned short *unitsRowsNextSeparators, int unitsRowsLength, unsigned int *retUnits, unsigned short *unitsDurr);
extern int synthesizePhoneme(int greicioKoef, int tonas, unsigned short unitsDurr, unsigned int retUnit, short *phoneme, unsigned int naujo_signalo_masyvo_ilgis);
extern const char* id2fv(unsigned short id);
extern int synthesizeWholeText(char *tekstas, short *signbuf, unsigned int *signbufsize, event *evarr, int *evarrsize, int greitis, int tonas);
extern int raw2wav(int, char * filename, short * pBuffer);

extern bool loadLUSS();
extern void unloadLUSS();

extern const char* getLUSSErrorMessages(int err);

#endif //!LITHUSS_H_INCLUDED
