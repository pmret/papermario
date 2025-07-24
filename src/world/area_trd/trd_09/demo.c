#include "trd_09.h"
#include "world/partners.h"

EvtScript N(EVS_ProvideDemoInputs) = {
    Wait(5)
    Call(DemoJoystickXY, 78, 0)
    Wait(11)
    Call(DemoJoystickXY, 79, 1)
    Call(DemoSetButtons, BUTTON_A)
    Wait(7)
    Call(DemoSetButtons, 0)
    Wait(34)
    Call(DemoSetButtons, BUTTON_A)
    Wait(4)
    Call(DemoSetButtons, 0)
    Wait(9)
    Call(DemoJoystickXY, 78, 1)
    Wait(1)
    Call(DemoJoystickXY, 76, 6)
    Wait(1)
    Call(DemoJoystickXY, 71, 31)
    Wait(1)
    Call(DemoJoystickXY, 66, 51)
    Wait(1)
    Call(DemoJoystickXY, 63, 60)
    Wait(1)
    Call(DemoJoystickXY, 63, 61)
    Wait(7)
    Call(DemoJoystickXY, 64, 61)
    Wait(1)
    Call(DemoJoystickXY, 65, 59)
    Wait(1)
    Call(DemoJoystickXY, 65, 56)
    Wait(1)
    Call(DemoJoystickXY, 67, 45)
    Wait(1)
    Call(DemoJoystickXY, 71, 28)
    Wait(1)
    Call(DemoJoystickXY, 75, 14)
    Wait(1)
    Call(DemoJoystickXY, 77, 6)
    Wait(1)
    Call(DemoJoystickXY, 78, 2)
    Wait(13)
    Call(DemoJoystickXY, 78, 3)
    Call(DemoSetButtons, BUTTON_A)
    Wait(9)
    Call(DemoSetButtons, 0)
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("trd_09"), trd_09_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(123)
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
    Call(GotoMapSpecial, Ref("trd_09"), trd_09_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(113)
    Return
    End
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
    Call(N(SetupDemoScene))
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Set(GF_DemoSceneDone, false)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
