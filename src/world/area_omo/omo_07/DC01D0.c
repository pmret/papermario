#include "omo_07.h"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DC01D0", func_80242F20_DC01D0);
/*
ApiStatus N(func_80242F20_DC01D0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80245E00_DC30B0) == NULL) {
        N(D_80245E00_DC30B0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80245E00_DC30B0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80245E00_DC30B0)[i];
        }
        heap_free(N(D_80245E00_DC30B0));
        N(D_80245E00_DC30B0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"
