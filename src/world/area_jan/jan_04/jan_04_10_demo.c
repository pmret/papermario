#include "jan_04.h"
#include "world/partners.h"

extern Evt* D_8024A290;

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_CALL(DemoJoystickXY, -40, 30)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -67, 50)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -67, 53)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -67, 60)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -67, 65)
    EVT_WAIT(48)
    EVT_CALL(DemoJoystickXY, -65, 66)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -63, 66)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -58, 68)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -53, 70)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -46, 72)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -41, 73)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -36, 74)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -34, 74)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -30, 75)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -27, 76)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -20, 77)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -14, 78)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -10, 79)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -4, 79)
    EVT_WAIT(2)
    EVT_CALL(DemoSetButtons, BUTTON_C_DOWN)
    EVT_WAIT(28)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(25)
    EVT_CALL(DemoJoystickXY, 4, 80)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 5, 80)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 7, 81)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 11, 81)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 16, 80)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 21, 79)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 31, 77)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 40, 75)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 50, 72)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 60, 70)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 69)
    EVT_WAIT(30)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("jan_04"), jan_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("jan_04"), jan_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(DemoInitState) = 0;

API_CALLABLE(N(SetupDemoScene)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EvtScript* rideScriptSrc;

    switch (N(DemoInitState)) {
        case 0:
            rideScriptSrc = partner_get_enter_map_script();
            if (rideScriptSrc != NULL) {
                Evt* newScript;

                N(DemoInitState)++;
                newScript = start_script(rideScriptSrc, EVT_PRIORITY_0, EVT_FLAG_RUN_IMMEDIATELY);
                newScript->varTable[1] = playerStatus->pos.x - 10.0f;
                newScript->varTable[2] = playerStatus->pos.y;
                newScript->varTable[3] = playerStatus->pos.z;
                newScript->varTable[12] = 1;
                D_8024A290 = newScript;
            }
            break;
        case 1:
        case 2:
            N(DemoInitState)++;
            break;
        case 3:
            wPartnerNpc->yaw = 270.0f;
            playerStatus->targetYaw = 270.0f;
            playerStatus->curYaw = 270.0f;
            playerStatus->spriteFacingAngle = 180.0f;
            D_8024A290->functionTemp[1] = 1;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_PlayDemoScene) = {
    EVT_CALL(N(SetupDemoScene))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
