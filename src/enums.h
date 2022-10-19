#ifndef _ENUMS_H_
#define _ENUMS_H_

#include <sprites/box.h>

enum CONFIG {
    LETTERS_PER_WORD = 5,
    MAX_TRIES = 6,
    EMPTY_LETTER = 32, // 32 Space
    CURSOR = 95,       // underscore
    DEFAULT_BOARD_X = 18,
    DEFAULT_BOARD_Y = 16,
};

#define NUM_OF_WORDS MAX_TRIES

enum COLORS {
    WHITE = 0,         // #FFFFFF
    BLACK = 1,         // #000000
    MAUVE = 2,         // #8000FF
    BLUE = 3,          // #000080
    GREEN = 9,         // #008000
    YELLOW = 15,       // #FFFF00
    GRAY = 11,         // #808080
    ORANGE = 12,       // #FF8000
    RED = 7,           // #FF0000
    BRIGHT_GREEN = 13, // #00FF00
};

enum PENS {
    PEN_SPRITE_TO_REPLACE = 0xc0,
    PEN_WHITE = 0x00,        // #FFFFFF
    PEN_MAUVE = 0x0c,        // #8000FF
    PEN_BLACK = 0xc0,        // #000000
    PEN_BLUE = 0xcc,         // #000080
    PEN_GREEN = 0xc3,        // #008000
    PEN_YELLOW = 0xff,       // #FFFF00
    PEN_GRAY = 0xcf,         // #808080
    PEN_ORANGE = 0x33,       // #FF8000
    PEN_RED = 0xfc,          // #FF0000
    PEN_BRIGHT_GREEN = 0xf3, // #00FF00
};

enum LETTER_DIMS {
    LETTER_BOX_W = G_BOX_W,
    LETTER_BOX_H = G_BOX_H,
};

enum LETTER_STATUS {
    LETTER_NO_CHECKED, // when word has not been checked, because user is filling the cells
    LETTER_NOT_IN_WORD,
    LETTER_IN_WORD_NOT_IN_POSITION,
    LETTER_OK,
};

enum LETTER_FKC {
    Letter_FKC_A = 69,
    Letter_FKC_B = 54,
    Letter_FKC_C = 62,
    Letter_FKC_D = 61,
    Letter_FKC_E = 58,
    Letter_FKC_F = 53,
    Letter_FKC_G = 52,
    Letter_FKC_H = 44,
    Letter_FKC_I = 35,
    Letter_FKC_J = 45,
    Letter_FKC_K = 37,
    Letter_FKC_L = 36,
    Letter_FKC_M = 38,
    Letter_FKC_N = 46,
    Letter_FKC_O = 34,
    Letter_FKC_P = 27,
    Letter_FKC_Q = 67,
    Letter_FKC_R = 50,
    Letter_FKC_S = 60,
    Letter_FKC_T = 51,
    Letter_FKC_U = 42,
    Letter_FKC_V = 55,
    Letter_FKC_W = 59,
    Letter_FKC_X = 63,
    Letter_FKC_Y = 43,
    Letter_FKC_Z = 71,
};

#endif