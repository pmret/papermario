#include "kzn_02.h"
#include "world/entrances.h"
#include "world/partners.h"

API_CALLABLE(func_80242730_C5CE70);

EvtScript N(D_80246280_C609C0) = {
    EVT_CALL(DemoJoystickXY, 87, 0)
    EVT_WAIT(17)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(5)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(7)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(26)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(6)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_CALL(DemoSetButtons, BUTTON_A)
    EVT_WAIT(5)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, "kzn_02", kzn_02_ENTRY_2, TRANSITION_2)
    EVT_WAIT(110)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802463E4_C60B24) = {
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
    EVT_CALL(GotoMapSpecial, "kzn_02", kzn_02_ENTRY_2, TRANSITION_3)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

s32 N(D_802464A4) = 0;

EvtScript N(EVS_802464A8) = {
    EVT_CALL(func_80242730_C5CE70)
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(D_802463E4_C60B24))
    EVT_EXEC(N(D_80246280_C609C0))
    EVT_RETURN
    EVT_END
};

ApiStatus func_80242730_C5CE70(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (N(D_802464A4)) {
        case 0:
            N(D_802464A4) = 1;
            break;
        case 1:
        case 2:
            N(D_802464A4)++;
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
