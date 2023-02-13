#include "common.h"
#include "model.h"

API_CALLABLE(N(UnkBackgroundFunc2)) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(FOG_MODE_1);
        *gBackgroundFogModePtr = FOG_MODE_1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] += 10;

    if (script->functionTemp[0] >= 230) {
        set_background_color_blend(0, 0, 0, 230);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
