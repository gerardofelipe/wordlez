#include <cmp/TBoard.h>
#include <cmp/TGame.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/GameManager.h>
#include <man/SecretManager.h>
#include <man/WordManager.h>
#include <stdbool.h>

struct TBoard board;

void man_board_init() {
}

void man_board_initBoard(struct TGame *game) __z88dk_fastcall {
    struct TBoard *self = game->board;
    struct TSecret *secret;
    self->x = DEFAULT_BOARD_X;
    self->y = DEFAULT_BOARD_Y;
    self->triesLeft = MAX_TRIES;
    self->win = false;
    self->currentWord = self->words + 0;
    self->currentLetter = man_word_getLetter(self->currentWord, 0);
    self->secret = man_secret_getSecret();
    man_word_initWords(self);
}

struct TBoard *man_board_getBoard() {
    return &board;
}

void man_board_checkWin(struct TBoard *self) __z88dk_fastcall {
    struct TSecretWord *secretWord = man_secret_getSecretWord(self->secret);
    bool win = man_word_checkWord(self->currentWord, (char *)secretWord);
    self->win = win;
}

bool man_board_haveWon(struct TBoard *self) __z88dk_fastcall {
    return self->win;
}

u8 man_board_getTriesLeft(struct TBoard *self) __z88dk_fastcall {
    return self->triesLeft;
}

struct TWord *man_board_getWord(struct TBoard *self, u8 wordIndex) {
    return self->words + wordIndex;
}

struct TWord *man_board_getWords(struct TBoard *self) __z88dk_fastcall {
    return self->words;
}

struct TWord *man_board_getCurrentWord(struct TBoard *self) __z88dk_fastcall {
    return self->currentWord;
}
struct TLetter *man_board_getCurrentLetter(struct TBoard *self) __z88dk_fastcall {
    return self->currentLetter;
}

bool man_board_moveToPrevLetter(struct TBoard *self) __z88dk_fastcall {
    struct TLetter *currentLetter = self->currentLetter;
    if (currentLetter->index > 0) {
        self->currentLetter--;
        return true;
    }
    return false;
}

bool man_board_moveToNextLetter(struct TBoard *self) __z88dk_fastcall {
    struct TLetter *currentLetter = self->currentLetter;
    if (currentLetter->index < LETTERS_PER_WORD - 1) {
        self->currentLetter++;
        return true;
    }
    return false;
}

bool man_board_moveToNextWord(struct TBoard *self) __z88dk_fastcall {
    if (self->triesLeft) {
        self->triesLeft--;
        self->currentWord++;
        self->currentLetter = self->currentWord->letters + 0;
        return true;
    }
    return false;
}

bool man_board_isCurrentWordFilledIn(struct TBoard *self) __z88dk_fastcall {
    return man_word_isFilledIn(self->currentWord);
}

struct TSecretWord *man_board_getSecretWord(struct TBoard *self) __z88dk_fastcall {
    return man_secret_getSecretWord(self->secret);
}
