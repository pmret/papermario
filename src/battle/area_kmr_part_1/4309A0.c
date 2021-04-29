#include "common.h"

#define NAMESPACE b_area_kmr_part_1

extern f32 D_8021A194_432B34[];

//INCLUDE_ASM(s32, "battle/area_kmr_part_1/4309A0", func_80218000_4309A0, f32 arg0, f32 arg1); // goomba.c
u32 func_80218000_4309A0(f32 x, f32 y) {
    f32 tempF = abs(y) / length2D(x, y);
    u16 angle1 = 0;
    u16 angle2 = 90;
    u16 ret;
    u16 i;

    for (i = 0; i < 7; i++) {
        u16 temp_v1 = angle1 + ((angle2 - angle1) / 2);

        if (D_8021A194_432B34[temp_v1] < tempF) {
            angle1 = temp_v1;
        } else {
            angle2 = temp_v1;
        }
    }

    if (fabsf(D_8021A194_432B34[angle1] - tempF) < fabsf(D_8021A194_432B34[angle2] - tempF)) {
        ret = angle1;
    } else {
        ret = angle2;
    }

    if (x < 0.0f && y >= 0.0f) {
        ret = 180 - ret;
    }

    if (x < 0.0f && y < 0.0f) {
        ret += 180;
    }

    if (x >= 0.0f && y < 0.0f) {
        ret = 360 - ret;
    }

    return ret;
}

//INCLUDE_ASM(s32, "battle/area_kmr_part_1/4309A0", func_8021818C_430B2C);
ApiStatus func_8021818C_430B2C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args);

    var3 -= var1;
    var4 -= var2;

    if (var3 == 0 && var4 == 0) {
        set_variable(script, *args, var5);
        return ApiStatus_DONE2;
    } else {
        set_variable(script, *args, func_80218000_4309A0(var3, var4) - 90);
        return ApiStatus_DONE2;
    }
}

INCLUDE_ASM(s32, "battle/area_kmr_part_1/4309A0", func_80218280_430C20, f32 arg0, f32 arg1);

// same as func_8021818C_430B2C
ApiStatus func_8021840C_430DAC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args);

    var3 -= var1;
    var4 -= var2;

    if (var3 == 0 && var4 == 0) {
        set_variable(script, *args, var5);
        return ApiStatus_DONE2;
    } else {
        set_variable(script, *args, func_80218280_430C20(var3, var4) - 90);
        return ApiStatus_DONE2;
    }
}

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_kmr_part_1/4309A0", func_80218558_430EF8, f32 arg0, f32 arg1);

// same as func_8021818C_430B2C
ApiStatus func_802186E4_431084(ScriptInstance* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args);

    var3 -= var1;
    var4 -= var2;

    if (var3 == 0 && var4 == 0) {
        set_variable(script, *args, var5);
        return ApiStatus_DONE2;
    } else {
        set_variable(script, *args, func_80218558_430EF8(var3, var4) - 90);
        return ApiStatus_DONE2;
    }
}
