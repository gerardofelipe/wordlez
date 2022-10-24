#ifndef _CMP_TGAME_H_
#define _CMP_TGAME_H_

#include <cmp/TBoard.h>

typedef struct TGame {
    u16 initialPoolIndex;
    u16 currentPoolIndex;
    struct TBoard *board;
};

#endif
