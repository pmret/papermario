#include "common.h"

Npc* playerNpc = (Npc*) 0x802DB270; // XXX: raw ptr

extern s16 D_802DB5B0;
extern VirtualEntityList D_802DB5C0;
extern VirtualEntityList D_802DB6C0;
extern VirtualEntityList* D_802DB7C0;

ApiStatus HidePlayerShadow(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 hideShadow = get_variable(script, *args++);

    if (hideShadow) {
        disable_player_shadow();
    } else {
        enable_player_shadow();
    }
    return ApiStatus_DONE2;
}

ApiStatus DisablePlayerPhysics(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 disable = get_variable(script, *args++);

    if (disable) {
        disable_player_static_collisions();
    } else {
        enable_player_static_collisions();
    }
    return ApiStatus_DONE2;
}

ApiStatus DisablePlayerInput(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 enable = get_variable(script, *args++);

    if (enable) {
        disable_player_input();
        func_800EF628();
        close_status_menu();
        func_800E984C();
        if (playerStatus->actionState == ACTION_STATE_SPIN) {
            playerStatus->animFlags |= 0x40000;
        }
        gOverrideFlags |= 0x40;
    } else {
        enable_player_input();
        func_800EF600();
        func_800E01DC();
        gOverrideFlags &= ~0x40;
        func_800E983C();
    }
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerPos(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 x = get_variable(script, *args++);
    f32 y = get_variable(script, *args++);
    f32 z = get_variable(script, *args++);

    playerNpc->pos.x = x;
    playerNpc->pos.y = y;
    playerNpc->pos.z = z;

    playerStatus->position.x = playerNpc->pos.x;
    playerStatus->position.y = playerNpc->pos.y;
    playerStatus->position.z = playerNpc->pos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerCollisionSize(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 height = get_variable(script, *args++);
    s32 radius = get_variable(script, *args);

    playerNpc->collisionHeight = height;
    playerNpc->collisionRadius = radius;

    playerStatus->colliderHeight = playerNpc->collisionHeight;
    playerStatus->colliderDiameter = playerNpc->collisionRadius;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerSpeed(ScriptInstance* script, s32 isInitialCall) {
    playerNpc->moveSpeed = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerJumpscale(ScriptInstance* script, s32 isInitialCall) {
    playerNpc->jumpScale = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerAnim currentAnim = get_variable(script, *args++);
    s32 shakeAnim = 0x80003;

    playerNpc->currentAnim.w = currentAnim;

    do { } while (0); // Needed to match for some reason

    gPlayerAnimation = playerNpc->currentAnim.w;

    if (gPlayerAnimation == shakeAnim) {
        exec_ShakeCam1(0, 0, 2);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerActionState(ScriptInstance* script, s32 isInitialCall) {
    set_action_state(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerAnimationSpeed(ScriptInstance* script, s32 isInitialCall) {
    playerNpc->animationSpeed = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus PlayerMoveTo(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = get_variable(script, *args++);
        f32 targetZ = get_variable(script, *args++);
        f32 moveSpeed;

        script->functionTemp[0].s = get_variable(script, *args++);
        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);

        if (script->functionTemp[0].s == 0) {
            script->functionTemp[0].s = dist2D(playerStatus->position.x, playerStatus->position.z, targetX,
                                               targetZ) / playerNpc->moveSpeed;
            moveSpeed = playerNpc->moveSpeed;
        } else {
            moveSpeed = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ) / script->functionTemp[0].s;
        }
        move_player(script->functionTemp[0].s, playerStatus->targetYaw, moveSpeed);
    }

    // functionTemp 0 is the time left
    script->functionTemp[0].s--;
    return script->functionTemp[0].s < 0;
}

ApiStatus func_802D1270(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = get_variable(script, *args++);
        f32 targetZ = get_variable(script, *args++);
        f32 var3 = get_float_variable(script, *args++);
        f32 dist;
        f32 moveSpeed;

        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);
        dist = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);
        script->functionTemp[0].s = dist / var3;
        moveSpeed = dist / script->functionTemp[0].s;

        move_player(script->functionTemp[0].s, playerStatus->targetYaw, moveSpeed);
    }

    // functionTemp 0 is the time left
    script->functionTemp[0].s--;
    return (script->functionTemp[0].s < 0) * ApiStatus_DONE2;
}

ApiStatus func_802D1380(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = get_variable(script, *args++);
        f32 targetZ = get_variable(script, *args++);

        playerNpc->duration = get_variable(script, *args++);
        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);

        if (playerNpc->duration != 0) {
            playerNpc->moveSpeed = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ) / (f32) playerNpc->duration;
        } else {
            playerNpc->duration = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ) / playerNpc->moveSpeed;
            if (playerNpc->duration == 0) {
                playerNpc->duration = 1;
            }
        }

        move_player(playerNpc->duration, playerStatus->targetYaw, playerNpc->moveSpeed);
    }

    return ApiStatus_DONE1;
}

