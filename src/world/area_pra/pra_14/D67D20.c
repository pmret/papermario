#include "pra_14.h"

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_14/D67D20", func_80240F20_D68C20);
/*
ApiStatus N(func_80240F20_D68C20)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241930_D69630) == NULL) {
        N(D_80241930_D69630) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241930_D69630)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241930_D69630)[i];
        }
        heap_free(N(D_80241930_D69630));
        N(D_80241930_D69630) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
