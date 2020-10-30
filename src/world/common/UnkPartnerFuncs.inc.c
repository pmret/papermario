#include "common.h"

static ApiStatus UnkRotatePartner(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = get_npc_unsafe(NpcId_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0].s = 60;
    }

    partner->yaw += 30.0f;
    if (partner->yaw >= 360.0f) {
        partner->yaw -= 360.0f;
    }

    script->functionTemp[0].s--;

    return (script->functionTemp[0].s >> 0x1F) & ApiStatus_DONE2;
}


static ApiStatus UnkMovePartner(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NpcId_PARTNER);

    if (isInitialCall) {
        script->functionTemp[1].f = get_float_variable(script, SI_VAR(0)) / 60.0f;
        script->functionTemp[2].f = get_float_variable(script, SI_VAR(5)) / 60.0f;
        script->functionTemp[3].f = get_float_variable(script, SI_VAR(1)) / 60.0f;
        script->functionTemp[0].s = 60;
    }

    npc->pos.x += script->functionTemp[1].f;
    npc->pos.y += script->functionTemp[2].f;
    npc->pos.z += script->functionTemp[3].f;
    script->functionTemp[0].s--;

    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}