s32 player_jump(ScriptInstance* script, s32 isInitialCall, s32 mode) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;
    f32 jumpVelocity;
    s32 duration;
    s32 animID;
    f32 dist;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        xTemp = get_variable(script, *args++);
        yTemp = get_variable(script, *args++);
        zTemp = get_variable(script, *args++);
        duration = get_variable(script, *args++);

        playerNpc->pos.x = playerStatus->position.x;
        playerNpc->pos.y = playerStatus->position.y;
        playerNpc->pos.z = playerStatus->position.z;
        playerNpc->moveToPos.x = xTemp;
        playerNpc->moveToPos.y = yTemp;
        playerNpc->moveToPos.z = zTemp;
        playerNpc->duration = duration;
        playerNpc->yaw = playerStatus->targetYaw;

        dist = dist2D(playerNpc->pos.x, playerNpc->pos.z, playerNpc->moveToPos.x, playerNpc->moveToPos.z);
        if (dist > 1.0) {
            playerNpc->yaw = atan2(playerNpc->pos.x, playerNpc->pos.z, playerNpc->moveToPos.x, playerNpc->moveToPos.z);
        }

        yTemp = playerNpc->moveToPos.y - playerNpc->pos.y;

        if (playerNpc->duration == 0) {
            playerNpc->duration = dist / playerNpc->moveSpeed;
        } else {
            playerNpc->moveSpeed = dist / playerNpc->duration;
        }

        playerNpc->jumpVelocity = (playerNpc->jumpScale * (playerNpc->duration - 1) / 2) + (yTemp / playerNpc->duration);
        playerStatus->flags |= 8;
        playerStatus->animFlags |= 0x10000000;

        if (mode == 0) {
            if (!(playerStatus->animFlags & 0x4000)) {
                if (!(playerStatus->animFlags & 1)) {
                    animID = 0x10007;
                } else {
                    animID = 0x60009;
                }
            } else {
                animID = 0x90005;
            }
            func_800DFEFC(animID);
            sfx_play_sound_at_player(SOUND_JUMP_2081, 0);
        }
        script->functionTemp[0].s = 1;
    }

    npc_move_heading(playerNpc, playerNpc->moveSpeed, playerNpc->yaw);
    playerNpc->pos.y += playerNpc->jumpVelocity;
    jumpVelocity = playerNpc->jumpVelocity; // TODO: temp needed and used specifically only once below for this to match
    playerNpc->jumpVelocity -= playerNpc->jumpScale;

    if (mode == 0 && jumpVelocity > 0.0f && playerNpc->jumpVelocity <= 0.0f) {
        if (!(playerStatus->animFlags & 0x4000)) {
            if (!(playerStatus->animFlags & 1)) {
                animID = 0x10008;
            } else {
                animID = 0x6000A;
            }
        } else {
            animID = 0x90005;
        }
        func_800DFEFC(animID);
    }

    playerStatus->position.x = playerNpc->pos.x;
    playerStatus->position.y = playerNpc->pos.y;
    playerStatus->position.z = playerNpc->pos.z;

    if (mode == 0) {
        playerStatus->targetYaw = playerNpc->yaw;
    }

    playerNpc->duration--;
    if (playerNpc->duration == 0) {
        playerStatus->flags &= -9;
        playerStatus->animFlags &= ~0x10000000;

        if (mode == 0) {
            if (!(playerStatus->animFlags & 0x4000)) {
                if (!(playerStatus->animFlags & 1)) {
                    animID = 0x10009;
                } else {
                    animID = 0x6000B;
                }
            } else {
                animID = 0x10003;
            }
            func_800DFEFC(animID);
            func_8003D660(playerNpc, 2);
        }

        if (mode == 0 || mode == 2) {
            s32 colliderID;

            yTemp = func_800E3514(playerNpc->jumpVelocity, &colliderID);

            if (colliderID >= 0) {
                playerStatus->position.y = yTemp;
                func_800E315C(colliderID);
                func_800EFD08();
            }
        }
        return TRUE;
    }
    return FALSE;
}

