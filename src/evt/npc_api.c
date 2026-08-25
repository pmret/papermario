#include "common.h"
#include "npc.h"
#include "world/partners.h"

extern s32 wExtraPartnerID;
extern s32 wExtraPartnerNpcID;

Npc* resolve_npc(Evt* script, s32 npcIdOrPtr) {
    if (npcIdOrPtr == NPC_SELF) {
        return get_npc_safe(script->owner2.npcID);
    } else if (npcIdOrPtr >= EVT_LIMIT) {
        return get_npc_safe(npcIdOrPtr);
    } else {
        return (Npc*) npcIdOrPtr;
    }
}

void set_npc_animation(Npc* npc, u32 animID) {
    PlayerData* playerData = &gPlayerData;

    if (PARTNER_ANIM_STILL <= animID && animID <= PARTNER_ANIM_HURT) {
        npc->curAnim = gPartnerAnimations[playerData->curPartner].anims[animID - PARTNER_ANIM_STILL];
    } else if (ENEMY_ANIM_IDLE <= animID && animID <= ENEMY_ANIM_F) {
        npc->curAnim = get_enemy(npc->npcID)->animList[animID - ENEMY_ANIM_IDLE];
    } else {
        npc->curAnim = animID;
    }
}

API_CALLABLE(CreateNpc) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 initialAnim = evt_get_variable(script, *args++);
    NpcBlueprint blueprint;
    Npc *npc;

    blueprint.flags = 0;
    blueprint.initialAnim = initialAnim;
    blueprint.onUpdate = nullptr;
    blueprint.onRender = nullptr;

    npc = get_npc_by_index(create_basic_npc(&blueprint));
    npc->npcID = npcID;
    disable_npc_shadow(npc);
    return ApiStatus_DONE2;
}

API_CALLABLE(DeleteNpc) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(evt_get_variable(script, *args++));

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    free_npc(npc);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetNpcPointer) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode varNPC = *args++;

    evt_set_variable(script, varNPC, (s32)get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcPos) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = x;
    npc->pos.y = y;
    npc->pos.z = z;
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.y = npc->pos.y;
    npc->colliderPos.z = npc->pos.z;
    npc->flags |= NPC_FLAG_DIRTY_SHADOW;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcRotation) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 rotX = evt_get_float_variable(script, *args++);
    f32 rotY = evt_get_float_variable(script, *args++);
    f32 rotZ = evt_get_float_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->rot.x = rotX;
    npc->rot.y = rotY;
    npc->rot.z = rotZ;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcRotationPivot) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    f32 value = evt_get_float_variable(script, *args++);
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->rotPivotOffsetY = value;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcScale) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 scaleX = evt_get_float_variable(script, *ptrReadPos++);
    f32 scaleY = evt_get_float_variable(script, *ptrReadPos++);
    f32 scaleZ = evt_get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->scale.x = scaleX;
    npc->scale.y = scaleY;
    npc->scale.z = scaleZ;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcCollisionSize) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 height = evt_get_variable(script, *ptrReadPos++);
    s32 radius = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->collisionHeight = height;
    npc->collisionDiameter = radius;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcSpeed) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 speed = evt_get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->moveSpeed = speed;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcJumpscale) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 jumpScale = evt_get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcAnimation) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 animation = evt_get_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    set_npc_animation(npc, animation);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetNpcAnimation) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outVar, npc->curAnim);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcAnimationSpeed) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 animationSpeed = evt_get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->animationSpeed = animationSpeed;
    return ApiStatus_DONE2;
}

