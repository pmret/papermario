#include "common.h"

API_CALLABLE(N(PreventNextPeachDisguise)) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= PEACH_FLAG_BLOCK_NEXT_DISGUISE;
    return ApiStatus_DONE2;
}
