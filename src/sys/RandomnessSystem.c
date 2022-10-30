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

u32 entropyCount;

void interruptHandler() {
    ++entropyCount;
}

void sys_randomness_init() {
    entropyCount = 0;
    cpct_setInterruptHandler(interruptHandler);
}

void sys_randomness_initRandomnessRelatedFunctions() {
    struct TGame *game = man_game_getGame();
    cpct_removeInterruptHandler();
    cpct_setSeed_mxor(entropyCount); // seed the cpct random generator

    man_game_applyEntropySeed(game);
}
