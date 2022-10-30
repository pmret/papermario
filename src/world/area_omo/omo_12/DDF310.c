#include "omo_12.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/atomic/CreateDarkness.inc.c"

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

ApiStatus func_80240314_DDF624(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 temp_s0_5 = evt_get_variable(script, *args++);

    set_screen_overlay_center_worldpos(1, 1, x, y, z);
    set_screen_overlay_alpha(1, temp_s0_5);
    set_screen_overlay_params_back(0xB, 255.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802403D8_DDF6E8(Evt* script, s32 isInitialCall) {
    set_screen_overlay_alpha(1, 0.0f);
    set_screen_overlay_params_back(0xB, 0.0f);
    return ApiStatus_DONE2;
}
