#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_1

extern EffectInstance* D_80224D60;
extern EffectInstance* D_80224D64;
extern s32 D_80224920_4EF060;

#include "common/ChainChompChainInit.inc.c"

#include "common/ChainChompChainUpdateHelperFunc.inc.c"

#include "common/ChainChompChainUpdateHelperFunc2.inc.c"

INCLUDE_ASM(s32, "battle/area_isk_part_1/4E29B0", b_area_isk_part_1_ChainChompChainUpdate);

// Clover's suggestion: isk_bt04_CreateTorchFX
// Reason: this sort of additional namespacing is required because the isk battle source includes the data for each of the stages
//   if these were regular maps, theyd have their own source files
ApiStatus func_802188B0_4E2FF0(Evt* script, s32 isInitialCall) {
    playFX_20(1, -133.0f, 72.0f, -143.0f, 0.3f, &D_80224D60);
    playFX_20(1, 129.0f, 72.0f, -143.0f, 0.3f, &D_80224D64);
    return ApiStatus_DONE2;
}

// Clover's suggestion: isk_bt04_DeleteTorchFX
// Reason: this sort of additional namespacing is required because the isk battle source includes the data for each of the stages
//   if these were regular maps, theyd have their own source files
ApiStatus func_80218944_4E3084(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224D60);
    remove_effect(D_80224D64);
    return ApiStatus_DONE2;
}
