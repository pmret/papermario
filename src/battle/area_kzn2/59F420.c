#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_kzn2

INCLUDE_ASM(s32, "battle/area_kzn2/59F420", func_80218D40_59F420);

ApiStatus func_80218D90_59F470(Evt* evt, s32 isInitialCall) {
    Bytecode* args = evt->ptrReadPos;
    EffectInstance* effect = evt_get_variable(evt, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->pos.x = evt_get_variable(evt, *args++);

    return ApiStatus_DONE2;
}
