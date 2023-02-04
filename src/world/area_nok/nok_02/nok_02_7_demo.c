#include "nok_02.h"
#include "world/partners.h"

EvtScript N(D_80251B40_9E8B60) = {
    EVT_CALL(DemoJoystickXY, 6, 4)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 29, 20)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 34)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, 41)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, 44)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, 52)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 60)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 62, 65)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 62, 66)
    EVT_WAIT(3)
    EVT_CALL(DemoJoystickXY, 62, 67)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 61, 69)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 24, 79)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, 83)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 2, 84)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 2, 82)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 3, 43)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -1, 0)
    EVT_WAIT(3)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(8)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(75)
    EVT_CALL(DemoJoystickXY, 7, 2)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 39, 8)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, 10)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, 12)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, 19)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 72, 29)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, 42)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, 54)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 62)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 62, 66)
    EVT_WAIT(3)
    EVT_CALL(DemoJoystickXY, 59, 70)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 53, 72)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 52, 73)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 43, 75)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 35, 77)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 33, 77)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 34, 77)
    EVT_WAIT(3)
    EVT_CALL(DemoJoystickXY, 33, 77)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 18, 78)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 11, 79)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 4, 32)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -1, 1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(6)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(53)
    EVT_CALL(DemoJoystickXY, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 11, 1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 28, 5)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 57, 15)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, 26)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 69, 33)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 65, 51)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, 61)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 62, 66)
    EVT_WAIT(4)
    EVT_CALL(DemoJoystickXY, 61, 66)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 52, 68)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 38, 72)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 30, 74)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 27, 67)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(10)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_02"), nok_02_ENTRY_2, TRANSITION_2)
    EVT_WAIT(110)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802522F4_9E9314) = {
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_CALL(GetDemoState, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("nok_02"), nok_02_ENTRY_2, TRANSITION_3)
    EVT_WAIT(110)
    EVT_RETURN
    EVT_END
};

s32 N(D_802523B4_9E93D4) = {
0 
};

// SetupDemoScene
API_CALLABLE(N(func_802438D0_9DA8F0)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(D_802523B4_9E93D4)) {
        case 0:
            N(D_802523B4_9E93D4) = 1;
            break;
        case 1:
        case 2:
            N(D_802523B4_9E93D4)++;
            break;
        case 3:
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(playerStatus->position.x, playerStatus->position.z);
            func_800EF3D4(0);
            set_npc_yaw(wPartnerNpc, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->currentYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_802523B8) = {
    EVT_CALL(N(func_802438D0_9DA8F0))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(D_802522F4_9E9314))
    EVT_EXEC(N(D_80251B40_9E8B60))
    EVT_RETURN
    EVT_END
};
