#include "common.h"

#define NAMESPACE code_EFEB00

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

#include "common/DeadUnk1.inc.c"

INCLUDE_ASM(s32, "code_EFEB00", func_80240340_EFEE40);
/*
ApiStatus N(func_80240340_EFEE40)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_EFEB00", func_802404D0_EFEFD0);

INCLUDE_ASM(s32, "code_EFEB00", func_80240540_EFF040);

INCLUDE_ASM(s32, "code_EFEB00", func_80240660_EFF160);

INCLUDE_ASM(s32, "code_EFEB00", func_80240784_EFF284);

INCLUDE_ASM(s32, "code_EFEB00", func_802407B0_EFF2B0);