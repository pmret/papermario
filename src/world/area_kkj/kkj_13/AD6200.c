#include "kkj_13.h"
#include "effects.h"

ApiStatus func_80240330_AD6200(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(1);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_23D, 0, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

ApiStatus func_80240390_AD6260(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(1);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_23D, 0, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

ApiStatus func_802403F0_AD62C0(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 64;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_color(0, 160, 160, 160);
    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024046C_AD633C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 64;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(0, 160, 160, 160);
    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_kkj/kkj_13/AD6200", func_802404E0_AD63B0);
