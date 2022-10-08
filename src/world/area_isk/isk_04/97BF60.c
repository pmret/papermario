#include "isk_04.h"

#include "world/common/SwitchToPartner.inc.c"

#include "world/partners.h"
extern s32 D_80242288_97D8B8;

// duplicate of SetupDemoScene from trd_09
ApiStatus func_8024095C_97BF8C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_80242288_97D8B8) {
        case 0:
            D_80242288_97D8B8 = 1;
            return ApiStatus_BLOCK;
        case 1:
        case 2:
            D_80242288_97D8B8++;
            return ApiStatus_BLOCK;
        case 3:
            wPartnerNpc->pos.x = playerStatus->position.x - 30.0f;
            wPartnerNpc->pos.z = playerStatus->position.z + 30.0f;
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
