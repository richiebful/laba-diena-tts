#ifndef TRANSCRLUSS_H_INCLUDED
#define TRANSCRLUSS_H_INCLUDED

extern int KircTranskr(char* eil, char* TrZodis, int TrEilIlg, unsigned short* unitsR, unsigned short* unitsRNextSep, int* unitsLet, int* letPos, int rules2use);
extern int initTranscrLUSS(const char *katVardas);

#endif //!TRANSCRLUSS_H_INCLUDED
