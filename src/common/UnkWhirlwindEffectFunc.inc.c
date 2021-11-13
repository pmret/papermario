#include "common.h"
#include "effects.h"

EffectWhirlwind effectStruct;

ApiStatus N(UnkWhirlwindEffectFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    effectStruct.unk_28 = var1;
    effectStruct.unk_2C = var2 - 10.0f;
    effectStruct.unk_30 = var3;
    
    playFX_46_whirlwind(6, (s32) &effectStruct, 1.0f, var4);
    return ApiStatus_DONE2;
}
