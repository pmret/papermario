#include "kzn_17.h"
#include "effects.h"

#define UNK_FUNC_50_LVar1 -583.0
#define UNK_FUNC_50_LVar2 165.0

#include "../common/SpinyTromp.inc.c"

EvtScript N(EVS_SpinyTromp_ManageCamera) = {
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamDistance, CAM_DEFAULT, 500)
    Call(SetCamSpeed, CAM_DEFAULT, Float(10.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Loop(0)
        IfEq(AF_KZN_Tromp2_ShakingDone, FALSE)
            IfLt(MV_TrompPosX, 550)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(MV_TrompPosX, LVar0)
                    Add(LVar0, MV_TrompPosX)
                    Div(LVar0, 2)
                Else
                    Set(LVar0, MV_TrompPosX)
                EndIf
                Add(LVar1, 55)
                Set(LVar2, LVar1)
                Call(N(UnkFunc46))
                Sub(LVar2, 55)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar2, 30)
                Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            EndIf
        EndIf
        Wait(1)
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
    IfGe(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
        Call(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
        Call(EnableModel, MODEL_me, FALSE)
        Call(EnableModel, MODEL_mae, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_gogo, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    Call(EnableModel, MODEL_ato, FALSE)
    Set(AF_KZN_Tromp2_HitKolorado, FALSE)
    Set(AF_KZN_Tromp2_ShakingDone, FALSE)
    Set(AF_KZN_TrompHitPlayer, FALSE)
    Set(AF_KZN_TrompRollingDone, FALSE)
    Set(AF_KZN_Tromp2_StopPlayer, FALSE)
    Set(LVar0, -583)
    Set(LVar2, 165)
    Call(TranslateGroup, MODEL_goron, LVar0, LVar2, 30)
    Call(TranslateModel, MODEL_me, LVar0, LVar2, 30)
    Label(0)
    Wait(1)
    IfEq(GF_KZN17_Hammer3BlockG, FALSE)
        Goto(0)
    EndIf
    ExecGetTID(N(EVS_SpinyTromp_ManageCamera), LVarA)
    Exec(N(EVS_Kolorado_TrompPanic))
    ExecGetTID(N(EVS_SpinyTromp_ShakeCam), MV_ScreenShakeTID)
    Call(PlaySound, SOUND_LOOP_TROMP_ROLL)
    Set(LVar3, 0)
    Call(MakeLerp, -583, 750, 270, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(UnkFunc46))
        Call(N(UnkFunc51), LVar0, LVar1, LVar2)
        Set(MV_TrompPosX, LVar0)
        Add(MV_TrompPosX, 20)
        Call(TranslateGroup, MODEL_goron, LVar0, LVar2, 30)
        Call(TranslateModel, MODEL_me, LVar0, LVar2, 30)
        Call(RotateGroup, MODEL_goron, LVar3, 0, 0, 1)
        Call(RotateModel, MODEL_me, LVar3, 0, 0, 1)
        Call(N(UnkFunc49))
        Call(TranslateModel, MODEL_me, LVar5, LVar6, 30)
        Call(N(UnkFunc50))
        IfEq(AF_KZN_Tromp2_StopPlayer, FALSE)
            Thread
                Call(GetPlayerPos, LVar3, LVar1, LVar2)
                Sub(LVar3, 20)
                IfLt(LVar3, LVar0)
                    Call(DisablePlayerInput, TRUE)
                    Set(AF_KZN_Tromp2_StopPlayer, TRUE)
                    Label(12)
                        Wait(1)
                        IfNe(AF_KZN_Tromp2_StopPlayer, FALSE)
                            Goto(12)
                        EndIf
                    Call(DisablePlayerInput, FALSE)
                EndIf
            EndThread
        EndIf
        IfEq(AF_KZN_Tromp2_HitKolorado, FALSE)
            IfGt(LVar0, 430)
                Exec(N(EVS_Kolorado_TrompImpact))
                Set(AF_KZN_Tromp2_HitKolorado, TRUE)
            EndIf
        EndIf
        IfEq(AF_KZN_Tromp2_ShakingDone, FALSE)
            IfGt(LVar0, 630)
                KillThread(MV_ScreenShakeTID)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_gogo, COLLIDER_FLAGS_UPPER_MASK)
                Call(PlaySoundAtCollider, COLLIDER_gogo, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT)
                PlayEffect(EFFECT_BOMBETTE_BREAKING, 2, 32, 32, 1, 10, 45)
                Call(EnableModel, MODEL_mae, FALSE)
                Call(EnableModel, MODEL_ato, TRUE)
                Thread
                    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(3.0))
                    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.7))
                    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.5))
                EndThread
                Set(AF_KZN_Tromp2_ShakingDone, TRUE)
            EndIf
        EndIf
        Wait(1)
        Call(N(SpinyTromp_CheckDist))
        IfLt(LVar4, 80)
            IfEq(AF_KZN_TrompHitPlayer, FALSE)
                Call(N(SpinyTromp_GetActingPartner))
                IfNe(LVar0, PARTNER_BOW)
                    Set(AF_KZN_TrompHitPlayer, TRUE)
                    Exec(N(D_80240D10_C7EE90))
                EndIf
            EndIf
        EndIf
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
    Wait(50)
    Call(StopSound, SOUND_LOOP_TROMP_ROLL)
    Call(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
    Call(EnableModel, MODEL_me, FALSE)
    KillThread(LVarA)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Set(AF_KZN_Tromp2_StopPlayer, FALSE)
    Set(AF_KZN_TrompRollingDone, TRUE)
    Return
    End
};
