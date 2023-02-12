#include "kkj_15.h"

ApiStatus func_802405D0_AE5B60(void) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags |= PEACH_STATUS_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

ApiStatus func_802405EC_AE5B7C(Evt* script, s32 isInitialCall) {
    GameStatus* gameStatus = gGameStatusPtr;

    gameStatus->peachFlags &= ~PEACH_STATUS_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}
