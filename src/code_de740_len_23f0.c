#include "common.h"

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80148040);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801480F0);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80148154);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801481C4);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801489B8);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801491E4);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149250);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149600);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149618);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149670);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149734);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801497FC);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149828);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149838);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801498C4);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149908);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149974);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_801499EC, s32 soundID, s32 arg1, f32 arg2, f32 arg3, f32 arg4);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149A6C);

INCLUDE_ASM(s32, "code_de740_len_23f0", _play_sound);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149BE4);

INCLUDE_ASM(s32, "code_de740_len_23f0", stop_sound);

void play_sound(s32 soundID) {
    _play_sound(soundID, 0, 0, 0);
}

void play_sound_at_player(s32 soundID, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    play_sound_at_position(soundID, arg1, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
}

void play_sound_at_npc(s32 soundID, s32 arg1, s32 npcID) {
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        play_sound_at_position(soundID, arg1, npc->pos.x, npc->pos.y, npc->pos.z);
    }
}

INCLUDE_ASM(s32, "code_de740_len_23f0", play_sound_at_position, s32 soundID, s32 value2, f32 posX, f32 posY,
            f32 posZ);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149E04);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_80149F58);

INCLUDE_ASM(s32, "code_de740_len_23f0", func_8014A1B4);
