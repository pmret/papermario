#include "mac_00.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_WAIT(50)
    EVT_CALL(DemoJoystickXY, 22, -26)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, -61)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 66, -67)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 66, -70)
    EVT_WAIT(30)
    EVT_CALL(DemoJoystickXY, 66, -71)
    EVT_WAIT(18)
    EVT_CALL(DemoJoystickXY, 67, -62)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -34)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 81, -6)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 82, -2)
    EVT_WAIT(3)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(7)
    EVT_CALL(DemoJoystickXY, 81, -3)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 80, -10)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 78, -22)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 75, -35)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 72, -49)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, -56)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, -57)
    EVT_WAIT(2)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(9)
    EVT_CALL(DemoJoystickXY, 70, -56)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -26)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 79, 8)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, 46)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 66, 68)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 66, 67)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 65, 67)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 66)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 45, 46)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 22, 23)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, -1)
    EVT_WAIT(2)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(4)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(61)
    EVT_CALL(DemoJoystickXY, 3, -1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 14, -1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -8)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 77, -9)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 78, -9)
    EVT_WAIT(11)
    EVT_CALL(DemoJoystickXY, 78, -8)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 79, -7)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("mac_00"), mac_00_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("mac_00"), mac_00_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupDemo) = {
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
