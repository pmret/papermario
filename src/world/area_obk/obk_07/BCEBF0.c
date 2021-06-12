#include "obk_07.h"

INCLUDE_ASM(s32, "world/area_obk/obk_07/BCEBF0", func_80240000_BCEBF0);
/*
ApiStatus N(func_80240000_BCEBF0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241FB0_BD0BA0) == NULL) {
        N(D_80241FB0_BD0BA0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241FB0_BD0BA0)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241FB0_BD0BA0)[i];
        }
        heap_free(N(D_80241FB0_BD0BA0));
        N(D_80241FB0_BD0BA0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
