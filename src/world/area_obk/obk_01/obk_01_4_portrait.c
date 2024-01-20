#include "obk_01.h"
#include "sprite.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPortraitItemAlpha)) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    item->alpha = 255;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateSpeakingPortrait) = {
    // hide empty frames
    Call(EnableModel, MODEL_n1, FALSE)
    Call(EnableModel, MODEL_n2, FALSE)
    Loop(0)
        // toggle different frames of the speaking 'animation'
        Call(EnableModel, MODEL_u1, TRUE)
        Call(EnableModel, MODEL_u2, TRUE)
        Call(EnableModel, MODEL_si1, FALSE)
        Call(EnableModel, MODEL_si2, FALSE)
        Wait(5)
        Call(EnableModel, MODEL_u1, FALSE)
        Call(EnableModel, MODEL_u2, FALSE)
        Call(EnableModel, MODEL_si1, TRUE)
        Call(EnableModel, MODEL_si2, TRUE)
        Wait(5)
        Sub(LVar0, 1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Interact_LowerPortrait) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_GOT_BOO_PORTRAIT)
            IfEq(GF_OBK01_Met_Portrait, FALSE)
                Call(ShowMessageAtScreenPos, MSG_CH3_002B, 160, 40)
                Set(GF_OBK01_Met_Portrait, TRUE)
            Else
                Call(ShowMessageAtScreenPos, MSG_CH3_002C, 160, 40)
            EndIf
        CaseEq(STORY_CH3_GOT_BOO_PORTRAIT)
            Call(ShowKeyChoicePopup)
            Call(CloseChoicePopup)
            Switch(LVar0)
                CaseGe(1)
                    Call(RemoveKeyItemAt, LVar1)
                    Wait(10 * DT)
                    Call(SetPlayerAnimation, ANIM_MarioW1_Lift)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Add(LVar1, 40)
                    Call(MakeItemEntity, ITEM_BOO_PORTRAIT, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
                    Call(N(SetPortraitItemAlpha))
                    Set(LVarA, LVar0)
                    Wait(30 * DT)
                    Call(GetPlayerPos, LVar3, LVar4, LVar5)
                    Set(LVar6, 40)
                    Add(LVar6, LVar4)
                    Set(LVar7, 70)
                    Add(LVar7, LVar4)
                    Call(MakeLerp, LVar6, LVar7, 20 * DT, EASING_LINEAR)
                    Loop(0)
                        Call(UpdateLerp)
                        Call(SetItemPos, LVarA, LVar3, LVar0, LVar5)
                        Wait(1)
                        IfEq(LVar1, 0)
                            BreakLoop
                        EndIf
                    EndLoop
                    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                    Call(MakeLerp, 255, 0, 30 * DT, EASING_LINEAR)
                    Loop(0)
                        Call(UpdateLerp)
                        Call(SetItemAlpha, LVarA, LVar0)
                        Wait(1)
                        IfEq(LVar1, 0)
                            BreakLoop
                        EndIf
                    EndLoop
                    Wait(30 * DT)
                    Call(RemoveItemEntity, LVarA)
                    IfEq(GF_OBK01_Met_Portrait, TRUE)
                        Set(LVar0, 25)
                        Exec(N(EVS_AnimateSpeakingPortrait))
                        Call(ShowMessageAtScreenPos, MSG_CH3_002D, 160, 40)
                    Else
                        Set(LVar0, 35)
                        Exec(N(EVS_AnimateSpeakingPortrait))
                        Call(ShowMessageAtScreenPos, MSG_CH3_002E, 160, 40)
                    EndIf
                    Set(GB_StoryProgress, STORY_CH3_RESTORED_BOO_PORTRAIT)
            EndSwitch
        CaseDefault
            Call(DisablePlayerPhysics, TRUE)
            Call(DisablePartnerAI, 0)
            Call(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_BeforeJump)
            Wait(3)
            Call(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_Jump)
            Wait(1)
            Call(SetPlayerJumpscale, Float(1.0))
            Call(PlayerJump, 812, -170, -2, 20 * DT)
            Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_IN, SOUND_SPACE_DEFAULT)
            Wait(10 * DT)
            Call(UseSettingsFrom, CAM_DEFAULT, 812, 0, 28)
            Call(SetPanTarget, CAM_DEFAULT, 812, 0, 28)
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Wait(10 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Jump)
            Wait(1)
            Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_OUT, SOUND_SPACE_DEFAULT)
            Call(SetPlayerPos, 812, 61, -2)
            Call(PlayerJump, 812, 0, 28, 8 * DT)
            Call(SetPlayerActionState, ACTION_STATE_LAND)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Call(EnablePartnerAI)
            IfEq(GF_OBK01_Portrait_Farewell, FALSE)
                Wait(10 * DT)
                Set(LVar0, 5)
                Exec(N(EVS_AnimateSpeakingPortrait))
                Call(ShowMessageAtScreenPos, MSG_CH3_002F, 160, 40)
                Set(GF_OBK01_Portrait_Farewell, TRUE)
            EndIf
            Call(DisablePlayerPhysics, FALSE)
            Wait(2)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Interact_UpperPortrait) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_BeforeJump)
    Wait(3)
    Call(SetPlayerAnimation, SPRITE_ID_BACK_FACING | ANIM_Mario1_Jump)
    Wait(1)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 812, 40, -2, 20)
    Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_IN, SOUND_SPACE_DEFAULT)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 812, -210, 28)
    Call(SetPanTarget, CAM_DEFAULT, 812, -210, 28)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Jump)
    Wait(1)
    Call(PlaySoundAtPlayer, SOUND_TRANSPORTER_OUT, SOUND_SPACE_DEFAULT)
    Call(SetPlayerPos, 812, -146, -2)
    Call(PlayerJump, 812, -210, 28, 8 * DT)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Wait(2)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_PortraitFrame_ShakeWhenNear) = {
    Loop(0)
        IfEq(AF_OBK01_IsPlayerNearPortrait, TRUE)
            IfNe(AF_OBK01_WasPlayerNearPortrait, AF_OBK01_IsPlayerNearPortrait)
                Loop(3)
                    Call(RotateModel, MODEL_n1, 5, 0, 0, 1)
                    Wait(2)
                    Call(RotateModel, MODEL_n1, 0, 0, 0, 1)
                    Wait(1)
                    Call(RotateModel, MODEL_n1, 5, 0, 0, 1)
                    Wait(2)
                    Call(RotateModel, MODEL_n1, 0, 0, 0, 1)
                    Wait(1)
                EndLoop
            EndIf
        EndIf
        Set(AF_OBK01_WasPlayerNearPortrait, AF_OBK01_IsPlayerNearPortrait)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_PortraitFrame_MonitorPlayerPos) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Set(AF_OBK01_IsPlayerNearPortrait, FALSE)
        IfEq(GF_OBK01_Met_Portrait, FALSE)
            IfGe(LVar1, -210)
                IfLe(LVar1, -100)
                    IfGe(LVar0, 775)
                        Set(AF_OBK01_IsPlayerNearPortrait, TRUE)
                    EndIf
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

