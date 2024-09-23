#include "mac_01.h"

API_CALLABLE(N(HideRowfBadges_IntroScene)) {
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableA) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableB) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableC) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_IntroWalking) = {
    Call(DisablePlayerInput, TRUE)
    Call(EnableModel, MODEL_ju_1, FALSE)
    Call(N(HideRowfBadges_IntroScene))
    Call(UseSettingsFrom, CAM_DEFAULT, -560, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -560, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcPos, NPC_Luigi, -460, 0, 0)
    Call(SetNpcYaw, NPC_Luigi, 90)
    Thread
        Call(func_802D1270, -100, 0, Float(4.0 / DT))
        Call(func_802D1270, -25, -25, Float(4.0 / DT))
        Call(func_802D1270, 0, -100, Float(4.0 / DT))
        Call(func_802D1270, 0, -400, Float(4.0 / DT))
    EndThread
    Thread
        Call(SetNpcSpeed, NPC_Luigi, Float(4.0 / DT))
        Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Run)
        Call(NpcMoveTo, NPC_Luigi, -100, 0, 0)
        Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_RunBack)
        Call(NpcMoveTo, NPC_Luigi, -25, -25, 0)
        Call(NpcMoveTo, NPC_Luigi, 0, -100, 0)
        Call(NpcMoveTo, NPC_Luigi, 0, -340, 0)
        Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleBack)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(MakeLerp, 300, 400, 100 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamDistance, CAM_DEFAULT, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Wait(75 * DT)
    Call(GotoMap, Ref("osr_00"), osr_00_ENTRY_4)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
