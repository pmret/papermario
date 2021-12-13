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
    gMusicUnkVolume2 = 8;
    gMusicCurrentVolume = 8;
    func_800561A4(8);
}

void bgm_reset_volume(void) {
    gMusicTargetVolume = 8;
    gMusicUnkVolume2 = 8;
}

// Loop struct shenanigans
#ifdef NON_EQUIVALENT

// Experiment to fix loop
typedef struct MusicSettingsInner {
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 fadeOutTime;
    /* 0x08 */ s32 fadeInTime;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s32 songID;
    /* 0x14 */ s32 variation;
    /* 0x18 */ s32 songName;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} MusicSettingsInner;

typedef struct MusicSettings2 {
    /* 0x00 */ u16 flags;
    /* 0x02 */ MusicSettingsInner unk_02;
} MusicSettings2; // size = 0x30

void bgm_update_music_settings(void) {
    MusicSettingsInner* inner;
    MusicSettings2* phi_s1;
    s32* flags;
    s32 phi_v0;
    s32 i;
    s32 a;
    s32 c;

    phi_s1 = gMusicSettings;

    for (i = 0; i < 2; i++, phi_s1++) {
        inner = &phi_s1->unk_02;
        c = 2;
        a = ~0x4;

        switch (inner->unk_02) {
            case 0:
                break;
            case 1:
                if (phi_s1->flags & 1) {
                    if (inner->fadeOutTime < 250) {
                        if (!(phi_s1->flags & 4)) {
                            phi_v0 = func_800559C4(inner->songName);
                        } else {
                            phi_v0 = func_80055AF0(inner->songName);
                        }
                    } else if (!(phi_s1->flags & 4)) {
                        phi_v0 = snd_set_song_variation_fade_time(inner->songName, inner->fadeOutTime, 0);
                    } else {
                        phi_v0 = func_80055BB8(inner->songName, 0xFA);
                    }
                    if (phi_v0 == 0) {
                        inner->unk_02 = c;
                    }
                } else {
                    if (phi_s1->flags & 4) {
                        phi_s1->flags |= 0x10;
                    }
                    phi_s1->flags &= a;
                    inner->unk_02 = 5;
                }
                break;
            case 2:
                phi_s1->flags &= a;
                if (!(phi_s1->flags & 1)) {
                    inner->unk_02 = 5;
                    break;
                }

                if (func_800559FC(inner->songName) == 0) {
                    phi_s1->flags &= ~0x1;
                    inner->unk_02 = 3;
                }

                break;
            case 3:
                inner->unk_02 = 4;
                break;
            case 4:
                inner->unk_02 = 5;
                break;
            case 5:
                if (!(phi_s1->flags & 8)) {
                    if (inner->songID < 0) {
                        inner->unk_02 = 0;
                    } else {
                        inner->songName = snd_load_song(inner->songID, i);
                        if (inner->songName > 0xFFFFU) {
                            if ((phi_s1->flags & 0x20) != 0) {
                                snd_set_song_variation_fade(inner->songName, inner->variation, inner->fadeInTime, inner->unk_0C, inner->unk_0E);
                                phi_s1->flags &= ~0x20;
                            } else {
                                bgm_set_target_volume(gMusicUnkVolume);
                            }
                            if (snd_start_song_variation(inner->songName, inner->variation) == 0) {
                                phi_s1->flags |= 1;
                                inner->unk_02 = 0;
                            }
                        }
                    }
                } else {
                    if (phi_s1->flags & 0x10) {
                        inner->unk_02 = 0;
                        phi_s1->flags &= ~0x18;
                    } else if (func_80055B28(inner->unk_2C) == 0) {
                        inner->unk_02 = 0;
                        inner->songID = inner->unk_24;
                        inner->variation = inner->unk_28;
                        inner->songName = inner->unk_2C;
                        phi_s1->flags |= 1;
                        phi_s1->flags &= ~0x8;
                    }
                }
                break;
        }
    }
    bgm_update_volume();
}
#else
INCLUDE_ASM(s32, "e0b30_len_b80", bgm_update_music_settings);
#endif

s32 _bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    if (gGameStatusPtr->demoState != 0) {
        return 1;
    } else {
        MusicSettings* musicSetting = &gMusicSettings[playerIndex];

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
    gMusicSettings[playerIndex].flags &= ~8;

    return _bgm_set_song(playerIndex, songID, variation, fadeOutTime, volume);
}

s32 func_8014A964(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5) {
    if (gGameStatusPtr->demoState != 0) {
        return 1;
    } else {
        MusicSettings* musicSetting = &gMusicSettings[playerIndex];

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
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

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
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    return func_80055DDC(musicSetting->songName, arg1);
}

s32 func_8014AB60(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

    if (!(musicSetting->flags & MUSIC_SETTINGS_FLAGS_1)) {
        return 0;
    }

    return func_80055E48(musicSetting->songName, arg1);
}

s32 func_8014ABB4(s32 playerIndex, s16 arg1) {
    MusicSettings* musicSetting = &gMusicSettings[playerIndex];

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

void bgm_update_volume(void) {
    s16 toVolume;

    if (D_8014F738 != 0) {
        D_8014F738--;
        return;
    }

    toVolume = gMusicTargetVolume;
    if (toVolume > gMusicUnkVolume2) {
        toVolume = gMusicUnkVolume2;
    }

    if (gMusicCurrentVolume != toVolume) {
        if (gMusicCurrentVolume >= toVolume) {
            gMusicCurrentVolume--;
        } else {
            gMusicCurrentVolume++;
        }
        func_800561A4(gMusicCurrentVolume);
        D_8014F738 = 3;
    }
}

// can't figure out the loop
#ifdef NON_EQUIVALENT
s32 func_8014AD40(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (!(gMusicSettings[i].flags & MUSIC_SETTINGS_FLAGS_1)) {
            continue;
        }

        if (func_800559FC(gMusicSettings[i].songName) != 0) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "e0b30_len_b80", func_8014AD40);
#endif

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
