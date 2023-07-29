

#include "nok_12.h"
#include "world/partners.h"

EvtScript N(EVS_ProvideDemoInputs1) = {
    EVT_CALL(DemoJoystickXY, 79, -7)
    EVT_WAIT(28)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(18)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(11)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(7)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(13)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(16)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(12)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(14)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(10)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorDemoState1) = {
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ProvideDemoInputs2) = {
    EVT_WAIT(13)
    EVT_CALL(DemoSetButtons, BUTTON_B)
    EVT_WAIT(3)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(160)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, -6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, -11)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 3, -18)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 7, -31)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 12, -42)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 16, -49)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 25, -56)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 36, -60)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 47, -61)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 52, -59)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 55, -52)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 56, -48)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 58, -44)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 61, -41)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 62, -40)
    EVT_WAIT(20)
    EVT_CALL(DemoJoystickXY, 63, -41)
    EVT_WAIT(5)
    EVT_CALL(DemoJoystickXY, 64, -41)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, -39)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, -39)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, -39)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, 0)
    EVT_WAIT(20)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorDemoState2) = {
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_12"), nok_12_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(216)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(N(SetupDemoScene1))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState1))
    EVT_EXEC(N(EVS_ProvideDemoInputs1))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(N(SetupDemoScene2))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState2))
    EVT_EXEC(N(EVS_ProvideDemoInputs2))
    EVT_RETURN
    EVT_END
};
