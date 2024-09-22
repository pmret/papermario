#include "common.h"
#include "script_api/battle.h"

#define LERP(a, b, alpha) ((a) * (alpha) + (b) * (1.0f-(alpha)))
#define CUBIC_SINE_INTERP(alpha) (1.0f - sin_rad(sin_rad(sin_rad((1.0f - alpha) * PI_S / 2) * PI_S / 2) * PI_S / 2))

static f32 BattleCam_PosX;
static f32 BattleCam_PosY;
static f32 BattleCam_PosZ;
static s16 BattleCam_SubjectActor;
static s16 BattleCam_SubjectActorPart;
static s16 BattleCam_BoomLength;
static s16 BattleCam_BoomYaw;
static s16 BattleCam_BoomPitch;
static s16 BattleCam_BoomOffsetY;
static f32 D_8029F288;
static f32 BattleCam_InitialBoomLength;
static f32 BattleCam_InitialBoomYaw;
static f32 BattleCam_InitialBoomPitch;
static f32 BattleCam_InitialBoomOffsetY;
static s8 BattleCam_DoneMoving;
static s16 BattleCam_MoveTimeLeft;
static s16 BattleCam_MoveTimeTotal;
static s8 BattleCam_AdjustTargetYMode;
static s8 BattleCam_AdjustTargetXMode;
static s8 BattleCam_SetImmediately;
static s8 BattleCam_UseLinearInterp;
static s8 BattleCam_ClampPosX;
static s8 BattleCam_ExtraOffsetX;
static f32 BattleCam_InitialPosX;
static f32 BattleCam_InitialPosY;
static f32 BattleCam_InitialPosZ;
static EvtScript* BattleCam_ControlScript;

s8 BattleCam_IsFrozen = FALSE;
s32 BattleCam_CurrentPresetID = -1;

API_CALLABLE(BattleCam_Update_Interrupt);
API_CALLABLE(BattleCam_Update_FocusMidpointA);
API_CALLABLE(BattleCam_Update_FocusMidpointB);
API_CALLABLE(BattleCam_Update_FocusActorPart);
API_CALLABLE(BattleCam_Update_FocusActor);
API_CALLABLE(BattleCam_Update_FocusGoal);
API_CALLABLE(BattleCam_Update_SimpleLerp_Unskippable);
API_CALLABLE(BattleCam_Update_ResetToNeutral_Skippable);
API_CALLABLE(BattleCam_Update_ViewAllEnemies);
API_CALLABLE(BattleCam_Update_ViewAllEnemies_MaintainY);
API_CALLABLE(BattleCam_Update_SimpleLerp_Skippable);
API_CALLABLE(BattleCam_Update_FollowActorY);
API_CALLABLE(BattleCam_Update_FollowActorPos);

EvtScript EVS_BattleCam_Interrupt = {
    Call(BattleCam_Update_Interrupt)
    Return
    End
};

EvtScript EVS_BattleCam_UnkF_Skippable = {
    Call(BattleCam_Update_FocusMidpointA)
    Return
    End
};

EvtScript EVS_BattleCam_UnkM_Skippable = {
    Call(BattleCam_Update_FocusMidpointB)
    Return
    End
};

EvtScript EVS_BattleCam_UnkG_Skippable = {
    Call(BattleCam_Update_FocusActorPart)
    Return
    End
};

EvtScript EVS_BattleCam_FocusActor = {
    Call(BattleCam_Update_FocusActor)
    Return
    End
};

EvtScript EVS_BattleCam_FocusGoal = {
    Call(BattleCam_Update_FocusGoal)
    Return
    End
};

EvtScript EVS_BattleCam_SimpleLerp_Unskippable = {
    Call(BattleCam_Update_SimpleLerp_Unskippable)
    Return
    End
};

EvtScript EVS_BattleCam_ResetNeutral = {
    Call(BattleCam_Update_ResetToNeutral_Skippable)
    Return
    End
};

