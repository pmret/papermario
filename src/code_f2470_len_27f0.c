#include "common.h"

npc* resolve_npc(script_context* script, NPC npcID) {
    if (npcID == NPC_SELF) {
        return get_npc_safe(script->ownerID);
    } else if (npcID >= -270000000) {
        return get_npc_safe(npcID);
    } else {
        return (npc*) npcID;
    }
}

INCLUDE_ASM(code_f2470_len_27f0, set_npc_animation);

INCLUDE_ASM(code_f2470_len_27f0, DeleteNpc);

INCLUDE_ASM(code_f2470_len_27f0, GetNpcPointer);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcPos);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcRotation);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcScale);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcCollisionSize);

INCLUDE_ASM(code_f2470_len_27f0, SetNpcSpeed);

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
