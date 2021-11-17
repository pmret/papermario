#include "hos_00.h"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_802407F0_A0C4E0);

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
