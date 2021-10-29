#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_2

extern EffectInstance* D_80220740;
extern EffectInstance* D_80220744;

ApiStatus func_80218850_4EFCF0(Evt* script, s32 isInitialCall) {
    playFX_20(1, -133.0f, 72.0f, -143.0f, 0.3f, &D_80220740);
    playFX_20(1, 129.0f, 72.0f, -143.0f, 0.3f, &D_80220744);
    return ApiStatus_DONE2;
}

ApiStatus func_802188E4_4EFD84(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220740);
    remove_effect(D_80220744);
    return ApiStatus_DONE2;
}
