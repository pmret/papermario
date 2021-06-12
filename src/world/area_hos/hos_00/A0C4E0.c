#include "hos_00.h"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_802407F0_A0C4E0);
/*
ApiStatus N(func_802407F0_A0C4E0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242970_A0E660) == NULL) {
        N(D_80242970_A0E660) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242970_A0E660)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_80242970_A0E660)[i];
        }
        heap_free(N(D_80242970_A0E660));
        N(D_80242970_A0E660) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240908_A0C5F8);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_8024091C_A0C60C);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240994_A0C684);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240A54_A0C744);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240B20_A0C810);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240B3C_A0C82C);
