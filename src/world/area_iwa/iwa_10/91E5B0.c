#include "iwa_10.h"

#if 0 // NON_MATCHING
ApiStatus N(func_80240040_91E5B0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241DD0_920340) == NULL) {
        N(D_80241DD0_920340) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241DD0_920340)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241DD0_920340)[i];
        }
        heap_free(N(D_80241DD0_920340));
        N(D_80241DD0_920340) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91E5B0", func_80240040_91E5B0);
#endif

#include "world/common/GetItemName.inc.c"
