#include "common.h"
#include "map.h"

ApiStatus N(IsGameStatusUnkAA_1)(ScriptInstance* script, s32 isInitialCall) {
    GameStatus* gameStatus = GAME_STATUS;

    script->varTable[0] = 0;
    if (gameStatus->unk_AA & 1) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(Add1Coin)(ScriptInstance* script, s32 isInitialCall) {
    add_coins(1);
    return ApiStatus_DONE2;
}
