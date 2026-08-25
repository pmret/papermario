#include "audio.h"
#include "audio/core.h"

BSS void (*CurrentSeqCmdHandler)(BGMPlayer*, BGMPlayerTrack*);

extern u8 EnvelopeReleaseDefaultFast[];
extern u8 BgmTicksRates[8];
extern u8 BgmCustomEnvLookup[40];

extern void (*SefCmdHandlers[])(SoundManager*, SoundPlayer*);
extern void (*SeqCmdHandlers[])(BGMPlayer*, BGMPlayerTrack*);
extern u8 SeqCmdArgCounts[];

static void au_bgm_stop_player(BGMPlayer* player);

static s32 au_bgm_bpm_to_tempo(BGMPlayer* player, u32 tempo);

static u8 au_bgm_get_random_pan(BGMPlayer* player, u8 arg1, u8 arg2);
static s16 au_bgm_get_random_pitch(s32 arg0, s32 arg1, u8 arg2);
static u8 au_bgm_get_random_vol(s32 arg0, u8 volume, u8 arg2);
static u8 au_bgm_get_random_reverb(s32 arg0, u8 arg1, u8 arg2);

void au_bgm_begin_video_frame(BGMPlayer* player) {
    BGMHeader* bgmFile;
    BGMFileInfo* bgmData;
    s32 unkType;
    u32 compID;
    s32 compOffset;
    u32 value;
    s32 consumed;
    u8 var_a1;
    u8 pos;
    u32 i;

    compID = 0;
    unkType = -1;
    player->frameCounter++;

    if (player->cmdBufPending != 0) {
        if (player->cmdBufPending < ARRAY_COUNT(player->cmdBufData)) {
            pos = player->cmdBufReadPos;
            for (var_a1 = 0; var_a1 < player->cmdBufPending; var_a1++) {
                value = player->cmdBufData[pos];
                if (value != 0) {
                    if (value < 16) {
                        unkType = value & 3;
                        compID = value >> 2;
                    }
                    pos++;
                    if (pos >= ARRAY_COUNT(player->cmdBufData)) {
                        pos = 0;
                    }
                }
            }
            consumed = player->cmdBufWritePos - player->cmdBufReadPos;
            if (consumed < 0) {
                consumed += ARRAY_COUNT(player->cmdBufData);
            }
            player->cmdBufPending -= consumed;
            player->cmdBufReadPos = player->cmdBufWritePos;
        } else {
            player->cmdBufPending = 0;
        }

        if (unkType != -1) {
            if (unkType != 0) {
                if (unkType != player->unk_58) {
                    player->unk_58 = unkType & 0xFF;
                    player->unk_5A = unkType & 0xFF;
                    player->masterState = BGM_PLAY_STATE_INIT;
                    player->nextUpdateStep = BGM_DEFAULT_UPDATE_STEP;
                    if (unkType == 2) {
                        bgmFile = player->globals->dataBGM[1];
                    } else {
                        bgmFile = player->globals->dataBGM[0];
                    }
                    player->bgmFile = bgmFile;
                    bgmData = &bgmFile->info;
                    au_bgm_set_tick_resolution(player, BGM_DEFAULT_UPDATE_STEP, BgmTicksRates[*(player->tickRatePtr) & 7]);

                    compOffset = bgmData->compositions[compID];
                    if (compOffset == 0) {
                        compOffset = bgmData->compositions[0];
                    }
                    player->compStartPos = AU_FILE_RELATIVE(bgmFile, compOffset << 2);
                    player->compReadPos = AU_FILE_RELATIVE(bgmFile, compOffset << 2);

                    if (bgmData->drums != 0) {
                        player->drumsInfo = AU_FILE_RELATIVE(player->bgmFile, bgmData->drums << 2);
                        player->bgmDrumCount = bgmData->drumCount;
                        for (i = 0; i < player->bgmDrumCount; i++) {
                            BGMDrumInfo* drum = &player->drumsInfo[i];
                            player->drums[i] = drum;
                        }
                        for (; i < ARRAY_COUNT(player->drums); i++) {
                            player->drums[i] = player->drums[0];
                        }
                    } else {
                        player->drumsInfo = nullptr;
                        player->bgmDrumCount = 0;
                    }

                    if (bgmData->instruments != 0) {
                        player->instrumentsInfo = AU_FILE_RELATIVE(player->bgmFile, bgmData->instruments << 2);
                        player->bgmInstrumentCount = bgmData->instrumentCount;
                        return;
                    }
                    player->instrumentsInfo = nullptr;
                    player->bgmInstrumentCount = 0;
                }
            } else {
                if (player->unk_58 != 0) {
                    player->masterState = BGM_PLAY_STATE_STOP;
                    player->nextUpdateCounter = 1;
                    player->nextUpdateStep = 1;
                } else {
                    au_bgm_stop_player(player);
                }
            }
        }
    }
}

BGMPlayer* au_bgm_get_player_with_song_name(s32 songString) {
    if (songString != gBGMPlayerA->globals->dataBGM[0]->name) {
        if (songString == gBGMPlayerA->globals->dataBGM[1]->name) {
            return gBGMPlayerB;
        }
    } else {
        return gBGMPlayerA;
    }
    return nullptr;
}

AuResult au_bgm_process_init_song(SongStartRequest* request) {
    BGMPlayer* player;
    BGMFileInfo* fileInfo;
    s32 songName;
    s32 variation;
    s32 duration;
    s32 volume0;
    s32 volume1;
    AuResult status;
    u32 i;

    status = AU_RESULT_OK;
    songName = request->songName;
    variation = request->variation;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != nullptr) {
            fileInfo = &player->bgmFile->info;
            duration = request->duration;
            if (duration != 0) {
                if (duration > SND_MAX_DURATION) {
                    duration = SND_MAX_DURATION;
                } else if (duration < SND_MIN_DURATION) {
                    duration = SND_MIN_DURATION;
                }
            }
            volume0 = request->startVolume;
            if (volume0 > AU_MAX_VOLUME_8) {
                volume0 = AU_MAX_VOLUME_8;
            }
            if (volume0 != 0) {
                volume0 = AU_VOL_8_TO_16(volume0);
            }
            volume1 = request->finalVolume;
            if (volume1 > AU_MAX_VOLUME_8) {
                volume1 = AU_MAX_VOLUME_8;
            }
            if (volume1 != 0) {
                volume1 = AU_VOL_8_TO_16(volume1);
            } else {
                volume1 = AU_MAX_VOLUME_16;
            }

            au_fade_init(&player->fadeInfo, duration, volume0, volume1);
            player->fadeInfo.envelopeTarget = AU_MAX_VOLUME_16;
            player->fadeInfo.envelopeTicks = 1;
            au_bgm_set_tick_resolution(player, BGM_DEFAULT_UPDATE_STEP, BgmTicksRates[fileInfo->timingPreset & 7]);

            if (variation < BGM_VARIATION_0 || variation > BGM_VARIATION_3 || fileInfo->compositions[variation] == 0) {
                variation = BGM_VARIATION_0;
            }
            player->curVariation = variation;

            player->compStartPos = AU_FILE_RELATIVE(player->bgmFile, fileInfo->compositions[variation] << 2);
            player->compReadPos = player->compStartPos;

            if (fileInfo->drums != 0) {
                player->drumsInfo = AU_FILE_RELATIVE(player->bgmFile, fileInfo->drums << 2);
                player->bgmDrumCount = fileInfo->drumCount;

                for (i = 0; i < player->bgmDrumCount; i++) {
                    BGMDrumInfo* drum = &player->drumsInfo[i];
                    player->drums[i] = drum;
                }
                for (; i < ARRAY_COUNT(player->drums); i++) {
                    player->drums[i] = player->drums[0];
                }
            } else {
                player->drumsInfo = nullptr;
                player->bgmDrumCount = 0;
            }

            if (fileInfo->instruments != 0) {
                player->instrumentsInfo = AU_FILE_RELATIVE(player->bgmFile, fileInfo->instruments << 2);
                player->bgmInstrumentCount = fileInfo->instrumentCount;
            } else {
                player->instrumentsInfo = nullptr;
                player->bgmInstrumentCount = 0;
            }

            player->songName = songName;
            au_bgm_player_initialize(player);
        } else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

AuResult au_bgm_stop_song(s32 songName) {
    BGMPlayer* player;
    AuResult status = AU_RESULT_OK;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != nullptr) {
            if (songName == player->songName) {
                au_bgm_stop_player(player);
            }
        } else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }

    return status;
}

void au_bgm_stop_all(void) {
    au_bgm_stop_player(gBGMPlayerA);
    au_bgm_stop_player(gBGMPlayerB);
}

static void au_bgm_stop_player(BGMPlayer* player) {
    if (player->masterState != BGM_PLAY_STATE_IDLE) {
        player->masterState = BGM_PLAY_STATE_STOP;
        player->nextUpdateCounter = 1;
        player->nextUpdateStep = 1;
        au_fade_clear(&player->fadeInfo);
    }
}

AuResult au_bgm_is_song_playing(s32 songName) {
    BGMPlayer* player;
    AuResult result = AU_RESULT_OK;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != nullptr) {
            result = (songName == player->songName);
        } else {
            result = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        result = AU_ERROR_NULL_SONG_NAME;
    }

    return result;
}

