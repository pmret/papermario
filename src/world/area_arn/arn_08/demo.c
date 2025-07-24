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
    Call(N(InitializeDemoEquipment))
    Call(DemoJoystickXY, 2, 0)
    Wait(1)
    Call(DemoJoystickXY, 12, 4)
    Wait(1)
    Call(DemoJoystickXY, 28, 11)
    Wait(1)
    Call(DemoJoystickXY, 47, 22)
    Wait(1)
    Call(DemoJoystickXY, 68, 38)
    Wait(1)
    Call(DemoJoystickXY, 67, 48)
    Wait(1)
    Call(DemoJoystickXY, 64, 59)
    Wait(1)
    Call(DemoJoystickXY, 64, 62)
    Wait(4)
    Call(DemoSetButtons, BUTTON_A)
    Wait(10)
    Call(DemoJoystickXY, 64, 58)
    Call(DemoSetButtons, 0)
    Wait(1)
    Call(DemoJoystickXY, 70, 34)
    Wait(1)
    Call(DemoJoystickXY, 77, -2)
    Wait(1)
    Call(DemoJoystickXY, 74, -23)
    Wait(1)
    Call(DemoJoystickXY, 71, -36)
    Wait(1)
    Call(DemoJoystickXY, 69, -44)
    Wait(1)
    Call(DemoJoystickXY, 67, -49)
    Wait(1)
    Call(DemoJoystickXY, 30, -30)
    Wait(1)
    Call(DemoJoystickXY, 0, 0)
    Wait(1)
    Call(DemoJoystickXY, 0, -1)
    Wait(8)
    Call(DemoSetButtons, BUTTON_A)
    Wait(2)
    Call(DemoJoystickXY, 0, -2)
    Wait(2)
    Call(DemoJoystickXY, 0, -1)
    Wait(2)
    Call(DemoJoystickXY, 0, 0)
    Wait(1)
    Call(DemoSetButtons, 0)
    Wait(1)
    Call(DemoJoystickXY, 1, 0)
    Wait(1)
    Call(DemoJoystickXY, 0, 0)
    Call(N(SetPartnerFollowDist))
    Call(DemoSetButtons, BUTTON_A)
    Wait(12)
    Call(DemoSetButtons, 0)
    Wait(20)
    IfEq(GF_DemoSceneDone, true)
        Return
    EndIf
    Set(GF_DemoSceneDone, true)
    Call(GotoMapSpecial, Ref("arn_08"), arn_08_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(100)
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
    Call(GotoMapSpecial, Ref("arn_08"), arn_08_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(35)
    Return
    End
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
    Call(N(func_802400F4_BF4894))
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
    Call(SetCamProperties, CAM_DEFAULT, Float(90.0), 0, 0, 0, Float(470.0), Float(17.0), Float(-7.0))
    Call(N(SetupDemoScene))
    Set(GF_DemoSceneDone, false)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_ProvideDemoInputs))
    Return
    End
};
