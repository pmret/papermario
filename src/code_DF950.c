#include "common.h"

INCLUDE_ASM(s32, "code_DF950", func_80149250);

void func_80149600(void) {
    gCurrentDoorSoundsSet = 0;
    D_80151308 = 0;
}

INCLUDE_ASM(s32, "code_DF950", func_80149618);

INCLUDE_ASM(s32, "code_DF950", func_80149670);

INCLUDE_ASM(s32, "code_DF950", func_80149734);

INCLUDE_ASM(s32, "code_DF950", func_801497FC);

INCLUDE_ASM(s32, "code_DF950", func_80149828);

INCLUDE_ASM(s32, "code_DF950", func_80149838);

INCLUDE_ASM(s32, "code_DF950", func_801498C4);

INCLUDE_ASM(s32, "code_DF950", func_80149908);

INCLUDE_ASM(s32, "code_DF950", func_80149974);

INCLUDE_ASM(s32, "code_DF950", func_801499EC, s32 soundID, s32 arg1, f32 arg2, f32 arg3, f32 arg4);

INCLUDE_ASM(s32, "code_DF950", func_80149A6C);

INCLUDE_ASM(s32, "code_DF950", _play_sound);

INCLUDE_ASM(s32, "code_DF950", func_80149BE4);

INCLUDE_ASM(s32, "code_DF950", stop_sound);

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

INCLUDE_ASM(s32, "code_DF950", play_sound_at_position, s32 soundID, s32 value2, f32 posX, f32 posY,
            f32 posZ);

INCLUDE_ASM(s32, "code_DF950", func_80149E04);

INCLUDE_ASM(s32, "code_DF950", func_80149F58);

INCLUDE_ASM(s32, "code_DF950", func_8014A1B4);
