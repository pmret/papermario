#include "isk_09.h"

EvtScript N(EVS_FlipStairsCCW) = {
    EVT_WAIT(20)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, LVar4, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, LVar5, EASING_COS_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCW) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, LVar3, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 90, 0, LVar5, EASING_COS_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCCW_BottomBlue) = {
    EVT_SET(LVar2, MODEL_g321)
    EVT_SET(LVar3, COLLIDER_o2031)
    EVT_SET(LVar4, COLLIDER_o2032)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCW_BottomBlue) = {
    EVT_SET(LVar2, MODEL_g321)
    EVT_SET(LVar3, COLLIDER_o2031)
    EVT_SET(LVar4, COLLIDER_o2032)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCCW_TopBlue) = {
    EVT_SET(LVar2, MODEL_g327)
    EVT_SET(LVar3, COLLIDER_o2034)
    EVT_SET(LVar4, COLLIDER_o2033)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCW_TopBlue) = {
    EVT_SET(LVar2, MODEL_g327)
    EVT_SET(LVar3, COLLIDER_o2034)
    EVT_SET(LVar4, COLLIDER_o2033)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCCW_BottomRed) = {
    EVT_SET(LVar2, MODEL_g328)
    EVT_SET(LVar3, COLLIDER_o2036)
    EVT_SET(LVar4, COLLIDER_o2035)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCW_BottomRed) = {
    EVT_SET(LVar2, MODEL_g328)
    EVT_SET(LVar3, COLLIDER_o2036)
    EVT_SET(LVar4, COLLIDER_o2035)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCCW_TopRed) = {
    EVT_SET(LVar2, MODEL_g329)
    EVT_SET(LVar3, COLLIDER_o2037)
    EVT_SET(LVar4, COLLIDER_o2038)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipStairsCW_TopRed) = {
    EVT_SET(LVar2, MODEL_g329)
    EVT_SET(LVar3, COLLIDER_o2037)
    EVT_SET(LVar4, COLLIDER_o2038)
    EVT_SET(LVar5, 30)
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlueStairs_FlipCCW) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -522, -310, -95)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -522, -377, -92)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW_BottomBlue))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -522, -222, -92)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW_TopBlue))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlueStairs_FlipCW) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -522, -310, -95)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -522, -377, -92)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW_BottomBlue))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -522, -222, -92)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW_TopBlue))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RedStairs_FlipCCW) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -408, -310, -347)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -408, -377, -347)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW_BottomRed))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -408, -222, -347)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCCW_TopRed))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RedStairs_FlipCW) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -408, -310, -347)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -408, -377, -347)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW_BottomRed))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -408, -222, -347)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FlipStairsCW_TopRed))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipBlueStairs) = {
    EVT_IF_EQ(MF_BlueStairsFlipped, FALSE)
        EVT_EXEC_WAIT(N(EVS_BlueStairs_FlipCCW))
        EVT_SET(MF_BlueStairsFlipped, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_BlueStairs_FlipCW))
        EVT_SET(MF_BlueStairsFlipped, FALSE)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(AF_ISK09_FlippingBlueStairs, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipRedStairs) = {
    EVT_IF_EQ(MF_RedStairsFlipped, FALSE)
        EVT_EXEC_WAIT(N(EVS_RedStairs_FlipCW))
        EVT_SET(MF_RedStairsFlipped, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_RedStairs_FlipCCW))
        EVT_SET(MF_RedStairsFlipped, FALSE)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(AF_ISK09_FlippingRedStairs, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStairs) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2033, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(RotateModel, MODEL_g328, 90, 0, 0, 1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(RotateModel, MODEL_g329, 90, 0, 0, 1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MF_BlueStairsFlipped, FALSE)
    EVT_SET(MF_RedStairsFlipped, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_FlipBlueStairs)), TRIGGER_AREA_FLAG_SET, AF_ISK09_FlippingBlueStairs, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_FlipRedStairs)), TRIGGER_AREA_FLAG_SET, AF_ISK09_FlippingRedStairs, 1, 0)
    EVT_RETURN
    EVT_END
};
