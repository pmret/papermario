#include "kpa_15.h"

#if 0 // NON_MATCHING
ApiStatus N(func_80240310_A596A0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240AA0_A59E30) == NULL) {
        N(D_80240AA0_A59E30) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240AA0_A59E30)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240AA0_A59E30)[i];
        }
        heap_free(N(D_80240AA0_A59E30));
        N(D_80240AA0_A59E30) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kpa/kpa_15/A596A0", func_80240310_A596A0);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
