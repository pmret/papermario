#include "kzn_02.h"

ApiStatus func_80240310_C5AA50(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;

    get_model_center_and_size(evt_get_variable(script, *args++), &sp20, &sp24, &sp28, &sp2C, &sp30, &sp34);
    script->varTable[7] = sp20;
    script->varTable[8] = sp28;
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

ApiStatus func_802403B0_C5AAF0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    evt_set_variable(script, *args++, gPartnerActionStatus.actingPartner);
    return ApiStatus_DONE2;
}

ApiStatus func_802403DC_C5AB1C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s1 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus= &gCollisionStatus;
    Npc* partner;

    if ((collisionStatus->currentFloor == temp_s1) || ((collisionStatus->lastTouchedFloor == temp_s1)) || (collisionStatus->currentFloor == temp_s0_3) || (collisionStatus->lastTouchedFloor == temp_s0_3)) {
        playerStatus->extraVelocity.x = temp_s2;
    }
    if (gPlayerData.currentPartner != 0){
        partner = get_npc_unsafe(-4);
        if ((partner->currentFloor == temp_s1) || (partner->currentFloor == temp_s0_3)) {
            partner->pos.x += temp_s2;
        }
    }
    return ApiStatus_DONE2;
}
