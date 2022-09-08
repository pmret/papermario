#include "common.h"

void get_npc_pos(s32 npcID, f32* outX, f32* outY, f32* outZ, s32* arg4) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc;

    *outX = 0.0f;
    *outY = 0.0f;
    *outZ = 0.0f;
    *arg4 = FALSE;

    if (npcID == NPC_SELF) {
        *outX = playerStatus->position.x;
        *outY = playerStatus->position.y;
        *outZ = playerStatus->position.z;
        if (playerStatus->flags & (PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING)) {
            *arg4 = TRUE;
        }
    } else {
        npc = get_npc_unsafe(npcID);
        *outX = npc->pos.x;
        *outY = npc->pos.y;
        *outZ = npc->pos.z;
        if (npc->flags & NPC_FLAG_JUMPING) {
            *arg4 = TRUE;
        }
    }

}

void func_8005DECC(Npc* npc, s32 arg1, void* arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);
INCLUDE_ASM(s32, "39210_len_aa0", func_8005DECC);

INCLUDE_ASM(s32, "39210_len_aa0", func_8005DFD4);

INCLUDE_ASM(s32, "39210_len_aa0", func_8005E12C);
