#include "mac_03.h"
#include "effects.h"

typedef struct LilOinkReward {
    /* 0x00 */ s32 itemID;
    /* 0x04 */ s32 quantity;
    /* 0x08 */ s32 chance;
} LilOinkReward; // size = 0x0C

extern LilOinkReward D_8024F800_841000[10];

#include "world/common/GetFloorCollider.inc.c"

#include "world/common/GetPlayerCoins.inc.c"

ApiStatus func_80241F80_833780(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

// OINK cod start

ApiStatus func_80241FA0_8337A0(Evt* script, s32 isInitialCall) {
    f32 angle = script->varTable[2] + 230000000;

    angle = clamp_angle(angle * (1.0f / 1024.0f)); // EVT_FIXED_TO_FLOAT ? TODO
    script->varTable[2] = (sin_deg(angle) * 110.0f) + 167.0f;
    script->varTable[3] = 85;
    script->varTable[4] = -343.75f - (cos_deg(angle) * 110.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_8024206C_83386C(Evt* script, s32 isInitialCall) {
    s32 typeBase = GB_MAC03_LilOink_00;
    s32 numPigs = evt_get_variable(NULL, GB_MAC03_LilOinkCount);
    EffectInstance* effect = fx_lil_oink(0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    s32 i;

    evt_set_variable(script, GW(2), (s32) effect);

    for (i = 0; i < numPigs; i++) {
        effect->data.lilOink->type[i] = evt_get_variable(NULL, typeBase + i);
        effect->data.lilOink->x[i] = 300 + (i * 30);
        effect->data.lilOink->y[i] = 20.0f;
        effect->data.lilOink->z[i] = -180.0f;
        effect->data.lilOink->rot[i] = 270.0f;
        effect->data.lilOink->flags[i] |= 1;
        effect->data.lilOink->flags[i] |= 2;
        effect->data.lilOink->unk_EF[i] = 2;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802427D0_833FD0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, GB_MAC03_LilOink_00);
    s32 itemID = *args++;
    s32 quantity = *args++;
    s32 chance = *args++;
    LilOinkReward* reward = &D_8024F800_841000[index];

    evt_set_variable(script, itemID, reward->itemID);
    evt_set_variable(script, quantity, reward->quantity);
    evt_set_variable(script, chance, reward->chance);
    return ApiStatus_DONE2;
}
