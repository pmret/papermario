#include "omo_07.h"

static char* N(exit_str_0) = "omo_06";
static char* N(exit_str_1) = "";

#include "world/common/enemy/ShyGuyAI.inc.c"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_802413FC_DBE6AC);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_8024146C_DBE71C);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_8024153C_DBE7EC);

#define NAMESPACE dup_omo_07
#include "world/common/UnkNpcDurationAnimationFunc.inc.c"
#define NAMESPACE omo_07

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80241634_DBE8E4);

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80242EA8_DC0158);