s32 N(ItemList_BooPortrait)[] = {
    ITEM_BOO_PORTRAIT,
    ITEM_NONE
};

EvtScript N(EVS_SetupPortrait) = {
    BindPadlock(Ref(N(EVS_Interact_LowerPortrait)), TRIGGER_WALL_PRESS_A, COLLIDER_aa1, Ref(N(ItemList_BooPortrait)), 0, 1)
    BindTrigger(Ref(N(EVS_Interact_UpperPortrait)), TRIGGER_WALL_PRESS_A, COLLIDER_aa2, 1, 0)
    Exec(N(EVS_PortraitFrame_MonitorPlayerPos))
    Exec(N(EVS_PortraitFrame_ShakeWhenNear))
    IfLt(GB_StoryProgress, STORY_CH3_RESTORED_BOO_PORTRAIT)
        Call(EnableModel, MODEL_n1, TRUE)
        Call(EnableModel, MODEL_u1, FALSE)
        Call(EnableModel, MODEL_si1, FALSE)
        Call(EnableModel, MODEL_n2, TRUE)
        Call(EnableModel, MODEL_u2, FALSE)
        Call(EnableModel, MODEL_si2, FALSE)
    Else
        Call(EnableModel, MODEL_n1, FALSE)
        Call(EnableModel, MODEL_n2, FALSE)
        Call(EnableModel, MODEL_u1, TRUE)
        Call(EnableModel, MODEL_u2, TRUE)
        Call(EnableModel, MODEL_si1, FALSE)
        Call(EnableModel, MODEL_si2, FALSE)
    EndIf
    Return
    End
};

s32 N(Unused_80243C7C_3C7C)[] = {
    0, 1, 0, 5, 1, 0, 5, 1,
    0, 5, 1, 1, 5, 1, 1, 5,
    2, 2, 5, 2, 2, 5, 2, 2,
    5, 2, 3, 5, 2, 3, 5, 3,
    4, 5, 3, 4, 5, 3, 4, 5,
    3, 5, 5, 3, 5, 5, 4, 6,
    5, 4, 6, 5, 4, 6, 5, 4,
    7, 5, 4, 7, 5,
};
