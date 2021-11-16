#include "common.h"

#define NAMESPACE b_area_pra2

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkFloatFunc.inc.c"

ApiStatus GetActorPartOpacity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    evt_set_variable(script, *args++, get_actor_part(get_actor(actorID), partIndex)->opacity);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_pra2/660750", func_80218280_6609D0);

INCLUDE_ASM(s32, "battle/area_pra2/660750", func_802182E4_660A34);

INCLUDE_ASM(s32, "battle/area_pra2/660750", func_80218344_660A94);

ApiStatus func_802183A4_660AF4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 startX = evt_get_variable(script, *args++);
    f32 startZ = evt_get_variable(script, *args++);
    f32 endX = evt_get_variable(script, *args++);
    f32 endZ = evt_get_variable(script, *args++);

    evt_set_variable(script, arg0, atan2(startX, startZ, endX, endZ));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_pra2/660750", func_8021848C_660BDC);
