#include "isk_04.h"
#include "world/partners.h"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_ProvideDemoInputs) = {
    Call(EnableWorldStatusBar, FALSE)
    Call(DemoSetButtons, BUTTON_C_DOWN)
    Wait(5)
    Call(DemoSetButtons, 0)
    Wait(93)
    Call(DemoJoystickXY, 2, 0)
    Wait(1)
    Call(DemoJoystickXY, 15, 0)
    Wait(1)
    Call(DemoJoystickXY, 45, 19)
    Wait(1)
    Call(DemoJoystickXY, 75, 11)
    Wait(1)
    Call(DemoJoystickXY, 76, 11)
    Wait(8)
    Call(DemoJoystickXY, 69, 11)
    Wait(1)
    Call(DemoJoystickXY, -2, 21)
    Wait(1)
    Call(DemoJoystickXY, -1, -1)
    Call(N(SwitchToPartner), PARTNER_BOMBETTE)
    Wait(57)
    Call(DemoSetButtons, BUTTON_C_DOWN)
    Wait(4)
    Call(DemoSetButtons, 0)
    Wait(34)
    Call(DemoJoystickXY, -1, 0)
    Wait(1)
    Call(DemoJoystickXY, -4, 0)
    Wait(1)
    Call(DemoJoystickXY, -23, 3)
    Wait(1)
    Call(DemoJoystickXY, -48, 4)
    Wait(1)
    Call(DemoJoystickXY, -67, 6)
    Wait(1)
    Call(DemoJoystickXY, -76, 7)
    Wait(1)
    Call(DemoJoystickXY, -78, 7)
    Wait(4)
    Call(DemoJoystickXY, -36, 6)
    Wait(1)
    Call(DemoJoystickXY, 1, -1)
    Wait(1)
    Call(DemoJoystickXY, 47, -6)
    Wait(1)
    Call(DemoJoystickXY, 74, -12)
    Wait(1)
    Call(DemoJoystickXY, 63, -9)
    Wait(1)
    Call(DemoJoystickXY, -1, 0)
    Wait(70)
    Call(DemoJoystickXY, 0, 0)
    Wait(2)
    Call(DemoJoystickXY, 3, 0)
    Wait(1)
    Call(DemoJoystickXY, 17, 0)
    Wait(1)
    Call(DemoJoystickXY, 38, 0)
    Wait(1)
    Call(DemoJoystickXY, 64, -3)
    Wait(1)
    Call(DemoJoystickXY, 76, -6)
    Wait(8)
    Call(DemoJoystickXY, 77, -5)
    Wait(3)
    Call(DemoJoystickXY, 77, -4)
    Wait(1)
    Call(DemoJoystickXY, 77, -2)
    Wait(2)
    Call(DemoJoystickXY, 77, -1)
    Wait(1)
    Call(DemoJoystickXY, 78, -1)
    Wait(2)
    Call(DemoJoystickXY, 78, 0)
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("isk_04"), isk_04_ENTRY_5, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(323)
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
    Call(GotoMapSpecial, Ref("isk_04"), isk_04_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(313)
    Return
    End
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
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, 530, 25, -50)
    Call(SetCamPitch, CAM_DEFAULT, 12, -3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 25, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(1)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamPitch, CAM_DEFAULT, 12, -3)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, 25, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(N(SetupDemoScene))
    Set(GF_DemoSceneDone, FALSE)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
