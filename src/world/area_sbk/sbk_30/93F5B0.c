#include "sbk_30.h"

static char* N(exit_str_0) = "sbk_99";
static char* N(exit_str_1) = "sbk_31";
static char* N(exit_str_2) = "sbk_20";
static char* N(exit_str_3) = "sbk_40";
static char* N(exit_str_4) = "dro_01";
static char* N(exit_str_5) = "";

s32 N(get_tattle)(void) {
    s32 tattle;
    if (evt_get_variable(NULL, GB_StoryProgress) > STORY_CH2_STAR_SPRIT_DEPARTED) {
        tattle = MSG_MapTattle_sbk_30_after;
    } else {
        tattle = MSG_MapTattle_sbk_30_before;
    }
    return  tattle;
}

#include "world/common/atomic/UnkFunc27.inc.c"

#include "world/common/SpawnSunEffect.inc.c"

#include "world/common/enemy/StationaryAI.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// AwaitLetterChoiceResult
INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241120_9406D0);

// SetLetterChoiceResult
INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241174_940724);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802411AC_94075C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241248_9407F8);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

#include "common/foliage.inc.c"