API_CALLABLE(NpcMoveTo) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;
    f32 dist;
    f32 moveSpeed;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 npcID = evt_get_variable(script, *args++);
        f32 goalX = evt_get_variable(script, *args++);
        f32 goalZ = evt_get_variable(script, *args++);
        s32 duration = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == nullptr) {
            return ApiStatus_DONE2;
        }

        script->functionTempPtr[1] = npc;
        npc->moveToPos.x = goalX;
        npc->moveToPos.z = goalZ;
        npc->duration = duration;
        dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);

        if (npc->duration == 0) {
            npc->duration = dist / npc->moveSpeed;
        } else {
            npc->moveSpeed = dist / npc->duration;
        }
        if (npc->duration == 0) {
            npc->duration = 1;
        }
        script->functionTemp[0] = 1;
    }

    npc = script->functionTempPtr[1];
    npc->yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->moveSpeed < 4.0) {
        npc_surface_spawn_fx(npc, SURFACE_INTERACT_WALK);
    } else {
        npc_surface_spawn_fx(npc, SURFACE_INTERACT_RUN);
    }

    dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);

    moveSpeed = npc->moveSpeed;
    if (moveSpeed < 1.0) {
        moveSpeed = 1.0f;
    }

    if (dist <= moveSpeed) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus _npc_jump_to(Evt* script, s32 isInitialCall, s32 snapYaw) {
    Bytecode* args = script->ptrReadPos;
    f32* yaw = &script->functionTempF[2];
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 npcID = evt_get_variable(script, *args++);
        f32 goalX = evt_get_variable(script, *args++);
        f32 goalY = evt_get_variable(script, *args++);
        f32 goalZ = evt_get_variable(script, *args++);
        s32 duration = evt_get_variable(script, *args++);
        f32 dist;

        npc = resolve_npc(script, npcID);

        if (npc == nullptr) {
            return ApiStatus_DONE2;
        }

        script->functionTempPtr[1] = npc;
        npc->moveToPos.x = goalX;
        npc->moveToPos.y = goalY;
        npc->moveToPos.z = goalZ;

        npc->duration = duration;
        dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
        *yaw = 0.0f;
        if (dist > 2.0) {
            *yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
            if (snapYaw == 0) {
                npc->yaw = *yaw;
            }
        }

        goalY = npc->moveToPos.y - npc->pos.y;

        if (npc->duration == 0) {
            npc->duration = dist / npc->moveSpeed;
        } else {
            npc->moveSpeed = dist / npc->duration;
        }

        npc->flags |= NPC_FLAG_JUMPING;
        npc->jumpVel = (npc->jumpScale * npc->duration * 0.5f) + (goalY / npc->duration);
        script->functionTemp[0] =1;
    }

    npc = script->functionTempPtr[1];
    npc_move_heading(npc, npc->moveSpeed, *yaw);

    npc->pos.y += npc->jumpVel;
    npc->jumpVel -= npc->jumpScale;

    npc->duration--;
    if (npc->duration < 0) {
        npc->jumpVel = 0.0f;
        npc->pos.x = npc->moveToPos.x;
        npc->pos.y = npc->moveToPos.y;
        npc->pos.z = npc->moveToPos.z;
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc_surface_spawn_fx(npc, SURFACE_INTERACT_LAND);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(NpcJump0) {
    return _npc_jump_to(script, isInitialCall, 0);
}

API_CALLABLE(NpcJump1) {
    return _npc_jump_to(script, isInitialCall, 1);
}

API_CALLABLE(NpcFlyTo) {
    Bytecode* args = script->ptrReadPos;
    f32* outX = (f32*)&script->varTable[3];
    f32* outY = (f32*)&script->varTable[4];
    f32* outZ = (f32*)&script->varTable[5];
    Npc* npc;
    f32 dist;
    f32 yDelta;

    if (isInitialCall) {
        npc = resolve_npc(script, evt_get_variable(script, *args++));
        if (npc == nullptr) {
            return ApiStatus_DONE2;
        }

        script->functionTempPtr[1] = npc;
        npc->moveToPos.x = evt_get_float_variable(script, *args++);
        npc->moveToPos.y = evt_get_float_variable(script, *args++);
        npc->moveToPos.z = evt_get_float_variable(script, *args++);
        script->varTable[6] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
        npc->duration = 0;
        *outX = npc->pos.x;
        *outY = npc->pos.y;
        *outZ = npc->pos.z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
        dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
        npc->planarFlyDist = dist;

        if (script->varTable[6] == 0) {
            script->varTable[6] = (dist / npc->moveSpeed);
        } else {
            npc->moveSpeed = dist / script->varTable[6];
        }
    }

    npc = script->functionTempPtr[1];
    npc->pos.x = update_lerp(script->functionTemp[3], *outX, npc->moveToPos.x, npc->duration, script->varTable[6]);
    npc->pos.y = update_lerp(script->functionTemp[3], *outY, npc->moveToPos.y, npc->duration, script->varTable[6]);
    npc->pos.z = update_lerp(script->functionTemp[3], *outZ, npc->moveToPos.z, npc->duration, script->varTable[6]);

    npc->duration++;
    if (npc->duration >= script->varTable[6]) {
        npc->pos.x = npc->moveToPos.x;
        npc->pos.y = npc->moveToPos.y;
        npc->pos.z = npc->moveToPos.z;
        return ApiStatus_DONE2;
    }

    dist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
    if (dist == 0.0f) {
        dist = 1.0f;
    }
    if (npc->planarFlyDist == 0.0f) {
        npc->planarFlyDist = 1.0f;
    }

    yDelta = sin_deg((1.0 - (dist / npc->planarFlyDist)) * 180.0);
    if (script->functionTemp[2] == 0) {
        yDelta = 0.0f;
    }
    if (script->functionTemp[2] < 0) {
        yDelta = -yDelta * -script->functionTemp[2];
    }
    if (script->functionTemp[2] > 0) {
        yDelta *= script->functionTemp[2];
    }
    npc->pos.y += yDelta;
    return ApiStatus_BLOCK;
}

API_CALLABLE(GetNpcYaw) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outVar, clamp_angle(npc->yaw));
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcYaw) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    set_npc_yaw(npc, evt_get_variable(script, *ptrReadPos++));
    return ApiStatus_DONE2;
}

