#include "common.h"

enum NpcFollowStates {
    NPC_FOLLOW_STATE_RUN = 0,
    NPC_FOLLOW_STATE_JUMP = 1,
    NPC_FOLLOW_STATE_FALL = 2,
    NPC_FOLLOW_STATE_IDLE = 10,
};

void get_npc_pos(s32 npcID, f32* outX, f32* outY, f32* outZ, s32* outAirborne) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc;

    *outX = 0.0f;
    *outY = 0.0f;
    *outZ = 0.0f;
    *outAirborne = FALSE;

    if (npcID == NPC_SELF) {
        *outX = playerStatus->pos.x;
        *outY = playerStatus->pos.y;
        *outZ = playerStatus->pos.z;
        if (playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING)) {
            *outAirborne = TRUE;
        }
    } else {
        npc = get_npc_unsafe(npcID);
        *outX = npc->pos.x;
        *outY = npc->pos.y;
        *outZ = npc->pos.z;
        if (npc->flags & NPC_FLAG_JUMPING) {
            *outAirborne = TRUE;
        }
    }

}

void npc_follow_init(Npc* npc, s32 targetNpcID, FollowAnims* anims, f32 walkSpeed, f32 runSpeed, s32 idleRadius, s32 walkRadius) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    NpcFollowData* followData;
    s32 i;

    npc->blur.followData = followData = heap_malloc(sizeof(*followData));
    ASSERT(followData != NULL);

    for (i = 0; i < ARRAY_COUNT(followData->moveHistory); i++) {
        followData->moveHistory[i].pos.x = playerStatus->pos.x;
        followData->moveHistory[i].pos.y = playerStatus->pos.y;
        followData->moveHistory[i].pos.z = playerStatus->pos.z;
        followData->moveHistory[i].isAirborne = FALSE;
    }
    followData->lastPointIdx = 0;
    followData->targetPointIdx = 0;
    followData->followState = NPC_FOLLOW_STATE_RUN;
    followData->targetNpcID = targetNpcID;
    followData->anims = anims;
    followData->walkSpeed = walkSpeed;
    followData->runSpeed = runSpeed;
    followData->idleRadius = idleRadius;
    followData->walkRadius = walkRadius;
    npc->curAnim = followData->anims->idle;
    npc->jumpVel = 0.0f;
    npc->flags |= NPC_FLAG_GRAVITY;
    npc->flags &= ~NPC_FLAG_IGNORE_PLAYER_COLLISION;
    npc->collisionChannel = COLLISION_CHANNEL_10000;
}

void npc_update_npc_tracking(Npc* npc) {
    NpcFollowData* followData = npc->blur.followData;
    f32 x, y, z;
    s32 airborne;
    s32 isAirborne;
    NpcHistoryPoint* historyPoint;

    get_npc_pos(followData->targetNpcID, &x, &y, &z, &airborne);
    historyPoint = &followData->moveHistory[followData->lastPointIdx];
    isAirborne = airborne != FALSE;

    if (historyPoint->isAirborne && isAirborne) {
        return;
    }

    if (!isAirborne && dist2D(npc->pos.x, npc->pos.z, x, z) <= followData->idleRadius && !historyPoint->isAirborne) {
        return;
    }

    historyPoint = &followData->moveHistory[followData->lastPointIdx];
    if (historyPoint->pos.x != x || historyPoint->pos.y != y || historyPoint->pos.z != z) {
        if (followData->targetPointIdx != followData->lastPointIdx + 1) {
            followData->lastPointIdx++;
            if (followData->lastPointIdx >= ARRAY_COUNT(followData->moveHistory)) {
                followData->lastPointIdx = 0;
            }
            historyPoint = &followData->moveHistory[followData->lastPointIdx];
            historyPoint->pos.x = x;
            historyPoint->pos.y = y;
            historyPoint->pos.z = z;
            historyPoint->isAirborne = isAirborne;
        }
    }
}

