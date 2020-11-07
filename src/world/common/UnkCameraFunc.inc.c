#include "common.h"

static ApiStatus UnkCameraFunc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;
    s32 cameraYaw = CURRENT_CAM->currentYaw;
    s32 outVal1 = get_variable(script, SI_ARRAY(1)) - (var2 * cos_deg(cameraYaw));
    s32 outVal2 = get_variable(script, SI_ARRAY(3)) - (var2 * sin_deg(cameraYaw));

    outVal1 -= var0;
    outVal2 -= var1;

    set_variable(script, out1, outVal1);
    set_variable(script, out2, outVal2);

    return ApiStatus_DONE2;
}
