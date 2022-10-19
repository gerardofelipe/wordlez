#include <cpctelera.h>
#include <utils/asm.s.h>
#include <utils/cpc.h>

static const char LETTERS_BY_FKC[80] = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    'P',
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    'O',
    'I',
    'L',
    'K',
    'M',
    0x0,
    0x0,
    0x0,
    'U',
    'Y',
    'H',
    'J',
    'N',
    0x0,
    0x0,
    0x0,
    'R',
    'T',
    'G',
    'F',
    'B',
    'V',
    0x0,
    0x0,
    'E',
    'W',
    'S',
    'D',
    'C',
    'X',
    0x0,
    0x0,
    0x0,
    'Q',
    0x0,
    'A',
    0x0,
    'Z',
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};

void waitNTimesVSYNCStart(u8 n) __z88dk_fastcall {
    u8 i = n + 1;
    do
        cpct_waitVSYNCStart();
    while (--i);
}

void pressAnyKey() {
    do
        cpct_scanKeyboard();
    while (!cpct_isAnyKeyPressed_f());
}

void releaseAnyKey() {
    do
        cpct_scanKeyboard();
    while (cpct_isAnyKeyPressed_f());
}

// @TODO Handle the case where several keys are pressed simultaneously.
u8 getFKCPressed() {
    u8 c = 11;
    u8 indexLine = 9;
    u8 *keys = cpct_keyboardStatusBuffer + 9;
    u8 keypressed;

    while (--c) {
        keypressed = *keys ^ 0xFF;
        if (keypressed) {
            u8 indexBit = get_highest_active_bit_position(keypressed);
            return indexLine * 8 + indexBit;
        }
        --indexLine;
        --keys;
    };

    // No key was pressed
    return 0;
}

char readUserInputChar() {
    u8 a = 0;
    u8 fkc = getFKCPressed();
    return LETTERS_BY_FKC[fkc];
}