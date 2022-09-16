#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kzn2

ApiStatus func_80218D40_59F420(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->unk_2C = evt_get_float_variable(script, *args++);

    return ApiStatus_DONE2;
}


ApiStatus func_80218D90_59F470(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->pos.x = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}
