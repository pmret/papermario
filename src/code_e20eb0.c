#include "common.h"

s32 func_802B7000(f32 angle) {
    s32 angleDiff;

    if (angle >= 270.0f) {
        angleDiff = 360.0f - angle;
    } else if (angle >= 180.0f) {
        angleDiff = angle - 180.0f;
    } else if (angle >= 90.0f) {
        angleDiff = 180.0f - angle;
    } else {
        angleDiff = angle;
    }
    return 0xFF - angleDiff - angleDiff;
}

INCLUDE_ASM("code_e20eb0", func_802B70B4);

INCLUDE_ASM("code_e20eb0", func_802B71C8);

INCLUDE_ASM("code_e20eb0", func_802B742C);
