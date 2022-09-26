#include "kzn_02.h"
#include "world/partners.h"

static char* N(exit_str_0) = "kzn_02";

extern s32 D_802464A4_C60BE4;

ApiStatus func_80242730_C5CE70(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_802464A4_C60BE4) {
        case 0:
            D_802464A4_C60BE4 = 1;
            break;
        case 1:
        case 2:
            D_802464A4_C60BE4++;
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
