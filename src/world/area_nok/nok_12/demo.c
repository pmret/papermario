

#include "nok_12.h"
#include "world/partners.h"

EvtScript N(EVS_ProvideDemoInputs1) = {
    Call(DemoJoystickXY, 79, -7)
    Wait(28)
    Call(DemoSetButtons, BUTTON_A)
    Wait(18)
    Call(DemoSetButtons, 0)
    Wait(11)
    Call(DemoSetButtons, BUTTON_A)
    Wait(7)
    Call(DemoSetButtons, 0)
    Wait(13)
    Call(DemoSetButtons, BUTTON_A)
    Wait(16)
    Call(DemoSetButtons, 0)
    Wait(12)
    Call(DemoSetButtons, BUTTON_A)
    Wait(14)
    Call(DemoSetButtons, 0)
    Wait(10)
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MonitorDemoState1) = {
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
    Call(GotoMapSpecial, Ref("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ProvideDemoInputs2) = {
    Wait(13)
    Call(DemoSetButtons, BUTTON_B)
    Wait(3)
    Call(DemoSetButtons, 0)
    Wait(160)
    Call(DemoJoystickXY, 0, 0)
    Wait(1)
    Call(DemoJoystickXY, 0, -6)
    Wait(1)
    Call(DemoJoystickXY, 1, -11)
    Wait(1)
    Call(DemoJoystickXY, 3, -18)
    Wait(1)
    Call(DemoJoystickXY, 7, -31)
    Wait(1)
    Call(DemoJoystickXY, 12, -42)
    Wait(1)
    Call(DemoJoystickXY, 16, -49)
    Wait(1)
    Call(DemoJoystickXY, 25, -56)
    Wait(1)
    Call(DemoJoystickXY, 36, -60)
    Wait(1)
    Call(DemoJoystickXY, 47, -61)
    Wait(1)
    Call(DemoJoystickXY, 52, -59)
    Wait(1)
    Call(DemoJoystickXY, 55, -52)
    Wait(1)
    Call(DemoJoystickXY, 56, -48)
    Wait(1)
    Call(DemoJoystickXY, 58, -44)
    Wait(1)
    Call(DemoJoystickXY, 61, -41)
    Wait(1)
    Call(DemoJoystickXY, 62, -40)
    Wait(20)
    Call(DemoJoystickXY, 63, -41)
    Wait(5)
    Call(DemoJoystickXY, 64, -41)
    Wait(1)
    Call(DemoJoystickXY, 67, -39)
    Wait(1)
    Call(DemoJoystickXY, 68, -39)
    Wait(1)
    Call(DemoJoystickXY, 68, -39)
    Wait(1)
    Call(DemoJoystickXY, 70, 0)
    Wait(20)
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MonitorDemoState2) = {
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
    Call(GotoMapSpecial, Ref("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(216)
    Return
    End
};

s32 N(DemoInitState1) = 0;

API_CALLABLE(N(SetupDemoScene1)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(DemoInitState1)) {
        case 0:
            N(DemoInitState1) = 1;
            break;
        case 1:
        case 2:
            N(DemoInitState1)++;
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

EvtScript N(EVS_PlayDemoScene1) = {
    Call(N(SetupDemoScene1))
    Set(GF_DemoSceneDone, false)
    Exec(N(EVS_MonitorDemoState1))
    Exec(N(EVS_ProvideDemoInputs1))
    Return
    End
};

s32 N(DemoInitState2) = 0;

API_CALLABLE(N(SetupDemoScene2)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(DemoInitState2)) {
        case 0:
            N(DemoInitState2) = 1;
            break;
        case 1:
        case 2:
            N(DemoInitState2)++;
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

EvtScript N(EVS_PlayDemoScene2) = {
    Call(N(SetupDemoScene2))
    Set(GF_DemoSceneDone, false)
    Exec(N(EVS_MonitorDemoState2))
    Exec(N(EVS_ProvideDemoInputs2))
    Return
    End
};
