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

#include "world/common/todo/SpawnSunEffect.inc.c"

#include "world/common/enemy/ai/StationaryAI.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// AwaitLetterChoiceResult
INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241120_9406D0);

// SetLetterChoiceResult
INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241174_940724);

extern s32 sbk_30_D_80244A50[];

ApiStatus func_802411AC_94075C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            sbk_30_D_80244A50[i] = ptr[i];
        }
        sbk_30_D_80244A50[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            sbk_30_D_80244A50[i] = i + 16;
            sbk_30_D_80244A50[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 sbk_30_D_80244C18[];

ApiStatus func_80241248_9407F8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            sbk_30_D_80244C18[i] = ptr[i];
        }
        sbk_30_D_80244C18[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            sbk_30_D_80244C18[i] = i + 128;
            sbk_30_D_80244C18[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

#include "common/foliage.inc.c"
