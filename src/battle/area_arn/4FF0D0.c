#include "common.h"

#define NAMESPACE b_area_arn

ApiStatus func_80218680_4FF0D0(Evt* script, s32 isInitialCall) {
    Bytecode *readPos;
    s32 var1;
    s32 var2;
    s32 var3;
    f32 var4;
    Temp8025D160* temp8025D160;

    readPos = script->ptrReadPos;
    temp8025D160 = (Temp8025D160*)evt_get_variable(script, *readPos++);
    var1 = evt_get_variable(script, *readPos++);
    var2 = evt_get_variable(script, *readPos++);
    var3 = evt_get_variable(script, *readPos++);
    var4 = evt_get_float_variable(script, *readPos++);

    temp8025D160->unk_0C->unk_04 = var1;
    temp8025D160->unk_0C->unk_08 = var2;
    temp8025D160->unk_0C->unk_0C = var3;
    temp8025D160->unk_0C->unk_34 = var4;

    return ApiStatus_DONE2;
}
