#include "pra_11.h"

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_11/D61520", func_80240F20_D62420);
/*
ApiStatus N(func_80240F20_D62420)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241610_D62B10) == NULL) {
        N(D_80241610_D62B10) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241610_D62B10)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241610_D62B10)[i];
        }
        heap_free(N(D_80241610_D62B10));
        N(D_80241610_D62B10) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
