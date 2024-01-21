#include "isk_06.h"

EvtScript N(EVS_TexPan_DrippingSand) = {
    Call(SetTexPanner, MODEL_o2057, TEX_PANNER_4)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Label(10)
        Add(LVar1, -1000)
        Add(LVar2, 200)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar2, 0)
        Wait(1)
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
            Goto(10)
        EndIf
    Call(EnableModel, MODEL_o2057, FALSE)
    Return
    End
};

EvtScript N(EVS_Camera_LookAtDrain) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 356, -95, -373)
    Call(SetCamDistance, CAM_DEFAULT, 364)
    Call(SetCamPosA, CAM_DEFAULT, -623, 192)
    Call(SetCamPosB, CAM_DEFAULT, 566, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(13.6), Float(-1.5))
    Call(SetPanTarget, CAM_DEFAULT, 356, -95, -373)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_Camera_LookBelow) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.4), Float(-5.5))
    Call(SetPanTarget, CAM_DEFAULT, 356, -285, -373)
    Return
    End
};

EvtScript N(EVS_Camera_Reset) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 356, -95, -373)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_UpperSand) = {
    Call(SetTexPanner, MODEL_o1689, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1690, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1691, TEX_PANNER_0)
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
        IfLt(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
            Goto(20)
        EndIf
        Return
    End
};

EvtScript N(EVS_TexPan_LowerSand) = {
    Call(SetTexPanner, MODEL_o1682, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o1681, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1675, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1676, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1677, TEX_PANNER_3)
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
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
        Goto(10)
    EndIf
    Set(LVar5, 0x00001800)
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
        Call(ScaleModel, MODEL_o1690, Float(1.0), LVar0, Float(1.0))
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
        Call(ScaleModel, MODEL_o1681, LVar2, LVar3, LVar2)
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
        Call(TranslateGroup, MODEL_g279, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1959, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o1960, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o1961, 0, LVar2, 0)
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
        Call(TranslateGroup, MODEL_g279, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1959, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o1960, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o1961, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_FillLowerSand) = {
    Call(MakeTransformGroup, MODEL_g277)
    Call(MakeLerp, -200, 0, 120, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        DivF(LVar0, 10)
        Call(TranslateGroup, MODEL_g277, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o1681, 0, LVar0, 0)
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
        Call(TranslateModel, MODEL_o1682, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_Scene_DrainSand) = {
    Wait(5)
    Call(InterpPlayerYaw, 98, 0)
    Call(EnableModel, MODEL_o1675, TRUE)
    Call(EnableModel, MODEL_o1676, TRUE)
    Call(EnableModel, MODEL_o1677, TRUE)
    Call(EnableModel, MODEL_o1678, TRUE)
    Call(EnableModel, MODEL_o1679, TRUE)
    Call(EnableModel, MODEL_o1680, TRUE)
    Call(EnableModel, MODEL_o1681, TRUE)
    Call(EnableModel, MODEL_o1682, TRUE)
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
    Call(EnableModel, MODEL_o1686, FALSE)
    Call(EnableModel, MODEL_o1687, FALSE)
    Call(EnableModel, MODEL_o1688, FALSE)
    Call(EnableModel, MODEL_o1689, FALSE)
    Call(EnableModel, MODEL_o1690, FALSE)
    Call(EnableModel, MODEL_o1691, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1689, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1690, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1691, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1675, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1676, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1677, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o2047, TRUE)
    Call(EnableModel, MODEL_o2048, TRUE)
    Call(EnableModel, MODEL_o2049, TRUE)
    Call(EnableModel, MODEL_o2050, TRUE)
    Call(EnableModel, MODEL_o2051, TRUE)
    Call(EnableModel, MODEL_o2052, FALSE)
    Call(EnableModel, MODEL_o2053, FALSE)
    Call(EnableModel, MODEL_o2054, FALSE)
    Call(EnableModel, MODEL_o2055, FALSE)
    Call(EnableModel, MODEL_o2056, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2077, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2078, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
    Call(SetZoneEnabled, ZONE_o2012, FALSE)
    Call(SetZoneEnabled, ZONE_o2016, TRUE)
    Wait(20)
    Exec(N(EVS_Camera_Reset))
    Wait(5)
    Call(EnableModel, MODEL_o1681, FALSE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupSand) = {
    Set(AF_ISK06_SandSwitchActivated, FALSE)
    Call(MakeTransformGroup, MODEL_g279)
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
        BindTrigger(Ref(N(EVS_Scene_DrainSand)), TRIGGER_AREA_FLAG_SET, AF_ISK06_SandSwitchActivated, 1, 0)
        Call(EnableModel, MODEL_o1675, FALSE)
        Call(EnableModel, MODEL_o1676, FALSE)
        Call(EnableModel, MODEL_o1677, FALSE)
        Call(EnableModel, MODEL_o1678, FALSE)
        Call(EnableModel, MODEL_o1679, FALSE)
        Call(EnableModel, MODEL_o1680, FALSE)
        Call(EnableModel, MODEL_o1681, FALSE)
        Call(EnableModel, MODEL_o1682, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1675, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1676, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1677, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o2047, FALSE)
        Call(EnableModel, MODEL_o2048, FALSE)
        Call(EnableModel, MODEL_o2049, FALSE)
        Call(EnableModel, MODEL_o2050, FALSE)
        Call(EnableModel, MODEL_o2051, FALSE)
        Exec(N(EVS_TexPan_DrippingSand))
    Else
        Call(EnableModel, MODEL_o1686, FALSE)
        Call(EnableModel, MODEL_o1687, FALSE)
        Call(EnableModel, MODEL_o1688, FALSE)
        Call(EnableModel, MODEL_o1689, FALSE)
        Call(EnableModel, MODEL_o1690, FALSE)
        Call(EnableModel, MODEL_o1691, FALSE)
        Call(EnableModel, MODEL_o1681, FALSE)
        Call(EnableModel, MODEL_o1682, FALSE)
        Call(EnableModel, MODEL_o2052, FALSE)
        Call(EnableModel, MODEL_o2053, FALSE)
        Call(EnableModel, MODEL_o2054, FALSE)
        Call(EnableModel, MODEL_o2055, FALSE)
        Call(EnableModel, MODEL_o2056, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2077, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2078, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o2057, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1689, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1690, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1691, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
    Else
        Call(EnableModel, MODEL_o2057, FALSE)
    EndIf
    Return
    End
};
