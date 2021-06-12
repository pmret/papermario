#include "sam_10.h"

INCLUDE_ASM(s32, "world/area_sam/sam_10/D37800", func_80240000_D37800);
/*
ApiStatus N(func_80240000_D37800)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241040_D38840) == NULL) {
        N(D_80241040_D38840) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241040_D38840)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80241040_D38840)[i];
        }
        heap_free(N(D_80241040_D38840));
        N(D_80241040_D38840) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_10/D37800", func_802402BC_D37ABC);

INCLUDE_ASM(s32, "world/area_sam/sam_10/D37800", func_802402F0_D37AF0);
