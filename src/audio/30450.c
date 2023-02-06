#include "common.h"
#include "audio.h"

static u8* snd_song_get_track_volumes_set(MusicTrackVols arg0);

s32 PreventBGMPlayerUpdate = FALSE;
u16 D_80078DB4 = 0;
u16 AuAmbiencePlayOnlyIndex = 0;

// lists of data:
//  u8 trackIdx
//  u8 volume?
// repeated until idx = 0
u8 D_80078DB8[] = {
    2, 94,
    3, 80,
    4, 100,
    5, 84,
    0
};
u8 D_80078DC4[] = {
    2, 100,
    3, 110,
    4, 90,
    0
};
u8 D_80078DCC[] = {
    2, 95,
    0
};
u8 D_80078DD0[] = {
    5, 70,
    6, 90,
    7, 90,
    8, 100,
    0
};
// used in kpa_60-63
u8 TrackVols_KPA_Outside[] = {
    5, 0,
    6, 0,
    7, 0,
    8, 0,
    9, 0,
    10, 0,
    11, 0,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
// starting areas, only basic instrumentation
u8 TrackVols_KPA_1[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 0,
    10, 0,
    11, 0,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
// middle areas
u8 TrackVols_KPA_2[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 126,
    10, 88,
    11, 100,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
// final areas, full instrumentation
u8 TrackVols_KPA_3[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 126,
    10, 88,
    11, 100,
    12, 100,
    13, 106,
    14, 100,
    15, 100,
    16, 110,
    0
};

void func_80055050(ALHeap* heap) {
    D_80078DB4 = 1;
    PreventBGMPlayerUpdate = FALSE;
}

void func_80055068(u32 arg0) {
    u16 temp_a0 = D_80078DB4;
    u32 temp_v1 = arg0 & 0xF;

    if (temp_a0 == 1) {
        switch (temp_v1) {
            case 2:
            case 3:
                break;
            case 4:
                snd_start_sound_with_shift(arg0 >> 4, 0, 0, 0);
                break;
            case 1:
                if (temp_v1 == 1) {
                    s32 filename = au_song_load((arg0 >> 4) & 0xFF, 0);

                    if (filename > ASCII_TO_U32('0', ' ', ' ', '\0')) {
                        au_song_start_variation(filename, (arg0 >> 0xC) & 3);
                    }
                }
                break;
        }
    }
}

void func_80055110(BGMPlayer* player) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(player->unk_238); i++) {
        player->unk_238[i] = 0;
    }

    player->unk_25B = 0;
    player->unk_25A = 0;
    player->unk_259 = 0;
    player->unk_258 = 0;
}

void func_8005513C(u32 arg0) {
    BGMPlayer* player = NULL;
    u32 playerSwitch = arg0 & 0xF;

    if (playerSwitch != 0) {
        if (playerSwitch == 1) {
            player = gBGMPlayerA;
        } else if (playerSwitch == 2) {
            player = gBGMPlayerB;
        }

        if (player != NULL) {
            u32 temp;

            if (player->unk_258 < 8) {
                temp = player->unk_25A;

                player->unk_238[temp] = arg0 >> 4;

                temp++;
                if (temp >= 8) {
                    temp = 0;
                }
                player->unk_25A = temp;

                player->unk_258++;
            } else {
                temp = player->unk_25B + 1;

                if (temp > 99) {
                    temp = 99;
                }
                player->unk_25B = temp;
            }
        }
    }
}

void snd_start_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    au_sfx_enqueue_event(soundManager, soundID, vol, 0, pan);
}

void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    if (pitchShift > 2400) {
        pitchShift = 2400;
    } else if (pitchShift < -2400) {
        pitchShift = -2400;
    }

    au_sfx_enqueue_event(soundManager, soundID, vol, pitchShift, pan);
}

void snd_adjust_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    au_sfx_enqueue_event(soundManager, soundID | SOUND_ID_ADJUST, vol, 0, pan);
}

void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    if (pitchShift > 2400) {
        pitchShift = 2400;
    } else if (pitchShift < -2400) {
        pitchShift = -2400;
    }

    au_sfx_enqueue_event(soundManager, soundID | SOUND_ID_ADJUST, vol, pitchShift, pan);
}

void snd_stop_sound(s32 soundID) {
    SoundManager* soundManager = gSoundManager;

    au_sfx_enqueue_event(soundManager, soundID | SOUND_ID_STOP, 0, 0, 0);
}

