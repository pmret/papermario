#include "kpa_14.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"

ApiStatus N(func_80240710_A57BC0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *args++, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

ApiStatus func_8024073C_A57BEC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 xVel = evt_get_variable(script, *args++);
    s32 floor = evt_get_variable(script, *args++);
    s32 temp_a0 = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gCollisionStatus.currentFloor == floor || gCollisionStatus.lastTouchedFloor == floor) {
        if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP &&
            playerStatus->actionState != ACTION_STATE_SPIN_JUMP &&
            temp_a0 == 0)
        {
            playerStatus->extraVelocity.x = xVel;
        }
    }
    if (gPlayerData.currentPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        if (partner->currentFloor == floor) {
            partner->pos.x += xVel;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(IsPartnerLakilester)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
