#include "common.h"
#include "battle/battle.h"

ApiStatus N(UnkFloatFunc3)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 destBytecode1;
    s32 destBytecode2;
    s32 destBytecode3;
    f32 x;
    f32 y;
    f32 float3;
    f32 angle;
    // Seems to be necessary to get the stack allocations to line up.
    s8 unused[0x40];

    angle = evt_get_variable(script, *args++) / 10.0;
    angle = angle * TAU;
    angle = angle / 360.0f;

    destBytecode1 = *args++;
    destBytecode2 = *args++;
    destBytecode3 = *args++;

    x = sin_rad(angle) * 150.0f + 0.0f;
    y = cos_rad(angle) * 150.0f + 0.0f;
    float3 = -252.0f;

    x -= script->varTable[11];
    y -= script->varTable[12];
    float3 -= script->varTable[13];

    evt_set_float_variable(script, destBytecode1, x);
    evt_set_float_variable(script, destBytecode2, y);
    evt_set_float_variable(script, destBytecode3, float3);

    return ApiStatus_DONE2;
}
