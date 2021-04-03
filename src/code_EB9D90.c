#include "common.h"

INCLUDE_ASM(s32, "code_EB9D90", func_80240F40_EB9D90);

INCLUDE_ASM(s32, "code_EB9D90", func_80240FB0_EB9E00);

INCLUDE_ASM(s32, "code_EB9D90", func_802410E4_EB9F34);

INCLUDE_ASM(s32, "code_EB9D90", func_8024121C_EBA06C);
/*
A) {
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
*/

INCLUDE_ASM(s32, "code_EB9D90", func_802413AC_EBA1FC);

INCLUDE_ASM(s32, "code_EB9D90", func_802413CC_EBA21C);

INCLUDE_ASM(s32, "code_EB9D90", func_802413EC_EBA23C);
