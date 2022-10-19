#ifndef _CMP_WORD_MANAGER_H_
#define _CMP_WORD_MANAGER_H_

#include <cmp/TBoard.h>
#include <cmp/TWord.h>
#include <stdbool.h>

void man_word_init();

void man_word_initWords(struct TBoard *board) __z88dk_fastcall;

u8 man_word_getY(struct TWord *self) __z88dk_fastcall;

struct TLetter *man_word_getLetter(struct TWord *self, u8 letterIndex);

struct TLetter *man_word_getLetters(struct TWord *self) __z88dk_fastcall;

bool man_word_checkWord(struct TWord *self, char *secret);

#endif
