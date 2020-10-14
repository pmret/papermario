#include "common.h"

Npc* resolve_npc(ScriptInstance* script, NpcId npcIdOrPtr) {
    if (npcIdOrPtr == NpcId_SELF) {
        return get_npc_safe(script->ownerID);
    } else if (npcIdOrPtr >= -270000000) {
        return get_npc_safe(npcIdOrPtr);
    } else {
        return (Npc*) npcIdOrPtr;
    }
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", set_npc_animation);

INCLUDE_ASM(s32, "code_f2470_len_27f0", CreateNpc);

ApiStatus DeleteNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(get_variable(script, *args++));

    if (npc) {
        free_npc(npc);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetNpcPointer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcID = get_variable(script, *args++);
    Bytecode varNPC = *args++;

    set_variable(script, varNPC, (s32)get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", SetNpcPos, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", SetNpcRotation, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802CDE68(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcId = get_variable(script, *args++);
    f32 var1 = get_float_variable(script, *args++);
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc != NULL) {
        npc->unk_50 = var1;
    }

    return ApiStatus_DONE2;
    do {} while (0); // necessary to match
}

ApiStatus SetNpcScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 sizeX = get_float_variable(script, *ptrReadPos++);
    f32 sizeY = get_float_variable(script, *ptrReadPos++);
    f32 sizeZ = get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            npc->scale.x = sizeX;
            npc->scale.y = sizeY;
            npc->scale.z = sizeZ;
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcCollisionSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 height = get_variable(script, *ptrReadPos++);
    s32 radius = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            npc->collisionHeight = height;
            npc->collisionRadius = radius;
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 speed = get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        npc->moveSpeed = speed;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcJumpscale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 jumpScale = get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        npc->jumpScale = jumpScale;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 animation = get_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        set_npc_animation(npc, animation);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        set_variable(script, outVar, npc->currentAnim);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimationSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 animationSpeed = get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        npc->animationSpeed = animationSpeed;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", NpcMoveTo, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", _npc_jump_to);

void NpcJump0(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 0);
}

void NpcJump1(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 1);
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", NpcFlyTo, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            set_variable(script, outVar, clamp_angle(npc->yaw));
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        set_npc_yaw(npc, get_variable(script, *ptrReadPos++));
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", InterpNpcYaw, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", NpcFacePlayer, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", NpcFaceNpc, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", SetNpcFlagBits, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_f2470_len_27f0", GetNpcPos, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802CF1B4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc != NULL) {
        npc->unk_80 = arg1;
    }

    return ApiStatus_DONE2;
    do {} while (0); // necessary to match
}

ApiStatus func_802CF208(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc != NULL) {
        func_8003AC5C(npc, arg1, 0);
    }

    return ApiStatus_DONE2;
    do {} while (0); // necessary to match
}

ApiStatus EnableNpcShadow(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 enableShadow = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        if (enableShadow) {
            enable_npc_shadow(npc);
            return ApiStatus_DONE2;
        }
        disable_npc_shadow(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableNpcBlur(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 enableBlur = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        if (enableBlur) {
            enable_npc_blur(npc);
            return ApiStatus_DONE2;
        }
        disable_npc_blur(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus ClearPartnerMoveHistory(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        clear_partner_move_history(npc);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", NpcSetHomePosToCurrent, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetPartnerPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode posX = *ptrReadPos++;
    Bytecode posY = *ptrReadPos++;
    Bytecode posZ = *ptrReadPos++;
    Npc* npc = get_npc_unsafe(-4);

    if (npc != NULL) {
        set_variable(script, posX, npc->pos.x);
        set_variable(script, posY, npc->pos.y);
        set_variable(script, posZ, npc->pos.z);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerAI(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (get_variable(script, *ptrReadPos++) == 0) {
        func_800EF314();
    } else {
        func_800EF300();
    }
    return ApiStatus_DONE2;
}

ApiStatus EnablePartnerAI(ScriptInstance* script, s32 isInitialCall) {
    enable_partner_ai();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF54C(ScriptInstance* script, s32 isInitialCall) {
    func_800EF43C();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF56C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = get_variable(script, *ptrReadPos++);

    if (value == 2) {
        func_800EF3E4();
    } else {
        func_800EF3D4(value);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", BringPartnerOut);

INCLUDE_ASM(s32, "code_f2470_len_27f0", PutPartnerAway);

ApiStatus GetCurrentPartnerID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    return ApiStatus_DONE2;
}

ApiStatus PartnerCanUseAbility(ScriptInstance* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    set_variable(script, arg0, partner_can_use_ability());
    return ApiStatus_DONE2;
}

ApiStatus PartnerIsFlying(ScriptInstance* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    set_variable(script, arg0, is_current_partner_flying());
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", func_802CFD30);

ApiStatus func_802CFE2C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc != NULL) {
        npc->unk_A2 = arg1;
    }

    return ApiStatus_DONE2;
    do {} while (0); // necessary to match
}

ApiStatus func_802CFE80(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcId = get_variable(script, *args++);
    Bytecode var1 = get_variable(script, *args++);
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc != NULL) {
        func_8003B3D0(npc, var1);
    }

    return ApiStatus_DONE2;
    do {} while (0); // necessary to match
}

INCLUDE_ASM(s32, "code_f2470_len_27f0", func_802CFEEC);

INCLUDE_ASM(s32, "code_f2470_len_27f0", func_802CFFC0);

ApiStatus SetNpcEffect(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 value1 = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        func_8003C3D8(npc, value1, value2);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    SoundId soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc != NULL) {
        play_sound_at_position(soundID, value2, npc->pos.x, npc->pos.y, npc->pos.z);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802D0244(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    u8 renderMode = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    npc->renderMode = renderMode;
    return ApiStatus_DONE2;
}

