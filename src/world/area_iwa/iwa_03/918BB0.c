#include "iwa_03.h"

static char* N(exit_str_0) = "iwa_01";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_iwa/iwa_03/918BB0", func_80240000_918BB0);
/*
ApiStatus N(func_80240000_918BB0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241530_91A0E0) == NULL) {
        N(D_80241530_91A0E0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241530_91A0E0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241530_91A0E0)[i];
        }
        heap_free(N(D_80241530_91A0E0));
        N(D_80241530_91A0E0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_03/918BB0", func_802402BC_918E6C);
