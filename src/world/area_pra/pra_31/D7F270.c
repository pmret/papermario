#include "pra_31.h"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240510_D7F270);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240818_D7F578);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240894_D7F5F4);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240A3C_D7F79C);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240BBC_D7F91C);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240C70_D7F9D0);

#include "world/common/todo/UnkFunc12.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240E70_D7FBD0);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240F2C_D7FC8C);

ApiStatus func_80240FD0_D7FD30(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAGS_800000;
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc11.inc.c"
