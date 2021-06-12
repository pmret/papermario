#include "trd_00.h"

INCLUDE_ASM(s32, "world/area_trd/trd_00/999F80", func_80240310_999F80);
/*
ApiStatus N(func_80240310_999F80)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241340_99AFB0) == NULL) {
        N(D_80241340_99AFB0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241340_99AFB0)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241340_99AFB0)[i];
        }
        heap_free(N(D_80241340_99AFB0));
        N(D_80241340_99AFB0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
