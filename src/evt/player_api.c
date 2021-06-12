#include "common.h"

typedef struct UnkF5750 {
    /* 0x00 */ s32 entityModelIndex;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0x10];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} UnkF5750;

typedef UnkF5750* UnkF5750List[0x40];

extern s16 D_802DB5B0;
extern s32 D_802DB5C0;
extern s32 D_802DB6C0;
extern UnkF5750List* D_802DB7C0;

Npc* playerNpc = (Npc*) 0x802DB270; // XXX: raw ptr

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
    Bytecode* args = script->ptrReadPos;
    s32 height = get_variable(script, *args++);
    s32 radius = get_variable(script, *args);
    PlayerStatus* playerStatus = &gPlayerStatus;

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

    playerNpc->currentAnim = currentAnim;

    do { } while (0); // Needed to match for some reason

    gPlayerAnimation = playerNpc->currentAnim;

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

INCLUDE_ASM(s32, "evt/player_api", func_802D1270);

INCLUDE_ASM(s32, "evt/player_api", func_802D1380);

INCLUDE_ASM(s32, "evt/player_api", player_jump);

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

INCLUDE_ASM(s32, "evt/player_api", PlayerFaceNpc, ScriptInstance* script, s32 isInitialCall);

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
    f32 entryX = script->varTable[1].s = (*mapConfig->entryList)[gGameStatusPtr->entryID].x;
    f32 entryY = script->varTable[2].s = (*mapConfig->entryList)[gGameStatusPtr->entryID].y;
    f32 entryZ = script->varTable[3].s = (*mapConfig->entryList)[gGameStatusPtr->entryID].z;
    f32 cosTheta;
    f32 sinTheta;
    f32 exitTangentFrac;

    sin_cos_deg(clamp_angle((*mapConfig->entryList)[gGameStatusPtr->entryID].yaw + 180.0f), &sinTheta, &cosTheta);

    exitTangentFrac = gGameStatusPtr->exitTangent * 0.3f;
    gPlayerStatus.position.x = (entryX + (var1 * sinTheta)) - (exitTangentFrac * cosTheta);
    gPlayerStatus.position.z = (entryZ - (var1 * cosTheta)) - (exitTangentFrac * sinTheta);

    script->varTable[5].f = dist2D(gPlayerStatus.position.x, gPlayerStatus.position.z, entryX, entryZ) / var2;
    gPlayerStatus.flags |= 0x4000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802D2148(ScriptInstance* script, s32 isInitialCall) {
    gPlayerStatus.flags &= ~0x4000000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "evt/player_api", UseExitHeading, ScriptInstance* script, s32 isInitialCall);

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

INCLUDE_ASM(ApiStatus, "evt/player_api", func_802D2520, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802D286C(ScriptInstance* script, s32 isInitialCall) {
    s32 temp = *script->ptrReadPos;

    D_802DB5B0 = temp;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "evt/player_api", func_802D2884, ScriptInstance* script, s32 isInitialCall);

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

s32 func_802D2D30(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7);
INCLUDE_ASM(s32, "evt/player_api", func_802D2D30, u8 arg0, u8 arg1, u8 arg2, u8 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7);

void func_802D2ED4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u16 temp1 = arg4 + arg6;
    u16 temp2 = arg5 + arg7;

    func_802D2D30(arg0, arg1, arg2, arg3, arg4, arg5, temp1, temp2);
}

INCLUDE_ASM(void, "evt/player_api", func_802D2F34, UnkF5750* arg0, f32 arg1, f32 arg2);

void func_802D2FCC(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        UnkF5750* temp = (*D_802DB7C0)[i];

        if (temp != NULL && temp->entityModelIndex >= 0) {
            exec_entity_model_commandlist(temp->entityModelIndex);
        }
    }
}

INCLUDE_ASM(s32, "evt/player_api", func_802D3028);

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
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->entityModelIndex = load_entity_model(cmdList);
    temp->unk_04 = 0.0f;
    temp->unk_08 = 0.0f;
    temp->unk_0C = 0.0f;
    temp->unk_10 = 0.0f;
    temp->unk_14 = 0.0f;
    temp->unk_18 = 0.0f;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;
    exec_entity_model_commandlist(temp->entityModelIndex);

    return ApiStatus_DONE2;
}

