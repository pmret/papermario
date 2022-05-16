#include "common.h"
#include "script_api/battle.h"

#define LERP(a, b, alpha) ((a) * (alpha) + (b) * (1.0f-(alpha)))
// battle cam
extern f32 BattleCam_PosX;
extern f32 BattleCam_PosY;
extern f32 BattleCam_PosZ;
extern s16 BattleCam_TargetActor;
extern s16 BattleCam_TargetActorPart;
extern s16 BattleCam_BoomLength;
extern s16 BattleCam_BoomYaw;
extern s16 BattleCam_BoomPitch;
extern s16 BattleCam_BoomZOffset;
extern f32 D_8029F288;
extern f32 BattleCam_InitialBoomLength;
extern f32 BattleCam_InitialBoomYaw;
extern f32 BattleCam_InitialBoomPitch;
extern f32 BattleCam_InitialBoomZOffset;
extern s8 BattleCam_DoneMoving;
extern s16 BattleCam_MoveTimeLeft;
extern s16 BattleCam_MoveTimeTotal;
extern s8 D_8029F2A2;
extern s8 D_8029F2A3;
extern s8 BattleCam_SetImmediately;
extern s8 BattleCam_UseLinearInterp;
extern s8 D_8029F2A6;
extern s8 D_8029F2A7;
extern f32 BattleCam_InitialPosX;
extern f32 BattleCam_InitialPosY;
extern f32 BattleCam_InitialPosZ;
extern EvtScript* BattleCam_ControlScript;

s8 BattleCam_IsFrozen = FALSE;
s32 BattleCam_CurrentPresetID = -1;

