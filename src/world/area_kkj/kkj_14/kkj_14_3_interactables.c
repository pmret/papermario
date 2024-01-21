#include "kkj_14.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/todo/GetPeachDisguise.inc.c"

EvtScript N(EVS_Inspect_Fireplace) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            IfEq(GF_KKJ14_RevealedButton, FALSE)
                IfEq(AF_KKJ_14, FALSE)
                    Call(DisablePartnerAI, 0)
                    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0039)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003A)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003B)
                    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
                    Set(AF_KKJ_14, TRUE)
                    Call(EnablePartnerAI)
                Else
                    Call(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
                EndIf
            Else
                Call(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
            EndIf
        CaseRange(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(ShowMessageAtScreenPos, MSG_Peach_017B, 160, 40)
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0043, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_Dresses) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            IfEq(GF_KKJ14_RevealedButton, FALSE)
                IfEq(AF_KKJ_15, FALSE)
                    Call(DisablePartnerAI, 0)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003C)
                    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003D)
                    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
                    Set(AF_KKJ_15, TRUE)
                    Call(EnablePartnerAI)
                Else
                    Call(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
                EndIf
            Else
                Call(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
            EndIf
        CaseRange(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(ShowMessageAtScreenPos, MSG_Peach_017C, 160, 40)
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0044, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_Vanity) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH1_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(N(GetPeachDisguise), LVar0)
            IfEq(LVar0, 0)
                Call(InterpPlayerYaw, 45, 10)
                Wait(10)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar0, 5)
                Add(LVar1, 35)
                Add(LVar2, -10)
                Loop(6)
                    PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0)
                    Wait(15)
                EndLoop
            Else
                Call(DisablePartnerAI, 0)
                Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0044)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0045)
                Call(EnablePartnerAI)
            EndIf
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0045, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_Photo) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            IfEq(GF_KKJ14_RevealedButton, FALSE)
                IfEq(AF_KKJ_17, FALSE)
                    Call(DisablePartnerAI, 0)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_003E)
                    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_003F)
                    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
                    Set(AF_KKJ_17, TRUE)
                    Call(EnablePartnerAI)
                Else
                    Call(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
                EndIf
            Else
                Call(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
            EndIf
        CaseRange(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(ShowMessageAtScreenPos, MSG_Peach_017D, 160, 40)
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0046, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_Bed) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            IfEq(GF_KKJ14_RevealedButton, FALSE)
                IfEq(AF_KKJ_18, FALSE)
                    Call(DisablePartnerAI, 0)
                    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0040)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0041)
                    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
                    Set(AF_KKJ_18, TRUE)
                    Call(EnablePartnerAI)
                Else
                    Call(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
                EndIf
            Else
                Call(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
            EndIf
        CaseRange(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(ShowMessageAtScreenPos, MSG_Peach_017E, 160, 40)
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0047, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_Flowers) = {
    Call(DisablePlayerInput, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            IfEq(GF_KKJ14_RevealedButton, FALSE)
                IfEq(AF_KKJ_19, FALSE)
                    Call(DisablePartnerAI, 0)
                    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
                    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0042)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0043)
                    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
                    Set(AF_KKJ_19, TRUE)
                    Call(EnablePartnerAI)
                Else
                    Call(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
                EndIf
            Else
                Call(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
            EndIf
        CaseRange(STORY_CH2_BEGAN_PEACH_MISSION, STORY_CH7_BEGAN_PEACH_MISSION)
            Call(ShowMessageAtScreenPos, MSG_Peach_017F, 160, 40)
        CaseDefault
            Call(ShowMessageAtScreenPos, MSG_Intro_0048, 160, 40)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

s32 N(FireplaceAlpha) = 255;

API_CALLABLE(N(SetFireplaceAlpha)) {
    Bytecode* args = script->ptrReadPos;

    N(FireplaceAlpha) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(setup_gfx_fireplace)(void) {
    gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_INTERFERENCE, PM_CC_KKJ14_FIRE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(FireplaceAlpha));
}

EvtScript N(EVS_TexPan_Fireplace) = {
    Call(EnableTexPanning, MODEL_o42, TRUE)
    Call(EnableTexPanning, MODEL_o157, TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Loop(0)
        Add(LVar0, -110)
        Add(LVar1, 50)
        Call(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar2, 40)
        Add(LVar3, 130)
        Call(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_AUX, LVar2, LVar3)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_RevealButton) = {
    Call(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_REVEAL_BUTTON, 0)
    Call(MakeLerp, 0, 180, 15, EASING_LINEAR)
    Call(UpdateLerp)
    Call(RotateGroup, MODEL_g39, LVar0, 1, 0, 0)
    Wait(1)
    Call(EnableModel, MODEL_o146, TRUE)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g39, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, MODEL_o141, FALSE)
    Call(EnableModel, MODEL_o143, FALSE)
    Set(GF_KKJ14_RevealedButton, TRUE)
    Return
    End
};

EvtScript N(EVS_OpenHiddenPassage) = {
    Call(EnableModel, MODEL_o35, FALSE)
    Call(EnableModel, MODEL_o42, FALSE)
    Call(EnableGroup, MODEL_g27, TRUE)
    IfEq(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        Set(LVar0, 120 * DT)
    Else
        Set(LVar0, 60 * DT)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o129, SOUND_KKJ_EXTINGUISH_FIRE, 0)
    Call(MakeLerp, 255, 0, LVar0, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetFireplaceAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, MODEL_o157, FALSE)
    Call(SetModelFlags, MODEL_o157, 16, FALSE)
    Wait(10 * DT)
    Thread
        Wait(20 * DT)
        Call(PlaySoundAt, SOUND_KKJ_DROP_INTO_ASHES, SOUND_SPACE_DEFAULT, -125, 10, -120)
        PlayEffect(EFFECT_SMOKE_BURST, 0, -125, 10, -120, Float(2.0), 30)
    EndThread
    Call(MakeLerp, 0, -180, 30 * DT, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o39, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o129, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_KKJ14_OpenedPassage, TRUE)
    Return
    End
};

EvtScript N(EVS_Inspect_HiddenButton) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    IfEq(GF_KKJ14_RevealedButton, FALSE)
        ExecWait(N(EVS_RevealButton))
    Else
        Call(FacePlayerTowardPoint, -29, -148, 5)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Peach3_ReachForButtonHigh)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Peach3_PressButtonHigh)
        Thread
            Wait(5)
            Call(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_PRESS_BUTTON, 0)
        EndThread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump1, LVar0, LVar1, LVar2, 10)
        Call(SetPlayerAnimation, ANIM_Peach3_AfterPressButtonHigh)
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Peach1_Idle)
        Call(InterpPlayerYaw, 225, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        ExecWait(N(EVS_OpenHiddenPassage))
        Unbind
    EndIf
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Inspect_HiddenButton_FirstTime) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    IfEq(GF_KKJ14_RevealedButton, FALSE)
        IfEq(AF_KKJ_04, FALSE)
            Call(NpcFacePlayer, NPC_PARTNER, 0)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 5, MSG_Peach_0046)
            Set(AF_KKJ_04, TRUE)
        EndIf
        ExecWait(N(EVS_RevealButton))
    Else
        Call(FacePlayerTowardPoint, -29, -148, 5)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Peach3_ReachForButtonHigh)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Peach3_PressButtonHigh)
        Thread
            Wait(5)
            Call(PlaySoundAtCollider, COLLIDER_o128, SOUND_KKJ_PRESS_BUTTON, 0)
        EndThread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump1, LVar0, LVar1, LVar2, 10)
        Call(SetPlayerAnimation, ANIM_Peach3_AfterPressButtonHigh)
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Peach1_Idle)
        Call(InterpPlayerYaw, 225, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 225, 0)
        IfEq(AF_KKJ_05, FALSE)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, -120, 25, 0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
            Call(SetCamDistance, CAM_DEFAULT, 300)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        EndIf
        ExecWait(N(EVS_OpenHiddenPassage))
        IfEq(AF_KKJ_05, FALSE)
            Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
            Call(SetPlayerAnimation, ANIM_Peach2_Delighted)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_ShoutJoy, ANIM_Twink_ShoutJoy, 5, MSG_Peach_0047)
            Set(AF_KKJ_05, TRUE)
        EndIf
        Unbind
    EndIf
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupInteractables) = {
    IfEq(GF_KKJ14_RevealedButton, FALSE)
        Call(EnableModel, MODEL_o146, FALSE)
    Else
        Call(EnableModel, MODEL_o141, FALSE)
        Call(EnableModel, MODEL_o143, FALSE)
        Call(RotateGroup, MODEL_g39, 180, 1, 0, 0)
    EndIf
    IfEq(GF_KKJ14_OpenedPassage, FALSE)
        Call(EnableGroup, MODEL_g27, FALSE)
        Exec(N(EVS_TexPan_Fireplace))
        Call(SetModelCustomGfx, MODEL_o157, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
        Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_fireplace)), NULL)
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH0_WAKE_UP)
            CaseLt(STORY_CH2_BEGAN_PEACH_MISSION)
                BindTrigger(Ref(N(EVS_Inspect_HiddenButton_FirstTime)), TRIGGER_WALL_PRESS_A, COLLIDER_o128, 1, 0)
            CaseLt(STORY_CH8_REACHED_PEACHS_CASTLE)
                BindTrigger(Ref(N(EVS_Inspect_HiddenButton)), TRIGGER_WALL_PRESS_A, COLLIDER_o128, 1, 0)
            CaseDefault
        EndSwitch
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o129, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        Call(RotateModel, MODEL_o39, -180, 1, 0, 0)
        Call(EnableGroup, MODEL_g45, FALSE)
    EndIf
    BindTrigger(Ref(N(EVS_Inspect_Fireplace)), TRIGGER_WALL_PRESS_A, COLLIDER_o129, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Dresses)), TRIGGER_WALL_PRESS_A, COLLIDER_o143, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Vanity)), TRIGGER_WALL_PRESS_A, COLLIDER_o142, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Photo)), TRIGGER_WALL_PRESS_A, COLLIDER_o141, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Bed)), TRIGGER_WALL_PRESS_A, COLLIDER_o25, 1, 0)
    BindTrigger(Ref(N(EVS_Inspect_Flowers)), TRIGGER_WALL_PRESS_A, COLLIDER_o135, 1, 0)
    Return
    End
};
