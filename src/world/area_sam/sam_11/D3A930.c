#include "sam_11.h"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_80240360_D3A930);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024052C_D3AAFC);

// Almost the same as Set80151310, but we're setting it to 2 in the first func instead of 1
static ApiStatus Set80151310_2(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 2;
    return ApiStatus_DONE2;
}

static ApiStatus Set80151310_0(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 0;
    return ApiStatus_DONE2;
}

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024059C_D3AB6C);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_8024072C_D3ACFC);

INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_80240754_D3AD24);
