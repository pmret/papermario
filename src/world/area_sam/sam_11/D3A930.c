#include "sam_11.h"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_80240360_D3A930);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024052C_D3AAFC);

#define NAMESPACE dup_sam_11
ApiStatus N(Set80151310_2)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 2;
    return ApiStatus_DONE2;
}

ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}
#define NAMESPACE sam_11

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024059C_D3AB6C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024072C_D3ACFC);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_80240754_D3AD24);
