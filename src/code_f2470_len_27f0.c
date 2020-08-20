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

INCLUDE_ASM("code_f2470_len_27f0", set_npc_animation);

ApiStatus DeleteNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(get_variable(script, *ptrReadPos++));

    if (npc) {
        free_npc(npc);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetNpcPointer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode varNPC = *ptrReadPos++;

    set_variable(script, varNPC, (s32)get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcPos);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcRotation);

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

    if(npc != NULL) {
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

    if(npc != NULL) {
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

INCLUDE_API_ASM("code_f2470_len_27f0", NpcMoveTo);

INCLUDE_ASM("code_f2470_len_27f0", _npc_jump_to);

void NpcJump0(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 0);
}

void NpcJump1(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 1);
}

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFlyTo);

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

INCLUDE_API_ASM("code_f2470_len_27f0", InterpNpcYaw);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFacePlayer);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFaceNpc);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcFlagBits);

INCLUDE_API_ASM("code_f2470_len_27f0", GetNpcPos);

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
        else {
            disable_npc_shadow(npc);
        }
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

INCLUDE_API_ASM("code_f2470_len_27f0", NpcSetHomePosToCurrent);

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

    if( value == 2) {
        func_800EF3E4();
    } else {
        func_800EF3D4(value);
    }
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_f2470_len_27f0", BringPartnerOut);

INCLUDE_API_ASM("code_f2470_len_27f0", PutPartnerAway);

INCLUDE_API_ASM("code_f2470_len_27f0", GetCurrentPartnerID);

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

ApiStatus SetNpcRenderMode(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    u8 renderMode = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    npc->renderMode = renderMode;
    return ApiStatus_DONE2;
}

