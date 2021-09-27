#include "common.h"

#define MAX_SOUND_INSTANCES 10

typedef struct SoundInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ SoundID soundID;
    /* 0x08 */ s32 sourceFlags;
    /* 0x0C */ u8 volume;
    /* 0x0D */ u8 pan;
    /* 0x0E */ s16 pitchShift;
    /* 0x10 */ Vec3f position;
} SoundInstance; // size = 0x1C

extern SoundInstance D_801598A0[MAX_SOUND_INSTANCES];
extern SoundInstance D_801599B8[MAX_SOUND_INSTANCES];
extern SoundInstance* D_80159AD0;

void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);

s32 D_8014F2D0[] = { 0x00000287, 0x000002A8, 0x00000054, 0x00000056, 0x00000024, 0x00000027, 0x00000021, 0x00000022,
                     0x00000349, 0x00000273, 0x00000275, 0x00000275, 0x00000274, 0x00000273, 0x00000274, 0x00000099,
                     0x0000009E, 0x0000032E, 0x0000008E, 0x00000089, 0x00000083, 0x00000388, 0x000000A0, 0x0000004A,
                     0x0000009F, 0x00000168, 0x00000185, 0x00000052, 0x0000004E, 0x0000004F, 0x00000189, 0x00000000,
                     0x00000000, 0x00000198, 0x00000199, 0x00000194, 0x0000019A, 0x00000091, 0x00000164, 0x00000271,
                     0x00000271, 0x00000274, 0x00000275, 0x00000271, 0x00000273, 0x00000271, 0x00000273, 0x00000271,
                     0x00000274, 0x00000275, 0x00000276, 0x00000271, 0x00000273, 0x00000271, 0x00000274, 0x00000276,
                     0x00000275, 0x00000271, 0x00000271, 0x00000271, 0x00000271, 0x00000276, 0x00000275, 0x00000274,
                     0x0000039E, 0x00000341, 0x00000207, 0x00000271, 0x00000271, 0x00000275, 0x00000276, 0x00000271,
                     0x00000271, 0x00000271, 0x00000050, 0x00000070, 0x0000036C, 0x0000036D, 0x00000295, 0x00000043,
                     0x00000197, 0x00000221, 0x0000022A, 0x0000022B, 0x00002040, 0x00000046, 0x00000033, 0x00000034,
                     0x00000039, 0x0000004C, 0x0000004D, 0x000001B1, 0x000001B2, 0x00000094, 0x0000005D, 0x0000005B,
                     0x00000060, 0x000001B3, 0x00000000, 0x000000AD, 0x000000AE, 0x000000AF, 0x0000023D, 0x000000A2,
                     0x00000248, 0x00000249, 0x00000391, 0x000003BC, 0x000003AD, 0x0000022C, 0x0000022D,
                   };

s32 D_8014F48C[] = { 0x00000336, 0x00000316 };
s32 D_8014F494[] = { 0x00000337, 0x00000317 };
s32 D_8014F49C[] = { 0x00000338, 0x00000318 };
s32 D_8014F4A4[] = { 0x00000339, 0x00000319 };
s32 D_8014F4AC[] = { 0x0000033A, 0x0000031A };
s32 D_8014F4B4[] = { 0x0000033B, 0x0000031B };
s32 D_8014F4BC[] = { 0x0000033C, 0x0000031C };
s32 D_8014F4C4[] = { 0x0000033D, 0x0000031D };
s32 D_8014F4CC[] = { 0x0000033E, 0x0000031E };
s32 D_8014F4D4[] = { 0x0000033F, 0x0000031F };
s32 D_8014F4DC[] = { 0x00000340, 0x00000340 };
s32 D_8014F4E4[] = { 0x000002F4, 0x000002F5 };
s32 D_8014F4EC[] = { 0x0000032F, 0x00000330 };
s32 D_8014F4F4[] = { 0x00000334, 0x00000335 };
s32 D_8014F4FC[] = { 0x000002F1, 0x000002F2 };
s32 D_8014F504[] = { 0x000000C1, 0x000000C2 };
s32 D_8014F50C[] = { 0x000000C3, 0x000000C4 };
s32 D_8014F514[] = { 0x000001CB, 0x000001CD };
s32 D_8014F51C[] = { 0x000001CC, 0x000001CE };
s32 D_8014F524[] = { 0x000002A6, 0x000002A7 };
s32 D_8014F52C[] = { 0x0000020C, 0x0000020D, 0x0000020E };
s32 D_8014F538[] = { 0x00000259, 0x0000025A };
s32 D_8014F540[] = { 0x0000025C, 0x0000025D };
s32 D_8014F548[] = { 0x00000331, 0x00000332, 0x00000333 };
s32 D_8014F554[] = { 0x00002078, 0x00002079 };
s32 D_8014F55C[] = { 0x00000179, 0x0000017A };
s32 D_8014F564[] = { 0x000001FB, 0x000001FC };
s32 D_8014F56C[] = { 0x0000203A, 0x0000203B };
s32 D_8014F574[] = { 0x0000022E, 0x0000022F };
s32 D_8014F57C[] = { 0x0000202A, 0x0000202B };
s32 D_8014F584[] = { 0x00002041, 0x00002042 };
s32 D_8014F58C[] = { 0x00002043, 0x00002044 };
s32 D_8014F594[] = { 0x00002078, 0x00002079 };
s32 D_8014F59C[] = { 0x000003B6, 0x000003B7 };

