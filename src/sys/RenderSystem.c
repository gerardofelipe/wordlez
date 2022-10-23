#include <cmp/TSecret.h>
#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/LetterManager.h>
#include <man/WordManager.h>
#include <sprites/letter_box_sprites.h>
#include <sys/RenderSystem.h>
#include <utils/cpc.h>

void sys_render_init() {
}

void sys_render_initialRender() {
    struct TBoard *board = man_board_getBoard();
    struct TWord *word = man_board_getWords(board);

    u8 i = NUM_OF_WORDS + 1;
    while (--i) {
        cpct_waitVSYNC();
        sys_render_initialRenderWord(word);
        ++word;
    };
}

void sys_render_initialRenderWord(struct TWord *word) __z88dk_fastcall {
    u8 frame = 6; // sizeof(g_tileset) / 2
    do {
        u8 i = LETTERS_PER_WORD + 1;
        struct TLetter *letter = man_word_getLetter(word, (LETTERS_PER_WORD - 1));
        --frame;
        while (--i) {
            sys_render_initialRenderLetterByFrame(letter, frame);
            --letter;
        }
        cpct_waitVSYNC();
    } while (frame);
}

// using animation frame
void sys_render_initialRenderLetterByFrame(struct TLetter *letter, u8 frame) {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = man_letter_getCharacter(letter);
    u8 *sprite = g_tileset[frame];
    cpct_drawSprite(sprite, pvmem, LETTER_BOX_W, LETTER_BOX_H);
}

// whithout animation
void sys_render_initialRenderLetter(struct TLetter *letter) __z88dk_fastcall {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = man_letter_getCharacter(letter);
    u8 *sprite = g_tileset[0];
    cpct_drawSprite(sprite, pvmem, LETTER_BOX_W, LETTER_BOX_H);
}

void sys_render_renderCurrentWord() {
    struct TBoard *board = man_board_getBoard();
    sys_render_renderWord(man_board_getCurrentWord(board));
}

void sys_render_renderWord(struct TWord *word) __z88dk_fastcall {
    u8 i = LETTERS_PER_WORD + 1;
    struct TLetter *letter = man_word_getLetters(word);
    while (--i) {
        enum LETTER_STATUS status = man_letter_getStatus(letter);
        u8 color;
        u16 rplcPat;

        if (status == LETTER_OK) {
            color = GREEN;
            rplcPat = RPLC_PAT_LETTER_OK;

        } else if (status == LETTER_IN_WORD_NOT_IN_POSITION) {
            color = ORANGE;
            rplcPat = RPLC_PAT_LETTER_IN_WORD_NOT_IN_POSITION;
        } else {
            color = GRAY;
            rplcPat = RPLC_PAT_LETTER_NOT_IN_WORD;
        }
        sys_render_renderLetter(letter, color, rplcPat);
        ++letter;
    }
}

void sys_render_updateLetterCharacter(struct TLetter *letter) __z88dk_fastcall {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = man_letter_getCharacter(letter);
    cpct_setDrawCharM0(GRAY, WHITE);
    drawCharAt(character, posX + 2, posY + 8);
}

// @TODO optimize this function
void sys_render_renderLetter(struct TLetter *letter, u8 color, u16 rplcPat) {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = man_letter_getCharacter(letter);
    u8 *sprite;
    u8 i;

    cpct_setDrawCharM0(WHITE, color);

    cpct_waitVSYNC();

    // sizeof(g_tileset) == 12
    for (i = 0; i < 12; ++i) {
        sprite = g_tileset[i];

        // @TODO micro optimization: LETTER_OK status could be rendered without replace pattern
        cpct_drawSpriteColorizeM0(sprite, pvmem, LETTER_BOX_W, LETTER_BOX_H, rplcPat);

        // render the character 2 frames before end to make it look like it appears smoother
        if (i > 9)
            drawCharAt(character, posX + 2, posY + 8);

        // no need to wait once the animation has finished
        if (i < 11) {
            cpct_waitVSYNCStart();
            cpct_waitVSYNC();
        }
    }
}

void sys_render_renderHeader() {
    cpct_setDrawCharM0(BLUE, WHITE);
    drawStringAt("WORDLEZ", 26, 0);
}

void sys_render_renderWin() {
    cpct_setDrawCharM0(BLACK, WHITE);
    drawStringAt("!Has acertado!", 0, 180);
}

void sys_render_renderLose() {
    struct TBoard *board = man_board_getBoard();
    char *secret = (char *)man_board_getSecretWord(board);
    cpct_setDrawCharM0(BLACK, WHITE);
    drawStringAt("Ohh,no acertaste :(", 0, 178);
    drawStringAt("Respuesta:", 0, 190);
    cpct_setDrawCharM0(GREEN, WHITE);
    drawStringAt(secret, 42, 190);
}
