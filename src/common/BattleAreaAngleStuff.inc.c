#include "common.h"

// TODO: Define the table.
extern f32 N(sinTable)[];

u32 N(ArcsinDeg)(f32 x, f32 y) {
    f32 sinAngle = abs(y) / length2D(x, y);
    u16 minAngle = 0;
    u16 maxAngle = 90;
    u16 ret;
    u16 i;

    for (i = 0; i < 7; i++) {
        u16 midAngle = minAngle + ((maxAngle - minAngle) / 2);

        if (N(sinTable)[midAngle] < sinAngle) {
            minAngle = midAngle;
        } else {
            maxAngle = midAngle;
        }
    }

    if (fabsf(N(sinTable)[minAngle] - sinAngle) < fabsf(N(sinTable)[maxAngle] - sinAngle)) {
        ret = minAngle;
    } else {
        ret = maxAngle;
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

ApiStatus N(CalculateRotationZ)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x1 = evt_get_variable(script, *args++);
    s32 y1 = evt_get_variable(script, *args++);
    s32 x2 = evt_get_variable(script, *args++);
    s32 y2 = evt_get_variable(script, *args++);
    s32 outVar = evt_get_variable(script, *args);

    x2 -= x1;
    y2 -= y1;

    if (x2 == 0 && y2 == 0) {
        evt_set_variable(script, *args, outVar);
        return ApiStatus_DONE2;
    } else {
        evt_set_variable(script, *args, N(ArcsinDeg)(x2, y2) - 90);
        return ApiStatus_DONE2;
    }
}