bool au_bgm_player_is_active(BGMPlayer* player) {
    if (player->songName != 0 && player->masterState != 0) {
        return true;
    } else {
        return false;
    }
}

AuResult au_bgm_process_fade_out(SongFadeOutRequest* request) {
    AuResult status;
    BGMPlayer* player;
    u32 songName = request->songName;
    u32 duration = request->duration;
    s16 volume = request->finalVolume;

    status = AU_RESULT_OK;
    if (songName != 0) {
        if (duration >= SND_MIN_DURATION && duration <= SND_MAX_DURATION) {
            player = au_bgm_get_player_with_song_name(songName);
            if (player != nullptr) {
                if (player->songName == songName) {
                    if (player->masterState != BGM_PLAY_STATE_IDLE) {
                        if (!player->paused) {
                            player->fadeInfo.baseTarget = volume;
                            player->fadeInfo.baseTicks = (duration * 1000) / AU_FRAME_USEC;
                            player->fadeInfo.baseStep = ((volume << 0x10) - player->fadeInfo.baseVolume) / player->fadeInfo.baseTicks;
                            player->fadeInfo.onCompleteCallback = request->doneCallback;
                            if (request->onPush == 1) {
                                player->pushSongName = songName;
                            }
                        }
                    }
                }
            } else {
                status = AU_ERROR_SONG_NOT_PLAYING;
            }
        } else {
            status = AU_ERROR_INVALID_SONG_DURATION;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

AuResult au_bgm_complete_push(s32 songName) {
    SongSuspendRequest s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.index = BGM_SNAPSHOT_0;
    s.pauseMode = false;

    return au_bgm_process_suspend(&s, 0); // force stop
}

AuResult au_bgm_process_suspend(SongSuspendRequest* request, bool skipStop) {
    AuResult status;
    BGMPlayer* player;
    BGMPlayer* snapshot;
    s32 songName;
    s32 index;
    u32 i;
    u32 j;

    songName = request->songName;
    index = request->index;
    status = AU_RESULT_OK;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != nullptr) {
            if (!request->pauseMode) {
                snapshot = au_get_snapshot_by_index(index);
                if (snapshot != nullptr) {
                    if (songName == player->songName) {
                        if (!skipStop) {
                            for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                                BGMPlayerTrack* track = &player->tracks[i];
                                if (track->bgmReadPos != nullptr) {
                                    for (j = track->firstVoice; j < track->lastVoice; j++) {
                                        track->changed.all = 0;
                                    }
                                }
                            }
                        }
                        player->globals->snapshots[index].priority = player->priority;
                        player->globals->snapshots[index].assigned = 1;
                        player->pushSongName = 0;
                        au_copy_words(player, snapshot, sizeof(*player));
                        if (!skipStop) {
                            au_bgm_stop_player(player);
                        }
                    }
                } else {
                    status = AU_ERROR_INVALID_SONG_DURATION;
                }
            } else {
                if (songName == player->songName) {
                    if (player->masterState != BGM_PLAY_STATE_IDLE) {
                        player->paused = true;
                        au_bgm_reset_all_voices(player);
                    }
                }
            }
        } else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

AuResult au_bgm_process_resume(SongResumeRequest* request) {
    AuResult status;
    BGMPlayer* player;
    BGMPlayer* snapshot;
    s32 index;
    s32 songName;
    s32 volume0;
    s32 volume1;
    s32 duration;

    songName = request->songName;
    index = request->index;
    status = AU_RESULT_OK;

    if (songName != 0) {
        if (!request->pauseMode) {
            snapshot = au_get_snapshot_by_index(index);
            if (snapshot != nullptr && snapshot->globals->snapshots[index].assigned == 1) {
                player = au_get_client_by_priority(snapshot->globals->snapshots[index].priority);
                if (player != nullptr) {
                    if (!au_bgm_player_is_active(player)) {
                        status = au_reload_song_files(snapshot->songID, snapshot->bgmFile);
                        duration = request->duration;
                        if (duration != 0) {
                            if (duration > SND_MAX_DURATION) {
                                duration = SND_MAX_DURATION;
                            } else if (duration < SND_MIN_DURATION) {
                                duration = SND_MIN_DURATION;
                            }
                        }
                        volume0 = request->startVolume;
                        if (volume0 > AU_MAX_VOLUME_8) {
                            volume0 = AU_MAX_VOLUME_8;
                        }
                        if (volume0 != 0) {
                            volume0 = AU_VOL_8_TO_16(volume0);
                        }
                        volume1 = request->finalVolume;
                        if (volume1 > AU_MAX_VOLUME_8) {
                            volume1 = AU_MAX_VOLUME_8;
                        }
                        if (volume1 != 0) {
                            volume1 = AU_VOL_8_TO_16(volume1);
                        } else {
                            volume1 = AU_MAX_VOLUME_16;
                        }
                        player->globals->resumeCopyTo = player;
                        player->globals->resumeCopyFrom = snapshot;
                        player->globals->resumeSongName = songName;
                        player->globals->resumeFadeTime = duration;
                        player->globals->resumeFadeStart = volume0;
                        player->globals->resumeFadeEnd = volume1;
                        player->globals->resumeRequested = true;
                    } else {
                        status = AU_ERROR_7;
                    }
                } else {
                    status = AU_ERROR_6;
                }
            } else {
               status = AU_ERROR_INVALID_SONG_DURATION;
            }
        } else {
            player = au_bgm_get_player_with_song_name(songName);
            if (player != nullptr) {
                if (songName == player->songName) {
                    if (player->paused) {
                        player->paused = false;
                    }
                }
            }
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

void au_bgm_restore_copied_player(AuGlobals* globals) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    SeqNote* note;
    u32 i;
    u32 j;
    s32 k;

    player = globals->resumeCopyTo;
    au_copy_words(globals->resumeCopyFrom, globals->resumeCopyTo, sizeof(*player));
    if (globals->resumeSongName == player->songName) {
        for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
            track = &player->tracks[i];
            if (track->bgmReadPos != nullptr) {
                for (j = track->firstVoice; j < track->lastVoice; j++) {
                    note = &player->notes[j];
                    note->length = 0;
                }
            }
        }
        for (k = 0; k < ARRAY_COUNT(player->effectIndices); k++) {
            if (player->effectIndices[k] != 0xFF) {
                player->seqCmdArgs.MasterEffect.index = player->effectIndices[k];
                player->seqCmdArgs.MasterEffect.value = player->effectValues[k];
                au_BGMCmd_E6_MasterEffect(player, track);
            }
        }
        au_fade_init(&player->fadeInfo, globals->resumeFadeTime, globals->resumeFadeStart, globals->resumeFadeEnd);
    }
    globals->resumeRequested = false;
}

AuResult au_bgm_adjust_volume(SongStartRequest* request) {
    BGMPlayer* player;
    AuResult status = AU_RESULT_OK;

    if (request->songName != 0) {
        player = au_bgm_get_player_with_song_name(request->songName);
        if (player != nullptr) {
            au_fade_calc_envelope(&player->fadeInfo, request->duration, request->finalVolume);
        }
        else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

void au_bgm_player_init(BGMPlayer* player, s32 priority, s32 busID, AuGlobals* globals) {
    s16 i;

    player->globals = globals;
    au_bgm_set_tick_resolution(player, BGM_DEFAULT_UPDATE_STEP, BGM_DEFAULT_TICKS_PER_BEAT);
    player->busVolume = AU_MAX_BUS_VOLUME;
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterVolume = AU_MAX_VOLUME_8 << 24;
    player->frameCounter = 0;
    player->songPlayingCounter = 0;
    player->songName = 0;
    player->pushSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    player->compReadPos = nullptr;
    player->compStartPos = nullptr;
    player->phraseStartPos = 0;
    player->masterTempoTicks = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
    player->masterVolumeTicks = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->masterPitchShift = 0;
    player->detune = 0;
    player->paused = false;
    player->trackVolsConfig = nullptr;
    player->bFadeConfigSetsVolume = false;
    player->masterState = BGM_PLAY_STATE_IDLE;
    player->priority = priority;
    player->busID = busID;
    *(s32*)player->compLoopCounters = 0;
    player->unused_222 = 0;
    player->conditionalLoopFlags = 0;
    player->playbackRate = 1.0f;
    player->polyphonyCounts[BGM_POLYPHONY_0] = 0;
    player->polyphonyCounts[BGM_POLYPHONY_1] = 1;
    player->polyphonyCounts[BGM_POLYPHONY_UNUSED_A] = 0;
    player->polyphonyCounts[BGM_POLYPHONY_UNUSED_B] = 0;
    player->polyphonyCounts[BGM_POLYPHONY_UNUSED_C] = 0;
    player->polyphonyCounts[BGM_POLYPHONY_2] = 2;
    player->polyphonyCounts[BGM_POLYPHONY_3] = 3;
    player->polyphonyCounts[BGM_POLYPHONY_4] = 4;

    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        BGMPlayerTrack* track = &player->tracks[i];

        track->insVolume = 0;
        track->delayTime = 0;
        track->insCoarseDetune = 0;
        track->insFineDetune = 0;
        track->insPan = 0;
        track->insReverb = 0;
        track->patch = 0;
        track->isDrumTrack = false;
        track->volume = AU_MAX_VOLUME_8;
        track->pressOverride = 0;

        if (i < ARRAY_COUNT(player->cmdBufData)) {
            player->cmdBufData[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(player->notes); i++) {
        SeqNote* note = &player->notes[i];

        note->volume = 0;
        note->detune = 0;
        note->length = 0;
        note->randDetune = 0;
        note->velocity = 0;
        note->pendingTick = false;
    }

    au_fade_set_envelope(&player->fadeInfo, AU_MAX_VOLUME_16);
    snd_bgm_clear_legacy_commands(player);
}

void au_bgm_set_effect_indices(BGMPlayer* player, u8* list) {
    s32 i;
    s32 remaining;

    for (i = 0; i < ARRAY_COUNT(player->effectIndices); i++) {
        s8 idx = *list++;

        if (idx < 0) {
            break;
        }
        player->effectIndices[i] = idx;
    }

    remaining = ARRAY_COUNT(player->effectIndices) - i;
    if (remaining > 0) {
        while (remaining-- != 0) {
            player->effectIndices[i++] = -1;
        }
    }
}

void au_bgm_update_fade(BGMPlayer* player) {
    player->fadeInfo.baseTicks--;

    if (player->fadeInfo.baseTicks != 0) {
        player->fadeInfo.baseVolume += player->fadeInfo.baseStep;
    } else {
        player->fadeInfo.baseVolume = player->fadeInfo.baseTarget << 16;

        if (player->fadeInfo.onCompleteCallback != nullptr) {
            player->fadeInfo.onCompleteCallback();
        }

        // Was this fade tagged as a push?
        if (player->pushSongName != 0) {
            au_bgm_complete_push(player->pushSongName);
        } else if (player->fadeInfo.baseVolume == 0) {
            au_bgm_stop_player(player);
        }
    }
    au_bgm_update_bus_volumes(player);
}

void au_bgm_update_bus_volumes(BGMPlayer* player) {
    u16 volume = (
            ((u32)player->fadeInfo.baseVolume >> 16) *
            ((u32)player->fadeInfo.envelopeVolume >> 16)
        ) >> 15;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(player->effectIndices); i++) {
        s8 busID = player->effectIndices[i];

        if (busID < 0) {
            return;
        }
        au_fade_set_volume(busID, volume, player->busVolume);
    }
}

s32 au_bgm_player_audio_frame_update(BGMPlayer* player) {
    u16 hasMore = true;
    s32 retVal = false;

    // update pseudorandom numbers with fast 'good enough' method
    player->randomValue1 = (player->randomValue1 & 0xFFFF) + (player->songPlayingCounter & 0xFFFF) + (player->frameCounter & 0xFFFF);
    player->randomValue2 = (player->randomValue2 & 0xFFFF) + ((player->songPlayingCounter << 4) & 0xFFFF) + ((player->frameCounter >> 4) & 0xFFFF);
    do {
        switch (player->masterState) {
            case BGM_PLAY_STATE_IDLE:
                hasMore = false;
                break;
            case BGM_PLAY_STATE_ACTIVE:
                if (!player->paused) {
                    au_bgm_player_update_playing(player);
                    if (player->masterState == BGM_PLAY_STATE_ACTIVE) {
                        hasMore = false;
                    }
                } else {
                    hasMore = false;
                }
                break;
            case BGM_PLAY_STATE_FETCH:
                au_bgm_player_read_composition(player);
                break;
            case BGM_PLAY_STATE_INIT:
                au_bgm_player_initialize(player);
                hasMore = false;
                break;
            case BGM_PLAY_STATE_STOP:
                au_bgm_player_update_stop(player);
                break;
            default:
                retVal = true;
                hasMore = false;
                break;
        }
    } while (hasMore);
    return retVal;
}

void au_bgm_player_initialize(BGMPlayer* player) {
    s32* buf;
    s32 cmd;
    s32 keepReading;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        BGMPlayerTrack* track = &player->tracks[i];
        track->instrument = NO_INSTRUMENT;
        track->insVolume = AU_MAX_VOLUME_16 << 16; // @bug? incorrect format for 8.24 fixed, should be (AU_MAX_VOLUME_8 << 24)
        track->insPan = 0x40;
        track->insReverb = 0;
        track->patch = 0;
        track->insCoarseDetune = 0;
        track->insFineDetune = 0;
        track->volume = AU_MAX_VOLUME_8;
        track->pressOverride = 0;
        track->proxVolume = AU_MAX_VOLUME_16 << 16;
        track->savedPos = nullptr;
        track->prevReadPos = nullptr;
        track->detourLength = 0;
        track->detune = 0;
        track->tremoloDepth = 0;
        track->tremoloDelay = 0;
        track->tremoloRate = 0;
        track->insVolumeStep = 0;
        track->insVolumeTarget = 0;
        track->insVolumeTicks = 0;
        track->proxVolumeStep = 0;
        track->proxVolumeTarget = 0;
        track->proxVolumeTicks = 0;
        track->proxMixSetChanged = false;
        track->proxMixValChanged = false;
        track->proxVol1 = 0;
        track->proxVol2 = 0;
        track->polyVoiceCount = 0;
        track->polyphonicIdx = 0;
        track->randomPanAmount = 0;
        track->isDrumTrack = false;
        track->linkedTrackID = 0;
        track->muted = false;
        track->busID = player->busID;
        track->index = i;
    }

    for (i = 0; i < ARRAY_COUNT(player->notes); i++) {
        SeqNote* note = &player->notes[i];
        note->ins = NO_INSTRUMENT;
        note->pitchRatio = 2.0f;
        note->randDetune = 0;
        note->velocity = 0;
        note->length = 0;
        note->tremoloDepth = 0;
    }

    au_bgm_reset_all_voices(player);
    player->playbackRate = 128.0f; // set to 1.0 later om...
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterTempoBPM = BGM_DEFAULT_BPM;
    player->unused_21E = 0x80;
    player->masterVolume = AU_MAX_VOLUME_8 << 24;
    player->pushSongName = 0;
    player->tickRatePtr = nullptr;
    player->masterTempoTarget = 0;
    player->masterPitchShift = 0;
    player->detune = 0;
    player->masterVolumeTicks = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->proxMixValue = 0;
    player->proxMixID = 0;
    player->proxMixVolume = 0;
    player->compActiveLoopEndPos[3] = nullptr;
    player->compActiveLoopEndPos[2] = nullptr;
    player->compActiveLoopEndPos[1] = nullptr;
    player->compActiveLoopEndPos[0] = nullptr;
    *(s32*)player->compLoopCounters = 0;
    player->compLoopDepth = 0;
    player->unused_222 = 0;
    player->conditionalLoopFlags = 0;
    player->trackVolsConfig = nullptr;
    player->bFadeConfigSetsVolume = false;
    player->initLinkMute = true;
    player->writingCustomEnvelope = 0;
    player->playbackRate = 1.0f;

    for (i = 0; i < ARRAY_COUNT(player->customEnvelopeWritePos); i++) {
        au_bgm_clear_custom_note_press(player, i);
    }

    for (i = 0; i < ARRAY_COUNT(player->effectValues); i++) {
        player->effectValues[i] = 0;
    }

    player->paused = false;
    player->songPlayingCounter = 0;
    for (i = 0; i < ARRAY_COUNT(player->compLoopStartLabels); i++) {
        player->compLoopStartLabels[i] = player->compReadPos;
    }

    // find labels
    buf = player->compReadPos;
    keepReading = true;
    while (keepReading) {
        cmd = *buf++;
        if (cmd == 0) {
            keepReading = false;
        } else if ((cmd & 0xF0000000) == BGM_COMP_START_LOOP << 28) {
            player->compLoopStartLabels[cmd & 0x1F] = buf;
        }
    }

    player->masterState = BGM_PLAY_STATE_FETCH;
}

void au_bgm_clear_custom_note_press(BGMPlayer* player, s32 index) {
    s32 i;
    u16* pos = player->customPressEnvelopes[index];
    player->customEnvelopeWritePos[index] = 0;

    for (i = 0; i < 9; i++) {
        *pos++ = 0xFF00;
    }
}

void au_bgm_set_tick_resolution(BGMPlayer* player, s32 mBeatsPerMinute, u32 ticksPerBeat) {
    // compute how many audio frames before the next tick
    u32 mFramesPerTick = BGM_MFRAMES_PER_MINUTE / ticksPerBeat;

    // Clamp samples per tick to stay in a valid range
    if (mFramesPerTick > 500000) {
        mFramesPerTick = 500000;
    } else if (mFramesPerTick < 80000) {
        mFramesPerTick = 80000;
    }

    // Clamp to sample rate
    if (mFramesPerTick < mBeatsPerMinute) {
        mBeatsPerMinute = mFramesPerTick;
    }

    // breakdown of units:
    //
    //     tickUpdateInterval     /   nextUpdateStep   =  framesPerTick
    //
    //   1000 x frames    beat              min           frames
    //   ------------- x ------   x   ---------------  =  ------
    //       min          tick          1000 x beat        tick

    player->nextUpdateStep = mBeatsPerMinute;
    player->tickUpdateInterval = mFramesPerTick;
    player->nextUpdateCounter = mFramesPerTick;

    player->maxTempo = mFramesPerTick / BGM_UPDATE_SCALE;
}

// runs whenever a new composition begins playing
void au_bgm_player_read_composition(BGMPlayer* player) {
    u16 continueReading = true;
    u32 cmd;

    player->masterTempoStep = 0;
    player->masterTempoTicks = 0;

    while (continueReading) {
        cmd = *player->compReadPos++;
        if (cmd == BGM_COMP_END) {
            player->masterState = BGM_PLAY_STATE_STOP;
            continueReading = false;
        } else {
            switch (cmd >> 12) {
                case BGM_COMP_PLAY_PHRASE << 16:
                    au_bgm_load_phrase(player, cmd);
                    player->masterState = BGM_PLAY_STATE_ACTIVE;
                    continueReading = false;
                    break;
                case BGM_COMP_START_LOOP << 16:
                    break;
                case BGM_COMP_WAIT << 16:
                    continueReading = false;
                    break;
                case BGM_COMP_END_LOOP << 16:
                    au_bgm_end_composition_loop(player, cmd);
                    break;
                case BGM_COMP_END_COND_LOOP_FALSE << 16:
                    if (!(player->conditionalLoopFlags & 1)) {
                        au_bgm_end_composition_loop(player, cmd);
                    }
                    break;
                case BGM_COMP_END_COND_LOOP_TRUE << 16:
                    if (player->conditionalLoopFlags & 1) {
                        au_bgm_end_composition_loop(player, cmd);
                    }
                    break;
                default:
                    continueReading = false;
                    break;
            }
        }
    }
}

void au_bgm_end_composition_loop(BGMPlayer* player, u32 cmd) {
    s32 labelIndex = cmd & 0x1F; // 01F (bits 0-4)
    s32 iterCount = (cmd >> 5) & 0x7F; // FE0 (bits 5-11)
    u32 depth;

    depth = player->compLoopDepth;
    if (player->compActiveLoopEndPos[depth] != nullptr) {
        if (player->compActiveLoopEndPos[depth] == player->compReadPos) {
            if (player->compLoopCounters[depth] != 0) {
                player->compLoopCounters[depth]--;
                if ((player->compLoopCounters[depth]) == 0) {
                    player->compActiveLoopEndPos[depth] = nullptr;
                    if (depth > 0) {
                        depth--;
                    }
                } else {
                    player->compReadPos = player->compLoopStartLabels[labelIndex];
                }
            } else {
                player->compReadPos = player->compLoopStartLabels[labelIndex];
            }
        } else if (depth < 4) {
            depth++;
            player->compActiveLoopEndPos[depth] = player->compReadPos;
            player->compLoopCounters[depth] = iterCount;
            player->compReadPos = player->compLoopStartLabels[labelIndex];
        }
    } else {
        player->compActiveLoopEndPos[depth] = player->compReadPos;
        player->compLoopCounters[depth] = iterCount;
        player->compReadPos = player->compLoopStartLabels[labelIndex];
    }
    player->compLoopDepth = depth;
}

void au_bgm_load_phrase(BGMPlayer* player, u32 cmd) {
    BGMPlayerTrack* track;
    u32 trackInfo;
    s32* trackList;
    u32 linkedID;
    s32 count;
    s32 curVoice;
    s32 bFoundLinkedTrack;
    s32 i;

    curVoice = 0;
    bFoundLinkedTrack = false;
    player->phraseStartPos = AU_FILE_RELATIVE(player->compStartPos, (cmd & 0xFFFF) << 2);
    trackList = player->phraseStartPos;
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        trackInfo = *trackList++;
        track->bgmReadPos = (AuFilePos) (trackInfo >> 0x10);
        if (track->bgmReadPos != nullptr) {
            if ((trackInfo & 0x100) == 0) {
                track->polyphonicIdx = (trackInfo & (0x7 << 0xD)) >> 0xD;
                track->isDrumTrack = (trackInfo >> 7) & 1;
                linkedID = (trackInfo & (0xF << 9)) >> 9;
                track->linkedTrackID = 0;
                if (linkedID != 0) {
                    BGMPlayerTrack* linkedTrack = &player->tracks[linkedID - 1];
                    if ((linkedID - 1) < i) {
                        track->polyVoiceCount = linkedTrack->polyVoiceCount;
                        track->firstVoice = linkedTrack->firstVoice;
                        track->lastVoice = linkedTrack->lastVoice;

                        track->bgmReadPos = (track->bgmReadPos + (s32)player->phraseStartPos);
                        track->delayTime = 1;

                        track->linkedTrackID = linkedID;
                        if (player->initLinkMute) {
                            track->muted = true;
                        }
                        bFoundLinkedTrack = true;
                    } else {
                        track->bgmReadPos = nullptr;
                    }
                } else {
                    count = player->polyphonyCounts[track->polyphonicIdx];
                    track->polyVoiceCount = count;
                    track->firstVoice = curVoice;
                    curVoice += count;
                    track->lastVoice = curVoice;

                    track->bgmReadPos = (track->bgmReadPos + (s32)player->phraseStartPos);
                    track->delayTime = 1;
                }
            } else {
                track->bgmReadPos = nullptr;
            }
        }
    }
    player->totalVoices = curVoice;
    if (bFoundLinkedTrack) {
        player->initLinkMute = false;
    }
}

void au_bgm_player_update_stop(BGMPlayer* player) {
    s32 i;

    player->paused = false;
    player->songName = 0;
    player->pushSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        player->tracks[i].bgmReadPos = nullptr;
    }
    au_bgm_reset_all_voices(player);
    player->masterState = BGM_PLAY_STATE_IDLE;
    player->nextUpdateStep = BGM_DEFAULT_UPDATE_STEP;
}

#define POST_BGM_READ() \
if (track->detourLength != 0) {\
    track->detourLength--;\
    if (track->detourLength == 0) {\
        track->bgmReadPos = track->savedPos;\
    }\
}

/// play next tick
void au_bgm_player_update_playing(BGMPlayer *player) {
    s32 bVolumeFading;
    u8 sp1F;
    s16 notePitch;
    u8 bFinished;

    AuVoice* voice;
    BGMDrumInfo* drumInfo;
    BGMPlayerTrack* track;
    SeqNote* note;
    s32 var_a0;
    s32 temp;
    s32 tremoloDetune;
    s32 bAcquiredVoiceIdx;
    u8 opcode;
    u8 noteVelocity;
    s32 noteLength;
    u32 i;
    u8 voiceIdx;
    s32 temp2;
    bVolumeFading = false;
    bFinished = false;

    if (player->masterTempoTicks != 0) {
        player->masterTempoTicks--;
        if (player->masterTempoTicks == 0) {
            player->masterTempo = player->masterTempoTarget;
            player->masterTempoTarget = 0;
            player->masterTempoStep = 0;
        } else {
            player->masterTempo += player->masterTempoStep;
        }
        player->nextUpdateStep = BGM_TEMPO_TO_UPDATE_UNITS(player->masterTempo);
    }
    if (player->masterVolumeTicks != 0) {
        player->masterVolumeTicks--;
        if (player->masterVolumeTicks == 0) {
            player->masterVolume = player->masterVolumeTarget;
            player->masterVolumeTarget = 0;
            player->masterVolumeStep = 0;
        } else {
            player->masterVolume += player->masterVolumeStep;
        }
        bVolumeFading = true;
    }
    player->volumeChanged = false;
    if (player->trackVolsConfig != nullptr) {
        if (player->bFadeConfigSetsVolume) {
            // setting track volumes
            s32 lenLimit = 16;
            while (lenLimit-- != 0) {
                i = *player->trackVolsConfig++;
                if (i == 0) {
                    break;
                }
                track = &player->tracks[i - 1];
                player->seqCmdArgs.TrackVolumeFade.time = 48;
                player->seqCmdArgs.TrackVolumeFade.value = *(player->trackVolsConfig++);
                if (track->bgmReadPos != 0) {
                    au_BGMCmd_F6_InstrumentVolumeLerp(player, track);
                }
            }
        }
        else {
            // clearing track volumes
            s32 lenLimit = 16;
            while (lenLimit-- != 0) {
                i = *player->trackVolsConfig++;
                if (i == 0) {
                    break;
                }
                track = &player->tracks[i - 1];
                player->seqCmdArgs.TrackVolumeFade.time = 48;
                player->trackVolsConfig++; // ignore arg
                player->seqCmdArgs.TrackVolumeFade.value = 0;
                if (track->bgmReadPos != 0) {
                    au_BGMCmd_F6_InstrumentVolumeLerp(player, track);
                }
            }
        }
        player->trackVolsConfig = nullptr;
        player->bFadeConfigSetsVolume = false;
    }
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        if (track->bgmReadPos != nullptr) {
            track->changed.all = 0;
            if (bVolumeFading || player->volumeChanged) {
                track->changed.volume = true;
            } else {
                track->changed.volume = false;
            }
            if (track->insVolumeTicks != 0) {
                track->insVolumeTicks--;
                if (track->insVolumeTicks == 0) {
                    track->insVolume = track->insVolumeTarget;
                } else {
                    track->insVolume += track->insVolumeStep;
                }
                track->changed.volume = true;
            }
            if (track->proxVolumeTicks != 0) {
                track->proxVolumeTicks--;
                if (track->proxVolumeTicks == 0) {
                    track->proxVolume = track->proxVolumeTarget << 16;
                } else {
                    track->proxVolume += track->proxVolumeStep;
                }
                track->changed.volume = true;
            }
            track->delayTime--;
            if (track->delayTime <= 0) {
                sp1F = track->firstVoice;
                while (track->delayTime == 0) {
                    opcode = *(track->bgmReadPos++);
                    POST_BGM_READ();

                    if (opcode < 0x80) {
                        if (opcode == 0) {
                            if (track->prevReadPos != 0) {
                                track->bgmReadPos = track->prevReadPos;
                                track->prevReadPos = 0;
                            } else {
                                bFinished = true;
                                break;
                            }
                        } else {
                            if (opcode >= 0x78) {
                                // long delay
                                track->delayTime = (((opcode & 7) << 8) + *(track->bgmReadPos++)) + 0x78;
                                POST_BGM_READ();

                            } else {
                                // delay
                                track->delayTime = opcode;
                            }
                        }
                    } else {
                        // note
                        if (opcode < 0xD4) {
                            notePitch = (opcode & 0x7F);
                            noteVelocity = *(track->bgmReadPos++);
                            POST_BGM_READ();
                            noteLength = *(track->bgmReadPos++);
                            POST_BGM_READ();
                            if (!(noteLength < 0xC0)) {
                                noteLength = (((u8)noteLength & ~0xC0) << 8) + *(track->bgmReadPos++) + 0xC0;
                                POST_BGM_READ();
                            }
                            bAcquiredVoiceIdx = false;
                            if (!track->muted) {
                                // find first free voice
                                for (voiceIdx = sp1F; voiceIdx < track->lastVoice; voiceIdx++) {
                                    voice = &player->globals->voices[voiceIdx];
                                    sp1F++;
                                    if (voice->priority == AU_PRIORITY_FREE) {
                                        bAcquiredVoiceIdx = true;
                                        break;
                                    }
                                }

                                if (!bAcquiredVoiceIdx) {
                                    if (track->polyphonicIdx >= BGM_POLYPHONY_2) {
                                        // try stealing a voice with lower priority
                                        for (voiceIdx = track->firstVoice; voiceIdx < track->lastVoice; voiceIdx++) {
                                            voice = &player->globals->voices[voiceIdx];
                                            if (voice->priority < player->priority) {
                                                au_reset_voice(voice, voiceIdx);
                                                bAcquiredVoiceIdx = true;
                                                break;
                                            }
                                        }
                                        // try stealing a voice with equal priority and zero note length
                                        if (!bAcquiredVoiceIdx) {
                                            for (voiceIdx = track->firstVoice; voiceIdx < track->lastVoice; voiceIdx++) {
                                                voice = &player->globals->voices[voiceIdx];
                                                if (voice->priority == player->priority) {
                                                    note = &player->notes[voiceIdx];
                                                    if (note->length == 0) {
                                                        au_reset_voice(voice, voiceIdx);
                                                        bAcquiredVoiceIdx = true;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        // try stealing a voice with equal priority and lowest note length
                                        if (!bAcquiredVoiceIdx) {
                                            s32 shortestLength = 0xFFFF;
                                            u8 voice_it;
                                            AuVoice* curVoice;
                                            SeqNote* curNote;
                                            for (voice_it = track->firstVoice; voice_it < track->lastVoice; voice_it++) {
                                                curVoice = &player->globals->voices[voice_it];
                                                if (curVoice->priority == player->priority) {
                                                    curNote = &player->notes[voice_it];
                                                    if (!curNote->pendingTick && curNote->length < shortestLength) {
                                                        shortestLength = curNote->length;
                                                        voice = curVoice;
                                                        note = curNote;
                                                        voiceIdx = voice_it;
                                                        bAcquiredVoiceIdx = true;
                                                    }
                                                }
                                            }
                                            if (bAcquiredVoiceIdx) {
                                                note->length = 0;
                                                au_reset_voice(voice, voiceIdx);
                                            }
                                        }

                                    } else {
                                        voiceIdx = track->firstVoice;
                                        voice = &player->globals->voices[voiceIdx];
                                        note = &player->notes[voiceIdx];
                                        note->length = 0;
                                        if (voice->priority <= player->priority) {
                                            au_reset_voice(voice, voiceIdx);
                                            bAcquiredVoiceIdx = true;
                                        }
                                    }
                                }
                            }
                            if (bAcquiredVoiceIdx) {
                                note = &player->notes[voiceIdx];
                                note->tremoloDepth = 0;
                                if (noteVelocity > 0) {
                                    note->velocity = noteVelocity + 1;
                                } else {
                                    note->velocity = 0;
                                }
                                note->length = noteLength;
                                if (track->isDrumTrack) {
                                    if (notePitch < 72) { // = 6 * 12
                                        drumInfo = &player->globals->dataPER->drums[notePitch];
                                    } else {
                                        drumInfo = player->drums[notePitch - 72]; // = 6 * 12
                                    }
                                    note->ins = au_get_instrument(player->globals, drumInfo->bankPatch >> 8, drumInfo->bankPatch & 0xFF, &voice->envelope);
                                    if (drumInfo->randVolume != 0) {
                                        note->volume = note->velocity * au_bgm_get_random_vol(player->randomValue1, drumInfo->volume, drumInfo->randVolume);
                                    } else {
                                        note->volume = note->velocity * drumInfo->volume;
                                    }
                                    // combining formats: 7.24 * 7.24 * 15.16 * 7.0 * 15.0 --> 16.16
                                    // first step, shifting fractional factors by 21:
                                    // 7.24 * 7.24 * 15.16 --> 7.3 * 7.3 * 10.0 --> 24.6
                                    // shifting this down by 20 transforms 24.6 --> 10.0
                                    // now for the second step with whole:
                                    //  10.0 * 7.0 * 15.0 --> 32.0
                                    // and a final shift by 16 transforms 32.0 --> 16.16
                                    voice->clientVolume = ((
                                        ((player->masterVolume >> 21)       // 7.24 --> 7.3
                                        * (track->insVolume >> 21)     // 7.24 --> 7.3
                                        * (track->proxVolume >> 21)) >> 20) // 15.16 --> 10.0 (fractional part truncated?)
                                        * (track->volume * note->volume)) >> 16;
                                    note->detune =
                                        drumInfo->keyBase
                                        + track->insCoarseDetune
                                        + track->insFineDetune
                                        - note->ins->keyBase;
                                    temp = (note->detune + track->detune) + player->detune;
                                    if (drumInfo->randTune != 0) {
                                        note->randDetune = au_bgm_get_random_pitch(player->randomValue1, temp, drumInfo->randTune);
                                        temp = note->randDetune;
                                    }
                                    note->pitchRatio = au_compute_pitch_ratio(temp) * note->ins->pitchRatio;
                                    if (drumInfo->randPan != 0) {
                                        voice->pan = au_bgm_get_random_pan(player, drumInfo->pan, drumInfo->randPan);
                                    } else {
                                        voice->pan = drumInfo->pan;
                                    }
                                    if (drumInfo->randReverb != 0) {
                                        voice->reverb = au_bgm_get_random_reverb(player->randomValue1, drumInfo->reverb, drumInfo->randReverb);
                                    } else {
                                        voice->reverb = drumInfo->reverb;
                                    }
                                } else {
                                    // combining formats: 7.24 * 7.24 * 15.16 * 7.0 * 15.0 --> 16.16
                                    // first step, shifting fractional factors by 21:
                                    // 7.24 * 7.24 * 15.16 --> 7.3 * 7.3 * 10.0 --> 24.6
                                    // shifting this down by 20 transforms 24.6 --> 10.0
                                    // now for the second step with whole:
                                    //  10.0 * 7.0 * 7.0 --> 24.0
                                    // and a final shift by 9 transforms 24.0 --> 15.16
                                    voice->clientVolume = note->volume = ((
                                        ((player->masterVolume >> 21)       // 7.24 --> 7.3
                                        * (track->insVolume >> 21)     // 7.24 --> 7.3
                                        * (track->proxVolume >> 21)) >> 20) // 15.16 --> 10.0 (fractional part truncated?)
                                        * (track->volume * note->velocity)) >> 9;
                                    note->ins = track->instrument;
                                    note->detune =
                                        (notePitch * 100)
                                        + track->insCoarseDetune
                                        + player->masterPitchShift
                                        + track->insFineDetune
                                        - note->ins->keyBase;
                                    note->pitchRatio = au_compute_pitch_ratio(
                                        note->detune
                                        + track->detune
                                        + player->detune)
                                        * track->instrument->pitchRatio;

                                    if (track->randomPanAmount != 0) {
                                        voice->pan = au_bgm_get_random_pan(player, track->insPan, track->randomPanAmount);
                                    } else {
                                        voice->pan = track->insPan;
                                    }
                                    voice->reverb = track->insReverb;

                                    if (track->pressOverride != 0) {
                                        voice->envelope.cmdListPress = (u8*) player->customPressEnvelopes[track->pressOverride - 1];
                                    } else {
                                        voice->envelope.cmdListPress = track->envelope.cmdListPress;
                                    }
                                    voice->envelope.cmdListRelease = track->envelope.cmdListRelease;
                                }
                                voice->instrument = note->ins;
                                voice->pitchRatio = note->pitchRatio;
                                voice->busID = track->busID;
                                if (note->length > 1) {
                                    note->pendingTick = true;
                                    note->tremoloDepth = track->tremoloDepth;
                                    note->tremoloPhase = 0;
                                    note->tremoloDelay = track->tremoloDelay;
                                    voice->syncFlags = AU_VOICE_SYNC_FLAG_ALL;
                                    voice->priority = player->priority;
                                    voice->clientPriority = voice->priority;
                                }
                            }
                        } else {
                            //TODO variable is nargs, but reusing temp is required to match
                            temp = SeqCmdArgCounts[opcode - 0xE0];
                            if (temp != 0) {
                                player->seqCmdArgs.raw[0] = *(track->bgmReadPos++);
                                POST_BGM_READ();
                            } else {
                                goto bgm_args_done;
                            }
                            if (temp > 1) {
                                player->seqCmdArgs.raw[1] = *(track->bgmReadPos++);
                                POST_BGM_READ();
                            } else {
                                goto bgm_args_done;
                            }
                            if (temp > 2) {
                                player->seqCmdArgs.raw[2] = *(track->bgmReadPos++);
                                POST_BGM_READ();
                            } else {
                                goto bgm_args_done;
                            }
                            if (temp > 3) {
                                player->seqCmdArgs.raw[3] = *(track->bgmReadPos++);
                                POST_BGM_READ();
                            }
                            bgm_args_done:
                            CurrentSeqCmdHandler = SeqCmdHandlers[opcode - 0xE0];
                            CurrentSeqCmdHandler(player, track);
                        }
                    }
                } // end while
            }

            for (voiceIdx = track->firstVoice; voiceIdx < track->lastVoice; voiceIdx++) {
                if (!track->muted) {
                    voice = &player->globals->voices[voiceIdx];
                    if (voice->priority == player->priority) {
                        note = &player->notes[voiceIdx];
                        if (!note->pendingTick) {
                            if (note->length > 0) {
                                note->length--;
                                if (note->length == 0) {
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                }
                            }
                            if (track->isDrumTrack) {
                                if (track->changed.tune || (player->detune != 0)) {
                                    note->pitchRatio = au_compute_pitch_ratio(((note->detune + note->randDetune) + track->detune) + player->detune) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                    }
                                }
                                if (track->changed.volume) {
                                    // combining formats: 7.24 * 7.24 * 15.16 * 7.0 * 15.0 --> 16.16
                                    // first step, shifting fractional factors by 21:
                                    // 7.24 * 7.24 * 15.16 --> 7.3 * 7.3 * 10.0 --> 24.6
                                    // shifting this down by 20 transforms 24.6 --> 10.0
                                    // now for the second step with whole:
                                    //  10.0 * 7.0 * 15.0 --> 32.0
                                    // and a final shift by 16 transforms 32.0 --> 16.16
                                    voice->clientVolume = (
                                        ((((player->masterVolume >> 21)     // 7.24 --> 7.3
                                        * (track->insVolume >> 21))    // 7.24 --> 7.3
                                        * (track->proxVolume >> 21)) >> 20) // 15.16 --> 10.0 (fractional part truncated?)
                                        * (track->volume * note->volume)) >> 16;
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                }
                            } else {
                                // Modulate pitch using a triange wave for tremolo effect
                                if (note->tremoloDepth != 0) {
                                    if (note->tremoloDelay != 0) {
                                        note->tremoloDelay--;
                                    } else {
                                        u8 quadrant;
                                        note->tremoloPhase += track->tremoloRate;
                                        opcode = (note->tremoloPhase << 2) + 3; // +3 just to fill lower 2 bits

                                        // Determine what part of the triangle wave we are in (using top 2 bits of u8)
                                        quadrant = note->tremoloPhase >> 6;

                                        // Invert the triangle for quadrants 1 and 3 (ugly code required to match)
                                        /* visualized: //// --> /\/\ */
                                        if ((quadrant == 1) || (quadrant == 3)) {
                                            u8 temp2 = ~opcode;
                                            tremoloDetune = temp2 + 1;
                                        } else {
                                            tremoloDetune = opcode;
                                        }

                                        // Scale by depth
                                        tremoloDetune = (tremoloDetune * track->tremoloDepth) >> 8;

                                        // Invert sign for the second half of triangle wave
                                        if ((quadrant == 2) || (quadrant == 3)) {
                                            tremoloDetune = -tremoloDetune;
                                        }

                                        // Apply pitch detune from tremolo
                                        note->pitchRatio = au_compute_pitch_ratio(tremoloDetune + ((note->detune + track->detune) + player->detune)) * note->ins->pitchRatio;
                                        if (voice->pitchRatio != note->pitchRatio) {
                                            voice->pitchRatio = note->pitchRatio;
                                            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                        }
                                    }
                                } else if (track->changed.tune || (player->detune != 0)) {

                                    note->pitchRatio = au_compute_pitch_ratio((note->detune + track->detune) + player->detune) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                    }
                                }
                                if (track->changed.volume) {
                                    // combining formats: 7.24 * 7.24 * 15.16 * 7.0 * 15.0 --> 16.16
                                    // first step, shifting fractional factors by 21:
                                    // 7.24 * 7.24 * 15.16 --> 7.3 * 7.3 * 10.0 --> 24.6
                                    // shifting this down by 20 transforms 24.6 --> 10.0
                                    // now for the second step with whole:
                                    //  10.0 * 7.0 * 7.0 --> 24.0
                                    // and a final shift by 9 transforms 24.0 --> 15.16
                                    note->volume = ((
                                        (player->masterVolume >> 21)            // 7.24 --> 7.3
                                        * (track->insVolume >> 21)         // 7.24 --> 7.3
                                        * (track->proxVolume >> 21)) >> 20)
                                        * (track->volume * note->velocity) >> 9;
                                    voice->clientVolume = note->volume;
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                    voice->pan = track->insPan;
                                    voice->reverb = track->insReverb;
                                } else if (track->changed.pan || track->changed.reverb) {
                                    voice->pan = track->insPan;
                                    voice->reverb = track->insReverb;
                                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
                                }
                            }
                        }
                        note->pendingTick = false;
                    }
                }
            }
        }
    }

    if (bFinished) {
        player->masterState = BGM_PLAY_STATE_FETCH;
    }
}

static const f32 padding[] = {0.0f}; // at least after au_bgm_player_audio_frame_update

void au_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 bpm = player->seqCmdArgs.MasterTempo.value;
    s32 tempo;

    player->masterTempoBPM = bpm;
    tempo = au_bgm_bpm_to_tempo(player, bpm);
    player->masterTempo = tempo;
    player->nextUpdateStep = BGM_TEMPO_TO_UPDATE_UNITS(tempo);
    player->masterTempoTicks = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
}

static s32 au_bgm_bpm_to_tempo(BGMPlayer* player, u32 tempo) {
    u32 maxTempo = player->maxTempo;
    u32 ret = tempo;

    ret *= player->playbackRate;

    if (maxTempo < ret) {
        ret = maxTempo;
    } else if (ret == 0) {
        ret = 1;
    }

    return ret * 100;
}

void au_BGMCmd_E1_MasterVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    s8_24 volume = player->seqCmdArgs.MasterVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 24;
    }

    player->masterVolume = volume;
    player->masterVolumeTicks = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->volumeChanged = true;
    track->changed.volume = true;
}

