#include "common.h"

API_CALLABLE(PollMusicEvents);

extern MusicEvent* MusicEventList;
extern Evt* RunningMusicEvents[10];
extern s32 RunningMusicEventIDs[10];

s32 MusicEventPollCount = 0;

static EvtScript EVS_MusicEventMonitor = {
    Call(PollMusicEvents)
    Return
    End
};

API_CALLABLE(PollMusicEvents) {
    MusicEventTrigger* list;
    s32 musicEventID, scriptSelector;
    u32 count;
    s32 i;

    bgm_poll_music_events(&list, &count);

    for (i = 0; i < count; i++, list++) {
        MusicEvent* cur = MusicEventList;
        musicEventID = (*list & 0xFF0000) >> 0x10;
        scriptSelector = *list & 0xFF;
        while (cur->musicEventID != -1) {
            if (cur->musicEventID == musicEventID) {
                break;
            }
            cur++;
        }
        /// @bug? can cur ever be NULL here?
        /// condition should probably be if (cur->musicEventID != -1)
        if (cur != NULL) {
            EvtScript* newSource = cur->scripts[scriptSelector];
            if (RunningMusicEvents[musicEventID] != NULL) {
                kill_script_by_ID(RunningMusicEventIDs[musicEventID]);
            }
            if (newSource != NULL) {
                Evt* newEvt = start_script(newSource, EVT_PRIORITY_1, 0);
                RunningMusicEvents[musicEventID] = newEvt;
                RunningMusicEventIDs[musicEventID] = newEvt->id;
            }
        }
    }
    bgm_flush_music_events();
    MusicEventPollCount++;
    return ApiStatus_BLOCK;
}

API_CALLABLE(RegisterMusicEvents) {
    Bytecode* args = script->ptrReadPos;
    s32 i;

    // expects a list of MusicEvent, terminated by -1 0 0 0 0
    MusicEventList = (MusicEvent*) evt_get_variable(script, *args++);

    for (i = 0; i < ARRAY_COUNT(RunningMusicEvents); i++) {
        RunningMusicEvents[i] = NULL;
        RunningMusicEventIDs[i] = 0;
    }

    start_script(&EVS_MusicEventMonitor, EVT_PRIORITY_1, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(FadeOutMusic) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 fadeTime = evt_get_variable(script, *args++);

    if (bgm_set_song(musicPlayer, -1, 0, fadeTime, 8)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(SetMusicTrack) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);
    s16 volume = evt_get_variable(script, *args++);

    if (bgm_set_song(musicPlayer, songID, variation, 500, volume)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(FadeInMusic) {
    Bytecode* args = script->ptrReadPos;
    s32 musicPlayer = evt_get_variable(script, *args++);
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);
    s32 fadeTime = evt_get_variable(script, *args++);
    s16 fadeStartVolume = evt_get_variable(script, *args++);
    s16 fadeEndVolume = evt_get_variable(script, *args++);

    if (func_8014A964(musicPlayer, songID, variation, fadeTime, fadeStartVolume, fadeEndVolume)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(EnableMusicProximityMix) {
    Bytecode* args = script->ptrReadPos;
    s32 playerIndex = evt_get_variable(script, *args++);

    gMusicSettings[playerIndex].flags |= MUSIC_SETTINGS_FLAG_ENABLE_PROXIMITY_MIX;
    return ApiStatus_DONE2;
}

API_CALLABLE(AdjustMusicProximityMix) {
    Bytecode* args = script->ptrReadPos;
    s32 playerIndex = evt_get_variable(script, *args++);
    s32 mix = evt_get_variable(script, *args++);
    s32 state = evt_get_variable(script, *args++);

    bgm_adjust_proximity(playerIndex, mix, state);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetMusicTrackVolumes) {
    Bytecode* args = script->ptrReadPos;
    s16 trackVolSet = evt_get_variable(script, *args++);

    bgm_set_track_volumes(0, trackVolSet);
    return ApiStatus_DONE2;
}

API_CALLABLE(PopSong) {
    bgm_pop_song();
    return ApiStatus_DONE2;
}

API_CALLABLE(PushSong) {
    Bytecode* args = script->ptrReadPos;
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);

    bgm_push_song(songID, variation);
    return ApiStatus_DONE2;
}

API_CALLABLE(PopBattleSong) {
    bgm_pop_battle_song();
    return ApiStatus_DONE2;
}

API_CALLABLE(PushBattleSong) {
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleSong) {
    Bytecode* args = script->ptrReadPos;
    s32 songID = evt_get_variable(script, *args++);
    s32 variation = evt_get_variable(script, *args++);

    bgm_set_battle_song(songID, variation);
    return ApiStatus_DONE2;
}

API_CALLABLE(ClearAmbientSounds) {
    Bytecode* args = script->ptrReadPos;
    s32 time = evt_get_variable(script, *args++);

    if (play_ambient_sounds(-1, time)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(PlayAmbientSounds) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    if (play_ambient_sounds(soundID, 250)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(PlaySound) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    sfx_play_sound(soundID);
    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundWithVolume) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 volume = evt_get_variable(script, *args++);

    sfx_play_sound_with_params(soundID, volume, 0, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundAt) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);
    s32 flags = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sfx_play_sound_at_position(soundID, flags, x, y, z);
    return ApiStatus_DONE2;
}

API_CALLABLE(StopSound) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    sfx_stop_sound(soundID);
    return ApiStatus_DONE2;
}

API_CALLABLE(StopTrackingSoundPos) {
    Bytecode* args = script->ptrReadPos;
    s32 soundID = evt_get_variable(script, *args++);

    snd_stop_tracking_env_sound_pos(soundID, TRUE);
    return ApiStatus_DONE2;
}

API_CALLABLE(UseDoorSounds) {
    Bytecode* args = script->ptrReadPos;

    gCurrentDoorSounds = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(UseRoomDoorSounds) {
    Bytecode* args = script->ptrReadPos;

    gCurrentRoomDoorSounds = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundAtF) {
    Bytecode* args = script->ptrReadPos;
    Bytecode soundID = *args++;
    u16 spatializationFlags = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    sfx_play_sound_at_position(soundID, spatializationFlags, x, y, z);
    return ApiStatus_DONE2;
}
