
#ifndef _UTILS_PRNG_H_
#define _UTILS_PRNG_H_

#include <cpctelera.h>

u16 prngInit();

u16 prng(u16 x) __z88dk_fastcall;

#endif