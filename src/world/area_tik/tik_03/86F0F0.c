#include "tik_03.h"
#include "world/partners.h"

#include "world/common/UnkPosFunc2.inc.c"

extern s32 D_80242EBC_8719BC;
extern s32 D_80242930_871430[4];

ApiStatus func_80240960_86F460(Evt* script, s32 isInitialCall) {
    PlayerStatus* player = &gPlayerStatus;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80242930_871430); i++) {
        if (gCollisionStatus.currentFloor != D_80242930_871430[i]) {
            continue;
        }
        if ((player->actionState == ACTION_STATE_SPIN_POUND) || (player->actionState == ACTION_STATE_TORNADO_POUND)) {
            return ApiStatus_BLOCK;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802409C0_86F4C0(Evt* script, s32 isInitialCall) {
    func_800EF300();
    return ApiStatus_DONE2;
}

ApiStatus func_802409E0_86F4E0(Evt* script, s32 isInitialCall) {
    PlayerStatus* player = &gPlayerStatus;

    switch (D_80242EBC_8719BC) {
        case 0:
            D_80242EBC_8719BC = 1;
            return ApiStatus_BLOCK;
        case 1:
        case 2:
            D_80242EBC_8719BC++;
            return ApiStatus_BLOCK;
        case 3:
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(player->position.x, player->position.z);
            func_800EF3D4(0);
            wPartnerNpc->yaw = 270.0f;
            gPlayerStatus.targetYaw = 270.0f;
            gPlayerStatus.currentYaw = 270.0f;
            gPlayerStatus.spriteFacingAngle = 180.0f;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
