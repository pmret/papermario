#include "common.h"
#include "effects.h"

ApiStatus N(UnkLightningFXFunc)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)script->varTable[15];

    effect->data.any[12] = 85;
    effect->data.any[13] = 42;
    effect->data.any[14] = 255;
    effect->data.any[16] = 255;
    effect->data.any[17] = 175;
    effect->data.any[18] = 239;
    
    return ApiStatus_DONE2;
}
