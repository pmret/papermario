#include "common.h"

typedef struct UnkF5750 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
} UnkF5750;

typedef UnkF5750* UnkF5750List[0x40];

extern s16 D_802DB5B0;
extern UnkF5750List* D_802DB7C0;

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
        if (playerStatus->actionState == ActionState_SPIN) {
            playerStatus->animFlags |= 0x40000;
        }
        D_8009A650[0] |= 0x40;
    } else {
        enable_player_input();
        func_800EF600();
        func_800E01DC();
        D_8009A650[0] &= ~0x40;
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

    gPlayerNpcPtr->pos.x = x;
    gPlayerNpcPtr->pos.y = y;
    gPlayerNpcPtr->pos.z = z;

    playerStatus->position.x = gPlayerNpcPtr->pos.x;
    playerStatus->position.y = gPlayerNpcPtr->pos.y;
    playerStatus->position.z = gPlayerNpcPtr->pos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerCollisionSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 height = get_variable(script, *args++);
    s32 radius = get_variable(script, *args);
    Npc* player = gPlayerNpcPtr;
    PlayerStatus* playerStatus = &gPlayerStatus;

    player->collisionHeight = height;
    player->collisionRadius = radius;

    playerStatus->colliderHeight = player->collisionHeight;
    playerStatus->colliderDiameter = player->collisionRadius;

    return ApiStatus_DONE2;
}

