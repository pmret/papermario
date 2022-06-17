#include "common.h"

ApiStatus N(UnkLightningFXFunc)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)script->varTable[15];

    ((LightningFXData*)effect->data)->unk_30 = 85;
    ((LightningFXData*)effect->data)->unk_34 = 42;
    ((LightningFXData*)effect->data)->unk_38 = 255;
    ((LightningFXData*)effect->data)->unk_40 = 255;
    ((LightningFXData*)effect->data)->unk_44 = 175;
    ((LightningFXData*)effect->data)->unk_48 = 239;
    
    return ApiStatus_DONE2;
}
