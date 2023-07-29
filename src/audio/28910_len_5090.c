#include "audio.h"

extern u8 EnvelopeReleaseDefaultFast[];
extern u8 BgmDivisors[8];
extern u8 D_80078558[40];

extern void (*CurrentSeqCmdHandler)(BGMPlayer*, BGMPlayerTrack*);
extern void (*SefCmdHandlers[])(SoundManager*, SoundPlayer*);
extern void (*SeqCmdHandlers[])(BGMPlayer*, BGMPlayerTrack*);
extern u8 SeqCmdArgCounts[];

static void au_bgm_stop_player(BGMPlayer* player);

static s32 snd_bpm_to_tempo(BGMPlayer* player, u32 tempo);

static u8 au_bgm_get_random_pan(BGMPlayer* player, u8 arg1, u8 arg2);
static s16 au_bgm_get_random_pitch(s32 arg0, s32 arg1, u8 arg2);
static u8 au_bgm_get_random_vol(s32 arg0, u8 volume, u8 arg2);
static u8 au_bgm_get_random_reverb(s32 arg0, u8 arg1, u8 arg2);

void au_bgm_update_main(BGMPlayer* player) {
    BGMHeader* bgmFile;
    BGMFileInfo* bgmData;
    s32 unkType;
    u32 segmentID;
    s32 segmentOffset;
    u32 value;
    s32 delta;
    u8 var_a1;
    u8 pos;
    u32 i;

    segmentID = 0;
    unkType = -1;
    player->updateCounter++;

    if (player->unk_258 != 0) {
        if (player->unk_258 < ARRAY_COUNT(player->unk_238)) {
            pos = player->unk_259;
            for (var_a1 = 0; var_a1 < player->unk_258; var_a1++) {
                value = player->unk_238[pos];
                if (value != 0) {
                    if (value < 16) {
                        unkType = value & 3;
                        segmentID = value >> 2;
                    }
                    pos++;
                    if (pos >= ARRAY_COUNT(player->unk_238)) {
                        pos = 0;
                    }
                }
            }
            delta = player->unk_25A - player->unk_259;
            if (delta < 0) {
                delta += ARRAY_COUNT(player->unk_238);
            }
            player->unk_258 -= delta;
            player->unk_259 = player->unk_25A;
        } else {
            player->unk_258 = 0;
        }
        if (unkType != -1) {
            if (unkType != 0) {
                if (unkType != player->unk_58) {
                    player->unk_58 = unkType & 0xFF;
                    player->unk_5A = unkType & 0xFF;
                    player->masterState = BGM_PLAY_STATE_INIT;
                    player->nextUpdateStep = BGM_SAMPLE_RATE;
                    if (unkType == 2) {
                        bgmFile = player->globals->dataBGM[1];
                    } else {
                        bgmFile = player->globals->dataBGM[0];
                    }
                    player->bgmFile = bgmFile;
                    bgmData = &bgmFile->info;
                    func_8004E880(player, BGM_SAMPLE_RATE, BgmDivisors[((u8*)player->unk_74)[0] & 7]); //TODO revise unk_74 typing

                    segmentOffset = bgmData->segments[segmentID];
                    if (segmentOffset == 0) {
                        segmentOffset = bgmData->segments[0];
                    }
                    player->segmentStartPos = AU_FILE_RELATIVE(bgmFile, segmentOffset << 2);
                    player->segmentReadPos = AU_FILE_RELATIVE(bgmFile, segmentOffset << 2);

                    if (bgmData->drums != 0) {
                        player->drumsInfo = AU_FILE_RELATIVE(player->bgmFile, bgmData->drums << 2);
                        player->bgmDrumCount = bgmData->drumCount;
                        for (i = 0; i < player->bgmDrumCount; i++) {
                            BGMDrumInfo* drum = &player->drumsInfo[i];
                            player->drums[i] = drum;
                        }
                        for (; i < 12; i++) {
                            player->drums[i] = player->drums[0];
                        }
                    } else {
                        player->drumsInfo = NULL;
                        player->bgmDrumCount = 0;
                    }

                    if (bgmData->instruments != 0) {
                        player->instrumentsInfo = AU_FILE_RELATIVE(player->bgmFile, bgmData->instruments << 2);
                        player->bgmInstrumentCount = bgmData->instrumentCount;
                        return;
                    }
                    player->instrumentsInfo = NULL;
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
    return NULL;
}

AuResult au_bgm_dispatch_player_event(SongUpdateEvent* event) {
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
    songName = event->songName;
    variation = event->variation;
    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != NULL) {
            fileInfo = &player->bgmFile->info;
            duration = event->duration;
            if (duration != 0) {
                if (duration > SND_MAX_DURATION) {
                    duration = SND_MAX_DURATION;
                } else if (duration < SND_MIN_DURATION) {
                    duration = SND_MIN_DURATION;
                }
            }
            volume0 = event->startVolume;
            if (volume0 > 0x7F) {
                volume0 = 0x7F;
            }
            if (volume0 != 0) {
                volume0 = (volume0 << 8) | 0xFF;
            }
            volume1 = event->finalVolume;
            if (volume1 > 0x7F) {
                volume1 = 0x7F;
            }
            if (volume1 != 0) {
                volume1 = (volume1 << 8) | 0xFF;
            } else {
                volume1 = 0x7FFF;
            }

            au_fade_init(&player->fadeInfo, duration, volume0, volume1);
            player->fadeInfo.targetVolScale = 0x7FFF;
            player->fadeInfo.volScaleTime = 1;
            func_8004E880(player, BGM_SAMPLE_RATE, BgmDivisors[fileInfo->numSegments & 7]);

            if (variation < 0 || variation >= 4 || fileInfo->segments[variation] == 0) {
                variation = 0;
            }
            player->curSegmentID = variation;

            player->segmentStartPos = AU_FILE_RELATIVE(player->bgmFile, fileInfo->segments[variation] << 2);
            player->segmentReadPos = player->segmentStartPos;

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
                player->drumsInfo = NULL;
                player->bgmDrumCount = 0;
            }
            if (fileInfo->instruments != 0) {
                player->instrumentsInfo = AU_FILE_RELATIVE(player->bgmFile, fileInfo->instruments << 2);
                player->bgmInstrumentCount = fileInfo->instrumentCount;
            } else {
                player->instrumentsInfo = NULL;
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
        if (player != NULL) {
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
        if (player != NULL) {
            result = (songName == player->songName);
        } else {
            result = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        result = AU_ERROR_NULL_SONG_NAME;
    }

    return result;
}

s32 func_8004DB28(BGMPlayer* player) {
    if (player->songName != NULL && player->masterState != 0) {
        return 1;
    } else {
        return 0;
    }
}

AuResult func_8004DB4C(SongUpdateEvent* s) {
    AuResult status;
    BGMPlayer* player;
    u32 songName = s->songName;
    u32 duration = s->duration;
    s16 volume = s->finalVolume;

    status = AU_RESULT_OK;
    if (songName != 0) {
        if (duration >= SND_MIN_DURATION && duration <= SND_MAX_DURATION) {
            player = au_bgm_get_player_with_song_name(songName);
            if (player != NULL) {
                if (player->songName == songName) {
                    if (player->masterState != BGM_PLAY_STATE_IDLE) {
                        if (player->unk_220 == 0) {
                            player->fadeInfo.targetVolume = volume;
                            player->fadeInfo.fadeTime = (duration * 1000) / AU_5750;
                            player->fadeInfo.fadeStep = ((volume << 0x10) - player->fadeInfo.curVolume.s32) / player->fadeInfo.fadeTime;
                            player->fadeInfo.variation = s->variation;
                            if (s->unk14 == 1) {
                                player->fadeSongName = songName;
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

AuResult func_8004DC80(s32 songName) {
    SongUpdateEvent s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 0);
}

AuResult func_8004DCB8(SongUpdateEvent* update, s32 clearChanged) {
    AuResult status;
    BGMPlayer* playerA;
    BGMPlayer* playerB;
    s32 songName;
    s32 variation;
    u32 i;
    u32 j;

    songName = update->songName;
    variation = update->variation;
    status = AU_RESULT_OK;

    if (songName != 0) {
        playerA = au_bgm_get_player_with_song_name(songName);
        if (playerA != NULL) {
            if (update->unk14 == 0) {
                playerB = func_80053F64(variation);
                if (playerB != NULL) {
                    if (songName == playerA->songName) {
                        if (!clearChanged) {
                            for (i = 0; i < ARRAY_COUNT(playerA->tracks); i++) {
                                BGMPlayerTrack* track = &playerA->tracks[i];
                                if (track->bgmReadPos != 0) {
                                    for (j = track->unk_52; j < track->unk_53; j++) {
                                        track->changed.all = 0;
                                    }
                                }
                            }
                        }
                        playerA->globals->unk_globals_6C[variation].unk_5 = playerA->priority;
                        playerA->globals->unk_globals_6C[variation].unk_4 = 1;
                        playerA->fadeSongName = 0;
                        au_copy_words(playerA, playerB, sizeof(*playerA));
                        if (clearChanged == 0) {
                            au_bgm_stop_player(playerA);
                        }
                    }
                } else {
                    status = AU_ERROR_INVALID_SONG_DURATION;
                }
            } else {
                if (songName == playerA->songName) {
                    if (playerA->masterState != BGM_PLAY_STATE_IDLE) {
                        playerA->unk_220 = 1;
                        func_80050900(playerA);
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

AuResult func_8004DE2C(SongUpdateEvent* update) {
    AuResult status;
    BGMPlayer* playerA;
    BGMPlayer* playerB;
    s32 variation;
    s32 songName;
    s32 volume0;
    s32 volume1;
    s32 duration;

    songName = update->songName;
    variation = update->variation;
    status = AU_RESULT_OK;

    if (songName != 0) {
        if (update->unk14 == 0) {
            playerA = func_80053F64(variation);
            if (playerA != NULL && playerA->globals->unk_globals_6C[variation].unk_4 == 1) {
                playerB = func_80054248(playerA->globals->unk_globals_6C[variation].unk_5);
                if (playerB != NULL) {
                    if (func_8004DB28(playerB) == 0) {
                        status = func_80053E58(playerA->songID, playerA->bgmFile);
                        duration = update->duration;
                        if (duration != 0) {
                            if (duration > SND_MAX_DURATION) {
                                duration = SND_MAX_DURATION;
                            } else if (duration < SND_MIN_DURATION) {
                                duration = SND_MIN_DURATION;
                            }
                        }
                        volume0 = update->startVolume;
                        if (volume0 > BGM_MAX_VOLUME) {
                            volume0 = BGM_MAX_VOLUME;
                        }
                        if (volume0 != 0) {
                            volume0 = (volume0 << 8) | 0xFF;
                        }
                        volume1 = update->finalVolume;
                        if (volume1 > BGM_MAX_VOLUME) {
                            volume1 = BGM_MAX_VOLUME;
                        }
                        if (volume1 != 0) {
                            volume1 = (volume1 << 8) | 0xFF;
                        } else {
                            volume1 = 0x7FFF;
                        }
                        playerB->globals->unk_74 = playerB;
                        playerB->globals->unk_78 = playerA;
                        playerB->globals->unkSongName = songName;
                        playerB->globals->unkFadeTime = duration;
                        playerB->globals->unkFadeStart = volume0;
                        playerB->globals->unkFadeEnd = volume1;
                        playerB->globals->unk_80 = 1;
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
            playerB = au_bgm_get_player_with_song_name(songName);
            if (playerB != NULL) {
                if (songName == playerB->songName) {
                    if (playerB->unk_220 != 0) {
                        playerB->unk_220 = 0;
                    }
                }
            }
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

void func_8004DFD4(AuGlobals* globals) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    SeqNote* note;
    u32 i;
    u32 j;
    s32 k;

    player = globals->unk_74;
    au_copy_words(globals->unk_78, globals->unk_74, sizeof(*player));
    if (globals->unkSongName == player->songName) {
        for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
            track = &player->tracks[i];
            if (track->bgmReadPos != NULL) {
                for (j = track->unk_52; j < track->unk_53; j++) {
                    note = &player->notes[j];
                    note->noteLength = 0;
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
        au_fade_init(&player->fadeInfo, globals->unkFadeTime, globals->unkFadeStart, globals->unkFadeEnd);
    }
    globals->unk_80 = 0;
}

AuResult func_8004E0F4(SongUpdateEvent* update) {
    BGMPlayer* player;
    AuResult status = AU_RESULT_OK;

    if (update->songName != 0) {
        player = au_bgm_get_player_with_song_name(update->songName);
        if (player != NULL) {
            func_80053B04(&player->fadeInfo, update->duration, update->finalVolume);
        }
        else {
            status = AU_ERROR_SONG_NOT_PLAYING;
        }
    } else {
        status = AU_ERROR_NULL_SONG_NAME;
    }
    return status;
}

void au_bgm_player_init(BGMPlayer* player, s32 priority, s32 busId, AuGlobals* globals) {
    s16 i;

    player->globals = globals;
    func_8004E880(player, BGM_SAMPLE_RATE, 48);
    player->busVolume = 0x8000;
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterVolume = 0x7F000000;
    player->updateCounter = 0;
    player->songPlayingCounter = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    player->segmentReadPos = NULL;
    player->segmentStartPos = NULL;
    player->subSegmentStartPos = 0;
    player->masterTempoTime = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
    player->masterVolumeTime = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->masterPitchShift = 0;
    player->detune = 0;
    player->unk_220 = 0;
    player->trackVolsConfig = NULL;
    player->bFadeConfigSetsVolume = FALSE;
    player->masterState = BGM_PLAY_STATE_IDLE;
    player->priority = priority;
    player->busId = busId;
    *(s32*)player->segLoopCounters = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->playbackRate = 1.0f;
    player->unk_22A[0] = 0;
    player->unk_22A[1] = 1;
    player->unk_22A[2] = 0;
    player->unk_22A[3] = 0;
    player->unk_22A[4] = 0;
    player->unk_22A[5] = 2;
    player->unk_22A[6] = 3;
    player->unk_22A[7] = 4;

    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        BGMPlayerTrack* temp = &player->tracks[i];

        temp->subTrackVolume = 0;
        temp->delayTime = 0;
        temp->subTrackCoarseTune = 0;
        temp->subTrackFineTune = 0;
        temp->subTrackPan = 0;
        temp->subTrackReverb = 0;
        temp->patch = 0;
        temp->isDrumTrack = FALSE;
        temp->segTrackVolume = 0x7F;
        temp->unk_4C = 0;

        if (i < ARRAY_COUNT(player->unk_238)) {
            player->unk_238[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(player->notes); i++) {
        SeqNote* note = &player->notes[i];

        note->volume = 0;
        note->adjustedPitch = 0;
        note->noteLength = 0;
        note->unk_14 = 0;
        note->noteVelocity = 0;
        note->unk_note_17 = 0;
    }

    au_fade_set_vol_scale(&player->fadeInfo, 0x7FFF);
    func_80055110(player);
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
    player->fadeInfo.fadeTime--;

    if (player->fadeInfo.fadeTime != 0) {
        player->fadeInfo.curVolume.s32 += player->fadeInfo.fadeStep;
    } else {
        player->fadeInfo.curVolume.s32 = player->fadeInfo.targetVolume << 16;

        if (player->fadeInfo.onCompleteCallback != NULL) {
            player->fadeInfo.onCompleteCallback();
        }

        if (player->fadeSongName != 0) {
            func_8004DC80(player->fadeSongName);
        } else if (player->fadeInfo.curVolume.s32 == 0) {
            au_bgm_stop_player(player);
        }
    }
    func_8004E444(player);
}

void func_8004E444(BGMPlayer* arg0) {
    u16 mult = (arg0->fadeInfo.curVolume.u16 * arg0->fadeInfo.volScale.u16) >> 15;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->effectIndices); i++) {
        s8 busId = arg0->effectIndices[i];

        if (busId < 0) {
            return;
        }
        au_fade_set_volume(busId, mult, arg0->busVolume);
    }
}

s32 au_bgm_player_update_main(BGMPlayer* player) {
    u16 hasMore = TRUE;
    s32 retVal = FALSE;

    // update pseudorandom numbers with fast 'good enough' method
    player->randomValue1 = (u16)player->randomValue1 + (u16)player->songPlayingCounter + (u16)player->updateCounter;
    player->randomValue2 = (u16)player->randomValue2 + ((player->songPlayingCounter << 4) & 0xFFFF) + ((player->updateCounter >> 4) & 0xFFFF);
    do {
        switch (player->masterState) {
        case BGM_PLAY_STATE_IDLE:
            hasMore = FALSE;
            break;
        case BGM_STATE_PLAY_SUBSEG:
            if (player->unk_220 == 0) {
                au_bgm_player_update_playing(player);
                if (player->masterState == BGM_STATE_PLAY_SUBSEG) {
                    hasMore = FALSE;
                }
            } else {
                hasMore = FALSE;
            }
            break;
        case BGM_PLAY_STATE_NEXT_SUBSEG:
            au_bgm_player_read_segment(player);
            break;
        case BGM_PLAY_STATE_INIT:
            au_bgm_player_initialize(player);
            hasMore = FALSE;
            break;
        case BGM_PLAY_STATE_STOP:
            au_bgm_player_update_stop(player);
            break;
        default:
            retVal = TRUE;
            hasMore = FALSE;
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
        track->subTrackVolume = 0x7FFF0000;
        track->subTrackPan = 0x40;
        track->subTrackReverb = 0;
        track->patch = 0;
        track->subTrackCoarseTune = 0;
        track->subTrackFineTune = 0;
        track->segTrackVolume = 0x7F;
        track->unk_4C = 0;
        track->unkVolume = 0x7FFF0000;
        track->savedPos = NULL;
        track->prevReadPos = NULL;
        track->detourLength = 0;
        track->segTrackTune = 0;
        track->trackTremoloTime = 0;
        track->trackTremoloAmount = 0;
        track->trackTremoloSpeed = 0;
        track->subTrackVolumeStep = 0;
        track->subTrackVolumeTarget = 0;
        track->subTrackVolumeTime = 0;
        track->unkVolumeStep = 0;
        track->unkVolumeTarget = 0;
        track->unkVolumeTime = 0;
        track->unk_4D = 0;
        track->unk_4E = 0;
        track->unk_4F = 0;
        track->unk_50 = 0;
        track->unk_51 = 0;
        track->polyphonicIdx = 0;
        track->unk_57 = 0;
        track->isDrumTrack = FALSE;
        track->parentTrackIdx = 0;
        track->unk_5A = 0;
        track->subtrackBusId = player->busId;
        track->index = i;
    }

    for (i = 0; i < ARRAY_COUNT(player->notes); i++) {
        SeqNote* note = &player->notes[i];
        note->ins = NO_INSTRUMENT;
        note->pitchRatio = 2.0f;
        note->unk_14 = 0;
        note->noteVelocity = 0;
        note->noteLength = 0;
        note->tremoloTime = 0;
    }

    func_80050900(player);
    player->playbackRate = 128.0f; // set to 1.0 later om...
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterTempoBPM = BGM_DEFAULT_TEMPO / 100;
    player->unk_21E = 0x80;
    player->masterVolume = 0x7F000000;
    player->fadeSongName = 0;
    player->unk_74 = 0;
    player->masterTempoTarget = 0;
    player->masterPitchShift = 0;
    player->detune = 0;
    player->masterVolumeTime = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->proxMixValue = 0;
    player->proxMixID = 0;
    player->proxMixVolume = 0;
    player->segActiveLoopEndPos[3] = NULL;
    player->segActiveLoopEndPos[2] = NULL;
    player->segActiveLoopEndPos[1] = NULL;
    player->segActiveLoopEndPos[0] = NULL;
    *(s32*)player->segLoopCounters = 0;
    player->segLoopDepth = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->trackVolsConfig = NULL;
    player->bFadeConfigSetsVolume = FALSE;
    player->unk_233 = 1;
    player->unk_211 = 0;
    player->playbackRate = 1.0f;

    for (i = 0; i < ARRAY_COUNT(player->unk_212); i++) {
        func_8004E844(player, i);
    }

    for (i = 0; i < ARRAY_COUNT(player->effectValues); i++) {
        player->effectValues[i] = 0;
    }

    player->unk_220 = 0;
    player->songPlayingCounter = 0;
    for (i = 0; i < ARRAY_COUNT(player->segLoopStartLabels); i++) {
        player->segLoopStartLabels[i] = player->segmentReadPos;
    }

    // find labels
    buf = player->segmentReadPos;
    keepReading = TRUE;
    while (keepReading) {
        cmd = *buf++;
        if (cmd == 0) {
            keepReading = FALSE;
        } else if ((cmd & 0xF0000000) == BGM_SEGMENT_LABEL << 28) {
            player->segLoopStartLabels[cmd & 0x1F] = buf;
        }
    }

    player->masterState = BGM_PLAY_STATE_NEXT_SUBSEG;
}

void func_8004E844(BGMPlayer* player, s32 arg1) {
    s32 i;
    u16* temp = player->unk_174[arg1];
    player->unk_212[arg1] = 0;

    for (i = 0; i < 9; i++) {
        *temp++ = 0xFF00;
    }
}

// divisor is number of ticks per beat?
void func_8004E880(BGMPlayer* player, s32 sampleRate, s32 divisor) {
    u32 A;

    A = 10434782 / (u32)divisor;

    if (A > 500000) {
        A = 500000;
    } else if (A < 80000) {
        A = 80000;
    }
    if (A < sampleRate) {
        sampleRate = A;
    }
    player->nextUpdateStep = sampleRate;
    player->nextUpdateInterval = A;
    player->nextUpdateCounter = A;
    player->maxTempo = A / 1000;
}

// runs whenever a new segment begins playing
void au_bgm_player_read_segment(BGMPlayer* player) {
    u16 continueReading = TRUE;
    u32 cmd;

    player->masterTempoStep = 0;
    player->masterTempoTime = 0;
    while (continueReading) {
        cmd = *player->segmentReadPos++;
        if (cmd == BGM_SEGMENT_END) {
            player->masterState = BGM_PLAY_STATE_STOP;
            continueReading = FALSE;
        } else {
            switch (cmd >> 12) {
                case BGM_SEGMENT_SUBSEG << 16:
                    au_bgm_load_subsegment(player, cmd);
                    player->masterState = BGM_STATE_PLAY_SUBSEG;
                    continueReading = FALSE;
                    break;
                case BGM_SEGMENT_START_LOOP << 16:
                    break;
                case BGM_SEGMENT_WAIT << 16:
                    continueReading = FALSE;
                    break;
                case BGM_SEGMENT_END_LOOP << 16:
                    au_bgm_end_segment_loop(player, cmd);
                    break;
                case BGM_SEGMENT_6 << 16:
                    if (!(player->unk_223 & 1)) {
                        au_bgm_end_segment_loop(player, cmd);
                    }
                    break;
                case BGM_SEGMENT_7 << 16:
                    if (player->unk_223 & 1) {
                        au_bgm_end_segment_loop(player, cmd);
                    }
                    break;
                default:
                    continueReading = FALSE;
                    break;
            }
        }
    }
}

void au_bgm_end_segment_loop(BGMPlayer* player, u32 cmd) {
    s32 labelIndex = cmd & 0x1F; // 01F (bits 0-4)
    s32 iterCount = (cmd >> 5) & 0x7F; // FE0 (bits 5-11)
    u32 depth;

    depth = player->segLoopDepth;
    if (player->segActiveLoopEndPos[depth] != NULL) {
        if (player->segActiveLoopEndPos[depth] == player->segmentReadPos) {
            if (player->segLoopCounters[depth] != 0) {
                player->segLoopCounters[depth]--;
                if ((player->segLoopCounters[depth]) == 0) {
                    player->segActiveLoopEndPos[depth] = NULL;
                    if (depth > 0) {
                        depth--;
                    }
                } else {
                    player->segmentReadPos = player->segLoopStartLabels[labelIndex];
                }
            } else {
                player->segmentReadPos = player->segLoopStartLabels[labelIndex];
            }
        } else if (depth < 4) {
            depth++;
            player->segActiveLoopEndPos[depth] = player->segmentReadPos;
            player->segLoopCounters[depth] = iterCount;
            player->segmentReadPos = player->segLoopStartLabels[labelIndex];
        }
    } else {
        player->segActiveLoopEndPos[depth] = player->segmentReadPos;
        player->segLoopCounters[depth] = iterCount;
        player->segmentReadPos = player->segLoopStartLabels[labelIndex];
    }
    player->segLoopDepth = depth;
}

void au_bgm_load_subsegment(BGMPlayer* player, u32 cmd) {
    BGMPlayerTrack* track;
    u32 trackInfo;
    s32* trackList;
    u32 parentIdx;
    s32 count;
    s32 nextRelativePos;
    s32 bUsesPolyphony;
    s32 i;

    nextRelativePos = 0;
    bUsesPolyphony = FALSE;
    player->subSegmentStartPos = AU_FILE_RELATIVE(player->segmentStartPos, (cmd & 0xFFFF) << 2);
    trackList = player->subSegmentStartPos;
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        trackInfo = *trackList++;
        track->bgmReadPos = (AuFilePos) (trackInfo >> 0x10);
        if (track->bgmReadPos != NULL) {
            if ((trackInfo & 0x100) == 0) {
                track->polyphonicIdx = (trackInfo & (0x7 << 0xD)) >> 0xD;
                track->isDrumTrack = (trackInfo >> 7) & 1;
                parentIdx = (trackInfo & (0xF << 9)) >> 9;
                track->parentTrackIdx = 0;
                if (parentIdx != 0) {
                    BGMPlayerTrack* parentTrack = &player->tracks[parentIdx - 1];
                    if ((parentIdx - 1) < i) {
                        track->unk_51 = parentTrack->unk_51;
                        track->unk_52 = parentTrack->unk_52;
                        track->unk_53 = parentTrack->unk_53;

                        track->bgmReadPos = (track->bgmReadPos + (s32)player->subSegmentStartPos);
                        track->delayTime = 1;

                        track->parentTrackIdx = parentIdx;
                        if (player->unk_233 != 0) {
                            track->unk_5A = 1;
                        }
                        bUsesPolyphony = TRUE;
                    } else {
                        track->bgmReadPos = NULL;
                    }
                } else {
                    count = player->unk_22A[track->polyphonicIdx];
                    track->unk_51 = count;
                    track->unk_52 = nextRelativePos;
                    nextRelativePos += count;
                    track->unk_53 = nextRelativePos;

                    track->bgmReadPos = (track->bgmReadPos + (s32)player->subSegmentStartPos);
                    track->delayTime = 1;
                }
            } else {
                track->bgmReadPos = NULL;
            }
        }
    }
    player->unk_21B = nextRelativePos; // last Voice?
    if (bUsesPolyphony) {
        player->unk_233 = 0;
    }
}

void au_bgm_player_update_stop(BGMPlayer* player) {
    s32 i;

    player->unk_220 = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        player->tracks[i].bgmReadPos = NULL;
    }
    func_80050900(player);
    player->masterState = BGM_PLAY_STATE_IDLE;
    player->nextUpdateStep = BGM_SAMPLE_RATE;
}

#define POST_BGM_READ() \
if (track->detourLength != 0) {\
    track->detourLength--;\
    if (track->detourLength == 0) {\
        track->bgmReadPos = track->savedPos;\
    }\
}

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
    s32 var_a1_5;
    s32 bAcquiredVoiceIdx;
    u8 opcode;
    u8 noteVelocity;
    s32 noteLength;
    u32 i;
    u8 voiceIdx;
    s32 temp2;
    bVolumeFading = FALSE;
    bFinished = FALSE;

    if (player->masterTempoTime != 0) {
        player->masterTempoTime--;
        if (player->masterTempoTime == 0) {
            player->masterTempo = player->masterTempoTarget;
            player->masterTempoTarget = 0;
            player->masterTempoStep = 0;
        } else {
            player->masterTempo += player->masterTempoStep;
        }
        player->nextUpdateStep = player->masterTempo * 10;
    }
    if (player->masterVolumeTime != 0) {
        player->masterVolumeTime--;
        if (player->masterVolumeTime == 0) {
            player->masterVolume = player->masterVolumeTarget;
            player->masterVolumeTarget = 0;
            player->masterVolumeStep = 0;
        } else {
            player->masterVolume += player->masterVolumeStep;
        }
        bVolumeFading = TRUE;
    }
    player->volumeChanged = FALSE;
    if (player->trackVolsConfig != NULL) {
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
                    au_BGMCmd_F6_TrackVolumeFade(player, track);
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
                    au_BGMCmd_F6_TrackVolumeFade(player, track);
                }
            }
        }
        player->trackVolsConfig = NULL;
        player->bFadeConfigSetsVolume = FALSE;
    }
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        if (track->bgmReadPos != NULL) {
            track->changed.all = 0;
            if (bVolumeFading || player->volumeChanged) {
                track->changed.volume = 1;
            } else {
                track->changed.volume = 0;
            }
            if (track->subTrackVolumeTime != 0) {
                track->subTrackVolumeTime--;
                if (track->subTrackVolumeTime == 0) {
                    track->subTrackVolume = track->subTrackVolumeTarget;
                } else {
                    track->subTrackVolume += track->subTrackVolumeStep;
                }
                track->changed.volume = 1;
            }
            if (track->unkVolumeTime != 0) {
                track->unkVolumeTime--;
                if (track->unkVolumeTime == 0) {
                    track->unkVolume = track->unkVolumeTarget << 0x10;
                } else {
                    track->unkVolume += track->unkVolumeStep;
                }
                track->changed.volume = 1;
            }
            track->delayTime--;
            if (track->delayTime <= 0) {
                sp1F = track->unk_52;
                while (track->delayTime == 0) {
                    opcode = *(track->bgmReadPos++);
                    POST_BGM_READ();

                    if (opcode < 0x80) {
                        if (opcode == 0) {
                            if (track->prevReadPos != 0) {
                                track->bgmReadPos = track->prevReadPos;
                                track->prevReadPos = 0;
                            } else {
                                bFinished = TRUE;
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
                            bAcquiredVoiceIdx = FALSE;
                            if (track->unk_5A == 0) {
                                // find first free voice
                                for (voiceIdx = sp1F; voiceIdx < track->unk_53; voiceIdx++) {
                                    voice = &player->globals->voices[voiceIdx];
                                    sp1F++;
                                    if (voice->priority == AU_PRIORITY_FREE) {
                                        bAcquiredVoiceIdx = TRUE;
                                        break;
                                    }
                                }

                                if (!bAcquiredVoiceIdx) {
                                    if (track->polyphonicIdx >= 5) { // 5 = AL_DEFAULT_PRIORITY?
                                        // try stealing a voice with lower priority
                                        for (voiceIdx = track->unk_52; voiceIdx < track->unk_53; voiceIdx++) {
                                            voice = &player->globals->voices[voiceIdx];
                                            if (voice->priority < player->priority) {
                                                au_reset_voice(voice, voiceIdx);
                                                bAcquiredVoiceIdx = TRUE;
                                                break;
                                            }
                                        }
                                        // try stealing a voice with equal priority and zero note length
                                        if (!bAcquiredVoiceIdx) {
                                            for (voiceIdx = track->unk_52; voiceIdx < track->unk_53; voiceIdx++) {
                                                voice = &player->globals->voices[voiceIdx];
                                                if (voice->priority == player->priority) {
                                                    note = &player->notes[voiceIdx];
                                                    if (note->noteLength == 0) {
                                                        au_reset_voice(voice, voiceIdx);
                                                        bAcquiredVoiceIdx = TRUE;
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
                                            for (voice_it = track->unk_52; voice_it < track->unk_53; voice_it++) {
                                                curVoice = &player->globals->voices[voice_it];
                                                if (curVoice->priority == player->priority) {
                                                    curNote = &player->notes[voice_it];
                                                    if (curNote->unk_note_17 == 0 && curNote->noteLength < shortestLength) {
                                                        shortestLength = curNote->noteLength;
                                                        voice = curVoice;
                                                        note = curNote;
                                                        voiceIdx = voice_it;
                                                        bAcquiredVoiceIdx = TRUE;
                                                    }
                                                }
                                            }
                                            if (bAcquiredVoiceIdx) {
                                                note->noteLength = 0;
                                                au_reset_voice(voice, voiceIdx);
                                            }
                                        }

                                    } else {
                                        voiceIdx = track->unk_52;
                                        voice = &player->globals->voices[voiceIdx];
                                        note = &player->notes[voiceIdx];
                                        note->noteLength = 0;
                                        if (voice->priority <= player->priority) {
                                            au_reset_voice(voice, voiceIdx);
                                            bAcquiredVoiceIdx = TRUE;
                                        }
                                    }
                                }
                            }
                            if (bAcquiredVoiceIdx) {
                                note = &player->notes[voiceIdx];
                                note->tremoloTime = 0;
                                if (noteVelocity > 0) {
                                    note->noteVelocity = noteVelocity + 1;
                                } else {
                                    note->noteVelocity = 0;
                                }
                                note->noteLength = noteLength;
                                if (track->isDrumTrack) {
                                    if (notePitch < 72) { // = 6 * 12
                                        drumInfo = &player->globals->dataPER->drums[notePitch];
                                    } else {
                                        drumInfo = player->drums[notePitch - 72]; // = 6 * 12
                                    }
                                    note->ins = au_get_instrument(player->globals, (u16)drumInfo->bankPatch >> 8, (u16)drumInfo->bankPatch & 0xFF, &voice->envelope);
                                    if (drumInfo->randVolume != 0) {
                                        note->volume = note->noteVelocity * au_bgm_get_random_vol(player->randomValue1, drumInfo->volume, drumInfo->randVolume);
                                    } else {
                                        note->volume = note->noteVelocity * drumInfo->volume;
                                    }
                                    voice->clientVolume = ((
                                        ((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15) * (track->unkVolume >> 0x15)) >> 0x14)
                                        * (track->segTrackVolume * note->volume)) >> 0x10;
                                    note->adjustedPitch =
                                        drumInfo->keyBase
                                        + track->subTrackCoarseTune
                                        + track->subTrackFineTune
                                        - note->ins->keyBase;
                                    temp = (note->adjustedPitch + track->segTrackTune) + player->detune;
                                    if (drumInfo->randTune != 0) {
                                        note->unk_14 = au_bgm_get_random_pitch(player->randomValue1, temp, drumInfo->randTune);
                                        temp = note->unk_14;
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
                                    note->volume = ((
                                        ((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15) * (track->unkVolume >> 0x15)) >> 0x14)
                                        * (track->segTrackVolume * note->noteVelocity)) >> 9;
                                    voice->clientVolume = note->volume;
                                    note->ins = track->instrument;
                                    note->adjustedPitch =
                                        (notePitch * 100)
                                        + track->subTrackCoarseTune
                                        + player->masterPitchShift
                                        + track->subTrackFineTune
                                        - note->ins->keyBase;
                                    note->pitchRatio = au_compute_pitch_ratio(
                                        note->adjustedPitch
                                        + track->segTrackTune
                                        + player->detune)
                                        * track->instrument->pitchRatio;

                                    if (track->unk_57 != 0) {
                                        voice->pan = au_bgm_get_random_pan(player, track->subTrackPan, track->unk_57);
                                    } else {
                                        voice->pan = track->subTrackPan;
                                    }
                                    voice->reverb = track->subTrackReverb;

                                    if (track->unk_4C != 0) {
                                        voice->envelope.cmdListPress = (u8*) player->unk_174[track->unk_4C - 1]; //TODO ???
                                    } else {
                                        voice->envelope.cmdListPress = track->envelope.cmdListPress;
                                    }
                                    voice->envelope.cmdListRelease = track->envelope.cmdListRelease;
                                }
                                voice->instrument = note->ins;
                                voice->pitchRatio = note->pitchRatio;
                                voice->busId = track->subtrackBusId;
                                if (note->noteLength >= 2) {
                                    note->unk_note_17 = 1;
                                    note->tremoloTime = track->trackTremoloTime;
                                    note->unk_13 = 0;
                                    note->tremoloAmount = track->trackTremoloAmount;
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

            for (voiceIdx = track->unk_52; voiceIdx < track->unk_53; voiceIdx++) {
                if (track->unk_5A == 0) {
                    voice = &player->globals->voices[voiceIdx];
                    if (voice->priority == player->priority) {
                        note = &player->notes[voiceIdx];
                        if (note->unk_note_17 == 0) {
                            if (note->noteLength > 0) {
                                note->noteLength--;
                                if (note->noteLength == 0) {
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                }
                            }
                            if (track->isDrumTrack) {
                                if (track->changed.tune || (player->detune != 0)) {
                                    note->pitchRatio = au_compute_pitch_ratio(((note->adjustedPitch + note->unk_14) + track->segTrackTune) + player->detune) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                    }
                                }
                                if (track->changed.volume) {
                                    voice->clientVolume = (
                                        ((((player->masterVolume >> 0x15)
                                        * (track->subTrackVolume >> 0x15))
                                        * (track->unkVolume >> 0x15)) >> 0x14)
                                        * (track->segTrackVolume * note->volume)) >> 0x10;
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                }
                            } else {
                                if (note->tremoloTime != 0) {
                                    if (note->tremoloAmount != 0) {
                                        note->tremoloAmount--;
                                    } else {
                                        u8 temp_a0_6;
                                        u8 temp_a2_4;
                                        note->unk_13 += track->trackTremoloSpeed;
                                        opcode = (note->unk_13 << 2) + 3;
                                        temp_a2_4 = note->unk_13 >> 6;

                                        if ((temp_a2_4 == 1) || (temp_a2_4 == 3)) {
                                            u8 temp2 = ~opcode;
                                            var_a1_5 = temp2 + 1;
                                        } else {
                                            var_a1_5 = opcode;
                                        }

                                        var_a1_5 = (var_a1_5 * track->trackTremoloTime) >> 8;

                                        if ((temp_a2_4 == 2) || (temp_a2_4 == 3)) {
                                            var_a1_5 = -var_a1_5;
                                        }

                                        note->pitchRatio = au_compute_pitch_ratio(var_a1_5 + ((note->adjustedPitch + track->segTrackTune) + player->detune)) * note->ins->pitchRatio;
                                        if (voice->pitchRatio != note->pitchRatio) {
                                            voice->pitchRatio = note->pitchRatio;
                                            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                        }
                                    }
                                } else if (track->changed.tune || (player->detune != 0)) {

                                    note->pitchRatio = au_compute_pitch_ratio((note->adjustedPitch + track->segTrackTune) + player->detune) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                    }
                                }
                                if (track->changed.volume) {
                                    s32 tempVolume = ((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15) * (track->unkVolume >> 0x15)) >> 0x14;
                                    note->volume = (tempVolume * (track->segTrackVolume * note->noteVelocity)) >> 9;
                                    voice->clientVolume = note->volume;
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                    voice->pan = track->subTrackPan;
                                    voice->reverb = track->subTrackReverb;
                                } else if (track->changed.pan || track->changed.reverb) {
                                    voice->pan = track->subTrackPan;
                                    voice->reverb = track->subTrackReverb;
                                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
                                }
                            }
                        }
                        note->unk_note_17 = 0;
                    }
                }
            }
        }
    }

    if (bFinished) {
        player->masterState = BGM_PLAY_STATE_NEXT_SUBSEG;
    }
}

static const f32 padding[] = {0.0f}; // at least after func_8004E4B8

void au_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 bpm = player->seqCmdArgs.MasterTempo.value;
    s32 tempo;

    player->masterTempoBPM = bpm;
    tempo = snd_bpm_to_tempo(player, bpm);
    player->masterTempo = tempo;
    player->nextUpdateStep = tempo * 10;
    player->masterTempoTime = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
}

static s32 snd_bpm_to_tempo(BGMPlayer* player, u32 tempo) {
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
    s32 volume = player->seqCmdArgs.MasterVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    player->masterVolume = volume;
    player->masterVolumeTime = 0;
    player->masterVolumeTarget = 0;
    player->masterVolumeStep = 0;
    player->volumeChanged = TRUE;
    track->changed.volume = TRUE;
}

void au_BGMCmd_E2_MasterPitchShift(BGMPlayer* player, BGMPlayerTrack* track) {
    player->masterPitchShift = (s8)player->seqCmdArgs.MasterPitchShift.cent * 100;
}

void au_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->globals->effectChanges[player->busId].type = player->seqCmdArgs.UnkCmdE3.effectType;
    player->globals->effectChanges[player->busId].changed = TRUE;
}

void au_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.MasterEffect.index;
    u32 busId = player->effectIndices[index];

    if ((index < 4) && (busId < 0x80)) {
        if (player->globals->effectChanges[busId].type != player->seqCmdArgs.MasterEffect.value) {
            player->globals->effectChanges[busId].type = player->seqCmdArgs.MasterEffect.value;
            player->globals->effectChanges[busId].changed = TRUE;
        }
        player->effectValues[index] = player->seqCmdArgs.MasterEffect.value;
    }
}

void au_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterTempoFade.time;
    s32 tempo = snd_bpm_to_tempo(player, player->seqCmdArgs.MasterTempoFade.value);

    if (time <= 0) {
        time = 1;
    }

    player->masterTempoTime = time;
    player->masterTempoTarget = tempo;
    player->masterTempoStep = (tempo - player->masterTempo) / time;
}

void au_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterVolumeFade.time;
    s32 volume = player->seqCmdArgs.MasterVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (time <= 0) {
        time = 1;
    }

    player->masterVolumeTime = time;
    player->masterVolumeTarget = volume;
    player->masterVolumeStep = (volume - player->masterVolume) / time;
}

void au_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, BGMPlayerTrack* track) {
    track->patch = player->seqCmdArgs.TrackOverridePatch.patch;
    track->instrument = au_get_instrument(player->globals, player->seqCmdArgs.TrackOverridePatch.bank, track->patch, &track->envelope);
}

void au_BGMCmd_E9_SubTrackVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    u32 volume = arg0->seqCmdArgs.SubTrackVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    track->subTrackVolume = volume;
    track->changed.volume = TRUE;
}

void au_BGMCmd_F6_TrackVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.TrackVolumeFade.time;
    s32 volume = player->seqCmdArgs.TrackVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (volume != track->subTrackVolume) {
        if (time <= 0) {
            time = 1;
        }

        track->subTrackVolumeTime = time;
        track->subTrackVolumeTarget = volume;
        track->subTrackVolumeStep = (volume - track->subTrackVolume) / time;
    }
}

void au_BGMCmd_EA_SubTrackPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.SubTrackPan.value & 0x7F;
    track->unk_57 = 0;
    track->changed.pan = TRUE;
}

void au_BGMCmd_EB_SubTrackReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackReverb = player->seqCmdArgs.SubTrackReverb.value & 0x7F;
    track->changed.reverb = TRUE;
}

void au_BGMCmd_EC_SegTrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackVolume = player->seqCmdArgs.SegTrackVolume.value & 0x7F;
    track->changed.volume = TRUE;
}

void au_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackCoarseTune = (s8)player->seqCmdArgs.SubTrackCoarseTune.cent * 100;
}

void au_BGMCmd_EE_SubTrackFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackFineTune = player->seqCmdArgs.SubTrackFineTune.value;
}

void au_BGMCmd_EF_SegTrackTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackTune = player->seqCmdArgs.SegTrackTune.value;
    track->changed.tune = TRUE;
}

void au_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloAmount = player->seqCmdArgs.TrackTremolo.amount;
    track->trackTremoloSpeed = player->seqCmdArgs.TrackTremolo.speed;
    track->trackTremoloTime = player->seqCmdArgs.TrackTremolo.time;
}

void au_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloSpeed = player->seqCmdArgs.TrackTremoloSpeed.value;
}

void au_BGMCmd_F2_TrackTremoloTime(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = player->seqCmdArgs.TrackTremoloTime.time;
}

void au_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = 0;
}

void au_BGMCmd_F4(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.UnkCmdF4.pan0 & 0x7F;
    track->unk_57 = player->seqCmdArgs.UnkCmdF4.pan1 & 0x7F;
}

void au_BGMCmd_F5_TrackVoice(BGMPlayer* player, BGMPlayerTrack* track) {
    BGMInstrumentInfo* instrument;
    s32 volume;
    u32 voiceIndex;
    u32 patch;
    u32 bank;

    voiceIndex = player->seqCmdArgs.SetTrackVoice.index;
    if (voiceIndex < 0x80) {
        if (voiceIndex < player->bgmInstrumentCount) {
            instrument = &player->instrumentsInfo[voiceIndex];
        } else {
            instrument = &player->globals->defaultPRGEntry;
        }
    } else {
        voiceIndex -= 0x80;
        if (voiceIndex < 0x40) {
            instrument = &player->globals->dataPRG[voiceIndex];
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
        volume <<= 0x18;
    }
    track->subTrackVolume = volume;
    track->subTrackPan = instrument->pan & 0x7F;
    track->subTrackReverb = instrument->reverb & 0x7F;
    track->subTrackCoarseTune = instrument->coarseTune * 100;
    track->subTrackFineTune = instrument->fineTune;
    track->changed.all |= 0x10101;
}

void au_BGMCmd_F7_SubTrackReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.SubTrackReverbType.index;
    s8 busId = player->effectIndices[index];

    if ((index < 4) && (busId >= 0)) {
        track->subtrackBusId = busId;
    } else {
        track->subtrackBusId = player->busId;
    }
}

void au_BGMCmd_FD_EventTrigger(BGMPlayer* player, BGMPlayerTrack* track) {
    bgm_trigger_music_event(player->priority, track->index, player->seqCmdArgs.EventTrigger.eventInfo >> 8);
}

// jump to another part of the track and return after a specified read length
void au_BGMCmd_FE_Detour(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos readPos = AU_FILE_RELATIVE(player->bgmFile, player->seqCmdArgs.Detour.offset);

    track->detourLength = player->seqCmdArgs.Detour.length;
    track->savedPos = track->bgmReadPos;
    track->bgmReadPos = readPos;
}

// jump to another part of the track, switched by player->proxMixID
void au_BGMCmd_FC_Jump(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos args;
    u32 i;

    // get jump table
    args = AU_FILE_RELATIVE(player->bgmFile, player->seqCmdArgs.Jump.unk_00);
    if (player->proxMixID < player->seqCmdArgs.Jump.unk_02) {
        args += player->proxMixID * 3;
    }
    // read new position from jump table
    track->prevReadPos = track->bgmReadPos;
    track->bgmReadPos = AU_FILE_RELATIVE(player->bgmFile, (args[0] << 8) + args[1]);
    track->isDrumTrack = args[2];

    if (track->unk_4D != 0) {
        track->unk_4D = 0;
        track->unkVolume = 0;
        for (i = track->unk_52; i < track->unk_53; i++) {
            AuVoice* voice = &player->globals->voices[i];
            if ((voice->priority == player->priority) && (voice->cmdPtr != NULL)) {
                au_reset_voice(voice, i);
            }
        }
    }
    if (track->unk_4E != 0) {
        track->unk_4E = 0;
        func_80050888(player, track, player->proxMixVolume, 144);
    }
    track->subTrackCoarseTune = 0;
    track->subTrackFineTune = 0;
    track->unk_4C = 0;
    track->segTrackTune = 0;
    track->trackTremoloTime = 0;
    track->subTrackVolumeTime = 0;
    track->unk_57 = 0;
    track->subtrackBusId = player->busId;
}

void au_BGMCmd_FF(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 i;
    u32 j;
    u8 temp_a1;
    u8 temp_a3;

    u32 arg0 = player->seqCmdArgs.UnkCmdFF.unk_00;
    u32 arg1 = player->seqCmdArgs.UnkCmdFF.unk_01;
    u32 arg2 = player->seqCmdArgs.UnkCmdFF.unk_02;

    switch (arg0) {
        case 1:
            if ((arg1 < ARRAY_COUNT(player->effectIndices)) && ((s8)player->effectIndices[arg1] >= 0)) {
                player->globals->channelDelayBusId = player->effectIndices[arg1];
                if (arg2 != 0) {
                    temp_a3 = arg2 & 0xF;
                    temp_a1 = ((arg2 >> 4) & 1) + 1;
                    if ((player->globals->channelDelayTime != temp_a3) || (player->globals->channelDelaySide != temp_a1)) {
                        player->globals->channelDelayTime = temp_a3;
                        player->globals->channelDelaySide = temp_a1;
                        player->globals->channelDelayPending = 1;
                    }
                } else {
                    if (player->globals->channelDelaySide != 0) {
                        player->globals->channelDelaySide = 0;
                        player->globals->channelDelayPending = 1;
                    }
                }
            }
            break;
        case 2:
            if (arg1 - 1 < 8) {
                player->unk_211 = arg1;
                func_8004E844(player, arg1 - 1);
            } else {
                player->unk_211 = 0;
            }
            break;
        case 3:
            i = player->unk_211;
            if (i - 1 < 8) {
                i = i - 1; // needed to match
                j = player->unk_212[i];
                if (j < 8) {
                    if (arg1 >= 40) {
                        player->unk_174[i][j] = (arg1 << 8) + arg2;
                    } else {
                        player->unk_174[i][j] = (D_80078558[arg1] << 8) + arg2;
                    }
                    player->unk_212[i] = j + 1;
                }
            }
            break;
        case 4:
            if (arg1 < 9) {
                track->unk_4C = arg1;
            } else {
                track->unk_4C = 0;
            }
            break;
        case 5:
            if (player->soundManager != NULL) {
                for (i = 0; i < ARRAY_COUNT(player->soundManager->bgmSounds); i++) {
                    if ((player->soundManager->bgmSounds[i].unk_0) == 0) {
                        player->soundManager->bgmSounds[i].unk_0 = arg1;
                        player->soundManager->bgmSounds[i].volume = ((player->fadeInfo.curVolume.u16 * player->fadeInfo.volScale.u16) + 0x7FFF) >> 0x17;
                        break;
                    }
                }
            }
            break;
        case 6:
            if (arg1 == 0) {
                if (track->unk_4E != 0) {
                    track->unk_4E = 0;
                    for (i = 0; i < 16; i++) {
                        BGMPlayerTrack* otherTrack = &player->tracks[i];
                        if (player->proxMixVolume == 0x7F) {
                            if (otherTrack->unk_4F != 0) {
                                otherTrack->unk_4E = 0;
                                func_80050888(player, otherTrack, otherTrack->unk_4F, 72);
                            }
                        } else {
                            if (otherTrack->unk_50 != 0) {
                                otherTrack->unk_4E = 0;
                                func_80050888(player, otherTrack, otherTrack->unk_50, 72);
                            }
                        }
                    }
                }
            } else {
                track->unk_4F = arg1;
                track->unk_50 = arg2;
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
    if (retPan < 0) {
        retPan = 0;
    } else if (retPan >= 0x80) {
        retPan = 0x7F;
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
    s32 changed = FALSE;
    u8 mixID = mix & 0xFF;
    s32 i;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if ((player != NULL) && (player->proxMixValue != mix)) {
            player->proxMixValue = mix;
            if (player->proxMixID != mixID) {
                player->proxMixID = mixID;
                changed = TRUE;
            }
            player->proxMixVolume = (mix >> 0x18) & 0x7F;
            for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                track = &player->tracks[i];
                if (changed) {
                    track->unk_4D = 1;
                }
                track->unk_4E = 1;
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
    player->masterTempo = snd_bpm_to_tempo(player, player->masterTempoBPM);
    player->nextUpdateStep = player->masterTempo * 10;
    player->masterTempoTime = 0;
    player->masterTempoTarget = 0;
    player->masterTempoStep = 0;
}

void au_bgm_player_set_detune(BGMPlayer* player, s32 detune) {
    if (detune > 1200) {
        detune = 1200;
    } else if (detune < -2400) {
        detune = -2400;
    }

    player->detune = detune;
}

void au_bgm_change_track_volume(BGMPlayer* player, s32 trackIdx, s16 time, u8 volume) {
    BGMPlayerTrack* track = &player->tracks[trackIdx];

    if (track->bgmReadPos != 0) {
        player->seqCmdArgs.TrackVolumeFade.time = time;
        player->seqCmdArgs.TrackVolumeFade.value = volume;
        au_BGMCmd_F6_TrackVolumeFade(player, track);
    }
}

void au_bgm_set_track_volumes(BGMPlayer* player, u8* trackVols, s32 mode) {
    player->trackVolsConfig = trackVols;
    player->bFadeConfigSetsVolume = mode;
}

void func_80050888(BGMPlayer* player, BGMPlayerTrack* track, s32 target, s32 duration) {
    if (target != 0) {
        target = (target << 8) | 0xFF;
    }
    if (duration <= 0) {
        duration = 1;
    } else if (duration > 1000) {
        duration = 1000;
    }
    if (target == track->unkVolume) {
        track->unkVolumeTime = 0;
        return;
    }
    track->unkVolumeTime = duration;
    track->unkVolumeTarget = target;
    track->unkVolumeStep = ((target << 0x10) - track->unkVolume) / duration;
}

void func_80050900(BGMPlayer* player) {
    u8 i;

    for (i = 0; i < ARRAY_COUNT(player->globals->voices); i++) {
        AuVoice* voice = &player->globals->voices[i];
        if (voice->priority == player->priority) {
            au_reset_voice(voice, i);
        }
    }
}

AuResult func_80050970(SongUpdateEvent* update) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    BGMPlayerTrack* parentTrack;
    AuVoice* voice;
    s32 i;
    s32 j;
    s8 oldVolume;

    s32 songName = update->songName;
    s32 variation = update->variation;
    AuResult status = AU_RESULT_OK;

    if (songName != 0) {
        player = au_bgm_get_player_with_song_name(songName);
        if (player != NULL) {
            for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                track = &player->tracks[i];
                if (track->bgmReadPos != NULL) {
                    if (track->parentTrackIdx != 0) {
                        parentTrack = &player->tracks[track->parentTrackIdx - 1];
                        if (variation != 0) {
                            if (track->unk_5A != 0) {
                                track->unk_5A = 0;
                                parentTrack->unk_5A = 1;
                                for (j = parentTrack->unk_52; j < parentTrack->unk_53; j++) {
                                    voice = &player->globals->voices[j];
                                    if (voice->priority == player->priority) {
                                        voice->envelope.cmdListRelease = EnvelopeReleaseDefaultFast;
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                    }
                                }
                                oldVolume = track->subTrackVolume >> 24;
                                au_BGMCmd_E9_SubTrackVolume(player, track);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                au_BGMCmd_F6_TrackVolumeFade(player, track);
                            }
                        } else {
                            if (track->unk_5A == 0) {
                                track->unk_5A = 1;
                                parentTrack->unk_5A = 0;
                                for (j = track->unk_52; j < track->unk_53; j++) {
                                    voice = &player->globals->voices[j];
                                    if (voice->priority == player->priority) {
                                        voice->envelope.cmdListRelease = EnvelopeReleaseDefaultFast;
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                    }
                                }
                                oldVolume = parentTrack->subTrackVolume >> 24;
                                au_BGMCmd_E9_SubTrackVolume(player, parentTrack);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                au_BGMCmd_F6_TrackVolumeFade(player, parentTrack);
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
