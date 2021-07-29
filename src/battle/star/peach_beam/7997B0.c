#include "common.h"

#define NAMESPACE battle_star_peach_beam

#include "common/StarPower.inc.c"

INCLUDE_ASM(s32, "battle/star/peach_beam/7997B0", func_802A1518_799CC8);

ApiStatus func_802A2468_79AC18(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = D_802A3838;
    return ApiStatus_DONE2;
}

ApiStatus func_802A247C_79AC2C(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 230;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] <= 200) {
        set_background_color_blend(0, 0, 0, 200);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

// this file is identical in c code to star beam
