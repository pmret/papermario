#include "jan_04.h"
#include "world/partners.h"

extern Evt* D_8024A290;

EvtScript N(EVS_ProvideDemoInputs) = {
    Call(DemoJoystickXY, -40, 30)
    Wait(1)
    Call(DemoJoystickXY, -67, 50)
    Wait(1)
    Call(DemoJoystickXY, -67, 53)
    Wait(1)
    Call(DemoJoystickXY, -67, 60)
    Wait(1)
    Call(DemoJoystickXY, -67, 65)
    Wait(48)
    Call(DemoJoystickXY, -65, 66)
    Wait(1)
    Call(DemoJoystickXY, -63, 66)
    Wait(1)
    Call(DemoJoystickXY, -58, 68)
    Wait(1)
    Call(DemoJoystickXY, -53, 70)
    Wait(1)
    Call(DemoJoystickXY, -46, 72)
    Wait(1)
    Call(DemoJoystickXY, -41, 73)
    Wait(1)
    Call(DemoJoystickXY, -36, 74)
    Wait(1)
    Call(DemoJoystickXY, -34, 74)
    Wait(1)
    Call(DemoJoystickXY, -30, 75)
    Wait(1)
    Call(DemoJoystickXY, -27, 76)
    Wait(1)
    Call(DemoJoystickXY, -20, 77)
    Wait(1)
    Call(DemoJoystickXY, -14, 78)
    Wait(1)
    Call(DemoJoystickXY, -10, 79)
    Wait(1)
    Call(DemoJoystickXY, -4, 79)
    Wait(2)
    Call(DemoSetButtons, BUTTON_C_DOWN)
    Wait(28)
    Call(DemoSetButtons, 0)
    Wait(25)
    Call(DemoJoystickXY, 4, 80)
    Wait(2)
    Call(DemoJoystickXY, 5, 80)
    Wait(1)
    Call(DemoJoystickXY, 7, 81)
    Wait(1)
    Call(DemoJoystickXY, 11, 81)
    Wait(1)
    Call(DemoJoystickXY, 16, 80)
    Wait(1)
    Call(DemoJoystickXY, 21, 79)
    Wait(1)
    Call(DemoJoystickXY, 31, 77)
    Wait(1)
    Call(DemoJoystickXY, 40, 75)
    Wait(1)
    Call(DemoJoystickXY, 50, 72)
    Wait(1)
    Call(DemoJoystickXY, 60, 70)
    Wait(1)
    Call(DemoJoystickXY, 64, 69)
    Wait(30)
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("jan_04"), jan_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    Call(GotoMapSpecial, Ref("jan_04"), jan_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(100)
    Return
    End
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
    Call(N(SetupDemoScene))
    Set(GF_DemoSceneDone, FALSE)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
