#include "common.h"

// TODO: determine purpose and name accordingly

f32 N(angleTable)[] = {
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

u32 N(angle_calculate)(f32 x, f32 y) {
    f32 tempF = abs(y) / length2D(x, y);
    u16 angle1 = 0;
    u16 angle2 = 90;
    u16 ret;
    u16 i;

    for (i = 0; i < 7; i++) {
        u16 temp_v1 = angle1 + ((angle2 - angle1) / 2);

        if (N(angleTable)[temp_v1] < tempF) {
            angle1 = temp_v1;
        } else {
            angle2 = temp_v1;
        }
    }

    if (fabsf(N(angleTable)[angle1] - tempF) < fabsf(N(angleTable)[angle2] - tempF)) {
        ret = angle1;
    } else {
        ret = angle2;
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

ApiStatus N(AngleCalculate)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args);

    var3 -= var1;
    var4 -= var2;

    if (var3 == 0 && var4 == 0) {
        evt_set_variable(script, *args, var5);
        return ApiStatus_DONE2;
    } else {
        evt_set_variable(script, *args, N(angle_calculate)(var3, var4) - 90);
        return ApiStatus_DONE2;
    }
}
