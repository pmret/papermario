#include "flo_03.h"

INCLUDE_ASM(s32, "world/area_flo/flo_03/CA72E0", func_80240040_CA72E0);
/*
ApiStatus N(func_80240040_CA72E0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240F08_CA81A8) == NULL) {
        N(D_80240F08_CA81A8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240F08_CA81A8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240F08_CA81A8)[i];
        }
        heap_free(N(D_80240F08_CA81A8));
        N(D_80240F08_CA81A8) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_03/CA72E0", func_80240158_CA73F8);

#include "world/common/SomeMatrixOperations.inc.c"
