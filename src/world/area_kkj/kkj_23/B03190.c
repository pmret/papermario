#include "kkj_23.h"
#include "effects.h"

void func_800E63A4(s32);

ApiStatus func_80240910_B03190(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    effect->data.lightning->unk_30 = var1;
    effect->data.lightning->unk_34 = var2;
    effect->data.lightning->unk_38 = var3;

    return ApiStatus_DONE2;
}

ApiStatus func_802409AC_B0322C(Evt* script, s32 isInitialCall) {
    func_800E63A4(0);
    return ApiStatus_DONE2;
}
