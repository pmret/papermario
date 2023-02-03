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

typedef struct UnkKKJ13 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} UnkKKJ13; // size = 0x4

extern UnkKKJ13 D_80243614_AD94E4[28]; // TODO remove hard-coded size once data is migrated

ApiStatus func_802404E0_AD63B0(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;
    f32 temp_f20;
    f32 temp_f24;
    f32 temp_f26;
    s32 a0;
    f32 a1;
    f32 a2;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80243614_AD94E4); i++) {
        a0 = (i & 1) + 2;
        temp_f20 = D_80243614_AD94E4[i].unk_00;
        temp_f24 = (temp_f20 * cos_deg(D_80243614_AD94E4[i].unk_02)) * 1.3;
        temp_f26 = (temp_f20 * sin_deg(D_80243614_AD94E4[i].unk_02)) * 1.5;
        a1 = temp_f24 + 600.0f;
        a2 = temp_f26 + 100.0f;
        temp_f24 *= 0.1;
        temp_f26 *= 0.1;
        temp_f24 += cos_deg(temp_f20 * 15.0f) * 5.0f;
        effect = fx_ice_shard(a0, a1, a2, -150.0f, ((i & 3) * 0.4) + 1.0, ((i & 3) * 4) + 30);
        effect->data.iceShard->animFrame = 0;
        effect->data.iceShard->animRate = (rand_int(10) * 0.2) + 0.1;
        effect->data.iceShard->rotation = 35 * i;
        effect->data.iceShard->angularVel = rand_int(10) - 5;
        effect->data.iceShard->vel.x = temp_f24;
        effect->data.iceShard->vel.y = temp_f26;
        effect->data.iceShard->vel.z = 2.0f;
        effect->data.iceShard->gravAccel = -0.1f;
    }
    return ApiStatus_DONE2;
}

const char* N(exit_str_0) = "osr_03";
const char* N(exit_str_1) = "hos_10";
