#include "isk_06.h"

EvtScript N(EVS_TexPan_DrippingSand) = {
    EVT_CALL(SetTexPanner, MODEL_o2057, TEX_PANNER_4)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(10)
        EVT_ADD(LVar1, -1000)
        EVT_ADD(LVar2, 200)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(EnableModel, MODEL_o2057, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_LookAtDrain) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 356, -95, -373)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 364)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -623, 192)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 566, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.6), EVT_FLOAT(-1.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 356, -95, -373)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_LookBelow) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.4), EVT_FLOAT(-5.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 356, -285, -373)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_Reset) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 356, -95, -373)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_UpperSand) = {
    EVT_CALL(SetTexPanner, MODEL_o1689, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1690, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1691, TEX_PANNER_0)
    EVT_SET(LVar2, 0)
    EVT_CALL(MakeLerp, 0, 500, 60, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar2, LVar0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(20)
        EVT_ADD(LVar2, 500)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LowerSand) = {
    EVT_CALL(SetTexPanner, MODEL_o1682, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o1681, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o1675, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o1676, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o1677, TEX_PANNER_3)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_LABEL(10)
    EVT_ADD(LVar2, 0x1800)
    EVT_ADD(LVar3, -500)
    EVT_ADD(LVar4, -100)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar3)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar4)
    EVT_WAIT(1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVar5, 0x00001800)
    EVT_SET(LVar6, -500)
    EVT_SET(LVar7, -100)
    EVT_LOOP(10)
        EVT_ADD(LVar5, -512)
        EVT_ADD(LVar6, 50)
        EVT_ADD(LVar7, 10)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_ADD(LVar4, LVar7)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar2)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar3)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RescaleDrainingSand) = {
    EVT_CALL(MakeLerp, 0, 100, 60, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(ScaleModel, MODEL_o1690, EVT_FLOAT(1.0), LVar0, EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CollapseSandPile) = {
    EVT_CALL(MakeLerp, 0, 50, 10, EASING_QUADRATIC_OUT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, 100)
        EVT_SETF(LVar2, 1)
        EVT_ADDF(LVar2, LVar0)
        EVT_SETF(LVar3, 1)
        EVT_SUBF(LVar3, LVar0)
        EVT_CALL(ScaleModel, MODEL_o1681, LVar2, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DrainUpperSand) = {
    EVT_CALL(MakeLerp, 0, -100, 60, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, 10)
        EVT_SETF(LVar2, 0)
        EVT_SUBF(LVar2, LVar0)
        EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o1959, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o1960, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o1961, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(MakeLerp, -100, -250, 30, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, 10)
        EVT_SETF(LVar2, 0)
        EVT_SUBF(LVar2, LVar0)
        EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o1959, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o1960, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o1961, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FillLowerSand) = {
    EVT_CALL(MakeTransformGroup, MODEL_g277)
    EVT_CALL(MakeLerp, -200, 0, 120, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, 10)
        EVT_CALL(TranslateGroup, MODEL_g277, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o1681, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerSandColumn) = {
    EVT_CALL(MakeLerp, 0, -200, 10, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1682, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_DrainSand) = {
    EVT_WAIT(5)
    EVT_CALL(InterpPlayerYaw, 98, 0)
    EVT_CALL(EnableModel, MODEL_o1675, TRUE)
    EVT_CALL(EnableModel, MODEL_o1676, TRUE)
    EVT_CALL(EnableModel, MODEL_o1677, TRUE)
    EVT_CALL(EnableModel, MODEL_o1678, TRUE)
    EVT_CALL(EnableModel, MODEL_o1679, TRUE)
    EVT_CALL(EnableModel, MODEL_o1680, TRUE)
    EVT_CALL(EnableModel, MODEL_o1681, TRUE)
    EVT_CALL(EnableModel, MODEL_o1682, TRUE)
    EVT_EXEC(N(EVS_Camera_LookAtDrain))
    EVT_WAIT(30)
    EVT_EXEC(N(EVS_TexPan_UpperSand))
    EVT_EXEC(N(EVS_RescaleDrainingSand))
    EVT_EXEC(N(EVS_DrainUpperSand))
    EVT_CALL(PlaySound, SOUND_ISK_DRAINING_SAND)
    EVT_WAIT(75)
    EVT_EXEC(N(EVS_Camera_LookBelow))
    EVT_WAIT(30)
    EVT_EXEC(N(EVS_TexPan_LowerSand))
    EVT_EXEC(N(EVS_FillLowerSand))
    EVT_CALL(PlaySound, SOUND_ISK_DRAINING_SAND | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_WAIT(120)
    EVT_EXEC(N(EVS_LowerSandColumn))
    EVT_WAIT(5)
    EVT_EXEC(N(EVS_CollapseSandPile))
    EVT_CALL(PlaySound, SOUND_ISK_DRAINING_SAND | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o1686, FALSE)
    EVT_CALL(EnableModel, MODEL_o1687, FALSE)
    EVT_CALL(EnableModel, MODEL_o1688, FALSE)
    EVT_CALL(EnableModel, MODEL_o1689, FALSE)
    EVT_CALL(EnableModel, MODEL_o1690, FALSE)
    EVT_CALL(EnableModel, MODEL_o1691, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1689, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1690, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1691, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1675, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1676, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1677, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o2047, TRUE)
    EVT_CALL(EnableModel, MODEL_o2048, TRUE)
    EVT_CALL(EnableModel, MODEL_o2049, TRUE)
    EVT_CALL(EnableModel, MODEL_o2050, TRUE)
    EVT_CALL(EnableModel, MODEL_o2051, TRUE)
    EVT_CALL(EnableModel, MODEL_o2052, FALSE)
    EVT_CALL(EnableModel, MODEL_o2053, FALSE)
    EVT_CALL(EnableModel, MODEL_o2054, FALSE)
    EVT_CALL(EnableModel, MODEL_o2055, FALSE)
    EVT_CALL(EnableModel, MODEL_o2056, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2077, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2078, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
    EVT_CALL(SetZoneEnabled, ZONE_o2012, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_o2016, TRUE)
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_Camera_Reset))
    EVT_WAIT(5)
    EVT_CALL(EnableModel, MODEL_o1681, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSand) = {
    EVT_SET(AF_ISK06_SandSwitchActivated, FALSE)
    EVT_CALL(MakeTransformGroup, MODEL_g279)
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_DrainSand)), TRIGGER_AREA_FLAG_SET, AF_ISK06_SandSwitchActivated, 1, 0)
        EVT_CALL(EnableModel, MODEL_o1675, FALSE)
        EVT_CALL(EnableModel, MODEL_o1676, FALSE)
        EVT_CALL(EnableModel, MODEL_o1677, FALSE)
        EVT_CALL(EnableModel, MODEL_o1678, FALSE)
        EVT_CALL(EnableModel, MODEL_o1679, FALSE)
        EVT_CALL(EnableModel, MODEL_o1680, FALSE)
        EVT_CALL(EnableModel, MODEL_o1681, FALSE)
        EVT_CALL(EnableModel, MODEL_o1682, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1675, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1676, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1677, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o2047, FALSE)
        EVT_CALL(EnableModel, MODEL_o2048, FALSE)
        EVT_CALL(EnableModel, MODEL_o2049, FALSE)
        EVT_CALL(EnableModel, MODEL_o2050, FALSE)
        EVT_CALL(EnableModel, MODEL_o2051, FALSE)
        EVT_EXEC(N(EVS_TexPan_DrippingSand))
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o1686, FALSE)
        EVT_CALL(EnableModel, MODEL_o1687, FALSE)
        EVT_CALL(EnableModel, MODEL_o1688, FALSE)
        EVT_CALL(EnableModel, MODEL_o1689, FALSE)
        EVT_CALL(EnableModel, MODEL_o1690, FALSE)
        EVT_CALL(EnableModel, MODEL_o1691, FALSE)
        EVT_CALL(EnableModel, MODEL_o1681, FALSE)
        EVT_CALL(EnableModel, MODEL_o1682, FALSE)
        EVT_CALL(EnableModel, MODEL_o2052, FALSE)
        EVT_CALL(EnableModel, MODEL_o2053, FALSE)
        EVT_CALL(EnableModel, MODEL_o2054, FALSE)
        EVT_CALL(EnableModel, MODEL_o2055, FALSE)
        EVT_CALL(EnableModel, MODEL_o2056, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2077, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2078, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o2057, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1689, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1690, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1691, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_SECOND_SAND_ROOM)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o2057, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
