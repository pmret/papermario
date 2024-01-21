#include "isk_12.h"

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
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
            Goto(10)
        EndIf
    Call(EnableModel, MODEL_o6000, FALSE)
    Return
    End
};

EvtScript N(EVS_Camera_LookAtDrain) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 500, -485, 178)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPosA, CAM_DEFAULT, 50, -202)
    Call(SetCamPosB, CAM_DEFAULT, 566, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(13.6), Float(-1.5))
    Call(SetPanTarget, CAM_DEFAULT, 525, -485, 152)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_Camera_LookBelow) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.4), Float(-3.0))
    Call(SetPanTarget, CAM_DEFAULT, 525, -720, 152)
    Return
    End
};

EvtScript N(EVS_Camera_Reset) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 525, -485, 152)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_UpperSand) = {
    Call(SetTexPanner, MODEL_o1706, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1707, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1708, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1939, TEX_PANNER_0)
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
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_TexPan_LowerSand) = {
    Call(SetTexPanner, MODEL_o1699, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o1698, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1692, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1693, TEX_PANNER_3)
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
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
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
        Call(SetTexPanOffset, 1, 0, 0, LVar2)
        Call(SetTexPanOffset, 2, 0, 0, LVar3)
        Call(SetTexPanOffset, 3, 0, 0, LVar4)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_RescaleDrainingSand) = {
    Call(MakeLerp, 0, 100, 60, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        Call(ScaleModel, MODEL_o1707, Float(1.0), LVar0, Float(1.0))
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
        Call(ScaleModel, MODEL_o1698, LVar2, LVar3, LVar2)
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
        Call(TranslateGroup, MODEL_g285, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o2007, 0, LVar2, 0)
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
        Call(TranslateGroup, MODEL_g285, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o2007, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_FillLowerSand) = {
    Call(MakeTransformGroup, MODEL_g283)
    Call(MakeLerp, -200, 0, 120, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    DivF(LVar0, 10)
    Call(TranslateGroup, MODEL_g283, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o1698, 0, LVar0, 0)
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
    Call(TranslateModel, MODEL_o1699, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_DrainSand) = {
    Wait(5)
    Call(EnableModel, MODEL_o1692, TRUE)
    Call(EnableModel, MODEL_o1693, TRUE)
    Call(EnableModel, MODEL_o1696, TRUE)
    Call(EnableModel, MODEL_o1697, TRUE)
    Call(EnableModel, MODEL_o1698, TRUE)
    Call(EnableModel, MODEL_o1699, TRUE)
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
    Call(EnableModel, MODEL_o1703, FALSE)
    Call(EnableModel, MODEL_o1704, FALSE)
    Call(EnableModel, MODEL_o1705, FALSE)
    Call(EnableModel, MODEL_o1706, FALSE)
    Call(EnableModel, MODEL_o1707, FALSE)
    Call(EnableModel, MODEL_o1708, FALSE)
    Call(EnableModel, MODEL_o1938, FALSE)
    Call(EnableModel, MODEL_o1939, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2042, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2043, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2044, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2045, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
    Call(SetZoneEnabled, ZONE_on, FALSE)
    Call(SetZoneEnabled, ZONE_deiliw, TRUE)
    Wait(20)
    Exec(N(EVS_Camera_Reset))
    Wait(5)
    Call(EnableModel, MODEL_o1698, FALSE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupSand) = {
    Set(AF_ISK12_SandSwitchActivated, FALSE)
    Call(MakeTransformGroup, MODEL_g285)
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
        BindTrigger(Ref(N(EVS_Scene_DrainSand)), TRIGGER_AREA_FLAG_SET, AF_ISK12_SandSwitchActivated, 1, 0)
        Call(EnableModel, MODEL_o1692, FALSE)
        Call(EnableModel, MODEL_o1693, FALSE)
        Call(EnableModel, MODEL_o1696, FALSE)
        Call(EnableModel, MODEL_o1697, FALSE)
        Call(EnableModel, MODEL_o1698, FALSE)
        Call(EnableModel, MODEL_o1699, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2044, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2045, COLLIDER_FLAGS_UPPER_MASK)
        Exec(N(EVS_TexPan_DrippingSand))
    Else
        Call(EnableModel, MODEL_o1703, FALSE)
        Call(EnableModel, MODEL_o1704, FALSE)
        Call(EnableModel, MODEL_o1705, FALSE)
        Call(EnableModel, MODEL_o1706, FALSE)
        Call(EnableModel, MODEL_o1707, FALSE)
        Call(EnableModel, MODEL_o1708, FALSE)
        Call(EnableModel, MODEL_o1938, FALSE)
        Call(EnableModel, MODEL_o1939, FALSE)
        Call(EnableModel, MODEL_o1698, FALSE)
        Call(EnableModel, MODEL_o1699, FALSE)
        Call(EnableModel, MODEL_o6000, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2042, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2043, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