EvtScript EVS_BattleCam_ViewEnemies = {
    Call(BattleCam_Update_ViewAllEnemies)
    Return
    End
};

EvtScript EVS_BattleCam_ViewEnemies_MaintainY = {
    Call(BattleCam_Update_ViewAllEnemies_MaintainY)
    Return
    End
};

EvtScript EVS_BattleCam_SimpleLerp_Skippable = {
    Call(BattleCam_Update_SimpleLerp_Skippable)
    Return
    End
};

EvtScript EVS_BattleCam_FollowActorY = {
    Call(BattleCam_Update_FollowActorY)
    Return
    End
};

EvtScript EVS_BattleCam_FollowActorPos = {
    Call(BattleCam_Update_FollowActorPos)
    Return
    End
};

EvtScript EVS_BattleCam_Reset = {
    Call(ForceBattleCamTarget, 0, 15, 0)
    Call(SetBattleCamParam, CAM_PARAM_BOOM_LENGTH, 550)
    Call(SetBattleCamParam, CAM_PARAM_FOV_SCALE, 100)
    Call(SetBattleCamParam, CAM_PARAM_BOOM_PITCH, 8)
    Return
    End
};

EvtScript EVS_OnBattleInit = {
    Call(SetCamPerspective, CAM_BATTLE, CAM_UPDATE_NO_INTERP, 25, 16, 1024)
    Call(SetCamViewport, CAM_BATTLE, 12, 20, 296, 200)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetCamEnabled, CAM_BATTLE, TRUE)
    Wait(1)
    Call(InitVirtualEntityList)
    Call(InitAnimatedModels)
    Call(SetInterpCamParams, CAM_BATTLE, 0, 240, 100, 8)
    Call(SetCamLookTarget, CAM_BATTLE, -75, 35, 0)
    Call(BattleCamTargetActor, 0)
    Call(BattleCam_Init)
    Return
    End
};

