#include "common.h"
#include "npc.h"

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

    if (animID - PARTNER_ANIM_WALK < 9) {
        npc->currentAnim = gPartnerAnimations[playerData->currentPartner].anims[animID - PARTNER_ANIM_WALK];
    } else if ((animID - 0x201) < 0x10) {
        npc->currentAnim = get_enemy(npc->npcID)->animList[animID - 0x201];
    } else {
        npc->currentAnim = animID;
    }
}

ApiStatus CreateNpc(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 initialAnim = evt_get_variable(script, *args++);
    NpcBlueprint blueprint;
    Npc *npc;

    blueprint.flags = 0;
    blueprint.initialAnim = initialAnim;
    blueprint.onUpdate = NULL;
    blueprint.onRender = NULL;

    npc = get_npc_by_index(_create_npc_basic(&blueprint));
    npc->npcID = npcID;
    disable_npc_shadow(npc);
    return ApiStatus_DONE2;
}

ApiStatus DeleteNpc(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(evt_get_variable(script, *args++));

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    free_npc(npc);
    return ApiStatus_DONE2;
}

ApiStatus GetNpcPointer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode varNPC = *args++;

    evt_set_variable(script, varNPC, (s32)get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

ApiStatus SetNpcPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = x;
    npc->pos.y = y;
    npc->pos.z = z;
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.y = npc->pos.y;
    npc->colliderPos.z = npc->pos.z;
    npc->flags |= 0x10000;

    return ApiStatus_DONE2;
}

ApiStatus SetNpcRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 rotX = evt_get_float_variable(script, *args++);
    f32 rotY = evt_get_float_variable(script, *args++);
    f32 rotZ = evt_get_float_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->rotation.x = rotX;
    npc->rotation.y = rotY;
    npc->rotation.z = rotZ;
    return ApiStatus_DONE2;
}

ApiStatus func_802CDE68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    f32 value = evt_get_float_variable(script, *args++);
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->rotationVerticalPivotOffset = value;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcScale(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 scaleX = evt_get_float_variable(script, *ptrReadPos++);
    f32 scaleY = evt_get_float_variable(script, *ptrReadPos++);
    f32 scaleZ = evt_get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->scale.x = scaleX;
    npc->scale.y = scaleY;
    npc->scale.z = scaleZ;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcCollisionSize(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 height = evt_get_variable(script, *ptrReadPos++);
    s32 radius = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->collisionHeight = height;
    npc->collisionRadius = radius;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 speed = evt_get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcJumpscale(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 jumpScale = evt_get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 animation = evt_get_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_animation(npc, animation);
    return ApiStatus_DONE2;
}

ApiStatus GetNpcAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outVar, npc->currentAnim);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimationSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    f32 animationSpeed = evt_get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->animationSpeed = animationSpeed;
    return ApiStatus_DONE2;
}

