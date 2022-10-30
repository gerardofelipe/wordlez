#ifndef _CMP_GAME_MANAGER_H_
#define _CMP_GAME_MANAGER_H_

#include <cmp/TBoard.h>
#include <cmp/TGame.h>
#include <enums.h>
#include <stdbool.h>

void man_game_init();

struct TGame *man_game_getGame();

void man_game_initGame(struct TGame *self) __z88dk_fastcall;

void man_game_applyEntropySeed(struct TGame *self, u16 initialPoolIndex);

u16 man_game_getcurrentPoolIndex(struct TGame *self) __z88dk_fastcall;

struct TBoard *man_game_getBoard(struct TGame *self) __z88dk_fastcall;

void man_game_moveToNextBoard(struct TGame *self) __z88dk_fastcall;

#endif
