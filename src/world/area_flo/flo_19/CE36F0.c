#include "flo_19.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_19/CE36F0", func_8024030C_CE39FC);
/*
void func_80072950();

ApiStatus N(func_8024030C_CE39FC)(ScriptInstance* script, s32 isInitialCall) {
    func_80072950(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
*/

// Identical to UnkFloatFunc except for the presence of the fabsf
ApiStatus func_80240340_CE3A30(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a1 = *args++;
    s32 var0 = get_variable(script, a1);
    s32 a2 = *args++;
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    f32 temp = (get_float_variable(script, *args++) / 180.0f) * PI;
    f32 diff = fabsf(var2 - var1) / 2;

    if (var4 != 0 && var3 < var0) {
        var0 = var3;
        set_variable(script, a1, var3);
    }

    set_float_variable(script, a2, (var1 + diff) - (diff * cos_rad(((var0 * PI) / var3) + temp)));

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_flo/flo_19/CE36F0", func_802404D0_CE3BC0);
/*
ApiStatus N(func_802404D0_CE3BC0)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_19/CE36F0", func_80240540_CE3C30);

INCLUDE_ASM(s32, "world/area_flo/flo_19/CE36F0", func_80240660_CE3D50);

INCLUDE_ASM(s32, "world/area_flo/flo_19/CE36F0", func_80240784_CE3E74);

#include "common/UnkFloatFunc.inc.c"
