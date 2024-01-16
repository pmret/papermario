#include "common.h"
#include "effects.h"

API_CALLABLE(N(CreateWhaleGeyser)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);
    s32 var8 = evt_get_variable(script, *args++);
    EffectInstance* outVal;

    fx_effect_3D(var1, var2, var3, var4, var5, var6, var7, var8, &outVal);
    script->varTablePtr[0] = outVal;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetWhaleGeyserPos)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    effect->data.unk_3D->pos.x = x;
    effect->data.unk_3D->pos.y = y;
    effect->data.unk_3D->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DisposeWhaleGeyser)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_3D->unk_04 = 1;
    return ApiStatus_DONE2;
}
