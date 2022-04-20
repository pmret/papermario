#include "sam_07.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_08";

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240000_D2BD30);

#include "world/common/SetEntityPositionF.inc.c"

#include "world/common/GetEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_802405B0_D2C2E0);

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/enemy/PiranhaPlantAI.inc.c"
