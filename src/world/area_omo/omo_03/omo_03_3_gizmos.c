
#include "omo_03.h"
#include "effects.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Shutters) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Clocks) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_PullBlueSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 70, 30, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_bou1, LVar0, 0, 0, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_bou1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_OMO_TRAIN_TRACK_LEVER, SOUND_SPACE_DEFAULT, -440, 10, 40)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o978, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -184, 10, -229)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -184, 10, -229)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(517.4))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-180.0), EVT_FLOAT(-322.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAt, SOUND_OMO_FLIP_TRAIN_TRACK, SOUND_SPACE_DEFAULT, -130, 0, -215)
    EVT_CALL(MakeLerp, 0, 180, 30, EASING_COS_IN_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o933, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o818, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o817, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_OMO_FLIP_TRACK_THUD, SOUND_SPACE_DEFAULT, -130, 0, -215)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_CALL(GetModelCenter, MODEL_o932)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0)
    EVT_WAIT(30)
    EVT_SET(GF_OMO03_BlueSwitchActivated, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_EXEC(N(EVS_Gizmos_Clocks))
    EVT_CALL(ParentColliderToModel, COLLIDER_bou1, MODEL_bou1)
    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_PullBlueSwitch)), TRIGGER_WALL_PRESS_A, COLLIDER_o801, 1, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o978, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(RotateModel, MODEL_bou1, 70, 0, 0, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_bou1)
        EVT_CALL(RotateModel, MODEL_o933, 180, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o818, 180, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o817, 180, 1, 0, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
