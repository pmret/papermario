#include "common.h"

API_CALLABLE(N(SetPeachFlag8)) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= PEACH_STATUS_FLAG_8;
    return ApiStatus_DONE2;
}
