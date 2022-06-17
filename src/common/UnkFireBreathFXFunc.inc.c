#include "common.h"

ApiStatus N(UnkFireBreathFXFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    FireBreathFXData* data = (FireBreathFXData*)effect->data;

    data->scale = 0.04f;
    data->unk_30 = 0.04f;
    ((FireBreathFXData*)effect->data)->unk_34 = 1.875f;
    ((FireBreathFXData*)effect->data)->scaleChangeFactor = 0.05f;

    return ApiStatus_DONE2;
}
