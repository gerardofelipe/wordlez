#ifndef _CMP_BOARD_MANAGER_H_
#define _CMP_BOARD_MANAGER_H_

#include <cmp/Tboard.h>
#include <cpctelera.h>
#include <enums.h>
#include <stdbool.h>

void man_board_init();

struct TBoard *man_board_getBoard();

void man_board_initBoard(struct TBoard *self) __z88dk_fastcall;

void man_board_checkWin(struct TBoard *self) __z88dk_fastcall;

bool man_board_haveWon(struct TBoard *self) __z88dk_fastcall;

u8 man_board_getTriesLeft(struct TBoard *self) __z88dk_fastcall;

struct TWord *man_board_getWord(struct TBoard *self, u8 i);

struct TWord *man_board_getWords(struct TBoard *self) __z88dk_fastcall;

struct TWord *man_board_getCurrentWord(struct TBoard *self) __z88dk_fastcall;

struct TLetter *man_board_getCurrentLetter(struct TBoard *self) __z88dk_fastcall;

bool man_board_moveToPrevLetter(struct TBoard *self) __z88dk_fastcall;

bool man_board_moveToNextLetter(struct TBoard *self) __z88dk_fastcall;

bool man_board_moveToNextWord(struct TBoard *self) __z88dk_fastcall;

bool man_board_isCurrentWordFilledIn(struct TBoard *self) __z88dk_fastcall;

char *man_board_getSecret(struct TBoard *self) __z88dk_fastcall;

char *_generateSecret();

#endif
