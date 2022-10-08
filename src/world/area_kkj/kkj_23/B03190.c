#include "kkj_23.h"
#include "effects.h"

void peach_force_disguise_action(s32);

ApiStatus func_80240910_B03190(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    effect->data.any[12] = var1;
    effect->data.any[13] = var2;
    effect->data.any[14] = var3;

    return ApiStatus_DONE2;
}

ApiStatus func_802409AC_B0322C(Evt* script, s32 isInitialCall) {
    peach_force_disguise_action(FALSE);
    return ApiStatus_DONE2;
}
