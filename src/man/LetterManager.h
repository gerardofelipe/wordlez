#ifndef _CMP_LETTER_MANAGER_H_
#define _CMP_LETTER_MANAGER_H_

#include <cmp/TLetter.h>
#include <cmp/TWord.h>
#include <enums.h>
#include <stdbool.h>

void man_letter_init();

void man_letter_initLetters(struct TWord *word) __z88dk_fastcall;

char man_letter_getCharacter(struct TLetter *self) __z88dk_fastcall;

void man_letter_setCharacter(struct TLetter *self, char input);

enum LETTER_STATUS man_letter_getStatus(struct TLetter *self) __z88dk_fastcall;

void man_letter_setStatus(struct TLetter *self, enum LETTER_STATUS status);

bool man_letter_isLetterEmpty(struct TLetter *self) __z88dk_fastcall;

void man_letter_resetLetter(struct TLetter *self) __z88dk_fastcall;

#endif