void au_BGMCmd_E2_MasterDetune(BGMPlayer* player, BGMPlayerTrack* track) {
    player->masterPitchShift = (s8)player->seqCmdArgs.MasterPitchShift.cent * 100;
}

void au_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->globals->effectChanges[player->busID].type = player->seqCmdArgs.UnkCmdE3.effectType;
    player->globals->effectChanges[player->busID].changed = true;
}

void au_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.MasterEffect.index;
    u32 busID = player->effectIndices[index];

    if ((index < 4) && (busID < 0x80)) {
        if (player->globals->effectChanges[busID].type != player->seqCmdArgs.MasterEffect.value) {
            player->globals->effectChanges[busID].type = player->seqCmdArgs.MasterEffect.value;
            player->globals->effectChanges[busID].changed = true;
        }
        player->effectValues[index] = player->seqCmdArgs.MasterEffect.value;
    }
}

void au_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterTempoFade.time;
    s32 tempo = au_bgm_bpm_to_tempo(player, player->seqCmdArgs.MasterTempoFade.value);

    if (time <= 0) {
        time = 1;
    }

    player->masterTempoTicks = time;
    player->masterTempoTarget = tempo;
    player->masterTempoStep = (tempo - player->masterTempo) / time;
}

void au_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterVolumeFade.time;
    s8_24 volume = player->seqCmdArgs.MasterVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 24;
    }

    if (time <= 0) {
        time = 1;
    }

    player->masterVolumeTicks = time;
    player->masterVolumeTarget = volume;
    player->masterVolumeStep = (volume - player->masterVolume) / time;
}

