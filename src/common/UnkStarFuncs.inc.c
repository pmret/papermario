#include "common.h"

ApiStatus N(UnkStarFunc1)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_8006FEF0(0, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc2)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_80070550(5, a, b, c, 50.0f, 50.0f, 40, 30);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc3)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_8006FEF0(0, a, b, c, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_80072350(4, var1, var2, get_variable(script, *args++), 20.0f, 20.0f, 1.0f, 0xA, 0xF);
    return ApiStatus_DONE2;
}
