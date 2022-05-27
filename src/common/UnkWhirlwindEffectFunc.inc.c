#include "common.h"
#include "effects.h"

BSS EffectWhirlwindUnk N(effectUnk);
BSS static s32 padding[0x94];

ApiStatus N(UnkWhirlwindEffectFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    N(effectUnk).unk_28 = var1;
    N(effectUnk).unk_2C = var2 - 10.0f;
    N(effectUnk).unk_30 = var3;

    fx_46(6, &N(effectUnk), 1.0f, var4);
    return ApiStatus_DONE2;
}
