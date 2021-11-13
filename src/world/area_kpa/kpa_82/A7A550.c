#include "kpa_82.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_8024027C_A7A77C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80240C20_A7B120) = FALSE;
    }

    if (N(D_80240C20_A7B120)) {
        N(D_80240C20_A7B120) = FALSE;
        evt_set_variable(script, *args, N(D_80240C24_A7B124));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_8024027C_A7A77C);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802402D0_A7A7D0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80240C24_A7B124) = evt_get_variable(script, *args);
    N(D_80240C20_A7B120) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_802402D0_A7A7D0);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240308_A7A808)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_80240308_A7A808);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802403A4_A7A8A4)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_802403A4_A7A8A4);
#endif
