#include "common.h"

// TODO: Figure out what this function is doing
s32 func_802B7000(f32 angle) {
    s32 angleDiff;

    if (270.0f <= angle) {
        angleDiff = 360.0f - angle;
    } else if (180.0f <= angle) {
        angleDiff = angle - 180.0f;
    } else if (90.0f <= angle) {
        angleDiff = 180.0f - angle;
    } else {
        angleDiff = angle;
    }
    return 0xFF - angleDiff - angleDiff;
}

INCLUDE_ASM(code_e20eb0, func_802B70B4);

INCLUDE_ASM(code_e20eb0, func_802B71C8);

INCLUDE_ASM(code_e20eb0, func_802B742C);
