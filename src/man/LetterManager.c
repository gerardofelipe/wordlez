#include <cmp/TLetter.h>
#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/LetterManager.h>
#include <stdbool.h>

void man_letter_init() {
}

void man_letter_initLetters(struct TWord *word) __z88dk_fastcall {
    u8 c = LETTERS_PER_WORD + 1;
    u8 wordX = word->x;
    u8 wordY = word->y;
    u8 i = LETTERS_PER_WORD - 1;
    struct TLetter *letter = word->letters + i;
    while (--c) {
        letter->index = i;
        letter->x = wordX + (LETTER_BOX_W + 1) * i;
        letter->y = wordY;
        letter->character = EMPTY_LETTER;
        letter->status = LETTER_NO_CHECKED;

        --letter;
        --i;
    }
}

char man_letter_getCharacter(struct TLetter *self) __z88dk_fastcall {
    return self->character;
}

void man_letter_setCharacter(struct TLetter *self, char input) {
    self->character = input;
}

enum LETTER_STATUS man_letter_getStatus(struct TLetter *self) __z88dk_fastcall {
    return self->status;
}

void man_letter_setStatus(struct TLetter *self, enum LETTER_STATUS status) {
    self->status = status;
}

bool man_letter_isLetterEmpty(struct TLetter *self) __z88dk_fastcall {
    return self->character == EMPTY_LETTER;
}

void man_letter_resetLetter(struct TLetter *self) __z88dk_fastcall {
    self->character = EMPTY_LETTER;
    self->status = LETTER_NO_CHECKED;
}
