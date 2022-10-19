#ifndef _CMP_TWORD_H_
#define _CMP_TWORD_H_

#include <cmp/TLetter.h>
#include <enums.h>

typedef struct TWord {
    u8 index;
    u8 x;
    u8 y;
    struct TLetter letters[LETTERS_PER_WORD];
};

#endif
