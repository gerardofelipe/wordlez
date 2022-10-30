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
#include <utils/prng.h>
#include <stdlib.h>

u32 entropySeed;

void interruptHandler() {
    // As a guideline, going straight to play, in a normal way (not extremely fast), is about 350 interrupts.
    // Using a nice prime number like this (actually, it doesn't need to be prime), we flip the 32bits approximately
    // every 178 interrupts, trying to get a more diverse seed.
    entropySeed += 367;
}

void sys_randomness_init() {
    entropySeed = 0;
    cpct_setInterruptHandler(interruptHandler);
}

void sys_randomness_initRandomnessRelatedFunctions() {
    u16 initialX;
    struct TGame *game;
    cpct_removeInterruptHandler();
    srand(entropySeed);
    initialX = prngInit();
    game = man_game_getGame();
    man_game_applyEntropySeed(game, initialX);
}
