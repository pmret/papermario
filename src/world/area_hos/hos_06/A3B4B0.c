#include "hos_06.h"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_80241FD0_A3B4B0);
/*
ApiStatus N(func_80241FD0_A3B4B0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80245E80_A3F360) == NULL) {
        N(D_80245E80_A3F360) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80245E80_A3F360)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80245E80_A3F360)[i];
        }
        heap_free(N(D_80245E80_A3F360));
        N(D_80245E80_A3F360) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#define NAMESPACE dup_hos_06
#include "world/common/GetItemName.inc.c"
#define NAMESPACE hos_06

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_8024228C_A3B76C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_802424CC_A3B9AC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_80242534_A3BA14);
