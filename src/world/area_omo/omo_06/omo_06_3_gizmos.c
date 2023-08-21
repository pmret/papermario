#include "omo_06.h"
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
        EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_PullPinkSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 70, 30 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_bou1, LVar0, 0, 0, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_bou1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_OMO_TRAIN_TRACK_LEVER, SOUND_SPACE_DEFAULT, -395, 0, -185)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o930, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(20 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 223, 10, -165)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 223, 10, -165)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-500.0), EVT_FLOAT(-200.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAt, SOUND_OMO_FLIP_TRAIN_TRACK, SOUND_SPACE_DEFAULT, 265, 0, -235)
    EVT_CALL(MakeLerp, 0, 180, 30 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o898, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o899, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o897, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_OMO_FLIP_TRACK_THUD, SOUND_SPACE_DEFAULT, 265, 0, -235)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_CALL(GetModelCenter, MODEL_o897)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0)
    EVT_WAIT(30 * DT)
    EVT_SET(GB_StoryProgress, STORY_CH4_PULLED_SWITCH_SWITCH)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_CALL(ParentColliderToModel, COLLIDER_bou1, MODEL_bou1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_PULLED_SWITCH_SWITCH)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_PullPinkSwitch)), TRIGGER_WALL_PRESS_A, COLLIDER_o664, 1, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o930, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(RotateModel, MODEL_bou1, 70, 0, 0, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_bou1)
        EVT_CALL(RotateModel, MODEL_o898, 180, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o899, 180, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o897, 180, 1, 0, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
