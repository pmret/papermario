#include "common.h"
#include "npc.h"
#include "sprite.h"
#include "world/partners.h"

extern Npc playerNpcData;
extern u16 D_802DB5B0;
extern s32 D_802DB5B4[3]; // unused

Npc* playerNpc = &playerNpcData;

ApiStatus HidePlayerShadow(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 hideShadow = evt_get_variable(script, *args++);

    if (hideShadow) {
        disable_player_shadow();
    } else {
        enable_player_shadow();
    }
    return ApiStatus_DONE2;
}

ApiStatus DisablePlayerPhysics(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 disable = evt_get_variable(script, *args++);

    if (disable) {
        disable_player_static_collisions();
    } else {
        enable_player_static_collisions();
    }
    return ApiStatus_DONE2;
}

ApiStatus DisablePlayerInput(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 enable = evt_get_variable(script, *args++);

    if (enable) {
        disable_player_input();
        partner_disable_input();
        close_status_menu();
        func_800E984C();
        if (playerStatus->actionState == ACTION_STATE_SPIN) {
            playerStatus->animFlags |= PA_FLAG_INTERRUPT_SPIN;
        }
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    } else {
        enable_player_input();
        partner_enable_input();
        func_800E01DC();
        gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
        func_800E983C();
    }
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerPos(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);

    playerNpc->pos.x = x;
    playerNpc->pos.y = y;
    playerNpc->pos.z = z;

    playerStatus->position.x = playerNpc->pos.x;
    playerStatus->position.y = playerNpc->pos.y;
    playerStatus->position.z = playerNpc->pos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerCollisionSize(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 height = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);

    playerNpc->collisionHeight = height;
    playerNpc->collisionRadius = radius;

    playerStatus->colliderHeight = playerNpc->collisionHeight;
    playerStatus->colliderDiameter = playerNpc->collisionRadius;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    playerNpc->moveSpeed = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerJumpscale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    playerNpc->jumpScale = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    AnimID anim = evt_get_variable(script, *args++);

    gPlayerStatus.anim = playerNpc->currentAnim = anim;

    if (gPlayerStatus.anim == ANIM_Mario_80003) {
        exec_ShakeCam1(0, 0, 2);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerActionState(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_action_state(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerAnimationSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    playerNpc->animationSpeed = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus PlayerMoveTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = evt_get_variable(script, *args++);
        f32 targetZ = evt_get_variable(script, *args++);
        f32 moveSpeed;

        script->functionTemp[0] = evt_get_variable(script, *args++);
        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);

        if (script->functionTemp[0] == 0) {
            script->functionTemp[0] = dist2D(playerStatus->position.x, playerStatus->position.z, targetX,
                                               targetZ) / playerNpc->moveSpeed;
            moveSpeed = playerNpc->moveSpeed;
        } else {
            moveSpeed = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ) / script->functionTemp[0];
        }
        move_player(script->functionTemp[0], playerStatus->targetYaw, moveSpeed);
    }

    // functionTemp 0 is the time left
    script->functionTemp[0]--;
    return script->functionTemp[0] < 0;
}

ApiStatus func_802D1270(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = evt_get_variable(script, *args++);
        f32 targetZ = evt_get_variable(script, *args++);
        f32 var3 = evt_get_float_variable(script, *args++);
        f32 dist;
        f32 moveSpeed;

        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);
        dist = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);
        script->functionTemp[0] = dist / var3;
        moveSpeed = dist / script->functionTemp[0];

        move_player(script->functionTemp[0], playerStatus->targetYaw, moveSpeed);
    }

    // functionTemp 0 is the time left
    script->functionTemp[0]--;
    return (script->functionTemp[0] < 0) * ApiStatus_DONE2;
}

