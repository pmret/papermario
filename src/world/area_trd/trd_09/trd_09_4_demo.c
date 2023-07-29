#include "trd_09.h"
#include "world/partners.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_WAIT(5)
    EVT_CALL(DemoJoystickXY, 78, 0)
    EVT_WAIT(11)
    EVT_CALL(DemoJoystickXY, 79, 1)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(7)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(34)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(4)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(9)
    EVT_CALL(DemoJoystickXY, 78, 1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 76, 6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 71, 31)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 66, 51)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 60)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 61)
    EVT_WAIT(7)
    EVT_CALL(DemoJoystickXY, 64, 61)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, 59)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, 56)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, 45)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 71, 28)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 75, 14)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 77, 6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 78, 2)
    EVT_WAIT(13)
    EVT_CALL(DemoJoystickXY, 78, 3)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(9)
    EVT_CALL(DemoSetButtons, 0)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("trd_09"), trd_09_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(123)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("trd_09"), trd_09_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(113)
    EVT_RETURN
    EVT_END
};

s32 N(DemoInitState) = 0;

// duplicate of SetupDemoScene from isk_04
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
            wPartnerNpc->pos.x = playerStatus->pos.x - 30.0f;
            wPartnerNpc->pos.z = playerStatus->pos.z + 30.0f;
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

EvtScript N(EVS_PlayDemoScene) = {
    EVT_CALL(N(SetupDemoScene))
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