API_CALLABLE(BattleCam_Update_Interrupt) {
    BattleCam_DoneMoving = TRUE;
    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FocusMidpointA) {
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
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;

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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_MINUS_1) {
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_AdjustTargetYMode == BTL_CAM_MODEY_MINUS_1) {
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

    if (BattleCam_ClampPosX) {
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
            camera->params.basic.dist = BattleCam_BoomLength;
            camera->params.basic.offsetY = BattleCam_BoomOffsetY * 256;
            camera->params.basic.yaw = BattleCam_BoomYaw;
            camera->params.basic.pitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
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
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;

    dist = dist2D(camera->lookAt_obj_target.x, camera->lookAt_obj_target.z, middlePosX, middlePosZ);
    adjustedSize = (averageSize + targetAverageSize) / 8;
    extraLength = dist + adjustedSize - 64.0f;
    distToTarget = dist3D(x, y, z, targetX, targetY, targetZ);
    boomLength = BattleCam_BoomLength + extraLength + distToTarget * 0.5f;

    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FocusMidpointB) {
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
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;

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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_MINUS_1) {
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
                    middlePosY = targetY + (y - targetY) * 0.5f + (y - targetY) / 6.0f;
                } else {
                    middlePosY = y;
                }
            } else {
                if (BattleCam_AdjustTargetYMode == BTL_CAM_MODEY_MINUS_1) {
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

    if (BattleCam_ClampPosX) {
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
            camera->params.basic.dist = BattleCam_BoomLength;
            camera->params.basic.offsetY = BattleCam_BoomOffsetY * 256;
            camera->params.basic.yaw = BattleCam_BoomYaw;
            camera->params.basic.pitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
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
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;

    dist = dist2D(camera->lookAt_obj_target.x, camera->lookAt_obj_target.z, middlePosX, middlePosZ);
    extraLength = dist + averageSize + targetAverageSize - 64.0f;
    distToTarget = dist3D(x, y, z, targetX, targetY, targetZ);
    boomLength = BattleCam_BoomLength + extraLength + distToTarget * 0.5f;

    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, boomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FocusActorPart) {
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
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;

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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
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
            actorPart = get_actor_part(targetActor, BattleCam_SubjectActorPart);
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
            if (BattleCam_AdjustTargetYMode > BTL_CAM_MODEY_MINUS_1) {
                if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
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

    if (BattleCam_ClampPosX) {
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
            camera->params.basic.dist = BattleCam_BoomLength;
            camera->params.basic.offsetY = BattleCam_BoomOffsetY * 256;
            camera->params.basic.yaw = BattleCam_BoomYaw;
            camera->params.basic.pitch = BattleCam_BoomPitch;
        }

        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
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
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;

    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FocusActor) {
    Actor* actor;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 sizeX, sizeY;
    f32 averageSize, targetAverageSize;
    f32 alpha;
    f32 extraLength;
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;

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

    if (BattleCam_ClampPosX) {
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
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    if (BattleCam_AdjustTargetXMode != BTL_CAM_MODEX_0) {
        camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x + BattleCam_ExtraOffsetX, alpha);
    }
    if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
        camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    }
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength + extraLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FocusGoal) {
    Actor* actor;
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 currentX, currentY;
    f32 averageSize;
    f32 alpha;
    f32 extraLength;
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;

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

    if (BattleCam_AdjustTargetYMode != BTL_CAM_MODEY_0) {
        f32 delta = currentY - y;
        y += delta / 2 + delta / 6.0f;
    }

    if (BattleCam_AdjustTargetXMode != BTL_CAM_MODEX_0) {
        x += (currentX - x) / 2;
        if (x > 75.0f) {
            x -= fabsf(75.0f - x);
        }
    }

    if (BattleCam_ClampPosX) {
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
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);

    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    extraLength = averageSize - 32.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength + extraLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_SimpleLerp_Unskippable) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    x = BattleCam_PosX;
    y = BattleCam_PosY;
    z = BattleCam_PosZ;

    if (isInitialCall) {
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
        BattleCam_InitialPosX = camera->lookAt_obj_target.x;
        BattleCam_InitialPosY = camera->lookAt_obj_target.y;
        BattleCam_InitialPosZ = camera->lookAt_obj_target.z;
        BattleCam_MoveTimeTotal = BattleCam_MoveTimeLeft;
    }

    if (!BattleCam_UseLinearInterp) {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_ResetToNeutral_Skippable) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 0.0f;
        BattleCam_PosY = 60.0f;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomYaw = 0;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomOffsetY = 0;
        if (BattleCam_SetImmediately) {
            camera->lookAt_obj_target.x = BattleCam_PosX;
            camera->lookAt_obj_target.y = BattleCam_PosY;
            camera->lookAt_obj_target.z = BattleCam_PosZ;
            camera->params.basic.offsetY = BattleCam_BoomOffsetY;
            camera->params.basic.yaw = BattleCam_BoomYaw;
            camera->params.basic.pitch = BattleCam_BoomPitch;
            camera->params.basic.dist = BattleCam_BoomLength;
        }
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
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
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_ViewAllEnemies) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        BattleCam_PosX = 35.0f;
        BattleCam_PosY = 60.0f;
        BattleCam_PosZ = 0.0f;
        BattleCam_BoomPitch = 8;
        BattleCam_BoomYaw = 0;

        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
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
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_ViewAllEnemies_MaintainY) {
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
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
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
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_SimpleLerp_Skippable) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 alpha;
    f32 x, y, z;

    if (isInitialCall) {
        if (BattleCam_SetImmediately) {
            BattleCam_PosX = camera->lookAt_obj_target.x;
            BattleCam_PosY = camera->lookAt_obj_target.y;
            BattleCam_PosZ = camera->lookAt_obj_target.z;
        }
        BattleCam_InitialBoomLength = camera->params.basic.dist;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomOffsetY = camera->params.basic.offsetY / 256;
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
        alpha = CUBIC_SINE_INTERP(alpha);
    } else {
        alpha = BattleCam_MoveTimeLeft;
        alpha /= BattleCam_MoveTimeTotal;
    }

    camera->lookAt_obj_target.x = LERP(BattleCam_InitialPosX, x, alpha);
    camera->lookAt_obj_target.y = LERP(BattleCam_InitialPosY, y, alpha);
    camera->lookAt_obj_target.z = LERP(BattleCam_InitialPosZ, z, alpha);
    camera->params.basic.offsetY = LERP(BattleCam_InitialBoomOffsetY, BattleCam_BoomOffsetY, alpha) * 256.0f;
    camera->params.basic.dist = LERP(BattleCam_InitialBoomLength, BattleCam_BoomLength, alpha);
    camera->params.basic.yaw = LERP(BattleCam_InitialBoomYaw, BattleCam_BoomYaw, alpha);
    camera->params.basic.pitch = LERP(BattleCam_InitialBoomPitch, BattleCam_BoomPitch, alpha);

    if (BattleCam_MoveTimeLeft == 0) {
        BattleCam_DoneMoving = TRUE;
    } else {
        BattleCam_MoveTimeLeft--;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleCam_Update_FollowActorY) {
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
        D_8029F288 = camera->params.basic.dist;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
    }

    y = 0.0f;
    actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    actorID = BattleCam_SubjectActor & 0xFF;

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

    get_screen_coords(CAM_BATTLE, BattleCam_PosX, y, BattleCam_PosZ, &screenX, &screenY, &screenZ);

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