ApiStatus func_802D1380(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 targetX = evt_get_variable(script, *args++);
        f32 targetZ = evt_get_variable(script, *args++);

        playerNpc->duration = evt_get_variable(script, *args++);
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

s32 player_jump(Evt* script, s32 isInitialCall, s32 mode) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;
    f32 jumpVelocity;
    s32 duration;
    AnimID anim;
    f32 dist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        xTemp = evt_get_variable(script, *args++);
        yTemp = evt_get_variable(script, *args++);
        zTemp = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);

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
        playerStatus->flags |= PS_FLAG_FLYING;
        playerStatus->animFlags |= PA_FLAG_NO_OOB_RESPAWN;

        if (mode == 0) {
            if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)) {
                if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                    anim = ANIM_Mario_AnimMidairStill;
                } else {
                    anim = ANIM_Mario_60009;
                }
            } else {
                anim = ANIM_Mario_90005;
            }
            suggest_player_anim_clearUnkFlag(anim);
            sfx_play_sound_at_player(SOUND_JUMP_2081, SOUND_SPACE_MODE_0);
        }
        script->functionTemp[0] = 1;
    }

    npc_move_heading(playerNpc, playerNpc->moveSpeed, playerNpc->yaw);
    playerNpc->pos.y += playerNpc->jumpVelocity;
    jumpVelocity = playerNpc->jumpVelocity; // TODO: temp needed and used specifically only once below for this to match
    playerNpc->jumpVelocity -= playerNpc->jumpScale;

    if (mode == 0 && jumpVelocity > 0.0f && playerNpc->jumpVelocity <= 0.0f) {
        if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)) {
            if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                anim = ANIM_Mario_AnimMidair;
            } else {
                anim = ANIM_Mario_6000A;
            }
        } else {
            anim = ANIM_Mario_90005;
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    playerStatus->position.x = playerNpc->pos.x;
    playerStatus->position.y = playerNpc->pos.y;
    playerStatus->position.z = playerNpc->pos.z;

    if (mode == 0) {
        playerStatus->targetYaw = playerNpc->yaw;
    }

    playerNpc->duration--;
    if (playerNpc->duration == 0) {
        playerStatus->flags &= ~PS_FLAG_FLYING;
        playerStatus->animFlags &= ~PA_FLAG_NO_OOB_RESPAWN;

        if (mode == 0) {
            if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)) {
                if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                    anim = ANIM_Mario_10009;
                } else {
                    anim = ANIM_Mario_6000B;
                }
            } else {
                anim = ANIM_Mario_AnimPanting;
            }
            suggest_player_anim_clearUnkFlag(anim);
            func_8003D660(playerNpc, 2);
        }

        if (mode == 0 || mode == 2) {
            s32 colliderID;

            yTemp = player_check_collision_below(playerNpc->jumpVelocity, &colliderID);

            if (colliderID >= 0) {
                playerStatus->position.y = yTemp;
                player_handle_floor_collider_type(colliderID);
                handle_floor_behavior();
            }
        }
        return TRUE;
    }
    return FALSE;
}

ApiStatus PlayerJump(Evt* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 0);
}

ApiStatus PlayerJump1(Evt* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 1);
}

ApiStatus PlayerJump2(Evt* script, s32 isInitialCall) {
    return player_jump(script, isInitialCall, 2);
}

