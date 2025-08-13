#include "common.h"
#include "npc.h"
#include "audio.h"

void bgm_update_volume(void);
void bgm_set_target_volume(s32 volume);

BSS s16 MusicDefaultVolume;
BSS s16 MusicTargetVolume;
BSS s16 MusicMaxVolume;
BSS s16 MusicCurrentVolume;

MusicControlData gMusicControlData[2];

MusicControlData BlankMusicControlData = {
    .flags = 0,
    .state = MUSIC_STATE_IDLE,
    .fadeOutTime = -1,
    .fadeInTime = 0,
    .fadeStartVolume = 0,
    .fadeEndVolume = 0,
    .requestedSongID = AU_SONG_NONE,
    .variation = -1,
    .songName = -1,
    .battleSongID = 0,
    .battleVariation = 0,
    .savedSongID = 0,
    .savedVariation = 0,
    .savedSongName = 0
};

/// Lists the songs that are forced to use the variation determined by `map.songVariation & 1`.
/// @see bgm_get_map_default_variation
s32 SongsUsingVariationFlag[] = {
    SONG_SPECIAL_BATTLE,
    SONG_TUBBA_BLUBBA_BATTLE,
    SONG_JR_TROOPA_BATTLE,
    SONG_YOSHI_KIDS_FOUND,
    SONG_ITEM_UPGRADE,
    SONG_NEW_PARTNER,
};

s16 NextVolumeUpdateTimer = 0;

/// If the given song ID is present in SongsUsingVariationFlag, returns the current
/// map's `songVariation & 1` value. Otherwise, returns -1.
///
/// @see SongsUsingVariationFlag
/// @returns -1: no override; 0: override to variation 0; 1 override to variation 1
s32 bgm_get_map_default_variation(s32 songID) {
    u32 i;

    for (i = 0; i < ARRAY_COUNT(SongsUsingVariationFlag); i++) {
        if (SongsUsingVariationFlag[i] == songID) {
            MapConfig* map = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];

            return map->songVariation & 1;
        }
    }

    return -1;
}

void bgm_reset_sequence_players(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMusicControlData); i++) {
        gMusicControlData[i] = BlankMusicControlData;
    }

    MusicTargetVolume = VOL_LEVEL_FULL;
    MusicMaxVolume = VOL_LEVEL_FULL;
    MusicCurrentVolume = VOL_LEVEL_FULL;
    snd_set_bgm_volume(VOL_LEVEL_FULL);
}

void bgm_reset_volume(void) {
    MusicTargetVolume = VOL_LEVEL_FULL;
    MusicMaxVolume = VOL_LEVEL_FULL;
}

//TODO refactor out constants
void bgm_update_music_control(void) {
    MusicControlData* music = gMusicControlData;
    s32 i = 0;
    s16 stateFadeOut = MUSIC_STATE_AWAIT_FADEOUT;
    s16 pushedFlag = MUSIC_FLAG_PUSHING;
    s32 flags;

    for (i; i < ARRAY_COUNT(gMusicControlData); i++, music++) {
        switch (music->state) {
            case MUSIC_STATE_IDLE:
                break;
            case MUSIC_STATE_STOP_CURRENT:
                if (music->flags & MUSIC_FLAG_PLAYING) {
                    if (music->fadeOutTime < 250) {
                        if (!(music->flags & MUSIC_FLAG_PUSHING)) {
                            if (snd_song_stop(music->songName) == AU_RESULT_OK) {
                                music->state = stateFadeOut;
                            }
                        } else {
                            if (snd_song_push_stop(music->songName) == AU_RESULT_OK) {
                                music->state = stateFadeOut;
                            }
                        }
                    } else if (!(music->flags & MUSIC_FLAG_PUSHING)) {
                        if (snd_song_request_fade_out(music->songName, music->fadeOutTime, nullptr) == AU_RESULT_OK) {
                            music->state = stateFadeOut;
                        }
                    } else {
                        if (snd_song_request_push_fade_out(music->songName, 250) == AU_RESULT_OK) {
                            music->state = stateFadeOut;
                        }
                    }
                } else {
                    if (music->flags & MUSIC_FLAG_PUSHING) {
                        // nothing was playing in this case, so remember to skip the next pop
                        music->flags |= MUSIC_FLAG_IGNORE_POP;
                    }
                    music->flags &= ~pushedFlag;
                    music->state = MUSIC_STATE_PLAY_NEXT;
                }
                break;
            case MUSIC_STATE_AWAIT_FADEOUT:
                flags = music->flags;
                music->flags &= ~pushedFlag;
                if (flags & MUSIC_FLAG_PLAYING) {
                    if (snd_song_is_playing(music->songName) == AU_RESULT_OK) {
                        music->flags &= ~MUSIC_FLAG_PLAYING;
                        music->state = MUSIC_STATE_DELAY_2;
                    }
                } else {
                    music->state = MUSIC_STATE_PLAY_NEXT;
                }
                break;
            case MUSIC_STATE_DELAY_2:
                music->state = MUSIC_STATE_DELAY_1;
                break;
            case MUSIC_STATE_DELAY_1:
                music->state = MUSIC_STATE_PLAY_NEXT;
                break;
            case MUSIC_STATE_PLAY_NEXT:
                if (!(music->flags & MUSIC_FLAG_POPPING)) {
                    if (music->requestedSongID <= AU_SONG_NONE) {
                        // new song is AU_SONG_NONE, play nothing
                        music->state = MUSIC_STATE_IDLE;
                    } else {
                        music->songName = snd_song_load(music->requestedSongID, i);
                        // snd_song_lond may return either songName or an AuResult error code.
                        // since song names are 4-character big-endian identifiers packed into an s32, we require
                        // the upper half of the return value to be nonzero for songs which loaded without error.
                        // this reserves return values from 0 to 0xFFFF for AuResult codes.
                        if (music->songName > 0xFFFFU) {
                            if ((music->flags & MUSIC_FLAG_FADE_IN_NEXT)) {
                                snd_song_request_fade_in(music->songName, music->variation,
                                    music->fadeInTime, music->fadeStartVolume, music->fadeEndVolume);
                                music->flags &= ~MUSIC_FLAG_FADE_IN_NEXT;
                            } else {
                                // if we aren't fading in, just start at the default volume level
                                bgm_set_target_volume(MusicDefaultVolume);
                            }
                            /// @bug this is called even if we are trying to fade in, immediately overriding any fade parameters
                            if (snd_song_request_play(music->songName, music->variation) == AU_RESULT_OK) {
                                music->flags |= MUSIC_FLAG_PLAYING;
                                music->state = MUSIC_STATE_IDLE;
                            }
                        }
                    }
                } else {
                    if (music->flags & MUSIC_FLAG_IGNORE_POP) {
                        music->state = MUSIC_STATE_IDLE;
                        music->flags &= ~(MUSIC_FLAG_IGNORE_POP | MUSIC_FLAG_POPPING);
                    } else if (snd_song_request_pop(music->savedSongName) == AU_RESULT_OK) {
                        music->requestedSongID = music->savedSongID;
                        music->variation = music->savedVariation;
                        music->songName = music->savedSongName;
                        music->state = MUSIC_STATE_IDLE;
                        music->flags |= MUSIC_FLAG_PLAYING;
                        music->flags &= ~MUSIC_FLAG_POPPING;
                    }
                }
                break;
        }
    }
    bgm_update_volume();
}