void snd_reset(void) {
    gSoundManager->resetPending = 1;
}

void snd_start_sound_raw(s32 soundID, s16 volume, s16 pitchShift, s32 pan) {
    SoundManager* soundManager = gSoundManager;

    au_sfx_enqueue_event(soundManager, soundID, volume, pitchShift, pan);
}

AuResult snd_load_ambient(s32 ambSoundID) {
    return au_ambient_load(ambSoundID);
}

AuResult snd_ambient_play(s32 index, s32 fadeInTime) {
    AuResult status = au_amb_check_player_index(index);

    if (status != AU_RESULT_OK) {
        return status;
    }
    return au_amb_start(index, fadeInTime);
}

AuResult snd_ambient_stop_quick(s32 index) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_stop_quick(index);
    }

    return status;
}

AuResult snd_ambient_stop_slow(s32 index, s32 fadeOutTime) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_stop_slow(index, fadeOutTime);
    }

    return status;
}

AuResult snd_ambient_pause(s32 index, s32 fadeOutTime) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_pause(index, fadeOutTime);
    }

    return status;
}

AuResult snd_ambient_resume(s32 index, s32 fadeInTime) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_resume(index, fadeInTime);
    }

    return status;
}

AuResult snd_ambient_is_stopped(s32 index) {
    AuResult status = au_amb_check_player_index(index);

    if (status != AU_RESULT_OK) {
        return status;
    }
    return au_amb_is_stopped(index);
}

// TODO perhaps inaccurate name
AuResult snd_ambient_mute(s32 index, s32 arg1) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_load_tracks_fade(index, arg1);
    }

    return status;
}

AuResult snd_ambient_set_volume(s32 index, s32 time, s32 volume) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_set_volume(index, time, volume);
    }

    return status;
}

AuResult snd_ambient_disable(s32 index) {
    AuResult status = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_set_disabled(index, TRUE);
    }

    return status;
}

AuResult snd_ambient_enable(s32 index) {
    AuResult status  = au_amb_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_amb_set_disabled(index, FALSE);
    }

    return status;
}

// snd_ambient_init_tracks ?
void snd_ambient_80055760(s32 index) {
    u32 i;
    s32 lim = 4;

    AuAmbiencePlayOnlyIndex = 0xFF;

    for (i = 0; i < lim; i++) {
        if (snd_ambient_play(i, 0) != AU_RESULT_OK) {
            return;
        }
    }

    snd_ambient_play_only(index);
}

AuResult snd_ambient_stop_all(s32 time) {
    AuResult status = AU_RESULT_OK;
    s32 lim = 4;
    u32 i;

    for (i = 0; i < lim; i++) {
        if (i == AuAmbiencePlayOnlyIndex) {
            status = snd_ambient_stop_slow(i, time);
        } else {
            status = snd_ambient_stop_quick(i);
        }
        if (status != AU_RESULT_OK) {
            break;
        }
    }
    return status;
}

AuResult snd_ambient_play_only(s32 index) {
    AuResult status = AU_RESULT_OK;
    s32 lim = 4;

    if (index != AuAmbiencePlayOnlyIndex) {
        u32 i;

        for (i = 0; i < lim; i++) {
            if (i == index) {
                status = snd_ambient_enable(i);
            } else {
                status = snd_ambient_disable(i); // mute
            }

            if (status != AU_RESULT_OK) {
                break;
            }
        }

        if (status == AU_RESULT_OK) {
            AuAmbiencePlayOnlyIndex = index;
        }
    }

    return status;
}

AuResult au_song_load(s32 songID, s32 playerIndex) {
    BGMHeader* bgmFile;
    BGMPlayer* player;

    au_get_bgm_player_and_file(playerIndex, &bgmFile, &player);

    if (bgmFile != NULL) {
        return au_load_song_files(songID, bgmFile, player);
    } else {
        return AU_ERROR_NULL_SONG_NAME;
    }
}

AuResult au_song_start(s32 songName) {
    AuResult status;
    SongUpdateEvent s;

    PreventBGMPlayerUpdate = TRUE;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 127;
    s.finalVolume = 127;
    s.variation = 0;
    s.unk14 = 0;
    status = au_bgm_dispatch_player_event(&s);
    PreventBGMPlayerUpdate = FALSE;

    return status;
}

