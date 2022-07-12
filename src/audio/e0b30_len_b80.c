#include "common.h"
#include "npc.h"

void bgm_update_volume(void);
void bgm_set_target_volume(s16 volume);

MusicSettings D_8014F6F0 = {
    .flags = 0,
    .state = 0,
    .fadeOutTime = -1,
    .fadeInTime = 0,
    .unk_0C = 0,
    .unk_0E = 0,
    .songID = -1,
    .variation = -1,
    .songName = -1,
    .battleSongID = 0,
    .battleVariation = 0,
    .savedSongID = 0,
    .savedVariation = 0,
    .savedSongName = 0
};

s32 gSongsUsingVariationFlag[] = {
    SONG_SPECIAL_BATTLE,
    SONG_TUBBA_BLUBBA_BATTLE,
    SONG_JR_TROOPA_BATTLE,
    SONG_YOSHI_KIDS_FOUND,
    SONG_ITEM_UPGRADE,
    SONG_NEW_PARTNER,
};

s16 gNextVolumeUpdateTimer = 0;

/// If the given song ID is present in gSongsUsingVariationFlag, returns the current
/// map's `songVariation & 1` value. Otherwise, returns -1.
///
/// @see gSongsUsingVariationFlag
/// @returns -1: no override; 0: override to variation 0; 1 override to variation 1
s32 bgm_get_map_default_variation(s32 songID) {
    u32 i;

    for (i = 0; i < ARRAY_COUNT(gSongsUsingVariationFlag); i++) {
        if (gSongsUsingVariationFlag[i] == songID) {
            Map* map = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];

            return map->unk_1C.bytes.songVariation & 1;
        }
    }

    return -1;
}

void bgm_reset_sequence_players(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gMusicSettings[i] = D_8014F6F0;
    }

    gMusicTargetVolume = 8;
    gMusicMaxVolume = 8;
    gMusicCurrentVolume = 8;
    func_800561A4(8);
}

void bgm_reset_volume(void) {
    gMusicTargetVolume = 8;
    gMusicMaxVolume = 8;
}

//TODO refactor out constants
void bgm_update_music_settings(void) {
    MusicSettings* music = gMusicSettings;
    s32 i = 0;
    s16 state2 = 2;
    s16 flag4 = MUSIC_SETTINGS_FLAGS_4;
    s32 flags;
    
    for (i; i < 2; i++, music++) {
        switch (music->state) {
        case 0:
            break;
        case 1:
            if (music->flags & MUSIC_SETTINGS_FLAGS_1) {
                if (music->fadeOutTime < 250) {
                    if (!(music->flags & MUSIC_SETTINGS_FLAGS_4)) {
                        if (func_800559C4(music->songName) == AU_RESULT_OK) {
                            music->state = state2;
                        }
                    } else {
                        if (func_80055AF0(music->songName) == AU_RESULT_OK) {
                           music->state = state2;
                        }
                    }
                } else if (!(music->flags & MUSIC_SETTINGS_FLAGS_4)) {
                    if (snd_set_song_variation_fade_time(music->songName, music->fadeOutTime, 0) == 0) {
                        music->state = state2;
                    }
                } else {
                    if (func_80055BB8(music->songName, 250) == AU_RESULT_OK) {
                        music->state = state2;
                    }
                }
            } else {
                if (music->flags & MUSIC_SETTINGS_FLAGS_4) {
                    music->flags |= MUSIC_SETTINGS_FLAGS_10;
                }
                music->flags &= ~flag4;
                music->state = 5;
            }
            break;
        case 2:
            flags = music->flags;
            music->flags &= ~flag4;
            if (flags & 1) {
                if (func_800559FC(music->songName) == AU_RESULT_OK) {
                    music->flags &= ~MUSIC_SETTINGS_FLAGS_1;
                    music->state = 3;
                }
            } else {
                music->state = 5;
            }
            break;
        case 3:
            music->state = 4;
            break;
        case 4:
            music->state = 5;
            break;
        case 5:
            if (!(music->flags & MUSIC_SETTINGS_FLAGS_8)) {
                if (music->songID < 0) {
                    music->state = 0;
                } else {
                    music->songName = snd_load_song(music->songID, i);
                    if (music->songName > 0xFFFFU) {
                        if ((music->flags & MUSIC_SETTINGS_FLAGS_20)) {
                            snd_set_song_variation_fade(music->songName, music->variation, music->fadeInTime, music->unk_0C, music->unk_0E);
                            music->flags &= ~MUSIC_SETTINGS_FLAGS_20;
                        } else {
                            bgm_set_target_volume(gMusicDefaultVolume);
                        }
                        if (snd_start_song_variation(music->songName, music->variation) == 0) {
                            music->flags |= MUSIC_SETTINGS_FLAGS_1;
                            music->state = 0;
                        }
                    }
                }
            } else {
                if (music->flags & MUSIC_SETTINGS_FLAGS_10) {
                    music->state = 0;
                    music->flags &= ~(MUSIC_SETTINGS_FLAGS_10 | MUSIC_SETTINGS_FLAGS_8);
                } else if (func_80055B28(music->savedSongName) == 0) {
                    music->songID = music->savedSongID;
                    music->variation = music->savedVariation;
                    music->songName = music->savedSongName;
                    music->state = 0;
                    music->flags |= MUSIC_SETTINGS_FLAGS_1; 
                    music->flags &= ~MUSIC_SETTINGS_FLAGS_8;
                }
            }
            break;
        }
    }
    bgm_update_volume();
}

