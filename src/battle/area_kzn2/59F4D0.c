#include "common.h"
#include "effects.h"

ApiStatus func_80218DF0_59F4D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    FlameFXData* data = ((EffectInstance*) evt_get_variable(script, *args++))->data.flame;
    f32 temp_f0 = evt_get_float_variable(script, *args++);

    data->unk_2C = temp_f0;
    data->unk_30 = temp_f0;
    return ApiStatus_DONE2;
}
