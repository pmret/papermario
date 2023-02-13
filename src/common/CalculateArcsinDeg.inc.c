#include "common.h"

f32 N(sinTable)[] = {
    0.000000f, 0.017452f, 0.034899f, 0.052336f, 0.069756f, 0.087156f, 0.104528f, 0.121869f,
    0.139173f, 0.156434f, 0.173648f, 0.190809f, 0.207912f, 0.224951f, 0.241922f, 0.258819f,
    0.275637f, 0.292372f, 0.309017f, 0.325568f, 0.342020f, 0.358368f, 0.374607f, 0.390731f,
    0.406737f, 0.422618f, 0.438371f, 0.453990f, 0.469472f, 0.484810f, 0.500000f, 0.515038f,
    0.529919f, 0.544639f, 0.559193f, 0.573576f, 0.587785f, 0.601815f, 0.615661f, 0.629320f,
    0.642788f, 0.656059f, 0.669131f, 0.681998f, 0.694658f, 0.707107f, 0.719340f, 0.731354f,
    0.743145f, 0.754710f, 0.766044f, 0.777146f, 0.788011f, 0.798636f, 0.809017f, 0.819152f,
    0.829038f, 0.838671f, 0.848048f, 0.857167f, 0.866025f, 0.874620f, 0.882948f, 0.891007f,
    0.898794f, 0.906308f, 0.913545f, 0.920505f, 0.927184f, 0.933580f, 0.939693f, 0.945519f,
    0.951057f, 0.956305f, 0.961262f, 0.965926f, 0.970296f, 0.974370f, 0.978148f, 0.981627f,
    0.984808f, 0.987688f, 0.990268f, 0.992546f, 0.994522f, 0.996195f, 0.997564f, 0.998630f,
    0.999391f, 0.999848f, 1.000000f,
};

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

API_CALLABLE(N(CalculateArcsinDeg)) {
    Bytecode* args = script->ptrReadPos;
    s32 x1 = evt_get_variable(script, *args++);
    s32 y1 = evt_get_variable(script, *args++);
    s32 x2 = evt_get_variable(script, *args++);
    s32 y2 = evt_get_variable(script, *args++);
    s32 outVar = evt_get_variable(script, *args);

    x2 -= x1;
    y2 -= y1;

    if (x2 == 0 && y2 == 0) {
        evt_set_variable(script, *args++, outVar);
        return ApiStatus_DONE2;
    } else {
        evt_set_variable(script, *args++, N(ArcsinDeg)(x2, y2) - 90);
        return ApiStatus_DONE2;
    }
}
