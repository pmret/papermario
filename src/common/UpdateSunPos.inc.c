#include "common.h"
#include "battle/battle.h"

API_CALLABLE(N(UpdateSunPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 outPosX;
    s32 outPosY;
    s32 outPosZ;
    f32 x;
    f32 y;
    f32 z;
    f32 angle;
    // Needed to make stack allocations line up
#if !VERSION_PAL
    s8 unused[0x40];
#endif

    angle = evt_get_variable(script, *args++) / 10.0;
    angle = angle * TAU;
    angle = angle / 360.0f;

    outPosX = *args++;
    outPosY = *args++;
    outPosZ = *args++;

    x = sin_rad(angle) * 150.0f + 0.0f;
    y = cos_rad(angle) * 150.0f + 0.0f;
    z = -252.0f;

    x -= script->varTable[11];
    y -= script->varTable[12];
    z -= script->varTable[13];

    evt_set_float_variable(script, outPosX, x);
    evt_set_float_variable(script, outPosY, y);
    evt_set_float_variable(script, outPosZ, z);

    return ApiStatus_DONE2;
}