void au_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, BGMPlayerTrack* track) {
    track->patch = player->seqCmdArgs.OverridePatch.patch;
    track->instrument = au_get_instrument(player->globals, player->seqCmdArgs.OverridePatch.bank, track->patch, &track->envelope);
}

void au_BGMCmd_E9_InstrumentVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    s8_24 volume = arg0->seqCmdArgs.InstrumentVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 24;
    }

    track->insVolume = volume;
    track->changed.volume = true;
}

void au_BGMCmd_F6_InstrumentVolumeLerp(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.TrackVolumeFade.time;
    s8_24 volume = player->seqCmdArgs.TrackVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 24;
    }

    if (volume != track->insVolume) {
        if (time <= 0) {
            time = 1;
        }

        track->insVolumeTicks = time;
        track->insVolumeTarget = volume;
        track->insVolumeStep = (volume - track->insVolume) / time;
    }
}

void au_BGMCmd_EA_InstrumentPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->insPan = player->seqCmdArgs.InstrumentPan.value & 0x7F;
    track->randomPanAmount = 0;
    track->changed.pan = true;
}

void au_BGMCmd_EB_InstrumentReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->insReverb = player->seqCmdArgs.InstrumentReverb.value & 0x7F;
    track->changed.reverb = true;
}

void au_BGMCmd_EC_TrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->volume = player->seqCmdArgs.TrackVolume.value & 0x7F;
    track->changed.volume = true;
}

