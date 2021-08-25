#include "dgb_18.h"

// TODO: StashVars.inc.c
ApiStatus N(func_80240FB0_C56EF0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802436E0_C59620) == NULL) {
        N(D_802436E0_C59620) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802436E0_C59620)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802436E0_C59620)[i];
        }
        heap_free(N(D_802436E0_C59620));
        N(D_802436E0_C59620) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
