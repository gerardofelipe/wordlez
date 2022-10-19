#ifndef _CMP_TLETTER_H_
#define _CMP_TLETTER_H_

#include <cpctelera.h>
#include <enums.h>

typedef struct TLetter {
    u8 index;
    u8 x;
    u8 y;
    char character;
    enum LETTER_STATUS status;
};

#endif