static const f32 padding = 0.0f;

s32 _bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    MusicSettings* musicSetting;
    s32 mapSongVariation;

    if (gGameStatusPtr->demoState != 0) {
        return 1;
    }

    musicSetting = &gMusicSettings[playerIndex];

    if (!gGameStatusPtr->musicEnabled) {
        func_800559C4(musicSetting->songName);
        musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_1;

        return 1;
    }

    mapSongVariation = bgm_get_map_default_variation(songID);
    if (mapSongVariation >= 0) {
        variation = mapSongVariation;
    }

    if (musicSetting->songID == songID && musicSetting->variation == variation) {
        bgm_set_target_volume(volume);

        if (musicSetting->flags & MUSIC_SETTINGS_FLAGS_4) {
            func_80055B80(musicSetting->songName);
            musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_4;
        }

        return 2;
    }

    gMusicDefaultVolume = volume;
    musicSetting->songID = songID;
    musicSetting->variation = variation;
    musicSetting->fadeOutTime = fadeOutTime;
    musicSetting->state = 1;
    musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_2;

    return 1;
}

s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    gMusicSettings[playerIndex].flags &= ~MUSIC_SETTINGS_FLAGS_8;

    return _bgm_set_song(playerIndex, songID, variation, fadeOutTime, volume);
}

s32 func_8014A964(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5) {
    MusicSettings* musicSetting;
    s32 mapSongVariation;

    if (gGameStatusPtr->demoState) {
        return 1;
    }

    musicSetting = &gMusicSettings[playerIndex];

    if (!gGameStatusPtr->musicEnabled) {
        func_800559C4(musicSetting->songName);
        musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_1;
        return 1;
    }

    mapSongVariation = bgm_get_map_default_variation(songID);
    if (mapSongVariation >= 0) {
        variation = mapSongVariation;
    }

    musicSetting->fadeInTime = fadeInTime;
    musicSetting->unk_0C = arg4;
    musicSetting->unk_0E = arg5;
    musicSetting->songID = songID;
    musicSetting->variation = variation;
    musicSetting->flags |= MUSIC_SETTINGS_FLAGS_20;
    musicSetting->state = 1;
    musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_2;

    return 1;
}

s32 bgm_adjust_proximity(s32 playerIndex, s32 mix, s16 state) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return FALSE;
    }

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_2)) {
        return FALSE;
    }

    switch (state) {
        case MUSIC_PROXIMITY_FAR:
            bgm_set_proximity_mix_far(musicSetting->songName, mix);
            break;
        case MUSIC_PROXIMITY_NEAR:
            bgm_set_proximity_mix_near(musicSetting->songName, mix);
            break;
        case MUSIC_PROXIMITY_FULL:
            bgm_set_proximity_mix_full(musicSetting->songName, mix);
            break;
    }
    return TRUE;
}

