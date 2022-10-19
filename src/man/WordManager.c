#include <cmp/TBoard.h>
#include <cmp/TLetter.h>
#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/LetterManager.h>
#include <man/WordManager.h>
#include <sprites/box.h>
#include <stdbool.h>

#define ALREADY_TESTED 0

void man_word_init() {
}

void man_word_initWords(struct TBoard *board) __z88dk_fastcall {
    u8 c = NUM_OF_WORDS + 1;
    u8 i = NUM_OF_WORDS - 1;
    struct TWord *word = board->words + i;
    while (--c) {
        word->index = i;
        word->x = board->x;
        word->y = board->y + (LETTER_BOX_H + 2) * i;
        man_letter_initLetters(word);
        --word;
        --i;
    }
}

u8 man_word_getY(struct TWord *self) __z88dk_fastcall {
    return self->y;
}

struct TLetter *man_word_getLetter(struct TWord *self, u8 letterIndex) {
    return self->letters + letterIndex;
}

struct TLetter *man_word_getLetters(struct TWord *self) __z88dk_fastcall {
    return self->letters;
}

// @TODO optimize this function
bool man_word_checkWord(struct TWord *self, char *secret) {
    struct TLetter *letters = self->letters;
    u8 wrongLettersCount = 0;
    char bufferSecret[LETTERS_PER_WORD]; // store the characters of the secret to be checked in the second cycle
    struct TLetter *bufferLetters[LETTERS_PER_WORD]; // store the letters to be checked in the second cycle

    {
        u8 c = LETTERS_PER_WORD + 1;
        char *secretPtr = secret + 0;
        struct TLetter *letterPtr = letters + 0;
        while (--c) {
            char secretChar = *secretPtr;
            if (letterPtr->character == secretChar) {
                letterPtr->status = LETTER_OK;
            } else {
                letterPtr->status = LETTER_NOT_IN_WORD; // until next check cycle
                bufferSecret[wrongLettersCount] = secretChar;
                bufferLetters[wrongLettersCount] = letterPtr;
                ++wrongLettersCount;
            }

            ++secretPtr;
            ++letterPtr;
        }
    }

    if (wrongLettersCount == 0)
        return true; // win!

    for (u8 i = 0; i < wrongLettersCount; i++) {
        struct TLetter *letter = bufferLetters[i];
        for (u8 j = 0; j < wrongLettersCount; j++) {
            char secretChar = bufferSecret[j];
            if (secretChar == ALREADY_TESTED) {
                continue;
            }
            if (letter->character == secretChar) {
                letter->status = LETTER_IN_WORD_NOT_IN_POSITION;
                bufferSecret[j] = ALREADY_TESTED;
                break;
            }
        }
    }

    return false;
}
