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

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcPos);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcRotation);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcScale);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcCollisionSize);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcSpeed);
// TODO: Fix issue with BNEZL vs BNEZ
/*
ApiStatus SetNpcSpeed(ScriptInstance* script, s32 isInitialCall) {
    Vytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    f32 speed = get_float_variable(script, *ptrReadPos);
    Npc* npcPtr = resolve_npc(script, npcID);

    npcPtr->moveSpeed = speed;
    if(npcPtr != NULL) {
        return ApiStatus_DONE2;
    }
}
*/

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcJumpscale);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcAnimation);

INCLUDE_API_ASM("code_f2470_len_27f0", GetNpcAnimation);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcMoveTo);

INCLUDE_ASM("code_f2470_len_27f0", _npc_jump_to);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcJump0);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcJump1);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFlyTo);

INCLUDE_API_ASM("code_f2470_len_27f0", GetNpcYaw);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcYaw);

INCLUDE_API_ASM("code_f2470_len_27f0", InterpNpcYaw);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFacePlayer);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcFaceNpc);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcFlagBits);

INCLUDE_API_ASM("code_f2470_len_27f0", GetNpcPos);

INCLUDE_API_ASM("code_f2470_len_27f0", EnableNpcShadow);

INCLUDE_API_ASM("code_f2470_len_27f0", EnableNpcBlur);

INCLUDE_API_ASM("code_f2470_len_27f0", ClearPartnerMoveHistory);

INCLUDE_API_ASM("code_f2470_len_27f0", NpcSetHomePosToCurrent);

INCLUDE_API_ASM("code_f2470_len_27f0", GetPartnerPos);

INCLUDE_API_ASM("code_f2470_len_27f0", DisablePartnerAI);

INCLUDE_API_ASM("code_f2470_len_27f0", EnablePartnerAI);

INCLUDE_API_ASM("code_f2470_len_27f0", BringPartnerOut);

INCLUDE_API_ASM("code_f2470_len_27f0", PutPartnerAway);

INCLUDE_API_ASM("code_f2470_len_27f0", GetCurrentPartnerID);

INCLUDE_API_ASM("code_f2470_len_27f0", SetNpcEffect);

INCLUDE_API_ASM("code_f2470_len_27f0", PlaySoundAtNpc);
