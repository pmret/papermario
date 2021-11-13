#include "sam_04.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_8024053C_D13B0C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024387C_D16E4C) = FALSE;
    }

    if (N(D_8024387C_D16E4C)) {
        N(D_8024387C_D16E4C) = FALSE;
        evt_set_variable(script, *args, N(D_80243880_D16E50));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_8024053C_D13B0C);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240590_D13B60)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80243880_D16E50) = evt_get_variable(script, *args);
    N(D_8024387C_D16E4C) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_80240590_D13B60);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802405C8_D13B98)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_802405C8_D13B98);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240664_D13C34)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_80240664_D13C34);
#endif
