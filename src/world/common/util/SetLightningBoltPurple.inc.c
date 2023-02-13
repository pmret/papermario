#include "common.h"
#include "effects.h"

ApiStatus N(SetLightningBoltPurple)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)script->varTable[15];

    effect->data.lightningBolt->outerColor.r = 85;
    effect->data.lightningBolt->outerColor.g = 42;
    effect->data.lightningBolt->outerColor.b = 255;
    effect->data.lightningBolt->innerColor.r = 255;
    effect->data.lightningBolt->innerColor.g = 175;
    effect->data.lightningBolt->innerColor.b = 239;
    
    return ApiStatus_DONE2;
}
