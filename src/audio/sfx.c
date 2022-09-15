#include "common.h"
#include "audio.h"

#define MAX_SOUND_INSTANCES 10

// sound IDs
s32 LoopingSounds[] = {
    0x00000287, 0x000002A8, 0x00000054, 0x00000056, 0x00000024, 0x00000027, 0x00000021, 0x00000022, 0x00000349,
    0x00000273, 0x00000275, 0x00000275, 0x00000274, 0x00000273, 0x00000274, 0x00000099, 0x0000009E, 0x0000032E,
    0x0000008E, 0x00000089, 0x00000083, 0x00000388, 0x000000A0, 0x0000004A, 0x0000009F, 0x00000168, 0x00000185,
    0x00000052, 0x0000004E, 0x0000004F, 0x00000189, 0x00000000, 0x00000000, 0x00000198, 0x00000199, 0x00000194,
    0x0000019A, 0x00000091, 0x00000164, 0x00000271, 0x00000271, 0x00000274, 0x00000275, 0x00000271, 0x00000273,
    0x00000271, 0x00000273, 0x00000271, 0x00000274, 0x00000275, 0x00000276, 0x00000271, 0x00000273, 0x00000271,
    0x00000274, 0x00000276, 0x00000275, 0x00000271, 0x00000271, 0x00000271, 0x00000271, 0x00000276, 0x00000275,
    0x00000274, 0x0000039E, 0x00000341, 0x00000207, 0x00000271, 0x00000271, 0x00000275, 0x00000276, 0x00000271,
    0x00000271, 0x00000271, 0x00000050, 0x00000070, 0x0000036C, 0x0000036D, 0x00000295, 0x00000043, 0x00000197,
    0x00000221, 0x0000022A, 0x0000022B, 0x00002040, 0x00000046, 0x00000033, 0x00000034, 0x00000039, 0x0000004C,
    0x0000004D, 0x000001B1, 0x000001B2, 0x00000094, 0x0000005D, 0x0000005B, 0x00000060, 0x000001B3, 0x00000000,
    0x000000AD, 0x000000AE, 0x000000AF, 0x0000023D, 0x000000A2, 0x00000248, 0x00000249, 0x00000391, 0x000003BC,
    0x000003AD, 0x0000022C, 0x0000022D,
};

// all sound IDs for alternating sounds
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

AlternatingSoundSet AlternatingSounds[] = {
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

s32 OpenCloseSounds[][2] = {
    { SOUND_BASIC_DOOR_OPEN, SOUND_BASIC_DOOR_CLOSE },
    { SOUND_METAL_DOOR_OPEN, SOUND_METAL_DOOR_CLOSE },
    { SOUND_LARGE_DOOR_OPEN, SOUND_LARGE_DOOR_CLOSE },
    { SOUND_CREAKY_DOOR_OPEN, SOUND_CREAKY_DOOR_CLOSE },
    { SOUND_METAL_GATE_OPEN, SOUND_METAL_GATE_CLOSE },
    { SOUND_1CB, SOUND_1CC },
    { SOUND_20A3, SOUND_20A4 },
};

extern SoundInstance D_801598A0[MAX_SOUND_INSTANCES];
extern SoundInstance D_801599B8[MAX_SOUND_INSTANCES];
extern SoundInstance* D_80159AD0;
extern s32 D_80159AD4;

void sfx_compute_spatialized_sound_params_2(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags) {
    s32 screenX, screenY, screenZ;
    f32 f1, f2, f3;
    f32 lerp1, lerp2, lerp3;
    f32 volTemp, panTemp;
    s32 phi_v0;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 5000 || screenX < -5000 || screenY > 5000 || screenY < -5000) {
        *volume = -1;
        *pan = 0;
        return;
    }

    if (flags & 0x20000) {
        if (screenX < -30 || screenX > 350 || screenY < -30) {
            *volume = -1;
            *pan = 0;
            return;
        }

        if (screenY > 270) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & 0x40000) {
        if (screenX < -30 || screenX > 350) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & 0x80000) {
        if (screenY < -30 || screenY > 270) {
            *volume = -1;
            *pan = 0;
            return;
        }
    }

    lerp1 = abs(160 - screenX) - 145;
    if (lerp1 < 0.0) {
        lerp1 = 0.0f;
    }

    f1 = update_lerp(0, 1.0f, 0.0f, lerp1, 200);
    if (f1 < 0.0) {
        f1 = 0.0f;
    }

    lerp2 = abs(120 - screenY) - 105;
    if (lerp2 < 0.0) {
        lerp2 = 0.0f;
    }

    f2 = update_lerp(0, 1.0f, 0.0f, lerp2, 130);
    if (f2 < 0.0) {
        f2 = 0.0f;
    }

    lerp3 = screenZ - 5550.0;
    if (lerp3 < 0.0) {
        lerp3 = 0.0f;
    }

    f3 = update_lerp(0, 1.0f, 0.0f, lerp3, 250);
    if (f3 < 0.0) {
        f3 = 0.0f;
    }

    volTemp = (f1 * f2 * f3) * 127.0;
    if (volTemp < 15.0) {
        volTemp = 15.0f;
    } else if (volTemp > 127.0) {
        volTemp = 127.0f;
    }
    *volume = volTemp;

    panTemp = (((f32) screenX - (SCREEN_WIDTH / 2.0)) / 3.6) + 64.0;
    if (panTemp < 1.0) {
        panTemp = 1.0f;
    } else if (panTemp > 127.0) {
        panTemp = 127.0f;
    }
    *pan = panTemp;
}

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

