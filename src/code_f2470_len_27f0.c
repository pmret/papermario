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

INCLUDE_ASM(code_f2470_len_27f0, set_npc_animation);

ApiStatus DeleteNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Npc* npcPtr = get_npc_unsafe(get_variable(script, *ptrReadPos++));

    if (npcPtr) {
        free_npc(npcPtr);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetNpcPointer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode varNPC = *ptrReadPos++;

    set_variable(script, varNPC, get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM(code_f2470_len_27f0, SetNpcPos);

INCLUDE_API_ASM(code_f2470_len_27f0, SetNpcRotation);

ApiStatus SetNpcScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 sizeX = get_float_variable(script, *ptrReadPos++);
    f32 sizeY = get_float_variable(script, *ptrReadPos++);
    f32 sizeZ = get_float_variable(script, *ptrReadPos++);
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            npcPtr->scale.x = sizeX;
            npcPtr->scale.y = sizeY;
            npcPtr->scale.z = sizeZ;
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
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            npcPtr->collisionHeight = height;
            npcPtr->collisionRadius = radius;
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 speed = get_float_variable(script, *ptrReadPos);
    Npc* npcPtr = resolve_npc(script, npcID);

    if(npcPtr != NULL) {
        npcPtr->moveSpeed = speed;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcJumpscale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 jumpScale = get_float_variable(script, *ptrReadPos);
    Npc* npcPtr = resolve_npc(script, npcID);

    if(npcPtr != NULL) {
        npcPtr->jumpScale = jumpScale;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    s32 animation = get_variable(script, *ptrReadPos);
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        set_npc_animation(npcPtr, animation);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        set_variable(script, outVar, npcPtr->currentAnim);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimationSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 animationSpeed = get_float_variable(script, *ptrReadPos++);
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        npcPtr->animationSpeed = animationSpeed;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM(code_f2470_len_27f0, NpcMoveTo);

INCLUDE_ASM(code_f2470_len_27f0, _npc_jump_to);

void NpcJump0(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 0);
}

void NpcJump1(ScriptInstance* script, s32 isInitialCall) {
    _npc_jump_to(script, isInitialCall, 1);
}

INCLUDE_API_ASM(code_f2470_len_27f0, NpcFlyTo);

ApiStatus GetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npcPtr = resolve_npc(script, npcID);

    if (npcPtr != NULL) {
        s32 todo = 1; // TODO: Figure out why this variable and subsequent if block is required for matching
        if (todo) {
            set_variable(script, outVar, clamp_angle(npcPtr->yaw));
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Npc* npcPtr = resolve_npc(script, npcID);
    
    if (npcPtr != NULL) {
        set_npc_yaw(npcPtr, get_variable(script, *ptrReadPos++));
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM(code_f2470_len_27f0, InterpNpcYaw);

INCLUDE_API_ASM(code_f2470_len_27f0, NpcFacePlayer);

INCLUDE_API_ASM(code_f2470_len_27f0, NpcFaceNpc);

INCLUDE_API_ASM(code_f2470_len_27f0, SetNpcFlagBits);

INCLUDE_API_ASM(code_f2470_len_27f0, GetNpcPos);

INCLUDE_API_ASM(code_f2470_len_27f0, EnableNpcShadow);

INCLUDE_API_ASM(code_f2470_len_27f0, EnableNpcBlur);

INCLUDE_API_ASM(code_f2470_len_27f0, ClearPartnerMoveHistory);

INCLUDE_API_ASM(code_f2470_len_27f0, NpcSetHomePosToCurrent);

INCLUDE_API_ASM(code_f2470_len_27f0, GetPartnerPos);

INCLUDE_API_ASM(code_f2470_len_27f0, DisablePartnerAI);

INCLUDE_API_ASM(code_f2470_len_27f0, EnablePartnerAI);

INCLUDE_API_ASM(code_f2470_len_27f0, BringPartnerOut);

INCLUDE_API_ASM(code_f2470_len_27f0, PutPartnerAway);

INCLUDE_API_ASM(code_f2470_len_27f0, GetCurrentPartnerID);

INCLUDE_API_ASM(code_f2470_len_27f0, SetNpcEffect);

INCLUDE_API_ASM(code_f2470_len_27f0, PlaySoundAtNpc);