void au_BGMCmd_ED_InstrumentCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->insCoarseDetune = player->seqCmdArgs.InstrumentCoarseTune.semitone * AU_SEMITONE_CENTS;
}

void au_BGMCmd_EE_InstrumentFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->insFineDetune = player->seqCmdArgs.InstrumentFineTune.cent;
}

void au_BGMCmd_EC_TrackDetune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->detune = player->seqCmdArgs.TrackDetune.cents;
    track->changed.tune = true;
}

void au_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->tremoloDelay = player->seqCmdArgs.TrackTremolo.delay;
    track->tremoloRate = player->seqCmdArgs.TrackTremolo.speed;
    track->tremoloDepth = player->seqCmdArgs.TrackTremolo.depth;
}

void au_BGMCmd_F1_TrackTremoloRate(BGMPlayer* player, BGMPlayerTrack* track) {
    track->tremoloRate = player->seqCmdArgs.TrackTremoloRate.value;
}

void au_BGMCmd_F2_TrackTremoloDepth(BGMPlayer* player, BGMPlayerTrack* track) {
    track->tremoloDepth = player->seqCmdArgs.TrackTremoloDepth.value;
}

void au_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->tremoloDepth = 0;
}

void au_BGMCmd_F4_SubTrackRandomPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->insPan = player->seqCmdArgs.RandomPan.pan0 & 0x7F;
    track->randomPanAmount = player->seqCmdArgs.RandomPan.pan1 & 0x7F;
}

