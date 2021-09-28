#include "common.h"

#define NAMESPACE b_area_arn

ApiStatus func_80218680_4FF0D0(Evt* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Temp8025D160* temp8025D160 = (Temp8025D160*)evt_get_variable(script, *args++);

    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    temp8025D160->unk_0C->unk_04 = var1;
    temp8025D160->unk_0C->unk_08 = var2;
    temp8025D160->unk_0C->unk_0C = var3;
    temp8025D160->unk_0C->unk_34 = var4;

    return ApiStatus_DONE2;
}
