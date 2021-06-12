#include "pra_27.h"

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240000_D799F0);

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_27/D799F0", func_80240F50_D7A940);
/*
ApiStatus N(func_80240F50_D7A940)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241690_D7B080) == NULL) {
        N(D_80241690_D7B080) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241690_D7B080)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241690_D7B080)[i];
        }
        heap_free(N(D_80241690_D7B080));
        N(D_80241690_D7B080) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
