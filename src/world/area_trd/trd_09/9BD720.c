#include "trd_09.h"

#include "world/partners.h"
extern s32 D_80245234_9C2894;

// duplicate of func_8024095C_97BF8C
ApiStatus func_802400C0_9BD720(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_80245234_9C2894) {
        case 0:
            D_80245234_9C2894 = 1;
            return ApiStatus_BLOCK;
        case 1:
        case 2:
            D_80245234_9C2894++;
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