typedef struct AlternatingSoundSet {
    /* 0x00 */ s32* sounds;
    /* 0x04 */ s16 soundCount;
    /* 0x06 */ s16 currentIndex;
} AlternatingSoundSet; // size = 0x08

AlternatingSoundSet D_8014F5A4[] = {
    {
        .sounds = D_8014F48C,
        .soundCount = ARRAY_COUNT(D_8014F48C),
    },
    {
        .sounds = D_8014F494,
        .soundCount = ARRAY_COUNT(D_8014F494),
    },
    {
        .sounds = D_8014F49C,
        .soundCount = ARRAY_COUNT(D_8014F494),
    },
    {
        .sounds = D_8014F4A4,
        .soundCount = ARRAY_COUNT(D_8014F4A4),
    },
    {
        .sounds = D_8014F4AC,
        .soundCount = ARRAY_COUNT(D_8014F4AC),
    },
    {
        .sounds = D_8014F4B4,
        .soundCount = ARRAY_COUNT(D_8014F4B4),
    },
    {
        .sounds = D_8014F4BC,
        .soundCount = ARRAY_COUNT(D_8014F4BC),
    },
    {
        .sounds = D_8014F4C4,
        .soundCount = ARRAY_COUNT(D_8014F4C4),
    },
    {
        .sounds = D_8014F4CC,
        .soundCount = ARRAY_COUNT(D_8014F4CC),
    },
    {
        .sounds = D_8014F4D4,
        .soundCount = ARRAY_COUNT(D_8014F4D4),
    },
    {
        .sounds = D_8014F4DC,
        .soundCount = ARRAY_COUNT(D_8014F4DC),
    },
    {
        .sounds = D_8014F4E4,
        .soundCount = ARRAY_COUNT(D_8014F4E4),
    },
    {
        .sounds = D_8014F4EC,
        .soundCount = ARRAY_COUNT(D_8014F4EC),
    },
    {
        .sounds = D_8014F4F4,
        .soundCount = ARRAY_COUNT(D_8014F4F4),
    },
    {
        .sounds = D_8014F4FC,
        .soundCount = ARRAY_COUNT(D_8014F4FC),
    },
    {
        .sounds = D_8014F504,
        .soundCount = ARRAY_COUNT(D_8014F504),
    },
    {
        .sounds = D_8014F50C,
        .soundCount = ARRAY_COUNT(D_8014F50C),
    },
    {
        .sounds = D_8014F514,
        .soundCount = ARRAY_COUNT(D_8014F514),
    },
    {
        .sounds = D_8014F51C,
        .soundCount = ARRAY_COUNT(D_8014F51C),
    },
    {
        .sounds = D_8014F524,
        .soundCount = ARRAY_COUNT(D_8014F524),
    },
    {
        .sounds = D_8014F52C,
        .soundCount = ARRAY_COUNT(D_8014F52C),
    },
    {
        .sounds = D_8014F538,
        .soundCount = ARRAY_COUNT(D_8014F538),
    },
    {
        .sounds = D_8014F540,
        .soundCount = ARRAY_COUNT(D_8014F540),

    },
    {
        .sounds = D_8014F548,
        .soundCount = ARRAY_COUNT(D_8014F548),

    },
    {
        .sounds = D_8014F554,
        .soundCount = ARRAY_COUNT(D_8014F554),
    },
    {
        .sounds = D_8014F55C,
        .soundCount = ARRAY_COUNT(D_8014F55C),
    },
    {
        .sounds = D_8014F564,
        .soundCount = ARRAY_COUNT(D_8014F564),
    },
    {
        .sounds = D_8014F56C,
        .soundCount = ARRAY_COUNT(D_8014F56C),
    },
    {
        .sounds = D_8014F574,
        .soundCount = ARRAY_COUNT(D_8014F574),
    },
    {
        .sounds = D_8014F57C,
        .soundCount = ARRAY_COUNT(D_8014F57C),
    },
    {
        .sounds = D_8014F584,
        .soundCount = ARRAY_COUNT(D_8014F584),
    },
    {
        .sounds = D_8014F58C,
        .soundCount = ARRAY_COUNT(D_8014F58C),
    },
    {
        .sounds = D_8014F594,
        .soundCount = ARRAY_COUNT(D_8014F594),
    },
    {
        .sounds = D_8014F59C,
        .soundCount = ARRAY_COUNT(D_8014F59C),
    }
};

