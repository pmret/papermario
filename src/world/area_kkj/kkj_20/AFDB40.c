#include "kkj_20.h"

INCLUDE_ASM(s32, "world/area_kkj/kkj_20/AFDB40", func_80240000_AFDB40);
/*
ApiStatus N(func_80240000_AFDB40)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240880_AFE3C0) == NULL) {
        N(D_80240880_AFE3C0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240880_AFE3C0)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80240880_AFE3C0)[i];
        }
        heap_free(N(D_80240880_AFE3C0));
        N(D_80240880_AFE3C0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
