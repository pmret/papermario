#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_2

extern EffectInstance* D_80220760;
extern EffectInstance* D_80220770;
extern EffectInstance* D_80220780;

ApiStatus func_802189F0_4EFE90(Evt* script, s32 isInitialCall) {
    playFX_20(1, -110.0f, 80.0f, -146.0f, 0.3f, &D_80220760);
    return ApiStatus_DONE2;
}

ApiStatus func_80218A38_4EFED8(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220760);
    return ApiStatus_DONE2;
}

ApiStatus func_80218A60_4EFF00(Evt* script, s32 isInitialCall) {
    playFX_20(1, -110.0f, 80.0f, -146.0f, 0.3f, &D_80220770);
    return ApiStatus_DONE2;
}

ApiStatus func_80218AA8_4EFF48(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220770);
    return ApiStatus_DONE2;
}

ApiStatus func_80218AD0_4EFF70(Evt* script, s32 isInitialCall) {
    playFX_20(1, 110.0f, 80.0f, -146.0f, 0.3f, &D_80220780);
    return ApiStatus_DONE2;
}

ApiStatus func_80218B18_4EFFB8(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220780);
    return ApiStatus_DONE2;
}
