#include "flo_10.h"

INCLUDE_ASM(s32, "world/area_flo/flo_10/CB9280", func_80240080_CB9280);
/*
ApiStatus N(func_80240080_CB9280)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241CB0_CBAEB0) == NULL) {
        N(D_80241CB0_CBAEB0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241CB0_CBAEB0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241CB0_CBAEB0)[i];
        }
        heap_free(N(D_80241CB0_CBAEB0));
        N(D_80241CB0_CBAEB0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"
