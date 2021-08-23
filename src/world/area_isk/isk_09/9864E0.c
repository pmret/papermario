#include "isk_09.h"

static char* N(exit_str_0) = "isk_08";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_isk/isk_09/9864E0", func_80240000_9864E0);
/*
ApiStatus N(func_80240000_9864E0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802406F0_986BD0) == NULL) {
        N(D_802406F0_986BD0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802406F0_986BD0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802406F0_986BD0)[i];
        }
        heap_free(N(D_802406F0_986BD0));
        N(D_802406F0_986BD0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_isk/isk_09/9864E0", func_802402BC_98679C);
