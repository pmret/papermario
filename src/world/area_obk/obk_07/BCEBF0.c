#include "obk_07.h"

static char* N(exit_str_0) = "obk_01";
static char* N(exit_str_1) = "";

#if 0 // NON_MATCHING
ApiStatus N(func_80240000_BCEBF0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241FB0_BD0BA0) == NULL) {
        N(D_80241FB0_BD0BA0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241FB0_BD0BA0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241FB0_BD0BA0)[i];
        }
        heap_free(N(D_80241FB0_BD0BA0));
        N(D_80241FB0_BD0BA0) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_obk/obk_07/BCEBF0", func_80240000_BCEBF0);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