void au_BGMCmd_F5_UseInstrument(BGMPlayer* player, BGMPlayerTrack* track) {
    BGMInstrumentInfo* instrument;
    s32 volume;
    u32 insIndex;
    u32 patch;
    u32 bank;

    insIndex = player->seqCmdArgs.UseInstrument.index;
    if (insIndex < BGM_MAX_INSTRUMNETS) {
        if (insIndex < player->bgmInstrumentCount) {
            instrument = &player->instrumentsInfo[insIndex];
        } else {
            instrument = &player->globals->defaultPRGEntry;
        }
    } else {
        insIndex -= BGM_MAX_INSTRUMNETS;
        if (insIndex < PRG_MAX_COUNT) {
            instrument = &player->globals->dataPRG[insIndex];
        } else {
            instrument = &player->globals->defaultPRGEntry;
        }
    }
    bank = instrument->bankPatch >> 8;
    patch = (u8)instrument->bankPatch;
    volume = instrument->volume & 0x7F;
    track->patch = patch;
    track->instrument = au_get_instrument(player->globals, bank, patch, &track->envelope);
    if (volume != 0) {
        volume <<= 24;
    }
    track->insVolume = volume;
    track->insPan = instrument->pan & 0x7F;
    track->insReverb = instrument->reverb & 0x7F;
    track->insCoarseDetune = instrument->coarseTune * AU_SEMITONE_CENTS;
    track->insFineDetune = instrument->fineTune;
    track->changed.all |= 0x10101; // volume, pan, and reverb
}

