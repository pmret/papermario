#include "tik_15.h"

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_802405F0_890190);

#if 0 // NON_MATCHING
ApiStatus N(func_80240960_890500)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242758_8922F8) == NULL) {
        N(D_80242758_8922F8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242758_8922F8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242758_8922F8)[i];
        }
        heap_free(N(D_80242758_8922F8));
        N(D_80242758_8922F8) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240960_890500);
#endif

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240A78_890618);

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240AA4_890644);

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240AD0_890670);
