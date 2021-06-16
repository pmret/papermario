#include "kzn_08.h"

INCLUDE_ASM(s32, "world/area_kzn/kzn_08/C71C10", func_80240790_C71C10);
/*
ApiStatus N(func_80240790_C71C10)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80244BB0_C76030) == NULL) {
        N(D_80244BB0_C76030) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80244BB0_C76030)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80244BB0_C76030)[i];
        }
        heap_free(N(D_80244BB0_C76030));
        N(D_80244BB0_C76030) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
