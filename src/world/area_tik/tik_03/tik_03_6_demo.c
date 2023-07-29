#include "tik_03.h"
#include "world/partners.h"

API_CALLABLE(N(ChangePartnerFollowState)) {
    func_800EF300();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_CALL(DemoJoystickXY, -85, -1)
    EVT_WAIT(32)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(7)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(30)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(15)
    EVT_CALL(N(ChangePartnerFollowState))
    EVT_WAIT(15)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("tik_03"), tik_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("tik_03"), tik_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(DemoInitState) = {
    0
};

API_CALLABLE(N(SetupDemoScene)) {
    PlayerStatus* player = &gPlayerStatus;

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
            partner_set_goal_pos(player->pos.x, player->pos.z);
            func_800EF3D4(0);
            wPartnerNpc->yaw = 270.0f;
            gPlayerStatus.targetYaw = 270.0f;
            gPlayerStatus.curYaw = 270.0f;
            gPlayerStatus.spriteFacingAngle = 180.0f;
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
