#include "flo_00.h"

ApiStatus N(func_80240F10_C9EE30)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240F80_C9EEA0)(Evt* script, s32 isInitialCall) {
    f32 var1 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(-83.0f, 87.0f, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(atan2(-83.0f, 87.0f, script->varTable[9], script->varTable[11]) - var1);

    var1 = sin_deg(clamped);
    gPlayerStatus.position.x = (dist * var1) + -83.0f;
    gPlayerStatus.position.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    var1 = cos_deg(clamped);
    gPlayerStatus.position.z = 87.0f - (dist * var1);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802410B4_C9EFD4)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_by_index(0);
    f32 temp_f20 = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(-83.0f, 87.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(atan2(-83.0f, 87.0f, script->varTable[12], script->varTable[14]) - temp_f20);

    temp_f20 = sin_deg(clamped);
    npc->pos.x = (dist * temp_f20) + -83.0f;
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp_f20 = cos_deg(clamped);
    npc->pos.z = 87.0f - (dist * temp_f20);

    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

#include "world/common/todo/SyncStatusMenu.inc.c"

ApiStatus N(func_8024139C_C9F2BC)(Evt* script, s32 isInitialCall) {
    increment_status_menu_disabled();
    return ApiStatus_DONE2;
}

ApiStatus N(func_802413BC_C9F2DC)(Evt* script, s32 isInitialCall) {
    decrement_status_menu_disabled();
    return ApiStatus_DONE2;
}
