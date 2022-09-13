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
        if (playerStatus->flags & (PS_FLAGS_FALLING | PS_FLAGS_JUMPING)) {
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

INCLUDE_ASM(s32, "39210_len_aa0", func_8005DECC);

INCLUDE_ASM(s32, "39210_len_aa0", func_8005DFD4);

INCLUDE_ASM(s32, "39210_len_aa0", func_8005E12C);
