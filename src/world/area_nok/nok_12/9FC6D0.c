#include "nok_12.h"

extern s32 D_802459CC_A001BC;
extern s32 D_80245A14_A00204;
extern Npc* wPartnerNpc;

// SetupDemoScene
ApiStatus func_80241EE0_9FC6D0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_802459CC_A001BC) {
        case 0:
            D_802459CC_A001BC = 1;
            break;
        case 1:
        case 2:
            D_802459CC_A001BC++;
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

// SetupDemoScene
ApiStatus func_80241FD0_9FC7C0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_80245A14_A00204) {
        case 0:
            D_80245A14_A00204 = 1;
            break;
        case 1:
        case 2:
            D_80245A14_A00204++;
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
