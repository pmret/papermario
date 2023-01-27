#include "omo_09.h"

s32 N(ConveyorColliders)[4] = {
    COLLIDER_o904,
    COLLIDER_o906,
    COLLIDER_o907,
    COLLIDER_o911 
};

//TODO Vec2f[4]
f32 N(ConveyorPushVels)[4][2] = {
    { -3.9,  0.0 },
    {  3.9,  0.0 },
    {  0.0,  3.9 },
    {  0.0, -3.9 },
};

s32 N(ShouldPauseConveyor)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (playerStatus->flags & PS_FLAG_PAUSED) {
        return TRUE;
    }

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE &&
        (playerData->currentPartner == PARTNER_GOOMBARIO || playerData->currentPartner == PARTNER_SUSHIE))
    {
        return TRUE;
    }

    return FALSE;
}

API_CALLABLE(N(WaitWhileConveyorPaused)) {
    if (!N(ShouldPauseConveyor)()) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AddConveyorPush)) {
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
    if (N(ShouldPauseConveyor)()) {
        return ApiStatus_DONE2;
    }

    one = 1;
    if (partnerActionStatus->actingPartner == PARTNER_BOW) {
        if (partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE && playerStatus->alpha1 == 128) {
            x = playerStatus->position.x;
            y = playerStatus->position.y;
            z = playerStatus->position.z;
            outLength = 1000.0f;
            hit = player_raycast_below_cam_relative(playerStatus,
                &x, &y, &z, &outLength,
                &hitRx, &hitRz, &hitDirX, &hitDirZ
            );

            for (i = 0; i < ARRAY_COUNT(N(ConveyorColliders)); i++) {
                if (hit == N(ConveyorColliders)[i]) {
                    playerStatus->pushVelocity.x = N(ConveyorPushVels)[i][0];
                    playerStatus->pushVelocity.z = N(ConveyorPushVels)[i][one]; // TODO needed to match
                }
            }
            script->varTable[0] = 1;
            return ApiStatus_DONE2;
        }
    }
    one = 1;
    if (partnerActionStatus->actingPartner != PARTNER_LAKILESTER ||
        partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE)
    {
        for (i = 0; i < ARRAY_COUNT(N(ConveyorColliders)); i++) {
            if (gCollisionStatus.currentFloor == N(ConveyorColliders)[i] ||
                gCollisionStatus.lastTouchedFloor == N(ConveyorColliders)[i])
            {
                playerStatus->pushVelocity.x = N(ConveyorPushVels)[i][0];
                playerStatus->pushVelocity.z = N(ConveyorPushVels)[i][one]; // TODO needed to match
            }

            if (partner->currentFloor == N(ConveyorColliders)[i] &&
                ((partnerActionStatus->actingPartner != PARTNER_KOOPER) ||
                 (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE)))
            {
                partner->pos.x += N(ConveyorPushVels)[i][0];
                partner->pos.z += N(ConveyorPushVels)[i][one]; // TODO needed to match
                partner_clear_player_tracking(partner);
            }
        }
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupConveyors) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(EnableTexPanning, MODEL_1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_4, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_8, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(0)
            EVT_CALL(N(WaitWhileConveyorPaused))
            EVT_ADD(LVar1, -1280)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_8, TEX_PANNER_MAIN, 0, LVar1)
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(10)
            EVT_CALL(N(AddConveyorPush))
            EVT_WAIT(1)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
