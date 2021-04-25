#include "flo_07.h"

#include "world/common/SomeMatrixOperations.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_07/CAC5D0", func_8024061C_CAC80C);
/*
ApiStatus N(func_8024061C_CAC80C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241BB0_CADDA0) == NULL) {
        N(D_80241BB0_CADDA0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241BB0_CADDA0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241BB0_CADDA0)[i];
        }
        heap_free(N(D_80241BB0_CADDA0));
        N(D_80241BB0_CADDA0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"
