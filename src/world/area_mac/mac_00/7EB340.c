#include "mac_00.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 6

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_802418F0_7EC600);

 INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241944_7EC654);

extern s32 mac_00_D_80255BA0[];

ApiStatus func_8024197C_7EC68C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_00_D_80255BA0[i] = ptr[i];
        }
        mac_00_D_80255BA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_00_D_80255BA0[i] = i + 16;
            mac_00_D_80255BA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 mac_00_D_80255D68[];

ApiStatus func_80241A18_7EC728(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_00_D_80255D68[i] = ptr[i];
        }
        mac_00_D_80255D68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            mac_00_D_80255D68[i] = i + 128;
            mac_00_D_80255D68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241DA0_7ECAB0);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E04_7ECB14);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241E80_7ECB90);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7EB340", func_80241FF0_7ECD00);

#include "world/common/todo/UnkPositionFunc.inc.c"

ApiStatus N(SetDojoBattle)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = N(dojoBattleIDs)[evt_get_variable(script, GB_MAC00_DojoRank)];
    return ApiStatus_DONE2;
}

ApiStatus func_802421D0_7ECEE0(Evt* script, s32 isInitialCall) {
    func_8011B950(0x8A, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80242224_7ECF34(Evt* script, s32 isInitialCall) {
    gPlayerData.curHP = 1;
    sync_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus func_80242250_7ECF60(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s32) ((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

ApiStatus func_8024228C_7ECF9C(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
