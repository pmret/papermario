#include "common.h"
#include "audio.h"
#include "audio/core.h"

static u8* snd_song_get_track_volumes_set(MusicTrackVols arg0);

/// While true, the audio thread skips BGM player updates.
/// Used by the game thread to lock out BGM updates while modifying player state,
/// to prevent race conditions.
s32 PreventBGMPlayerUpdate = false;

u16 SoundEngineReady = 0;
u16 AmbienceRadioChannel = 0;

// lists of data:
//  u8 trackIdx
//  u8 volume
// repeated until idx = 0
u8 TrackVols_JAN_Full[] = {
    2, 94,
    3, 80,
    4, 100,
    5, 84,
    0
};
u8 TrackVols_Unused1[] = {
    2, 100,
    3, 110,
    4, 90,
    0
};
u8 TrackVols_TIK_Shiver[] = {
    2, 95,
    0
};
u8 TrackVols_Unused3[] = {
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

void snd_notify_engine_ready(ALHeap* heap) {
    SoundEngineReady = 1;
    PreventBGMPlayerUpdate = false;
}

/// Unused
/// Seems to be an early function that accepts a command to play any kind of audio asset,
// but only BGM and SFX are supported.
void snd_legacy_sound_dispatch(u32 id) {
    u16 ready = SoundEngineReady;
    u32 type = id & 0xF;

    if (ready == 1) {
        switch (type) {
            case 2:
            case 3:
                break;
            case 4:
                snd_start_sound_with_shift(id >> 4, 0, 0, 0);
                break;
            case 1:
                if (type == 1) {
                    s32 filename = snd_song_load((id >> 4) & 0xFF, 0);

                    if (filename > ASCII_TO_U32('0', ' ', ' ', '\0')) {
                        snd_song_request_play(filename, (id >> 0xC) & 3);
                    }
                }
                break;
        }
    }
}

/// Part of an unused system for inter-thread communication with a BGM player using commands.
/// Use functions in bgm_control to manipualte gMusicControlData instead.
void snd_bgm_clear_legacy_commands(BGMPlayer* player) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(player->cmdBufData); i++) {
        player->cmdBufData[i] = 0;
    }

    player->cmdBufOverflows = 0;
    player->cmdBufWritePos = 0;
    player->cmdBufReadPos = 0;
    player->cmdBufPending = 0;
}

/// Unused
/// Part of an unused system for inter-thread communication with a BGM player using commands.
/// Use functions in bgm_control to manipualte gMusicControlData instead.
void snd_bgm_enqueue_legacy_command(u32 cmd) {
    BGMPlayer* player = nullptr;
    u32 playerID = cmd & 0xF;

    if (playerID == 0) {
        return;
    } else if (playerID == 1) {
        player = gBGMPlayerA;
    } else if (playerID == 2) {
        player = gBGMPlayerB;
    }

    if (player != nullptr) {
        u32 pos;

        if (player->cmdBufPending < ARRAY_COUNT(player->cmdBufData)) {
            pos = player->cmdBufWritePos;

            player->cmdBufData[pos] = cmd >> 4;

            pos++;
            if (pos >= 8) {
                pos = 0;
            }
            player->cmdBufWritePos = pos;

            player->cmdBufPending++;
        } else {
            pos = player->cmdBufOverflows + 1;

            if (pos > 99) {
                pos = 99;
            }
            player->cmdBufOverflows = pos;
        }
    }
}

void snd_start_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > AU_PAN_MAX) {
        pan = AU_PAN_MAX;
    }

    au_sfx_enqueue_event(soundManager, soundID, vol, 0, pan);
}

void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > AU_PAN_MAX) {
        pan = AU_PAN_MAX;
    }

    if (pitchShift > 2 * AU_OCTAVE_CENTS) {
        pitchShift = 2 * AU_OCTAVE_CENTS;
    } else if (pitchShift < -2 * AU_OCTAVE_CENTS) {
        pitchShift = -2 * AU_OCTAVE_CENTS;
    }

    au_sfx_enqueue_event(soundManager, soundID, vol, pitchShift, pan);
}

