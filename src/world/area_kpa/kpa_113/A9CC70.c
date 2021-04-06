#include "kpa_113.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_113/A9CC70", func_80240040_A9CC70);
/*
ApiStatus N(func_80240040_A9CC70)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_113/A9CC70", func_802400FC_A9CD2C);
/*
ApiStatus N(func_802400FC_A9CD2C)(ScriptInstance *script, s32 isInitialCall) {
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

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_113/A9CC70", func_8024022C_A9CE5C);

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_113/A9CC70", func_80240544_A9D174);

#include "world/common/AwaitPlayerNearNpc.inc.c"
