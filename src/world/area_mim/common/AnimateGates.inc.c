#include "common.h"

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
