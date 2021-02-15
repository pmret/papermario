#include "common.h"

#define NAMESPACE battle_move_jump

#include "world/common/UnkMoveFunc1.inc.c"

ApiStatus func_802A10E4_73D944(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[15] = 1;

    switch (playerData->bootsLevel) {
        case 0:
            script->varTable[15] = 1;
            break;
        case 1:
            script->varTable[15] = 2;
            break;
        case 2:
            script->varTable[15] = 3;
            break;
        default:
            break;
    }

    return ApiStatus_DONE2;
}