ApiStatus NpcMoveTo(Evt* script, s32 isInitialCall) {
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
        if (npc == NULL) {
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
        func_8003D660(npc, 0);
    } else {
        func_8003D660(npc, 1);
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

        if (npc == NULL) {
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

        npc->flags |= 0x800;
        npc->jumpVelocity = (npc->jumpScale * npc->duration * 0.5f) + (goalY / npc->duration);
        script->functionTemp[0] =1;
    }

    npc = script->functionTempPtr[1];
    npc_move_heading(npc, npc->moveSpeed, *yaw);

    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;

    npc->duration--;
    if (npc->duration < 0) {
        npc->jumpVelocity = 0.0f;
        npc->pos.x = npc->moveToPos.x;
        npc->pos.y = npc->moveToPos.y;
        npc->pos.z = npc->moveToPos.z;
        npc->flags &= ~0x800;
        func_8003D660(npc, 2);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus NpcJump0(Evt* script, s32 isInitialCall) {
    return _npc_jump_to(script, isInitialCall, 0);
}

ApiStatus NpcJump1(Evt* script, s32 isInitialCall) {
    return _npc_jump_to(script, isInitialCall, 1);
}

ApiStatus NpcFlyTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32* outX = (f32*)&script->varTable[3];
    f32* outY = (f32*)&script->varTable[4];
    f32* outZ = (f32*)&script->varTable[5];
    Npc* npc;
    f32 dist;
    f32 yDelta;

    if (isInitialCall) {
        npc = resolve_npc(script, evt_get_variable(script, *args++));
        if (npc == NULL) {
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

ApiStatus GetNpcYaw(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outVar, clamp_angle(npc->yaw));
    return ApiStatus_DONE2;
}

ApiStatus SetNpcYaw(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_yaw(npc, evt_get_variable(script, *ptrReadPos++));
    return ApiStatus_DONE2;
}

ApiStatus InterpNpcYaw(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* npc;

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == NULL) {
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

ApiStatus NpcFacePlayer(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* turnTime = &script->functionTemp[3];
    Npc* npc;

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);

        npc = resolve_npc(script, npcID);
        if (npc == NULL) {
            return ApiStatus_DONE2;
        }

        *initialYaw = npc->yaw;
        *deltaYaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z) - *initialYaw;
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

ApiStatus NpcFaceNpc(Evt* script, s32 isInitialCall) {
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
        if (targetNpc == NULL) {
            return ApiStatus_DONE2;
        }

        turningNpc = resolve_npc(script, turningNpcID);
        if (turningNpc == NULL) {
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

ApiStatus SetNpcFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 flagBits = *args++;
    s32 enable = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enable) {
        npc->flags |= flagBits;
    } else {
        npc->flags &= ~flagBits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetNpcPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, outX, npc->pos.x);
    evt_set_variable(script, outY, npc->pos.y);
    evt_set_variable(script, outZ, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcCollisionChannel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode channel = *args;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->collisionChannel = channel;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSprite(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Bytecode animID = *args;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_sprite(npc, animID, NULL);
    return ApiStatus_DONE2;
}

ApiStatus EnableNpcShadow(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 enableShadow = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enableShadow) {
        enable_npc_shadow(npc);
    } else {
        disable_npc_shadow(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableNpcBlur(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 enableBlur = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enableBlur) {
        enable_npc_blur(npc);
    } else {
        disable_npc_blur(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus ClearPartnerMoveHistory(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    partner_clear_player_tracking(npc);
    return ApiStatus_DONE2;
}

ApiStatus NpcSetHomePosToCurrent(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, evt_get_variable(script, *script->ptrReadPos));

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->homePos.x = npc->pos.x;
    npc->homePos.y = npc->pos.y;
    npc->homePos.z = npc->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus GetPartnerPos(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode posX = *ptrReadPos++;
    Bytecode posY = *ptrReadPos++;
    Bytecode posZ = *ptrReadPos++;
    Npc* npc = get_npc_unsafe(-4);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    evt_set_variable(script, posX, npc->pos.x);
    evt_set_variable(script, posY, npc->pos.y);
    evt_set_variable(script, posZ, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerAI(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (evt_get_variable(script, *ptrReadPos++) == 0) {
        func_800EF314();
    } else {
        func_800EF300();
    }
    return ApiStatus_DONE2;
}

ApiStatus EnablePartnerAI(Evt* script, s32 isInitialCall) {
    enable_partner_ai();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF54C(Evt* script, s32 isInitialCall) {
    func_800EF43C();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF56C(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = evt_get_variable(script, *ptrReadPos++);

    if (value == 2) {
        func_800EF3E4();
    } else {
        func_800EF3D4(value);
    }
    return ApiStatus_DONE2;
}

s32 BringPartnerOut(Evt *script, s32 isInitialCall) {
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
        if (playerData->currentPartner == wExtraPartnerID) {
            wExtraPartnerID = 0;
            return ApiStatus_DONE2;
        }

        partner = get_npc_unsafe(NPC_PARTNER);
        partner->npcID = -5;

        bpPointer->flags = NPC_FLAG_100;
        bpPointer->initialAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_FLY];
        bpPointer->onUpdate = NULL;
        bpPointer->onRender = NULL;

        wExtraPartnerNpcID = _create_npc_basic(bpPointer);
        npc = get_npc_by_index(wExtraPartnerNpcID);
        npc->collisionRadius = 10;
        npc->collisionHeight = 10;
        npc->npcID = NPC_PARTNER;
        npc->scale.x = 0.0f;
        npc->scale.y = 0.0f;
        npc->scale.z = 0.0f;

        npc->moveToPos.x = targetX = partner->pos.x;
        playerY = playerStatus->position.y;
        npc->moveToPos.y = playerStatus->position.y;
        npc->moveToPos.z = targetZ = partner->pos.z + 30.0f;
        npc->pos.x = playerX = playerStatus->position.x;
        npc->pos.y = targetY = playerStatus->position.y + (playerStatus->colliderHeight / 2);
        playerZ = playerStatus->position.z;
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

        npc->jumpVelocity = ((playerY - targetY) + (npc->jumpScale * npc->duration * npc->duration * 0.5f)) / npc->duration;
        npc->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_WALK];
        return ApiStatus_BLOCK;
    }

    npc = get_npc_by_index(wExtraPartnerNpcID);
    npc->jumpVelocity -= npc->jumpScale;
    npc->pos.y += npc->jumpVelocity;
    if (npc->jumpVelocity <= 0.0f) {
        npc->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_JUMP];
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
        npc->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_IDLE];
        npc->jumpVelocity = 0.0f;
        npc->pos.y = npc->moveToPos.y;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        npc->yaw = clamp_angle(npc->yaw + 180.0f);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus PutPartnerAway(Evt* script, s32 isInitialCall) {
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
            partner->flags &= ~0x200;
            partner->flags &= ~8;
            targetX = playerStatus->position.x;
            partner->moveToPos.x = targetX;
            partnerX = partner->pos.x;
            targetY = playerStatus->position.y + (playerStatus->colliderHeight / 2);
            partner->moveToPos.y = targetY;
            partnerY = partner->pos.y;
            targetZ = playerStatus->position.z;
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
            partner->jumpVelocity = (partnerY + (partner->jumpScale * partner->duration * partner->duration * 0.5f)) / partner->duration;
            partner->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_WALK];
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE2;
        }
    }

    partner->jumpVelocity -= partner->jumpScale;
    partner->pos.y += partner->jumpVelocity;
    if (partner->jumpVelocity <= 0.0f) {
        partner->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_JUMP];
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
        partner->currentAnim = gPartnerAnimations[wExtraPartnerID].anims[PARTNER_ANIM_INDEX_FALL];
        partner->jumpVelocity = 0.0f;
        partner->pos.y = partner->moveToPos.y;
        free_npc_by_index(wExtraPartnerNpcID);
        get_npc_unsafe(-5)->npcID = NPC_PARTNER;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus GetCurrentPartnerID(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    return ApiStatus_DONE2;
}

ApiStatus PartnerCanUseAbility(Evt* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    evt_set_variable(script, arg0, partner_can_use_ability());
    return ApiStatus_DONE2;
}

ApiStatus PartnerIsFlying(Evt* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    evt_set_variable(script, arg0, partner_is_flying());
    return ApiStatus_DONE2;
}

ApiStatus func_802CFD30(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode var1 = evt_get_variable(script, *args++);
    Bytecode var2 = evt_get_variable(script, *args++);
    Bytecode var3 = evt_get_variable(script, *args++);
    Bytecode var4 = evt_get_variable(script, *args++);
    Bytecode var5 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003D624(npc, var1, var2, var3, var4, var5, npc->unk_A2);
    return ApiStatus_DONE2;
}

ApiStatus func_802CFE2C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->unk_A2 = arg1;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcPaletteSwapMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode var1 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_mode_A(npc, var1);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcPaletteSwapLower(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcId = evt_get_variable(script, *args++);
    Bytecode var1 = evt_get_variable(script, *args++);
    Bytecode var2 = evt_get_variable(script, *args++);
    Bytecode var3 = evt_get_variable(script, *args++);
    Bytecode var4 = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_1(npc, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcPaletteSwapping(Evt* script, s32 isInitialCall) {
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

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc_set_palswap_1(npc, var1, var2, var3, var4);
    npc_set_palswap_2(npc, var5, var6, var7, var8);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcDecoration(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 value1 = evt_get_variable(script, *ptrReadPos++);
    s32 value2 = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc_set_decoration(npc, value1, value2);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtNpc(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    s32 soundID = evt_get_variable(script, *ptrReadPos++);
    s32 value2 = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    sfx_play_sound_at_position(soundID, value2, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcRenderMode(Evt* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *ptrReadPos++);
    u8 renderMode = evt_get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    npc->renderMode = renderMode;
    return ApiStatus_DONE2;
}
