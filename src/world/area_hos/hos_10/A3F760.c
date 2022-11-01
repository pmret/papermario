#include "hos_10.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024032C_A3FA6C(Evt* script, s32 isInitialCall) {
    if (
        gGameStatusPtr->creditsViewportMode == 0 ||
        gGameStatusPtr->creditsViewportMode == 1 ||
        gGameStatusPtr->creditsViewportMode == 2 ||
        gGameStatusPtr->creditsViewportMode == 3 ||
        gGameStatusPtr->creditsViewportMode == 4)
    {
        gGameStatusPtr->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

void func_80240364_A3FAA4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4) {
    f32 temp_f2 = arg1 - arg2;

    if (arg1 - arg0 > 0.0f) {
        if (temp_f2 < 0.0f) {
            *arg4 = arg1;
        } else if (arg3 < temp_f2) {
            *arg4 += arg3;
        } else {
            *arg4 += temp_f2;
        }
    } else if (temp_f2 > 0.0f) {
        *arg4 = arg1;
    } else if (temp_f2 < -arg3) {
        *arg4 -= arg3;
    } else {
        *arg4 += temp_f2;
    }
}

ApiStatus func_80240404_A3FB44(Evt* script, s32 isInitialCall) {
    fx_star(1, 200.0f, 400.0f, 1200.0f, -300.0f, -100.0f, 0.0f, 30.0f);
    return ApiStatus_DONE2;
}
