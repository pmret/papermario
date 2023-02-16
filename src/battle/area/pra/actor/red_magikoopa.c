#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_pra_red_magikoopa

API_CALLABLE(func_80218240_649050) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);

    // function is never called, so the effect type can't be inferred
    ((f32*)effect->data.any)[14] = var1;
    ((f32*)effect->data.any)[15] = var2;
    ((f32*)effect->data.any)[16] = var3;

    return ApiStatus_DONE2;
}

#include "battle/common/actor/red_magikoopa.inc.c"
