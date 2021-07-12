#include "common.h"
#include "map.h"

ApiStatus N(FadeBackgroundToBlack)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 20;
    }

    set_background_color_blend(0, 0, 0, ((20 - script->functionTemp[0].s) * 10) & 254);
    script->functionTemp[0].s--;
    do {} while (0);
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}
