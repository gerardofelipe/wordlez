#include <cmp/TBoard.h>
#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/LetterManager.h>
#include <man/WordManager.h>
#include <sprites/box.h>
#include <stdbool.h>
#include <sys/InputSystem.h>
#include <sys/RenderSystem.h>
#include <utils/asm.s.h>
#include <utils/cpc.h>

void initialize() {
    cpct_disableFirmware();
    cpct_setVideoMode(0);
    cpct_setPalette(g_palette, 16);
    cpct_setBorder(HW_BRIGHT_WHITE);
    cpct_setBorder(HW_BRIGHT_WHITE);
}

// GAME
void playSystem() {
    struct TBoard *board = man_board_getBoard();
    do {
        struct TLetter *currentLetter = man_board_getCurrentLetter(board);
        struct TWord *currentWord = man_board_getCurrentWord(board);

        char userInput = sys_input_update();

        if (userInput) {
            man_letter_setCharacter(currentLetter, userInput);
            sys_render_updateLetterCharacter(currentLetter);
            man_board_moveToNextLetter(board);
        }

        if (man_board_haveWon(board))
            break;

    } while (man_board_getTriesLeft(board));

    if (man_board_haveWon(board))
        sys_render_renderWin();
    else
        sys_render_renderLose();
}

int main(void) {
    initialize();

    man_letter_init();
    man_word_init();
    man_board_init();
    sys_input_init();
    sys_render_init();

    sys_render_renderHeader();

    // initial render
    sys_render_initialRender();

    // start playing
    playSystem();

    while (1)
        ;
}