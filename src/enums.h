#ifndef _ENUMS_H_
#define _ENUMS_H_

#include <sprites/letter_box_sprites.h>

enum CONFIG {
    LETTERS_PER_WORD = 5,
    MAX_TRIES = 6,
    EMPTY_LETTER = 32, // 32 Space
    CURSOR = 95,       // underscore
    DEFAULT_BOARD_X = 18,
    DEFAULT_BOARD_Y = 16,
};

#define NUM_OF_WORDS MAX_TRIES

// enum COLORS_M0 {
//     WHITE = 0,         // #FFFFFF
//     BLACK = 1,         // #000000
//     MAUVE = 2,         // #8000FF
//     BLUE = 3,          // #000080
//     GREEN = 9,         // #008000
//     YELLOW = 14,       // #FFFF00
//     GRAY = 11,         // #808080
//     ORANGE = 12,       // #FF8000
//     RED = 7,           // #FF0000
//     BRIGHT_GREEN = 13, // #00FF00
// };

enum COLORS_M1 {
    WHITE = 0,         // #FFFFFF 255,255,255
    GRAY = 1,         // #808080 128,128,128
    GREEN = 2,         // #008000 0,128,0
    ORANGE = 3,       // #FF8000 255,128,0
};

// enum PEN_2PIXEL_PATTERNS_M0 {
//     SPRITE_PAT_BASE = 0xc3,  // GREEN
//     PEN_2PIXEL_PAT_WHITE = 0x00,        // #FFFFFF
//     PEN_2PIXEL_PAT_MAUVE = 0x0c,        // #8000FF
//     PEN_2PIXEL_PAT_BLACK = 0xc0,        // #000000
//     PEN_2PIXEL_PAT_BLUE = 0xcc,         // #000080
//     PEN_2PIXEL_PAT_GREEN = 0xc3,        // #008000
//     PEN_2PIXEL_PAT_YELLOW = 0xff,       // #FFFF00
//     PEN_2PIXEL_PAT_GRAY = 0xcf,         // #808080
//     PEN_2PIXEL_PAT_ORANGE = 0x33,       // #FF8000
//     PEN_2PIXEL_PAT_RED = 0xfc,          // #FF0000
//     PEN_2PIXEL_PAT_BRIGHT_GREEN = 0xf3, // #00FF00
// };

enum PEN_2PIXEL_PATTERNS_M1 {
    SPRITE_PAT_BASE = 0x0f,  // GREEN
    PEN_2PIXEL_PAT_WHITE = 0x00,        // #FFFFFF
    PEN_2PIXEL_PAT_GRAY = 0xf0,         // #808080
    PEN_2PIXEL_PAT_GREEN = 0x0f,        // #008000
    PEN_2PIXEL_PAT_ORANGE = 0xff,       // #FF8000  
};

enum LETTER_DIMS {
    LETTER_BOX_W = G_LETTER_BOX_SPRITES_00_W,
    LETTER_BOX_H = G_LETTER_BOX_SPRITES_00_H,
};

enum LETTER_STATUS {
    LETTER_NO_CHECKED, // when word has not been checked, because user is filling the cells
    LETTER_NOT_IN_WORD,
    LETTER_IN_WORD_NOT_IN_POSITION,
    LETTER_OK,
};

// enum REPLACE_PATERN_BY_LETTER_STATUS_M0 {
//     RPLC_PAT_LETTER_NOT_IN_WORD = 0xc3cf,             // SPRITE_PAT_BASE << 8 | PEN_GRAY,
//     RPLC_PAT_LETTER_IN_WORD_NOT_IN_POSITION = 0xc333, // SPRITE_PAT_BASE << 8 | PEN_ORANGE,
//     RPLC_PAT_LETTER_OK = 0xc3c3,                      // SPRITE_PAT_BASE << 8 | PEN_GREEN,
// };

enum REPLACE_PATERN_BY_LETTER_STATUS_M1 {
    RPLC_PAT_LETTER_NOT_IN_WORD = 0x0ff0,             // SPRITE_PAT_BASE << 8 | PEN_GRAY,
    RPLC_PAT_LETTER_IN_WORD_NOT_IN_POSITION = 0x0fff, // SPRITE_PAT_BASE << 8 | PEN_ORANGE,
    RPLC_PAT_LETTER_OK = 0x0f0f,                      // SPRITE_PAT_BASE << 8 | PEN_GREEN,
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