#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_1

extern EffectInstance* D_80224D80;
extern EffectInstance* D_80224D90;
extern EffectInstance* D_80224DA0;
extern EffectInstance* D_80224DB0;

ApiStatus func_80218A50_4E3190(Evt* script, s32 isInitialCall) {
    playFX_20(1, -110.0f, 80.0f, -146.0f, 0.3f, &D_80224D80);
    return ApiStatus_DONE2;
}

ApiStatus func_80218A98_4E31D8(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224D80);
    return ApiStatus_DONE2;
}

ApiStatus func_80218AC0_4E3200(Evt* script, s32 isInitialCall) {
    playFX_20(1, 110.0f, 80.0f, -146.0f, 0.3f, &D_80224D90);
    return ApiStatus_DONE2;
}

ApiStatus func_80218B08_4E3248(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224D90);
    return ApiStatus_DONE2;
}

ApiStatus func_80218B30_4E3270(Evt* script, s32 isInitialCall) {
    playFX_20(1, -110.0f, 80.0f, -146.0, 0.3f, &D_80224DA0);
    return ApiStatus_DONE2;
}

ApiStatus func_80218B78_4E32B8(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224DA0);
    return ApiStatus_DONE2;
}

ApiStatus func_80218BA0_4E32E0(Evt* script, s32 isInitialCall) {
    playFX_20(1, 0, 72.0f, -146.0, 0.3f, &D_80224DB0);
    return ApiStatus_DONE2;
}

ApiStatus func_80218BE8_4E3328(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224DB0);
    return ApiStatus_DONE2;
}
