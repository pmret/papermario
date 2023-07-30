#include "common.h"
#include "script_api/battle.h"

#define LERP(a, b, alpha) ((a) * (alpha) + (b) * (1.0f-(alpha)))

static f32 BattleCam_PosX;
static f32 BattleCam_PosY;
static f32 BattleCam_PosZ;
static s16 BattleCam_TargetActor;
static s16 BattleCam_TargetActorPart;
static s16 BattleCam_BoomLength;
static s16 BattleCam_BoomYaw;
static s16 BattleCam_BoomPitch;
static s16 BattleCam_BoomZOffset;
static f32 D_8029F288;
static f32 BattleCam_InitialBoomLength;
static f32 BattleCam_InitialBoomYaw;
static f32 BattleCam_InitialBoomPitch;
static f32 BattleCam_InitialBoomZOffset;
static s8 BattleCam_DoneMoving;
static s16 BattleCam_MoveTimeLeft;
static s16 BattleCam_MoveTimeTotal;
static s8 BattleCam_ModeY;
static s8 BattleCam_ModeX;
static s8 BattleCam_SetImmediately;
static s8 BattleCam_UseLinearInterp;
static s8 D_8029F2A6;
static s8 D_8029F2A7;
static f32 BattleCam_InitialPosX;
static f32 BattleCam_InitialPosY;
static f32 BattleCam_InitialPosZ;
static EvtScript* BattleCam_ControlScript;

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

