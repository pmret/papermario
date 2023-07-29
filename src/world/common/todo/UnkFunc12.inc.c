#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc12)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 posX, posY, posZ, hitDepth;

    if (script->varTable[5] == 0) {
        playerStatus->pos.x = script->varTable[0];
    } else {
        playerStatus->pos.z = script->varTable[0];
    }

    posX = playerStatus->pos.x;
    posY = playerStatus->pos.y + 10.0f;
    posZ = playerStatus->pos.z;
    hitDepth = 40.0f;

    npc_raycast_down_sides(0, &posX, &posY, &posZ, &hitDepth);

    playerStatus->pos.x = posX;
    playerStatus->pos.y = posY;
    playerStatus->pos.z = posZ;

    return ApiStatus_DONE2;
}
