#include "common.h"
#include "npc.h"

ApiStatus N(IsGameStatusUnkAA_1)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if (gGameStatusPtr->demoFlags & 1) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(Add1Coin)(Evt* script, s32 isInitialCall) {
    add_coins(1);
    return ApiStatus_DONE2;
}
