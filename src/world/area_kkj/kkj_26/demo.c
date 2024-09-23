#include "kkj_26.h"
#include "sprite/player.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    Call(EnableWorldStatusBar, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 550, 30, -20)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.5), Float(-10.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(570.0), 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(60)
    Call(DemoJoystickXY, 10, 0)
    Wait(40)
    Call(DemoJoystickXY, 0, 0)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Wait(20)
    Call(ResetCam, CAM_DEFAULT, Float(1.0))
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("kkj_26"), kkj_26_ENTRY_2, TRANSITION_SLOW_FADE_TO_WHITE)
    Wait(110)
    Return
    End
};

EvtScript N(EVS_MonitorDemoState) = {
    Wait(10)
    Loop(0)
        Call(GetDemoState, LVar0)
        IfEq(LVar0, DEMO_STATE_CHANGE_MAP)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("kkj_26"), kkj_26_ENTRY_2, TRANSITION_SLOW_FADE_TO_WHITE)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_PlayDemoScene) = {
    Call(RotateModel, MODEL_o85, 80, 0, -1, 0)
    Call(RotateModel, MODEL_o83, 80, 0, 1, 0)
    Call(RotateModel, MODEL_o86, 80, 0, -1, 0)
    Call(RotateModel, MODEL_o84, 80, 0, 1, 0)
    Set(GF_DemoSceneDone, FALSE)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
