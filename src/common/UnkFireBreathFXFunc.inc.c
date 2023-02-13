#include "common.h"
#include "effects.h"

API_CALLABLE(N(UnkFireBreathFXFunc)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FireBreathFXData* data = effect->data.fireBreath;

    data->scale = 0.04f;
    data->unk_30 = 0.04f;
    effect->data.fireBreath->unk_34 = 1.875f;
    effect->data.fireBreath->scaleChangeFactor = 0.05f;

    return ApiStatus_DONE2;
}
