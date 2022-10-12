#include "kkj_00.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

static char* N(exit_str) = "end_00";

ApiStatus func_80240F40_ABC1D0(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(0, 208, 208, 208);
    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 7;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}
