#include "pra_31.h"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240510_D7F270);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240818_D7F578);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240894_D7F5F4);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240A3C_D7F79C);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", delete_actor_D7F91C);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240C70_D7F9D0);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240DBC_D7FB1C);
/*
ApiStatus N(func_80240DBC_D7FB1C)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 posX, posY, posZ, posW;

    if (script->varTable[5] == 0) {
        playerStatus->position.x = script->varTable[0];
    } else {
        playerStatus->position.z = script->varTable[0];
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
*/

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240E70_D7FBD0);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240F2C_D7FC8C);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240FD0_D7FD30);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240FF0_D7FD50);
