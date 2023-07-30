#include "isk_04.h"
#include "world/partners.h"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_ProvideDemoInputs) = {
    EVT_CALL(EnableWorldStatusBar, FALSE)
    EVT_CALL(DemoSetButtons, BUTTON_C_DOWN)
    EVT_WAIT(5)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(93)
    EVT_CALL(DemoJoystickXY, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 15, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 45, 19)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 75, 11)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 76, 11)
    EVT_WAIT(8)
    EVT_CALL(DemoJoystickXY, 69, 11)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -2, 21)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -1, -1)
    EVT_CALL(N(SwitchToPartner), PARTNER_BOMBETTE)
    EVT_WAIT(57)
    EVT_CALL(DemoSetButtons, BUTTON_C_DOWN)
    EVT_WAIT(4)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(34)
    EVT_CALL(DemoJoystickXY, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -23, 3)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -48, 4)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -67, 6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -76, 7)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -78, 7)
    EVT_WAIT(4)
    EVT_CALL(DemoJoystickXY, -36, 6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, -1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 47, -6)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -12)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 63, -9)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, -1, 0)
    EVT_WAIT(70)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 17, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 38, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, -3)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 76, -6)
    EVT_WAIT(8)
    EVT_CALL(DemoJoystickXY, 77, -5)
    EVT_WAIT(3)
    EVT_CALL(DemoJoystickXY, 77, -4)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 77, -2)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 77, -1)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 78, -1)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 78, 0)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("isk_04"), isk_04_ENTRY_5, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(323)
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
    EVT_CALL(GotoMapSpecial, EVT_PTR("isk_04"), isk_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(313)
    EVT_RETURN
    EVT_END
};

s32 N(DemoInitState) = 0;

API_CALLABLE(N(SetupDemoScene)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(DemoInitState)) {
        case 0:
            N(DemoInitState) = 1;
            return ApiStatus_BLOCK;
        case 1:
        case 2:
            N(DemoInitState)++;
            return ApiStatus_BLOCK;
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


EvtScript N(EVS_SetupDemo) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 530, 25, -50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 12, -3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 25, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 12, -3)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 25, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(SetupDemoScene))
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_ProvideDemoInputs))
    EVT_RETURN
    EVT_END
};
