#ifndef TEXTNORMALIZATION_H_INCLUDED
#define TEXTNORMALIZATION_H_INCLUDED

#include "../include/common.h"

extern int initTextNorm(const char * szRulesFilesDirectory, const char * rulesFileName);
extern int normalizeText(char * buffer, char * retBuffer, int bufferSize, int * letPos);
extern int spellText(char * buffer, char * retBuffer, int bufferSize, int * letPos);

extern BOOL loadTextNorm(char*);
extern void unloadTextNorm();

#endif
