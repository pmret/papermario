#include "battle/battle.h"

API_CALLABLE(N(UnkFloatFunc005)) {
    Bytecode* args = script->ptrReadPos;
    #ifdef AVOID_UB
    f32 vt0 = 0.0f;
    f32 vt1 = 0.0f;
    f32 vt2 = 0.0f;
    #else
    f32 vt0;
    f32 vt1;
    f32 vt2;
    #endif
    f32 vt3;
    f32 vt4;
    f32 vt5;
    f32 vt6;
    f32 vt7;

    f64 temp_f20;
    f64 temp_f20_2;
    f64 temp_f20_3;
    f64 temp_f20_4;
    s32 temp_s1;

    script->functionTemp[0] = temp_s1 = evt_get_variable(script, *args++);

    switch (temp_s1) {
        case 0:
            vt0 = 142.0f;
            vt1 = 0.0f;
            vt2 = -118.0f;
            script->varTable[3] = 142;
            script->varTable[4] = 0;
            script->varTable[5] = -118;
            script->varTable[6] = 44;
            script->varTable[7] = -118;
            script->varTable[8] = 3;
            script->varTable[9] = 0;
            script->varTable[11] = 0;
            script->functionTemp[0] = 1;
            break;
        case 3:
            vt0 = 91.0f;
            vt1 = 0.0f;
            vt2 = -118.0f;
            script->varTable[3] = 91;
            script->varTable[4] = 0;
            script->varTable[5] = -118;
            script->varTable[6] = 91;
            script->varTable[7] = -118;
            script->varTable[8] = 3;
            script->varTable[9] = 0;
            script->varTable[11] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            script->varTable[9] += script->varTable[8];
            if (script->varTable[9] > 45) {
                script->varTable[9] = 45;
            }
            vt0 = script->varTable[3];
            vt1 = script->varTable[4];
            vt2 = script->varTable[5];
            vt3 = script->varTable[6];
            vt4 = script->varTable[7];
            temp_f20 = vt0 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt0 = (temp_f20 + (vt3 * sin_rad(DEG_TO_RAD(script->varTable[9]))));
            vt1 = vt1 + sin_rad(DEG_TO_RAD(script->varTable[9] * 2)) * 90.0f;
            temp_f20_2 = vt2 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt2 = temp_f20_2 + (vt4 * sin_rad(DEG_TO_RAD(script->varTable[9])));
            if (script->varTable[9] == 45) {
                script->varTable[11] = 1;
            }
            break;
        case 2:
            script->varTable[9] += script->varTable[8];
            if (script->varTable[9] > 90) {
                script->varTable[9] = 90;
            }
            vt0 = script->varTable[3];
            vt1 = script->varTable[4];
            vt2 = script->varTable[5];
            vt3 = script->varTable[6];
            vt4 = script->varTable[7];
            temp_f20_3 = vt0 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt0 = (temp_f20_3 + (vt3 * sin_rad(DEG_TO_RAD(script->varTable[9]))));
            vt1 = vt1 + sin_rad(DEG_TO_RAD(script->varTable[9] * 2)) * 90.0f;
            temp_f20_4 = vt2 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt2 = temp_f20_4 + (vt4 * sin_rad(DEG_TO_RAD(script->varTable[9])));
            if (script->varTable[9] == 90) {
                script->varTable[11] = 2;
            }
            break;
    }
    script->varTable[0] = vt0;
    script->varTable[1] = vt1;
    script->varTable[2] = vt2;
    return ApiStatus_DONE2;
}
