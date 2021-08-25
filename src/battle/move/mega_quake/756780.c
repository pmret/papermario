#include "common.h"

#define NAMESPACE battle_move_mega_quake

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

ApiStatus func_802A10A4_756824(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] != 0) {
        if (script->functionTemp[0] != 1) {
            return ApiStatus_BLOCK;
        }
    } else {
        script->functionTemp[1] = 30;
        script->functionTemp[0] = 1;
    }

    set_screen_overlay_center(1, 0, 0, 0);
    set_screen_overlay_center(1, 1, SCREEN_WIDTH, SCREEN_HEIGHT);
    set_screen_overlay_params_back(12, 160.0f);

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    } else {
        set_screen_overlay_center(1, 0, 0, 0);
        set_screen_overlay_center(1, 1, SCREEN_WIDTH, SCREEN_HEIGHT);
        set_screen_overlay_params_back(12, 0.0f);
        return ApiStatus_DONE2;
    }
}