AuResult bgm_set_track_volumes(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return AU_RESULT_OK;
    }

    return snd_song_set_track_volumes(musicSetting->songName, arg1);
}

AuResult func_8014AB60(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return AU_RESULT_OK;
    }

    return snd_song_clear_track_volumes(musicSetting->songName, arg1);
}

AuResult bgm_set_variation(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return AU_RESULT_OK;
    }

    return snd_set_song_variation(musicSetting->songName, arg1);
}

s32 bgm_init_music_players(void) {
    bgm_set_song(0, -1, 0, 250, 8);
    bgm_set_song(1, -1, 0, 250, 8);

    return 1;
}

void bgm_quiet_max_volume(void) {
    gMusicMaxVolume = 4;
}

void bgm_reset_max_volume(void) {
    gMusicMaxVolume = 8;
}

void bgm_set_target_volume(s16 volume) {
    gMusicTargetVolume = volume;
}

void bgm_update_volume(void) {
    s16 toVolume;

    if (gNextVolumeUpdateTimer != 0) {
        gNextVolumeUpdateTimer--;
        return;
    }

    toVolume = gMusicTargetVolume;
    if (toVolume > gMusicMaxVolume) {
        toVolume = gMusicMaxVolume;
    }

    if (gMusicCurrentVolume != toVolume) {
        if (gMusicCurrentVolume >= toVolume) {
            gMusicCurrentVolume--;
        } else {
            gMusicCurrentVolume++;
        }
        func_800561A4(gMusicCurrentVolume);
        gNextVolumeUpdateTimer = 3;
    }
}

s32 func_8014AD40(void) {
    MusicSettings* settings = gMusicSettings;
    s32 i;

    for (i = 0; i < 2; i++, settings++) {
        if (!(settings->flags & MUSIC_SETTINGS_FLAGS_1)) {
            continue;
        }

        if (func_800559FC(settings->songName)) {
            return TRUE;
        }
    }
    return FALSE;
}

void bgm_pop_song(void) {
    MusicSettings* musicSetting = gMusicSettings;

    if (gGameStatusPtr->demoState == 0) {
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_8;
        _bgm_set_song(0, musicSetting->savedSongID, musicSetting->savedVariation, 0, 8);
    }
}

void bgm_push_song(s32 songID, s32 variation) {
    MusicSettings* musicSetting = gMusicSettings;

    if (gGameStatusPtr->demoState == 0) {
        musicSetting->savedSongID = musicSetting->songID;
        musicSetting->savedVariation = musicSetting->variation;
        musicSetting->savedSongName = musicSetting->songName;
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_4;
        bgm_set_song(0, songID, variation, 500, 8);
    }
}

void bgm_pop_battle_song(void) {
    MusicSettings* musicSetting = gMusicSettings;

    if (gGameStatusPtr->demoState == 0) {
        if (gOverrideFlags & GLOBAL_OVERRIDES_20000) {
            gOverrideFlags &= ~GLOBAL_OVERRIDES_20000;
        } else {
            musicSetting->flags |= MUSIC_SETTINGS_FLAGS_8;
            _bgm_set_song(0, musicSetting->savedSongID, musicSetting->savedVariation, 0, 8);
            snd_ambient_80055590(0, 250);
        }
    }
}

void bgm_push_battle_song(void) {
    MusicSettings* musicSetting = gMusicSettings;

    if (gGameStatusPtr->demoState == 0 && !(gOverrideFlags & GLOBAL_OVERRIDES_20000)) {
        snd_ambient_8005553C(0, 250);
        musicSetting->savedSongID = musicSetting->songID;
        musicSetting->savedVariation = musicSetting->variation;
        musicSetting->savedSongName = musicSetting->songName;
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_4;
        bgm_set_song(0, musicSetting->battleSongID, musicSetting->battleVariation, 500, 8);
    }
}

void bgm_set_battle_song(s32 songID, s32 variation) {
    MusicSettings* musicSetting = gMusicSettings;

    musicSetting->battleSongID = songID;
    musicSetting->battleVariation = variation;
}

void func_8014AFA0(void) {
}
