#include "flo_00.h"

ApiStatus N(func_80240F10_C9EE30)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus N(func_80240F80_C9EEA0)(ScriptInstance *script, s32 isInitialCall) {
    f32 var1 = get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(-83.0f, 87.0f, script->varTable[9], script->varTable[11]);

    var1 = clamp_angle(atan2(-83.0f, 87.0f, script->varTable[9], script->varTable[11]) - var1);

    gPlayerStatus.position.x = (dist * sin_deg(var1)) + -83.0f;
    gPlayerStatus.position.y = get_variable(NULL, script->varTable[10]) + get_variable(NULL, script->varTable[3]);
    gPlayerStatus.position.z = 87.0f - (dist * cos_deg(var1));

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_00/C9EE30", flo_00_func_80240F80_C9EEA0, ScriptInstance *script, s32 isInitialCall);
#endif

#ifdef NON_MATCHING
ApiStatus N(func_802410B4_C9EFD4)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_by_index(0);
    f32 temp_f20;
    f32 temp_f22;

    temp_f20 = get_variable(NULL, script->varTable[2]);
    temp_f22 = dist2D(-83.0f, 87.0f, script->varTable[12], script->varTable[14]);
    temp_f20 = clamp_angle(atan2(-83.0f, 87.0f, script->varTable[12], script->varTable[14]) - temp_f20);
    
    npc->pos.x = (temp_f22 * sin_deg(temp_f20)) + -83.0f;
    npc->pos.y = get_variable(NULL, script->varTable[13]) + get_variable(NULL, script->varTable[3]);
    npc->pos.z = 87.0f - (temp_f22 * cos_deg(temp_f20));
    
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_00/C9EE30", flo_00_func_802410B4_C9EFD4, ScriptInstance *script, s32 isInitialCall);
#endif

#include "common/UnkFloatFunc.inc.c"

#include "world/common/SyncStatusMenu.inc.c"

ApiStatus N(func_8024139C_C9F2BC)(ScriptInstance *script, s32 isInitialCall) {
    increment_status_menu_disabled();
    return ApiStatus_DONE2;
}

ApiStatus N(func_802413BC_C9F2DC)(ScriptInstance *script, s32 isInitialCall) {
    decrement_status_menu_disabled();
    return ApiStatus_DONE2;
}
