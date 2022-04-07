#include "common.h"
#include "npc.h"

ApiStatus N(SuperBlock_EndGlowEffect)(Evt* script, s32 isInitialCall) {
    EffectGraphics* effect = (EffectGraphics*)evt_get_variable(script, *script->ptrReadPos);

    effect->flags |= 0x10;

    return ApiStatus_DONE2;
}
