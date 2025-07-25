#include "dro_01.h"

API_CALLABLE(N(AwaitPlayerApproachShop)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_variable(script, *args++);
    f32 temp_f0 = (var4 - var2) / (var3 - var1);

    if (playerStatus->pos.z < ((temp_f0 * playerStatus->pos.x) + (var2 - (temp_f0 * var1)))) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcIdle_ShopOwner) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
            Call(N(AwaitPlayerApproachShop), 16, 190, -134, -131)
            Call(DisablePlayerInput, true)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
            Call(SetNpcPos, NPC_SELF, 0, 0, -180)
            ExecWait(N(EVS_OpenShopDoor))
            Wait(10 * DT)
            Call(GetPlayerPos, LVarA, LVarB, LVarC)
            Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            Call(SetPanTarget, CAM_DEFAULT, 32, 0, -67)
            Call(SetCamDistance, CAM_DEFAULT, -210)
            Call(SetCamPitch, CAM_DEFAULT, 20, -12)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Wait(20 * DT)
            Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            Call(SetCamDistance, CAM_DEFAULT, -350)
#if VERSION_PAL
            Call(SetCamSpeed, 0, Float(0.961))
#else
            Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
#endif
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            Call(NpcMoveTo, NPC_SELF, -23, -105, 20)
            Wait(10 * DT)
            Call(InterpNpcYaw, NPC_SELF, 65, 0)
            Wait(10 * DT)
            ExecWait(N(EVS_CloseShopDoor))
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            Call(NpcMoveTo, NPC_SELF, 37, -27, 20 * DT)
            Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
            Call(SetPanTarget, CAM_DEFAULT, 142, 0, -67)
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(NpcMoveTo, NPC_SELF, 62, -6, 20 * DT)
            Call(NpcMoveTo, NPC_SELF, 103, 11, 20 * DT)
            Call(NpcMoveTo, NPC_SELF, 150, 18, 20 * DT)
            Call(EnableNpcBlur, NPC_SELF, true)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
            Call(NpcMoveTo, NPC_SELF, 554, -12, 20 * DT)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Wait(30 * DT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PanToTarget, CAM_DEFAULT, 0, false)
            Call(DisablePlayerInput, false)
            Set(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_LEFT_SHOP)
        CaseLt(STORY_CH2_SPOKE_WITH_SHEEK)
        CaseLt(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            Call(EnableNpcBlur, NPC_SELF, true)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
            Call(SetNpcPos, NPC_SELF, 470, 0, 18)
            Call(NpcMoveTo, NPC_SELF, 287, 9, 20 * DT)
            Call(NpcMoveTo, NPC_SELF, 102, -14, 20 * DT)
            Call(NpcMoveTo, NPC_SELF, -32, -96, 20 * DT)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            ExecWait(N(EVS_OpenShopDoor))
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            Call(NpcMoveTo, NPC_SELF, 20, -375, 30 * DT)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            ExecWait(N(EVS_CloseShopDoor))
            Call(EnableNpcBlur, NPC_SELF, false)
            Set(GB_StoryProgress, STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
        CaseDefault
            Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            Call(SetNpcPos, NPC_SELF, 20, 0, -375)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShopOwner) = {
    IfEq(AB_DRO_SHOP_PREV1, 4)
        IfEq(AB_DRO_SHOP_PREV2, 1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
            ExecWait(N(EVS_LetterPrompt_ShopOwner))
            IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
                Return
            EndIf
            Return
        EndIf
    EndIf
    ExecWait(EVS_ShopOwnerDialog)
    ExecWait(N(EVS_LetterPrompt_ShopOwner))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_ShopOwner) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShopOwner)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShopOwner)))
    Return
    End
};
