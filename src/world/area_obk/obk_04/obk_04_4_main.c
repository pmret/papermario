#include "obk_04.h"
#include "effects.h"

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(obk_04_ENTRY_0)
            Thread
                Wait(10)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetPlayerSpeed, Float(3.0))
                Call(PlayerMoveTo, -150, LVar2, 0)
            EndThread
            Call(EnableModel, MODEL_door_off1, FALSE)
            Call(EnableModel, MODEL_door_off2, FALSE)
            Set(LVar2, MODEL_door1)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
            Call(EnableModel, MODEL_door_off1, TRUE)
            Call(EnableModel, MODEL_door_off2, TRUE)
            Wait(20)
            Call(MakeLerp, 0, -90, 15, EASING_QUADRATIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_door1, LVar0, 0, 0, 1)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            PlayEffect(EFFECT_LANDING_DUST, 1, -215, 0, 25, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, -215, 0, -25, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, -200, 0, 25, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, -200, 0, -25, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, -185, 0, 25, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, -185, 0, -25, 0)
            Wait(20)
            Call(EnableModel, MODEL_door1, FALSE)
            Call(MakeLerp, 0, 10, 15, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_door_off1, LVar0, 0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(EnableModel, MODEL_door_off3, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TexPan_Fog) = {
    Thread
        Call(SetTexPanner, MODEL_m1, TEX_PANNER_0)
        Call(SetTexPanner, MODEL_m2, TEX_PANNER_0)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Label(20)
        Add(LVar0, 300)
        Add(LVar1, 100)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        Wait(1)
        Goto(20)
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_ManageHole))
    Exec(N(EVS_TexPan_Fog))
    Exec(N(EVS_EnterMap))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hip1, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
