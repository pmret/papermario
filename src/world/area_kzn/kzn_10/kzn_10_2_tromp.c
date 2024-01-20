#include "kzn_10.h"
#include "effects.h"
#include "sprite/player.h"

#define UNK_FUNC_50_LVar1 -469.0
#define UNK_FUNC_50_LVar2 46.0

#include "../common/SpinyTromp.inc.c"

EvtScript N(EVS_SpinyTromp_ManageCamera) = {
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, Float(10.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Loop(0)
        IfEq(AF_KZN_TrompHitPlayer, FALSE)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, MV_TrompPosX)
            Div(LVar0, 2)
        Else
            Set(LVar0, MV_TrompPosX)
        EndIf
        Set(LVar3, LVar0)
        Switch(LVar3)
            CaseLt(-350)
                Set(LVar6, 500)
            CaseLt(-200)
                Set(LVar6, LVar3)
                Add(LVar6, 850)
            CaseLt(150)
                Set(LVar6, 650)
            CaseLt(300)
                Set(LVar0, LVar3)
                Set(LVar6, 800)
                Sub(LVar6, LVar0)
            CaseDefault
                Set(LVar6, 500)
        EndSwitch
        Call(SetCamDistance, CAM_DEFAULT, LVar6)
        Set(LVar0, LVar3)
        Set(LVar2, 0)
        Call(N(UnkFunc46))
        Sub(LVar2, 55)
        Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar2, 0)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(D_80241224_C7F3A4) = {
    SetGroup(EVT_GROUP_0A)
    Loop(5)
        PlayEffect(EFFECT_DUST, 1, -430, 100, 0, 30)
        Wait(2)
    EndLoop
    Label(0)
    Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar1, 100)
    PlayEffect(EFFECT_DUST, 1, LVar0, LVar1, LVar2, 40)
    Wait(20)
    Sub(LVar0, 100)
    Add(LVar1, 50)
    PlayEffect(EFFECT_DUST, 1, LVar0, LVar1, LVar2, 40)
    Wait(20)
    IfEq(AF_KZN_Tromp1_ShakingDone, FALSE)
        Goto(0)
    EndIf
    Loop(8)
        PlayEffect(EFFECT_DUST, 1, 400, -80, 0, 40)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SpinyTromp_ShakeCam) = {
    Loop(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.0))
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupSpinyTromp) = {
    SetGroup(EVT_GROUP_EF)
    Call(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
    Call(EnableModel, MODEL_me, FALSE)
    Call(TranslateGroup, MODEL_goron, 0, 0, 0)
    Call(RotateGroup, MODEL_goron, 0, 0, 0, 1)
    Set(AF_KZN_Tromp1_ShakingDone, FALSE)
    Set(AF_KZN_TrompHitPlayer, FALSE)
    Set(AF_KZN_TrompRollingDone, FALSE)
    Call(GetEntryID, LVar3)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(LVar3, kzn_10_ENTRY_0)
            IfGe(LVar0, -400)
                BreakLoop
            EndIf
        Else
            IfLe(LVar0, -400)
                BreakLoop
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Call(InterruptUsePartner)
    Call(SetGroupVisibility, MODEL_goron, MODEL_GROUP_VISIBLE)
    Call(EnableModel, MODEL_me, TRUE)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, UNK_FUNC_50_LVar1)
    Set(LVar2, 0)
    Call(N(UnkFunc46))
    Call(MakeLerp, 200, LVar2, 20, EASING_QUADRATIC_IN)
    Label(10)
    Call(UpdateLerp)
    Set(MV_TrompPosX, UNK_FUNC_50_LVar1)
    Call(TranslateGroup, MODEL_goron, UNK_FUNC_50_LVar1, LVar0, 0)
    Call(TranslateModel, MODEL_me, UNK_FUNC_50_LVar1, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Sub(LVar2, 55)
    PlayEffect(EFFECT_LANDING_DUST, 4, UNK_FUNC_50_LVar1, LVar2, 0)
    Exec(N(D_80241224_C7F3A4))
    Thread
        Call(GetPartnerInUse, LVar0)
        Switch(LVar0)
            CaseEq(PARTNER_PARAKARRY)
            CaseEq(PARTNER_BOW)
            CaseDefault
                Call(GetPlayerPos, LVar1, LVar2, LVar3)
                Call(SetPlayerJumpscale, Float(2.5))
                Call(PlayerJump1, LVar1, LVar2, LVar3, 8)
                Call(InterpPlayerYaw, 270, 0)
                IfNe(LVar0, PARTNER_LAKILESTER)
                    Wait(3)
                    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
                    Wait(10)
                    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                EndIf
        EndSwitch
    EndThread
    Call(PlaySoundAt, SOUND_TROMP_DROP, SOUND_SPACE_DEFAULT, -465, 0, 0)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(2.5))
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.2))
    Wait(15)
    Call(DisablePlayerInput, FALSE)
    ExecGetTID(N(EVS_SpinyTromp_ManageCamera), LVarA)
    ExecGetTID(N(EVS_SpinyTromp_ShakeCam), MV_ScreenShakeTID)
    Call(PlaySoundAt, SOUND_LOOP_TROMP_ROLL, SOUND_SPACE_DEFAULT, -465, 0, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Call(MakeLerp, UNK_FUNC_50_LVar1, 418, 180, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(UnkFunc46))
        Call(N(UnkFunc51), LVar0, LVar1, LVar2)
        Set(MV_TrompPosX, LVar0)
        Call(TranslateGroup, MODEL_goron, LVar0, LVar2, 0)
        Call(TranslateModel, MODEL_me, LVar0, LVar2, 0)
        Set(LVar8, LVar0)
        Set(LVar9, LVar2)
        Call(RotateGroup, MODEL_goron, LVar3, 0, 0, 1)
        Call(RotateModel, MODEL_me, LVar3, 0, 0, 1)
        Call(N(UnkFunc49))
        Call(TranslateModel, MODEL_me, LVar5, LVar6, 0)
        Call(N(UnkFunc50))
        Wait(1)
        Call(N(SpinyTromp_CheckDist))
        IfLt(LVar4, 80)
            IfEq(AF_KZN_TrompHitPlayer, FALSE)
                Call(N(SpinyTromp_GetActingPartner))
                IfNe(LVar0, PARTNER_BOW)
                    Exec(N(D_80240D10_C7EE90))
                    IfEq(AF_KZN_TrompHitPlayer, FALSE)
                        KillThread(LVarA)
                        Set(AF_KZN_TrompHitPlayer, TRUE)
                    EndIf
                    Thread
                        Call(ResetCam, CAM_DEFAULT, Float(2.0))
                        Wait(45)
                        Set(AF_KZN_TrompRollingDone, TRUE)
                    EndThread
                EndIf
            EndIf
        EndIf
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(AF_KZN_Tromp1_ShakingDone, TRUE)
    KillThread(MV_ScreenShakeTID)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 35, Float(2.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
    EndThread
    Call(StopSound, SOUND_LOOP_TROMP_ROLL)
    Call(PlaySoundAt, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT, 415, -240, 0)
    Call(EnableModel, MODEL_me, FALSE)
    Thread
        Set(LVar0, 418)
        Set(LVar2, 0)
        Call(N(UnkFunc46))
        PlayEffect(EFFECT_00, LVar0, LVar2, 0, 1, 20, 3, 8)
    EndThread
    Set(LVar0, LVar8)
    Set(LVar1, LVar9)
    Set(LVar2, LVar8)
    Set(LVar3, LVar9)
    Set(LVar4, LVar8)
    Set(LVar5, LVar9)
    Set(LVar6, LVar8)
    Set(LVar7, LVar9)
    Loop(90)
        Call(TranslateModel, MODEL_o70, LVar6, LVar1, 0)
        Call(TranslateModel, MODEL_o72, LVar6, LVar3, 0)
        Call(TranslateModel, MODEL_o73, LVar4, LVar5, 0)
        Call(TranslateModel, MODEL_o74, LVar4, LVar7, 0)
        Call(TranslateModel, MODEL_2_1, LVar2, LVar3, 0)
        Call(TranslateModel, MODEL_2_2, LVar2, LVar1, 0)
        Call(TranslateModel, MODEL_2_3, LVar0, LVar7, 0)
        Call(TranslateModel, MODEL_2_4, LVar0, LVar5, 0)
        Call(TranslateModel, MODEL_3_1, LVar0, LVar5, 0)
        Call(TranslateModel, MODEL_3_2, LVar0, LVar7, 0)
        Call(TranslateModel, MODEL_3_3, LVar2, LVar1, 0)
        Call(TranslateModel, MODEL_3_4, LVar2, LVar3, 0)
        Call(TranslateModel, MODEL_4_1, LVar4, LVar7, 0)
        Call(TranslateModel, MODEL_4_2, LVar4, LVar5, 0)
        Call(TranslateModel, MODEL_4_3, LVar6, LVar3, 0)
        Call(TranslateModel, MODEL_4_4, LVar6, LVar1, 0)
        Add(LVar0, 2)
        Add(LVar1, -7)
        Add(LVar2, -5)
        Add(LVar3, 7)
        Add(LVar4, 9)
        Add(LVar5, -3)
        Add(LVar6, -6)
        Add(LVar7, 7)
        Wait(1)
    EndLoop
    Call(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
    Call(EnableModel, MODEL_me, FALSE)
    Wait(10)
    IfEq(AF_KZN_TrompHitPlayer, FALSE)
        KillThread(LVarA)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Set(AF_KZN_TrompRollingDone, TRUE)
    EndIf
    Return
    End
};
