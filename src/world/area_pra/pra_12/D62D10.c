#include "pra_12.h"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240000_D62D10);

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240F50_D63C60);
/*
ApiStatus N(func_80240F50_D63C60)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802416B0_D643C0) == NULL) {
        N(D_802416B0_D643C0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802416B0_D643C0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802416B0_D643C0)[i];
        }
        heap_free(N(D_802416B0_D643C0));
        N(D_802416B0_D643C0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
