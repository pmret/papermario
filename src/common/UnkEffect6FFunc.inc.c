#include "battle/battle.h"
#include "effects.h"

API_CALLABLE(N(UnkEffect6FFunc)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect;
    s32 unused_var = evt_get_variable(script, *args++);
    s32 temp_s6 = evt_get_variable(script, *args++);
    s32 temp_s5 = evt_get_variable(script, *args++);
    s32 temp_s4 = evt_get_variable(script, *args++);
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s3 = evt_get_variable(script, *args++);
    s32 temp_s1 = evt_get_variable(script, *args++);
    s32 temp_s0_9 = evt_get_variable(script, *args++);

    effect = fx_cold_breath(1, temp_s6, temp_s5, temp_s4, temp_f20, temp_s2);
    effect->data.coldBreath->unk_18 = temp_s3;
    effect->data.coldBreath->unk_1C = temp_s1;
    effect->data.coldBreath->unk_20 = temp_s0_9;
    effect->data.coldBreath->unk_28 = 255;
    effect->data.coldBreath->unk_2C = 255;
    effect->data.coldBreath->unk_30 = 255;

    return ApiStatus_DONE2;
}
