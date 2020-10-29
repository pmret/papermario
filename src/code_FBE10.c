#include "common.h"

void func_802D7460(f32 x, f32 y, f32 z, s32 arg3);
INCLUDE_ASM(void, "code_fa4c0_len_3bf0", func_802D7460, f32 x, f32 y, f32 z, s32 arg3);

void func_802D74C0(f32 x, f32 y, f32 z, s32 arg3);
INCLUDE_ASM(void, "code_fa4c0_len_3bf0", func_802D74C0, f32 x, f32 y, f32 z, s32 arg3);

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    func_802D7460(x, y, z, get_variable(script, *args++));
    play_sound_at_position(0x2055, 0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    func_802D74C0(x, y, z, get_variable(script, *args++));
    play_sound_at_position(0x378, 0, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_FBE10", func_802D7690);

INCLUDE_ASM(s32, "code_FBE10", ShowEmote, ScriptInstance* script, s32 isInitialCall);

ApiStatus RemoveEffect(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    remove_effect(get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B10(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *args++);

    *ptrValue |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B44(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[5] = 10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B74(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[12] = 5;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_FBE10", func_802D7BA4);

ApiStatus func_802D7CF8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args++);
    s32 var6 = get_variable(script, *args++);
    ScriptInstance* newScript = start_script(&D_802D9D50, 1, 0);

    newScript->varTable[0] = var0;
    newScript->varTable[1] = var1;
    newScript->varTable[2] = var2;
    newScript->varTable[3] = var3;
    newScript->varTable[4] = var4;
    newScript->varTable[5] = var5;
    newScript->varTable[6] = var6;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_FBE10", func_802D7E08);

INCLUDE_ASM(s32, "code_FBE10", ShowSleepBubble);

INCLUDE_ASM(s32, "code_FBE10", func_802D8248);

INCLUDE_ASM(s32, "code_FBE10", PlayEffect);
