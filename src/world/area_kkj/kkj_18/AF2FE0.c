#include "kkj_18.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_8024056C_AF320C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241F10_AF4BB0) = FALSE;
    }

    if (N(D_80241F10_AF4BB0)) {
        N(D_80241F10_AF4BB0) = FALSE;
        evt_set_variable(script, *args, N(D_80241F14_AF4BB4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_8024056C_AF320C);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802405C0_AF3260)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241F14_AF4BB4) = evt_get_variable(script, *args);
    N(D_80241F10_AF4BB0) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405C0_AF3260);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802405F8_AF3298)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405F8_AF3298);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240694_AF3334)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240694_AF3334);
#endif

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240730_AF33D0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240774_AF3414);
