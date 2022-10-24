#include <cmp/TBoard.h>
#include <cmp/TGame.h>
#include <cmp/TWord.h>
#include <cpctelera.h>
#include <enums.h>
#include <man/BoardManager.h>
#include <man/GameManager.h>
#include <man/LetterManager.h>
#include <sys/InputSystem.h>
#include <sys/PlaySystem.h>
#include <sys/RenderSystem.h>
#include <utils/cpc.h>

void sys_play_init() {}

void sys_play_initPlay() {
    struct TGame *game = man_game_getGame();
    struct TBoard *board = man_game_getBoard(game);

    do {
        bool haveWon = false;

        do {
            sys_play_waitForUserInput();
            haveWon = man_board_haveWon(board);
        } while (!haveWon && man_board_getTriesLeft(board));

        if (haveWon)
            sys_render_renderWin();
        else
            sys_render_renderLose();

        // @TODO Show statistics view

        if (!sys_input_askForContinue())
            break;

        sys_play_nextLevel();
    } while (1);
}

void sys_play_nextLevel() {
    struct TGame *game = man_game_getGame();
    man_game_moveToNextBoard(game);

    sys_render_eraseFooter();

    sys_render_initialRender();
}

void sys_play_waitForUserInput() {
    char userInput = sys_input_update();

    if (userInput) {
        struct TBoard *board = man_board_getBoard();
        struct TLetter *currentLetter = man_board_getCurrentLetter(board);
        man_letter_setCharacter(currentLetter, userInput);
        sys_render_updateLetterCharacter(currentLetter);
        man_board_moveToNextLetter(board);
    }
}
