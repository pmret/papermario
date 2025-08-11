#include "nok_02.h"
#include "world/partners.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    Call(DemoJoystickXY, 6, 4)
    Wait(1)
    Call(DemoJoystickXY, 29, 20)
    Wait(1)
    Call(DemoJoystickXY, 64, 34)
    Wait(1)
    Call(DemoJoystickXY, 68, 41)
    Wait(1)
    Call(DemoJoystickXY, 67, 44)
    Wait(1)
    Call(DemoJoystickXY, 65, 52)
    Wait(1)
    Call(DemoJoystickXY, 63, 60)
    Wait(1)
    Call(DemoJoystickXY, 62, 65)
    Wait(1)
    Call(DemoJoystickXY, 62, 66)
    Wait(3)
    Call(DemoJoystickXY, 62, 67)
    Wait(2)
    Call(DemoJoystickXY, 61, 69)
    Wait(1)
    Call(DemoJoystickXY, 24, 79)
    Wait(1)
    Call(DemoJoystickXY, 1, 83)
    Wait(1)
    Call(DemoJoystickXY, 2, 84)
    Wait(1)
    Call(DemoJoystickXY, 2, 82)
    Wait(1)
    Call(DemoJoystickXY, 3, 43)
    Wait(1)
    Call(DemoJoystickXY, -1, 0)
    Wait(3)
    Call(DemoSetButtons, BUTTON_A)
    Wait(8)
    Call(DemoSetButtons, 0)
    Wait(75)
    Call(DemoJoystickXY, 7, 2)
    Wait(1)
    Call(DemoJoystickXY, 39, 8)
    Wait(1)
    Call(DemoJoystickXY, 74, 10)
    Wait(1)
    Call(DemoJoystickXY, 74, 12)
    Wait(1)
    Call(DemoJoystickXY, 74, 19)
    Wait(1)
    Call(DemoJoystickXY, 72, 29)
    Wait(1)
    Call(DemoJoystickXY, 68, 42)
    Wait(1)
    Call(DemoJoystickXY, 65, 54)
    Wait(1)
    Call(DemoJoystickXY, 63, 62)
    Wait(1)
    Call(DemoJoystickXY, 62, 66)
    Wait(3)
    Call(DemoJoystickXY, 59, 70)
    Wait(1)
    Call(DemoJoystickXY, 53, 72)
    Wait(1)
    Call(DemoJoystickXY, 52, 73)
    Wait(1)
    Call(DemoJoystickXY, 43, 75)
    Wait(1)
    Call(DemoJoystickXY, 35, 77)
    Wait(1)
    Call(DemoJoystickXY, 33, 77)
    Wait(1)
    Call(DemoJoystickXY, 34, 77)
    Wait(3)
    Call(DemoJoystickXY, 33, 77)
    Wait(1)
    Call(DemoJoystickXY, 18, 78)
    Wait(1)
    Call(DemoJoystickXY, 11, 79)
    Wait(1)
    Call(DemoJoystickXY, 4, 32)
    Wait(1)
    Call(DemoJoystickXY, -1, 1)
    Wait(1)
    Call(DemoJoystickXY, -1, 0)
    Wait(1)
    Call(DemoSetButtons, BUTTON_A)
    Wait(6)
    Call(DemoSetButtons, 0)
    Wait(53)
    Call(DemoJoystickXY, 2, 0)
    Wait(1)
    Call(DemoJoystickXY, 11, 1)
    Wait(1)
    Call(DemoJoystickXY, 28, 5)
    Wait(1)
    Call(DemoJoystickXY, 57, 15)
    Wait(1)
    Call(DemoJoystickXY, 68, 26)
    Wait(1)
    Call(DemoJoystickXY, 69, 33)
    Wait(1)
    Call(DemoJoystickXY, 65, 51)
    Wait(1)
    Call(DemoJoystickXY, 63, 61)
    Wait(1)
    Call(DemoJoystickXY, 62, 66)
    Wait(4)
    Call(DemoJoystickXY, 61, 66)
    Wait(1)
    Call(DemoJoystickXY, 52, 68)
    Wait(1)
    Call(DemoJoystickXY, 38, 72)
    Wait(1)
    Call(DemoJoystickXY, 30, 74)
    Wait(2)
    Call(DemoJoystickXY, 27, 67)
    Wait(1)
    Call(DemoJoystickXY, 0, 0)
    Wait(10)
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("nok_02"), nok_02_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("nok_02"), nok_02_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(110)
    Return
    End
};

s32 N(DemoInitState) = 0;

API_CALLABLE(N(SetupDemoScene)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(DemoInitState)) {
        case 0:
            N(DemoInitState) = 1;
            break;
        case 1:
        case 2:
            N(DemoInitState)++;
            break;
        case 3:
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(playerStatus->pos.x, playerStatus->pos.z);
            func_800EF3D4(0);
            set_npc_yaw(wPartnerNpc, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->curYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_SetupDemo) = {
    Call(N(SetupDemoScene))
    Set(GF_DemoSceneDone, false)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
