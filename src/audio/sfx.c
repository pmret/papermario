#include "common.h"
#include "audio.h"

#define MAX_SOUND_INSTANCES 10

SHIFT_BSS u16 gCurrentDoorSounds;
SHIFT_BSS u16 gCurrentRoomDoorSounds;

// sound IDs
s32 LoopingSounds[] = {
    SOUND_287, SOUND_2A8, SOUND_54, SOUND_56, SOUND_24, SOUND_27, SOUND_21, SOUND_22, SOUND_349,
    SOUND_273, SOUND_275, SOUND_275, SOUND_274, SOUND_273, SOUND_274, SOUND_99, SOUND_9E, SOUND_32E,
    SOUND_8E, SOUND_89, SOUND_83, SOUND_388, SOUND_A0, SOUND_4A, SOUND_9F, SOUND_168, SOUND_185,
    SOUND_52, SOUND_4E, SOUND_4F, SOUND_189, 0, 0, SOUND_198, SOUND_199, SOUND_194,
    SOUND_19A, SOUND_91, SOUND_164, SOUND_271, SOUND_271, SOUND_274, SOUND_275, SOUND_271, SOUND_273,
    SOUND_271, SOUND_273, SOUND_271, SOUND_274, SOUND_275, SOUND_276, SOUND_271, SOUND_273, SOUND_271,
    SOUND_274, SOUND_276, SOUND_275, SOUND_271, SOUND_271, SOUND_271, SOUND_271, SOUND_276, SOUND_275,
    SOUND_274, SOUND_39E, SOUND_341, SOUND_207, SOUND_271, SOUND_271, SOUND_275, SOUND_276, SOUND_271,
    SOUND_271, SOUND_271, SOUND_50, SOUND_70, SOUND_36C, SOUND_36D, SOUND_295, SOUND_43, SOUND_197,
    SOUND_221, SOUND_22A, SOUND_22B, SOUND_2040, SOUND_JR_TROOPA_SWIM, SOUND_33, SOUND_34, SOUND_39, SOUND_4C,
    SOUND_4D, SOUND_1B1, SOUND_1B2, SOUND_94, SOUND_5D, SOUND_5B, SOUND_60, SOUND_1B3, 0,
    SOUND_AD, SOUND_AE, SOUND_AF, SOUND_23D, SOUND_A2, SOUND_248, SOUND_249, SOUND_391, SOUND_3BC,
    SOUND_3AD, SOUND_22C, SOUND_22D,
};

// all sound IDs for alternating sounds
s32 D_8014F48C[] = { SOUND_336, SOUND_316 };
s32 D_8014F494[] = { SOUND_337, SOUND_317 };
s32 D_8014F49C[] = { SOUND_338, SOUND_318 };
s32 D_8014F4A4[] = { SOUND_339, SOUND_319 };
s32 D_8014F4AC[] = { SOUND_33A, SOUND_31A };
s32 D_8014F4B4[] = { SOUND_33B, SOUND_31B };
s32 D_8014F4BC[] = { SOUND_33C, SOUND_31C };
s32 D_8014F4C4[] = { SOUND_33D, SOUND_31D };
s32 D_8014F4CC[] = { SOUND_33E, SOUND_31E };
s32 D_8014F4D4[] = { SOUND_33F, SOUND_31F };
s32 D_8014F4DC[] = { SOUND_340, SOUND_340 };
s32 D_8014F4E4[] = { SOUND_2F4, SOUND_2F5 };
s32 D_8014F4EC[] = { SOUND_32F, SOUND_330 };
s32 D_8014F4F4[] = { SOUND_334, SOUND_335 };
s32 D_8014F4FC[] = { SOUND_2F1, SOUND_2F2 };
s32 D_8014F504[] = { SOUND_BOO_VANISH_A, SOUND_BOO_VANISH_B };
s32 D_8014F50C[] = { SOUND_BOO_APPEAR_A, SOUND_BOO_APPEAR_B };
s32 D_8014F514[] = { SOUND_1CB, SOUND_1CD };
s32 D_8014F51C[] = { SOUND_1CC, SOUND_1CE };
s32 D_8014F524[] = { SOUND_2A6, SOUND_2A7 };
s32 D_8014F52C[] = { SOUND_20C, SOUND_20D, SOUND_20E };
s32 D_8014F538[] = { SOUND_259, SOUND_25A };
s32 D_8014F540[] = { SOUND_25C, SOUND_25D };
s32 D_8014F548[] = { SOUND_331, SOUND_332, SOUND_333 };
s32 D_8014F554[] = { SOUND_2078, SOUND_2079 };
s32 D_8014F55C[] = { SOUND_179, SOUND_17A };
s32 D_8014F564[] = { SOUND_1FB, SOUND_1FC };
s32 D_8014F56C[] = { SOUND_203A, SOUND_203B };
s32 D_8014F574[] = { SOUND_22E, SOUND_22F };
s32 D_8014F57C[] = { SOUND_202A, SOUND_202B };
s32 D_8014F584[] = { SOUND_2041, SOUND_2042 };
s32 D_8014F58C[] = { SOUND_2043, SOUND_2044 };
s32 D_8014F594[] = { SOUND_2078, SOUND_2079 };
s32 D_8014F59C[] = { SOUND_3B6, SOUND_3B7 };

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

