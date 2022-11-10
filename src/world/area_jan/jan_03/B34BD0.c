#include "jan_03.h"
#include "effects.h"

static char* N(exit_str_0) = "jan_02";
static char* N(exit_str_1) = "jan_05";
static char* N(exit_str_2) = "jan_22";
static char* N(exit_str_3) = "";

#define CHUCK_QUIZMO_NPC_ID 17

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_802405EC_B351BC(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

static char* N(exit_str_4) = "tik_08";

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802419D8_B365A8);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 D_8024FBA0[];

ApiStatus func_80241A64_B36634(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024FBA0[i] = ptr[i];
        }
        D_8024FBA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_8024FBA0[i] = i + 16;
            D_8024FBA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_8024FD68[];

ApiStatus func_80241B00_B366D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024FD68[i] = ptr[i];
        }
        D_8024FD68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_8024FD68[i] = i + 128;
            D_8024FD68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

extern s32 D_8024A5AC_B3F17C[];

ApiStatus func_80242F1C_B37AEC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 outVar = *args++;
    s32 outVal = 0;
    s32* it;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        it = D_8024A5AC_B3F17C;
        while (*it != 0) {
            if (playerData->invItems[i] == *it++) {
                outVal++;
            }
        }
    }
    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}
