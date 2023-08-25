#include "battle/battle.h"
#include "effects.h"

API_CALLABLE(N(UnkEffect6FFunc)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect;
    s32 unusedType = evt_get_variable(script, *args++);
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 r = evt_get_variable(script, *args++);
    s32 g = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);

    effect = fx_cold_breath(1, posX, posY, posZ, scale, duration);
    effect->data.coldBreath->primCol.r = r;
    effect->data.coldBreath->primCol.g = g;
    effect->data.coldBreath->primCol.b = b;
    effect->data.coldBreath->envCol.r = 255;
    effect->data.coldBreath->envCol.g = 255;
    effect->data.coldBreath->envCol.b = 255;

    return ApiStatus_DONE2;
}
