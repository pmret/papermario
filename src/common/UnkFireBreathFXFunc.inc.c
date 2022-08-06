#include "common.h"
#include "effects.h"

ApiStatus N(UnkFireBreathFXFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FireBreathFXData* data = effect->data.fireBreath;

    data->scale = 0.04f;
    data->unk_30 = 0.04f;
    effect->data.fireBreath->unk_34 = 1.875f;
    effect->data.fireBreath->scaleChangeFactor = 0.05f;

    return ApiStatus_DONE2;
}
