#include "common.h"
#include "effects.h"

ApiStatus N(ShrinkActor)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var1 = evt_get_float_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    s32 var7 = evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);
    EffectInstance* effect = playFX_12(0, var1, (f32) var2 + 5.0, var3, var4, var5, var6, var7);

    if (actor->debuff == STATUS_SHRINK) {
        effect->data->unk_28 = 0.4f;
    }

    return ApiStatus_DONE2;
}
