#include "isk_12.h"

EvtScript N(EVS_TexPan_DrippingSand) = {
    EVT_CALL(SetTexPanner, MODEL_o6000, TEX_PANNER_4)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(10)
        EVT_ADD(LVar1, -1000)
        EVT_ADD(LVar2, 200)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(EnableModel, MODEL_o6000, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_LookAtDrain) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 500, -485, 178)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 50, -202)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 566, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.6), EVT_FLOAT(-1.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 525, -485, 152)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_LookBelow) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.4), EVT_FLOAT(-3.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 525, -720, 152)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Camera_Reset) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 525, -485, 152)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_UpperSand) = {
    EVT_CALL(SetTexPanner, MODEL_o1706, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1707, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1708, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1939, TEX_PANNER_0)
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
        EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LowerSand) = {
    EVT_CALL(SetTexPanner, MODEL_o1699, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o1698, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o1692, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o1693, TEX_PANNER_3)
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
        EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(LVar5, 0x1800)
    EVT_SET(LVar6, -500)
    EVT_SET(LVar7, -100)
    EVT_LOOP(10)
        EVT_ADD(LVar5, -512)
        EVT_ADD(LVar6, 50)
        EVT_ADD(LVar7, 10)
        EVT_ADD(LVar2, LVar5)
        EVT_ADD(LVar3, LVar6)
        EVT_ADD(LVar4, LVar7)
        EVT_CALL(SetTexPanOffset, 1, 0, 0, LVar2)
        EVT_CALL(SetTexPanOffset, 2, 0, 0, LVar3)
        EVT_CALL(SetTexPanOffset, 3, 0, 0, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RescaleDrainingSand) = {
    EVT_CALL(MakeLerp, 0, 100, 60, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(ScaleModel, MODEL_o1707, EVT_FLOAT(1.0), LVar0, EVT_FLOAT(1.0))
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
        EVT_CALL(ScaleModel, MODEL_o1698, LVar2, LVar3, LVar2)
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
        EVT_CALL(TranslateGroup, MODEL_g285, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o2007, 0, LVar2, 0)
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
        EVT_CALL(TranslateGroup, MODEL_g285, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o2007, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FillLowerSand) = {
    EVT_CALL(MakeTransformGroup, MODEL_g283)
    EVT_CALL(MakeLerp, -200, 0, 120, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LVar0, 10)
    EVT_CALL(TranslateGroup, MODEL_g283, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o1698, 0, LVar0, 0)
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
    EVT_CALL(TranslateModel, MODEL_o1699, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_DrainSand) = {
    EVT_WAIT(5)
    EVT_CALL(EnableModel, MODEL_o1692, TRUE)
    EVT_CALL(EnableModel, MODEL_o1693, TRUE)
    EVT_CALL(EnableModel, MODEL_o1696, TRUE)
    EVT_CALL(EnableModel, MODEL_o1697, TRUE)
    EVT_CALL(EnableModel, MODEL_o1698, TRUE)
    EVT_CALL(EnableModel, MODEL_o1699, TRUE)
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
    EVT_CALL(EnableModel, MODEL_o1703, FALSE)
    EVT_CALL(EnableModel, MODEL_o1704, FALSE)
    EVT_CALL(EnableModel, MODEL_o1705, FALSE)
    EVT_CALL(EnableModel, MODEL_o1706, FALSE)
    EVT_CALL(EnableModel, MODEL_o1707, FALSE)
    EVT_CALL(EnableModel, MODEL_o1708, FALSE)
    EVT_CALL(EnableModel, MODEL_o1938, FALSE)
    EVT_CALL(EnableModel, MODEL_o1939, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2042, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2043, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2044, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2045, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
    EVT_CALL(SetZoneEnabled, ZONE_on, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_deiliw, TRUE)
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_Camera_Reset))
    EVT_WAIT(5)
    EVT_CALL(EnableModel, MODEL_o1698, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSand) = {
    EVT_SET(AF_ISK12_SandSwitchActivated, FALSE)
    EVT_CALL(MakeTransformGroup, MODEL_g285)
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_DrainSand)), TRIGGER_AREA_FLAG_SET, AF_ISK12_SandSwitchActivated, 1, 0)
        EVT_CALL(EnableModel, MODEL_o1692, FALSE)
        EVT_CALL(EnableModel, MODEL_o1693, FALSE)
        EVT_CALL(EnableModel, MODEL_o1696, FALSE)
        EVT_CALL(EnableModel, MODEL_o1697, FALSE)
        EVT_CALL(EnableModel, MODEL_o1698, FALSE)
        EVT_CALL(EnableModel, MODEL_o1699, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2044, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2045, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC(N(EVS_TexPan_DrippingSand))
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o1703, FALSE)
        EVT_CALL(EnableModel, MODEL_o1704, FALSE)
        EVT_CALL(EnableModel, MODEL_o1705, FALSE)
        EVT_CALL(EnableModel, MODEL_o1706, FALSE)
        EVT_CALL(EnableModel, MODEL_o1707, FALSE)
        EVT_CALL(EnableModel, MODEL_o1708, FALSE)
        EVT_CALL(EnableModel, MODEL_o1938, FALSE)
        EVT_CALL(EnableModel, MODEL_o1939, FALSE)
        EVT_CALL(EnableModel, MODEL_o1698, FALSE)
        EVT_CALL(EnableModel, MODEL_o1699, FALSE)
        EVT_CALL(EnableModel, MODEL_o6000, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2042, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2043, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
