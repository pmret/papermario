#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kzn2_petit_piranha

ApiStatus N(SetFlameUnk2C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->unk_2C = evt_get_float_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus N(SetFlameX)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->pos.x = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}