s32 _bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    MusicControlData* music;
    s32 mapSongVariation;

    if (gGameStatusPtr->demoState != DEMO_STATE_NONE) {
        return 1;
    }

    music = &gMusicControlData[playerIndex];

    if (!gGameStatusPtr->musicEnabled) {
        snd_song_stop(music->songName);
        music->flags &= ~MUSIC_FLAG_PLAYING;
        return 1;
    }

    mapSongVariation = bgm_get_map_default_variation(songID);
    if (mapSongVariation >= 0) {
        variation = mapSongVariation;
    }

    if (music->requestedSongID == songID && music->variation == variation) {
        bgm_set_target_volume(volume);

        if (music->flags & MUSIC_FLAG_PUSHING) {
            snd_song_request_snapshot(music->songName);
            music->flags &= ~MUSIC_FLAG_PUSHING;
        }

        return 2;
    }

    MusicDefaultVolume = volume;
    music->requestedSongID = songID;
    music->variation = variation;
    music->fadeOutTime = fadeOutTime;
    music->state = MUSIC_STATE_STOP_CURRENT;
    music->flags &= ~MUSIC_FLAG_ENABLE_PROX_MIX;

    return 1;
}

s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume) {
    gMusicControlData[playerIndex].flags &= ~MUSIC_FLAG_POPPING;

    return _bgm_set_song(playerIndex, songID, variation, fadeOutTime, volume);
}

bool bgm_fade_in_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 fadeStartVolume, s16 fadeEndVolume) {
    MusicControlData* music;
    s32 mapSongVariation;

    if (gGameStatusPtr->demoState) {
        return true;
    }

    music = &gMusicControlData[playerIndex];

    if (!gGameStatusPtr->musicEnabled) {
        snd_song_stop(music->songName);
        music->flags &= ~MUSIC_FLAG_PLAYING;
        return true;
    }

    mapSongVariation = bgm_get_map_default_variation(songID);
    if (mapSongVariation >= 0) {
        variation = mapSongVariation;
    }

    music->fadeInTime = fadeInTime;
    music->fadeStartVolume = fadeStartVolume;
    music->fadeEndVolume = fadeEndVolume;
    music->requestedSongID = songID;
    music->variation = variation;
    music->flags |= MUSIC_FLAG_FADE_IN_NEXT;
    music->state = MUSIC_STATE_STOP_CURRENT;
    music->flags &= ~MUSIC_FLAG_ENABLE_PROX_MIX;

    return true;
}