ApiStatus InterpPlayerYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* time = &script->functionTemp[3];

    if (isInitialCall) {
        playerNpc->yaw = playerStatus->targetYaw;
        *initialYaw = playerNpc->yaw;
        *deltaYaw = evt_get_float_variable(script, *args++) - *initialYaw;
        *time = evt_get_variable(script, *args++);
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

ApiStatus PlayerFaceNpc(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* args = script->ptrReadPos;
    f32* playerTargetYaw = &script->functionTempF[1];
    f32* angle = &script->functionTempF[2];
    s32* ft3 = &script->functionTemp[3];

    if (isInitialCall) {
        s32 npcID = evt_get_variable(script, *args++);
        Npc* npc;

        if (npcID == NPC_SELF) {
            npc = get_npc_safe(script->owner2.npcID);
        } else if (npcID < EVT_LIMIT) {
            npc = (Npc*)npcID;
        } else {
            npc = get_npc_safe(npcID);
            if (npc == NULL) {
                return ApiStatus_DONE2;
            }
        }

        *playerTargetYaw = playerNpc->yaw = playerStatus->targetYaw;
        *angle = atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z) - *playerTargetYaw;
        *ft3 = evt_get_variable(script, *args++);

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

ApiStatus GetPlayerTargetYaw(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerStatus.targetYaw);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode bits = *args++;
    Bytecode a1 = *args;

    if (evt_get_variable(script, a1)) {
        playerStatus->flags |= bits;
    } else {
        playerStatus->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPlayerActionState(Evt* script, s32 isInitialCall) {
    Bytecode outVar = *script->ptrReadPos;
    evt_set_variable(script, outVar, gPlayerStatus.actionState);
    return ApiStatus_DONE2;
}

ApiStatus GetPlayerPos(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;

    evt_set_variable(script, outVar1, playerStatus->position.x);
    evt_set_variable(script, outVar2, playerStatus->position.y);
    evt_set_variable(script, outVar3, playerStatus->position.z);
    return ApiStatus_DONE2;
}

ApiStatus GetPlayerAnimation(Evt* script, s32 isInitialCall) {
    Bytecode outVar = *script->ptrReadPos;

    evt_set_variable(script, outVar, gPlayerStatus.anim);
    return ApiStatus_DONE2;
}

ApiStatus FullyRestoreHPandFP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    return ApiStatus_DONE2;
}

ApiStatus FullyRestoreSP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->specialBarsFilled = playerData->maxStarPower * 256;
    return ApiStatus_DONE2;
}

ApiStatus EnablePartner(Evt* script, s32 isInitialCall) {
    s32 partnerIdx = evt_get_variable(script, *script->ptrReadPos) - 1;
    PartnerData* partner = &gPlayerData.partners[partnerIdx];

    partner->enabled = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus DisablePartner(Evt* script, s32 isInitialCall) {
    s32 partnerIdx = evt_get_variable(script, *script->ptrReadPos) - 1;
    PartnerData* partner = &gPlayerData.partners[partnerIdx];

    partner->enabled = FALSE;
    return ApiStatus_DONE2;
}

ApiStatus UseEntryHeading(Evt *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MapSettings* mapSettings = get_current_map_settings();
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    f32 entryX = script->varTable[1] = (*mapSettings->entryList)[gGameStatusPtr->entryID].x;
    f32 entryY = script->varTable[2] = (*mapSettings->entryList)[gGameStatusPtr->entryID].y;
    f32 entryZ = script->varTable[3] = (*mapSettings->entryList)[gGameStatusPtr->entryID].z;
    f32 cosTheta;
    f32 sinTheta;
    f32 exitTangentFrac;

    sin_cos_deg(clamp_angle((*mapSettings->entryList)[gGameStatusPtr->entryID].yaw + 180.0f), &sinTheta, &cosTheta);

    exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
    gPlayerStatus.position.x = (entryX + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
    gPlayerStatus.position.z = (entryZ - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);

    script->varTableF[5] = dist2D(gPlayerStatus.position.x, gPlayerStatus.position.z, entryX, entryZ) / var2;
    gPlayerStatus.flags |= PS_FLAG_CAMERA_DOESNT_FOLLOW;

    return ApiStatus_DONE2;
}

ApiStatus func_802D2148(Evt* script, s32 isInitialCall) {
    gPlayerStatus.flags &= ~PS_FLAG_CAMERA_DOESNT_FOLLOW;
    return ApiStatus_DONE2;
}

ApiStatus UseExitHeading(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapSettings* mapSettings = get_current_map_settings();
    f32* varTableVar5 = &script->varTableF[5];

    if (can_trigger_loading_zone()) {
        s32 var1 = evt_get_variable(script, *args++);
        s32 entryID = evt_get_variable(script, *args++);
        f32 entryX = (*mapSettings->entryList)[entryID].x;
        f32 entryZ = (*mapSettings->entryList)[entryID].z;
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

        sin_cos_deg(clamp_angle((*mapSettings->entryList)[entryID].yaw + 180.0f), &sinTheta, &cosTheta);
        gGameStatusPtr->exitTangent = (cosTheta * (playerStatus->position.x - entryX)) - (sinTheta * (entryZ - playerStatus->position.z));
        exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
        script->varTable[1] = (playerStatus->position.x + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
        script->varTable[3] = (playerStatus->position.z - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);
        script->varTable[2] = (*mapSettings->entryList)[entryID].y;
        *varTableVar5 = var1 / 15;
        playerStatus->animFlags |= PA_FLAG_CHANGING_MAP;
        playerStatus->flags |= PS_FLAG_CAMERA_DOESNT_FOLLOW;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

s32 func_802D23F8(void) {
    if (gPlayerStatus.actionState == ACTION_STATE_IDLE || gPlayerStatus.actionState == ACTION_STATE_WALK ||
        gPlayerStatus.actionState == ACTION_STATE_RUN || gPlayerStatus.actionState == ACTION_STATE_LAND ||
        gPlayerStatus.actionState == ACTION_STATE_STEP_DOWN_LAND || gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND ||
        gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND || gPlayerStatus.actionState == ACTION_STATE_SPIN) {
        return TRUE;
    }
    return FALSE;
}

ApiStatus WaitForPlayerTouchingFloor(Evt* script, s32 isInitialCall) {
    if ((gCollisionStatus.currentFloor >= 0) && func_802D23F8()) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802D2484(Evt* script, s32 isInitialCall) {
    if (gCollisionStatus.currentFloor >= 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus IsPlayerOnValidFloor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 result = FALSE;

    if (gCollisionStatus.currentFloor >= 0) {
        result = (func_802D23F8() != 0);
    }
    evt_set_variable(script, *args++, result);

    return ApiStatus_DONE2;
}

ApiStatus WaitForPlayerMoveToComplete(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.moveFrames == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus WaitForPlayerInputEnabled(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.flags & PS_FLAG_INPUT_DISABLED) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus func_802D2520(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 a0 = *args++;
    s32 foldType = evt_get_variable(script, *args++);
    s32 a2, a3, a4, a5;

    func_802DDFF8(a0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0);

    switch (foldType) {
        case FOLD_TYPE_NONE:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            func_802DDFF8(a0, FOLD_TYPE_NONE, 0, 0, 0, 0, D_802DB5B0);
            break;
        case FOLD_TYPE_2:
        case FOLD_TYPE_3:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
        case FOLD_TYPE_1:
            func_802DDFF8(a0, foldType, 0, 0, 0, 0, D_802DB5B0);
            break;
        case FOLD_TYPE_4:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_4, a2, a3, a4, 0, D_802DB5B0);
            break;
        case FOLD_TYPE_6:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_6, a2, a3, a4, 255, D_802DB5B0);
            break;
        case FOLD_TYPE_7:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a5 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_7, 255, 255, 255, a5, D_802DB5B0);
            break;
        case FOLD_TYPE_8:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            a5 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_8, a2, a3, a4, a5, D_802DB5B0);
            break;
        case FOLD_TYPE_5:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_5, a2, a3, a4, 0, D_802DB5B0);
            break;
        case FOLD_TYPE_D:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            a5 = evt_get_variable(script, *args++);
            func_802DDFF8(a0, FOLD_TYPE_D, a2, a3, a4, a5, D_802DB5B0);
            break;
    }

    D_802DB5B0 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802D286C(Evt* script, s32 isInitialCall) {
    s32 temp = *script->ptrReadPos;

    D_802DB5B0 = temp;
    return ApiStatus_DONE2;
}

ApiStatus func_802D2884(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* ft1 = &script->functionTempF[1];
    f32* angle = &script->functionTempF[2];
    s32* ft3 = &script->functionTemp[3];

    if (isInitialCall) {
        f32 x = evt_get_float_variable(script, *args++);
        f32 z = evt_get_float_variable(script, *args++);
        f32 yawTemp;

        *ft1 = playerNpc->yaw = playerStatus->targetYaw;

        if (playerStatus->position.x != x || playerStatus->position.z != z) {
            yawTemp = atan2(playerStatus->position.x, playerStatus->position.z, x, z);
        } else {
            yawTemp = playerStatus->targetYaw;
        }

        *angle = yawTemp - *ft1;
        *ft3 = evt_get_variable(script, *args++);
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

ApiStatus DisablePulseStone(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (evt_get_variable(script, *script->ptrReadPos)) {
        playerStatus->animFlags &= ~PA_FLAG_USING_PULSE_STONE;
    } else {
        playerStatus->animFlags |= PA_FLAG_USING_PULSE_STONE;
    }

    return ApiStatus_DONE2;
}

// returns partnerID of current partner if using their ability, otherwise PARTNER_NONE
ApiStatus GetPartnerInUse(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    PlayerData* playerData = &gPlayerData;
    s32 currentPartner = PARTNER_NONE;

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        currentPartner = playerData->currentPartner;
    }

    evt_set_variable(script, outVar, currentPartner);
    return ApiStatus_DONE2;
}

ApiStatus ForceUsePartner(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAG_FORCE_USE_PARTNER;
    return ApiStatus_DONE2;
}

ApiStatus InterruptUsePartner(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
    return ApiStatus_DONE2;
}

ApiStatus Disable8bitMario(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (evt_get_variable(script, *args)) {
        playerStatus->colliderHeight = 37;
        playerStatus->colliderDiameter = 26;
        playerStatus->animFlags &= ~PA_FLAG_8BIT_MARIO;
    } else {
        playerStatus->colliderHeight = 19;
        playerStatus->colliderDiameter = 26;
        playerStatus->animFlags |= PA_FLAG_8BIT_MARIO
            | PA_FLAG_INTERRUPT_SPIN
            | PA_FLAG_INTERRUPT_USE_PARTNER;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D2C14(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_800EF3D4(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerPushVelocity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_variable(script, *args++);
    f32 y;
    f32 z;

    gPlayerStatus.pushVelocity.x = x;
    gPlayerStatus.pushVelocity.y = evt_get_variable(script, *args++);
    gPlayerStatus.pushVelocity.z = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtPlayer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);

    sfx_play_sound_at_player(soundID, flags);
    return ApiStatus_DONE2;
}
