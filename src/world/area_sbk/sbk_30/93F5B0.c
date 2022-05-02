#include "sbk_30.h"

static char* N(exit_str_0) = "sbk_99";
static char* N(exit_str_1) = "sbk_31";
static char* N(exit_str_2) = "sbk_20";
static char* N(exit_str_3) = "sbk_40";
static char* N(exit_str_4) = "dro_01";
static char* N(exit_str_5) = "";

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240000_93F5B0);

#include "world/common/atomic/UnkFunc27.inc.c"

#include "world/common/SpawnSunEffect.inc.c"

#include "world/common/enemy/StationaryAI.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241120_9406D0);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241174_940724);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802411AC_94075C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241248_9407F8);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

#include "common/foliage.inc.c"
