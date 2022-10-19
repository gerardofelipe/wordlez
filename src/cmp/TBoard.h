#ifndef _CMP_TBOARD_H_
#define _CMP_TBOARD_H_

#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <stdbool.h>

typedef struct TBoard {
    u8 x;
    u8 y;
    u8 triesLeft;
    bool win;
    struct TWord *currentWord;
    struct TLetter *currentLetter;
    char *secret;
    struct TWord words[NUM_OF_WORDS];
};

#endif
