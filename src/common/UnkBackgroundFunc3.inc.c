#include "common.h"

ApiStatus N(UnkBackgroundFunc3)(ScriptInstance* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(1);
    *D_801512F0 = 1;
    set_background_color_blend(0, 0, 0, 0);
    return ApiStatus_DONE2;
}