void snd_adjust_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > AU_PAN_MAX) {
        pan = AU_PAN_MAX;
    }

    au_sfx_enqueue_event(soundManager, soundID | SOUND_ID_ADJUST, vol, 0, pan);
}

void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > AU_PAN_MAX) {
        pan = AU_PAN_MAX;
    }

    if (pitchShift > 2 * AU_OCTAVE_CENTS) {
        pitchShift = 2 * AU_OCTAVE_CENTS;
    } else if (pitchShift < -2 * AU_OCTAVE_CENTS) {
        pitchShift = -2 * AU_OCTAVE_CENTS;
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
    AuResult status = au_mseq_check_player_index(index);

    if (status != AU_RESULT_OK) {
        return status;
    }
    return au_mseq_start(index, fadeInTime);
}

AuResult snd_ambient_stop_quick(s32 index) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_stop_quick(index);
    }

    return status;
}

AuResult snd_ambient_stop_slow(s32 index, s32 fadeOutTime) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_stop_slow(index, fadeOutTime);
    }

    return status;
}

AuResult snd_ambient_pause(s32 index, s32 fadeOutTime) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_pause(index, fadeOutTime);
    }

    return status;
}

AuResult snd_ambient_resume(s32 index, s32 fadeInTime) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_resume(index, fadeInTime);
    }

    return status;
}

AuResult snd_ambient_is_stopped(s32 index) {
    AuResult status = au_mseq_check_player_index(index);

    if (status != AU_RESULT_OK) {
        return status;
    }
    return au_mseq_check_stopped(index);
}

AuResult snd_ambient_fade_out(s32 index, s32 arg1) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_load_tracks_fade(index, arg1);
    }

    return status;
}

AuResult snd_ambient_set_volume(s32 index, s32 time, s32 volume) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_set_volume(index, time, volume);
    }

    return status;
}

AuResult snd_ambient_disable(s32 index) {
    AuResult status = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_set_disabled(index, true);
    }

    return status;
}

AuResult snd_ambient_enable(s32 index) {
    AuResult status  = au_mseq_check_player_index(index);

    if (status == AU_RESULT_OK) {
        au_mseq_set_disabled(index, false);
    }

    return status;
}

void snd_ambient_radio_setup(s32 index) {
    s32 radioChannels = 4;
    u32 i;

    AmbienceRadioChannel = 0xFF;

    for (i = 0; i < radioChannels; i++) {
        if (snd_ambient_play(i, 0) != AU_RESULT_OK) {
            return;
        }
    }

    snd_ambient_radio_select(index);
}