ApiStatus PlayerJump(ScriptInstance* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 0);
}

ApiStatus PlayerJump1(ScriptInstance* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 1);
}

ApiStatus PlayerJump2(ScriptInstance* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 2);
}

ApiStatus InterpPlayerYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* initialYaw = &script->functionTemp[1].f;
    f32* deltaYaw = &script->functionTemp[2].f;
    s32* time = &script->functionTemp[3].s;

    if (isInitialCall) {
        playerNpc->yaw = playerStatus->targetYaw;
        *initialYaw = playerNpc->yaw;
        *deltaYaw = get_float_variable(script, *args++) - *initialYaw;
        *time = get_variable(script, *args++);
        playerNpc->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    if (*time > 0) {
        playerNpc->duration++;
        playerNpc->yaw = *initialYaw + ((*deltaYaw * playerNpc->duration) / *time);
        playerNpc->yaw = clamp_angle(playerNpc->yaw);
        playerStatus->targetYaw = playerNpc->yaw;

        return !(playerNpc->duration < *time);
    } else {
        playerNpc->yaw += *deltaYaw;
        playerNpc->yaw = clamp_angle(playerNpc->yaw);
        playerStatus->targetYaw = playerNpc->yaw;

        return ApiStatus_DONE2;
    }
}

ApiStatus PlayerFaceNpc(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* args = script->ptrReadPos;
    f32* playerTargetYaw = &script->functionTemp[1].f;
    f32* angle = &script->functionTemp[2].f;
    s32* ft3 = &script->functionTemp[3].s;

    if (isInitialCall) {
        NpcID npcID = get_variable(script, *args++);
        Npc* npc;

        if (npcID == NPC_SELF) {
            npc = get_npc_safe(script->owner2.npcID);
        } else if (npcID < -270000000) {
            npc = (Npc*)npcID;
        } else {
            npc = get_npc_safe(npcID);
            if (npc == NULL) {
                return ApiStatus_DONE2;
            }
        }

        *playerTargetYaw = playerNpc->yaw = playerStatus->targetYaw;
        *angle = atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z) - *playerTargetYaw;
        *ft3 = get_variable(script, *args++);

        playerNpc->duration = 0;

        if (*angle < -180.0f) {
            *angle += 360.0f;
        }
        if (*angle > 180.0f) {
            *angle -= 360.0f;
        }
    }

    if (*ft3 > 0) {
        playerNpc->duration++;
        playerNpc->yaw = *playerTargetYaw + ((*angle * playerNpc->duration) / *ft3);
        playerStatus->targetYaw = playerNpc->yaw = clamp_angle(playerNpc->yaw);
        return (playerNpc->duration >= *ft3) * ApiStatus_DONE1;
    }

    playerNpc->yaw += *angle;
    playerStatus->targetYaw = playerNpc->yaw = clamp_angle(playerNpc->yaw);

    return ApiStatus_DONE2;
}

ApiStatus GetPlayerTargetYaw(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerStatus.targetYaw);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode bits = *args++;
    Bytecode a1 = *args;

    if (get_variable(script, a1)) {
        playerStatus->flags |= bits;
    } else {
        playerStatus->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPlayerActionState(ScriptInstance* script, s32 isInitialCall) {
    Bytecode outVar = *script->ptrReadPos;
    set_variable(script, outVar, gPlayerActionState);
    return ApiStatus_DONE2;
}

ApiStatus GetPlayerPos(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;

    set_variable(script, outVar1, playerStatus->position.x);
    set_variable(script, outVar2, playerStatus->position.y);
    set_variable(script, outVar3, playerStatus->position.z);
    return ApiStatus_DONE2;
}

ApiStatus GetPlayerAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode outVar = *script->ptrReadPos;

    set_variable(script, outVar, gPlayerAnimation);
    return ApiStatus_DONE2;
}

ApiStatus FullyRestoreHPandFP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    return ApiStatus_DONE2;
}

ApiStatus FullyRestoreSP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->specialBarsFilled = playerData->maxStarPower * 256;
    return ApiStatus_DONE2;
}

