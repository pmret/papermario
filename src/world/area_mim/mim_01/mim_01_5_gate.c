#include "mim_01.h"

EvtScript N(EVS_SetGateCameraZones) = {
    Switch(LVar1)
        CaseEq(0)
            Call(SetZoneEnabled, ZONE_north, TRUE)
            Call(SetZoneEnabled, ZONE_west, TRUE)
            Call(SetZoneEnabled, ZONE_south, TRUE)
            Call(SetZoneEnabled, ZONE_east, TRUE)
            Call(SetZoneEnabled, ZONE_higashi, FALSE)
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
            Call(SetZoneEnabled, ZONE_west, TRUE)
            Call(SetZoneEnabled, ZONE_south, FALSE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, TRUE)
            Call(SetZoneEnabled, ZONE_nishi, FALSE)
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
    Call(RotateGroup, MODEL_monw, 10, 0, 1, 0)
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

EvtScript N(EVS_PlayGateSounds) = {
    Call(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Wait(19)
    Call(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_UseGate) = {
    Exec(N(EVS_PlayGateSounds))
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
    Set(LVar9, 26)
    Set(LVarA, 155)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_South) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, 0)
    Set(LVar8, -70)
    Set(LVar9, 30)
    Set(LVarA, 161)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_East) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar7, -70)
    Set(LVar8, 0)
    Set(LVar9, 28)
    Set(LVarA, 158)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseGate_West) = {
    Set(LVar9, 32)
    Exec(N(EVS_PlayGateSounds))
    Call(DisablePlayerInput, TRUE)
    IfNe(AB_MIM_1, 1)
        Thread
            Call(MakeLerp, 10, 90, 10, EASING_QUADRATIC_IN)
            Label(10)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, COLLIDER_monw)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        EndThread
        Wait(15)
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, 70)
            Call(PlayerMoveTo, LVar0, LVar2, 15)
        EndThread
        Set(LVar1, 1)
        Exec(N(EVS_SetGateCameraZones))
        Call(MakeLerp, 90, 360, 30, EASING_LINEAR)
        Label(20)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
        Call(UpdateColliderTransform, COLLIDER_monw)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Exec(N(EVS_ResetGates))
        Set(AB_MIM_1, 1)
        Set(GF_MIM_ChoosingPath, TRUE)
    Else
        Thread
            Call(MakeLerp, 360, 270, 10, EASING_QUADRATIC_IN)
            Label(30)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
            Call(UpdateColliderTransform, COLLIDER_monw)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(30)
            EndIf
        EndThread
        Wait(15)
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar0, 70)
            Call(PlayerMoveTo, LVar0, LVar2, 15)
        EndThread
        Set(LVar1, 2)
        Exec(N(EVS_SetGateCameraZones))
        Call(MakeLerp, 270, 10, 30, EASING_LINEAR)
        Label(40)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
        Call(UpdateColliderTransform, COLLIDER_monw)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
        Set(AB_MIM_1, 0)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

#include "../common/SetupGates.inc.c"
