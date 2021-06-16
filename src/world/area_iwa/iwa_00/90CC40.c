#include "iwa_00.h"

INCLUDE_ASM(s32, "world/area_iwa/iwa_00/90CC40", func_80240000_90CC40);
/*
ApiStatus N(func_80240000_90CC40)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240FF8_90DC38) == NULL) {
        N(D_80240FF8_90DC38) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240FF8_90DC38)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240FF8_90DC38)[i];
        }
        heap_free(N(D_80240FF8_90DC38));
        N(D_80240FF8_90DC38) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_00/90CC40", func_80240118_90CD58);