s32 D_8014F6B4[] = { 0x000001C1, 0x000001C2, 0x000001C3, 0x000001C4, 0x000001C5, 0x000001C6, 0x000001C7, 0x000001C8,
                     0x000001C9, 0x000001CA, 0x000001CB, 0x000001CC, 0x000020A3, 0x000020A4, 0x00000000,
                   };

extern s32 D_80159AD4;

INCLUDE_ASM(void, "DF950", sfx_compute_spatialized_sound_params_2, f32 posX, f32 posY, f32 posZ, s16* volume, s16* pan,
            u32 sourceFlags);

void sfx_reset_door_sounds(void) {
    gCurrentDoorSoundsSet = 0;
    D_80151308 = 0;
}

void sfx_clear_sounds(void) {
    bzero(&D_801598A0, sizeof(D_801598A0));
    bzero(&D_801599B8, sizeof(D_801599B8));
    D_80159AD0 = D_801598A0;
    func_801497FC(0);
    sfx_reset_door_sounds();
}

// name might be incorrect?
void sfx_clear_env_sounds(s16 playSounds) {
    if (!gGameStatusPtr->isBattle) {
        D_80159AD0 = D_801598A0;
    } else {
        D_80159AD0 = D_801599B8;
    }

    if (playSounds) {
        SoundInstance* sound = D_80159AD0;
        s32 i;

        for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
            if (sound->flags & 1) {
                snd_start_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
            }
        }
    } else {
        bzero(D_80159AD0, MAX_SOUND_INSTANCES * sizeof(SoundInstance));
    }
}

INCLUDE_ASM(void, "DF950", sfx_update_looping_sound_params);

void func_801497FC(s32 arg0) {
    func_800561E4();
    D_80159AD4 = arg0;
}

s32 func_80149828(void) {
    return D_80159AD4;
}

void sfx_stop_env_sounds(void) {
    SoundInstance* sound;
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        D_80159AD0 = D_801598A0;
        
    } else {
        D_80159AD0 = D_801599B8;
    }

    sound = D_80159AD0;
    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & 1) {
            snd_stop_sound(sound->soundID);
        }
    }
}

SoundInstance* sfx_get_env_sound_instance(SoundID soundID) {
    SoundInstance* sound = D_80159AD0;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & 1 && sound->soundID == soundID) {
            return sound;
        }
    }

    return NULL;
}

void sfx_play_sound_looping(SoundID soundId, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound = D_80159AD0;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & 1)) {
            break;
        }
    }

    sound->pan = pan;
    sound->soundID = soundId;
    sound->volume = volume;
    sound->pitchShift = pitchShift;
    sound->flags |= 1;

    snd_start_sound_with_shift(soundId, volume, pan, pitchShift);
}

