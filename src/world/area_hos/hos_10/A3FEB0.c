#include "hos_10.h"

INCLUDE_ASM(s32, "world/area_hos/hos_10/A3FEB0", func_80240770_A3FEB0);

INCLUDE_ASM(s32, "world/area_hos/hos_10/A3FEB0", func_80240A84_A401C4);

INCLUDE_ASM(s32, "world/area_hos/hos_10/A3FEB0", func_80240B44_A40284);

INCLUDE_ASM(s32, "world/area_hos/hos_10/A3FEB0", func_80240B98_A402D8);

ApiStatus func_80240BEC_A4032C(Evt* script, s32 isInitialCall) {
    gPlayerData.currentPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

ApiStatus func_80240BFC_A4033C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(0, 208, 208, 208);
    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 7;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}
