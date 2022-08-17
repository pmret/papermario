#include "mac_00.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 6

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802418F0_7EC600);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241944_7EC654);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_8024197C_7EC68C);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241A18_7EC728);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241DA0_7ECAB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E04_7ECB14);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E80_7ECB90);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241FF0_7ECD00);

#include "world/common/UnkPositionFunc.inc.c"

ApiStatus N(SetDojoBattle)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = N(dojoBattleIDs)[evt_get_variable(script, EVT_SAVE_VAR(28))];
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802421D0_7ECEE0);

ApiStatus func_80242224_7ECF34(Evt* script, s32 isInitialCall) {
    gPlayerData.curHP = 1;
    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80242250_7ECF60);

ApiStatus func_8024228C_7ECF9C(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
