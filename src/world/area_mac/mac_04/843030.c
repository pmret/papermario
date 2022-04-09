#include "mac_04.h"
#include "effects.h"

#define UNK_ALPHA_FUNC_NPC 20

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_WasCorrect);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"
#include "world/common/atomic/Quizmo_UnkA.inc.c"
#include "world/common/atomic/Quizmo_UnkB.inc.c"
#include "world/common/atomic/Quizmo_UnkC.inc.c"
#include "world/common/atomic/Quizmo_UnkD.inc.c"
#include "world/common/atomic/Quizmo_UnkE.inc.c"
#include "world/common/atomic/Quizmo_UnkF.inc.c"
#include "world/common/atomic/Quizmo_UnkG.inc.c"
#include "world/common/atomic/Quizmo_UnkH.inc.c"
#include "world/common/GetGameStatus75.inc.c"
#include "world/common/SetCamVfov.inc.c"
#include "world/common/GetCamVfov.inc.c"
#include "world/common/UnkCameraFunc.inc.c"
#include "world/common/UnkRotatePlayer.inc.c"
#include "world/common/UnkPartnerFuncs.inc.c"
#include "world/common/atomic/Quizmo_UnkI.inc.c"
#include "world/common/atomic/Quizmo_UnkJ.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241720_8442F0);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_80241774_844344);

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802417AC_84437C);

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

INCLUDE_ASM(s32, "world/area_mac/mac_04/843030", func_802419AC_84457C);

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
