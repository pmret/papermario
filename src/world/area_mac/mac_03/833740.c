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
    //  f32 angle = clamp_angle(EVT_FIXED_TO_FLOAT(script->varTable[2])); ? TODO
    f32 angle = script->varTable[2] + EVT_FIXED_OFFSET;

    angle = clamp_angle(angle * (1.0f / 1024.0f));
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

    evt_set_variable(script, MapVar(2), (s32) effect);

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

ApiStatus func_802421E8_8339E8(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 type = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    s32 rot = evt_get_variable(script, *args++);

    effect->data.lilOink->type[i] = type;
    effect->data.lilOink->x[i] = x;
    effect->data.lilOink->y[i] = y;
    effect->data.lilOink->z[i] = z;
    effect->data.lilOink->rot[i] = rot;
    effect->data.lilOink->flags[i] |= 1;

    // When the pen is full?
    if (i != MAX_LIL_OINKS - 1) {
        effect->data.lilOink->flags[i] |= 2;
        effect->data.lilOink->unk_EF[i] = 2;
        evt_set_variable(script, i + GB_MAC03_LilOink_00, type);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80242384_833B84(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    s32 rot = evt_get_variable(script, *args++);

    effect->data.lilOink->x[i] = x;
    effect->data.lilOink->y[i] = y;
    effect->data.lilOink->z[i] = z;
    effect->data.lilOink->rot[i] = rot;
    return ApiStatus_DONE2;
}

ApiStatus func_802424A0_833CA0(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 xOut = *args++;
    s32 yOut = *args++;
    s32 zOut = *args++;
    s32 rotOut = *args++;

    evt_set_variable(script, xOut, effect->data.lilOink->x[i]);
    evt_set_variable(script, yOut, effect->data.lilOink->y[i]);
    evt_set_variable(script, zOut, effect->data.lilOink->z[i]);
    evt_set_variable(script, rotOut, effect->data.lilOink->rot[i]);
    return ApiStatus_DONE2;
}

ApiStatus func_802425A8_833DA8(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);

    effect->data.lilOink->flags[i] &= ~1;
    return ApiStatus_DONE2;
}

ApiStatus func_80242608_833E08(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    Bytecode* args = script->ptrReadPos;
    s32 i = evt_get_variable(script, *args++);
    s32 temp = evt_get_variable(script, *args++);

    effect->data.lilOink->flags[i] |= 2;
    effect->data.lilOink->unk_EF[i] = temp;
    return ApiStatus_DONE2;
}

ApiStatus func_80242694_833E94(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MapVar(2));
    s32 i;

    for (i = 1; i < MAX_LIL_OINKS - 1; i++) {
        s32 type = evt_get_variable(script, GB_MAC03_LilOink_00 + i);
        f32 x, y, z, rot;

        evt_set_variable(script, GB_MAC03_LilOinkCount + i, type);

        x = effect->data.lilOink->x[i];
        y = effect->data.lilOink->y[i];
        z = effect->data.lilOink->z[i];
        rot = effect->data.lilOink->rot[i];

        effect->data.lilOink->type[i - 1] = type;
        effect->data.lilOink->x[i - 1] = x;
        effect->data.lilOink->y[i - 1] = y;
        effect->data.lilOink->z[i - 1] = z;
        effect->data.lilOink->rot[i - 1] = rot;
        effect->data.lilOink->flags[i - 1] |= 1;
    }
    effect->data.lilOink->flags[MAX_LIL_OINKS - 2] &= ~1;
    evt_set_variable(script, GB_MAC03_LilOinkCount, 9);
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
