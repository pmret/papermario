#include "mim_07.h"

EvtScript N(EVS_SetGateCameraZones) = {
    Switch(LVar1)
        CaseEq(0)
            Call(SetZoneEnabled, ZONE_north, TRUE)
            Call(SetZoneEnabled, ZONE_west, TRUE)
            Call(SetZoneEnabled, ZONE_south, TRUE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, TRUE)
            Call(SetZoneEnabled, ZONE_nishi, FALSE)
            Call(SetZoneEnabled, ZONE_minami, FALSE)
            Call(SetZoneEnabled, ZONE_kita, FALSE)
            Call(SetZoneEnabled, ZONE_stage, FALSE)
            Set(LVar1, 0)
        CaseEq(1)
            Call(SetZoneEnabled, ZONE_north, FALSE)
            Call(SetZoneEnabled, ZONE_west, FALSE)
            Call(SetZoneEnabled, ZONE_south, FALSE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, FALSE)
            Call(SetZoneEnabled, ZONE_nishi, FALSE)
            Call(SetZoneEnabled, ZONE_minami, FALSE)
            Call(SetZoneEnabled, ZONE_kita, FALSE)
            Call(SetZoneEnabled, ZONE_stage, TRUE)
            Set(LVar1, 1)
        CaseEq(2)
            Call(SetZoneEnabled, ZONE_north, FALSE)
            Call(SetZoneEnabled, ZONE_west, FALSE)
            Call(SetZoneEnabled, ZONE_south, FALSE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, TRUE)
            Call(SetZoneEnabled, ZONE_nishi, TRUE)
            Call(SetZoneEnabled, ZONE_minami, TRUE)
            Call(SetZoneEnabled, ZONE_kita, TRUE)
            Call(SetZoneEnabled, ZONE_stage, FALSE)
            Set(LVar1, 2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_InitializeGates) = {
    Call(ParentColliderToModel, COLLIDER_monn, MODEL_n1)
    Call(RotateGroup, MODEL_monn, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monn)
    Call(ParentColliderToModel, COLLIDER_mons, MODEL_s1)
    Call(RotateGroup, MODEL_mons, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mons)
    Call(ParentColliderToModel, COLLIDER_mone, MODEL_e1)
    Call(RotateGroup, MODEL_mone, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mone)
    Call(ParentColliderToModel, COLLIDER_monw, MODEL_w1)
    Call(RotateGroup, MODEL_monw, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monw)
    Return
    End
};

EvtScript N(EVS_ResetGates) = {
    Call(RotateGroup, MODEL_monn, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monn)
    Call(RotateGroup, MODEL_mons, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mons)
    Call(RotateGroup, MODEL_mone, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mone)
    Call(RotateGroup, MODEL_monw, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monw)
    Return
    End
};

EvtScript N(EVS_UseGate) = {
    Thread
        Call(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_OPEN, SOUND_SPACE_DEFAULT)
        Wait(19)
        Call(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Switch(AB_MIM_1)
        CaseEq(0)
            Thread
                Call(MakeLerp, 10, 90, 10, EASING_QUADRATIC_IN)
                Label(10)
                Call(UpdateLerp)
                Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
                Call(UpdateColliderTransform, LVar9)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(10)
                EndIf
            EndThread
            Wait(15)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar0, LVar7)
                Add(LVar2, LVar8)
                Call(PlayerMoveTo, LVar0, LVar2, 15)
            EndThread
            Set(LVar1, 1)
            Exec(N(EVS_SetGateCameraZones))
            Call(MakeLerp, 90, 360, 30, EASING_LINEAR)
            Label(20)
            Call(UpdateLerp)
            Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, LVar9)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(20)
            EndIf
            Exec(N(EVS_ResetGates))
            Set(AB_MIM_1, 1)
            Set(GF_MIM_ChoosingPath, TRUE)
        CaseEq(1)
            Thread
                Call(MakeLerp, 360, 270, 10, EASING_QUADRATIC_IN)
                Label(30)
                Call(UpdateLerp)
                Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
                Call(UpdateColliderTransform, LVar9)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(30)
                EndIf
            EndThread
            Wait(15)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Sub(LVar0, LVar7)
                Sub(LVar2, LVar8)
                Call(PlayerMoveTo, LVar0, LVar2, 15)
            EndThread
            Set(LVar1, 2)
            Exec(N(EVS_SetGateCameraZones))
            Call(MakeLerp, 270, -10, 30, EASING_LINEAR)
            Label(40)
            Call(UpdateLerp)
            Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, LVar9)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(40)
            EndIf
            Set(AB_MIM_1, 2)
        CaseEq(2)
            Thread
                Call(MakeLerp, -10, 90, 10, EASING_QUADRATIC_IN)
                Label(50)
                Call(UpdateLerp)
                Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
                Call(UpdateColliderTransform, LVar9)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(50)
                EndIf
            EndThread
            Wait(15)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar0, LVar7)
                Add(LVar2, LVar8)
                Call(PlayerMoveTo, LVar0, LVar2, 15)
            EndThread
            Set(LVar1, 1)
            Exec(N(EVS_SetGateCameraZones))
            Call(MakeLerp, 90, 360, 30, EASING_LINEAR)
            Label(60)
            Call(UpdateLerp)
            Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, LVar9)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(60)
            EndIf
            Exec(N(EVS_ResetGates))
            Set(AB_MIM_1, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseGate_North) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, 0)
    Set(LVar8, 70)
    Set(LVar9, COLLIDER_monn)
    Set(LVarA, MODEL_monn)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_South) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, 0)
    Set(LVar8, -70)
    Set(LVar9, COLLIDER_mons)
    Set(LVarA, MODEL_mons)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_East) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, -70)
    Set(LVar8, 0)
    Set(LVar9, COLLIDER_mone)
    Set(LVarA, MODEL_mone)
    ExecWait(N(EVS_UseGate))
    IfGe(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        IfEq(GF_MIM10_Defeated_JrTroopa, FALSE)
            IfEq(GF_MIM10_JrTroopaFreakout, FALSE)
                Set(GF_MIM10_JrTroopaFreakout, TRUE)
                Call(ShowMessageAtScreenPos, MSG_CH3_0017, 160, 40)
            EndIf
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_West) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, 70)
    Set(LVar8, 0)
    Set(LVar9, COLLIDER_monw)
    Set(LVarA, MODEL_monw)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupGates) = {
    IfEq(GF_MIM_ChoosingPath, FALSE)
        Set(GF_MIM_ChoosingPath, TRUE)
        Set(AB_MIM_1, 2)
        Set(LVar1, 2)
        Set(LVar2, -10)
    Else
        Set(GF_MIM_ChoosingPath, FALSE)
        Set(AB_MIM_1, 0)
        Set(LVar1, 0)
        Set(LVar2, 10)
    EndIf
    ExecWait(N(EVS_SetGateCameraZones))
    Exec(N(EVS_InitializeGates))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    BindTrigger(Ref(N(EVS_UseGate_North)), TRIGGER_WALL_PRESS_A, COLLIDER_monn, 1, 0)
    BindTrigger(Ref(N(EVS_UseGate_South)), TRIGGER_WALL_PRESS_A, COLLIDER_mons, 1, 0)
    BindTrigger(Ref(N(EVS_UseGate_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    BindTrigger(Ref(N(EVS_UseGate_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_mone, 1, 0)
    Return
    End
};
