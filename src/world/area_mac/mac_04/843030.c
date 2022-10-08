#include "mac_04.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 20

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774_844344);

extern s32 mac_04_D_8024F5D0[];

ApiStatus func_802417AC_84437C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            mac_04_D_8024F5D0[i] = ptr[i];
        }
        mac_04_D_8024F5D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            mac_04_D_8024F5D0[i] = i + 16;
            mac_04_D_8024F5D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241848_844418);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802418AC_84447C);

ApiStatus PostChapter4StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

ApiStatus N(IsPartnerBow)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetPlayerCoins.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419E4_8445B4);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241A64_844634);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241B90_844760);

ApiStatus N(SetNpcShadowScale)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

ApiStatus N(80241C20_8447F0)(Evt* script, s32 isInitialCall) {
    func_800E9894();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C40_844810);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241C60_844830);
