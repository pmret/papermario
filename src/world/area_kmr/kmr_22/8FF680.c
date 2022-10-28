#include "kmr_22.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF680", func_80240010_8FF680);

ApiStatus func_802401E0_8FF850(Evt* script, s32 isInitialCall) {
    set_curtain_scale_goal(2.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240208_8FF878(Evt* script, s32 isInitialCall) {
    ApiStatus ret;

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_START) {
        ret = ApiStatus_DONE2;
    } else {
        ret = ApiStatus_BLOCK;
    }

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        ret = ApiStatus_DONE2;
        script->varTable[0] = -1;
    }
    return ret;
}
