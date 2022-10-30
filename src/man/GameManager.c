#include <cmp/TBoard.h>
#include <cmp/TGame.h>
#include <cmp/TSecret.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/GameManager.h>
#include <man/SecretManager.h>

struct TGame game;

void man_game_init() {
    man_game_initGame(&game);
}

struct TGame *man_game_getGame() {
    return &game;
}

void man_game_initGame(struct TGame *self) __z88dk_fastcall {
    self->initialPoolIndex = 0; // will be set later based on the entropy seed
    self->currentPoolIndex = 0;
    self->board = man_board_getBoard();
    man_board_initBoard(self);
}

void man_game_applyEntropySeed(struct TGame *self, u16 initialPoolIndex) {
    struct TSecret *secret;
    self->initialPoolIndex = initialPoolIndex;
    self->currentPoolIndex = initialPoolIndex;
    secret = man_secret_getSecret();
    man_secret_initSecret(secret, initialPoolIndex);
}

u16 man_game_getcurrentPoolIndex(struct TGame *self) __z88dk_fastcall {
    return self->currentPoolIndex;
}

struct TBoard *man_game_getBoard(struct TGame *self) __z88dk_fastcall {
    return self->board;
}

void man_game_moveToNextBoard(struct TGame *self) __z88dk_fastcall {
    struct TBoard *board = man_game_getBoard(self);
    struct TSecret *secret = board->secret;
    man_secret_moveToNextSecret(secret);
    self->currentPoolIndex = secret->index;
    man_board_initBoard(self);
}