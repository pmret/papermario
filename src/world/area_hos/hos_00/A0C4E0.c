#include "hos_00.h"

#if 0 // NON_MATCHING
ApiStatus N(func_802407F0_A0C4E0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242970_A0E660) == NULL) {
        N(D_80242970_A0E660) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242970_A0E660)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242970_A0E660)[i];
        }
        heap_free(N(D_80242970_A0E660));
        N(D_80242970_A0E660) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_802407F0_A0C4E0);
#endif

#include "world/common/GetItemName.inc.c"

ApiStatus N(EnableActionCommands)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->hasActionCommands = TRUE;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_8024091C_A0C60C);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240994_A0C684);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240A54_A0C744);

#include "world/common/SetCamera0Flag1000.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240B3C_A0C82C);
