#include "kkj_27.h"

extern s32 D_80240B00_B14870;

ApiStatus func_80240310_B14080(Evt* script, s32 isInitialCall) {
    f32 angle;
    f32 mag;
    f32 var;

    var = script->varTable[2] + 230000000;
    var /= 1024.0f;

    mag = dist2D(-250.0f, 0.0f, script->varTable[9], script->varTable[10]);
    angle = atan2(-250.0f, 0.0f, script->varTable[9], script->varTable[10]);
    angle = clamp_angle(angle - var);

    gPlayerStatus.position.x = -250.0f + mag * sin_deg(angle);
    gPlayerStatus.position.z = 0.0f - mag * cos_deg(angle);

    return ApiStatus_DONE2;
}

ApiStatus func_8024041C_B1418C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80240B00_B14870 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_80240448_B141B8(void) {
    if (D_80240B00_B14870 > 0) {
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80240B00_B14870);
    }
}
