#include "common.h"
#include "effects.h"

ApiStatus N(UnkLightningFXFunc)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)script->varTable[15];

    effect->data.lightning->unk_30 = 85;
    effect->data.lightning->unk_34 = 42;
    effect->data.lightning->unk_38 = 255;
    effect->data.lightning->unk_40 = 255;
    effect->data.lightning->unk_44 = 175;
    effect->data.lightning->unk_48 = 239;
    
    return ApiStatus_DONE2;
}
