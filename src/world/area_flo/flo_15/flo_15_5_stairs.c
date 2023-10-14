#include "flo_15.h"
#include "effects.h"

s32 N(ShakeCamParams)[] = {
    10, EVT_FLOAT(0.6),
    13, EVT_FLOAT(0.75),
    16, EVT_FLOAT(0.9),
    19, EVT_FLOAT(1.05),
    22, EVT_FLOAT(1.2),
    25, EVT_FLOAT(1.05),
    24, EVT_FLOAT(0.9),
    25, EVT_FLOAT(0.75),
    24, EVT_FLOAT(0.6),
    10, EVT_FLOAT(1.7),
};

EvtScript N(EVS_MonitorFallingStairs) = {
    EVT_IF_EQ(GF_FLO15_BombedRock, FALSE)
        EVT_LABEL(0)
        EVT_IF_EQ(GF_FLO15_BombedRock, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_USE_BUF(EVT_PTR(N(ShakeCamParams)))
            EVT_LOOP(10)
                EVT_BUF_READ2(LVar1, LVar2)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -170, 0, 35)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -170, 0, 35)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-9.0))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-50.0), EVT_FLOAT(25.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_WAIT(100)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -180, 0, -15, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -190, 0, -35, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(6)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_o175, SOUND_FLO_STAIRS_LOWERING, SOUND_SPACE_DEFAULT)
                EVT_WAIT(20)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, -50, 120, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g20, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g54, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
        EVT_WAIT(15)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g54, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(TranslateGroup, MODEL_g20, 0, -50, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
