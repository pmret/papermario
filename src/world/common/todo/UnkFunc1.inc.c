#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc1)) {
    increment_status_menu_disabled();
    set_screen_overlay_params_back(0, 255.0f);
    return ApiStatus_DONE2;
}