ApiStatus EnablePartner(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerIdx = get_variable(script, *script->ptrReadPos) - 1;
    PartnerData* partner = &gPlayerData.partners[partnerIdx];

    partner->enabled = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus DisablePartner(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerIdx = get_variable(script, *script->ptrReadPos) - 1;
    PartnerData* partner = &gPlayerData.partners[partnerIdx];

    partner->enabled = FALSE;
    return ApiStatus_DONE2;
}

ApiStatus UseEntryHeading(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MapConfig* mapConfig = get_current_map_header();
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    f32 entryX = script->varTable[1] = (*mapConfig->entryList)[gGameStatusPtr->entryID].x;
    f32 entryY = script->varTable[2] = (*mapConfig->entryList)[gGameStatusPtr->entryID].y;
    f32 entryZ = script->varTable[3] = (*mapConfig->entryList)[gGameStatusPtr->entryID].z;
    f32 cosTheta;
    f32 sinTheta;
    f32 exitTangentFrac;
    f32* blah;

    sin_cos_deg(clamp_angle((*mapConfig->entryList)[gGameStatusPtr->entryID].yaw + 180.0f), &sinTheta, &cosTheta);

    exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
    gPlayerStatus.position.x = (entryX + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
    gPlayerStatus.position.z = (entryZ - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);

    blah = &script->varTable[5];
    *blah = dist2D(gPlayerStatus.position.x, gPlayerStatus.position.z, entryX, entryZ) / var2;
    gPlayerStatus.flags |= 0x4000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802D2148(ScriptInstance* script, s32 isInitialCall) {
    gPlayerStatus.flags &= ~0x4000000;
    return ApiStatus_DONE2;
}

ApiStatus UseExitHeading(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapConfig* mapConfig = get_current_map_header();
    f32* varTableVar5 = &script->varTable[5];

    if (func_800E26C4()) {
        s32 var1 = get_variable(script, *args++);
        s32 entryID = get_variable(script, *args++);
        f32 entryX = (*mapConfig->entryList)[entryID].x;
        f32 entryZ = (*mapConfig->entryList)[entryID].z;
        f32 temp = (var1 + 10.0f) / 2;
        f32 temp_f2 = dist2D(entryX, entryZ, playerStatus->position.x, playerStatus->position.z) - temp;
        f32 sinTheta;
        f32 cosTheta;
        f32 exitTangentFrac;

        if (temp_f2 > 0.0f) {
            if (temp_f2 > var1 + 10.0f) {
                temp_f2 = var1 + 10.0f;
            }
            var1 -= temp_f2 / 2;
        }

        sin_cos_deg(clamp_angle((*mapConfig->entryList)[entryID].yaw + 180.0f), &sinTheta, &cosTheta);
        gGameStatusPtr->exitTangent = (cosTheta * (playerStatus->position.x - entryX)) - (sinTheta * (entryZ - playerStatus->position.z));
        exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
        script->varTable[1] = (playerStatus->position.x + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
        script->varTable[3] = (playerStatus->position.z - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);
        script->varTable[2] = (*mapConfig->entryList)[entryID].y;
        *varTableVar5 = var1 / 15;
        playerStatus->animFlags |= 0x100000;
        playerStatus->flags |= 0x4000000;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

s32 func_802D23F8(void) {
    if (gPlayerActionState == ACTION_STATE_IDLE || gPlayerActionState == ACTION_STATE_WALK ||
        gPlayerActionState == ACTION_STATE_RUN || gPlayerActionState == ACTION_STATE_LAND ||
        gPlayerActionState == ACTION_STATE_STEP_DOWN_LAND || gPlayerActionState == ACTION_STATE_GROUND_POUND ||
        gPlayerActionState == ACTION_STATE_ULTRA_POUND || gPlayerActionState == ACTION_STATE_SPIN) {
        return TRUE;
    }
    return FALSE;
}

ApiStatus WaitForPlayerTouchingFloor(ScriptInstance* script, s32 isInitialCall) {
    if ((gCollisionStatus.currentFloor >= 0) && func_802D23F8()) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D2484(ScriptInstance* script, s32 isInitialCall) {
    return (gCollisionStatus.currentFloor >= 0) * ApiStatus_DONE2;
}

ApiStatus IsPlayerOnValidFloor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 val = 0;

    if (gCollisionStatus.currentFloor >= 0) {
        val = func_802D23F8() != 0;
    }
    set_variable(script, *args, val);

    return ApiStatus_DONE2;
}

ApiStatus WaitForPlayerMoveToComplete(ScriptInstance* script, s32 isInitialCall) {
    return (gPlayerStatus.moveFrames == 0) * ApiStatus_DONE2;
}

ApiStatus WaitForPlayerInputEnabled(ScriptInstance* script, s32 isInitialCall) {
    return !(gPlayerStatus.flags & 0x2000) * ApiStatus_DONE2;
}

//regs, the global at the end
#ifdef NON_MATCHING
ApiStatus func_802D2520(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 a0 = *args++;
    s32 val = get_variable(script, *args++);
    s32 a2;
    s32 a3;

    func_802DDFF8(a0, 0, 0, 0, 0, 0, 0);

    switch (val) {
        case 0:
            playerStatus->renderMode = 0xD;
            func_802DDFF8(a0, 0, 0, 0, 0, 0, 0);
            break;
        case 2:
        case 3:
            playerStatus->renderMode = 0xD;
        case 1:
            func_802DDFF8(a0, val, 0, 0, 0, 0, 0);
            break;
        case 4:
            playerStatus->renderMode = 13;
            a2 = get_variable(script, *args++);
            a3 = get_variable(script, *args++);
            get_variable(script, *args++);
            func_802DDFF8(a0, 4, a2, a3, 0, 0, 0);
            break;
        case 6:
            playerStatus->renderMode = 13;
            a2 = get_variable(script, *args++);
            a3 = get_variable(script, *args++);
            get_variable(script, *args++);
            func_802DDFF8(a0, 6, a2, a3, 0, 0, 0);
            break;
        case 7:
            playerStatus->renderMode = 22;
            get_variable(script, *args++);
            func_802DDFF8(a0, 7, 0xFF, 0xFF, 0, 0, 0);
            break;
        case 8:
            playerStatus->renderMode = 22;
            a3 = get_variable(script, *args++);
            a2 = get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            func_802DDFF8(a0, 8, a2, a3, 0, 0, 0);
            break;
        case 5:
            playerStatus->renderMode = 13;
            a2 = get_variable(script, *args++);
            a3 = get_variable(script, *args++);
            get_variable(script, *args++);
            func_802DDFF8(a0, 5, a2, a3, 0, 0, 0);
            break;
        case 13:
            playerStatus->renderMode = 22;
            a2 = get_variable(script, *args++);
            a3 = get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            func_802DDFF8(a0, 13, a2, a3, 0, 0, 0);
            break;
        default:
            break;
    }

    D_802DB5B0 = 0;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "evt/player_api", func_802D2520, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus func_802D286C(ScriptInstance* script, s32 isInitialCall) {
    s32 temp = *script->ptrReadPos;

    D_802DB5B0 = temp;
    return ApiStatus_DONE2;
}

ApiStatus func_802D2884(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* ft1 = &script->functionTemp[1].f;
    f32* angle = &script->functionTemp[2].f;
    s32* ft3 = &script->functionTemp[3].s;

    if (isInitialCall) {
        f32 x = get_float_variable(script, *args++);
        f32 z = get_float_variable(script, *args++);
        f32 yawTemp;

        *ft1 = playerNpc->yaw = playerStatus->targetYaw;

        if (playerStatus->position.x != x || playerStatus->position.z != z) {
            yawTemp = atan2(playerStatus->position.x, playerStatus->position.z, x, z);
        } else {
            yawTemp = playerStatus->targetYaw;
        }

        *angle = yawTemp - *ft1;
        *ft3 = get_variable(script, *args++);
        playerNpc->duration = 0;

        if (*angle < -180.0f) {
            *angle += 360.0f;
        }
        if (*angle > 180.0f) {
            *angle -= 360.0f;
        }
    }

    if (*ft3 > 0) {
        playerNpc->duration++;
        playerNpc->yaw = *ft1 + ((*angle * playerNpc->duration) / *ft3);
        playerStatus->targetYaw = playerNpc->yaw = clamp_angle(playerNpc->yaw);
        return !(playerNpc->duration < *ft3) * ApiStatus_DONE1;
    }

    playerNpc->yaw += *angle;
    playerStatus->targetYaw = playerNpc->yaw = clamp_angle(playerNpc->yaw);
    return ApiStatus_DONE2;
}

ApiStatus DisablePulseStone(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (get_variable(script, *script->ptrReadPos)) {
        playerStatus->animFlags &= ~0x80;
    } else {
        playerStatus->animFlags |= 0x80;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetCurrentPartner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args;
    PlayerData* playerData = &gPlayerData;
    s32 currentPartner = 0;

    if (D_8010EBB0.unk_00 != 0) {
        currentPartner = playerData->currentPartner;
    }

    set_variable(script, a0, currentPartner);
    return ApiStatus_DONE2;
}

ApiStatus func_802D2B50(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= 8;
    return ApiStatus_DONE2;
}

ApiStatus func_802D2B6C(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= 4;
    return ApiStatus_DONE2;
}

ApiStatus Disable8bitMario(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (get_variable(script, *args)) {
        playerStatus->colliderHeight = 37;
        playerStatus->colliderDiameter = 26;
        playerStatus->animFlags &= ~0x4000;
    } else {
        playerStatus->colliderHeight = 19;
        playerStatus->colliderDiameter = 26;
        playerStatus->animFlags |= 0x44004;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D2C14(ScriptInstance* script, s32 isInitialCall) {
    func_800EF3D4(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802D2C40(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    f32 x = get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 y;
    f32 z;

    playerStatus->extraVelocity.x = x;
    playerStatus->extraVelocity.y = get_variable(script, *args++);
    playerStatus->extraVelocity.z = get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtPlayer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    sfx_play_sound_at_player(var, var2);
    return ApiStatus_DONE2;
}

void func_802D2D30(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 right, u16 bottom) {
    gDPPipeSync(gMasterGfxPos++);

    if (a == 0xFF) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMasterGfxPos++, left, top, right, bottom);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
}

void func_802D2ED4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u16 temp1 = arg4 + arg6;
    u16 temp2 = arg5 + arg7;

    func_802D2D30(arg0, arg1, arg2, arg3, arg4, arg5, temp1, temp2);
}

void func_802D2F34(VirtualEntity* virtualEntity, f32 arg1, f32 arg2) {
    f32 theta = (arg2 * TAU) / 360.0f;
    f32 sinTheta = sin_rad(theta);
    f32 cosTheta = cos_rad(theta);

    virtualEntity->pos.x += arg1 * sinTheta;
    virtualEntity->pos.z += -arg1 * cosTheta;
}

void func_802D2FCC(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        VirtualEntity* virtualEntity = (*D_802DB7C0)[i];

        if (virtualEntity != NULL && virtualEntity->entityModelIndex >= 0) {
            exec_entity_model_commandlist(virtualEntity->entityModelIndex);
        }
    }
}

INCLUDE_ASM(void, "evt/player_api", func_802D3028, void);

INCLUDE_ASM(s32, "evt/player_api", func_802D31E0);

ApiStatus func_802D3398(ScriptInstance* script, s32 isInitialCall) {
    if (!gGameStatusPtr->isBattle) {
        D_802DB7C0 = &D_802DB6C0;
    } else {
        D_802DB7C0 = &D_802DB5C0;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802D33D4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    u32* cmdList = (u32*)get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->entityModelIndex = load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;
    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return ApiStatus_DONE2;
}

ApiStatus func_802D3474(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32* unkStructPtr = (s32*)get_variable(script, *args++);
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        virtualEntity = (*D_802DB7C0)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    virtualEntity->entityModelIndex = load_entity_model(unkStructPtr);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);
    set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus func_802D354C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32* unkStructPtr = (s32*)get_variable(script, *args++);
    VirtualEntity* virtualEntity;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        virtualEntity = (*D_802DB7C0)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    virtualEntity->entityModelIndex = ALT_load_entity_model(unkStructPtr);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);
    set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus func_802D3624(ScriptInstance* script, s32 isInitialCall) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[get_variable(script, *script->ptrReadPos)];

    free_entity_model_by_index(virtualEntity->entityModelIndex);
    virtualEntity->entityModelIndex = -1;
    return ApiStatus_DONE2;
}

ApiStatus func_802D3674(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    u32* commandList = (u32*)get_variable(script, *args++);

    set_entity_model_render_command_list((*D_802DB7C0)[index]->entityModelIndex, commandList);
    return ApiStatus_DONE2;
}

ApiStatus func_802D36E0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->pos.x = x;
    virtualEntity->pos.y = y;
    virtualEntity->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    set_variable(script, outVar1, virtualEntity->pos.x);
    set_variable(script, outVar2, virtualEntity->pos.y);
    set_variable(script, outVar3, virtualEntity->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D3840(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->rot.x = x;
    virtualEntity->rot.y = y;
    virtualEntity->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_802D38EC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->scale.x = x;
    virtualEntity->scale.y = y;
    virtualEntity->scale.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_802D3998(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);

    (*D_802DB7C0)[index]->moveSpeed = get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802D39FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);

    (*D_802DB7C0)[index]->jumpGravity = get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802D3A60(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        s32 index = get_variable(script, *args++);
        f32 xTemp = get_variable(script, *args++);
        f32 yTemp = get_variable(script, *args++);
        f32 zTemp = get_variable(script, *args++);
        s32 moveTime = get_variable(script, *args++);
        f32 goalPosX;
        f32 goalPosZ;

        virtualEntity = (*D_802DB7C0)[index];
        script->functionTemp[1].s = index;

        virtualEntity->goalPos.x = xTemp;
        virtualEntity->goalPos.y = yTemp;
        virtualEntity->goalPos.z = zTemp;

        xTemp = virtualEntity->pos.x;
        zTemp = virtualEntity->pos.z;

        goalPosX = virtualEntity->goalPos.x;
        goalPosZ = virtualEntity->goalPos.z;

        virtualEntity->moveTime = moveTime;
        virtualEntity->moveAngle = atan2(xTemp, zTemp, goalPosX, goalPosZ);
        virtualEntity->moveDist = dist2D(xTemp, zTemp, goalPosX, goalPosZ);

        if (virtualEntity->moveTime == 0.0f) {
            virtualEntity->moveTime = virtualEntity->moveDist / virtualEntity->moveSpeed;
        } else {
            virtualEntity->moveSpeed = virtualEntity->moveDist / virtualEntity->moveTime;
        }

        script->functionTemp[0].s = 1;
    }

    virtualEntity = (*D_802DB7C0)[script->functionTemp[1].s];
    func_802D2F34(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);
    virtualEntity->moveTime--;

    if (virtualEntity->moveTime <= 0.0f) {
        virtualEntity->pos.x = virtualEntity->goalPos.x;
        virtualEntity->pos.z = virtualEntity->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

// float bs
#ifdef NON_MATCHING
ApiStatus func_802D3C58(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;
    s32 index;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;
    s32 moveTime;
    f32 goalPosX;
    f32 goalPosY;
    f32 goalPosZ;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        index = get_variable(script, *args++);
        xTemp = get_variable(script, *args++);
        yTemp = get_variable(script, *args++);
        zTemp = get_variable(script, *args++);
        moveTime = get_variable(script, *args++);

        virtualEntity = (*D_802DB7C0)[index];
        script->functionTemp[1].s = index;

        virtualEntity->goalPos.x = xTemp;
        virtualEntity->goalPos.y = yTemp;
        virtualEntity->goalPos.z = zTemp;

        xTemp = virtualEntity->pos.x;
        yTemp = virtualEntity->pos.y;
        zTemp = virtualEntity->pos.z;

        goalPosX = virtualEntity->goalPos.x;
        goalPosY = virtualEntity->goalPos.y;
        goalPosZ = virtualEntity->goalPos.z;

        goalPosY = goalPosY - yTemp;

        virtualEntity->moveTime = moveTime;
        virtualEntity->moveAngle = atan2(xTemp, zTemp, goalPosX, goalPosZ);
        virtualEntity->moveDist = dist2D(zTemp, zTemp, goalPosX, goalPosZ);

        if (virtualEntity->moveTime == 0.0f) {
            virtualEntity->moveTime = virtualEntity->moveDist / virtualEntity->moveSpeed;
        } else {
            virtualEntity->moveSpeed = virtualEntity->moveDist / virtualEntity->moveTime;
        }

        virtualEntity->jumpVelocity = (virtualEntity->jumpGravity * virtualEntity->moveTime / 2) +
                                      (goalPosY / virtualEntity->moveTime);
        script->functionTemp[0].s = 1;
    }

    virtualEntity = (*D_802DB7C0)[script->functionTemp[1].s];
    virtualEntity->pos.y += virtualEntity->jumpVelocity;
    virtualEntity->jumpVelocity -= virtualEntity->jumpGravity;

    func_802D2F34(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);

    virtualEntity->moveTime -= 1.0f;
    if (virtualEntity->moveTime <= 0.0f) {
        virtualEntity->pos.x = virtualEntity->goalPos.x;
        virtualEntity->pos.y = virtualEntity->goalPos.y;
        virtualEntity->pos.z = virtualEntity->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "evt/player_api", func_802D3C58, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus func_802D3EB8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    VirtualEntity* virtualEntity;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        script->functionTemp[1].s = get_variable(script, *args++);
        script->functionTemp[0].s = 1;
    }

    virtualEntity = (*D_802DB7C0)[script->functionTemp[1].s];
    virtualEntity->pos.y += virtualEntity->jumpVelocity;
    virtualEntity->jumpVelocity -= virtualEntity->jumpGravity;

    func_802D2F34(virtualEntity, virtualEntity->moveSpeed, virtualEntity->moveAngle);

    if (virtualEntity->pos.y < 0.0f) {
        virtualEntity->pos.y = 0.0f;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802D3F74(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 flags = *args++;

    get_entity_model((*D_802DB7C0)[index]->entityModelIndex)->flags = flags;
    return ApiStatus_DONE2;
}

ApiStatus func_802D3FC8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 flags = *args++;
    s32 cond = get_variable(script, *args++);
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    if (cond) {
        set_entity_model_flags(virtualEntity->entityModelIndex, flags);
    } else {
        clear_entity_model_flags(virtualEntity->entityModelIndex, flags);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D4050(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    EntityModel* entityModel = get_entity_model((*D_802DB7C0)[index]->entityModelIndex);

    switch (var2) {
        case -1:
            entityModel->renderMode = 1;
            break;
        case 0:
            entityModel->renderMode = 1;
            get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            break;
        case 2:
            entityModel->renderMode = 0xD;
            get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            break;
        case 3:
            entityModel->renderMode = 0x16;
            get_variable(script, *args++);
            break;
        case 4:
            entityModel->renderMode = 0x16;
            get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            get_variable(script, *args++);
            break;
    }
    return ApiStatus_DONE2;
}

VirtualEntity* func_802D4164(s32 index) {
    return (*D_802DB7C0)[index];
}

VirtualEntity* func_802D417C(s32 index, s32* entityModelData) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->entityModelIndex = load_entity_model(entityModelData);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;
    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return (*D_802DB7C0)[index];
}

s32 func_802D420C(s32* cmdList) {
    s32 i;
    VirtualEntity* virtualEntity;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        virtualEntity = (*D_802DB7C0)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return 0;
    }

    virtualEntity->entityModelIndex = load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return i;
}

VirtualEntity* func_802D42AC(s32* cmdList) {
    s32 i;
    VirtualEntity* virtualEntity;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        virtualEntity = (*D_802DB7C0)[i];
        if (virtualEntity->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return NULL;
    }

    virtualEntity->entityModelIndex = ALT_load_entity_model(cmdList);
    virtualEntity->pos.x = 0.0f;
    virtualEntity->pos.y = 0.0f;
    virtualEntity->pos.z = 0.0f;
    virtualEntity->rot.x = 0.0f;
    virtualEntity->rot.y = 0.0f;
    virtualEntity->rot.z = 0.0f;
    virtualEntity->scale.x = 1.0f;
    virtualEntity->scale.y = 1.0f;
    virtualEntity->scale.z = 1.0f;

    exec_entity_model_commandlist(virtualEntity->entityModelIndex);

    return (*D_802DB7C0)[i];
}

void func_802D4364(s32 index, s32 arg1, s32 arg2, s32 arg3) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->pos.x = arg1;
    virtualEntity->pos.y = arg2;
    virtualEntity->pos.z = arg3;
}

void func_802D43AC(s32 index, f32 arg1, f32 arg2, f32 arg3) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->scale.x = arg1;
    virtualEntity->scale.y = arg2;
    virtualEntity->scale.z = arg3;
}

void func_802D43D0(s32 index, f32 arg1, f32 arg2, f32 arg3) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    virtualEntity->rot.x = arg1;
    virtualEntity->rot.y = arg2;
    virtualEntity->rot.z = arg3;
}

void func_802D43F4(s32 index) {
    VirtualEntity* virtualEntity = (*D_802DB7C0)[index];

    free_entity_model_by_index(virtualEntity->entityModelIndex);
    virtualEntity->entityModelIndex = -1;
}

void func_802D4434(VirtualEntity* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        if ((*D_802DB7C0)[i] == arg0) {
            func_802D43F4(i);
            return;
        }
    }
}

void func_802D4488(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        D_802DB7C0 = &D_802DB6C0;
    } else {
        D_802DB7C0 = &D_802DB5C0;
    }

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        (*D_802DB7C0)[i] = heap_malloc(sizeof(VirtualEntity));
        ASSERT((*D_802DB7C0)[i] != NULL);
        (*D_802DB7C0)[i]->entityModelIndex = -1;
    }

    create_dynamic_entity_world(func_802D2FCC, func_802D3028);
    create_dynamic_entity_backUI(NULL, func_802D31E0);
}

void func_802D4560(void) {
    if (!gGameStatusPtr->isBattle) {
        D_802DB7C0 = &D_802DB6C0;
    } else {
        D_802DB7C0 = &D_802DB5C0;
    }
}
