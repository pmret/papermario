#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc12)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 posX, posY, posZ, posW;

    if (script->varTable[5].s == 0) {
        playerStatus->position.x = script->varTable[0].s;
    } else {
        playerStatus->position.z = script->varTable[0].s;
    }

    posX = playerStatus->position.x;
    posY = playerStatus->position.y + 10.0f;
    posZ = playerStatus->position.z;
    posW = 40.0f;
    func_800DCB7C(0, &posX, &posY, &posZ, &posW);
    playerStatus->position.x = posX;
    playerStatus->position.y = posY;
    playerStatus->position.z = posZ;

    return ApiStatus_DONE2;
}
