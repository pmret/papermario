#include "omo_06.h"

#if 0 // NON_MATCHING
ApiStatus N(func_80240870_DB8180)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802456C0_DBCFD0) == NULL) {
        N(D_802456C0_DBCFD0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802456C0_DBCFD0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802456C0_DBCFD0)[i];
        }
        heap_free(N(D_802456C0_DBCFD0));
        N(D_802456C0_DBCFD0) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_06/DB8180", func_80240870_DB8180);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
