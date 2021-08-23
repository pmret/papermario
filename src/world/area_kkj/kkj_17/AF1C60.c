#include "kkj_17.h"

static char* N(exit_str_0) = "kkj_11";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_kkj/kkj_17/AF1C60", func_80240000_AF1C60);
/*
ApiStatus N(func_80240000_AF1C60)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802408C0_AF2520) == NULL) {
        N(D_802408C0_AF2520) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802408C0_AF2520)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802408C0_AF2520)[i];
        }
        heap_free(N(D_802408C0_AF2520));
        N(D_802408C0_AF2520) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_17/AF1C60", func_802402BC_AF1F1C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_17/AF1C60", func_80240500_AF2160);

INCLUDE_ASM(s32, "world/area_kkj/kkj_17/AF1C60", func_80240568_AF21C8);
