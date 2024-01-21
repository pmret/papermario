#include "hos_04.h"

EvtScript N(EVS_ExitWalk_hos_03_1) = EVT_EXIT_WALK(60, hos_04_ENTRY_0, "hos_03", hos_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_hos_05_0) = EVT_EXIT_WALK(60, hos_04_ENTRY_1, "hos_05", hos_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_hos_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_hos_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o163, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(AF_HOS_B5, FALSE)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_04_ENTRY_0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
            IfEq(GF_HOS04_Visited, FALSE)
                Thread
                    Call(DisablePlayerInput, TRUE)
                    Call(SetPlayerPos, -630, 0, 0)
                    Call(GetPartnerInUse, LVar0)
                    IfEq(LVar0, PARTNER_NONE)
                        Call(DisablePartnerAI, 0)
                        Call(SetNpcPos, NPC_PARTNER, -660, 0, 0)
                        Wait(1)
                        Call(EnablePartnerAI)
                    EndIf
                    Call(UseSettingsFrom, CAM_DEFAULT, -565, 0, 0)
                    Call(SetPanTarget, CAM_DEFAULT, -565, 0, 0)
                    Call(SetCamDistance, CAM_DEFAULT, 1350)
                    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-25.0))
                    Call(SetCamPosA, CAM_DEFAULT, Float(-15.0), Float(-100.0))
                    Call(SetCamPosB, CAM_DEFAULT, Float(87.5), Float(50.0))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Wait(10)
                    Call(SetCamPitch, CAM_DEFAULT, Float(4.0), Float(-7.5))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(0.15))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Wait(30)
                    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                    ExecWait(EnterWalk)
                    Wait(20)
                    Set(GF_HOS04_Visited, TRUE)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
                    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Call(PanToTarget, CAM_DEFAULT, 0, 0)
                    Set(AF_HOS_B5, TRUE)
                    Call(DisablePlayerInput, FALSE)
                EndThread
            Else
                Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                Exec(EnterWalk)
                Wait(1)
            EndIf
        CaseEq(hos_04_ENTRY_1)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(hos_04_ENTRY_2)
            Exec(N(EVS_Starship_FlyingAway))
        CaseEq(hos_04_ENTRY_3)
            ExecWait(N(EVS_Intro_PreHeist_Unused))
        CaseEq(hos_04_ENTRY_4)
            ExecWait(N(EVS_Intro_PostHeist))
        CaseEq(hos_04_ENTRY_5)
            Call(EnableGroup, MODEL_g1, FALSE)
            Exec(N(EVS_BetaStarship_Flight1))
        CaseEq(hos_04_ENTRY_6)
            Call(EnableGroup, MODEL_g1, FALSE)
            Exec(N(EVS_BetaStarship_Flight2))
        CaseEq(hos_04_ENTRY_7)
            Call(EnableGroup, MODEL_g1, FALSE)
            Exec(N(EVS_BetaStarship_Return))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_STAR_HAVEN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Thread
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndThread
    Exec(N(EVS_SetupFountains))
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupNarrator))
    Return
    End
};
