#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc1)) {
    increment_status_bar_disabled();
    set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, 255.0f);
    return ApiStatus_DONE2;
}
