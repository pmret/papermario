#include "mac_00.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    Wait(50)
    Call(DemoJoystickXY, 22, -26)
    Wait(1)
    Call(DemoJoystickXY, 65, -61)
    Wait(1)
    Call(DemoJoystickXY, 66, -67)
    Wait(1)
    Call(DemoJoystickXY, 66, -70)
    Wait(30)
    Call(DemoJoystickXY, 66, -71)
    Wait(18)
    Call(DemoJoystickXY, 67, -62)
    Wait(1)
    Call(DemoJoystickXY, 74, -34)
    Wait(1)
    Call(DemoJoystickXY, 81, -6)
    Call(DemoSetButtons, BUTTON_A)
    Wait(1)
    Call(DemoJoystickXY, 82, -2)
    Wait(3)
    Call(DemoSetButtons, 0)
    Wait(7)
    Call(DemoJoystickXY, 81, -3)
    Wait(1)
    Call(DemoJoystickXY, 80, -10)
    Wait(1)
    Call(DemoJoystickXY, 78, -22)
    Wait(1)
    Call(DemoJoystickXY, 75, -35)
    Wait(1)
    Call(DemoJoystickXY, 72, -49)
    Call(DemoSetButtons, BUTTON_A)
    Wait(1)
    Call(DemoJoystickXY, 70, -56)
    Wait(1)
    Call(DemoJoystickXY, 70, -57)
    Wait(2)
    Call(DemoSetButtons, 0)
    Wait(9)
    Call(DemoJoystickXY, 70, -56)
    Wait(1)
    Call(DemoJoystickXY, 74, -26)
    Wait(1)
    Call(DemoJoystickXY, 79, 8)
    Wait(1)
    Call(DemoJoystickXY, 70, 46)
    Wait(1)
    Call(DemoJoystickXY, 66, 68)
    Wait(1)
    Call(DemoJoystickXY, 66, 67)
    Wait(2)
    Call(DemoJoystickXY, 65, 67)
    Wait(1)
    Call(DemoJoystickXY, 63, 66)
    Wait(1)
    Call(DemoJoystickXY, 45, 46)
    Wait(1)
    Call(DemoJoystickXY, 22, 23)
    Wait(1)
    Call(DemoJoystickXY, 1, -1)
    Wait(2)
    Call(DemoSetButtons, BUTTON_A)
    Wait(4)
    Call(DemoSetButtons, 0)
    Wait(61)
    Call(DemoJoystickXY, 3, -1)
    Wait(1)
    Call(DemoJoystickXY, 14, -1)
    Wait(1)
    Call(DemoJoystickXY, 74, -8)
    Wait(1)
    Call(DemoJoystickXY, 77, -9)
    Wait(1)
    Call(DemoJoystickXY, 78, -9)
    Wait(11)
    Call(DemoJoystickXY, 78, -8)
    Wait(1)
    Call(DemoJoystickXY, 79, -7)
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("mac_00"), mac_00_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    Call(GotoMapSpecial, Ref("mac_00"), mac_00_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetupDemo) = {
    Set(GF_DemoSceneDone, FALSE)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
