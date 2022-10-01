#include "kkj_25.h"

ApiStatus func_80240020_B06A20(Evt* script, s32 isInitialCall) {
    increment_status_menu_disabled();
    set_screen_overlay_params_back(0, 255.0f);

    return ApiStatus_DONE2;
}
