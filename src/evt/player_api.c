#include "common.h"
#include "npc.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/player.h"

SHIFT_BSS PlayerStatus gPlayerStatus;
SHIFT_BSS PlayerData gPlayerData;

extern Npc playerNpcData;
extern u16 PlayerImgFXFlags;
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
        close_status_bar();
        disable_status_bar_input();
        if (playerStatus->actionState == ACTION_STATE_SPIN) {
            playerStatus->animFlags |= PA_FLAG_INTERRUPT_SPIN;
        }
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    } else {
        enable_player_input();
        partner_enable_input();
        func_800E01DC();
        gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
        enable_status_bar_input();
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

    playerStatus->pos.x = playerNpc->pos.x;
    playerStatus->pos.y = playerNpc->pos.y;
    playerStatus->pos.z = playerNpc->pos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerCollisionSize(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 height = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);

    playerNpc->collisionHeight = height;
    playerNpc->collisionDiameter = radius;

    playerStatus->colliderHeight = playerNpc->collisionHeight;
    playerStatus->colliderDiameter = playerNpc->collisionDiameter;

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

    gPlayerStatus.anim = playerNpc->curAnim = anim;

    if (gPlayerStatus.anim == ANIM_MarioW2_Collapse) {
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
        playerStatus->targetYaw = atan2(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ);

        if (script->functionTemp[0] == 0) {
            script->functionTemp[0] = dist2D(playerStatus->pos.x, playerStatus->pos.z, targetX,
                                               targetZ) / playerNpc->moveSpeed;
            moveSpeed = playerNpc->moveSpeed;
        } else {
            moveSpeed = dist2D(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ) / script->functionTemp[0];
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

        playerStatus->targetYaw = atan2(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ);
        dist = dist2D(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ);
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
        playerStatus->targetYaw = atan2(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ);

        if (playerNpc->duration != 0) {
            playerNpc->moveSpeed = dist2D(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ) / (f32) playerNpc->duration;
        } else {
            playerNpc->duration = dist2D(playerStatus->pos.x, playerStatus->pos.z, targetX, targetZ) / playerNpc->moveSpeed;
            if (playerNpc->duration == 0) {
                playerNpc->duration = 1;
            }
        }

        move_player(playerNpc->duration, playerStatus->targetYaw, playerNpc->moveSpeed);
    }

    return ApiStatus_DONE1;
}

/// Internal function for PlayerJump(), PlayerJump1(), and PlayerJump2().
ApiStatus player_jump(Evt* script, s32 isInitialCall, s32 mode) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;
    f32 jumpVel;
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

        playerNpc->pos.x = playerStatus->pos.x;
        playerNpc->pos.y = playerStatus->pos.y;
        playerNpc->pos.z = playerStatus->pos.z;
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

        playerNpc->jumpVel = (playerNpc->jumpScale * (playerNpc->duration - 1) / 2) + (yTemp / playerNpc->duration);
        playerStatus->flags |= PS_FLAG_FLYING;
        playerStatus->animFlags |= PA_FLAG_NO_OOB_RESPAWN;

        if (mode == 0) {
            if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)) {
                if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                    anim = ANIM_Mario1_Jump;
                } else {
                    anim = ANIM_MarioW1_JumpWatt;
                }
            } else {
                anim = ANIM_MarioW3_8bit_Jump;
            }
            suggest_player_anim_allow_backward(anim);
            sfx_play_sound_at_player(SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT);
        }
        script->functionTemp[0] = 1;
    }

    npc_move_heading(playerNpc, playerNpc->moveSpeed, playerNpc->yaw);
    playerNpc->pos.y += playerNpc->jumpVel;
    jumpVel = playerNpc->jumpVel; // TODO: temp needed and used specifically only once below for this to match
    playerNpc->jumpVel -= playerNpc->jumpScale;

    if (mode == 0 && jumpVel > 0.0f && playerNpc->jumpVel <= 0.0f) {
        if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)) {
            if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                anim = ANIM_Mario1_Fall;
            } else {
                anim = ANIM_MarioW1_FallWatt;
            }
        } else {
            anim = ANIM_MarioW3_8bit_Jump;
        }
        suggest_player_anim_allow_backward(anim);
    }

    playerStatus->pos.x = playerNpc->pos.x;
    playerStatus->pos.y = playerNpc->pos.y;
    playerStatus->pos.z = playerNpc->pos.z;

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
                    anim = ANIM_Mario1_Land;
                } else {
                    anim = ANIM_MarioW1_LandWatt;
                }
            } else {
                anim = ANIM_Mario1_TiredIdle;
            }
            suggest_player_anim_allow_backward(anim);
            spawn_surface_effects(playerNpc, SURFACE_INTERACT_LAND);
        }

        if (mode == 0 || mode == 2) {
            s32 colliderID;

            yTemp = player_check_collision_below(playerNpc->jumpVel, &colliderID);

            if (colliderID >= 0) {
                playerStatus->pos.y = yTemp;
                player_handle_floor_collider_type(colliderID);
                handle_floor_behavior();
            }
        }
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
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
        *angle = atan2(playerStatus->pos.x, playerStatus->pos.z, npc->pos.x, npc->pos.z) - *playerTargetYaw;
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
    Bytecode mode = evt_get_variable(script, *args++);

    if (mode) {
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

    evt_set_variable(script, outVar1, playerStatus->pos.x);
    evt_set_variable(script, outVar2, playerStatus->pos.y);
    evt_set_variable(script, outVar3, playerStatus->pos.z);
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

    playerData->starPower = playerData->maxStarPower * SP_PER_BAR;
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

ApiStatus UseEntryHeading(Evt* script, s32 isInitialCall) {
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
    gPlayerStatus.pos.x = (entryX + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
    gPlayerStatus.pos.z = (entryZ - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);

    script->varTableF[5] = dist2D(gPlayerStatus.pos.x, gPlayerStatus.pos.z, entryX, entryZ) / var2;
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
        f32 temp_f2 = dist2D(entryX, entryZ, playerStatus->pos.x, playerStatus->pos.z) - temp;
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
        gGameStatusPtr->exitTangent = (cosTheta * (playerStatus->pos.x - entryX)) - (sinTheta * (entryZ - playerStatus->pos.z));
        exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
        script->varTable[1] = (playerStatus->pos.x + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
        script->varTable[3] = (playerStatus->pos.z - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);
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
    if ((gCollisionStatus.curFloor >= 0) && func_802D23F8()) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802D2484(Evt* script, s32 isInitialCall) {
    if (gCollisionStatus.curFloor >= 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus IsPlayerOnValidFloor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 result = FALSE;

    if (gCollisionStatus.curFloor >= 0) {
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

ApiStatus UpdatePlayerImgFX(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 a0 = *args++;
    s32 imgfxType = evt_get_variable(script, *args++);
    s32 a2, a3, a4, a5;

    set_player_imgfx_all(a0, IMGFX_CLEAR, 0, 0, 0, 0, 0);

    switch (imgfxType) {
        case IMGFX_CLEAR:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            set_player_imgfx_all(a0, IMGFX_CLEAR, 0, 0, 0, 0, PlayerImgFXFlags);
            break;
        case IMGFX_UNK_2:
        case IMGFX_RESET:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
        case IMGFX_UNK_1:
            set_player_imgfx_all(a0, imgfxType, 0, 0, 0, 0, PlayerImgFXFlags);
            break;
        case IMGFX_SET_WAVY:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_SET_WAVY, a2, a3, a4, 0, PlayerImgFXFlags);
            break;
        case IMGFX_SET_COLOR:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_SET_COLOR, a2, a3, a4, 255, PlayerImgFXFlags);
            break;
        case IMGFX_SET_ALPHA:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a5 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_SET_ALPHA, 255, 255, 255, a5, PlayerImgFXFlags);
            break;
        case IMGFX_SET_TINT:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            a5 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_SET_TINT, a2, a3, a4, a5, PlayerImgFXFlags);
            break;
        case IMGFX_SET_ANIM:
            playerStatus->renderMode = RENDER_MODE_ALPHATEST;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_SET_ANIM, a2, a3, a4, 0, PlayerImgFXFlags);
            break;
        case IMGFX_HOLOGRAM:
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            a2 = evt_get_variable(script, *args++);
            a3 = evt_get_variable(script, *args++);
            a4 = evt_get_variable(script, *args++);
            a5 = evt_get_variable(script, *args++);
            set_player_imgfx_all(a0, IMGFX_HOLOGRAM, a2, a3, a4, a5, PlayerImgFXFlags);
            break;
    }

    PlayerImgFXFlags = 0;
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerImgFXFlags(Evt* script, s32 isInitialCall) {
    s32 imgfxFlags = *script->ptrReadPos;

    PlayerImgFXFlags = imgfxFlags;
    return ApiStatus_DONE2;
}

ApiStatus FacePlayerTowardPoint(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* initialYaw = &script->functionTempF[1];
    f32* deltaYaw = &script->functionTempF[2];
    s32* duration = &script->functionTemp[3];

    if (isInitialCall) {
        f32 targetX = evt_get_float_variable(script, *args++);
        f32 targetY = evt_get_float_variable(script, *args++);
        f32 targetYaw;

        *initialYaw = playerNpc->yaw = playerStatus->targetYaw;

        if (playerStatus->pos.x != targetX || playerStatus->pos.z != targetY) {
            targetYaw = atan2(playerStatus->pos.x, playerStatus->pos.z, targetX, targetY);
        } else {
            targetYaw = playerStatus->targetYaw;
        }

        *deltaYaw = targetYaw - *initialYaw;
        *duration = evt_get_variable(script, *args++);
        playerNpc->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    if (*duration > 0) {
        playerNpc->duration++;
        playerNpc->yaw = *initialYaw + ((*deltaYaw * playerNpc->duration) / *duration);
        playerStatus->targetYaw = playerNpc->yaw = clamp_angle(playerNpc->yaw);
        if (playerNpc->duration < *duration) {
            return ApiStatus_BLOCK;
        } else {
            return ApiStatus_DONE1;
        }
    }

    playerNpc->yaw += *deltaYaw;
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

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        currentPartner = playerData->curPartner;
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

    gPlayerStatus.pushVel.x = x;
    gPlayerStatus.pushVel.y = evt_get_variable(script, *args++);
    gPlayerStatus.pushVel.z = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtPlayer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);

    sfx_play_sound_at_player(soundID, flags);
    return ApiStatus_DONE2;
}
