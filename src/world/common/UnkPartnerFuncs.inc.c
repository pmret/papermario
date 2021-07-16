#include "common.h"
#include "map.h"

ApiStatus N(UnkRotatePartner)(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    partner->yaw += 30.0f;
    if (partner->yaw >= 360.0f) {
        partner->yaw -= 360.0f;
    }

    script->functionTemp[0]--;

    return (script->functionTemp[0] >> 0x1F) & ApiStatus_DONE2;
}

ApiStatus N(UnkMovePartner)(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_PARTNER);
    f32* x = (f32*) &script->functionTemp[1];
    f32* y = (f32*) &script->functionTemp[2];
    f32* z = (f32*) &script->functionTemp[3];

    if (isInitialCall) {
        *x = get_float_variable(script, SI_VAR(0)) / 60.0f;
        *y = get_float_variable(script, SI_VAR(5)) / 60.0f;
        *z = get_float_variable(script, SI_VAR(1)) / 60.0f;
        script->functionTemp[0] = 60;
    }

    npc->pos.x += *x;
    npc->pos.y += *y;
    npc->pos.z += *z;
    script->functionTemp[0]--;

    return (script->functionTemp[0] == 0) * ApiStatus_DONE2;
}
