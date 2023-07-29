#include "arn_08.h"
#include "world/partners.h"

API_CALLABLE(N(InitializeDemoEquipment)) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetPartnerFollowDist)) {
    func_800EF300();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_CALL(N(InitializeDemoEquipment))
    EVT_CALL(DemoJoystickXY, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 12, 4)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 28, 11)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 47, 22)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, 38)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, 48)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 59)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 62)
    EVT_WAIT(4)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(10)
    EVT_CALL(DemoJoystickXY, 64, 58)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, 34)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 77, -2)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -23)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 71, -36)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 69, -44)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, -49)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 30, -30)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, -1)
    EVT_WAIT(8)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, -2)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, -1)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_CALL(N(SetPartnerFollowDist))
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(12)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("arn_08"), arn_08_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(100)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("arn_08"), arn_08_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(35)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_802400F4_BF4894)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (!(playerStatus->pos.y > -10.0f)) {
        f32 temp_f20 = player_fall_distance();
        s32 colliderID;

        playerStatus->pos.y = player_check_collision_below(temp_f20, &colliderID);
        script->functionTemp[0] += fabsf(temp_f20);

        return (script->functionTemp[0] > 50) * ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_8024116C) = {
    EVT_CALL(N(func_802400F4_BF4894))
    EVT_RETURN
    EVT_END
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
        case 3: {
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(playerStatus->pos.x, playerStatus->pos.z);
            func_800EF3D4(0);
            set_npc_yaw(wPartnerNpc, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->curYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_PlayDemoScene) = {
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 0, 0, EVT_FLOAT(470.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(N(SetupDemoScene))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
