#ifndef UNITSELECTION_H_INCLUDED
#define UNITSELECTION_H_INCLUDED

#include "../include/common.h"
 
extern int initUnitSel(const char * dataBaseDirName);
extern int selectUnits(unsigned short unitsRow[], unsigned short unitsRowNextSeparators[], unsigned short unitsRowDurr[], int unitsRowLength, int retUnits[], int * retCost);

#endif //!UNITSELECTION_H_INCLUDED