void sfx_update_looping_sound_params(void) {
    SoundInstance* sound = D_80159AD0;
    u16 volume;
    u16 pan;
    s32 i;

    for (i = 0; i < 10; i++, sound++) {
        if (sound->flags & 1) {
            if (sound->flags & 2) {
                sfx_get_spatialized_sound_params(sound->position.x, sound->position.y, sound->position.z, &volume, &pan, sound->sourceFlags);
                sound->volume = volume;
                sound->pan = pan;
            }
            snd_adjust_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
        }
    }
}

void func_801497FC(s32 arg0) {
    func_800561E4(arg0);
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

SoundInstance* sfx_get_env_sound_instance(s32 soundID) {
    SoundInstance* sound = D_80159AD0;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & 1 && sound->soundID == soundID) {
            return sound;
        }
    }

    return NULL;
}

void sfx_play_sound_looping(s32 soundId, u8 volume, u8 pan, s16 pitchShift) {
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

void sfx_register_looping_sound_at_position(s32 soundID, s32 flags, f32 x, f32 y, f32 z) {
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

s32 sfx_adjust_env_sound_pos(s32 soundID, s32 sourceFlags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound == NULL) {
        return FALSE;
    }

    sound->sourceFlags = sourceFlags;
    sound->position.x = x;
    sound->position.y = y;
    sound->position.z = z;
    sound->soundID = soundID;
    sound->flags |= 3;
    return TRUE;
}

void func_80149A6C(s32 soundID, s32 keepPlaying) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound != NULL) {
        sound->flags &= -SOUND_INSTANCE_FLAG_4;
        if (!keepPlaying) {
            snd_stop_sound(sound->soundID);
        }
    }
}

void sfx_play_sound_with_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    AlternatingSoundSet* alternatingSet;

    if (gGameStatusPtr->demoState) {
        return;
    }

    if (soundID & SOUND_TYPE_SPECIAL) {
        s32 soundIndex = soundID & 0xFF;
        s32 soundType = ((u32)soundID >> 0x1C) & 7;
        switch (soundType) {
            case SOUND_TYPE_LOOPING:
                sfx_play_sound_looping(LoopingSounds[soundIndex], volume, pan, pitchShift);
                return;
            case SOUND_TYPE_DOOR1:
                soundID = OpenCloseSounds[gCurrentDoorSoundsSet][soundIndex];
                break;
            case SOUND_TYPE_DOOR2:
                soundID = OpenCloseSounds[D_80151308][soundIndex];
                break;
            case SOUND_TYPE_ALTERNATING:
                alternatingSet = &AlternatingSounds[soundIndex];
                if (alternatingSet->currentIndex >= alternatingSet->soundCount) {
                    alternatingSet->currentIndex = 0;
                }
                soundID = alternatingSet->sounds[alternatingSet->currentIndex++];
                break;
        }
    }
    snd_start_sound_with_shift(soundID, volume, pan, pitchShift);
}

void sfx_adjust_env_sound_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound;

    if (soundID & SOUND_TYPE_SPECIAL) {
        sound = sfx_get_env_sound_instance(LoopingSounds[soundID & 0xFFFF]);
        if (sound != NULL) {
            sound->volume = volume;
            sound->pan = pan;
            sound->pitchShift = pitchShift;
        }
    } else {
        snd_adjust_sound_with_shift(soundID, volume, pan, pitchShift);
    }
}

void sfx_stop_sound(s32 soundID) {
    s32 sound = soundID;

    if (sound & SOUND_TYPE_SPECIAL) {
        func_80149A6C(LoopingSounds[sound & 0xFFFF], 0);
    } else {
        snd_stop_sound(sound);
    }
}

