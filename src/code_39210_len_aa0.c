#include "common.h"

void get_npc_pos(s32 arg0, f32* outX, f32* outY, f32* outZ, s32* arg4) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc;
    s32 phi_v0;

    *outX = 0.0f;
    *outY = 0.0f;
    *outZ = 0.0f;
    *arg4 = 0;

    if (arg0 == -1) {
        *outX = playerStatus->position.x;
        *outY = playerStatus->position.y;
        *outZ = playerStatus->position.z;
        phi_v0 = playerStatus->flags & 6;
    } else {
        npc = get_npc_unsafe(arg0);
        *outX = npc->pos.x;
        *outY = npc->pos.y;
        *outZ = npc->pos.z;
        phi_v0 = npc->flags & 0x800;
    }

    if (phi_v0 != 0) {
        *arg4 = 1;
    }
}

INCLUDE_ASM("code_39210_len_aa0", func_8005DECC);

INCLUDE_ASM("code_39210_len_aa0", func_8005DFD4);

INCLUDE_ASM("code_39210_len_aa0", func_8005E12C);