SHIFT_BSS SoundInstance wEnvSounds[MAX_SOUND_INSTANCES];
SHIFT_BSS SoundInstance bEnvSounds[MAX_SOUND_INSTANCES];
SHIFT_BSS SoundInstance* gCurrentEnvSounds;
SHIFT_BSS s32 SfxReverbMode;

void sfx_compute_spatialized_sound_params_full(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags) {
    s32 screenX, screenY, screenZ;
    f32 volAmtOffsetX, volAmtDeltaY, volAmtDepth;
    f32 offsetX, offsetY, depth;
    f32 volTemp, panTemp;
    s32 phi_v0;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    if (screenX > 5000 || screenX < -5000 || screenY > 5000 || screenY < -5000) {
        *volume = -1;
        *pan = 0;
        return;
    }

    if (flags & SOUND_PARAM_CLIP_OFFSCREEN_ANY) {
        if (screenX < -30 || screenX > SCREEN_WIDTH + 30 || screenY < -30 || screenY > SCREEN_HEIGHT + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & SOUND_PARAM_CLIP_OFFSCREEN_X) {
        if (screenX < -30 || screenX > SCREEN_WIDTH + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    } else if (flags & SOUND_PARAM_CLIP_OFFSCREEN_Y) {
        if (screenY < -30 || screenY > SCREEN_HEIGHT + 30) {
            *volume = -1;
            *pan = 0;
            return;
        }
    }

    offsetX = abs((SCREEN_WIDTH / 2) - screenX) - 145;
    if (offsetX < 0.0) {
        offsetX = 0.0f;
    }

    volAmtOffsetX = update_lerp(EASING_LINEAR, 1.0f, 0.0f, offsetX, 200);
    if (volAmtOffsetX < 0.0) {
        volAmtOffsetX = 0.0f;
    }

    offsetY = abs((SCREEN_HEIGHT / 2) - screenY) - 105;
    if (offsetY < 0.0) {
        offsetY = 0.0f;
    }

    volAmtDeltaY = update_lerp(EASING_LINEAR, 1.0f, 0.0f, offsetY, 130);
    if (volAmtDeltaY < 0.0) {
        volAmtDeltaY = 0.0f;
    }

    depth = screenZ - 5550.0;
    if (depth < 0.0) {
        depth = 0.0f;
    }

    volAmtDepth = update_lerp(EASING_LINEAR, 1.0f, 0.0f, depth, 250);
    if (volAmtDepth < 0.0) {
        volAmtDepth = 0.0f;
    }

    volTemp = (volAmtOffsetX * volAmtDeltaY * volAmtDepth) * 127.0;
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
    gCurrentDoorSounds = 0;
    gCurrentRoomDoorSounds = 0;
}

void sfx_clear_sounds(void) {
    bzero(&wEnvSounds, sizeof(wEnvSounds));
    bzero(&bEnvSounds, sizeof(bEnvSounds));
    gCurrentEnvSounds = wEnvSounds;
    sfx_set_reverb_mode(0);
    sfx_reset_door_sounds();
}

// name might be incorrect?
void sfx_clear_env_sounds(s16 playSounds) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentEnvSounds = wEnvSounds;
    } else {
        gCurrentEnvSounds = bEnvSounds;
    }

    if (playSounds) {
        SoundInstance* sound = gCurrentEnvSounds;
        s32 i;

        for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
            if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
                snd_start_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
            }
        }
    } else {
        bzero(gCurrentEnvSounds, MAX_SOUND_INSTANCES * sizeof(SoundInstance));
    }
}

