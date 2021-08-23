#include "common.h"

#define NAMESPACE b_area_omo3

ApiStatus func_80218000_5573E0(Evt* script, s32 isInitialCall) {
    get_actor(script->owner1.actorID);

    set_screen_overlay_params_back(13, 220.0f);
    set_screen_overlay_alpha(1, 200.0f);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_omo3/5573E0", func_80218038_557418);

INCLUDE_ASM(s32, "battle/area_omo3/5573E0", func_80218070_557450);

INCLUDE_ASM(s32, "battle/area_omo3/5573E0", func_80218490_557870);