void sfx_play_sound(s32 soundID) {
    sfx_play_sound_with_params(soundID, 0, 0, 0);
}

void sfx_play_sound_at_player(s32 soundID, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    sfx_play_sound_at_position(soundID, arg1, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
}

void sfx_play_sound_at_npc(s32 soundID, s32 arg1, s32 npcID) {
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        sfx_play_sound_at_position(soundID, arg1, npc->pos.x, npc->pos.y, npc->pos.z);
    }
}

void sfx_play_sound_at_position(s32 soundID, s32 flags, f32 posX, f32 posY, f32 posZ) {
    if ((soundID & 0xF0000000) == 0x80000000) {
        s32 id = LoopingSounds[soundID & 0xFFFF];

        sfx_register_looping_sound_at_position(id, flags, posX, posY, posZ);
    } else {
        s16 volume;
        s16 pan;

        sfx_get_spatialized_sound_params(posX, posY, posZ, &volume, &pan, flags);
        if (volume >= 0) {
            sfx_play_sound_with_params(soundID, volume, pan, 0);
        }
    }
}

void sfx_get_spatialized_sound_params(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags) {
    u32 upperFlags;
    u32 lowerFlags;

    upperFlags = flags & 0xFFFF0000;

    do {
        lowerFlags = flags & 0xFFFF;
    } while (0); // required to match

    switch (lowerFlags) {
        case 0:
            sfx_compute_spatialized_sound_params_0(x, y, z, volume, pan);
            break;
        case 1:
            sfx_compute_spatialized_sound_params_1(x, y, z, volume, pan);
            break;
        case 2:
            sfx_compute_spatialized_sound_params_2(x, y, z, volume, pan, upperFlags);
            break;
    }

    if (upperFlags & 0x10000) {
        *volume = 0;
    } else if (upperFlags & 0x400000) {
        if (*volume < 80) {
            *volume = 80;
        }
    } else if (upperFlags & 0x200000) {
        if (*volume < 60) {
            *volume = 60;
        }
    } else if (upperFlags & 0x100000) {
        if (*volume < 40) {
            *volume = 40;
        }
    }

    if (*pan < 1) {
        *pan = 1;
    }
    if (*pan > 127) {
        *pan = 127;
    }
}

void sfx_compute_spatialized_sound_params_0(f32 x, f32 y, f32 z, s16* volume, s16* pan) {
    s32 screenX, screenY, screenZ;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 3000 || screenX < -3000 || screenY > 3000 || screenY < -3000) {
        *volume = 1;
        *pan = 0;
        return;
    }

    *volume = 127;
    if (screenX < 0) {
        *volume = (screenX * 0.3f) + 127.0f;
        screenX = 0;
    }
    if (screenX > SCREEN_WIDTH) {
        *volume = 127.0f - ((screenX - SCREEN_WIDTH) * 0.3f);
        screenX = SCREEN_WIDTH;
    }

    if (*volume < 1) {
        *volume = 1;
    }

    if (!gGameStatusPtr->isBattle) {
        *pan = (screenX * 0.2f) + 32.0f;
    } else {
        f32 temp_f20 = ((screenX * 127.0) / 320.0) - 64.0;
        *pan = (s32) (temp_f20 * sin_rad(DEG_TO_RAD(fabs(temp_f20) * 90.0 / 64.0))) + 64;
    }
}

void sfx_compute_spatialized_sound_params_1(f32 x, f32 y, f32 z, s16* volume, s16* pan) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 screenX, screenY, screenZ;
    f32 temp_f0;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 3000 || screenX < -3000 || screenY > 3000 || screenY < -3000) {
        *volume = 1;
        *pan = 0;
        return;
    }

    *volume = 127;
    if (screenX < 0) {
        *volume = (screenX * 0.3f) + 127.0f;
        screenX = 0;
    }

    if (camera->viewportW < screenX) {
        *volume = 127.0f - ((screenX - camera->viewportW) * 0.3f);
        screenX = camera->viewportW;
    }

    temp_f0 = fabsf(5000 - screenZ);
    if (temp_f0 > 1000.0f) {
        temp_f0 = 1000.0f;
    }

    *volume = *volume * (1500.0f - temp_f0) * 0.001f;
    if (*volume > 127) {
        *volume = 127;
    }
    if (*volume < 1) {
        *volume = 1;
    }

    *pan = ((screenX * 64.0f) / camera->viewportW) + 32.0f;
}