void npc_follow_npc(Npc* npc) {
    NpcFollowData* followData = npc->blur.followData;
    f32 x, y, z;
    s32 airborne;
    f32 currentX, currentY, currentZ;
    f32 dist;
    NpcHistoryPoint* historyPoint;
    f32 targetX, targetY, targetZ;
    f32 theta;
    f32 yaw;

    get_npc_pos(followData->targetNpcID, &x, &y, &z, &airborne);

    switch (followData->followState) {
        case NPC_FOLLOW_STATE_RUN:
            historyPoint = &followData->moveHistory[followData->targetPointIdx];
            targetX = historyPoint->pos.x;
            targetY = historyPoint->pos.y;
            targetZ = historyPoint->pos.z;
            currentX = npc->pos.x;
            currentY = npc->pos.y;
            currentZ = npc->pos.z;
            npc->moveSpeed = followData->walkSpeed;

            dist = dist2D(npc->pos.x, npc->pos.z, x, z);
            if (dist >= followData->walkRadius) {
                npc->moveSpeed = followData->runSpeed;
            }

            npc->curAnim = followData->anims->run;
            if (!(npc->flags & NPC_FLAG_GROUNDED)) {
                npc->curAnim = followData->anims->fall;
            }

            while (TRUE) {
                dist = dist2D(currentX, currentZ, targetX, targetZ);
                yaw = atan2(currentX, currentZ, targetX, targetZ);
                if (dist > npc->moveSpeed) {
                    dist = dist2D(currentX, currentZ, x, z);
                    if (dist > followData->walkRadius) {
                        break;
                    }

                    if (dist > followData->idleRadius) {
                        npc->moveSpeed = dist - followData->idleRadius;
                        if (npc->moveSpeed > followData->walkSpeed) {
                            npc->moveSpeed = followData->walkSpeed;
                        } else {
                            npc->moveSpeed += 1.0;
                        }
                        break;
                    }
                }

                if (followData->targetPointIdx == followData->lastPointIdx) {
                    npc->moveSpeed = 0.0f;
                    yaw = npc->yaw;
                    npc->curAnim = followData->anims->idle;
                    break;
                }

                dist = dist2D(npc->pos.x, npc->pos.z, x, z);
                if (dist <= followData->idleRadius) {
                    npc->moveSpeed = 0.0f;
                    yaw = npc->yaw;
                    npc->curAnim = followData->anims->idle;
                    followData->followState = NPC_FOLLOW_STATE_IDLE;
                    break;
                }

                followData->targetPointIdx++;
                if (followData->targetPointIdx >= ARRAY_COUNT(followData->moveHistory)) {
                    followData->targetPointIdx = 0;
                }
                historyPoint = &followData->moveHistory[followData->targetPointIdx];
                targetX = historyPoint->pos.x;
                targetZ = historyPoint->pos.z;
                if (npc->flags & NPC_FLAG_GROUNDED) {
                    if (historyPoint->isAirborne) {
                        followData->followState = NPC_FOLLOW_STATE_JUMP;
                        break;
                    }
                }
            }

            if (!(npc->flags & NPC_FLAG_GROUNDED)) {
                npc->moveSpeed *= 0.5f;
            }
            npc->yaw = yaw;
            npc_move_heading(npc, npc->moveSpeed, yaw);
            if ((npc->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD) && (npc->flags & NPC_FLAG_GROUNDED)) {
                followData->followState = NPC_FOLLOW_STATE_JUMP;
            }
            break;
        case NPC_FOLLOW_STATE_JUMP:
            if (followData->targetPointIdx != followData->lastPointIdx) {
                followData->targetPointIdx++;
                if (followData->targetPointIdx >= ARRAY_COUNT(followData->moveHistory)) {
                    followData->targetPointIdx = 0;
                }
                historyPoint = &followData->moveHistory[followData->targetPointIdx];
                targetX = historyPoint->pos.x;
                targetY = historyPoint->pos.y;
                targetZ = historyPoint->pos.z;
                npc->moveToPos.x = targetX;
                npc->moveToPos.y = targetY;
                npc->moveToPos.z = targetZ;
                npc->duration = 0;
                npc->jumpScale = 2.0f;
                npc->moveSpeed = followData->runSpeed;
                npc->planarFlyDist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
                npc->yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
                dist = npc->planarFlyDist;
                currentY = npc->moveToPos.y - npc->pos.y;
                if (npc->planarFlyDist < currentY) {
                    dist = currentY;
                }
                if (dist < followData->idleRadius) {
                    npc->jumpVel = 0.0f;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
                    followData->followState = NPC_FOLLOW_STATE_RUN;
                    return;
                }
                npc->duration = dist / npc->moveSpeed;
                if (npc->duration < 10) {
                    npc->duration = 10;
                }
                npc->moveSpeed = npc->planarFlyDist / npc->duration;
                npc->jumpVel = (currentY + (npc->jumpScale * npc->duration * npc->duration * 0.5f)) / npc->duration;
                npc->curAnim = followData->anims->jump;
                npc->flags &= ~NPC_FLAG_GRAVITY;
                followData->followState = NPC_FOLLOW_STATE_FALL;
            }
            break;
        case NPC_FOLLOW_STATE_FALL:
            npc->jumpVel -= npc->jumpScale;
            npc->pos.y += npc->jumpVel;
            if (npc->jumpVel <= 0.0f) {
                npc->curAnim = followData->anims->fall;
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->jumpVel <= 0.0f) {
                currentX = npc->pos.x;
                dist = fabsf(npc->jumpVel) + 8.0;
                currentY = npc->pos.y + dist;
                currentZ = npc->pos.z;
                if (npc_raycast_down_sides(npc->collisionChannel, &currentX, &currentY, &currentZ, &dist) != 0 &&
                    dist <= fabsf(npc->jumpVel) + 8.0)
                {
                    npc->curAnim = followData->anims->land;
                    npc->jumpVel = 0.0f;
                    npc->pos.y = currentY;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->yaw = atan2(currentX, currentZ, x, z);
                    followData->followState = NPC_FOLLOW_STATE_RUN;
                }
            }
            break;
        case NPC_FOLLOW_STATE_IDLE:
            historyPoint = &followData->moveHistory[followData->targetPointIdx];
            targetX = historyPoint->pos.x;
            targetY = historyPoint->pos.y;
            targetZ = historyPoint->pos.z;
            currentX = npc->pos.x;
            currentY = npc->pos.y;
            currentZ = npc->pos.z;
            dist = dist2D(npc->pos.x, npc->pos.z, x, z);
            if (dist <= followData->idleRadius) {
                break;
            }

            while (TRUE) {
                if (historyPoint->isAirborne) {
                    break;
                }

                yaw = atan2(npc->pos.x, npc->pos.z, targetX, targetZ);
                if (fabsf(get_clamped_angle_diff(yaw, atan2(npc->pos.x, npc->pos.z, x, z))) < 90.0f) {
                    break;
                }

                if (followData->targetPointIdx == followData->lastPointIdx) {
                    break;
                }

                followData->targetPointIdx++;
                if (followData->targetPointIdx >= ARRAY_COUNT(followData->moveHistory)) {
                    followData->targetPointIdx = 0;
                }
                historyPoint = &followData->moveHistory[followData->targetPointIdx];
                targetX = historyPoint->pos.x;
                targetZ = historyPoint->pos.z;
                continue;
            }

            if (!historyPoint->isAirborne) {
                followData->followState = NPC_FOLLOW_STATE_RUN;
                return;
            }

            while (TRUE) {
                if (!historyPoint->isAirborne) {
                    break;
                }

                yaw = atan2(npc->pos.x, npc->pos.z, targetX, targetZ);
                if (fabsf(get_clamped_angle_diff(yaw, atan2(npc->pos.x, npc->pos.z, x, z))) < 90.0f) {
                    break;
                }

                if (followData->targetPointIdx == followData->lastPointIdx) {
                    break;
                }

                followData->targetPointIdx++;
                if (followData->targetPointIdx >= ARRAY_COUNT(followData->moveHistory)) {
                    followData->targetPointIdx = 0;
                }
                historyPoint = &followData->moveHistory[followData->targetPointIdx];
                targetX = historyPoint->pos.x;
                targetZ = historyPoint->pos.z;
            }
            followData->followState = NPC_FOLLOW_STATE_JUMP;
            break;
    }
}