s32 bgm_adjust_proximity(s32 playerIndex, s32 mix, s16 state) {
    MusicControlData* music = &gMusicControlData[playerIndex];

    if (!(music->flags & MUSIC_FLAG_PLAYING)) {
        return false;
    }

    if (!(music->flags & MUSIC_FLAG_ENABLE_PROX_MIX)) {
        return false;
    }

    switch (state) {
        case MUSIC_PROXIMITY_FAR:
            snd_song_set_proximity_mix_far(music->songName, mix);
            break;
        case MUSIC_PROXIMITY_NEAR:
            snd_song_set_proximity_mix_near(music->songName, mix);
            break;
        case MUSIC_PROXIMITY_FULL:
            snd_song_set_proximity_mix_full(music->songName, mix);
            break;
    }
    return true;
}

AuResult bgm_set_track_volumes(s32 playerIndex, s16 trackVolSet) {
    MusicControlData* music = &gMusicControlData[playerIndex];

    if (!(music->flags & MUSIC_FLAG_PLAYING)) {
        return AU_RESULT_OK;
    }

    return snd_song_set_track_volumes(music->songName, trackVolSet);
}

AuResult bgm_clear_track_volumes(s32 playerIndex, s16 trackVolSet) {
    MusicControlData* music = &gMusicControlData[playerIndex];

    if (!(music->flags & MUSIC_FLAG_PLAYING)) {
        return AU_RESULT_OK;
    }

    return snd_song_clear_track_volumes(music->songName, trackVolSet);
}

AuResult bgm_set_linked_mode(s32 playerIndex, b16 mode) {
    MusicControlData* music = &gMusicControlData[playerIndex];

    if (!(music->flags & MUSIC_FLAG_PLAYING)) {
        return AU_RESULT_OK;
    }

    return snd_song_set_linked_mode(music->songName, mode);
}

s32 bgm_init_music_players(void) {
    bgm_set_song(0, AU_SONG_NONE, 0, 250, VOL_LEVEL_FULL);
    bgm_set_song(1, AU_SONG_NONE, 0, 250, VOL_LEVEL_FULL);

    return 1;
}

void bgm_quiet_max_volume(void) {
    MusicMaxVolume = VOL_LEVEL_4;
}

void bgm_reset_max_volume(void) {
    MusicMaxVolume = VOL_LEVEL_FULL;
}

void bgm_set_target_volume(s32 volume) {
    MusicTargetVolume = volume;
}

void bgm_update_volume(void) {
    s16 toVolume;

    if (NextVolumeUpdateTimer != 0) {
        NextVolumeUpdateTimer--;
        return;
    }

    toVolume = MusicTargetVolume;
    if (toVolume > MusicMaxVolume) {
        toVolume = MusicMaxVolume;
    }

    if (MusicCurrentVolume != toVolume) {
        if (MusicCurrentVolume >= toVolume) {
            MusicCurrentVolume--;
        } else {
            MusicCurrentVolume++;
        }
        snd_set_bgm_volume(MusicCurrentVolume);
        NextVolumeUpdateTimer = 3;
    }
}

bool bgm_is_any_song_playing(void) {
    MusicControlData* music = gMusicControlData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMusicControlData); i++, music++) {
        if (music->flags & MUSIC_FLAG_PLAYING) {
            if (snd_song_is_playing(music->songName)) {
                return true;
            }
        }
    }
    return false;
}

void bgm_pop_song(void) {
    MusicControlData* music = gMusicControlData;

    if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
        music->flags |= MUSIC_FLAG_POPPING;
        _bgm_set_song(0, music->savedSongID, music->savedVariation, 0, VOL_LEVEL_FULL);
    }
}

void bgm_push_song(s32 songID, s32 variation) {
    MusicControlData* music = gMusicControlData;

    if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
        music->savedSongID = music->requestedSongID;
        music->savedVariation = music->variation;
        music->savedSongName = music->songName;
        music->flags |= MUSIC_FLAG_PUSHING;
        bgm_set_song(0, songID, variation, 500, VOL_LEVEL_FULL);
    }
}

void bgm_pop_battle_song(void) {
    MusicControlData* music = gMusicControlData;

    if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
        if (gOverrideFlags & GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE) {
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE;
        } else {
            music->flags |= MUSIC_FLAG_POPPING;
            _bgm_set_song(0, music->savedSongID, music->savedVariation, 0, VOL_LEVEL_FULL);
            snd_ambient_resume(0, 250);
        }
    }
}

void bgm_push_battle_song(void) {
    MusicControlData* music = gMusicControlData;

    if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
        if (!(gOverrideFlags & GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)) {
            snd_ambient_pause(0, 250);
            music->savedSongID = music->requestedSongID;
            music->savedVariation = music->variation;
            music->savedSongName = music->songName;
            music->flags |= MUSIC_FLAG_PUSHING;
            bgm_set_song(0, music->battleSongID, music->battleVariation, 500, VOL_LEVEL_FULL);
        }
    }
}

void bgm_set_battle_song(s32 songID, s32 variation) {
    MusicControlData* music = gMusicControlData;

    music->battleSongID = songID;
    music->battleVariation = variation;
}

void bgm_NOOP(void) {
}
