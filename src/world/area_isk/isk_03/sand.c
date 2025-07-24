#include "isk_03.h"

EvtScript N(EVS_TexPan_DrippingSand) = {
    Call(SetTexPanner, MODEL_o6000, TEX_PANNER_4)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Label(10)
        Add(LVar1, -1000)
        Add(LVar2, 200)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar2, 0)
        Wait(1)
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
            Goto(10)
        EndIf
    Call(EnableModel, MODEL_o6000, false)
    Return
    End
};

EvtScript N(EVS_Camera_LookAtDrain) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 454, 35, 285)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPosA, CAM_DEFAULT, 250, 40)
    Call(SetCamPosB, CAM_DEFAULT, 566, -50)
    Call(SetCamPitch, CAM_DEFAULT, Float(13.6), Float(-1.5))
    Call(SetPanTarget, CAM_DEFAULT, 429, 35, 278)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Return
    End
};

EvtScript N(EVS_Camera_LookBelow) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.4), Float(-5.5))
    Call(SetPanTarget, CAM_DEFAULT, 429, -153, 278)
    Return
    End
};

EvtScript N(EVS_Camera_Reset) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 430, 35, 295)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Return
    End
};

EvtScript N(EVS_TexPan_UpperSand) = {
    Call(SetTexPanner, MODEL_o1350, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1351, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1352, TEX_PANNER_0)
    Set(LVar2, 0)
    Call(MakeLerp, 0, 500, 60, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        Add(LVar2, LVar0)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Label(20)
        Add(LVar2, 500)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, LVar2)
        Wait(1)
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_TexPan_LowerSand) = {
    Call(SetTexPanner, MODEL_o1341, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o1346, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1343, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1344, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1345, TEX_PANNER_3)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Set(LVar4, 0)
    Label(10)
        Add(LVar2, 0x1800)
        Add(LVar3, -500)
        Add(LVar4, -100)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar2)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar3)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar4)
        Wait(1)
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
            Goto(10)
        EndIf
    Set(LVar5, 0x1800)
    Set(LVar6, -500)
    Set(LVar7, -100)
    Loop(10)
        Add(LVar5, -512)
        Add(LVar6, 50)
        Add(LVar7, 10)
        Add(LVar2, LVar5)
        Add(LVar3, LVar6)
        Add(LVar4, LVar7)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar2)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar3)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar4)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_RescaleDrainingSand) = {
    Call(MakeLerp, 0, 100, 60, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        Call(ScaleModel, MODEL_o1351, Float(1.0), LVar0, Float(1.0))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_CollapseSandPile) = {
    Call(MakeLerp, 0, 50, 10, EASING_QUADRATIC_OUT)
    Label(10)
        Call(UpdateLerp)
        DivF(LVar0, 100)
        SetF(LVar2, 1)
        AddF(LVar2, LVar0)
        SetF(LVar3, 1)
        SubF(LVar3, LVar0)
        Call(ScaleModel, MODEL_o1346, LVar2, LVar3, LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_DrainUpperSand) = {
    Call(MakeLerp, 0, -100, 60, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        DivF(LVar0, 10)
        SetF(LVar2, 0)
        SubF(LVar2, LVar0)
        Call(TranslateGroup, MODEL_g206, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1952, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(MakeLerp, -100, -250, 30, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        DivF(LVar0, 10)
        SetF(LVar2, 0)
        SubF(LVar2, LVar0)
        Call(TranslateGroup, MODEL_g206, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1952, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_FillLowerSand) = {
    Call(MakeTransformGroup, MODEL_g210)
    Call(MakeLerp, -200, 0, 120, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        DivF(LVar0, 10)
        Call(TranslateGroup, MODEL_g210, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1346, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_LowerSandColumn) = {
    Call(MakeLerp, 0, -200, 10, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1341, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_Scene_DrainSand) = {
    Wait(5)
    Call(InterpPlayerYaw, 179, 0)
    Call(EnableModel, MODEL_o1343, true)
    Call(EnableModel, MODEL_o1344, true)
    Call(EnableModel, MODEL_o1345, true)
    Call(EnableModel, MODEL_o1354, true)
    Call(EnableModel, MODEL_o1355, true)
    Call(EnableModel, MODEL_o1356, true)
    Call(EnableModel, MODEL_o1341, true)
    Call(EnableModel, MODEL_o1346, true)
    Exec(N(EVS_Camera_LookAtDrain))
    Wait(30)
    Exec(N(EVS_TexPan_UpperSand))
    Exec(N(EVS_RescaleDrainingSand))
    Exec(N(EVS_DrainUpperSand))
    Call(PlaySound, SOUND_ISK_DRAINING_SAND)
    Wait(75)
    Exec(N(EVS_Camera_LookBelow))
    Wait(30)
    Exec(N(EVS_TexPan_LowerSand))
    Exec(N(EVS_FillLowerSand))
    Call(PlaySound, SOUND_ISK_DRAINING_SAND | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Wait(120)
    Exec(N(EVS_LowerSandColumn))
    Wait(5)
    Exec(N(EVS_CollapseSandPile))
    Call(PlaySound, SOUND_ISK_DRAINING_SAND | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Wait(10)
    Call(EnableModel, MODEL_o1347, false)
    Call(EnableModel, MODEL_o1348, false)
    Call(EnableModel, MODEL_o1349, false)
    Call(EnableModel, MODEL_o1350, false)
    Call(EnableModel, MODEL_o1351, false)
    Call(EnableModel, MODEL_o1352, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1350, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1351, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1352, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
    Call(SetZoneEnabled, ZONE_o2008, false)
    Call(SetZoneEnabled, ZONE_o2023, true)
    Wait(20)
    Exec(N(EVS_Camera_Reset))
    Wait(5)
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupSand) = {
    Set(AF_ISK03_SandSwitchActivated, false)
    Call(MakeTransformGroup, MODEL_g206)
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
        BindTrigger(Ref(N(EVS_Scene_DrainSand)), TRIGGER_AREA_FLAG_SET, AF_ISK03_SandSwitchActivated, 1, 0)
        Call(EnableModel, MODEL_o1343, false)
        Call(EnableModel, MODEL_o1344, false)
        Call(EnableModel, MODEL_o1345, false)
        Call(EnableModel, MODEL_o1354, false)
        Call(EnableModel, MODEL_o1355, false)
        Call(EnableModel, MODEL_o1356, false)
        Call(EnableModel, MODEL_o1341, false)
        Call(EnableModel, MODEL_o1346, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1343, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1344, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1345, COLLIDER_FLAGS_UPPER_MASK)
        Exec(N(EVS_TexPan_DrippingSand))
    Else
        Call(EnableModel, MODEL_o1347, false)
        Call(EnableModel, MODEL_o1348, false)
        Call(EnableModel, MODEL_o1349, false)
        Call(EnableModel, MODEL_o1350, false)
        Call(EnableModel, MODEL_o1351, false)
        Call(EnableModel, MODEL_o1352, false)
        Call(EnableModel, MODEL_o1341, false)
        Call(EnableModel, MODEL_o1346, false)
        Call(EnableModel, MODEL_o6000, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1350, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1351, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1352, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
    Else
        Call(EnableModel, MODEL_o6000, false)
    EndIf
    Return
    End
};
