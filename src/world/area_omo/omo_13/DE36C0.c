#include "omo_13.h"

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE36C0", func_80241230_DE36C0);
/*
ApiStatus N(func_80241230_DE36C0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242C70_DE5100) == NULL) {
        N(D_80242C70_DE5100) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242C70_DE5100)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242C70_DE5100)[i];
        }
        heap_free(N(D_80242C70_DE5100));
        N(D_80242C70_DE5100) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