void sfx_register_looping_sound_at_position(SoundID soundID, s32 flags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = D_80159AD0;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & 1)) {
            break;
        }
    }

    sound->sourceFlags = flags;
    sound->position.x = x;
    sound->position.y = y;
    sound->position.z = z;
    sound->soundID = soundID;
    sound->flags |= 3;

    sfx_play_sound_at_position(soundID, flags, x, y, z);
}

s32 sfx_adjust_env_sound_pos(SoundID soundID, s32 sourceFlags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound == NULL) {
        return 0;
    }

    sound->sourceFlags = sourceFlags;
    sound->position.x = x;
    sound->position.y = y;
    sound->position.z = z;
    sound->soundID = soundID;
    sound->flags |= 3;

    return 1;
}

void func_80149A6C(SoundID soundID, s32 keepPlaying) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound != NULL) {
        sound->flags &= -4;
        if (!keepPlaying) {
            snd_stop_sound(sound->soundID);
        }
    }
}

#ifdef NON_MATCHING // weird & 0xFF everywhere
void sfx_play_sound_with_params(SoundID soundID, u8 arg1, u8 arg2, s16 arg3) {
    AlternatingSoundSet* alternatingSound;
    
    if (gGameStatusPtr->demoState) {
        return;
    }

    if (soundID < 0) {
        SoundID sound = soundID & 0xFF;
        switch ((soundID >> 0x1C) & 7) {
            case 0:
                sfx_play_sound_looping(D_8014F2D0[sound], arg1, arg2, arg3);
                break;
            case 1:
                snd_start_sound_with_shift(D_8014F6B4[sound + ((u16)gCurrentDoorSoundsSet * 2)], arg1, arg2, arg3);
                break;
            case 2:
                snd_start_sound_with_shift(D_8014F6B4[sound + ((u16)D_80151308 * 2)], arg1, arg2, arg3);
                break;
            case 3:
                alternatingSound = &D_8014F5A4[sound];
                if (alternatingSound->currentIndex >= alternatingSound->soundCount) {
                    alternatingSound->currentIndex = 0;
                }
                snd_start_sound_with_shift(alternatingSound->sounds[alternatingSound->currentIndex++], arg1, arg2, arg3);
                break;
            default:
                snd_start_sound_with_shift(soundID, arg1, arg2, arg3);
                break;
        }
    } else {
        snd_start_sound_with_shift(soundID, arg1, arg2, arg3);
    }
}
#else
INCLUDE_ASM(void, "DF950", sfx_play_sound_with_params, s32 arg0, u8 arg1, u8 arg2, s16 arg3);
#endif

void sfx_adjust_env_sound_params(SoundID soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound;

    if (soundID < 0) {
        sound = sfx_get_env_sound_instance(D_8014F2D0[soundID & 0xFFFF]);
        if (sound != NULL) {
            sound->volume = volume;
            sound->pan = pan;
            sound->pitchShift = pitchShift;
        }
    } else {
        snd_adjust_sound_with_shift(soundID, volume, pan, pitchShift);
    }
}

void sfx_stop_sound(SoundID soundID) {
    SoundID sound = soundID;

    if (sound < 0) {
        func_80149A6C(D_8014F2D0[sound & 0xFFFF], 0);
    } else {
        snd_stop_sound(sound);
    }
}

void sfx_play_sound(SoundID soundID) {
    sfx_play_sound_with_params(soundID, 0, 0, 0);
}

void sfx_play_sound_at_player(SoundID soundID, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    sfx_play_sound_at_position(soundID, arg1, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
}

void sfx_play_sound_at_npc(SoundID soundID, s32 arg1, s32 npcID) {
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        sfx_play_sound_at_position(soundID, arg1, npc->pos.x, npc->pos.y, npc->pos.z);
    }
}

INCLUDE_ASM(s32, "DF950", sfx_play_sound_at_position, SoundID soundID, s32 value2, f32 posX, f32 posY,
            f32 posZ);

INCLUDE_ASM(void, "DF950", sfx_get_spatialized_sound_params, f32 arg0, f32 arg1, f32 arg2, s16* arg3, s16* arg4,
            s32 arg5);

INCLUDE_ASM(s32, "DF950", sfx_compute_spatialized_sound_params_0);

INCLUDE_ASM(s32, "DF950", sfx_compute_spatialized_sound_params_1);