void sfx_update_env_sound_params(void) {
    SoundInstance* sound = gCurrentEnvSounds;
    u16 volume;
    u16 pan;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
            if (sound->flags & SOUND_INSTANCE_FLAG_POSITION_CHANGED) {
                sfx_get_spatialized_sound_params(sound->pos.x, sound->pos.y, sound->pos.z, &volume, &pan, sound->sourceFlags);
                sound->volume = volume;
                sound->pan = pan;
            }
            snd_adjust_sound_with_shift(sound->soundID, sound->volume, sound->pan, sound->pitchShift);
        }
    }
}

void sfx_set_reverb_mode(s32 mode) {
    func_800561E4(mode);
    SfxReverbMode = mode;
}

s32 sfx_get_reverb_mode(void) {
    return SfxReverbMode;
}

void sfx_stop_env_sounds(void) {
    SoundInstance* sound;
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentEnvSounds = wEnvSounds;
    } else {
        gCurrentEnvSounds = bEnvSounds;
    }

    sound = gCurrentEnvSounds;
    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE) {
            snd_stop_sound(sound->soundID);
        }
    }
}

SoundInstance* sfx_get_env_sound_instance(s32 soundID) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (sound->flags & SOUND_INSTANCE_FLAG_ACTIVE && sound->soundID == soundID) {
            return sound;
        }
    }

    return NULL;
}

void sfx_play_sound_looping(s32 soundId, u8 volume, u8 pan, s16 pitchShift) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & SOUND_INSTANCE_FLAG_ACTIVE)) {
            break;
        }
    }

    sound->pan = pan;
    sound->soundID = soundId;
    sound->volume = volume;
    sound->pitchShift = pitchShift;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE;

    snd_start_sound_with_shift(soundId, volume, pan, pitchShift);
}

void sfx_register_looping_sound_at_position(s32 soundID, s32 flags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = gCurrentEnvSounds;
    s32 i;

    for (i = 0; i < MAX_SOUND_INSTANCES; i++, sound++) {
        if (!(sound->flags & SOUND_INSTANCE_FLAG_ACTIVE)) {
            break;
        }
    }

    sound->sourceFlags = flags;
    sound->pos.x = x;
    sound->pos.y = y;
    sound->pos.z = z;
    sound->soundID = soundID;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED;

    sfx_play_sound_at_position(soundID, flags, x, y, z);
}

s32 sfx_adjust_env_sound_pos(s32 soundID, s32 sourceFlags, f32 x, f32 y, f32 z) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound == NULL) {
        return FALSE;
    }

    sound->sourceFlags = sourceFlags;
    sound->pos.x = x;
    sound->pos.y = y;
    sound->pos.z = z;
    sound->soundID = soundID;
    sound->flags |= SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED;
    return TRUE;
}