API_CALLABLE(InterpNpcYaw) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* npc;

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == nullptr) {
            return ApiStatus_DONE2;
        }

        *initialYaw = npc->yaw;
        *deltaYaw = evt_get_variable(script, *args++) - *initialYaw;
        script->functionTempPtr[0] = npc;
        *turnTime = evt_get_variable(script, *args++);

        if (*turnTime == 0) {
            npc->yaw += *deltaYaw;
            return ApiStatus_DONE2;
        }

        npc->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    npc = script->functionTempPtr[0];
    if (*turnTime > 0) {
        npc->duration++;
        npc->yaw = *initialYaw + ((*deltaYaw * npc->duration) / *turnTime);
        npc->yaw = clamp_angle(npc->yaw);
        return !(npc->duration < *turnTime) * ApiStatus_DONE1;
    }

    npc->yaw += *deltaYaw;
    return ApiStatus_DONE2;
}

API_CALLABLE(NpcFacePlayer) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* npc;

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == nullptr) {
            return ApiStatus_DONE2;
        }

        *initialYaw = npc->yaw;
        *deltaYaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) - *initialYaw;
        script->functionTempPtr[0] = npc;
        *turnTime = evt_get_variable(script, *args++);
        npc->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    npc = script->functionTempPtr[0];
    if (*turnTime > 0) {
        npc->duration++;
        npc->yaw = *initialYaw + ((*deltaYaw * npc->duration) / *turnTime);
        npc->yaw = clamp_angle(npc->yaw);
        return !(npc->duration < *turnTime) * ApiStatus_DONE1;
    }

    npc->yaw += *deltaYaw;
    return ApiStatus_DONE2;
}

