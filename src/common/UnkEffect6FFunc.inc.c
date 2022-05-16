#include "battle/battle.h"
#include "effects.h"

ApiStatus N(UnkEffect6FFunc)(Evt* script, s32 isInitialCall) {
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
    ((Effect6FFXData*)effect->data)->rotation.z = temp_s3;
    ((Effect6FFXData*)effect->data)->scale.x = temp_s1;
    ((Effect6FFXData*)effect->data)->scale.y = temp_s0_9;
    ((Effect6FFXData*)effect->data)->color.x = 255;
    ((Effect6FFXData*)effect->data)->color.y = 255;
    ((Effect6FFXData*)effect->data)->color.z = 255;

    return ApiStatus_DONE2;
}
