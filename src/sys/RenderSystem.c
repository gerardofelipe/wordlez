#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/LetterManager.h>
#include <man/WordManager.h>
#include <sprites/box_spritesheet.h>
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
    u8 i = LETTERS_PER_WORD + 1;
    struct TLetter *letter = word->letters + (LETTERS_PER_WORD - 1);

    while (--i) {
        sys_render_initialRenderLetter(letter);
        --letter;
    }
}

void sys_render_initialRenderLetter(struct TLetter *letter) __z88dk_fastcall {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = letter->character;

    cpct_drawSprite(g_box_spritesheet_0, pvmem, G_BOX_SPRITESHEET_0_W, G_BOX_SPRITESHEET_0_H);

    cpct_setDrawCharM0(GRAY, WHITE);
    drawCharAt(character, posX + 2, posY + 8);
}

void sys_render_renderCurrentWord() {
    struct TBoard *board = man_board_getBoard();
    cpct_waitVSYNC();
    sys_render_renderWord(board->currentWord);
}

void sys_render_renderWord(struct TWord *word) __z88dk_fastcall {
    u8 i = LETTERS_PER_WORD + 1;
    struct TLetter *letter = word->letters;

    while (--i) {
        sys_render_renderLetter(letter);
        ++letter;
    }
}

void sys_render_updateLetterCharacter(struct TLetter *letter) __z88dk_fastcall {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = letter->character;
    enum LETTER_STATUS status = letter->status;

    switch (status) {
    case LETTER_OK:
        cpct_setDrawCharM0(WHITE, GREEN);
        break;
    case LETTER_IN_WORD_NOT_IN_POSITION:
        cpct_setDrawCharM0(WHITE, ORANGE);
        break;
    case LETTER_NOT_IN_WORD:
        cpct_setDrawCharM0(WHITE, GRAY);
        break;
    default:
        cpct_setDrawCharM0(GRAY, WHITE);
    }
    drawCharAt(character, posX + 2, posY + 8);
}

void sys_render_renderLetter(struct TLetter *letter) __z88dk_fastcall {
    u8 posX = letter->x;
    u8 posY = letter->y;
    u8 *pvmem = getScreenPtr(posX, posY);
    char character = letter->character;
    enum LETTER_STATUS status = letter->status;

    switch (status) {
    case LETTER_OK:
        cpct_setDrawCharM0(WHITE, GREEN);
        cpct_drawSolidBox(pvmem, PEN_GREEN, LETTER_BOX_W, LETTER_BOX_H);
        break;
    case LETTER_IN_WORD_NOT_IN_POSITION:
        cpct_setDrawCharM0(WHITE, ORANGE);
        cpct_drawSolidBox(pvmem, PEN_ORANGE, LETTER_BOX_W, LETTER_BOX_H);
        break;
    default: // case LETTER_NOT_IN_WORD:
        cpct_setDrawCharM0(WHITE, GRAY);
        cpct_drawSolidBox(pvmem, PEN_GRAY, LETTER_BOX_W, LETTER_BOX_H);
    }
    drawCharAt(character, posX + 2, posY + 8);
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
    char *secret = man_board_getSecret(board);
    cpct_setDrawCharM0(BLACK, WHITE);
    drawStringAt("Ohh,no acertaste :(", 0, 178);
    drawStringAt("Respuesta:", 0, 190);
    cpct_setDrawCharM0(GREEN, WHITE);
    drawStringAt(secret, 42, 190);
}
