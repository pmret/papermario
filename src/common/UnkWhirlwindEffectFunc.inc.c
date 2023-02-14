#include "common.h"
#include "effects.h"

BSS PlayerStatus N(effectUnk);

API_CALLABLE(N(UnkWhirlwindEffectFunc)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    N(effectUnk).position.x = var1;
    N(effectUnk).position.y = var2 - 10.0f;
    N(effectUnk).position.z = var3;

    fx_46(6, &N(effectUnk), 1.0f, var4);
    return ApiStatus_DONE2;
}