API_CALLABLE(NpcFaceNpc) {
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* targetNpc;
    Npc* turningNpc;

    if (isInitialCall) {
        s32 turningNpcID = evt_get_variable(script, *args++);
        s32 targetNpcID = evt_get_variable(script, *args++);

        targetNpc = resolve_npc(script, targetNpcID);
        if (targetNpc == nullptr) {
            return ApiStatus_DONE2;
        }

        turningNpc = resolve_npc(script, turningNpcID);
        if (turningNpc == nullptr) {
            return ApiStatus_DONE2;
        }

        *initialYaw = turningNpc->yaw;
        *deltaYaw = atan2(turningNpc->pos.x, turningNpc->pos.z, targetNpc->pos.x, targetNpc->pos.z) - *initialYaw;
        script->functionTempPtr[0] = turningNpc;
        *turnTime = evt_get_variable(script, *args++);
        turningNpc->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    turningNpc = script->functionTempPtr[0];
    if (*turnTime > 0) {
        turningNpc->duration++;
        turningNpc->yaw = *initialYaw + ((*deltaYaw * turningNpc->duration) / *turnTime);
        turningNpc->yaw = clamp_angle(turningNpc->yaw);
        return !(turningNpc->duration < *turnTime) * ApiStatus_DONE1;
    }

    turningNpc->yaw += *deltaYaw;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcFlagBits) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    if (mode) {
        npc->flags |= bits;
    } else {
        npc->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetNpcPos) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outX, npc->pos.x);
    evt_set_variable(script, outY, npc->pos.y);
    evt_set_variable(script, outZ, npc->pos.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcCollisionChannel) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode channel = *args;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->collisionChannel = channel;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcSprite) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode animID = *args;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    set_npc_sprite(npc, animID, nullptr);
    return ApiStatus_DONE2;
}