EvtScript CamPreset_B = {
    EVT_CALL(CamPresetUpdate_B)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_F = {
    EVT_CALL(CamPresetUpdate_F)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_M = {
    EVT_CALL(CamPresetUpdate_M)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_G = {
    EVT_CALL(CamPresetUpdate_G)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_I = {
    EVT_CALL(CamPresetUpdate_I)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_H = {
    EVT_CALL(CamPresetUpdate_H)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_N = {
    EVT_CALL(CamPresetUpdate_N)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_C = {
    EVT_CALL(CamPresetUpdate_C)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_D = {
    EVT_CALL(CamPresetUpdate_D)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_E = {
    EVT_CALL(CamPresetUpdate_E)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_J = {
    EVT_CALL(CamPresetUpdate_J)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_K = {
    EVT_CALL(CamPresetUpdate_K)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_L = {
    EVT_CALL(CamPresetUpdate_L)
    EVT_RETURN
    EVT_END
};

EvtScript CamPreset_A = {
    EVT_CALL(func_8024E9B0, 0, 15, 0)
    EVT_CALL(func_8024E748, 2, 550)
    EVT_CALL(func_8024E748, 3, 100)
    EVT_CALL(func_8024E748, 4, 8)
    EVT_RETURN
    EVT_END
};

EvtScript D_80280EB8 = {
    EVT_CALL(SetCamPerspective, 1, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 1, 12, 20, 296, 200)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 1, 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(InitVirtualEntityList)
    EVT_CALL(InitAnimatedModels)
    EVT_CALL(func_802CABE8, 1, 0, 240, 100, 8)
    EVT_CALL(func_802CAE50, 1, -75, 35, 0)
    EVT_CALL(BattleCamTargetActor, 0)
    EVT_CALL(func_8024CE9C)
    EVT_RETURN
    EVT_END
};

ApiStatus CamPresetUpdate_B(Evt* script, s32 isInitialCall) {
    BattleCam_DoneMoving = TRUE;
    return ApiStatus_BLOCK;
}

s32 CamPresetUpdate_F(Evt* script, s32 isInitialCall) {
    Actor* actor;
    Actor* targetActor;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    f32 x, y, z;
    f32 middlePosX, middlePosY, middlePosZ;
    f32 targetX, targetY, targetZ;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 distToTarget;
    f32 adjustedSize;
    f32 boomLength;
    f32 extraLength;
    f32 dist;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (D_8029F2A2 != -1) {
                    middlePosY = y + (targetY - y) / 4;
                } else {
                    middlePosY = targetY;
                }
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) /2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = targetY;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) * 0.5f;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (D_8029F2A2 == -1) {
                    middlePosY = targetY;
                } else {
                    middlePosY = y;
                }
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        default:
            return ApiStatus_BLOCK;
    }

    if (D_8029F2A6) {
        f32 upperBound = (500.0f - BattleCam_InitialBoomLength) * 0.4 + 30.0;
        f32 lowerBound = -upperBound;

        if (middlePosX < lowerBound) {
            middlePosX += (lowerBound - middlePosX) / 2;
        }
        if (middlePosX > upperBound) {
            middlePosX += (upperBound - middlePosX) / 2;
        }
    }
    if (isInitialCall) {
        sizeX -= 24.0f;
        sizeY -= 24.0f;
        if (sizeX < 0.0f) {
            sizeX = 0.0f;
        }
        if (sizeY < 0.0f) {
            sizeY = 0.0f;
        }
        BattleCam_BoomLength += sizeX + sizeY;
        if (BattleCam_SetImmediately) {
            camera->auxPos.x = middlePosX;
            camera->auxPos.y = middlePosY;
            camera->auxPos.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    x = camera->auxPos.x;
    y = camera->auxPos.y;
    z = camera->auxPos.z;

    camera->auxPos.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->auxPos.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->auxPos.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;

    dist = dist2D(camera->auxPos.x, camera->auxPos.z, middlePosX, middlePosZ);
    adjustedSize = (averageSize + targetAverageSize) / 8;
    extraLength = dist + adjustedSize - 64.0f;
    distToTarget = dist3D(x, y, z, targetX, targetY, targetZ);
    boomLength = BattleCam_BoomLength + extraLength + distToTarget * 0.5f;

    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->auxBoomYaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->auxBoomPitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

s32 CamPresetUpdate_M(Evt* script, s32 isInitialCall) {
    Actor* actor;
    Actor* targetActor;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    f32 x, y, z;
    f32 middlePosX, middlePosY, middlePosZ;
    f32 targetX, targetY, targetZ;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 distToTarget;
    f32 boomLength;
    f32 extraLength;
    f32 dist;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (D_8029F2A2 != -1) {
                    middlePosY = y + (targetY - y) / 4;
                } else {
                    middlePosY = targetY;
                }
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) /2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = targetY;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) * 0.5f;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (D_8029F2A2 == -1) {
                    middlePosY = targetY;
                } else {
                    middlePosY = y;
                }
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        default:
            return ApiStatus_BLOCK;
    }

    if (D_8029F2A6) {
        f32 upperBound = (500.0f - BattleCam_InitialBoomLength) * 0.4 + 30.0;
        f32 lowerBound = -upperBound;

        if (middlePosX < lowerBound) {
            middlePosX += (lowerBound - middlePosX) / 2;
        }
        if (middlePosX > upperBound) {
            middlePosX += (upperBound - middlePosX) / 2;
        }
    }
    if (isInitialCall) {
        sizeX -= 24.0f;
        sizeY -= 24.0f;
        if (sizeX < 0.0f) {
            sizeX = 0.0f;
        }
        if (sizeY < 0.0f) {
            sizeY = 0.0f;
        }
        BattleCam_BoomLength += sizeX + sizeY;
        if (BattleCam_SetImmediately) {
            camera->auxPos.x = middlePosX;
            camera->auxPos.y = middlePosY;
            camera->auxPos.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    x = camera->auxPos.x;
    y = camera->auxPos.y;
    z = camera->auxPos.z;

    camera->auxPos.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->auxPos.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->auxPos.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;

    dist = dist2D(camera->auxPos.x, camera->auxPos.z, middlePosX, middlePosZ);
    extraLength = dist + averageSize + targetAverageSize - 64.0f;
    distToTarget = dist3D(x, y, z, targetX, targetY, targetZ);
    boomLength = BattleCam_BoomLength + extraLength + distToTarget * 0.5f;

    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->auxBoomYaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->auxBoomPitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

s32 CamPresetUpdate_G(Evt* script, s32 isInitialCall) {
    Actor* actor;
    Actor* targetActor;
    Actor* enemyActor;
    ActorPart* actorPart;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    f32 x, y, z;
    f32 middlePosX, middlePosY, middlePosZ;
    f32 targetX, targetY, targetZ;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 distToTarget;
    f32 boomLength;
    f32 extraLength;
    f32 dist;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->auxPos.y;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->auxPos.y;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            targetActor = battleStatus->enemyActors[actorID];
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }
            actorPart = get_actor_part(targetActor, BattleCam_TargetActorPart);
            x = actorPart->absolutePosition.x;
            y = actorPart->absolutePosition.y + actorPart->size.y / 2 + actorPart->size.y / 4;
            z = actorPart->absolutePosition.z;

            sizeY = actorPart->size.y;
            sizeX = actorPart->size.x;

            targetActor = get_actor(targetActor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->currentPos.x;
            targetY = targetActor->currentPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->currentPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (D_8029F2A2 >= 0) {
                if (D_8029F2A2 != 0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->auxPos.y;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        default:
            return ApiStatus_DONE2;
    }

    if (D_8029F2A6) {
        f32 upperBound = (500.0f - BattleCam_InitialBoomLength) * 0.4 + 30.0;
        f32 lowerBound = -upperBound;

        if (middlePosX < lowerBound) {
            middlePosX += (lowerBound - middlePosX) / 2;
        }
        if (middlePosX > upperBound) {
            middlePosX += (upperBound - middlePosX) / 2;
        }
    }
    if (isInitialCall) {
        sizeX -= 24.0f;
        sizeY -= 24.0f;
        if (sizeX < 0.0f) {
            sizeX = 0.0f;
        }
        if (sizeY < 0.0f) {
            sizeY = 0.0f;
        }
        BattleCam_BoomLength += sizeX + sizeY;
        if (BattleCam_SetImmediately) {
            camera->auxPos.x = middlePosX;
            camera->auxPos.y = middlePosY;
            camera->auxPos.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    x = camera->auxPos.x;
    y = camera->auxPos.y;
    z = camera->auxPos.z;

    camera->auxPos.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->auxPos.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->auxPos.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;

    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->auxBoomYaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->auxBoomPitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

s32 CamPresetUpdate_I(Evt* script, s32 isInitialCall) {
    Actor* actor;
    Actor* targetActor;
    Actor* enemyActor;
    ActorPart* actorPart;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 distToTarget;
    f32 boomLength;
    f32 extraLength;
    f32 dist;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                func_8024E40C(BTL_CAM_PRESET_C);
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + playerStatus->colliderHeight / 2;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                func_8024E40C(BTL_CAM_PRESET_C);
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                func_8024E40C(BTL_CAM_PRESET_C);
                return ApiStatus_BLOCK;
            }
            x = actor->currentPos.x;
            y = actor->currentPos.y + actor->size.y / 2;
            z = actor->currentPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;
            break;
        default:
            return ApiStatus_DONE2;
    }

    if (D_8029F2A6) {
        f32 upperBound = (500.0f - BattleCam_InitialBoomLength) * 0.4 + 30.0;
        f32 lowerBound = -upperBound;

        if (x < lowerBound) {
            x += (lowerBound - x) / 2;
        }
        if (x > upperBound) {
            x += (upperBound - x) / 2;
        }
    }
    if (isInitialCall) {
        sizeX -= 24.0f;
        sizeY -= 24.0f;
        if (sizeX < 0.0f) {
            sizeX = 0.0f;
        }
        if (sizeY < 0.0f) {
            sizeY = 0.0f;
        }
        BattleCam_BoomLength += sizeX + sizeY;
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    if (D_8029F2A3) {
        camera->auxPos.x = LERP(BattleCam_InitialPosX, x + D_8029F2A7, alpha);
    }
    if (D_8029F2A2 != 0) {
        camera->auxPos.y = LERP(BattleCam_InitialPosY, y, alpha);
    }
    camera->auxPos.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    boomLength = BattleCam_BoomLength + extraLength;
    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->auxBoomYaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->auxBoomPitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

s32 CamPresetUpdate_H(Evt* script, s32 isInitialCall) {
    Actor* actor;
    Actor* targetActor;
    Actor* enemyActor;
    ActorPart* actorPart;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 currentX, currentY, targetZ;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 distToTarget;
    f32 boomLength;
    f32 extraLength;
    f32 dist;
    s32 temp;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->currentPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->currentPos.y + playerStatus->colliderHeight / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->currentPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->currentPos.y + actor->size.y / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->currentPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->currentPos.y + actor->size.y / 2;
            break;
        default:
            return ApiStatus_DONE2;
    }

    if (D_8029F2A2 != 0) {
        f32 delta = currentY - y;
        y += delta / 2 + delta / 6.0f;
    }

    if (D_8029F2A3) {
        x += (currentX - x) / 2;
        if (x > 75.0f) {
            x -= fabsf(75.0f - x);
        }
    }

    if (D_8029F2A6) {
        f32 upperBound = (500.0f - BattleCam_InitialBoomLength) * 0.4 + 30.0;
        f32 lowerBound = -upperBound;

        if (x < lowerBound) {
            x += (lowerBound - x) / 2;
        }
        if (x > upperBound) {
            x += (upperBound - x) / 2;
        }
    }
    if (isInitialCall) {
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->auxPos.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->auxPos.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->auxPos.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    boomLength = BattleCam_BoomLength + extraLength;
    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->auxBoomYaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->auxBoomPitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_N(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha, oneMinusAlpha;
    f32 x, y, z;

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (isInitialCall) {
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    oneMinusAlpha = 1.0f - alpha;
    camera->auxPos.x = (BattleCam_InitialPosX * alpha) + (x * oneMinusAlpha);
    camera->auxPos.y = (BattleCam_InitialPosY * alpha) + (y * oneMinusAlpha);
    camera->auxPos.z = (BattleCam_InitialPosZ * alpha) + (z * oneMinusAlpha);
    camera->auxBoomZOffset = ((BattleCam_InitialBoomZOffset * alpha) + (BattleCam_BoomZOffset * oneMinusAlpha)) * 256.0f;
    camera->auxBoomLength = (BattleCam_InitialBoomLength * alpha) + (BattleCam_BoomLength * oneMinusAlpha);
    camera->auxBoomYaw = (BattleCam_InitialBoomYaw * alpha) + (BattleCam_BoomYaw * oneMinusAlpha);
    camera->auxBoomPitch = (BattleCam_InitialBoomPitch * alpha) + (BattleCam_BoomPitch * oneMinusAlpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_C(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha, oneMinusAlpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 0.0f;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomYaw = 0;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomZOffset = 0;
        BattleCam_PosY = 60.0f;
        if (BattleCam_SetImmediately) {
            camera->auxPos.y = 60.0f;
            camera->auxBoomZOffset = 0;
            camera->auxBoomYaw = 0;
            camera->auxBoomPitch = 8;
            camera->auxPos.x = BattleCam_PosX;
            camera->auxPos.z = BattleCam_PosX;
            camera->auxBoomLength = BattleCam_BoomLength;
        }
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    oneMinusAlpha = 1.0f - alpha;
    camera->auxPos.x = (BattleCam_InitialPosX * alpha) + (x * oneMinusAlpha);
    camera->auxPos.y = (BattleCam_InitialPosY * alpha) + (y * oneMinusAlpha);
    camera->auxPos.z = (BattleCam_InitialPosZ * alpha) + (z * oneMinusAlpha);
    camera->auxBoomZOffset = ((BattleCam_InitialBoomZOffset * alpha) + (BattleCam_BoomZOffset * oneMinusAlpha)) * 256.0f;
    camera->auxBoomLength = (BattleCam_InitialBoomLength * alpha) + (BattleCam_BoomLength * oneMinusAlpha);
    camera->auxBoomYaw = (BattleCam_InitialBoomYaw * alpha) + (BattleCam_BoomYaw * oneMinusAlpha);
    camera->auxBoomPitch = (BattleCam_InitialBoomPitch * alpha) + (BattleCam_BoomPitch * oneMinusAlpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_D(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha, oneMinusAlpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 35.0f;
        BattleCam_PosY = 60.0f;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomYaw = 0;

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    oneMinusAlpha = 1.0f - alpha;
    camera->auxPos.x = (BattleCam_InitialPosX * alpha) + (x * oneMinusAlpha);
    camera->auxPos.y = (BattleCam_InitialPosY * alpha) + (y * oneMinusAlpha);
    camera->auxPos.z = (BattleCam_InitialPosZ * alpha) + (z * oneMinusAlpha);
    camera->auxBoomZOffset = ((BattleCam_InitialBoomZOffset * alpha) + (BattleCam_BoomZOffset * oneMinusAlpha)) * 256.0f;
    camera->auxBoomLength = (BattleCam_InitialBoomLength * alpha) + (BattleCam_BoomLength * oneMinusAlpha);
    camera->auxBoomYaw = (BattleCam_InitialBoomYaw * alpha) + (BattleCam_BoomYaw * oneMinusAlpha);
    camera->auxBoomPitch = (BattleCam_InitialBoomPitch * alpha) + (BattleCam_BoomPitch * oneMinusAlpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_E(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha, oneMinusAlpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 35.0f;
        BattleCam_PosY = camera->auxPos.y;
        if (BattleCam_PosY < 60.0f) {
            BattleCam_PosY = 60.0f;
        }
        BattleCam_BoomPitch = 8;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomYaw = 0;
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    oneMinusAlpha = 1.0f - alpha;
    camera->auxPos.x = (BattleCam_InitialPosX * alpha) + (x * oneMinusAlpha);
    camera->auxPos.y = (BattleCam_InitialPosY * alpha) + (y * oneMinusAlpha);
    camera->auxPos.z = (BattleCam_InitialPosZ * alpha) + (z * oneMinusAlpha);
    camera->auxBoomZOffset = ((BattleCam_InitialBoomZOffset * alpha) + (BattleCam_BoomZOffset * oneMinusAlpha)) * 256.0f;
    camera->auxBoomLength = (BattleCam_InitialBoomLength * alpha) + (BattleCam_BoomLength * oneMinusAlpha);
    camera->auxBoomYaw = (BattleCam_InitialBoomYaw * alpha) + (BattleCam_BoomYaw * oneMinusAlpha);
    camera->auxBoomPitch = (BattleCam_InitialBoomPitch * alpha) + (BattleCam_BoomPitch * oneMinusAlpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_J(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha, oneMinusAlpha;
    f32 x, y, z;

    if (isInitialCall) {
        if (BattleCam_SetImmediately) {
            BattleCam_PosX = camera->auxPos.x;
            BattleCam_PosY = camera->auxPos.y;
            BattleCam_PosZ = camera->auxPos.z;
        }
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->auxPos.x;
        BattleCam_InitialPosY = camera->auxPos.y;
        BattleCam_InitialPosZ = camera->auxPos.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    oneMinusAlpha = 1.0f - alpha;
    camera->auxPos.x = (BattleCam_InitialPosX * alpha) + (x * oneMinusAlpha);
    camera->auxPos.y = (BattleCam_InitialPosY * alpha) + (y * oneMinusAlpha);
    camera->auxPos.z = (BattleCam_InitialPosZ * alpha) + (z * oneMinusAlpha);
    camera->auxBoomZOffset = ((BattleCam_InitialBoomZOffset * alpha) + (BattleCam_BoomZOffset * oneMinusAlpha)) * 256.0f;
    camera->auxBoomLength = (BattleCam_InitialBoomLength * alpha) + (BattleCam_BoomLength * oneMinusAlpha);
    camera->auxBoomYaw = (BattleCam_InitialBoomYaw * alpha) + (BattleCam_BoomYaw * oneMinusAlpha);
    camera->auxBoomPitch = (BattleCam_InitialBoomPitch * alpha) + (BattleCam_BoomPitch * oneMinusAlpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_K(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 screenX, screenY, screenZ;
    f32 deltaY;
    f32 y;
    s32 actorID;
    s32 actorClass;

    if (isInitialCall) {
        BattleCam_PosX = camera->auxPos.x;
        BattleCam_PosY = camera->auxPos.y;
        BattleCam_PosZ = camera->auxPos.z;
        D_8029F288 = camera->auxBoomLength;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
    }

    y = 0.0f;
    actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            if (battleStatus->playerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->playerActor->currentPos.y + (playerStatus->colliderHeight / 2);
            break;
        case ACTOR_CLASS_PARTNER:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->partnerActor->currentPos.y;
            break;
        case ACTOR_CLASS_ENEMY:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->enemyActors[actorID]->currentPos.y;
            break;
    }

    get_screen_coords(1, BattleCam_PosX, y, BattleCam_PosZ, &screenX, &screenY, &screenZ);

    if (screenY < 100) {
        y += 25.0f;
    }

    if (y < BattleCam_PosY) {
        y = BattleCam_PosY;
    }

    deltaY = y - camera->auxPos.y;
    if (fabsf(deltaY) < 0.01) {
        if (deltaY != 0.0f) {
            camera->auxPos.y = y;
        }
    } else {
        camera->auxPos.y += deltaY / 5.0f;
    }

    return ApiStatus_BLOCK;
}

ApiStatus CamPresetUpdate_L(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;
    f32 temp;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            if (battleStatus->playerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->playerActor->currentPos.x;
            y = battleStatus->playerActor->currentPos.y + (playerStatus->colliderHeight / 2);
            z = battleStatus->playerActor->currentPos.z;
            break;
        case ACTOR_CLASS_PARTNER:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->partnerActor->currentPos.x;
            y = battleStatus->partnerActor->currentPos.y;
            z = battleStatus->partnerActor->currentPos.z;
            break;
        case ACTOR_CLASS_ENEMY:
        default:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->enemyActors[actorID]->currentPos.x;
            y = battleStatus->enemyActors[actorID]->currentPos.y;
            z = battleStatus->enemyActors[actorID]->currentPos.z;
            break;
    }

    if (isInitialCall) {
        BattleCam_PosX = camera->auxPos.x;
        BattleCam_PosY = camera->auxPos.y;
        BattleCam_PosZ = camera->auxPos.z;
        D_8029F288 = camera->auxBoomLength;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
    }

    get_screen_coords(1, x, y, z, &screenX, &screenY, &screenZ);

    if (screenY < 100) {
        y += 25.0f;
    }
    if (y < BattleCam_PosY) {
        y = BattleCam_PosY;
    }

    if (screenX < 100) {
        x -= 25.0f;
    }
    if (x < BattleCam_PosX) {
        x = BattleCam_PosX;
    }
    if (screenX > 220) {
        x += 25.0f;
    }

    temp = x - camera->auxPos.x;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->auxPos.x = x;
        }
    } else {
        camera->auxPos.x += temp / 5.0f;
    }

    temp = y - camera->auxPos.y;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->auxPos.y = y;
        }
    } else {
        camera->auxPos.y += temp / 5.0f;
    }

    temp = z - camera->auxPos.z;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->auxPos.z = z;
        }
    } else {
        camera->auxPos.z += temp / 5.0f;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024CE9C(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];

    BattleCam_BoomPitch = 8;
    camera->auxBoomYaw = 0;
    camera->auxBoomZOffset = 0;
    BattleCam_BoomYaw = BattleCam_BoomZOffset = 0;
    BattleCam_IsFrozen = FALSE;
    D_8029F288 = camera->unk_1C;
    BattleCam_InitialBoomLength = camera->auxBoomLength;
    BattleCam_InitialBoomPitch = camera->auxBoomPitch;
    BattleCam_InitialBoomZOffset = BattleCam_InitialBoomYaw = 0.0f;
    return ApiStatus_DONE2;
}

void btl_cam_use_preset(s32 id) {
    BattleStatus* battleStatus = &gBattleStatus;
    EvtScript* preset = NULL;
    Evt* newScript;

    if (!BattleCam_IsFrozen) {
        D_8029F2A6 = TRUE;
        D_8029F2A2 = 0;
        D_8029F2A3 = FALSE;
        BattleCam_UseLinearInterp = FALSE;
        D_8029F2A7 = 0;

        switch (id) {
            case BTL_CAM_PRESET_A:
                preset = &CamPreset_A;
                break;
            case BTL_CAM_PRESET_B:
                preset = &CamPreset_B;
                break;
            case BTL_CAM_PRESET_C:
                if (BattleCam_CurrentPresetID != id) {
                    BattleCam_BoomLength = 500;
                    BattleCam_MoveTimeLeft = 30;
                    preset = &CamPreset_C;
                    break;
                }
                return;
            case BTL_CAM_PRESET_D:
                if (BattleCam_CurrentPresetID != id) {
                    BattleCam_BoomLength = 480;
                    preset = &CamPreset_D;
                    BattleCam_MoveTimeLeft = 20;
                    BattleCam_BoomZOffset = 0;
                    break;
                }
                return;
            case BTL_CAM_PRESET_E:
                if (BattleCam_CurrentPresetID != id) {
                    BattleCam_BoomLength = 500;
                    preset = &CamPreset_E;
                    BattleCam_MoveTimeLeft = 10;
                    BattleCam_BoomZOffset = 0;
                    break;
                }
                return;
            case BTL_CAM_PRESET_F:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_F;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_G:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_G;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_H:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_H;
                break;
            case BTL_CAM_PRESET_I:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_I;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_9:
                if (BattleCam_ControlScript != &CamPreset_C) {
                    BattleCam_BoomLength = 500;
                    BattleCam_MoveTimeLeft = 120;
                    preset = &CamPreset_C;
                    break;
                }
                return;
            case BTL_CAM_PRESET_10:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_F;
                BattleCam_BoomZOffset = 15;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_11:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                preset = &CamPreset_F;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_12:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_F;
                BattleCam_BoomZOffset = 30;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_13:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_I;
                BattleCam_BoomZOffset = 15;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_14:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                preset = &CamPreset_I;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_15:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_I;
                BattleCam_BoomZOffset = 30;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_16:
                BattleCam_BoomLength = 267;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 23;
                preset = &CamPreset_H;
                break;
            case BTL_CAM_PRESET_17:
                BattleCam_BoomLength = 300;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 8;
                preset = &CamPreset_H;
                break;
            case BTL_CAM_PRESET_18:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                preset = &CamPreset_H;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                break;
            case BTL_CAM_PRESET_19:
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_20:
                preset = &CamPreset_K;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                break;
            case BTL_CAM_PRESET_21:
                preset = &CamPreset_L;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                break;
            case BTL_CAM_PRESET_25:
                BattleCam_BoomLength = 266;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 40;
                btl_cam_set_target_pos(-80.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 20;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_24:
                BattleCam_BoomLength = 250;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 14;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_IsFrozen = TRUE;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_23:
                BattleCam_BoomLength = 255;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 29;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                btl_cam_set_target_pos(-95.0f, 18.0f, 10.0f);
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_22:
                BattleCam_BoomLength = 230;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_26:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_27:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_28:
                BattleCam_BoomLength = 340;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_30:
            case BTL_CAM_PRESET_31:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomZOffset = -32;
                D_8029F2A7 = 20;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_32:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 10;
                preset = &CamPreset_N;
                BattleCam_BoomZOffset = 10;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -65.0f;
                BattleCam_PosY = 30.0f;
                break;
            case BTL_CAM_PRESET_33:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                preset = &CamPreset_I;
                BattleCam_BoomZOffset = 24;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_34:
                BattleCam_BoomLength = 280;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_35:
                BattleCam_BoomLength = 380;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                BattleCam_UseLinearInterp = TRUE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_37:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_36:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                BattleCam_UseLinearInterp = TRUE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_38:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_39:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_40:
                BattleCam_BoomLength = 360;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_M;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                break;
            case BTL_CAM_PRESET_41:
            case BTL_CAM_PRESET_42:
                BattleCam_BoomLength = 200;
                BattleCam_MoveTimeLeft = 7;
                BattleCam_MoveTimeTotal = 7;
                BattleCam_DoneMoving = FALSE;
                D_8029F2A6 = FALSE;
                preset = BattleCam_ControlScript;
                break;
            case BTL_CAM_PRESET_43:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                D_8029F2A2 = -2;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_44:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A2 = 0;
                D_8029F2A3 = TRUE;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_45:
                BattleCam_BoomLength = 430;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 16;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_N;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                break;
            case BTL_CAM_PRESET_46:
                BattleCam_BoomLength = 460;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 27;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A2 = 0;
                preset = &CamPreset_N;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                break;
            case BTL_CAM_PRESET_70:
                BattleCam_BoomLength = 390;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 45;
                btl_cam_set_target_pos(-70.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 10;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_71:
                BattleCam_BoomLength = 500;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 45;
                btl_cam_set_target_pos(0.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 40;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_69:
            case BTL_CAM_PRESET_72:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 45;
                btl_cam_set_target_pos(-50.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 20;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_73:
                BattleCam_BoomLength = 166;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 1;
                preset = &CamPreset_N;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 17;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -75.0f;
                BattleCam_PosY = 150.0f;
                break;
            case BTL_CAM_PRESET_47:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 16;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                preset = &CamPreset_M;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                break;
            case BTL_CAM_PRESET_48:
                BattleCam_BoomLength = 250;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomZOffset = 16;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                BattleCam_UseLinearInterp = TRUE;
                preset = &CamPreset_M;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                break;
            case BTL_CAM_PRESET_49:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomZOffset = 16;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                BattleCam_UseLinearInterp = TRUE;
                preset = &CamPreset_I;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                break;
            case BTL_CAM_PRESET_50:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                D_8029F2A2 = 1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                break;
            case BTL_CAM_PRESET_29:
            case BTL_CAM_PRESET_51:
                BattleCam_MoveTimeLeft = 50;
                BattleCam_BoomLength = 500;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_D;
                break;
            case BTL_CAM_PRESET_52:
                BattleCam_BoomLength = 280;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                D_8029F2A2 = 1;
                BattleCam_BoomYaw = 0;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                break;
            case BTL_CAM_PRESET_53:
                BattleCam_BoomLength = 380;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                D_8029F2A2 = 1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_M;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                break;
            case BTL_CAM_PRESET_54:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 24;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                preset = &CamPreset_I;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                break;
            case BTL_CAM_PRESET_55:
                BattleCam_BoomLength = 210;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_N;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 10;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -95.0f;
                BattleCam_PosY = 22.0f;
                break;
            case BTL_CAM_PRESET_56:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                D_8029F2A2 = 1;
                BattleCam_BoomYaw = 0;
                D_8029F2A3 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_57:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                D_8029F2A2 = 1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                D_8029F2A3 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_58:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                preset = &CamPreset_N;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 10;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 25.0f;
                BattleCam_PosY = 60.0f;
                break;
            case BTL_CAM_PRESET_59:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomZOffset = 11;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                BattleCam_UseLinearInterp = TRUE;
                preset = &CamPreset_I;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                break;
            case BTL_CAM_PRESET_60:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A2 = 0;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_61:
            case BTL_CAM_PRESET_62:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomZOffset = -32;
                D_8029F2A7 = 20;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_63:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_F;
                BattleCam_BoomZOffset = 27;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_64:
                BattleCam_BoomLength = 358;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_65:
                BattleCam_MoveTimeLeft = 50;
                BattleCam_BoomLength = 500;
                preset = &CamPreset_C;
                break;
            case BTL_CAM_PRESET_66:
                BattleCam_BoomLength = 267;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = FALSE;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_67:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                preset = &CamPreset_F;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
            case BTL_CAM_PRESET_68:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                preset = &CamPreset_F;
                BattleCam_MoveTimeLeft = 4;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = TRUE;
                break;
        }

        BattleCam_CurrentPresetID = id;

        if (battleStatus->camMovementScript != NULL) {
            kill_script_by_ID(battleStatus->camMovementScriptID);
        }

        BattleCam_ControlScript = preset;
        newScript = start_script(preset, EVT_PRIORITY_A, EVT_FLAG_20);
        BattleCam_DoneMoving = FALSE;
        battleStatus->camMovementScript = newScript;
        battleStatus->camMovementScriptID = newScript->id;
    }
}

void func_8024E3D8(s32 arg0) {
    if (!BattleCam_IsFrozen) {
        BattleCam_SetImmediately = TRUE;
        btl_cam_use_preset(arg0);
    }
}

void func_8024E40C(s32 arg0) {
    if (!BattleCam_IsFrozen) {
        BattleCam_SetImmediately = FALSE;
        btl_cam_use_preset(arg0);
    }
}

void btl_cam_target_actor(s32 actorID) {
    if (!BattleCam_IsFrozen) {
        BattleCam_TargetActor = actorID;
    }
}

void btl_cam_target_actor_part(s32 actorID, s32 actorPartIndex) {
    if (!BattleCam_IsFrozen) {
        BattleCam_TargetActor = actorID;
        BattleCam_TargetActorPart = actorPartIndex;
    }
}

void func_8024E484(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 zoomPercent) {
    Camera* camera = &gCameras[CAM_BATTLE];

    if (!BattleCam_IsFrozen) {
        camera->unk_1C = arg0;
        camera->auxBoomLength = arg1;
        camera->unk_20 = arg2;
        camera->auxBoomPitch = arg3;
        camera->auxBoomYaw = arg4;
        camera->auxBoomZOffset = arg5 * 256;
        camera->unk_28 = arg6;
        camera->zoomPercent = zoomPercent;
    }
}

void btl_cam_move(s16 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (!BattleCam_IsFrozen) {
        BattleCam_MoveTimeLeft = arg0;
        if (battleStatus->camMovementScript != NULL) {
            restart_script(battleStatus->camMovementScript);
        }
    }
}

void btl_cam_set_target_pos(f32 x, f32 y, f32 z) {
    if (!BattleCam_IsFrozen) {
        BattleCam_PosX = x;
        BattleCam_PosY = y;
        BattleCam_PosZ = z;
    }
}

void func_8024E554(f32 arg0, f32 arg1, f32 arg2) {
    Camera* camera = &gCameras[CAM_BATTLE];

    if (!BattleCam_IsFrozen) {
        camera->auxPos.x = arg0;
        camera->auxPos.y = arg1;
        camera->auxPos.z = arg2;
    }
}

s32 btl_cam_is_moving_done(void) {
    return BattleCam_DoneMoving;
}

void btl_cam_set_zoom(s16 zoom) {
    if (!BattleCam_IsFrozen) {
        BattleCam_BoomLength = zoom;
    }
}

void btl_cam_add_zoom(s32 zoom) {
    if (!BattleCam_IsFrozen) {
        BattleCam_BoomLength += zoom;
    }
}

void btl_cam_set_zoffset(s16 zOffset) {
    if (!BattleCam_IsFrozen) {
        BattleCam_BoomZOffset = zOffset;
    }
}

void btl_cam_unfreeze(void) {
    BattleCam_IsFrozen = FALSE;
}

void func_8024E60C(void) {
    D_8029F2A6 = FALSE;
}

ApiStatus UseBattleCamPreset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 preset;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    preset = evt_get_variable(script, *args++);
    BattleCam_SetImmediately = FALSE;
    btl_cam_use_preset(preset);

    return ApiStatus_DONE2;
}

ApiStatus func_8024E664(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 preset;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    preset = evt_get_variable(script, *args++);
    BattleCam_SetImmediately = TRUE;
    btl_cam_use_preset(preset);

    return ApiStatus_DONE2;
}

ApiStatus func_8024E6B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_8024E40C(evt_get_variable(script, *args++));
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (btl_cam_is_moving_done()) {
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8024E748(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    Bytecode* args = script->ptrReadPos;
    s32 mode;
    s32 val;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    mode = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    switch (mode) {
        case AUX_CAM_PARAM_1:
            camera->unk_1C = val;
            break;
        case AUX_CAM_BOOM_LENGTH:
            camera->auxBoomLength = val;
            break;
        case AUX_CAM_PARAM_3:
            camera->unk_20 = val;
            break;
        case AUX_CAM_BOOM_PITCH:
            camera->auxBoomPitch = val;
            break;
        case AUX_CAM_BOOM_YAW:
            camera->auxBoomYaw = val;
            break;
        case AUX_CAM_BOOM_ZOFFSET:
            camera->auxBoomZOffset = val * 256;
            break;
        case AUX_CAM_PARAM_7:
            camera->unk_28 = val;
            break;
        case AUX_CAM_ZOOM_PERCENT:
            camera->zoomPercent = val;
            break;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024E820(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[CAM_BATTLE];

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    camera->unk_1C = evt_get_variable(script, *args++);
    camera->auxBoomLength = evt_get_variable(script, *args++);
    camera->unk_20 = evt_get_variable(script, *args++);
    camera->auxBoomPitch = evt_get_variable(script, *args++);
    camera->auxBoomYaw = evt_get_variable(script, *args++);
    camera->auxBoomZOffset = evt_get_variable(script, *args++) * 256;
    camera->unk_28 = evt_get_variable(script, *args++);
    camera->zoomPercent = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_PosX = evt_get_variable(script, *args++);
    BattleCam_PosY = evt_get_variable(script, *args++);
    BattleCam_PosZ = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8024E9B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[CAM_BATTLE];

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    camera->auxPos.x = evt_get_variable(script, *args++);
    camera->auxPos.y = evt_get_variable(script, *args++);
    camera->auxPos.z = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamOffsetZ(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomZOffset = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus AddBattleCamOffsetZ(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomZOffset += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomYaw = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus BattleCamTargetActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    btl_cam_target_actor(actorID);

    return ApiStatus_DONE2;
}

ApiStatus BattleCamTargetActorPart(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    btl_cam_target_actor_part(actorID, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus MoveBattleCamOver(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_MoveTimeLeft = evt_get_variable(script, *args++);
    BattleCam_CurrentPresetID = 0;

    if (battleStatus->camMovementScript != NULL) {
        restart_script(battleStatus->camMovementScript);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamZoom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomLength = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus AddBattleCamZoom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomLength += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8024ECF8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    D_8029F2A2 = evt_get_variable(script, *args++);
    D_8029F2A3 = evt_get_variable(script, *args++);
    BattleCam_UseLinearInterp = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus FreezeBattleCam(Evt* script, s32 isInitialCall) {
    BattleCam_IsFrozen = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_8024EDA4(Evt* script, s32 isInitialCall) {
    D_8029F2A6 = FALSE;
    return ApiStatus_DONE2;
}
