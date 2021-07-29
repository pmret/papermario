#include "common.h"

extern f32 N(floatTable)[];

u32 N(BattleAreaAngleStuff1)(f32 x, f32 y) {
    f32 tempF = abs(y) / length2D(x, y);
    u16 angle1 = 0;
    u16 angle2 = 90;
    u16 ret;
    u16 i;

    for (i = 0; i < 7; i++) {
        u16 temp_v1 = angle1 + ((angle2 - angle1) / 2);

        if (N(floatTable)[temp_v1] < tempF) {
            angle1 = temp_v1;
        } else {
            angle2 = temp_v1;
        }
    }

    if (fabsf(N(floatTable)[angle1] - tempF) < fabsf(N(floatTable)[angle2] - tempF)) {
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

ApiStatus N(BattleAreaAngleStuff2)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args);

    var3 -= var1;
    var4 -= var2;

    if (var3 == 0 && var4 == 0) {
        set_variable(script, *args, var5);
        return ApiStatus_DONE2;
    } else {
        set_variable(script, *args, N(BattleAreaAngleStuff1)(var3, var4) - 90);
        return ApiStatus_DONE2;
    }
}
