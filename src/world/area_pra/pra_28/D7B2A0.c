#include "pra_28.h"

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240000_D7B2A0);

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_28/D7B2A0", func_80240F50_D7C1F0);
/*
ApiStatus N(func_80240F50_D7C1F0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241690_D7C930) == NULL) {
        N(D_80241690_D7C930) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241690_D7C930)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241690_D7C930)[i];
        }
        heap_free(N(D_80241690_D7C930));
        N(D_80241690_D7C930) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
