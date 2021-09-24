#include "dead.h"
#include "common.h"

// This whole file seems to be a dead/unused flo map?
// It especially shares a lot of familiarities with flo_19

#define NAMESPACE EFEB00

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

#include "common/DeadUnk1.inc.c"

#include "common/DeadUnkFloatFuncAbs.inc.c"

ApiStatus func_802404D0_EFEFD0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

ApiStatus func_80240540_EFF040(Evt* script, s32 isInitialCall) {
    f32 temp_f20 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 temp_f22 = clamp_angle(atan2(0.0f, 0.0f, script->varTable[9], script->varTable[11]) - temp_f20);

    temp_f20 = sin_deg(temp_f22);
    gPlayerStatus.position.x = (dist * temp_f20) + 0.0f;
    gPlayerStatus.position.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp_f20 = cos_deg(temp_f22);
    gPlayerStatus.position.z = 0.0f - (dist * temp_f20);

    return ApiStatus_DONE2;
}

ApiStatus func_80240660_EFF160(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_by_index(0);
    f32 temp_f20 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(atan2(0.0f, 0.0f, script->varTable[12], script->varTable[14]) - temp_f20);

    temp_f20 = sin_deg(clamped);
    npc->pos.x = (dist * temp_f20) + 0.0f;
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp_f20 = cos_deg(clamped);
    npc->pos.z = 0.0f - (dist * temp_f20);

    return ApiStatus_DONE2;
}

ApiStatus func_80240784_EFF284(Evt* script, s32 isInitialCall) {
    set_screen_overlay_params_back(1, script->varTable[0]);
    return ApiStatus_DONE2;
}

#include "common/DeadUnkFloatFunc.inc.c"

