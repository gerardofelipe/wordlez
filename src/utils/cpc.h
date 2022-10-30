#ifndef _UTILS_CPC_H_
#define _UTILS_CPC_H_

#include <cpctelera.h>

#define getScreenPtr(x, y) cpct_getScreenPtr(CPCT_VMEM_START, x, y)
#define drawStringAt(s, x, y) cpct_drawStringM1(s, getScreenPtr(x, y))
#define drawCharAt(c, x, y) cpct_drawCharM1(getScreenPtr(x, y), c)

static const char LETTERS_BY_FKC[80];

void waitNTimesVSYNCStart(u8 n) __z88dk_fastcall;

void pressAnyKey();

void releaseAnyKey();

u8 getFKCPressed();

char readUserInputChar();

u16 getRandom16Index(u16 arrSize) __z88dk_fastcall;

#endif
