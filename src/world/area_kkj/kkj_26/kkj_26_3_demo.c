#include "kkj_26.h"
#include "sprite/player.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_CALL(EnableWorldStatusBar, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 550, 30, -20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(570.0), 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60)
    EVT_CALL(DemoJoystickXY, 10, 0)
    EVT_WAIT(40)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_WAIT(20)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_26"), kkj_26_ENTRY_2, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(110)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorDemoState) = {
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_CALL(GetDemoState, LVar0)
        EVT_IF_EQ(LVar0, DEMO_STATE_CHANGE_MAP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_26"), kkj_26_ENTRY_2, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayDemoScene) = {
    EVT_CALL(RotateModel, MODEL_o85, 80, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o83, 80, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o86, 80, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o84, 80, 0, 1, 0)
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
