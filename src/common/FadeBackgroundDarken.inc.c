#include "common.h"
#include "model.h"
#include "npc.h"

API_CALLABLE(N(FadeBackgroundDarken)) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(FOG_MODE_1);
        *gBackgroundFogModePtr = FOG_MODE_1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, ((20 - script->functionTemp[0]) * 10) & 254);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
