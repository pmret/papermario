#include "common.h"
#include "npc.h"

// Similar to ApproachPlayer100Units but compares with 50.0f instead of 100.0f. TODO maybe turn into a define?
API_CALLABLE(N(ApproachPlayer50Units)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;
    Npc* npc = resolve_npc(script, npcID);
    s32 phi_s4;
    f32 angle;
    f32 x;
    f32 z;

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    if (dist2D(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z) < 50.0f) {
        phi_s4 = false;
    } else {
        phi_s4 = true;
    }

    angle = clamp_angle(atan2(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z));
    x = playerStatus->pos.x + (sin_deg(angle) * 50.0f);
    z = playerStatus->pos.z - (cos_deg(angle) * 50.0f);
    evt_set_variable(script, outVar1, phi_s4);
    evt_set_variable(script, outVar2, x);
    evt_set_variable(script, outVar3, z);
    return ApiStatus_DONE2;
}