ApiStatus SetPlayerSpeed(ScriptInstance* script, s32 isInitialCall) {
    gPlayerNpcPtr->moveSpeed = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerJumpscale(ScriptInstance* script, s32 isInitialCall) {
    gPlayerNpcPtr->jumpScale = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus SetPlayerAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerAnim animation;

    animation = get_variable(script, *args);

    gPlayerNpcPtr->currentAnim = animation;
    gPlayerAnimation = animation;

    if (animation == 0x80003) {
        exec_ShakeCam1(0, 0, 2);
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_F5750", SetPlayerAnimation, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus SetPlayerActionState(ScriptInstance* script, s32 isInitialCall) {
    set_action_state(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerAnimationSpeed(ScriptInstance* script, s32 isInitialCall) {
    gPlayerNpcPtr->animationSpeed = get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus PlayerMoveTo(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = PLAYER_STATUS;

    if (isInitialCall) {
        f32 targetX = get_variable(script, *args++);
        f32 targetZ = get_variable(script, *args++);
        f32 moveSpeed;

        script->functionTemp[0].s = get_variable(script, *args++);
        playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, targetX, targetZ);

        if (script->functionTemp[0].s == 0) {
            script->functionTemp[0].s = dist2D(playerStatus->position.x, playerStatus->position.z, targetX,
                                               targetZ) / gPlayerNpcPtr->moveSpeed;
            moveSpeed = gPlayerNpcPtr->moveSpeed;
        } else {
            moveSpeed = dist2D(playerStatus->position.x, playerStatus->position.z, targetX, targetZ) / script->functionTemp[0].s;
        }
        move_player(script->functionTemp[0].s, playerStatus->targetYaw, moveSpeed);
    }

    // functionTemp 0 is the time left
    script->functionTemp[0].s--;
    return script->functionTemp[0].s < 0;
}

INCLUDE_ASM(s32, "code_F5750", func_802D1270);

INCLUDE_ASM(s32, "code_F5750", func_802D1380);

INCLUDE_ASM(s32, "code_F5750", player_jump);

void PlayerJump(ScriptInstance* script, s32 isInitialCall) {
    player_jump(script, isInitialCall, 0);
}

void PlayerJump1(ScriptInstance* script, s32 isInitialCall) {
    player_jump(script, isInitialCall, 1);
}

void PlayerJump2(ScriptInstance* script, s32 isInitialCall) {
    player_jump(script, isInitialCall, 2);
}

ApiStatus InterpPlayerYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = PLAYER_STATUS;
    f32* initialYaw = &script->functionTemp[1].f;
    f32* deltaYaw = &script->functionTemp[2].f;
    s32* time = &script->functionTemp[3].s;

    if (isInitialCall) {
        Npc** player = &gPlayerNpcPtr;

        (*player)->yaw = playerStatus->targetYaw;
        *initialYaw = (*player)->yaw;
        *deltaYaw = get_float_variable(script, *args++) - *initialYaw;
        *time = get_variable(script, *args++);
        (*player)->duration = 0;

        if (*deltaYaw < -180.0f) {
            *deltaYaw += 360.0f;
        }
        if (*deltaYaw > 180.0f) {
            *deltaYaw -= 360.0f;
        }
    }

    if (*time > 0) {
        Npc** player = &gPlayerNpcPtr;

        (*player)->duration++;
        (*player)->yaw = *initialYaw + ((*deltaYaw * (*player)->duration) / *time);
        (*player)->yaw = clamp_angle((*player)->yaw);
        playerStatus->targetYaw = (*player)->yaw;

        return !((*player)->duration < *time);
    } else {
        Npc** player = &gPlayerNpcPtr;

        (*player)->yaw += *deltaYaw;
        (*player)->yaw = clamp_angle((*player)->yaw);
        playerStatus->targetYaw = (*player)->yaw;

        return ApiStatus_DONE2;
    }
}

INCLUDE_ASM(s32, "code_F5750", PlayerFaceNpc, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetPlayerTargetYaw(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerStatus.targetYaw);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;
    Bytecode bits = *args++;
    Bytecode a1 = *args;

    if (get_variable(script, a1)) {
        playerStatus->flags |= bits;
    } else {
        playerStatus2->flags &= ~bits;
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

INCLUDE_ASM(s32, "code_F5750", UseEntryHeading);

ApiStatus func_802D2148(ScriptInstance* script, s32 isInitialCall) {
    gPlayerStatus.flags &= ~0x4000000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_F5750", UseExitHeading);

INCLUDE_ASM(s32, "code_F5750", func_802D23F8);

ApiStatus WaitForPlayerTouchingFloor(ScriptInstance* script, s32 isInitialCall) {
    if ((gCollisionStatus.currentFloor >= 0) && (func_802D23F8() != 0)) {
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

INCLUDE_ASM(s32, "code_F5750", func_802D2520);

ApiStatus func_802D286C(ScriptInstance* script, s32 isInitialCall) {
    s32 temp = *script->ptrReadPos;

    D_802DB5B0 = temp;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_F5750", func_802D2884);

ApiStatus DisablePulseStone(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;

    if (get_variable(script, *script->ptrReadPos)) {
        playerStatus->animFlags &= ~0x80;
    } else {
        playerStatus2->animFlags |= 0x80;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetCurrentPartner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args;
    PlayerData* playerData = &gPlayerData;
    s32 currentPartner = 0;

    if (D_8010EBB0[0] != 0) {
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
    PlayerStatus* playerStatus2 = &gPlayerStatus;

    if (get_variable(script, *args)) {
        playerStatus->colliderHeight = 37;
        playerStatus->colliderDiameter = 26;
        playerStatus->animFlags &= ~0x4000;
    } else {
        playerStatus2->colliderHeight = 19;
        playerStatus2->colliderDiameter = 26;
        playerStatus2->animFlags |= 0x44004;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802D2C14(ScriptInstance* script, s32 isInitialCall) {
    func_800EF3D4(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802D2C40(ScriptInstance *script) {
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

    play_sound_at_player(var, var2);
    return 2;
}

INCLUDE_ASM(s32, "code_F5750", func_802D2D30);

INCLUDE_ASM(s32, "code_F5750", func_802D2ED4);

INCLUDE_ASM(s32, "code_F5750", func_802D2F34);

INCLUDE_ASM(s32, "code_F5750", func_802D2FCC);

INCLUDE_ASM(s32, "code_F5750", func_802D3028);

INCLUDE_ASM(s32, "code_F5750", func_802D31E0);

INCLUDE_ASM(s32, "code_F5750", func_802D3398);

INCLUDE_ASM(s32, "code_F5750", func_802D33D4);

ApiStatus func_802D3474(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32* unkStructPtr = get_variable(script, *args++);
    UnkF5750* temp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*D_802DB7C0); i++) {
        temp = (*D_802DB7C0)[i];
        if (temp->unk_00 < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    temp->unk_00 = load_entity_model(unkStructPtr);
    temp->unk_04 = 0;
    temp->unk_08 = 0;
    temp->unk_0C = 0;
    temp->unk_10 = 0;
    temp->unk_14 = 0;
    temp->unk_18 = 0;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;

    update_entity_rendercmd(temp->unk_00);
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
        if (temp->unk_00 < 0) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(*D_802DB7C0)) {
        return ApiStatus_DONE2;
    }

    temp->unk_00 = ALT_load_entity_model(unkStructPtr);
    temp->unk_04 = 0;
    temp->unk_08 = 0;
    temp->unk_0C = 0;
    temp->unk_10 = 0;
    temp->unk_14 = 0;
    temp->unk_18 = 0;
    temp->unk_1C = 1.0f;
    temp->unk_20 = 1.0f;
    temp->unk_24 = 1.0f;

    update_entity_rendercmd(temp->unk_00);
    set_variable(script, outVar, i);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_F5750", func_802D3624);

INCLUDE_ASM(s32, "code_F5750", func_802D3674);

INCLUDE_ASM(s32, "code_F5750", func_802D36E0);

INCLUDE_ASM(s32, "code_F5750", func_802D378C);

INCLUDE_ASM(s32, "code_F5750", func_802D3840);

INCLUDE_ASM(s32, "code_F5750", func_802D38EC);

INCLUDE_ASM(s32, "code_F5750", func_802D3998);

INCLUDE_ASM(s32, "code_F5750", func_802D39FC);

INCLUDE_ASM(s32, "code_F5750", func_802D3A60);

INCLUDE_ASM(s32, "code_F5750", func_802D3C58);

INCLUDE_ASM(s32, "code_F5750", func_802D3EB8);

INCLUDE_ASM(s32, "code_F5750", func_802D3F74);

INCLUDE_ASM(s32, "code_F5750", func_802D3FC8);

INCLUDE_ASM(s32, "code_F5750", func_802D4050);

UnkF5750* func_802D4164(s32 index) {
    return (*D_802DB7C0)[index];
}

INCLUDE_ASM(s32, "code_F5750", func_802D417C);

INCLUDE_ASM(s32, "code_F5750", func_802D420C);

INCLUDE_ASM(s32, "code_F5750", func_802D42AC);

INCLUDE_ASM(s32, "code_F5750", func_802D4364);

void func_802D43AC(s32 index, f32 arg1, f32 arg2, f32 arg3) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_1C = arg1;
    temp->unk_20 = arg2;
    temp->unk_24 = arg3;
}

void func_802D43D0(s32 index, s32 arg1, s32 arg2, s32 arg3) {
    UnkF5750* temp = (*D_802DB7C0)[index];

    temp->unk_10 = arg1;
    temp->unk_14 = arg2;
    temp->unk_18 = arg3;
}

INCLUDE_ASM(s32, "code_F5750", func_802D43F4);

INCLUDE_ASM(s32, "code_F5750", func_802D4434);

INCLUDE_ASM(s32, "code_F5750", func_802D4488);

INCLUDE_ASM(s32, "code_F5750", func_802D4560);