API_CALLABLE(BattleCam_Update_FollowActorPos) {
    Camera* camera = &gCameras[CAM_BATTLE];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actorClass = BattleCam_SubjectActor & ACTOR_CLASS_MASK;
    s32 actorID = BattleCam_SubjectActor & 0xFF;
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
        D_8029F288 = camera->params.basic.dist;
        BattleCam_InitialBoomYaw = camera->params.basic.yaw;
        BattleCam_InitialBoomPitch = camera->params.basic.pitch;
    }

    get_screen_coords(CAM_BATTLE, x, y, z, &screenX, &screenY, &screenZ);

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

API_CALLABLE(BattleCam_Init) {
    Camera* camera = &gCameras[CAM_BATTLE];

    BattleCam_BoomPitch = 8;
    camera->params.basic.yaw = 0;
    camera->params.basic.offsetY = 0;
    BattleCam_BoomYaw = BattleCam_BoomOffsetY = 0;
    BattleCam_IsFrozen = FALSE;
    D_8029F288 = camera->params.basic.skipRecalc;
    BattleCam_InitialBoomLength = camera->params.basic.dist;
    BattleCam_InitialBoomPitch = camera->params.basic.pitch;
    BattleCam_InitialBoomOffsetY = BattleCam_InitialBoomYaw = 0.0f;
    return ApiStatus_DONE2;
}