void au_BGMCmd_F7_ReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.ReverbType.index;
    s8 busID = player->effectIndices[index];

    if ((index < ARRAY_COUNT(player->effectIndices)) && (busID >= 0)) {
        track->busID = busID;
    } else {
        track->busID = player->busID;
    }
}

void au_BGMCmd_FD_EventTrigger(BGMPlayer* player, BGMPlayerTrack* track) {
    snd_song_trigger_music_event(player->priority, track->index, player->seqCmdArgs.EventTrigger.eventInfo >> 8);
}

// jump to another part of the track and return after a specified read length
void au_BGMCmd_FE_Detour(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos readPos = AU_FILE_RELATIVE(player->bgmFile, player->seqCmdArgs.Detour.offset);

    track->detourLength = player->seqCmdArgs.Detour.length;
    track->savedPos = track->bgmReadPos;
    track->bgmReadPos = readPos;
}

// jump to another part of the track, selected by player->branchVar
void au_BGMCmd_FC_Branch(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos args;
    u32 i;

    // get jump table
    args = AU_FILE_RELATIVE(player->bgmFile, player->seqCmdArgs.Branch.offset);
    if (player->proxMixID < player->seqCmdArgs.Branch.tableCount) {
        args += player->proxMixID * 3;
    }
    // read new position from jump table
    track->prevReadPos = track->bgmReadPos;
    track->bgmReadPos = AU_FILE_RELATIVE(player->bgmFile, (args[0] << 8) + args[1]);
    track->isDrumTrack = args[2];

    if (track->proxMixSetChanged) {
        track->proxMixSetChanged = false;
        track->proxVolume = 0;
        for (i = track->firstVoice; i < track->lastVoice; i++) {
            AuVoice* voice = &player->globals->voices[i];
            if ((voice->priority == player->priority) && (voice->cmdPtr != nullptr)) {
                au_reset_voice(voice, i);
            }
        }
    }
    if (track->proxMixValChanged) {
        track->proxMixValChanged = false;
        au_bgm_set_prox_mix_fade(player, track, player->proxMixVolume, 144);
    }
    // reset an odd subset of parameters
    track->insCoarseDetune = 0;
    track->insFineDetune = 0;
    track->pressOverride = 0;
    track->detune = 0;
    track->tremoloDepth = 0;
    track->insVolumeTicks = 0;
    track->randomPanAmount = 0;
    track->busID = player->busID;
}

void au_BGMCmd_FF_Special(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 writePos;
    u8 delaySide;
    u8 delayTime;
    u32 i;

    u32 type = player->seqCmdArgs.Special.type;
    u32 arg1 = player->seqCmdArgs.Special.arg1;
    u32 arg2 = player->seqCmdArgs.Special.arg2;

    switch (type) {
        case BGM_SPECIAL_SET_STEREO_DELAY:
            if ((arg1 < ARRAY_COUNT(player->effectIndices)) && ((s8)player->effectIndices[arg1] >= 0)) {
                player->globals->channelDelayBusID = player->effectIndices[arg1];
                if (arg2 != 0) {
                    delayTime = arg2 & 0xF;
                    delaySide = ((arg2 >> 4) & 1) + 1;
                    if ((player->globals->channelDelayTime != delayTime) || (player->globals->channelDelaySide != delaySide)) {
                        player->globals->channelDelayTime = delayTime;
                        player->globals->channelDelaySide = delaySide;
                        player->globals->channelDelayPending = true;
                    }
                } else {
                    if (player->globals->channelDelaySide != AU_DELAY_CHANNEL_NONE) {
                        player->globals->channelDelaySide = AU_DELAY_CHANNEL_NONE;
                        player->globals->channelDelayPending = true;
                    }
                }
            }
            break;
        case BGM_SPECIAL_SEEK_CUSTOM_ENV:
            if (arg1 - 1 < ARRAY_COUNT(player->customPressEnvelopes)) {
                player->writingCustomEnvelope = arg1;
                au_bgm_clear_custom_note_press(player, arg1 - 1);
            } else {
                player->writingCustomEnvelope = 0;
            }
            break;
        case BGM_SPECIAL_WRITE_CUSTOM_ENV:
            i = player->writingCustomEnvelope;
            if (i - 1 < ARRAY_COUNT(player->customPressEnvelopes)) {
                i--; // convert ID --> array index, needed to match
                writePos = player->customEnvelopeWritePos[i];
                if (writePos < ARRAY_COUNT(player->customPressEnvelopes[i]) - 1) {
                    if (arg1 >= ARRAY_COUNT(BgmCustomEnvLookup)) {
                        player->customPressEnvelopes[i][writePos] = (arg1 << 8) + arg2;
                    } else {
                        player->customPressEnvelopes[i][writePos] = (BgmCustomEnvLookup[arg1] << 8) + arg2;
                    }
                    player->customEnvelopeWritePos[i] = writePos + 1;
                }
            }
            break;
        case BGM_SPECIAL_USE_CUSTOM_ENV:
            if (arg1 <= ARRAY_COUNT(player->customPressEnvelopes)) {
                track->pressOverride = arg1;
            } else {
                track->pressOverride = 0;
            }
            break;
        case BGM_SPECIAL_TRIGGER_SOUND:
            if (player->soundManager != nullptr) {
                for (i = 0; i < ARRAY_COUNT(player->soundManager->bgmSounds); i++) {
                    if ((player->soundManager->bgmSounds[i].index) == 0) {
                        player->soundManager->bgmSounds[i].index = arg1;
                        player->soundManager->bgmSounds[i].volume =
                            ((s32)(
                                ((u32)player->fadeInfo.baseVolume >> 16) *
                                ((u32)player->fadeInfo.envelopeVolume >> 16)
                            ) + AU_MAX_VOLUME_16) >> 0x17;
                        break;
                    }
                }
            }
            break;
        case BGM_SPECIAL_PROX_MIX_OVERRIDE:
            if (arg1 == 0) {
                if (track->proxMixValChanged) {
                    track->proxMixValChanged = false;
                    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                        BGMPlayerTrack* otherTrack = &player->tracks[i];
                        if (player->proxMixVolume == AU_MAX_VOLUME_8) {
                            if (otherTrack->proxVol1 != 0) {
                                otherTrack->proxMixValChanged = false;
                                au_bgm_set_prox_mix_fade(player, otherTrack, otherTrack->proxVol1, 72);
                            }
                        } else {
                            if (otherTrack->proxVol2 != 0) {
                                otherTrack->proxMixValChanged = false;
                                au_bgm_set_prox_mix_fade(player, otherTrack, otherTrack->proxVol2, 72);
                            }
                        }
                    }
                }
            } else {
                track->proxVol1 = arg1;
                track->proxVol2 = arg2;
            }
            break;
    }
}

