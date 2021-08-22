#include "kmr_20.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED440", func_80241620_8ED440);
/*
ApiStatus N(func_80241620_8ED440)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_8024A908_8F6728) == NULL) {
        N(D_8024A908_8F6728) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_8024A908_8F6728)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_8024A908_8F6728)[i];
        }
        heap_free(N(D_8024A908_8F6728));
        N(D_8024A908_8F6728) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED440", func_80241738_8ED558);
