#ifndef _AI_FIRE_BAR_INC_
#define _AI_FIRE_BAR_INC_ 0

#include "common.h"

// from data
extern s32 N(FireBar_Sounds)[11];
extern EvtScript N(EVS_FireBar_Defeated);

enum {
    FIRE_BAR_SLOW_DOWN  = 0,
    FIRE_BAR_SPEED_UP   = 1,
    FIRE_BAR_HIT        = 2,
};

API_CALLABLE(N(FireBarAI_Main)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Bytecode* args = script->ptrReadPos;
    FireBarAISettings* settings;
    FireBarData* data;
    Npc* partnerNpc;
    Npc* npc;
    f32 distToPlayer, angleToPlayer;
    f32 distToNpc, angleToNpc;
    f32 deltaYaw, clampedYaw;
    f32 dX, dY, dZ;
    f32 tempPlayerDist;
    s32 hitDetected;
    s32 i;

    settings = (FireBarAISettings*) evt_get_variable(script, *args++);
    npc = get_npc_unsafe(script->owner1.enemy->npcID);
    partnerNpc = get_npc_unsafe(NPC_PARTNER);
    hitDetected = 0;

    if (isInitialCall) {
        data = heap_malloc(sizeof(*data));
        script->functionTempPtr[1] = data;
        data->flags = 0;
        data->centerPos.x = settings->centerPos.x;
        data->centerPos.y = settings->centerPos.y;
        data->centerPos.z = settings->centerPos.z;
        data->rotRate = settings->rotRate;
        data->firstNpc = settings->firstNpc;
        data->npcCount = settings->npcCount;
        data->callback = settings->callback;
        data->soundIndex = 0;
        data->lastDeltaYaw = 0;
        data->yaw = 0;
        data->settings = settings;
    }

    if (get_time_freeze_mode() != TIME_FREEZE_NORMAL) {
        return 0;
    }

    data = script->functionTempPtr[1];
    for (i = 0; i < data->npcCount; i++) {
        npc = get_npc_unsafe(data->firstNpc + i);
        if (!(data->flags & 1)) {
            f32 radius = (i * npc->collisionDiameter) * npc->scale.x;
            dX = radius * sin_deg(data->yaw);
            dZ = -radius * cos_deg(data->yaw);
            npc->pos.x = data->centerPos.x + dX;
            npc->pos.y = data->centerPos.y;
            npc->pos.z = data->centerPos.z + dZ;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
        }
        if (!(data->flags & 2) && !(playerStatus->flags & PS_FLAG_HAZARD_INVINCIBILITY)) {
            dY = playerStatus->pos.y - npc->pos.y;
            if (partnerStatus->partnerActionState == PARTNER_ACTION_USE) {
                if (partnerStatus->actingPartner == PARTNER_LAKILESTER) {
                    dY = partnerNpc->pos.y - npc->pos.y;
                } else if (partnerStatus->actingPartner == PARTNER_PARAKARRY) {
                    dY = (playerStatus->pos.y - 10.0f) - npc->pos.y;
                }
            }
            dX = playerStatus->pos.x - npc->pos.x;
            dZ = playerStatus->pos.z - npc->pos.z;
            if ((fabsf(dY) < (npc->collisionHeight * 0.8f))
                && (sqrtf(SQ(dX) + SQ(dZ)) <= ((npc->collisionDiameter * 0.5f * npc->scale.x * 0.5f) + (playerStatus->colliderDiameter * 0.5f * 0.5f)))) {
                hitDetected = 1;
            }
        }
    }
    if (playerStatus->flags & PS_FLAG_HAZARD_INVINCIBILITY) {
        hitDetected = -1;
    }
    data->yaw += data->rotRate;
    clampedYaw = clamp_angle(data->yaw);
    if (clampedYaw != data->yaw) {
        data->yaw = clampedYaw;
        sfx_play_sound_at_position(N(FireBar_Sounds)[data->soundIndex], SOUND_SPACE_MODE_0, data->centerPos.x, data->centerPos.y, data->centerPos.z);
    }
    distToPlayer = dist2D(data->centerPos.x, data->centerPos.z, playerStatus->pos.x, playerStatus->pos.z);
    distToNpc = dist2D(data->centerPos.x, data->centerPos.z, npc->pos.x, npc->pos.z)
        + (npc->collisionDiameter * 0.5f * npc->scale.x * 0.5f) + (playerStatus->colliderDiameter * 0.5f * 0.5f);
    tempPlayerDist = distToPlayer; // needed to match
    angleToPlayer = atan2(data->centerPos.x, data->centerPos.z, playerStatus->pos.x, playerStatus->pos.z);
    angleToNpc = atan2(data->centerPos.x, data->centerPos.z, npc->pos.x, npc->pos.z);
    deltaYaw = get_clamped_angle_diff(angleToPlayer, angleToNpc);
    if ((hitDetected > 0) && (playerStatus->actionState != ACTION_STATE_HIT_FIRE)) {
        playerStatus->hazardType = HAZARD_TYPE_FIRE_BAR;
        set_action_state(ACTION_STATE_HIT_FIRE);
        sfx_play_sound_at_position(SOUND_E8, SOUND_SPACE_MODE_0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
        gCurrentEncounter.battleTriggerCooldown = 45;
        playerStatus->blinkTimer = 45;
        playerStatus->lastGoodPos.x = playerStatus->pos.x;
        playerStatus->lastGoodPos.y = playerStatus->pos.y;
        playerStatus->lastGoodPos.z = playerStatus->pos.z;
        data->soundIndex = 0;
        if (data->callback != NULL) {
            data->callback(data, FIRE_BAR_HIT);
        }
    } else if ((tempPlayerDist < distToNpc) && !(data->flags & 2)
        && (hitDetected == 0) && (playerStatus->actionState != ACTION_STATE_HIT_FIRE)) {
        if (data->rotRate > 0.0f) {
            if (data->lastDeltaYaw < 0.0f) {
                if (deltaYaw > 0.0f) {
                    data->soundIndex++;
                    if (data->callback != NULL) {
                        data->callback(data, FIRE_BAR_SPEED_UP);
                    }
            }
            }
        } else if (data->lastDeltaYaw > 0.0f) {
            if (deltaYaw < 0.0f) {
                data->soundIndex++;
                if (data->callback != NULL) {
                    data->callback(data, FIRE_BAR_SPEED_UP);
                }
            }
        }
    }
    data->lastDeltaYaw = deltaYaw;
    if (data->callback != NULL) {
        data->callback(data, FIRE_BAR_SLOW_DOWN);
    }
    return ApiStatus_BLOCK;
}

void N(FireBarAI_Callback)(FireBarData* data, s32 mode) {
    switch (mode) {
        case FIRE_BAR_SLOW_DOWN:
            if (data->flags & 2) {
                data->rotRate *= 0.95f;
            }
            break;
        case FIRE_BAR_SPEED_UP:
            data->rotRate *= 1.12f;
            if (data->soundIndex == 10) {
                Evt* script = start_script(&N(EVS_FireBar_Defeated), EVT_PRIORITY_1, 0);
                script->varTable[0] = data->firstNpc;
                script->varTable[1] = data->npcCount;
                data->flags |= 2;
            }
            break;
        case FIRE_BAR_HIT:
            data->rotRate = abs(data->settings->rotRate) * signF(-data->rotRate);
            break;
    }
    return;
}

#endif