void au_BGMCmd_NOP(BGMPlayer* player, BGMPlayerTrack* track) {
}

/*
Uses bit masks:
3F00 = 0011 1111 0000 0000 -> 0011 1111
000C = 0000 0000 0000 1100 -> 1100 0000
*/
static u8 au_bgm_get_random_pan(BGMPlayer* player, u8 pan, u8 amplitude) {
    s32 seed = player->randomValue1;
    s32 tap7 = seed >> 7;
    s32 tap2 = seed >> 2;
    s32 parity = (tap7 + tap2) & 1;
    s32 lo = (seed >> 8) & 0x3F; // bitmask 0x3F00
    s32 hi = (seed << 4) & 0xC0; // bitmask 0x000C
    s32 random = lo + hi;
    s32 base = pan;
    s32 retPan;

    if (parity) {
        retPan = base + ((amplitude * random) >> 8);
    } else {
        retPan = base - ((amplitude * random) >> 8);
    }
    if (retPan < AU_PAN_MIN) {
        retPan = AU_PAN_MIN;
    } else if (retPan > AU_PAN_MAX) {
        retPan = AU_PAN_MAX;
    }
    return retPan;
}

/*
Uses bit masks:
3C0 = 0000 0011 1100 0000 -> 0001 1111
03C = 0000 0000 0011 1100 -> 1110 0000
*/
static s16 au_bgm_get_random_pitch(s32 seed, s32 pitch, u8 amplitude) {
    s32 tap4 = seed >> 4;
    s32 tap1 = seed >> 1;
    s32 parity = (tap4 + tap1) & 1;
    s32 lo = (seed >> 6) & 0xF;  // bitmask 0x3C0
    s32 hi = (seed << 2) & 0xF0; // bitmask 0x03C
    s32 random = lo + hi;
    s32 retVal;

    if (parity) {
        retVal = pitch + ((amplitude * 5 * random) >> 8);
    } else {
        retVal = pitch - ((amplitude * 5 * random) >> 8);
    }
    return retVal;
}

/*
Uses bit masks:
1F00 = 0001 1111 0000 0000 -> 0001 1111
00E0 = 0000 0000 1110 0000 -> 1110 0000
*/
static u8 au_bgm_get_random_vol(s32 seed, u8 volume, u8 amplitude) {
    s32 lo = (seed >> 8) & 0x1F; // bitmask 0x1F00
    s32 hi = seed & 0xE0;
    s32 random = lo + hi;

    return volume * (0x8000 - amplitude * random);
}

/*
Uses bit masks:
0380 = 0000 0011 1000 0000 -> 0000 0111
001F = 0000 0000 0001 1111 -> 1111 1000
*/
static u8 au_bgm_get_random_reverb(s32 seed, u8 reverb, u8 amplitude) {
    s32 lo = (seed >> 7) & 7;    // bitmask 0x380
    s32 hi = (seed << 3) & 0xF8; // bitmask 0x01F
    s32 random = lo + hi;

    return reverb * (0x8000 - (amplitude * random));
}

void au_bgm_set_proximity_mix(s32 songName, u32 mix) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    s32 changed = false;
    u8 mixID = mix & 0xFF;
    s32 i;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if ((player != nullptr) && (player->proxMixValue != mix)) {
            player->proxMixValue = mix;
            if (player->proxMixID != mixID) {
                player->proxMixID = mixID;
                changed = true;
            }
            player->proxMixVolume = (mix >> 0x18) & 0x7F;
            for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                track = &player->tracks[i];
                if (changed) {
                    track->proxMixSetChanged = true;
                }
                track->proxMixValChanged = true;
            }
        }
    }
}

void au_bgm_set_playback_rate(BGMPlayer* player, f32 rate) {
    if (rate > 2.0) {
        rate = 2.0f;
    } else if (rate < 0.25) {
        rate = 0.25f;
    }

    player->playbackRate = rate;
    player->masterTempo = au_bgm_bpm_to_tempo(player, player->masterTempoBPM);
    player->nextUpdateStep = BGM_TEMPO_TO_UPDATE_UNITS(player->masterTempo);
    player->masterTempoTicks = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
}

void au_bgm_player_set_detune(BGMPlayer* player, s32 detune) {
    if (detune > AU_OCTAVE_CENTS) {
        detune = AU_OCTAVE_CENTS;
    } else if (detune < -2 * AU_OCTAVE_CENTS) {
        detune = -2 * AU_OCTAVE_CENTS;
    }

    player->detune = detune;
}

void au_bgm_change_track_volume(BGMPlayer* player, s32 trackIdx, s16 time, u8 volume) {
    BGMPlayerTrack* track = &player->tracks[trackIdx];

    if (track->bgmReadPos != 0) {
        player->seqCmdArgs.TrackVolumeFade.time = time;
        player->seqCmdArgs.TrackVolumeFade.value = volume;
        au_BGMCmd_F6_InstrumentVolumeLerp(player, track);
    }
}

void au_bgm_set_track_volumes(BGMPlayer* player, u8* trackVols, s32 mode) {
    player->trackVolsConfig = trackVols;
    player->bFadeConfigSetsVolume = mode;
}

void au_bgm_set_prox_mix_fade(BGMPlayer* player, BGMPlayerTrack* track, s32 target, s32 duration) {
    if (target != 0) {
        target = AU_VOL_8_TO_16(target);
    }
    if (duration <= 0) {
        duration = 1;
    } else if (duration > 1000) {
        duration = 1000;
    }
    if (target == track->proxVolume) {
        track->proxVolumeTicks = 0;
        return;
    }
    track->proxVolumeTicks = duration;
    track->proxVolumeTarget = target;
    track->proxVolumeStep = ((target << 0x10) - track->proxVolume) / duration;
}

void au_bgm_reset_all_voices(BGMPlayer* player) {
    u8 i;

    for (i = 0; i < ARRAY_COUNT(player->globals->voices); i++) {
        AuVoice* voice = &player->globals->voices[i];
        if (voice->priority == player->priority) {
            au_reset_voice(voice, i);
        }
    }
}

AuResult au_bgm_set_linked_tracks(SongSwapLinkedRequest* request) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    BGMPlayerTrack* linkTrack;
    AuVoice* voice;
    s32 trackIdx;
    s32 voiceIdx;
    s8 oldVolume;

    s32 songName = request->songName;
    bool enabled = request->enabled;
    AuResult status = AU_RESULT_OK;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != nullptr) {
            for (trackIdx = 0; trackIdx < ARRAY_COUNT(player->tracks); trackIdx++) {
                track = &player->tracks[trackIdx];
                if (track->bgmReadPos != nullptr) {
                    if (track->linkedTrackID != 0) {
                        linkTrack = &player->tracks[track->linkedTrackID - 1];
                        if (enabled) {
                            if (track->muted) {
                                track->muted = false;
                                linkTrack->muted = true;
                                // release all voices for linked track
                                for (voiceIdx = linkTrack->firstVoice; voiceIdx < linkTrack->lastVoice; voiceIdx++) {
                                    voice = &player->globals->voices[voiceIdx];
                                    if (voice->priority == player->priority) {
                                        voice->envelope.cmdListRelease = EnvelopeReleaseDefaultFast;
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                    }
                                }
                                // fade in main track
                                oldVolume = track->insVolume >> 24;
                                au_BGMCmd_E9_InstrumentVolume(player, track);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                au_BGMCmd_F6_InstrumentVolumeLerp(player, track);
                            }
                        } else {
                            if (!track->muted) {
                                track->muted = true;
                                linkTrack->muted = false;
                                // release all voices for main track
                                for (voiceIdx = track->firstVoice; voiceIdx < track->lastVoice; voiceIdx++) {
                                    voice = &player->globals->voices[voiceIdx];
                                    if (voice->priority == player->priority) {
                                        voice->envelope.cmdListRelease = EnvelopeReleaseDefaultFast;
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                    }
                                }
                                // fade in linked track
                                oldVolume = linkTrack->insVolume >> 24;
                                au_BGMCmd_E9_InstrumentVolume(player, linkTrack);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                au_BGMCmd_F6_InstrumentVolumeLerp(player, linkTrack);
                            }
                        }
                    }
                }
            }
        } else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }

    return status;
}
