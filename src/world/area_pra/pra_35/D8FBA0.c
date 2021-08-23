#include "pra_35.h"

INCLUDE_ASM(s32, "world/area_pra/pra_35/D8FBA0", func_80242950_D8FBA0);
/*
ApiStatus N(func_80242950_D8FBA0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80243DE0_D91030) == NULL) {
        N(D_80243DE0_D91030) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80243DE0_D91030)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80243DE0_D91030)[i];
        }
        heap_free(N(D_80243DE0_D91030));
        N(D_80243DE0_D91030) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
