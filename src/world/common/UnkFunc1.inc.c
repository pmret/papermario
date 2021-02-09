#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc1)(ScriptInstance* script, s32 isInitialCall) {
    increment_status_menu_disabled();
    set_transition_stencil_zoom_1(0, 255.0f);
    return ApiStatus_DONE2;
}
