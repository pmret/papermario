#include "common.h"
#include "model.h"
#include "npc.h"

API_CALLABLE(N(FadeBackgroundDarken)) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 20;
    }

    mdl_set_shroud_tint_params(0, 0, 0, ((20 - script->functionTemp[0]) * 10) & 254);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
