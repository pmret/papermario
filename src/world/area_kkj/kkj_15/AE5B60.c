#include "kkj_15.h"

ApiStatus func_802405D0_AE5B60(void) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802405EC_AE5B7C(void) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags &= ~0x10;
    return ApiStatus_DONE2;
}
