#include "kpa_111.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_80240000_A99590);
/*
ApiStatus N(func_80240000_A99590)(ScriptInstance *script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;

    if (((collisionStatus->pushingAgainstWall != var) && (playerStatus->actionState == 20)) ||
        playerStatus->enableCollisionOverlapsCheck || playerStatus->statusMenuCounterinputEnabledCounter) {
        set_action_state(0);
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    if (collisionStatus->pushingAgainstWall != var) {
        script->varTable[0] = 0;
    } else if ((playerStatus->actionState != 20) && (playerStatus->actionState != 1) &&
               (playerStatus->actionState != 2)) {
        script->varTable[0] = 0;
    } else if (playerStatus->animFlags & 1) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_802400BC_A9964C);
/*
ApiStatus N(func_802400BC_A9964C)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_80240170_A99700);

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_80240360_A998F0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_802404A4_A99A34);

#include "world/common/UnkSetDurationFunc.inc.c"

#include "world/common/UnkNpcAIFunc9.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_802406CC_A99C5C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_80240C08_A9A198);

INCLUDE_ASM(s32, "world/area_kpa/kpa_111/A99590", func_80241064_A9A5F4);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"
