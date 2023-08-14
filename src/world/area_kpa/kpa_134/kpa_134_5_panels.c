#include "kpa_134.h"

s32 N(WallPanels)[] = {
    MODEL_o371, -230, 272, -100,
    MODEL_o372, -160, 272, -100,
    MODEL_o373, -103, 272, -100,
    MODEL_o374, -46, 272, -100,
    MODEL_o375, 10, 272, -100,
    MODEL_o376, 67, 272, -100,
    MODEL_o377, 135, 272, -100,
    MODEL_o382, 245, 272, -100,
    MODEL_o381, 318, 272, -100,
    MODEL_o380, 375, 272, -100,
    MODEL_o379, 432, 272, -100,
    MODEL_o378, 490, 272, -100,
    MODEL_o383, 547, 272, -100,
    MODEL_o384, 615, 272, -100,
    -1,
};

EvtScript N(EVS_FocusCam_Wall) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar6, LVar7, LVar8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.5), EVT_FLOAT(-8.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar6, LVar7, LVar8)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipWallPanel) = {
    EVT_CALL(MakeLerp, 0, 450, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar5, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVar5, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipWallPanels) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o383, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o384, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sikake, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_USE_BUF(EVT_PTR(N(WallPanels)))
    EVT_CALL(GetPlayerPos, LVar6, LVar7, LVar8)
    EVT_SET(LVar6, 615)
    EVT_EXEC(N(EVS_FocusCam_Wall))
    EVT_LOOP(0)
        EVT_BUF_READ4(LVar5, LVar6, LVar7, LVar8)
        EVT_IF_EQ(LVar5, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_KPA_FLIP_BRIDGE_PANEL, SOUND_SPACE_DEFAULT, LVar6, LVar7, LVar8)
        EVT_EXEC(N(EVS_FlipWallPanel))
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_WAIT(50)
    EVT_CALL(StopSound, SOUND_KPA_FLIP_BRIDGE_PANEL)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GF_KPA134_BlueSwitch, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};
