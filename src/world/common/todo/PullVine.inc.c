#include "common.h"
#include "model.h"

ApiStatus N(PullVine_WaitForPlayerGrab)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 modelX, modelY, modelZ;
    f32 dx, dy, dz;
    f32 dist;
    s32 result;

    modelX = evt_get_float_variable(script, *args++);
    modelY = evt_get_float_variable(script, *args++) + 15.0f;
    modelZ = evt_get_float_variable(script, *args++);
    dist = evt_get_float_variable(script, *args++);
    dx = script->varTable[0] - modelX;
    dy = script->varTable[1] - modelY;
    dz = script->varTable[2] - modelZ;
    result = 1;
    if (!(SQ(dx) + SQ(dy) + SQ(dz) < SQ(dist))) {
        result = 0;
    }
    script->varTable[0] = result;
    return ApiStatus_DONE2;
}

ApiStatus N(PullVine_UpdatePosition)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x1 = evt_get_float_variable(script, *args++);
    f32 x2 = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, *args++, (x2 - x1) / 10.0f);
    return ApiStatus_DONE2;
}

#include "world/common/todo/PullVineSub.inc.c"
