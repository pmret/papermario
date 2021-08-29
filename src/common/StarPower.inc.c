#include "common.h"
#include "effects.h"

ApiStatus N(UnkStarFunc1)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_11(0, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_22(5, a, b, c, 50.0f, 50.0f, 40, 30);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc3)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_11(0, a, b, c, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkStarFunc4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    playFX_72(4, var1, var2, evt_get_variable(script, *args++), 20.0f, 20.0f, 1.0f, 0xA, 0xF);
    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

#include "common/UnkStarFunc.inc.c"

#include "common/SetNpcCollision32.inc.c"