AuResult au_song_start_variation(s32 songName, s32 variation) {
    AuResult status;
    SongUpdateEvent s;

    PreventBGMPlayerUpdate = TRUE;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 127;
    s.finalVolume = 127;
    s.variation = variation;
    s.unk14 = 0;
    status = au_bgm_dispatch_player_event(&s);
    PreventBGMPlayerUpdate = FALSE;

    return status;
}

AuResult au_song_stop(s32 songName) {
    return au_bgm_stop_song(songName);
}

void au_stop_songs(void) {
    au_bgm_stop_all();
}

AuResult au_song_is_playing(s32 songName) {
    return au_bgm_is_song_playing(songName);
}

AuResult snd_set_song_variation_fade(s32 songName, s32 variation, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult status;
    SongUpdateEvent s;

    PreventBGMPlayerUpdate = TRUE;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = variation;
    s.unk14 = 0;
    status = au_bgm_dispatch_player_event(&s);
    PreventBGMPlayerUpdate = FALSE;

    return status;
}

AuResult snd_set_song_fade(s32 songName, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult status;
    SongUpdateEvent s;

    PreventBGMPlayerUpdate = TRUE;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = 0;
    s.unk14 = 0;
    status = au_bgm_dispatch_player_event(&s);
    PreventBGMPlayerUpdate = FALSE;

    return status;
}

AuResult snd_set_song_variation_fade_time(s32 songName, s32 fadeTime, s32 variation) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = fadeTime;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = variation;
    s.unk14 = 0;
    return func_8004DB4C(&s);
}

AuResult func_80055AF0(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 0);
}

AuResult func_80055B28(s32 songName) {
    AuResult status;
    SongUpdateEvent s;

    PreventBGMPlayerUpdate = TRUE;
    s.songName = songName;
    s.duration = 2000;
    s.startVolume = 1;
    s.finalVolume = 127;
    s.variation = 0;
    s.unk14 = 0;
    status = func_8004DE2C(&s);
    PreventBGMPlayerUpdate = FALSE;

    return status;
}

AuResult func_80055B80(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 1);
}

AuResult func_80055BB8(s32 songName, s32 fadeTime) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = fadeTime;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DB4C(&s);
}

AuResult func_80055BF0(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DCB8(&s, 0);
}

AuResult func_80055C2C(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DE2C(&s);
}

AuResult func_80055C64(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 500;
    s.finalVolume = 0x2000;
    return func_8004E0F4(&s);
}

AuResult func_80055C94(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 500;
    s.finalVolume = 0x7FFF;
    return func_8004E0F4(&s);
}

AuResult snd_set_song_variation(s32 songName, s32 variation) {
    SongUpdateEvent s;
    s.songName = songName;
    s.variation = variation;
    return func_80050970(&s);
}

// get file and player information for a given song name if it's currently playing
AuResult snd_song_get_playing_info(s32 songName, BGMHeader** outFile, BGMPlayer** outPlayer) {
    AuResult status = AU_RESULT_OK;
    BGMHeader* bgmFile;

    bgmFile = gSoundGlobals->dataBGM[0];
    if (songName == bgmFile->name) {
        *outPlayer = gBGMPlayerA;
        *outFile = bgmFile;
    } else {
        bgmFile = gSoundGlobals->dataBGM[1];
        if (songName == bgmFile->name) {
            *outPlayer = gBGMPlayerB;
            *outFile = bgmFile;
        } else {
            status = AU_ERROR_1;
        }
    }
    return status;
}

AuResult snd_song_set_playback_rate(s32 songName, f32 rate) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);

    if (status == AU_RESULT_OK) {
        au_bgm_set_playback_rate(bgmPlayer, rate);
    }

    return status;
}

AuResult snd_song_set_detune(s32 songName, s32 detune) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);

    if (status == AU_RESULT_OK) {
        au_bgm_player_set_detune(bgmPlayer, detune);
    }

    return status;
}

AuResult snd_song_set_track_volumes(s32 songName, MusicTrackVols trackVolSet) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);

    if (status == AU_RESULT_OK) {
        u8* trackVols = snd_song_get_track_volumes_set(trackVolSet);

        if (trackVols != NULL) {
            au_bgm_set_track_volumes(bgmPlayer, trackVols, TRUE);
        } else {
            status = AU_ERROR_11;
        }
    }

    return status;
}

