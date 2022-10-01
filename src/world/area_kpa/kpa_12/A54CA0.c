#include "kpa_12.h"

ApiStatus N(func_80240350_A54CA0)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

ApiStatus func_8024037C_A54CCC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 velocity = evt_get_variable(script, *args++);
    s32 floor = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gCollisionStatus.currentFloor == floor || gCollisionStatus.lastTouchedFloor == floor) {
        playerStatus->pushVelocity.x = velocity;
    }

    if (gPlayerData.currentPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        if (partner->currentFloor == floor) {
            partner->pos.x += velocity;
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
