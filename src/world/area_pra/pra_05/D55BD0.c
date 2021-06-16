#include "pra_05.h"

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_05/D55BD0", func_80240F20_D56AD0);
/*
ApiStatus N(func_80240F20_D56AD0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241680_D57230) == NULL) {
        N(D_80241680_D57230) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241680_D57230)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241680_D57230)[i];
        }
        heap_free(N(D_80241680_D57230));
        N(D_80241680_D57230) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