void snd_stop_tracking_env_sound_pos(s32 soundID, s32 keepPlaying) {
    SoundInstance* sound = sfx_get_env_sound_instance(soundID);

    if (sound != NULL) {
        sound->flags &= ~(SOUND_INSTANCE_FLAG_ACTIVE | SOUND_INSTANCE_FLAG_POSITION_CHANGED);
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
        s32 soundType = (soundID & 0x70000000) >> 0x1C;
        switch (soundType) {
            case SOUND_TYPE_LOOPING:
                // 0x8xxxxxxx
                sfx_play_sound_looping(LoopingSounds[soundIndex], volume, pan, pitchShift);
                return;
            case SOUND_TYPE_EXIT_DOOR:
                soundID = OpenCloseSounds[gCurrentDoorSounds][soundIndex];
                break;
            case SOUND_TYPE_ROOM_DOOR:
                soundID = OpenCloseSounds[gCurrentRoomDoorSounds][soundIndex];
                break;
            case SOUND_TYPE_ALTERNATING:
                // 0xBxxxxxxx
                alternatingSet = &AlternatingSounds[soundIndex];
                if (alternatingSet->curIndex >= alternatingSet->soundCount) {
                    alternatingSet->curIndex = 0;
                }
                soundID = alternatingSet->sounds[alternatingSet->curIndex++];
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
        snd_stop_tracking_env_sound_pos(LoopingSounds[sound & 0xFFFF], FALSE);
    } else {
        snd_stop_sound(sound);
    }
}

void sfx_play_sound(s32 soundID) {
    sfx_play_sound_with_params(soundID, 0, 0, 0);
}

void sfx_play_sound_at_player(s32 soundID, s32 flags) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    sfx_play_sound_at_position(soundID, flags, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
}

void sfx_play_sound_at_npc(s32 soundID, s32 flags, s32 npcID) {
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        sfx_play_sound_at_position(soundID, flags, npc->pos.x, npc->pos.y, npc->pos.z);
    }
}

void sfx_play_sound_at_position(s32 soundID, s32 flags, f32 posX, f32 posY, f32 posZ) {
    if ((soundID & 0xF0000000) == SOUND_TYPE_SPECIAL) {
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
    u32 paramFlags;
    u32 spaceMode;

    paramFlags = flags & SOUND_SPACE_PARAMS_MASK;

    do {
        spaceMode = flags & SOUND_SPACE_MODE_MASK;
    } while (0); // required to match

    switch (spaceMode) {
        case SOUND_SPACE_MODE_0:
            sfx_compute_spatialized_sound_params_0(x, y, z, volume, pan);
            break;
        case SOUND_SPACE_MODE_1:
            sfx_compute_spatialized_sound_params_1(x, y, z, volume, pan);
            break;
        case SOUND_SPACE_FULL:
            sfx_compute_spatialized_sound_params_full(x, y, z, volume, pan, paramFlags);
            break;
    }

    if (paramFlags & SOUND_PARAM_MUTE) {
        *volume = 0;
    } else if (paramFlags & SOUND_PARAM_QUIET) {
        if (*volume < 80) {
            *volume = 80;
        }
    } else if (paramFlags & SOUND_PARAM_MORE_QUIET) {
        if (*volume < 60) {
            *volume = 60;
        }
    } else if (paramFlags & SOUND_PARAM_MOST_QUIET) {
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
        // 25/75 at screen edge
        *pan = (screenX * 0.2f) + 32.0f;
    } else {
        f32 temp_f20 = ((screenX * 127.0) / SCREEN_WIDTH) - 64.0;
        *pan = (s32) (temp_f20 * sin_rad(DEG_TO_RAD(fabs(temp_f20) * 90.0 / 64.0))) + 64;
    }
}

void sfx_compute_spatialized_sound_params_1(f32 x, f32 y, f32 z, s16* volume, s16* pan) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 screenX, screenY, screenZ;
    f32 depth;

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

    depth = fabsf(5000 - screenZ);
    if (depth > 1000.0f) {
        depth = 1000.0f;
    }

    *volume = *volume * (1500.0f - depth) * 0.001f;
    if (*volume > 127) {
        *volume = 127;
    }
    if (*volume < 1) {
        *volume = 1;
    }

    *pan = ((screenX * 64.0f) / camera->viewportW) + 32.0f;
}