API_CALLABLE(EnableNpcShadow) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 enableShadow = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    if (enableShadow) {
        enable_npc_shadow(npc);
    } else {
        disable_npc_shadow(npc);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(EnableNpcBlur) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 enableBlur = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    if (enableBlur) {
        enable_npc_blur(npc);
    } else {
        disable_npc_blur(npc);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(ClearPartnerMoveHistory) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    partner_clear_player_tracking(npc);
    return ApiStatus_DONE2;
}

API_CALLABLE(NpcSetHomePosToCurrent) {
    Npc* npc = resolve_npc(script, evt_get_variable(script, *script->ptrReadPos));

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->homePos.x = npc->pos.x;
    npc->homePos.y = npc->pos.y;
    npc->homePos.z = npc->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartnerPos) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode posX = *ptrReadPos++;
    Bytecode posY = *ptrReadPos++;
    Bytecode posZ = *ptrReadPos++;
    Npc* npc = get_npc_unsafe(NPC_PARTNER);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, posX, npc->pos.x);
    evt_set_variable(script, posY, npc->pos.y);
    evt_set_variable(script, posZ, npc->pos.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(DisablePartnerAI) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (evt_get_variable(script, *ptrReadPos++) == 0) {
        func_800EF314();
    } else {
        func_800EF300();
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(EnablePartnerAI) {
    enable_partner_ai();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802CF54C) {
    func_800EF43C();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802CF56C) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = evt_get_variable(script, *ptrReadPos++);

    if (value == 2) {
        func_800EF3E4();
    } else {
        func_800EF3D4(value);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(BringPartnerOut) {
    Bytecode* args = script->ptrReadPos;
    NpcBlueprint bp;
    NpcBlueprint* bpPointer = &bp;
    PlayerData* playerData = &gPlayerData;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* partner;
    Npc* npc;
    f32 duration;
    f32 playerZ;
    f32 targetZ;
    f32 playerX;
    f32 targetX;
    f32 targetY;
    f32 playerY;

    if (isInitialCall) {
        wExtraPartnerID = evt_get_variable(script, *args++);
        if (playerData->curPartner == wExtraPartnerID) {
            wExtraPartnerID = 0;
            return ApiStatus_DONE2;
        }

        partner = get_npc_unsafe(NPC_PARTNER);
        partner->npcID = -5;

        bpPointer->flags = NPC_FLAG_IGNORE_PLAYER_COLLISION;
        bpPointer->initialAnim = gPartnerAnimations[wExtraPartnerID].fly;
        bpPointer->onUpdate = nullptr;
        bpPointer->onRender = nullptr;

        wExtraPartnerNpcID = create_basic_npc(bpPointer);
        npc = get_npc_by_index(wExtraPartnerNpcID);
        npc->collisionDiameter = 10;
        npc->collisionHeight = 10;
        npc->npcID = NPC_PARTNER;
        npc->scale.x = 0.0f;
        npc->scale.y = 0.0f;
        npc->scale.z = 0.0f;

        npc->moveToPos.x = targetX = partner->pos.x;
        playerY = playerStatus->pos.y;
        npc->moveToPos.y = playerStatus->pos.y;
        npc->moveToPos.z = targetZ = partner->pos.z + 30.0f;
        npc->pos.x = playerX = playerStatus->pos.x;
        npc->pos.y = targetY = playerStatus->pos.y + (playerStatus->colliderHeight / 2);
        playerZ = playerStatus->pos.z;
        npc->moveSpeed = 4.0f;
        npc->jumpScale = 1.6f;
        npc->pos.z = playerZ;

        npc->planarFlyDist = dist2D(playerX, npc->pos.z, targetX, targetZ);
        npc->yaw = atan2(playerX, playerZ, targetX, targetZ);
        npc->duration = npc->planarFlyDist / npc->moveSpeed;

        if (npc->duration < 10) {
            npc->duration = 10;
            npc->moveSpeed = npc->planarFlyDist / npc->duration;
        }

        npc->jumpVel = ((playerY - targetY) + (npc->jumpScale * npc->duration * npc->duration * 0.5f)) / npc->duration;
        npc->curAnim = gPartnerAnimations[wExtraPartnerID].walk;
        return ApiStatus_BLOCK;
    }

    npc = get_npc_by_index(wExtraPartnerNpcID);
    npc->jumpVel -= npc->jumpScale;
    npc->pos.y += npc->jumpVel;
    if (npc->jumpVel <= 0.0f) {
        npc->curAnim = gPartnerAnimations[wExtraPartnerID].jump;
    }
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    duration = npc->duration;
    if (duration > 10.0f) {
        duration = 10.0f;
    }
    npc->scale.x = (10.0f - duration) / 10.0f;
    npc->scale.y = npc->scale.x;
    npc->scale.z = npc->scale.x;

    npc->duration--;
    if (npc->duration < 0) {
        npc->curAnim = gPartnerAnimations[wExtraPartnerID].idle;
        npc->jumpVel = 0.0f;
        npc->pos.y = npc->moveToPos.y;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        npc->yaw = clamp_angle(npc->yaw + 180.0f);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(PutPartnerAway) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 scale;
    f32 targetX;
    f32 targetY;
    f32 targetZ;
    f32 partnerX;
    f32 partnerY;
    f32 partnerZ;

    if (isInitialCall) {
        if (wExtraPartnerID != 0) {
            partner->flags &= ~NPC_FLAG_GRAVITY;
            partner->flags &= ~NPC_FLAG_FLYING;
            targetX = playerStatus->pos.x;
            partner->moveToPos.x = targetX;
            partnerX = partner->pos.x;
            targetY = playerStatus->pos.y + (playerStatus->colliderHeight / 2);
            partner->moveToPos.y = targetY;
            partnerY = partner->pos.y;
            targetZ = playerStatus->pos.z;
            partner->moveToPos.z = targetZ;
            partnerZ = partner->pos.z;
            partner->moveSpeed = 4.0f;
            partner->jumpScale = 2.6f;
            partner->planarFlyDist = dist2D(partnerX, partnerZ, targetX, targetZ);
            partner->yaw = atan2(partnerX, partnerZ, targetX, targetZ);
            partner->duration = partner->planarFlyDist / partner->moveSpeed;

            if (partner->duration < 10) {
                partner->duration = 10;
                partner->moveSpeed = partner->planarFlyDist / partner->duration;
            }

            partnerY = targetY - partnerY;
            partner->jumpVel = (partnerY + (partner->jumpScale * partner->duration * partner->duration * 0.5f)) / partner->duration;
            partner->curAnim = gPartnerAnimations[wExtraPartnerID].walk;
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE2;
        }
    }

    partner->jumpVel -= partner->jumpScale;
    partner->pos.y += partner->jumpVel;
    if (partner->jumpVel <= 0.0f) {
        partner->curAnim = gPartnerAnimations[wExtraPartnerID].jump;
    }
    npc_move_heading(partner, partner->moveSpeed, partner->yaw);

    scale = partner->duration;
    if (scale > 10.0f) {
        scale = 10.0f;
    }

    partner->scale.x = scale / 10.0f;
    partner->scale.y = partner->scale.x;
    partner->scale.z = partner->scale.x;

    partner->duration--;
    if (partner->duration < 0) {
        partner->curAnim = gPartnerAnimations[wExtraPartnerID].fall;
        partner->jumpVel = 0.0f;
        partner->pos.y = partner->moveToPos.y;
        free_npc_by_index(wExtraPartnerNpcID);
        get_npc_unsafe(-5)->npcID = NPC_PARTNER;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(GetCurrentPartnerID) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerData.curPartner);
    return ApiStatus_DONE2;
}

API_CALLABLE(PartnerCanUseAbility) {
    Bytecode outVar = *script->ptrReadPos;

    evt_set_variable(script, outVar, partner_can_use_ability());
    return ApiStatus_DONE2;
}

API_CALLABLE(PartnerIsFlying) {
    Bytecode outVar = *script->ptrReadPos;

    evt_set_variable(script, outVar, partner_is_flying());
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcImgFXParams) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode imgfxType = evt_get_variable(script, *args++);
    Bytecode var2 = evt_get_variable(script, *args++);
    Bytecode var3 = evt_get_variable(script, *args++);
    Bytecode var4 = evt_get_variable(script, *args++);
    Bytecode var5 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc_set_imgfx_params(npc, imgfxType, var2, var3, var4, var5, npc->imgfxFlags);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcImgFXFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode flags = *args;
    Npc* npc = resolve_npc(script, npcId);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->imgfxFlags = flags;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcPaletteSwapMode) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode palAdjustMode = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_mode_A(npc, palAdjustMode);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcPaletteSwapLower) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode var1 = evt_get_variable(script, *args++);
    Bytecode var2 = evt_get_variable(script, *args++);
    Bytecode var3 = evt_get_variable(script, *args++);
    Bytecode var4 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_1(npc, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcPaletteSwapping) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode var1 = evt_get_variable(script, *args++);
    Bytecode var2 = evt_get_variable(script, *args++);
    Bytecode var3 = evt_get_variable(script, *args++);
    Bytecode var4 = evt_get_variable(script, *args++);
    Bytecode var5 = evt_get_variable(script, *args++);
    Bytecode var6 = evt_get_variable(script, *args++);
    Bytecode var7 = evt_get_variable(script, *args++);
    Bytecode var8 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_1(npc, var1, var2, var3, var4);
    npc_set_palswap_2(npc, var5, var6, var7, var8);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcDecoration) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 value1 = evt_get_variable(script, *ptrReadPos++);
    s32 value2 = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc_set_decoration(npc, value1, value2);
    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundAtNpc) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 soundID = evt_get_variable(script, *ptrReadPos++);
    s32 flags = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    sfx_play_sound_at_position(soundID, flags, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcRenderMode) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    u8 renderMode = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    npc->renderMode = renderMode;
    return ApiStatus_DONE2;
}