ApiStatus func_802D3474(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32* unkStructPtr = get_variable(script, *args++);
    UnkF5750* temp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        temp = (*D_802DB7C0)[i];
        if (temp->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    temp->entityModelIndex = load_entity_model(unkStructPtr);
    temp->unk_04 = 0.0f;
    temp->unk_08 = 0.0f;
    temp->unk_0C = 0.0f;
    temp->unk_10 = 0.0f;
    temp->unk_14 = 0.0f;
    temp->unk_18 = 0.0f;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;

    exec_entity_model_commandlist(temp->entityModelIndex);
    set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus func_802D354C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32* unkStructPtr = get_variable(script, *args++);
    UnkF5750* temp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        temp = (*D_802DB7C0)[i];
        if (temp->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    temp->entityModelIndex = ALT_load_entity_model(unkStructPtr);
    temp->unk_04 = 0.0f;
    temp->unk_08 = 0.0f;
    temp->unk_0C = 0.0f;
    temp->unk_10 = 0.0f;
    temp->unk_14 = 0.0f;
    temp->unk_18 = 0.0f;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;

    exec_entity_model_commandlist(temp->entityModelIndex);
    set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

ApiStatus func_802D3624(ScriptInstance* script, s32 isInitialCall) {
    UnkF5750* temp = (*D_802DB7C0)[get_variable(script, *script->ptrReadPos)];

    free_entity_model_by_index(temp->entityModelIndex);
    temp->entityModelIndex = -1;
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
    f32 f1 = get_float_variable(script, *args++);
    f32 f2 = get_float_variable(script, *args++);
    f32 f3 = get_float_variable(script, *args++);
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_04 = f1;
    temp->unk_08 = f2;
    temp->unk_0C = f3;
    return ApiStatus_DONE2;
}

ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    UnkF5750* temp = (*D_802DB7C0)[index];
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    set_variable(script, outVar1, temp->unk_04);
    set_variable(script, outVar2, temp->unk_08);
    set_variable(script, outVar3, temp->unk_0C);
    return ApiStatus_DONE2;
}

ApiStatus func_802D3840(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 f1 = get_float_variable(script, *args++);
    f32 f2 = get_float_variable(script, *args++);
    f32 f3 = get_float_variable(script, *args++);
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_10 = f1;
    temp->unk_14 = f2;
    temp->unk_18 = f3;
    return ApiStatus_DONE2;
}

ApiStatus func_802D38EC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 f1 = get_float_variable(script, *args++);
    f32 f2 = get_float_variable(script, *args++);
    f32 f3 = get_float_variable(script, *args++);
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_1C = f1;
    temp->unk_20 = f2;
    temp->unk_24 = f3;
    return ApiStatus_DONE2;
}

ApiStatus func_802D3998(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);

    (*D_802DB7C0)[index]->unk_3C = get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802D39FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);

    (*D_802DB7C0)[index]->unk_40 = get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/player_api", func_802D3A60);

INCLUDE_ASM(ApiStatus, "evt/player_api", func_802D3C58, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802D3EB8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkF5750* temp;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        script->functionTemp[1].s = get_variable(script, *args++);
        script->functionTemp[0].s = 1;
    }

    temp = (*D_802DB7C0)[script->functionTemp[1].s];
    temp->unk_08 += temp->unk_44;
    temp->unk_44 -= temp->unk_40;

    func_802D2F34(temp, temp->unk_3C, temp->unk_38);

    if (temp->unk_08 < 0.0f) {
        temp->unk_08 = 0.0f;
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
    UnkF5750* temp = (*D_802DB7C0)[index];

    if (cond) {
        set_entity_model_flags(temp->entityModelIndex, flags);
    } else {
        clear_entity_model_flags(temp->entityModelIndex, flags);
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/player_api", func_802D4050);

UnkF5750* func_802D4164(s32 index) {
    return (*D_802DB7C0)[index];
}

UnkF5750* func_802D417C(s32 arg0, s32* entityModelData) {
    UnkF5750* temp = (*D_802DB7C0)[arg0];

    temp->entityModelIndex = load_entity_model(entityModelData);
    temp->unk_04 = 0.0f;
    temp->unk_08 = 0.0f;
    temp->unk_0C = 0.0f;
    temp->unk_10 = 0.0f;
    temp->unk_14 = 0.0f;
    temp->unk_18 = 0.0f;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;
    exec_entity_model_commandlist(temp->entityModelIndex);

    return (*D_802DB7C0)[arg0];
}

s32 func_802D420C(s32* cmdList) {
    s32 i;
    UnkF5750* temp;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        temp = (*D_802DB7C0)[i];
        if (temp->entityModelIndex < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return 0;
    }

    temp->entityModelIndex = load_entity_model(cmdList);
    temp->unk_04 = 0.0f;
    temp->unk_08 = 0.0f;
    temp->unk_0C = 0.0f;
    temp->unk_10 = 0.0f;
    temp->unk_14 = 0.0f;
    temp->unk_18 = 0.0f;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;

    exec_entity_model_commandlist(temp->entityModelIndex);

    return i;
}

INCLUDE_ASM(s32, "evt/player_api", func_802D42AC);

void func_802D4364(s32 index, s32 arg1, s32 arg2, s32 arg3) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_04 = arg1;
    temp->unk_08 = arg2;
    temp->unk_0C = arg3;
}

void func_802D43AC(s32 index, f32 arg1, f32 arg2, f32 arg3) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_1C = arg1;
    temp->unk_20 = arg2;
    temp->unk_24 = arg3;
}

void func_802D43D0(s32 index, f32 arg1, f32 arg2, f32 arg3) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_10 = arg1;
    temp->unk_14 = arg2;
    temp->unk_18 = arg3;
}

void func_802D43F4(s32 index) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    free_entity_model_by_index(temp->entityModelIndex);
    temp->entityModelIndex = -1;
}

void func_802D4434(UnkF5750* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        if ((*D_802DB7C0)[i] == arg0) {
            func_802D43F4(i);
            return;
        }
    }
}

INCLUDE_ASM(s32, "evt/player_api", func_802D4488);

void func_802D4560(void) {
    if (!gGameStatusPtr->isBattle) {
        D_802DB7C0 = &D_802DB6C0;
    } else {
        D_802DB7C0 = &D_802DB5C0;
    }
}
