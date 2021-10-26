#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_2

extern EffectInstance* D_80220750;
extern EffectInstance* D_80220754;

ApiStatus func_80218920_4EFDC0(Evt* script, s32 isInitialCall) {
    playFX_20(1, -90.0f, 45.0f, -146.0f, 0.25f, &D_80220750);
    playFX_20(1, 80.0f, 45.0f, -146.0f, 0.25f, &D_80220754);
    return ApiStatus_DONE2;
}

ApiStatus func_802189B0_4EFE50(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220750);
    remove_effect(D_80220754);
    return ApiStatus_DONE2;
}
