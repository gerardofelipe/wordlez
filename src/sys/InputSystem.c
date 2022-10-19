#include <cpctelera.h>
#include <man/BoardManager.h>
#include <man/LetterManager.h>
#include <man/WordManager.h>
#include <sys/InputSystem.h>
#include <sys/RenderSystem.h>
#include <utils/cpc.h>

void sys_input_init() {
}

void sys_input_onEnterAction() {
    struct TBoard *board = man_board_getBoard();
    if (man_board_isCurrentWordFilledIn(board)) {
        man_board_checkWin(board);
        sys_render_renderCurrentWord();
        man_board_moveToNextWord(board);
    }
}

void sys_input_onDeleteAction() {
    struct TBoard *board = man_board_getBoard();
    struct TLetter *currentLetter = man_board_getCurrentLetter(board);
    if (man_letter_isLetterEmpty(currentLetter)) {
        man_board_moveToPrevLetter(board);
        currentLetter = man_board_getCurrentLetter(board);
    }
    man_letter_resetLetter(currentLetter);
    sys_render_updateLetterCharacter(currentLetter);
}

char sys_input_update() {
    u8 waitMultiplier = 12;
    char ch = 0;

    pressAnyKey();

    if (cpct_isKeyPressed(Key_Return) || cpct_isKeyPressed(Key_Enter)) {
        sys_input_onEnterAction();
    } else if (cpct_isKeyPressed(Key_CursorLeft) || cpct_isKeyPressed(Key_Del) || cpct_isKeyPressed(Key_Clr)) {
        sys_input_onDeleteAction();
        waitMultiplier = 8;
    } else {
        ch = readUserInputChar();
    }

    // control long press
    waitNTimesVSYNCStart(waitMultiplier);
    return ch;
}
