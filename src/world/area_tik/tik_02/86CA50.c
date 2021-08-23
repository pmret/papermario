#include "tik_02.h"

INCLUDE_ASM(s32, "world/area_tik/tik_02/86CA50", func_80240310_86CA50);
/*
ApiStatus N(func_80240310_86CA50)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802410C0_86D800) == NULL) {
        N(D_802410C0_86D800) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802410C0_86D800)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802410C0_86D800)[i];
        }
        heap_free(N(D_802410C0_86D800));
        N(D_802410C0_86D800) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
