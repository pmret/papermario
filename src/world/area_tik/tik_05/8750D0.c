#include "tik_05.h"

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_80240310_8750D0);

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_80240680_875440);
/*
ApiStatus N(func_80240680_875440)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241800_8765C0) == NULL) {
        N(D_80241800_8765C0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241800_8765C0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241800_8765C0)[i];
        }
        heap_free(N(D_80241800_8765C0));
        N(D_80241800_8765C0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_8024093C_8756FC);

#include "world/common/SetEntityPosition.inc.c"
