#include "common.h"

#define NAMESPACE battle_move_mega_quake

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

ApiStatus func_802A10A4_756824(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s != 0) {
        if (script->functionTemp[0].s != 1) {
            return ApiStatus_BLOCK; // What did they think they were doing here ???
        }
    } else {
        script->functionTemp[1].s = 30;
        script->functionTemp[0].s = 1;
    }

    set_transition_stencil_center(1, 0, 0, 0);
    set_transition_stencil_center(1, 1, 320, 240);
    set_transition_stencil_zoom_1(12, 160.0f);

    if (script->functionTemp[1].s != 0) {
        script->functionTemp[1].s = (script->functionTemp[1].s - 1);
        return ApiStatus_BLOCK;
    } else {
        set_transition_stencil_center(1, 0, 0, 0);
        set_transition_stencil_center(1, 1, 320, 240);
        set_transition_stencil_zoom_1(12, 0.0f);
        return ApiStatus_DONE2;
    }
}
