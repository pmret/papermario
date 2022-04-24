#include "kkj_15.h"

ApiStatus func_802405D0_AE5B60() {
    GameStatus *temp_v1 = gGameStatusPtr;

    temp_v1->peachFlags |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802405EC_AE5B7C() {
    GameStatus *temp_v1 = gGameStatusPtr;

    temp_v1->peachFlags &= 0xEF;
    return ApiStatus_DONE2;
}
