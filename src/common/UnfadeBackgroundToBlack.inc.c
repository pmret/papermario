#include "common.h"
#include "model.h"
#include "map.h"

API_CALLABLE(N(UnfadeBackgroundToBlack)) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 0xFE);
    script->functionTemp[0] -= 1;

    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
