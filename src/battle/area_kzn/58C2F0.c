#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kzn

#include "common/UnkSfxFunc.inc.c"

#include "common/UnkBattleFunc1.inc.c"

ApiStatus func_802181FC_58C4EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Effect6FInstance* effect;
    f32 temp_f20;
    s32 temp_s0_9;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;

    evt_get_variable(script, *args++);
    temp_s6 = evt_get_variable(script, *args++);
    temp_s5 = evt_get_variable(script, *args++);
    temp_s4 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_float_variable(script, *args++);
    temp_s2 = evt_get_variable(script, *args++);
    temp_s3 = evt_get_variable(script, *args++);
    temp_s1 = evt_get_variable(script, *args++);
    temp_s0_9 = evt_get_variable(script, *args++);
    effect = (Effect6FInstance*)playFX_6F(1, temp_s6, temp_s5, temp_s4, temp_f20, temp_s2);
    effect->data->rotation.z = temp_s3;
    effect->data->scale.x = temp_s1;
    effect->data->scale.y = temp_s0_9;
    effect->data->color.x = 255; // red
    effect->data->color.y = 255; // green
    effect->data->color.z = 255; // blue
    return ApiStatus_DONE2;
}
