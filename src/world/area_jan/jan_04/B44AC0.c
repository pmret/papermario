#include "jan_04.h"

INCLUDE_ASM(s32, "world/area_jan/jan_04/B44AC0", func_80240350_B44AC0);
/*
ApiStatus N(func_80240350_B44AC0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241800_B45F70) == NULL) {
        N(D_80241800_B45F70) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241800_B45F70)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241800_B45F70)[i];
        }
        heap_free(N(D_80241800_B45F70));
        N(D_80241800_B45F70) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
