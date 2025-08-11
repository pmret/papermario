#include "common.h"
#include "npc.h"

API_CALLABLE(N(ApproachPlayer100Units)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;
    Npc* npc = resolve_npc(script, npcID);
    s32 isCloseToPlayer;
    f32 angle;
    f32 posX;
    f32 posZ;

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    if (dist2D(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z) < 100.0f) {
        isCloseToPlayer = false;
    } else {
        isCloseToPlayer = true;
    }

    angle = clamp_angle(atan2(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z));
    posX = playerStatus->pos.x + (sin_deg(angle) * 100.0f);
    posZ = playerStatus->pos.z - (cos_deg(angle) * 100.0f);
    evt_set_variable(script, outVar1, isCloseToPlayer);
    evt_set_variable(script, outVar2, posX);
    evt_set_variable(script, outVar3, posZ);
    return ApiStatus_DONE2;
}
