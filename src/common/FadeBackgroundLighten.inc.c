#include "common.h"
#include "model.h"
#include "map.h"

API_CALLABLE(N(FadeBackgroundLighten)) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    mdl_set_shroud_tint_params(0, 0, 0, (script->functionTemp[0] * 10) & 254);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
