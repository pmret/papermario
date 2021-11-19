#include "common.h"
#include "npc.h"

MusicSettings D_8014F6F0 = {
    .flags = 0,
    .unk_02 = 0,
    .fadeOutTime = -1,
    .fadeInTime = 0,
    .unk_0C = 0,
    .unk_0E = 0,
    .songID = -1,
    .variation = -1,
    .songName = -1,
    .unk_20 = 0,
    .unk_24 = 0,
    .unk_28 = 0,
    .unk_2C = 0
};

s32 gSongsUsingVariationFlag[] = { SONG_SPECIAL_BATTLE, SONG_TUBBA_BLUBBA_BATTLE, SONG_JR_TROOPA_BATTLE,
                                      SONG_YOSHI_KIDS_FOUND, SONG_ITEM_UPGRADE, SONG_NEW_PARTNER,
                                    };

s16 D_8014F738 = 0;

void bgm_set_target_volume(s16 volume);

/// If the given song ID is present in gSongsUsingVariationFlag, returns the current
/// map's `songVariation & 1` value. Otherwise, returns -1.
///
/// @see gSongsUsingVariationFlag
/// @returns -1: no override; 0: override to variation 0; 1 override to variation 1
s32 bgm_get_map_default_variation(s32 songID) {
    u32 i = 0;
    Area* areas = gAreas;
    GameStatus** gameStatus = &gGameStatusPtr;
    s32* allowed = gSongsUsingVariationFlag;

    for (i = 0; i < ARRAY_COUNT(gSongsUsingVariationFlag); i++) {
        if (allowed[i] == songID) {
            Map* map = &areas[(*gameStatus)->areaID].maps[(*gameStatus)->mapID];

            return map->unk_1C.bytes.songVariation & 1;
        }
    }

    return -1;
}

void bgm_reset_sequence_players(void) {
    MusicSettings* src; // TODO: remove this temp when .data section for this file (incl. D_8014F6F0) is set up
    s32 i;

    for (i = 0; i < 2; i++) {
        MusicSettings* musicSettings = gMusicSettings;
        musicSettings[i] = *(src = &D_8014F6F0);
    }

    gMusicTargetVolume = 8;
    gMusicUnkVolume2 = 8;
    gMusicCurrentVolume = 8;
    func_800561A4(8);
}

void bgm_reset_volume(void) {
    gMusicTargetVolume = 8;
    gMusicUnkVolume2 = 8;
}

INCLUDE_ASM(s32, "e0b30_len_b80", bgm_update_music_settings);

s32 _bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    if (gGameStatusPtr->demoState != 0) {
        return 1;
    } else {
        // TODO: these two lines likely a MUSIC_PLAYER(idx) macro
        MusicSettings* musicSettings = gMusicSettings;
        MusicSettings* musicSetting = &musicSettings[playerIndex];

        if (!gGameStatusPtr->musicEnabled) {
            func_800559C4(musicSetting->songName);
            musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_1;

            return 1;
        } else {
            s32 override = bgm_get_map_default_variation(songID);
            if (override >= 0) {
                variation = override;
            }

            if (musicSetting->songID == songID && musicSetting->variation == variation) {
                bgm_set_target_volume(volume);

                if (musicSetting->flags & MUSIC_SETTINGS_FLAGS_4) {
                    func_80055B80(musicSetting->songName);
                    musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_4;
                }

                return 2;
            }

            gMusicUnkVolume = volume;
            musicSetting->songID = songID;
            musicSetting->variation = variation;
            musicSetting->fadeOutTime = fadeOutTime;
            musicSetting->unk_02 = 1;
            musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_2;

            return 1;
        }
    }
}

s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    MusicSettings* musicSettings = gMusicSettings;

    musicSettings[playerIndex].flags &= ~8;

    return _bgm_set_song(playerIndex, songID, variation, fadeOutTime, volume);
}

s32 func_8014A964(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5) {
    if (gGameStatusPtr->demoState != 0) {
        return 1;
    } else {
        MusicSettings* musicSettings = gMusicSettings;
        MusicSettings* musicSetting = &musicSettings[playerIndex];

        if (!gGameStatusPtr->musicEnabled) {
            func_800559C4(musicSetting->songName);
            musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_1;

            return 1;
        } else {
            s32 defaultVariation = bgm_get_map_default_variation(songID);
            if (defaultVariation >= 0) {
                variation = defaultVariation;
            }

            musicSetting->fadeInTime = fadeInTime;
            musicSetting->unk_0C = arg4;
            musicSetting->unk_0E = arg5;
            musicSetting->songID = songID;
            musicSetting->variation = variation;
            musicSetting->flags |= MUSIC_SETTINGS_FLAGS_20;
            musicSetting->unk_02 = 1;
            musicSetting->flags &= ~MUSIC_SETTINGS_FLAGS_2;

            return 1;
        }
    }
}

