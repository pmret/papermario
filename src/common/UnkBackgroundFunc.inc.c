#include "common.h"

ApiStatus N(UnkBackgroundFunc)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 20;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s * 10);
    script->functionTemp[0].s -= 1;

    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