AuResult snd_song_clear_track_volumes(s32 songName, MusicTrackVols trackVolSet) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);

    if (status == AU_RESULT_OK) {
        u8* trackVols = snd_song_get_track_volumes_set(trackVolSet);

        if (trackVols != NULL) {
            au_bgm_set_track_volumes(bgmPlayer, trackVols, FALSE);
        } else {
            status = AU_ERROR_11;
        }
    }

    return status;
}

static u8* snd_song_get_track_volumes_set(MusicTrackVols trackVolSet) {
    u8* trackVols = NULL;

    switch (trackVolSet) {
        case TRACK_VOLS_0:
            trackVols = D_80078DB8;
            break;
        case TRACK_VOLS_1:
            trackVols = D_80078DC4;
            break;
        case TRACK_VOLS_2:
            trackVols = D_80078DCC;
            break;
        case TRACK_VOLS_3:
            trackVols = D_80078DD0;
            break;
        case TRACK_VOLS_KPA_OUTSIDE:
            trackVols = TrackVols_KPA_Outside;
            break;
        case TRACK_VOLS_KPA_1:
            trackVols = TrackVols_KPA_1;
            break;
        case TRACK_VOLS_KPA_2:
            trackVols = TrackVols_KPA_2;
            break;
        case TRACK_VOLS_KPA_3:
            trackVols = TrackVols_KPA_3;
            break;
    }

    return trackVols;
}

static const f32 padding[] = {0.0f};

static AuResult snd_song_change_track_volume(s32 songName, u32 trackIdx, u32 volume) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);
    if (status == AU_RESULT_OK) {
        if (volume > 0x7F) {
            volume = 0x7F;
        }
        if (trackIdx > 15) {
            trackIdx = 15;
        }
        au_bgm_change_track_volume(bgmPlayer, trackIdx, 96, volume);
    }
    return status;
}

AuResult snd_song_set_track_vol_mute(s32 songName, s32 trackIdx) {
    return snd_song_change_track_volume(songName, trackIdx, 0);
}

AuResult snd_song_set_track_vol_quiet(s32 songName, s32 trackIdx) {
    return snd_song_change_track_volume(songName, trackIdx, 0x3F);
}

AuResult snd_song_set_track_vol_full(s32 songName, s32 trackIdx) {
    return snd_song_change_track_volume(songName, trackIdx, 0x7F);
}

void bgm_set_proximity_mix_far(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix);
}

void bgm_set_proximity_mix_near(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix | 0x57000000);
}

void bgm_set_proximity_mix_full(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix | 0x7F000000);
}

void bgm_poll_music_events(MusicEventTrigger** musicEvents, s32* count) {
    AuGlobals* globals = gSoundGlobals;

    *musicEvents = globals->musicEventQueue;
    *count = globals->musicEventQueueCount;
}

void bgm_flush_music_events(void) {
    gSoundGlobals->flushMusicEventQueue = TRUE;
}

void bgm_trigger_music_event(s32 playerID, s32 trackIndex, s32 eventInfo) {
    AuGlobals* globals = gSoundGlobals;

    if (globals->musicEventQueueCount < 16) {
        *globals->musicEventQueuePos++ = ((playerID << 0x1C) + ((trackIndex & 0xF) << 0x18) + eventInfo);
        globals->musicEventQueueCount++;
    }
}

void bgm_clear_music_events(void) {
    AuGlobals* globals = gSoundGlobals;
    s32* buf = globals->musicEventQueue;
    s32 i = 15;

    do {
        *buf++ = 0;
    } while (i-- != 0);

    globals->musicEventQueueCount = 0;
    globals->flushMusicEventQueue = FALSE;
    globals->musicEventQueuePos = globals->musicEventQueue;
}

void au_register_callback(AuCallback func, s32 index) {
    gSoundGlobals->audioThreadCallbacks[index] = func;
}

void audio_set_stereo(void) {
    func_80056D5C(1);
    func_80054DA8(0);
}

void audio_set_mono(void) {
    func_80056D5C(0);
    func_80054DA8(1);
}

void func_800561A4(s32 arg0) {
    func_80054CE0(1, arg0);
}

void func_800561C4(s32 arg0) {
    func_80054CE0(0x10, arg0);
}

void func_800561E4(s32 arg0) {
    func_80054D74(0x10, arg0);
}

void enable_sounds(void) {
    au_sfx_set_state(gSoundManager, SND_MANAGER_STATE_ENABLED);
}

void disable_sounds(void) {
    au_sfx_set_state(gSoundManager, SND_MANAGER_STATE_DISABLED);
}
