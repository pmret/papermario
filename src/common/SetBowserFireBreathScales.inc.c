#include "common.h"
#include "effects.h"

API_CALLABLE(N(SetBowserFireBreathScales)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FireBreathFXData* data = effect->data.fireBreath;

    data->scale = 0.04f;
    data->initialScale = 0.04f;
    effect->data.fireBreath->targetScale = 1.875f;
    effect->data.fireBreath->scaleChangeRate = 0.05f;

    return ApiStatus_DONE2;
}