s32 func_8014AA54(s32 playerIndex, s32 arg1, s16 arg2) {
    MusicSettings* musicSettings = gMusicSettings;
    MusicSettings* musicSetting = &musicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_2)) {
        return 0;
    }

    switch (arg2) {
        case 0:
            func_80056028(musicSetting->songName, arg1);
            break;
        case 1:
            func_80056044(musicSetting->songName, arg1);
            break;
        case 2:
            func_80056068(musicSetting->songName, arg1);
            break;
    }

    return 1;
}

s32 func_8014AB0C(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSettings = gMusicSettings;
    MusicSettings* musicSetting = &musicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    return func_80055DDC(musicSetting->songName, arg1);
}

s32 func_8014AB60(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSettings = gMusicSettings;
    MusicSettings* musicSetting = &musicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    return func_80055E48(musicSetting->songName, arg1);
}

s32 func_8014ABB4(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSettings = gMusicSettings;
    MusicSettings* musicSetting = &musicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    return func_80055CC4(musicSetting->songName, arg1);
}

s32 bgm_init_music_players(void) {
    bgm_set_song(0, -1, 0, 250, 8);
    bgm_set_song(1, -1, 0, 250, 8);

    return 1;
}

void bgm_quiet_max_volume(void) {
    gMusicUnkVolume2 = 4;
}

void bgm_reset_max_volume(void) {
    gMusicUnkVolume2 = 8;
}

void bgm_set_target_volume(s16 volume) {
    gMusicTargetVolume = volume;
}

//Data loading shenanigans
#ifdef NON_EQUIVALENT
void bgm_update_volume(void) {
    s16* currentVolume;
    s16 compareVolume;
    s16 toVolume;

    if (D_8014F738 != 0) {
        D_8014F738--;
        return;
    }

    compareVolume = gMusicTargetVolume;
    if (gMusicUnkVolume2 < gMusicTargetVolume) {
        compareVolume = gMusicUnkVolume2;
    }

    currentVolume = &gMusicCurrentVolume;
    if (*currentVolume != compareVolume) {
        toVolume = *currentVolume + 1;
        if (*currentVolume >= compareVolume) {
            toVolume = *currentVolume - 1;
        }
        *currentVolume = toVolume;
        func_800561A4(gMusicCurrentVolume);
        D_8014F738 = 3;
    }
}
#else
INCLUDE_ASM(s32, "e0b30_len_b80", bgm_update_volume);
#endif

INCLUDE_ASM(s32, "e0b30_len_b80", func_8014AD40);

void bgm_pop_song(void) {
    MusicSettings* musicSetting = &gMusicSettings[0];

    if (gGameStatusPtr->demoState == 0) {
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_8;
        _bgm_set_song(0, musicSetting->unk_24, musicSetting->unk_28, 0, 8);
    }
}

void bgm_push_song(s32 songID, s32 variation) {
    MusicSettings* musicSetting = &gMusicSettings[0];

    if (gGameStatusPtr->demoState == 0) {
        musicSetting->unk_24 = musicSetting->songID;
        musicSetting->unk_28 = musicSetting->variation;
        musicSetting->unk_2C = musicSetting->songName;
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_4;
        bgm_set_song(0, songID, variation, 500, 8);
    }
}

void bgm_pop_battle_song(void) {
    MusicSettings* musicSetting = &gMusicSettings[0];

    if (gGameStatusPtr->demoState == 0) {
        if (gOverrideFlags & 0x20000) {
            gOverrideFlags &= ~0x20000;
        } else {
            musicSetting->flags |= MUSIC_SETTINGS_FLAGS_8;
            _bgm_set_song(0, musicSetting->unk_24, musicSetting->unk_28, 0, 8);
            func_80055590(0, 250);
        }
    }
}

void bgm_push_battle_song(void) {
    MusicSettings* musicSetting = &gMusicSettings[0];

    if (gGameStatusPtr->demoState == 0 && !(gOverrideFlags & 0x20000)) {
        func_8005553C(0, 250);
        musicSetting->unk_24 = musicSetting->songID;
        musicSetting->unk_28 = musicSetting->variation;
        musicSetting->unk_2C = musicSetting->songName;
        musicSetting->flags |= MUSIC_SETTINGS_FLAGS_4;
        bgm_set_song(0, musicSetting->unk_1C, musicSetting->unk_20, 500, 8);
    }
}

void bgm_set_battle_song(s32 arg0, s32 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[0];

    musicSetting->unk_1C = arg0;
    musicSetting->unk_20 = arg1;
}

void func_8014AFA0(void) {
}
