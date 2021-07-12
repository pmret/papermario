#include "common.h"

ApiStatus N(UnkBackgroundFunc2)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);
    script->functionTemp[0].s += 10;

    if (script->functionTemp[0].s >= 230) {
        set_background_color_blend(0, 0, 0, 230);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
