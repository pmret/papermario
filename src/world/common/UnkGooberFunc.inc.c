#include "common.h"
#include "npc.h"

ApiStatus N(UnkGooberFunc)(Evt* script, s32 isInitialCall) {
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

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (dist2D(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z) < 100.0f) {
        phi_s4 = FALSE;
    } else {
        phi_s4 = TRUE;
    }

    angle = clamp_angle(atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z));
    x = playerStatus->position.x + (sin_deg(angle) * 100.0f);
    z = playerStatus->position.z - (cos_deg(angle) * 100.0f);
    evt_set_variable(script, outVar1, phi_s4);
    evt_set_variable(script, outVar2, x);
    evt_set_variable(script, outVar3, z);
    return ApiStatus_DONE2;
}
