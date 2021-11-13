#include "omo_09.h"

#if 0 // NON_MATCHING
ApiStatus N(func_80240720_DCD3F0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80247010_DD3CE0) == NULL) {
        N(D_80247010_DD3CE0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80247010_DD3CE0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80247010_DD3CE0)[i];
        }
        heap_free(N(D_80247010_DD3CE0));
        N(D_80247010_DD3CE0) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD3F0", func_80240720_DCD3F0);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
