#include "omo_09.h"

static char* N(exit_str_0) = "omo_08";
static char* N(exit_str_1) = "";

extern s32 D_80243A80_DD0750[4];
extern f32 D_80243A90_DD0760[4][2];

ApiStatus func_80240000_DCCCD0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (playerStatus->flags & PS_FLAGS_20) {
        return TRUE;
    }

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE &&
        (playerData->currentPartner == PARTNER_GOOMBARIO || playerData->currentPartner == PARTNER_SUSHIE))
    {
        return TRUE;
    }

    return FALSE;
}

ApiStatus func_80240054_DCCD24(Evt* script, s32 isInitialCall) {
    if (!func_80240000_DCCCD0()) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240078_DCCD48(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    f32 x, y, z;
    f32 outLength;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    s32 hit;
    s32 one;
    u32 i;

    script->varTable[0] = 0;
    if (func_80240000_DCCCD0()) {
        return ApiStatus_DONE2;
    }

    one = 1;
    if (partnerActionStatus->actingPartner == PARTNER_BOW &&
        partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE &&
        playerStatus->alpha1 == 128)
    {
        x = playerStatus->position.x;
        y = playerStatus->position.y;
        z = playerStatus->position.z;
        outLength = 1000.0f;
        hit = player_raycast_below_cam_relative(playerStatus,
            &x, &y, &z, &outLength,
            &hitRx, &hitRz, &hitDirX, &hitDirZ
        );

        for (i = 0; i < ARRAY_COUNT(D_80243A80_DD0750); i++) {
            if (hit == D_80243A80_DD0750[i]) {
                playerStatus->pushVelocity.x = D_80243A90_DD0760[i][0];
                playerStatus->pushVelocity.z = D_80243A90_DD0760[i][one]; // TODO needed to match
            }
        }
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    one = 1;
    if (partnerActionStatus->actingPartner != PARTNER_LAKILESTER ||
        partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE)
    {
        for (i = 0; i < ARRAY_COUNT(D_80243A80_DD0750); i++) {
            if (gCollisionStatus.currentFloor == D_80243A80_DD0750[i] || gCollisionStatus.lastTouchedFloor == D_80243A80_DD0750[i]) {
                playerStatus->pushVelocity.x = D_80243A90_DD0760[i][0];
                playerStatus->pushVelocity.z = D_80243A90_DD0760[i][one]; // TODO needed to match
            }
            if (partner->currentFloor == D_80243A80_DD0750[i] &&
                ((partnerActionStatus->actingPartner != PARTNER_KOOPER) ||
                 (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE)))
            {
                partner->pos.x += D_80243A90_DD0760[i][0];
                partner->pos.z += D_80243A90_DD0760[i][one]; // TODO needed to match
                partner_clear_player_tracking(partner);
            }
        }
    }

    return ApiStatus_DONE2;
}