void btl_cam_use_preset_impl(s32 id) {
    BattleStatus* battleStatus = &gBattleStatus;
    EvtScript* preset = NULL;
    Evt* newScript;

    if (!BattleCam_IsFrozen) {
        BattleCam_ClampPosX = TRUE;
        BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
        BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
        BattleCam_UseLinearInterp = FALSE;
        BattleCam_ExtraOffsetX = 0;

        switch (id) {
            case BTL_CAM_PRESET_00:
                preset = &EVS_BattleCam_Reset;
                break;
            case BTL_CAM_PRESET_01:
                preset = &EVS_BattleCam_Interrupt;
                break;
            case BTL_CAM_DEFAULT:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 500;
                BattleCam_MoveTimeLeft = 30;
                preset = &EVS_BattleCam_ResetNeutral;
                break;
            case BTL_CAM_PRESET_03:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 480;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_ViewEnemies;
                break;
            case BTL_CAM_PRESET_04:
                if (BattleCam_CurrentPresetID == id) {
                    return;
                }
                BattleCam_BoomLength = 500;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_ViewEnemies_MaintainY;
                break;
            case BTL_CAM_PRESET_05:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_06:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkG_Skippable;
                break;
            case BTL_CAM_PRESET_07:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                preset = &EVS_BattleCam_FocusGoal;
                break;
            case BTL_CAM_PRESET_08:
                BattleCam_BoomLength = 300;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_09:
                if (BattleCam_ControlScript != &EVS_BattleCam_ResetNeutral) {
                    BattleCam_BoomLength = 500;
                    BattleCam_MoveTimeLeft = 120;
                    preset = &EVS_BattleCam_ResetNeutral;
                    break;
                }
                return;
            case BTL_CAM_PRESET_10:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 15;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_11:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_12:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_13:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 15;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_14:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_15:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_16:
                BattleCam_BoomLength = 267;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 23;
                preset = &EVS_BattleCam_FocusGoal;
                break;
            case BTL_CAM_PRESET_17:
                BattleCam_BoomLength = 300;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 8;
                preset = &EVS_BattleCam_FocusGoal;
                break;
            case BTL_CAM_PRESET_18:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_FocusGoal;
                break;
            case BTL_CAM_PRESET_19:
                BattleCam_MoveTimeLeft = 20;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PRESET_20:
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_FollowActorY;
                break;
            case BTL_CAM_PRESET_21:
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_FollowActorPos;
                break;
            case BTL_CAM_PRESET_25:
                BattleCam_BoomLength = 266;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 40;
                btl_cam_set_target_pos(-80.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 20;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PRESET_24:
                BattleCam_BoomLength = 250;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 14;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_IsFrozen = TRUE;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_VICTORY:
                BattleCam_BoomLength = 255;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 29;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                btl_cam_set_target_pos(-95.0f, 18.0f, 10.0f);
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PLAYER_ENTRY:
                BattleCam_BoomLength = 230;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PLAYER_ATTACK_APPROACH:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_27:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_28:
                BattleCam_BoomLength = 340;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PLAYER_HIT_SPIKE:
            case BTL_CAM_PLAYER_HIT_HAZARD:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomOffsetY = -32;
                BattleCam_ExtraOffsetX = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PLAYER_CHARGE_UP:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomOffsetY = 10;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -65.0f;
                BattleCam_PosY = 30.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PLAYER_STATUS_AFFLICTED:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = 24;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_34:
                BattleCam_BoomLength = 280;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_35:
                BattleCam_BoomLength = 380;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_37:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_36:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_38:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_39:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_40:
                BattleCam_BoomLength = 360;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = -4;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_41:
            case BTL_CAM_PRESET_42:
                BattleCam_BoomLength = 200;
                BattleCam_MoveTimeLeft = 7;
                BattleCam_MoveTimeTotal = 7;
                BattleCam_DoneMoving = FALSE;
                BattleCam_ClampPosX = FALSE;
                preset = BattleCam_ControlScript;
                break;
            case BTL_CAM_PLAYER_AIM_HAMMER:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 16;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_MINUS_2;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PLAYER_HAMMER_STRIKE:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_45:
                BattleCam_BoomLength = 430;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 16;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PRESET_46:
                BattleCam_BoomLength = 460;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 27;
                BattleCam_SubjectActor = ACTOR_PLAYER;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 60.0f;
                BattleCam_PosY = 40.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PRESET_70:
                BattleCam_BoomLength = 390;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 45;
                btl_cam_set_target_pos(-70.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 10;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PRESET_71:
                BattleCam_BoomLength = 500;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 45;
                btl_cam_set_target_pos(0.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 40;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PRESET_69:
            case BTL_CAM_PRESET_72:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 45;
                btl_cam_set_target_pos(-50.0f, 0.0f, 0.0f);
                BattleCam_MoveTimeLeft = 20;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_SimpleLerp_Skippable;
                break;
            case BTL_CAM_PRESET_73:
                BattleCam_BoomLength = 166;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 17;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_PosX = -75.0f;
                BattleCam_PosY = 150.0f;
                BattleCam_PosZ = 0.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PARTNER_APPROACH:
                BattleCam_BoomLength = 310;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_48:
                BattleCam_BoomLength = 250;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomOffsetY = 16;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_49:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 120;
                BattleCam_BoomOffsetY = 16;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_50:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 5;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_29:
            case BTL_CAM_PRESET_51:
                BattleCam_MoveTimeLeft = 50;
                BattleCam_BoomLength = 500;
                BattleCam_BoomOffsetY = 0;
                preset = &EVS_BattleCam_ViewEnemies;
                break;
            case BTL_CAM_PRESET_52:
                BattleCam_BoomLength = 280;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = -4;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_53:
                BattleCam_BoomLength = 380;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PARTNER_INJURED:
                BattleCam_BoomLength = 220;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = 24;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_BoomYaw = 0;
                BattleCam_ClampPosX = FALSE;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_55:
                BattleCam_BoomLength = 210;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 10;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = -95.0f;
                BattleCam_PosY = 22.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PRESET_56:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomOffsetY = -4;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_57:
                BattleCam_BoomLength = 320;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_UnkM_Skippable;
                break;
            case BTL_CAM_PRESET_58:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 30;
                BattleCam_BoomYaw = 0;
                BattleCam_BoomOffsetY = 10;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                BattleCam_PosZ = 0.0f;
                BattleCam_PosX = 25.0f;
                BattleCam_PosY = 60.0f;
                preset = &EVS_BattleCam_SimpleLerp_Unskippable;
                break;
            case BTL_CAM_PRESET_59:
                BattleCam_BoomLength = 200;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 60;
                BattleCam_BoomOffsetY = 11;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_UseLinearInterp = TRUE;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                BattleCam_ClampPosX = FALSE;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_60:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 8;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_0;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_PRESET_61:
            case BTL_CAM_PRESET_62:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 15;
                BattleCam_BoomOffsetY = -32;
                BattleCam_ExtraOffsetX = 20;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                BattleCam_BoomYaw = 0;
                BattleCam_SubjectActor = ACTOR_PARTNER;
                preset = &EVS_BattleCam_FocusActor;
                break;
            case BTL_CAM_ENEMY_APPROACH:
                BattleCam_BoomLength = 400;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 27;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_64:
                BattleCam_BoomLength = 358;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 10;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_65:
                BattleCam_MoveTimeLeft = 50;
                BattleCam_BoomLength = 500;
                preset = &EVS_BattleCam_ResetNeutral;
                break;
            case BTL_CAM_PRESET_66:
                BattleCam_BoomLength = 267;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_0;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_67:
                BattleCam_BoomLength = 214;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 20;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
                break;
            case BTL_CAM_PRESET_68:
                BattleCam_BoomLength = 300;
                BattleCam_BoomPitch = 8;
                BattleCam_MoveTimeLeft = 4;
                BattleCam_BoomOffsetY = 16;
                BattleCam_BoomYaw = 0;
                BattleCam_AdjustTargetYMode = BTL_CAM_MODEY_1;
                BattleCam_AdjustTargetXMode = BTL_CAM_MODEX_1;
                preset = &EVS_BattleCam_UnkF_Skippable;
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
        BattleCam_SubjectActor = actorID;
    }
}

void btl_cam_target_actor_part(s32 actorID, s32 actorPartIndex) {
    if (!BattleCam_IsFrozen) {
        BattleCam_SubjectActor = actorID;
        BattleCam_SubjectActorPart = actorPartIndex;
    }
}

void btl_cam_set_params(b16 skipRecalc, s16 dist, s16 fovScale, s16 pitch, s32 yaw, s32 offsetY, s32 unkParam7, s32 zoomPercent) {
    Camera* camera = &gCameras[CAM_BATTLE];

    if (!BattleCam_IsFrozen) {
        camera->params.basic.skipRecalc = skipRecalc;
        camera->params.basic.dist = dist;
        camera->params.basic.fovScale = fovScale;
        camera->params.basic.pitch = pitch;
        camera->params.basic.yaw = yaw;
        camera->params.basic.offsetY = offsetY * 256;
        camera->params.basic.camParam7 = unkParam7;
        camera->params.basic.zoomPercent = zoomPercent;
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
        BattleCam_BoomOffsetY = zOffset;
    }
}

void btl_cam_unfreeze(void) {
    BattleCam_IsFrozen = FALSE;
}

void btl_cam_disable_clamp_x(void) {
    BattleCam_ClampPosX = FALSE;
}

API_CALLABLE(UseBattleCamPreset) {
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

API_CALLABLE(UseBattleCamPresetImmediately) {
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

API_CALLABLE(UseBattleCamPresetWait) {
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

API_CALLABLE(SetBattleCamParam) {
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
        case CAM_PARAM_SKIP_RECALC:
            camera->params.basic.skipRecalc = val;
            break;
        case CAM_PARAM_BOOM_LENGTH:
            camera->params.basic.dist = val;
            break;
        case CAM_PARAM_FOV_SCALE:
            camera->params.basic.fovScale = val;
            break;
        case CAM_PARAM_BOOM_PITCH:
            camera->params.basic.pitch = val;
            break;
        case CAM_PARAM_BOOM_YAW:
            camera->params.basic.yaw = val;
            break;
        case CAM_PARAM_BOOM_Y_OFFSET:
            camera->params.basic.offsetY = val * 256;
            break;
        case CAM_PARAM_UNK_7:
            camera->params.basic.camParam7 = val;
            break;
        case CAM_PARAM_ZOOM_PERCENT:
            camera->params.basic.zoomPercent = val;
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleCamParams) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[CAM_BATTLE];

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    camera->params.basic.skipRecalc = evt_get_variable(script, *args++);
    camera->params.basic.dist = evt_get_variable(script, *args++);
    camera->params.basic.fovScale = evt_get_variable(script, *args++);
    camera->params.basic.pitch = evt_get_variable(script, *args++);
    camera->params.basic.yaw = evt_get_variable(script, *args++);
    camera->params.basic.offsetY = evt_get_variable(script, *args++) * 256;
    camera->params.basic.camParam7 = evt_get_variable(script, *args++);
    camera->params.basic.zoomPercent = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleCamTarget) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_PosX = evt_get_variable(script, *args++);
    BattleCam_PosY = evt_get_variable(script, *args++);
    BattleCam_PosZ = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(ForceBattleCamTarget) {
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

API_CALLABLE(SetBattleCamOffsetY) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomOffsetY = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(AddBattleCamOffsetY) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomOffsetY += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleCamYaw) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomYaw = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(BattleCamTargetActor) {
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

API_CALLABLE(BattleCamTargetActorPart) {
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

API_CALLABLE(MoveBattleCamOver) {
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

API_CALLABLE(SetBattleCamDist) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomLength = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(AddBattleCamDist) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_BoomLength += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleCamTargetingModes) {
    Bytecode* args = script->ptrReadPos;

    if (BattleCam_IsFrozen) {
        return ApiStatus_DONE2;
    }

    BattleCam_AdjustTargetYMode = evt_get_variable(script, *args++);
    BattleCam_AdjustTargetXMode = evt_get_variable(script, *args++);
    BattleCam_UseLinearInterp = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(FreezeBattleCam) {
    BattleCam_IsFrozen = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(DisableBattleCamClampX) {
    BattleCam_ClampPosX = FALSE;
    return ApiStatus_DONE2;
}
