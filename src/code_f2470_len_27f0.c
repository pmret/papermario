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

s32 DeleteNpc(ScriptInstance* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Npc* npcPtr = get_npc_unsafe(get_variable(script, *ptrReadPos++));

    if (npcPtr) {
        free_npc(npcPtr);
        return 2;
    }
    return 2;
}

s32 GetNpcPointer(ScriptInstance* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode varNPC = *ptrReadPos++;

    set_variable(script, varNPC, get_npc_safe(npcID));
    return 2;
}

INCLUDE_ASM(code_f2470_len_27f0, SetNpcPos);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcRotation);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcScale);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcCollisionSize);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcSpeed);
// TODO: Fix issue with BNEZL vs BNEZ
/*
s32 SetNpcSpeed(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;
    bytecode npcID = get_variable(script, *ptrReadPos++);
    f32 speed = get_float_variable(script, *ptrReadPos);
    npc* npcPtr = resolve_npc(script, npcID);

    npcPtr->moveSpeed = speed;
    if(npcPtr != NULL) {
        return 2;
    }
}
*/

INCLUDE_ASM(code_f2470_len_27f0, SetNpcJumpscale);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcAnimation);

INCLUDE_ASM(code_f2470_len_27f0, GetNpcAnimation);

INCLUDE_ASM(code_f2470_len_27f0, NpcMoveTo);

INCLUDE_ASM(code_f2470_len_27f0, _npc_jump_to);

INCLUDE_ASM(code_f2470_len_27f0, NpcJump0);

INCLUDE_ASM(code_f2470_len_27f0, NpcJump1);

INCLUDE_ASM(code_f2470_len_27f0, NpcFlyTo);

INCLUDE_ASM(code_f2470_len_27f0, GetNpcYaw);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcYaw);

INCLUDE_ASM(code_f2470_len_27f0, InterpNpcYaw);

INCLUDE_ASM(code_f2470_len_27f0, NpcFacePlayer);

INCLUDE_ASM(code_f2470_len_27f0, NpcFaceNpc);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcFlagBits);

INCLUDE_ASM(code_f2470_len_27f0, GetNpcPos);

INCLUDE_ASM(code_f2470_len_27f0, EnableNpcShadow);

INCLUDE_ASM(code_f2470_len_27f0, EnableNpcBlur);

INCLUDE_ASM(code_f2470_len_27f0, ClearPartnerMoveHistory);

INCLUDE_ASM(code_f2470_len_27f0, NpcSetHomePosToCurrent);

INCLUDE_ASM(code_f2470_len_27f0, GetPartnerPos);

INCLUDE_ASM(code_f2470_len_27f0, DisablePartnerAI);

INCLUDE_ASM(code_f2470_len_27f0, EnablePartnerAI);

INCLUDE_ASM(code_f2470_len_27f0, BringPartnerOut);

INCLUDE_ASM(code_f2470_len_27f0, PutPartnerAway);

INCLUDE_ASM(code_f2470_len_27f0, GetCurrentPartnerID);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcEffect);

INCLUDE_ASM(code_f2470_len_27f0, PlaySoundAtNpc);