EvtScript EVS_BattleCam_Default = {
    EVT_CALL(BattleCamImpl_Default)
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
    EVT_CALL(SetBattleCamPos, 0, 15, 0)
    EVT_CALL(SetBattleCamParam, AUX_CAM_BOOM_LENGTH, 550)
    EVT_CALL(SetBattleCamParam, AUX_CAM_PARAM_3, 100)
    EVT_CALL(SetBattleCamParam, AUX_CAM_BOOM_PITCH, 8)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_OnBattleInit = {
    EVT_CALL(SetCamPerspective, CAM_BATTLE, CAM_UPDATE_MODE_6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, CAM_BATTLE, 12, 20, 296, 200)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_BATTLE, TRUE)
    EVT_WAIT(1)
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_ModeY != BTL_CAM_MODEY_MINUS_1) {
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) /2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) * 0.5f;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_ModeY == BTL_CAM_MODEY_MINUS_1) {
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
            camera->lookAt_obj_target.x = middlePosX;
            camera->lookAt_obj_target.y = middlePosY;
            camera->lookAt_obj_target.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    x = camera->lookAt_obj_target.x;
    y = camera->lookAt_obj_target.y;
    z = camera->lookAt_obj_target.z;

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;

    dist = dist2D(camera->lookAt_obj_target.x, camera->lookAt_obj_target.z, middlePosX, middlePosZ);
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_ModeY != BTL_CAM_MODEY_MINUS_1) {
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) /2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
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
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) * 0.5f;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_ModeY == BTL_CAM_MODEY_MINUS_1) {
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
            camera->lookAt_obj_target.x = middlePosX;
            camera->lookAt_obj_target.y = middlePosY;
            camera->lookAt_obj_target.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    x = camera->lookAt_obj_target.x;
    y = camera->lookAt_obj_target.y;
    z = camera->lookAt_obj_target.z;

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;

    dist = dist2D(camera->lookAt_obj_target.x, camera->lookAt_obj_target.z, middlePosX, middlePosZ);
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
    f32 targetAverageSize;
    f32 alpha;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->lookAt_obj_target.y;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2 + actor->size.y / 4;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;

            targetActor = get_actor(actor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->lookAt_obj_target.y;
            }
            middlePosZ = z + (targetZ - z) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            targetActor = battleStatus->enemyActors[actorID];
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }
            actorPart = get_actor_part(targetActor, BattleCam_TargetActorPart);
            x = actorPart->absolutePos.x;
            y = actorPart->absolutePos.y + actorPart->size.y / 2 + actorPart->size.y / 4;
            z = actorPart->absolutePos.z;

            sizeY = actorPart->size.y;
            sizeX = actorPart->size.x;

            targetActor = get_actor(targetActor->targetActorID);
            if (targetActor == NULL) {
                return ApiStatus_BLOCK;
            }

            targetX = targetActor->curPos.x;
            targetY = targetActor->curPos.y + targetActor->size.y / 2 + targetActor->size.y / 4;
            targetZ = targetActor->curPos.z;
            targetAverageSize = (targetActor->size.y + targetActor->size.x) / 2;

            middlePosX = x + (targetX - x) / 2;
            if (BattleCam_ModeY > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                middlePosY = camera->lookAt_obj_target.y;
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
            camera->lookAt_obj_target.x = middlePosX;
            camera->lookAt_obj_target.y = middlePosY;
            camera->lookAt_obj_target.z = middlePosZ;
            camera->auxBoomLength = BattleCam_BoomLength;
            camera->auxBoomZOffset = BattleCam_BoomZOffset * 256;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    x = camera->lookAt_obj_target.x;
    y = camera->lookAt_obj_target.y;
    z = camera->lookAt_obj_target.z;

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, middlePosX, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, middlePosY, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, middlePosZ, alpha);
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
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 extraLength;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                return ApiStatus_BLOCK;
            }
            x = actor->curPos.x;
            y = actor->curPos.y + playerStatus->colliderHeight / 2;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                return ApiStatus_BLOCK;
            }
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2;
            z = actor->curPos.z;

            sizeY = actor->size.y;
            sizeX = actor->size.x;
            averageSize = (sizeY + sizeX) / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                return ApiStatus_BLOCK;
            }
            x = actor->curPos.x;
            y = actor->curPos.y + actor->size.y / 2;
            z = actor->curPos.z;

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
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    if (BattleCam_ModeX != BTL_CAM_MODEX_0) {
        camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x + D_8029F2A7, alpha);
    }
    if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
        camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    }
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength + extraLength, alpha);
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
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 currentX, currentY;
    f32 averageSize;
    f32 alpha;
    f32 extraLength;
    s32 actorClass = BattleCam_TargetActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_TargetActor & 0xFF;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            actor = battleStatus->playerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->curPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->curPos.y + playerStatus->colliderHeight / 2;
            break;
        case ACTOR_CLASS_PARTNER:
            actor = battleStatus->partnerActor;
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->curPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->curPos.y + actor->size.y / 2;
            break;
        case ACTOR_CLASS_ENEMY:
            actor = battleStatus->enemyActors[actorID];
            if (actor == NULL) {
                return ApiStatus_BLOCK;
            }
            currentX = actor->curPos.x;
            x = actor->state.goalPos.x;
            y = actor->state.goalPos.y;
            z = actor->state.goalPos.z;
            averageSize = (actor->size.y + actor->size.x) / 2;
            currentY = actor->curPos.y + actor->size.y / 2;
            break;
        default:
            return ApiStatus_DONE2;
    }

    if (BattleCam_ModeY != BTL_CAM_MODEY_0) {
        f32 delta = currentY - y;
        y += delta / 2 + delta / 6.0f;
    }

    if (BattleCam_ModeX != BTL_CAM_MODEX_0) {
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
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->auxBoomZOffset = LERP(BattleCam_InitialBoomZOffset, BattleCam_BoomZOffset, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    camera->auxBoomLength = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength + extraLength, alpha);
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
    f32 alpha;
    f32 x, y, z;

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (isInitialCall) {
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
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

API_CALLABLE(BattleCamImpl_Default) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 0.0f;
        BattleCam_PosY = 60.0f;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomYaw = 0;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomZOffset = 0;
        if (BattleCam_SetImmediately) {
            camera->lookAt_obj_target.x = BattleCam_PosX;
            camera->lookAt_obj_target.y = BattleCam_PosY;
            camera->lookAt_obj_target.z = BattleCam_PosZ;
            camera->auxBoomZOffset = BattleCam_BoomZOffset;
            camera->auxBoomYaw = BattleCam_BoomYaw;
            camera->auxBoomPitch = BattleCam_BoomPitch;
            camera->auxBoomLength = BattleCam_BoomLength;
        }
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
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

ApiStatus CamPresetUpdate_D(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
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
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
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

ApiStatus CamPresetUpdate_E(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 35.0f;
        BattleCam_PosY = camera->lookAt_obj_target.y;
        if (BattleCam_PosY < 60.0f) {
            BattleCam_PosY = 60.0f;
        }
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomYaw = 0;
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
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

ApiStatus CamPresetUpdate_J(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        if (BattleCam_SetImmediately) {
            BattleCam_PosX = camera->lookAt_obj_target.x;
            BattleCam_PosY = camera->lookAt_obj_target.y;
            BattleCam_PosZ = camera->lookAt_obj_target.z;
        }
        BattleCam_InitialBoomLength = camera->auxBoomLength;
        BattleCam_InitialBoomPitch = camera->auxBoomPitch;
        BattleCam_InitialBoomYaw = camera->auxBoomYaw;
        BattleCam_InitialBoomZOffset = camera->auxBoomZOffset / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
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

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
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
        BattleCam_PosX = camera->lookAt_obj_target.x;
        BattleCam_PosY = camera->lookAt_obj_target.y;
        BattleCam_PosZ = camera->lookAt_obj_target.z;
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
            y = battleStatus->playerActor->curPos.y + (playerStatus->colliderHeight / 2);
            break;
        case ACTOR_CLASS_PARTNER:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->partnerActor->curPos.y;
            break;
        case ACTOR_CLASS_ENEMY:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->enemyActors[actorID]->curPos.y;
            break;
    }

    get_screen_coords(1, BattleCam_PosX, y, BattleCam_PosZ, &screenX, &screenY, &screenZ);

    if (screenY < 100) {
        y += 25.0f;
    }

    if (y < BattleCam_PosY) {
        y = BattleCam_PosY;
    }

    deltaY = y - camera->lookAt_obj_target.y;
    if (fabsf(deltaY) < 0.01) {
        if (deltaY != 0.0f) {
            camera->lookAt_obj_target.y = y;
        }
    } else {
        camera->lookAt_obj_target.y += deltaY / 5.0f;
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
    f32 delta;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            if (battleStatus->playerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->playerActor->curPos.x;
            y = battleStatus->playerActor->curPos.y + (playerStatus->colliderHeight / 2);
            z = battleStatus->playerActor->curPos.z;
            break;
        case ACTOR_CLASS_PARTNER:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->partnerActor->curPos.x;
            y = battleStatus->partnerActor->curPos.y;
            z = battleStatus->partnerActor->curPos.z;
            break;
        case ACTOR_CLASS_ENEMY:
        default:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->enemyActors[actorID]->curPos.x;
            y = battleStatus->enemyActors[actorID]->curPos.y;
            z = battleStatus->enemyActors[actorID]->curPos.z;
            break;
    }

    if (isInitialCall) {
        BattleCam_PosX = camera->lookAt_obj_target.x;
        BattleCam_PosY = camera->lookAt_obj_target.y;
        BattleCam_PosZ = camera->lookAt_obj_target.z;
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

    delta = x - camera->lookAt_obj_target.x;
    if (fabsf(delta) < 0.01) {
        if (delta != 0.0f) {
            camera->lookAt_obj_target.x = x;
        }
    } else {
        camera->lookAt_obj_target.x += delta / 5.0f;
    }

    delta = y - camera->lookAt_obj_target.y;
    if (fabsf(delta) < 0.01) {
        if (delta != 0.0f) {
            camera->lookAt_obj_target.y = y;
        }
    } else {
        camera->lookAt_obj_target.y += delta / 5.0f;
    }

    delta = z - camera->lookAt_obj_target.z;
    if (fabsf(delta) < 0.01) {
        if (delta != 0.0f) {
            camera->lookAt_obj_target.z = z;
        }
    } else {
        camera->lookAt_obj_target.z += delta / 5.0f;
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
    D_8029F288 = camera->auxPitch;
    BattleCam_InitialBoomLength = camera->auxBoomLength;
    BattleCam_InitialBoomPitch = camera->auxBoomPitch;
    BattleCam_InitialBoomZOffset = BattleCam_InitialBoomYaw = 0.0f;
    return ApiStatus_DONE2;
}

void btl_cam_use_preset_impl(s32 id) {
    BattleStatus* battleStatus = &gBattleStatus;
    EvtScript* preset = NULL;
    Evt* newScript;

    if (!BattleCam_IsFrozen) {
        D_8029F2A6 = TRUE;
        BattleCam_ModeY = BTL_CAM_MODEY_0;
        BattleCam_ModeX = BTL_CAM_MODEX_0;
        BattleCam_UseLinearInterp = FALSE;
        D_8029F2A7 = 0;

        switch (id) {
            case BTL_CAM_PRESET_00:
                preset = &CamPreset_A;
                break;
            case BTL_CAM_PRESET_01:
                preset = &CamPreset_B;
                break;
            case BTL_CAM_DEFAULT:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 500;
                BattleCam_MoveTimeLeft = 30;
                preset = &EVS_BattleCam_Default;
                break;
            case BTL_CAM_PRESET_03:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 480;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_D;
                break;
            case BTL_CAM_PRESET_04:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 500;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_E;
                break;
            case BTL_CAM_PRESET_05:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_06:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_G;
                break;
            case BTL_CAM_PRESET_07:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_H;
                break;
            case BTL_CAM_PRESET_08:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_09:
                if (BattleCam_ControlScript != &EVS_BattleCam_Default) {
                    BattleCam_BoomLength = 500;
                    BattleCam_MoveTimeLeft = 120;
                    preset = &EVS_BattleCam_Default;
                    break;
                }
                return;
            case BTL_CAM_PRESET_10:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 15;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_11:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_12:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_13:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 15;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_14:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_15:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_I;
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
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_H;
                break;
            case BTL_CAM_PRESET_19:
                BattleCam_MoveTimeLeft = 20;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PRESET_20:
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_K;
                break;
            case BTL_CAM_PRESET_21:
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                preset = &CamPreset_L;
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
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_IsFrozen = TRUE;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_VICTORY:
                BattleCam_BoomLength = 255;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 29;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                btl_cam_set_target_pos(-95.0f, 18.0f, 10.0f);
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PLAYER_ENTRY:
                BattleCam_BoomLength = 230;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_J;
                break;
            case BTL_CAM_PLAYER_ATTACK_APPROACH:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_27:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_28:
                BattleCam_BoomLength = 340;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PLAYER_HIT_SPIKE:
            case BTL_CAM_PLAYER_HIT_HAZARD:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomZOffset = -32;
                D_8029F2A7 = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PLAYER_CHARGE_UP:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomZOffset = 10;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -65.0f;
                BattleCam_PosY = 30.0f;
                preset = &CamPreset_N;
                break;
            case BTL_CAM_PLAYER_STATUS_AFFLICTED:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 24;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_34:
                BattleCam_BoomLength = 280;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
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
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_UseLinearInterp = TRUE;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_37:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_36:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_UseLinearInterp = TRUE;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_38:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_39:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_40:
                BattleCam_BoomLength = 360;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PLAYER;
                preset = &CamPreset_M;
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
            case BTL_CAM_PLAYER_AIM_HAMMER:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_ModeY = BTL_CAM_MODEY_MINUS_2;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PLAYER_HAMMER_STRIKE:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
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
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                preset = &CamPreset_N;
                break;
            case BTL_CAM_PRESET_46:
                BattleCam_BoomLength = 460;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 27;
                BattleCam_TargetActor = ACTOR_PLAYER;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                preset = &CamPreset_N;
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
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 17;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_PosX = -75.0f;
                BattleCam_PosY = 150.0f;
                BattleCam_PosZ = 0.0f;
                preset = &CamPreset_N;
                break;
            case BTL_CAM_PARTNER_APPROACH:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_48:
                BattleCam_BoomLength = 250;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomZOffset = 16;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_49:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomZOffset = 16;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_50:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_M;
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
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_53:
                BattleCam_BoomLength = 380;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PARTNER_INJURED:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = 24;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_BoomYaw = 0;
                D_8029F2A6 = FALSE;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_55:
                BattleCam_BoomLength = 210;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 10;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -95.0f;
                BattleCam_PosY = 22.0f;
                preset = &CamPreset_N;
                break;
            case BTL_CAM_PRESET_56:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomZOffset = -4;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_57:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_M;
                break;
            case BTL_CAM_PRESET_58:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomZOffset = 10;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 25.0f;
                BattleCam_PosY = 60.0f;
                preset = &CamPreset_N;
                break;
            case BTL_CAM_PRESET_59:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomZOffset = 11;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                D_8029F2A6 = FALSE;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_60:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                BattleCam_ModeY = BTL_CAM_MODEY_0;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_PRESET_61:
            case BTL_CAM_PRESET_62:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomZOffset = -32;
                D_8029F2A7 = 20;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                BattleCam_BoomYaw = 0;
                BattleCam_TargetActor = ACTOR_PARTNER;
                preset = &CamPreset_I;
                break;
            case BTL_CAM_ENEMY_APPROACH:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 27;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_64:
                BattleCam_BoomLength = 358;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_65:
                BattleCam_MoveTimeLeft = 50;
                BattleCam_BoomLength = 500;
                preset = &EVS_BattleCam_Default;
                break;
            case BTL_CAM_PRESET_66:
                BattleCam_BoomLength = 267;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_0;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_67:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
            case BTL_CAM_PRESET_68:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 4;
                BattleCam_BoomZOffset = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_ModeY = BTL_CAM_MODEY_1;
                BattleCam_ModeX = BTL_CAM_MODEX_1;
                preset = &CamPreset_F;
                break;
        }

        BattleCam_CurrentPresetID = id;

        if (battleStatus->camMovementScript != NULL) {
            kill_script_by_ID(battleStatus->camMovementScriptID);
        }

        BattleCam_ControlScript = preset;
        newScript = start_script(preset, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
        BattleCam_DoneMoving = FALSE;
        battleStatus->camMovementScript = newScript;
        battleStatus->camMovementScriptID = newScript->id;
    }
}

void btl_cam_use_preset_immediately(s32 preset) {
    if (!BattleCam_IsFrozen) {
        BattleCam_SetImmediately = TRUE;
        btl_cam_use_preset_impl(preset);
    }
}

void btl_cam_use_preset(s32 preset) {
    if (!BattleCam_IsFrozen) {
        BattleCam_SetImmediately = FALSE;
        btl_cam_use_preset_impl(preset);
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

void btl_cam_set_params(s16 arg0, s16 boomLength, s16 arg2, s16 boomPitch, s32 boomYaw, s32 boomZOffset, s32 arg6, s32 zoomPercent) {
    Camera* camera = &gCameras[CAM_BATTLE];

    if (!BattleCam_IsFrozen) {
        camera->auxPitch = arg0;
        camera->auxBoomLength = boomLength;
        camera->lookAt_dist = arg2;
        camera->auxBoomPitch = boomPitch;
        camera->auxBoomYaw = boomYaw;
        camera->auxBoomZOffset = boomZOffset * 256;
        camera->unk_28 = arg6;
        camera->zoomPercent = zoomPercent;
    }
}

void btl_cam_move(s16 moveTime) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (!BattleCam_IsFrozen) {
        BattleCam_MoveTimeLeft = moveTime;
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

void btl_cam_set_pos(f32 x, f32 y, f32 z) {
    Camera* camera = &gCameras[CAM_BATTLE];

    if (!BattleCam_IsFrozen) {
        camera->lookAt_obj_target.x = x;
        camera->lookAt_obj_target.y = y;
        camera->lookAt_obj_target.z = z;
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
    btl_cam_use_preset_impl(preset);

    return ApiStatus_DONE2;
}

ApiStatus UseBattleCamPresetImmediately(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 preset;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    preset = evt_get_variable(script, *args++);
    BattleCam_SetImmediately = TRUE;
    btl_cam_use_preset_impl(preset);

    return ApiStatus_DONE2;
}

ApiStatus UseBattleCamPresetWait(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            btl_cam_use_preset(evt_get_variable(script, *args++));
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

ApiStatus SetBattleCamParam(Evt* script, s32 isInitialCall) {
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
            camera->auxPitch = val;
            break;
        case AUX_CAM_BOOM_LENGTH:
            camera->auxBoomLength = val;
            break;
        case AUX_CAM_PARAM_3:
            camera->lookAt_dist = val;
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

ApiStatus SetBattleCamParams(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[CAM_BATTLE];

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    camera->auxPitch = evt_get_variable(script, *args++);
    camera->auxBoomLength = evt_get_variable(script, *args++);
    camera->lookAt_dist = evt_get_variable(script, *args++);
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

ApiStatus SetBattleCamPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[CAM_BATTLE];

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    camera->lookAt_obj_target.x = evt_get_variable(script, *args++);
    camera->lookAt_obj_target.y = evt_get_variable(script, *args++);
    camera->lookAt_obj_target.z = evt_get_variable(script, *args++);

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

    BattleCam_ModeY = evt_get_variable(script, *args++);
    BattleCam_ModeX = evt_get_variable(script, *args++);
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
