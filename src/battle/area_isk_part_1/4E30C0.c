#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_1

extern EffectInstance* D_80224D70;
extern EffectInstance* D_80224D74;

ApiStatus func_80218980_4E30C0(Evt* script, s32 isInitialCall) {
    playFX_20(1, -90.0f, 45.0f, -146.0f, 0.25f, &D_80224D70);
    playFX_20(1, 80.0f, 45.0f, -146.0f, 0.25f, &D_80224D74);
    return ApiStatus_DONE2;
}

ApiStatus func_80218A10_4E3150(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224D70);
    remove_effect(D_80224D74);
    return ApiStatus_DONE2;
}