AuResult snd_ambient_radio_stop(s32 time) {
    AuResult status = AU_RESULT_OK;
    s32 radioChannels = 4;
    u32 i;

    for (i = 0; i < radioChannels; i++) {
        if (i == AmbienceRadioChannel) {
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

AuResult snd_ambient_radio_select(s32 index) {
    AuResult status = AU_RESULT_OK;
    s32 radioChannels = 4;

    if (index != AmbienceRadioChannel) {
        u32 i;

        for (i = 0; i < radioChannels; i++) {
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
            AmbienceRadioChannel = index;
        }
    }

    return status;
}

AuResult snd_song_load(s32 songID, s32 playerIndex) {
    BGMHeader* bgmFile;
    BGMPlayer* player;

    au_get_bgm_player_and_file(playerIndex, &bgmFile, &player);

    if (bgmFile != nullptr) {
        return au_load_song_files(songID, bgmFile, player);
    } else {
        return AU_ERROR_NULL_SONG_NAME;
    }
}

/// Unused -- snd_song_request_play but always uses BGM_VARIATION_0
AuResult snd_song_request_play_default(s32 songName) {
    AuResult status;
    SongStartRequest s;

    PreventBGMPlayerUpdate = true;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = AU_MAX_VOLUME_8;
    s.finalVolume = AU_MAX_VOLUME_8;
    s.variation = BGM_VARIATION_0;
    s.unused_14 = 0;
    status = au_bgm_process_init_song(&s);
    PreventBGMPlayerUpdate = false;

    return status;
}

/// Called from bgm_control to start playing a particular song + variation
AuResult snd_song_request_play(s32 songName, s32 variation) {
    AuResult status;
    SongStartRequest s;

    PreventBGMPlayerUpdate = true;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = AU_MAX_VOLUME_8;
    s.finalVolume = AU_MAX_VOLUME_8;
    s.variation = variation;
    s.unused_14 = 0;
    status = au_bgm_process_init_song(&s);
    PreventBGMPlayerUpdate = false;

    return status;
}

AuResult snd_song_stop(s32 songName) {
    return au_bgm_stop_song(songName);
}

void snd_song_stop_all(void) {
    au_bgm_stop_all();
}

AuResult snd_song_is_playing(s32 songName) {
    return au_bgm_is_song_playing(songName);
}

/// Called from bgm_control to fade in a particular song + variation
AuResult snd_song_request_fade_in(s32 songName, s32 variation, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult status;
    SongStartRequest s;

    PreventBGMPlayerUpdate = true;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = variation;
    s.unused_14 = 0;
    status = au_bgm_process_init_song(&s);
    PreventBGMPlayerUpdate = false;

    return status;
}

/// Unused
AuResult snd_song_request_fade_in_default(s32 songName, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult status;
    SongStartRequest s;

    PreventBGMPlayerUpdate = true;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = 0;
    s.unused_14 = 0;
    status = au_bgm_process_init_song(&s);
    PreventBGMPlayerUpdate = false;

    return status;
}

AuResult snd_song_request_fade_out(s32 songName, s32 fadeTime, AuCallback callback) {
    SongFadeOutRequest s;

    s.songName = songName;
    s.duration = fadeTime;
    s.unused_08 = 0;
    s.finalVolume = 0;
    s.doneCallback = callback;
    s.onPush = false;

    return au_bgm_process_fade_out(&s);
}

AuResult snd_song_push_stop(s32 songName) {
    SongSuspendRequest s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = false;

    return au_bgm_process_suspend(&s, false); // force stop
}

AuResult snd_song_request_pop(s32 songName) {
    AuResult status;
    SongResumeRequest s;

    PreventBGMPlayerUpdate = true;
    s.songName = songName;
    s.duration = 2000;
    s.startVolume = 1;
    s.finalVolume = AU_MAX_VOLUME_8;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = false;
    status = au_bgm_process_resume(&s);
    PreventBGMPlayerUpdate = false;

    return status;
}

AuResult snd_song_request_snapshot(s32 songName) {
    SongSuspendRequest s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = false;

    return au_bgm_process_suspend(&s, true); // no stop
}

AuResult snd_song_request_push_fade_out(s32 songName, s32 fadeTime) {
    SongFadeOutRequest s;

    s.songName = songName;
    s.duration = fadeTime;
    s.unused_08 = 0;
    s.finalVolume = 0;
    s.doneCallback = nullptr;
    s.onPush = true;

    return au_bgm_process_fade_out(&s);
}

AuResult snd_song_request_pause(s32 songName) {
    SongSuspendRequest s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = true;

    return au_bgm_process_suspend(&s, false); // force stop
}

AuResult snd_song_request_unpause(s32 songName) {
    SongResumeRequest s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = true;

    return au_bgm_process_resume(&s);
}

AuResult snd_song_set_volume_quiet(s32 songName) {
    SongStartRequest s;

    s.songName = songName;
    s.duration = 500;
    s.finalVolume = 0.25001 * AU_MAX_VOLUME_16;

    return au_bgm_adjust_volume(&s);
}

AuResult snd_song_set_volume_full(s32 songName) {
    SongStartRequest s;

    s.songName = songName;
    s.duration = 500;
    s.finalVolume = AU_MAX_VOLUME_16;

    return au_bgm_adjust_volume(&s);
}

AuResult snd_song_set_linked_mode(s32 songName, bool mode) {
    SongSwapLinkedRequest s;

    s.songName = songName;
    s.enabled = mode;

    return au_bgm_set_linked_tracks(&s);
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

        if (trackVols != nullptr) {
            au_bgm_set_track_volumes(bgmPlayer, trackVols, true);
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

        if (trackVols != nullptr) {
            au_bgm_set_track_volumes(bgmPlayer, trackVols, false);
        } else {
            status = AU_ERROR_11;
        }
    }

    return status;
}

static u8* snd_song_get_track_volumes_set(MusicTrackVols trackVolSet) {
    u8* trackVols = nullptr;

    switch (trackVolSet) {
        case TRACK_VOLS_JAN_FULL:
            trackVols = TrackVols_JAN_Full;
            break;
        case TRACK_VOLS_UNUSED_1:
            trackVols = TrackVols_Unused1;
            break;
        case TRACK_VOLS_TIK_SHIVER:
            trackVols = TrackVols_TIK_Shiver;
            break;
        case TRACK_VOLS_UNUSED_3:
            trackVols = TrackVols_Unused3;
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

static AuResult snd_song_change_track_volume(s32 songName, u32 trackIdx, u32 volume) {
    BGMPlayer* bgmPlayer;
    BGMHeader* bgmFile;
    AuResult status;

    status = snd_song_get_playing_info(songName, &bgmFile, &bgmPlayer);
    if (status == AU_RESULT_OK) {
        if (volume > AU_MAX_VOLUME_8) {
            volume = AU_MAX_VOLUME_8;
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
    return snd_song_change_track_volume(songName, trackIdx, AU_MAX_VOLUME_8 / 2);
}

AuResult snd_song_set_track_vol_full(s32 songName, s32 trackIdx) {
    return snd_song_change_track_volume(songName, trackIdx, AU_MAX_VOLUME_8);
}

void snd_song_set_proximity_mix_far(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix);
}

void snd_song_set_proximity_mix_near(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix | ((s32)(0.69f * AU_MAX_VOLUME_8) << 24));
}

void snd_song_set_proximity_mix_full(s32 songName, s32 mix) {
    au_bgm_set_proximity_mix(songName, (u8)mix | (AU_MAX_VOLUME_8 << 24));
}

void snd_song_poll_music_events(MusicEventTrigger** musicEvents, s32* count) {
    AuGlobals* globals = gSoundGlobals;

    *musicEvents = globals->musicEventQueue;
    *count = globals->musicEventQueueCount;
}

void snd_song_flush_music_events(void) {
    gSoundGlobals->flushMusicEventQueue = true;
}

void snd_song_trigger_music_event(s32 playerID, s32 trackIndex, s32 eventInfo) {
    AuGlobals* globals = gSoundGlobals;

    if (globals->musicEventQueueCount < MUS_QUEUE_SIZE) {
        *globals->musicEventQueuePos++ = ((playerID << 28) + ((trackIndex & 0xF) << 24) + eventInfo);
        globals->musicEventQueueCount++;
    }
}

void snd_song_clear_music_events(void) {
    AuGlobals* globals = gSoundGlobals;
    s32* buf = globals->musicEventQueue;
    s32 i = 15;

    do {
        *buf++ = 0;
    } while (i-- != 0);

    globals->musicEventQueueCount = 0;
    globals->flushMusicEventQueue = false;
    globals->musicEventQueuePos = globals->musicEventQueue;
}

static const f32 padding[] = {0.0f};

void snd_register_callback(AuCallback func, s32 index) {
    gSoundGlobals->audioThreadCallbacks[index] = func;
}

void snd_set_stereo(void) {
    au_set_stereo_enabled(true);
    au_sync_channel_delay_enabled(0);
}

void snd_set_mono(void) {
    au_set_stereo_enabled(false);
    au_sync_channel_delay_enabled(1);
}

void snd_set_bgm_volume(VolumeLevels volume) {
    au_set_bus_volume_level(AUDIO_TYPE_BGM, volume);
}

void snd_set_sfx_volume(VolumeLevels volume) {
    au_set_bus_volume_level(AUDIO_TYPE_SFX, volume);
}

void snd_set_sfx_reverb_type(s32 reverbType) {
    au_set_reverb_type(AUDIO_TYPE_SFX, reverbType);
}

void snd_enable_sfx(void) {
    au_sfx_set_state(gSoundManager, SND_MANAGER_STATE_ENABLED);
}

void snd_disable_sfx(void) {
    au_sfx_set_state(gSoundManager, SND_MANAGER_STATE_DISABLED);
}
