#include "audio.h"

extern s32 D_80078554;
extern u8 BgmDivisors[8];
extern u8 D_80078558[40];

extern void (*CurrentSeqCmdHandler)(BGMPlayer*, BGMPlayerTrack*);
extern void (*SefCmdHandlers[])(SoundManager*, SoundPlayer*);
extern void (*SeqCmdHandlers[])(BGMPlayer*, BGMPlayerTrack*);
extern u8 SeqCmdArgCounts[];

void func_8004D510(BGMPlayer* player) {
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
    player->unk_14++;

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
                    player->masterState = BGM_PLAY_STATE_3;
                    player->unkFrequency = BGM_SAMPLE_RATE;
                    if (unkType == 2) {
                        bgmFile = (BGMHeader*) player->globals->currentTrackData[1];
                    } else {
                        bgmFile = (BGMHeader*) player->globals->currentTrackData[0];
                    }
                    player->bgmFile = (BGMHeader*) bgmFile;
                    bgmData = &bgmFile->info;
                    func_8004E880(player, BGM_SAMPLE_RATE, BgmDivisors[((u8*)player->unk_74)[0] & 7]); //TODO revise unk_74 typing

                    segmentOffset = bgmData->segments[segmentID];
                    if (segmentOffset == 0) {
                        segmentOffset = bgmData->segments[0];
                    }
                    player->segmentStartPos = (SegData*)((segmentOffset * 4) + (s32)bgmFile);
                    player->segmentReadPos = (SegData*)((segmentOffset * 4) + (s32)bgmFile);

                    if (bgmData->drums != 0) {
                        player->drumsInfo = (BGMDrumInfo*)((bgmData->drums * 4) + (s32)player->bgmFile);
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
                        player->instrumentsInfo = (BGMInstrumentInfo*)((bgmData->instruments * 4) + (s32)player->bgmFile);
                        player->bgmInstrumentCount = bgmData->instrumentCount;
                        return;
                    }
                    player->instrumentsInfo = NULL;
                    player->bgmInstrumentCount = 0;
                }
            } else {
                if (player->unk_58 != 0) {
                    player->masterState = BGM_PLAY_STATE_4;
                    player->unk_10 = 1;
                    player->unkFrequency = 1;
                } else {
                    func_8004DAA8(player);
                }
            }
        }
    }
}


// Return values are being pushed into v0 in the wrong place
// May depend on data decomp
#ifdef NON_EQUIVALENT
BGMPlayer* snd_get_player_with_song_name(s32 songString) {
    SndGlobals* temp_v1 = gBGMPlayerA->data;

    if (songString == temp_v1->currentTrackData[0][2]) {
        return gBGMPlayerA;
    }
    if (songString == temp_v1->currentTrackData[1][2]) {
        return gBGMPlayerB;
    }
    return NULL;
}
#else
INCLUDE_ASM(BGMPlayer*, "audio/28910_len_5090", snd_get_player_with_song_name, s32 songString);
#endif

s32 snd_dispatch_bgm_player_event(SongUpdateEvent* event) {
    BGMPlayer* player;
    BGMFileInfo* fileInfo;
    s32 songName;
    s32 variation;
    s32 duration;
    s32 volume0;
    s32 volume1;
    s32 error;
    u32 i;

    error = MUSIC_ERROR_NONE;
    songName = event->songName;
    variation = event->variation;
    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
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
            if (volume0 >= 0x80) {
                volume0 = 0x7F;
            }
            if (volume0 != 0) {
                volume0 = (volume0 << 8) | 0xFF;
            }
            volume1 = event->finalVolume;
            if (volume1 >= 0x80) {
                volume1 = 0x7F;
            }
            if (volume1 != 0) {
                volume1 = (volume1 << 8) | 0xFF;
            } else {
                volume1 = 0x7FFF;
            }

            snd_initialize_bgm_fade(&player->fadeInfo, duration, volume0, volume1);
            player->fadeInfo.targetVolScale = 0x7FFF;
            player->fadeInfo.volScaleTime = 1;
            func_8004E880(player, BGM_SAMPLE_RATE, BgmDivisors[fileInfo->numSegments & 7]);

            if (variation < 0 || variation >= 4 || fileInfo->segments[variation] == 0) {
                variation = 0;
            }
            player->curSegmentID = variation;

            player->segmentStartPos = (SegData*)(4 * fileInfo->segments[variation] + (s32)player->bgmFile);
            player->segmentReadPos = player->segmentStartPos;

            if (fileInfo->drums != 0) {
                player->drumsInfo = (BGMDrumInfo*)(4 * fileInfo->drums + (s32)player->bgmFile);
                player->bgmDrumCount = fileInfo->drumCount;

                for (i = 0; i < player->bgmDrumCount; i++) {
                    BGMDrumInfo* drum = &player->drumsInfo[i];
                    player->drums[i] = drum;
                }
                for (; i < ARRAY_COUNT(player->drums); i++) {
                    player->drums[i] = player->drums[0];
                }
            } else {
                player->drumsInfo = 0;
                player->bgmDrumCount = 0;
            }
            if (fileInfo->instruments != 0) {
                player->instrumentsInfo = (BGMInstrumentInfo*)(4 * fileInfo->instruments + (s32)player->bgmFile);
                player->bgmInstrumentCount = fileInfo->instrumentCount;
            } else {
                player->instrumentsInfo = 0;
                player->bgmInstrumentCount = 0;
            }
            player->songName = songName;
            snd_initialize_bgm_player(player);
        } else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }
    return error;
}

MusicError func_8004DA0C(s32 songName) {
    BGMPlayer* player;
    s32 error = MUSIC_ERROR_NONE;

    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
        if (player != NULL) {
            if (songName == player->songName) {
                func_8004DAA8(player);
            }
        } else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }

    return error;
}

void func_8004DA74(void) {
    func_8004DAA8(gBGMPlayerA);
    func_8004DAA8(gBGMPlayerB);
}

void func_8004DAA8(BGMPlayer* player) {
    if (player->masterState != BGM_PLAY_STATE_0) {
        player->masterState = BGM_PLAY_STATE_4;
        player->unk_10 = 1;
        player->unkFrequency = 1;
        snd_clear_bgm_fade(&player->fadeInfo);
    }
}

MusicError snd_is_song_playing(s32 songName) {
    BGMPlayer* player;
    s32 error = MUSIC_ERROR_NONE;

    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
        if (player != NULL) {
            error = (songName == player->songName);
        } else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }

    return error;
}

s32 func_8004DB28(BGMPlayer* player) {
    if (player->songName != NULL && player->masterState != 0) {
        return 1;
    } else {
        return 0;
    }
}

MusicError func_8004DB4C(SongUpdateEvent* s) {
    BGMPlayer* player;
    u32 songName = s->songName;
    u32 duration = s->duration;
    s16 volume = s->finalVolume;
    s32 error = MUSIC_ERROR_NONE;
    if (songName != 0) {
        if (duration >= SND_MIN_DURATION && duration <= SND_MAX_DURATION) {
            player = snd_get_player_with_song_name(songName);
            if (player != NULL) {
                if (player->songName == songName) {
                    if (player->masterState != BGM_PLAY_STATE_0) {
                        if (player->unk_220 == 0) {
                            player->fadeInfo.targetVolume = volume;
                            player->fadeInfo.fadeTime = (duration * 1000) / 5750;
                            player->fadeInfo.fadeStep = ((volume << 0x10) - player->fadeInfo.currentVolume.s32) / player->fadeInfo.fadeTime;
                            player->fadeInfo.onCompleteCallback = (void (*)()) s->variation; //TODO seems wrong
                            if (s->unk14 == 1) {
                                player->fadeSongName = songName;
                            }
                        }
                    }
                }
            } else {
                error = MUSIC_ERROR_2;
            }
        } else {
            error = MUSIC_ERROR_4;
        }
    } else {
        error = MUSIC_ERROR_3;
    }
    return error;
}

MusicError func_8004DC80(s32 songName) {
    SongUpdateEvent s;

    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 0);
}

MusicError func_8004DCB8(SongUpdateEvent* update, s32 clearChanged) {
    BGMPlayer* playerA;
    BGMPlayer* playerB;
    s32 songName;
    s32 variation;
    u32 i;
    u32 j;
    s32 error;

    songName = update->songName;
    variation = update->variation;
    error = MUSIC_ERROR_NONE;

    if (songName != 0) {
        playerA = snd_get_player_with_song_name(songName);
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
                        playerA->globals->unk_globals_6C[variation].unk_5 = playerA->unk_234;
                        playerA->globals->unk_globals_6C[variation].unk_4 = 1;
                        playerA->fadeSongName = 0;
                        snd_copy_words(playerA, playerB, sizeof(*playerA));
                        if (clearChanged == 0) {
                            func_8004DAA8(playerA);
                        }
                    }
                } else {
                    error = MUSIC_ERROR_4;
                }
            } else {
                if (songName == playerA->songName) {
                    if (playerA->masterState != BGM_PLAY_STATE_0) {
                        playerA->unk_220 = 1;
                        func_80050900(playerA);
                    }
                }
            }
        } else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }
    return error;
}

MusicError func_8004DE2C(SongUpdateEvent* update) {
    BGMPlayer* playerA;
    BGMPlayer* playerB;
    s32 variation;
    s32 songName;
    s32 volume0;
    s32 volume1;
    s32 duration;
    s32 error;

    songName = update->songName;
    variation = update->variation;
    error = MUSIC_ERROR_NONE;

    if (songName != 0) {
        if (update->unk14 == 0) {
            playerA = func_80053F64(variation);
            if (playerA != NULL && playerA->globals->unk_globals_6C[variation].unk_4 == 1) {
                playerB = func_80054248(playerA->globals->unk_globals_6C[variation].unk_5);
                if (playerB != NULL) {
                    if (func_8004DB28(playerB) == 0) {
                        error = func_80053E58(playerA->songID, (u8*)playerA->bgmFile);
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
                        error = MUSIC_ERROR_7;
                    }
                } else {
                    error = MUSIC_ERROR_6;
                }
            } else {
               error = MUSIC_ERROR_4;
            }
        } else {
            playerB = snd_get_player_with_song_name(songName);
            if (playerB != NULL) {
                if (songName == playerB->songName) {
                    if (playerB->unk_220 != 0) {
                        playerB->unk_220 = 0;
                    }
                }
            }
        }
    } else {
        error = MUSIC_ERROR_3;
    }
    return error;
}

void func_8004DFD4(AuGlobals* globals) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    SeqNote* note;
    u32 i;
    u32 j;
    s32 k;

    player = globals->unk_74;
    snd_copy_words(globals->unk_78, player, sizeof(*player));
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
                snd_BGMCmd_E6_MasterEffect(player, track);
            }
        }
        snd_initialize_bgm_fade(&player->fadeInfo, globals->unkFadeTime, globals->unkFadeStart, globals->unkFadeEnd);
    }
    globals->unk_80 = 0;
}

s32 func_8004E0F4(SongUpdateEvent* update) {
    BGMPlayer* player;
    s32 error = MUSIC_ERROR_NONE;

    if (update->songName != 0) {
        player = snd_get_player_with_song_name(update->songName);
        if (player != NULL) {
            func_80053B04(&player->fadeInfo, update->duration, update->finalVolume);
        }
        else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }
    return error;
}

void bgm_player_init(BGMPlayer* player, s32 arg1, s32 arg2, AuGlobals* arg3) {
    s16 i;

    player->globals = arg3;
    func_8004E880(player, BGM_SAMPLE_RATE, 48);
    player->unk_48 = 0x8000;
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterVolume = 0x7F000000;
    player->unk_14 = 0;
    player->unk_18 = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    player->segmentReadPos = NULL;
    player->segmentStartPos = NULL;
    player->unk_70 = 0;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->masterPitchShift = 0;
    player->unk_20E = 0;
    player->unk_220 = 0;
    player->trackFadeConfig = NULL;
    player->bFadeConfigSetsVolume = FALSE;
    player->masterState = BGM_PLAY_STATE_0;
    player->unk_234 = arg1;
    player->defaultReverbType = arg2;
    player->unk_168.s32 = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->unk_D0 = 1.0f;
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

        note->unk_08 = 0;
        note->adjustedPitch = 0;
        note->noteLength = 0;
        note->unk_14 = 0;
        note->noteVelocity = 0;
        note->unk_note_17 = 0;
    }

    snd_set_fade_vol_scale(&player->fadeInfo, 0x7FFF);
    func_80055110(player);
}

void bgm_set_effect_indices(BGMPlayer* player, u8* list) {
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

void snd_update_bgm_fade(BGMPlayer* player) {
    player->fadeInfo.fadeTime--;

    if (player->fadeInfo.fadeTime != 0) {
        player->fadeInfo.currentVolume.s32 += player->fadeInfo.fadeStep;
    } else {
        player->fadeInfo.currentVolume.s32 = player->fadeInfo.targetVolume << 16;

        if (player->fadeInfo.onCompleteCallback != NULL) {
            player->fadeInfo.onCompleteCallback();
        }

        if (player->fadeSongName != 0) {
            func_8004DC80(player->fadeSongName);
        } else if (player->fadeInfo.currentVolume.s32 == 0) {
            func_8004DAA8(player);
        }
    }
    func_8004E444(player);
}

void func_8004E444(BGMPlayer* arg0) {
    u16 mult = (arg0->fadeInfo.currentVolume.u16 * arg0->fadeInfo.volScale.u16) >> 15;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->effectIndices); i++) {
        s8 temp = arg0->effectIndices[i];

        if (temp < 0) {
            return;
        }
        func_80053A98(temp, mult, arg0->unk_48);
    }
}

s32 func_8004E4B8(BGMPlayer* player) {
    u16 hasMore = TRUE;
    s32 retVal = FALSE;

    player->unk_50 = (u16)player->unk_50 + (u16)player->unk_18 + (u16)player->unk_14;
    player->unk_54 = (u16)player->unk_54 +
        ((player->unk_18 << 4) & 0xFFFF) +
        ((player->unk_14 >> 4) & 0xFFFF);
    do {
        switch (player->masterState) {
        case BGM_PLAY_STATE_0:
            hasMore = FALSE;
            break;
        case BGM_PLAY_STATE_1:
            if (player->unk_220 == 0) {
                func_8004EC68(player);
                if (player->masterState == BGM_PLAY_STATE_1) {
                    hasMore = FALSE;
                }
            } else {
                hasMore = FALSE;
            }
            break;
        case BGM_PLAY_STATE_2:
            snd_bgm_state_2(player);
            break;
        case BGM_PLAY_STATE_3:
            snd_initialize_bgm_player(player);
            hasMore = FALSE;
            break;
        case BGM_PLAY_STATE_4:
            snd_bgm_state_4(player);
            break;
        default:
            retVal = TRUE;
            hasMore = FALSE;
            break;
        }
    } while (hasMore);
    return retVal;
}

void snd_initialize_bgm_player(BGMPlayer* player) {
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
        track->unk2C = 0x7FFF0000;
        track->unk_04 = 0;
        track->prevReadPos = 0;
        track->unk_3E = 0;
        track->segTrackTune = 0;
        track->trackTremoloTime = 0;
        track->trackTremoloAmount = 0;
        track->trackTremoloSpeed = 0;
        track->subTrackVolumeFadeDelta = 0;
        track->subTrackVolumeFadeVolume = 0;
        track->subTrackVolumeFadeTime = 0;
        track->unk30 = 0;
        track->unk34 = 0;
        track->unk36 = 0;
        track->unk_4D = 0;
        track->unk_4E = 0;
        track->unk_4F = 0;
        track->unk_50 = 0;
        track->unk_51 = 0;
        track->unk_54 = 0;
        track->unk_57 = 0;
        track->isDrumTrack = FALSE;
        track->unk_59 = 0;
        track->unk_5A = 0;
        track->subtrackReverbType = player->defaultReverbType;
        track->unk_5C = i;
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
    player->unk_D0 = 128.0f; // set to 1.0 later om...
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterTempoBPM = BGM_DEFAULT_TEMPO / 100;
    player->unk_21E = 0x80;
    player->masterVolume = 0x7F000000;
    player->fadeSongName = 0;
    player->unk_74 = 0;
    player->masterTempoFadeTempo = 0;
    player->masterPitchShift = 0;
    player->unk_20E = 0;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->proxMixValue = 0;
    player->proxMixID = 0;
    player->proxMixVolume = 0;
    player->segActiveLoopEndPos[3] = NULL;
    player->segActiveLoopEndPos[2] = NULL;
    player->segActiveLoopEndPos[1] = NULL;
    player->segActiveLoopEndPos[0] = NULL;
    player->unk_168.s32 = 0;
    player->segLoopDepth = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->trackFadeConfig = NULL;
    player->bFadeConfigSetsVolume = FALSE;
    player->unk_233 = 1;
    player->unk_211 = 0;
    player->unk_D0 = 1.0f;

    for (i = 0; i < ARRAY_COUNT(player->unk_212); i++) {
        func_8004E844(player, i);
    }

    for (i = 0; i < ARRAY_COUNT(player->effectValues); i++) {
        player->effectValues[i] = 0;
    }

    player->unk_220 = 0;
    player->unk_18 = 0;
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

    player->masterState = BGM_PLAY_STATE_2;
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
    player->unkFrequency = sampleRate;
    player->unk_0C = A;
    player->unk_10 = A;
    player->maxTempo = A / 1000;
}

// runs whenever a new segment begins playing
void snd_bgm_state_2(BGMPlayer* player) {
    u16 continueReading = TRUE;
    u32 cmd;

    player->masterTempoFadeDelta = 0;
    player->masterTempoFadeTime = 0;
    while (continueReading) {
        cmd = *player->segmentReadPos++;
        if (cmd == BGM_SEGMENT_END) {
            player->masterState = BGM_PLAY_STATE_4;
            continueReading = FALSE;
        } else {
            switch (cmd >> 12) {
                case BGM_SEGMENT_SUBSEG << 16:
                    func_8004EAD4(player, cmd);
                    player->masterState = BGM_PLAY_STATE_1;
                    continueReading = FALSE;
                    break;
                case BGM_SEGMENT_START_LOOP << 16:
                    break;
                case BGM_SEGMENT_HALT << 16:
                    continueReading = FALSE;
                    break;
                case BGM_SEGMENT_END_LOOP << 16:
                    func_8004EA34(player, cmd);
                    break;
                case BGM_SEGMENT_6 << 16:
                    if (!(player->unk_223 & 1)) {
                        func_8004EA34(player, cmd);
                    }
                    break;
                case BGM_SEGMENT_7 << 16:
                    if (player->unk_223 & 1) {
                        func_8004EA34(player, cmd);
                    }
                    break;
                default:
                    continueReading = FALSE;
                    break;
            }
        }
    }
}

void func_8004EA34(BGMPlayer* player, u32 cmd) {
    s32 labelIndex = cmd & 0x1F; // 01F (bits 0-4)
    s32 iterCount = (cmd >> 5) & 0x7F;   // FE0 (bits 5-11)
    u32 depth;

    depth = player->segLoopDepth;
    if (player->segActiveLoopEndPos[depth] != NULL) {
        if (player->segActiveLoopEndPos[depth] == player->segmentReadPos) {
            if (player->unk_168.u8[depth] != 0) {
                player->unk_168.u8[depth]--;
                if ((player->unk_168.u8[depth]) == 0) {
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
            player->unk_168.u8[depth] = iterCount;
            player->segmentReadPos = player->segLoopStartLabels[labelIndex];
        }
    } else {
        player->segActiveLoopEndPos[depth] = player->segmentReadPos;
        player->unk_168.u8[depth] = iterCount;
        player->segmentReadPos = player->segLoopStartLabels[labelIndex];
    }
    player->segLoopDepth = depth;
}

INCLUDE_ASM(s32, "audio/28910_len_5090", func_8004EAD4);

void snd_bgm_state_4(BGMPlayer* player) {
    s32 i;

    player->unk_220 = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    for (i = 0; i < 16; i++) {
        player->tracks[i].bgmReadPos = 0;
    }
    func_80050900(player);
    player->masterState = BGM_PLAY_STATE_0;
    player->unkFrequency = BGM_SAMPLE_RATE;
}

#define POST_BGM_READ() \
if (track->unk_3E != 0) {\
    track->unk_3E--;\
    if (track->unk_3E == 0) {\
        track->bgmReadPos = track->unk_04;\
    }\
}

void func_8004EC68(BGMPlayer *player) {
    s32 bVolumeFading;    // SP + 10
    u8 sp1F;              // SP + 1F
    s16 notePitch;        // SP + 26
    u8 bFinished;         // SP + 28

    AlUnkVoice* voice;
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

    if (player->masterTempoFadeTime != 0) {
        player->masterTempoFadeTime--;
        if (player->masterTempoFadeTime == 0) {
            player->masterTempo = player->masterTempoFadeTempo;
            player->masterTempoFadeTempo = 0;
            player->masterTempoFadeDelta = 0;
        } else {
            player->masterTempo += player->masterTempoFadeDelta;
        }
        player->unkFrequency = player->masterTempo * 10;
    }
    if (player->masterVolumeFadeTime != 0) {
        player->masterVolumeFadeTime--;
        if (player->masterVolumeFadeTime == 0) {
            player->masterVolume = player->masterVolumeFadeVolume;
            player->masterVolumeFadeVolume = 0;
            player->masterVolumeFadeDelta = 0;
        } else {
            player->masterVolume += player->masterVolumeFadeDelta;
        }
        bVolumeFading = TRUE;
    }
    player->volumeChanged = FALSE;
    if (player->trackFadeConfig != NULL) {
        if (player->bFadeConfigSetsVolume) {
            // setting track volumes
            s32 lenLimit = 16;
            while (lenLimit-- != 0) {
                i = *player->trackFadeConfig++;
                if (i == 0) {
                    break;
                }
                track = &player->tracks[i - 1];
                player->seqCmdArgs.TrackVolumeFade.time = 48;
                player->seqCmdArgs.TrackVolumeFade.value = *(player->trackFadeConfig++);
                if (track->bgmReadPos != 0) {
                    snd_BGMCmd_F6_TrackVolumeFade(player, track);
                }
            }
        }
        else {
            // clearing track volumes
            s32 lenLimit = 16;
            while (lenLimit-- != 0) {
                i = *player->trackFadeConfig++;
                if (i == 0) {
                    break;
                }
                track = &player->tracks[i - 1];
                player->seqCmdArgs.TrackVolumeFade.time = 48;
                player->trackFadeConfig++; // ignore arg
                player->seqCmdArgs.TrackVolumeFade.value = 0;
                if (track->bgmReadPos != 0) {
                    snd_BGMCmd_F6_TrackVolumeFade(player, track);
                }
            }
        }
        player->trackFadeConfig = NULL;
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
            if (track->subTrackVolumeFadeTime != 0) {
                track->subTrackVolumeFadeTime--;
                if (track->subTrackVolumeFadeTime == 0) {
                    track->subTrackVolume = track->subTrackVolumeFadeVolume;
                } else {
                    track->subTrackVolume += track->subTrackVolumeFadeDelta;
                }
                track->changed.volume = 1;
            }
            if (track->unk36 != 0) {
                track->unk36--;
                if (track->unk36 == 0) {
                    track->unk2C = track->unk34 << 0x10;
                } else {
                    track->unk2C += track->unk30;
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
                                for (voiceIdx = sp1F; voiceIdx < track->unk_53; voiceIdx++) {
                                    voice = &player->globals->voices[voiceIdx];
                                    sp1F++;
                                    if (voice->unk_45 == 0) {
                                        bAcquiredVoiceIdx = TRUE;
                                        break;
                                    }
                                }

                                if (!bAcquiredVoiceIdx) {
                                    if (track->unk_54 >= 5) { // 5 = AL_DEFAULT_PRIORITY?
                                        for(voiceIdx = track->unk_52; voiceIdx < track->unk_53; voiceIdx++) {
                                            voice = &player->globals->voices[voiceIdx];
                                            if (voice->unk_45 < player->unk_234) {
                                                func_800538C4(voice, voiceIdx);
                                                bAcquiredVoiceIdx = TRUE;
                                                break;
                                            }
                                        }
                                        if (!bAcquiredVoiceIdx) {
                                            for (voiceIdx = track->unk_52; voiceIdx < track->unk_53; voiceIdx++) {
                                                voice = &player->globals->voices[voiceIdx];
                                                if (voice->unk_45 == player->unk_234) {
                                                    note = &player->notes[voiceIdx];
                                                    if (note->noteLength == 0) {
                                                        func_800538C4(voice, voiceIdx);
                                                        bAcquiredVoiceIdx = TRUE;
                                                        break;
                                                    }
                                                }
                                            }
                                        }

                                        if (!bAcquiredVoiceIdx) {
                                            s32 shortestLength = 0xFFFF;
                                            u8 voice_it;
                                            AlUnkVoice* curVoice;
                                            SeqNote* curNote;
                                            for (voice_it = track->unk_52; voice_it < track->unk_53; voice_it++) {
                                                curVoice = &player->globals->voices[voice_it];
                                                if (curVoice->unk_45 == player->unk_234) {
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
                                                func_800538C4(voice, voiceIdx);
                                            }
                                        }

                                    } else {
                                        voiceIdx = track->unk_52;
                                        voice = &player->globals->voices[voiceIdx];
                                        note = &player->notes[voiceIdx];
                                        note->noteLength = 0;
                                        if (voice->unk_45 <= player->unk_234) {
                                            func_800538C4(voice, voiceIdx);
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
                                    note->ins = func_80053BE8(player->globals, (u16)drumInfo->bankPatch >> 8, (u16)drumInfo->bankPatch & 0xFF, &voice->unk_14);
                                    if (drumInfo->unk_08 != 0) {
                                        note->unk_08 = note->noteVelocity * func_80050654(player->unk_50, drumInfo->volume, drumInfo->unk_08);
                                    } else {
                                        note->unk_08 = note->noteVelocity * drumInfo->volume;
                                    }
                                    voice->unk_40 = (((((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15)) * (track->unk2C >> 0x15)) >> 0x14) * (track->segTrackVolume * note->unk_08)) >> 0x10;
                                    note->adjustedPitch = (((s8) track->subTrackFineTune) + (drumInfo->keyBase + track->subTrackCoarseTune)) - note->ins->keyBase;
                                    temp = (note->adjustedPitch + track->segTrackTune) + player->unk_20E;
                                    if (drumInfo->unk_07 != 0) {
                                        note->unk_14 = func_800505E4(player->unk_50, temp, drumInfo->unk_07);
                                        temp = note->unk_14;
                                    }
                                    note->pitchRatio = snd_compute_pitch_ratio(temp) * note->ins->pitchRatio;
                                    if (drumInfo->unk_09 != 0) {
                                        voice->pan = func_80050568(player, drumInfo->pan, drumInfo->unk_09);
                                    } else {
                                        voice->pan = drumInfo->pan;
                                    }
                                    if (drumInfo->unk_drum_0A != 0) {
                                        voice->reverb = func_8005068C(player->unk_50, drumInfo->unk_06, drumInfo->unk_drum_0A);
                                    } else {
                                        voice->reverb = drumInfo->unk_06;
                                    }
                                } else {
                                    note->unk_08 = (((((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15)) * (track->unk2C >> 0x15)) >> 0x14) * (track->segTrackVolume * note->noteVelocity)) >> 9;
                                    voice->unk_40 = note->unk_08;
                                    note->ins = track->instrument;
                                    note->adjustedPitch =
                                        (notePitch * 100)
                                        + track->subTrackCoarseTune
                                        + player->masterPitchShift
                                        + track->subTrackFineTune
                                        - note->ins->keyBase;
                                    note->pitchRatio = snd_compute_pitch_ratio((note->adjustedPitch + track->segTrackTune) + player->unk_20E) * track->instrument->pitchRatio;

                                    if (track->unk_57 != 0) {
                                        voice->pan = func_80050568(player, track->subTrackPan, track->unk_57);
                                    } else {
                                        voice->pan = track->subTrackPan;
                                    }
                                    voice->reverb = track->subTrackReverb;

                                    if (track->unk_4C != 0) {
                                        voice->unk_14.unk_00 = (s32*)player->unk_174[track->unk_4C - 1]; //TODO ???
                                    } else {
                                        voice->unk_14.unk_00 = track->unk_10.unk_00;
                                    }
                                    voice->unk_14.unk_04 = track->unk_10.unk_04;
                                }
                                voice->instrument = note->ins;
                                voice->pitchRatio = note->pitchRatio;
                                voice->reverbType = track->subtrackReverbType;
                                if (note->noteLength >= 2) {
                                    note->unk_note_17 = 1;
                                    note->tremoloTime = track->trackTremoloTime;
                                    note->unk_13 = 0;
                                    note->tremoloAmount = track->trackTremoloAmount;
                                    voice->unk_flags_43 = 2;
                                    voice->unk_45 = player->unk_234;
                                    voice->unk_44 = voice->unk_45;
                                }
                            }
                        } else {
                            //TODO variable is nargs, but temp is required to match
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
                    if (voice->unk_45 == player->unk_234) {
                        note = &player->notes[voiceIdx];
                        if (note->unk_note_17 == 0) {
                            if (note->noteLength > 0) {
                                note->noteLength--;
                                if (note->noteLength == 0) {
                                    voice->unk_flags_3D |= 0x10;
                                }
                            }
                            if (track->isDrumTrack) {
                                if (track->changed.tune || (player->unk_20E != 0)) {
                                    note->pitchRatio = snd_compute_pitch_ratio(((note->adjustedPitch + note->unk_14) + track->segTrackTune) + player->unk_20E) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->unk_flags_43 |= 8;
                                    }
                                }
                                if (track->changed.volume) {
                                    voice->unk_40 = (((((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15)) * (track->unk2C >> 0x15)) >> 0x14) * (track->segTrackVolume * note->unk_08)) >> 0x10;
                                    voice->unk_flags_3D |= 0x20;
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

                                        note->pitchRatio = snd_compute_pitch_ratio(var_a1_5 + ((note->adjustedPitch + track->segTrackTune) + player->unk_20E)) * note->ins->pitchRatio;
                                        if (voice->pitchRatio != note->pitchRatio) {
                                            voice->pitchRatio = note->pitchRatio;
                                            voice->unk_flags_43 |= 8;
                                        }
                                    }
                                } else if (track->changed.tune || (player->unk_20E != 0)) {

                                    note->pitchRatio = snd_compute_pitch_ratio((note->adjustedPitch + track->segTrackTune) + player->unk_20E) * note->ins->pitchRatio;
                                    if (voice->pitchRatio != note->pitchRatio) {
                                        voice->pitchRatio = note->pitchRatio;
                                        voice->unk_flags_43 |= 8;
                                    }
                                }
                                if (track->changed.volume) {
                                    s32 tempVolume = ((player->masterVolume >> 0x15) * (track->subTrackVolume >> 0x15) * (track->unk2C >> 0x15)) >> 0x14;
                                    note->unk_08 = (tempVolume * (track->segTrackVolume * note->noteVelocity)) >> 9;
                                    voice->unk_40 = note->unk_08;
                                    voice->unk_flags_3D |= 0x20;
                                    voice->pan = track->subTrackPan;
                                    voice->reverb = track->subTrackReverb;
                                } else if (track->changed.pan || track->changed.reverb) {
                                    voice->pan = track->subTrackPan;
                                    voice->reverb = track->subTrackReverb;
                                    voice->unk_flags_43 |= 0x10;
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
        player->masterState = BGM_PLAY_STATE_2;
    }
}

static const f32 padding[] = {0.0f}; // at least after func_8004E4B8

void snd_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 bpm = player->seqCmdArgs.MasterTempo.value;
    s32 tempo;

    player->masterTempoBPM = bpm;
    tempo = snd_bpm_to_tempo(player, bpm);
    player->masterTempo = tempo;
    player->unkFrequency = tempo * 10;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
}

s32 snd_bpm_to_tempo(BGMPlayer* player, u32 tempo) {
    u32 maxTempo = player->maxTempo;
    u32 ret = tempo;

    ret *= player->unk_D0;

    if (maxTempo < ret) {
        ret = maxTempo;
    } else if (ret == 0) {
        ret = 1;
    }

    return ret * 100;
}

void snd_BGMCmd_E1_MasterVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 volume = player->seqCmdArgs.MasterVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    player->masterVolume = volume;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->volumeChanged = TRUE;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_E2_MasterPitchShift(BGMPlayer* player, BGMPlayerTrack* track) {
    player->masterPitchShift = (s8)player->seqCmdArgs.MasterPitchShift.cent * 100;
}

void snd_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->globals->unk_globals_40[player->defaultReverbType].unk_00 = player->seqCmdArgs.UnkCmdE3.bank;
    player->globals->unk_globals_40[player->defaultReverbType].unk_01 = TRUE;
}

void snd_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.MasterEffect.index;
    u32 temp_v1 = player->effectIndices[index];

    if ((index < 4) && (temp_v1 < 0x80)) {
        if (player->globals->unk_globals_40[temp_v1].unk_00 != player->seqCmdArgs.MasterEffect.value) {
            player->globals->unk_globals_40[temp_v1].unk_00 = player->seqCmdArgs.MasterEffect.value;
            player->globals->unk_globals_40[temp_v1].unk_01 = TRUE;
        }
        player->effectValues[index] = player->seqCmdArgs.MasterEffect.value;
    }
}

void snd_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterTempoFade.time;
    s32 tempo = snd_bpm_to_tempo(player, player->seqCmdArgs.MasterTempoFade.value);

    if (time <= 0) {
        time = 1;
    }

    player->masterTempoFadeTime = time;
    player->masterTempoFadeTempo = tempo;
    player->masterTempoFadeDelta = (tempo - player->masterTempo) / time;
}

void snd_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.MasterVolumeFade.time;
    s32 volume = player->seqCmdArgs.MasterVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (time <= 0) {
        time = 1;
    }

    player->masterVolumeFadeTime = time;
    player->masterVolumeFadeVolume = volume;
    player->masterVolumeFadeDelta = (volume - player->masterVolume) / time;
}

void snd_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, BGMPlayerTrack* track) {
    track->patch = player->seqCmdArgs.TrackOverridePatch.patch;
    track->instrument = func_80053BE8(player->globals, player->seqCmdArgs.TrackOverridePatch.bank, track->patch, &track->unk_10);
}

void snd_BGMCmd_E9_SubTrackVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    u32 volume = arg0->seqCmdArgs.SubTrackVolume.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    track->subTrackVolume = volume;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_F6_TrackVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.TrackVolumeFade.time;
    s32 volume = player->seqCmdArgs.TrackVolumeFade.value & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (volume != track->subTrackVolume) {
        if (time <= 0) {
            time = 1;
        }

        track->subTrackVolumeFadeTime = time;
        track->subTrackVolumeFadeVolume = volume;
        track->subTrackVolumeFadeDelta = (volume - track->subTrackVolume) / time;
    }
}

void snd_BGMCmd_EA_SubTrackPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.SubTrackPan.value & 0x7F;
    track->unk_57 = 0;
    track->changed.pan = TRUE;
}

void snd_BGMCmd_EB_SubTrackReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackReverb = player->seqCmdArgs.SubTrackReverb.value & 0x7F;
    track->changed.reverb = TRUE;
}

void snd_BGMCmd_EC_SegTrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackVolume = player->seqCmdArgs.SegTrackVolume.value & 0x7F;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackCoarseTune = (s8)player->seqCmdArgs.SubTrackCoarseTune.cent * 100;
}

void snd_BGMCmd_EE_SubTrackFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackFineTune = player->seqCmdArgs.SubTrackFineTune.value;
}

void snd_BGMCmd_EF_SegTrackTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackTune = player->seqCmdArgs.SegTrackTune.value;
    track->changed.tune = TRUE;
}

void snd_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloAmount = player->seqCmdArgs.TrackTremolo.amount;
    track->trackTremoloSpeed = player->seqCmdArgs.TrackTremolo.speed;
    track->trackTremoloTime = player->seqCmdArgs.TrackTremolo.time;
}

void snd_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloSpeed = player->seqCmdArgs.TrackTremoloSpeed.value;
}

void snd_BGMCmd_F2_TrackTremoloTime(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = player->seqCmdArgs.TrackTremoloTime.time;
}

void snd_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = 0;
}

void snd_BGMCmd_F4(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.UnkCmdF4.pan0 & 0x7F;
    track->unk_57 = player->seqCmdArgs.UnkCmdF4.pan1 & 0x7F;
}

void snd_BGMCmd_F5_TrackVoice(BGMPlayer* player, BGMPlayerTrack* track) {
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
    track->instrument = func_80053BE8(player->globals, bank, patch, &track->unk_10);
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

void snd_BGMCmd_F7_SubTrackReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 index = player->seqCmdArgs.SubTrackReverbType.index;
    s8 type = player->effectIndices[index];

    if ((index < 4) && (type >= 0)) {
        track->subtrackReverbType = type;
    } else {
        track->subtrackReverbType = player->defaultReverbType;
    }
}

void snd_BGMCmd_FD(BGMPlayer* player, BGMPlayerTrack* track) {
    func_800560BC(player->unk_234, track->unk_5C, player->seqCmdArgs.UnkCmdFD.unk_00 >> 8);
}

void snd_BGMCmd_FE(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos readPos = (AuFilePos)(player->seqCmdArgs.UnkCmdFE.offset + (s32)player->bgmFile);

    track->unk_3E = player->seqCmdArgs.UnkCmdFE.unk_02;
    track->unk_04 = track->bgmReadPos;
    track->bgmReadPos = readPos;
}

void snd_BGMCmd_FC_Jump(BGMPlayer* player, BGMPlayerTrack* track) {
    AuFilePos args;
    u32 i;

    args = (AuFilePos)(player->seqCmdArgs.Jump.unk_00 + (s32)player->bgmFile);
    if (player->proxMixID < player->seqCmdArgs.Jump.unk_02) {
        args += player->proxMixID * 3;
    }
    track->prevReadPos = track->bgmReadPos;
    track->bgmReadPos = (AuFilePos)((args[0] << 8) + args[1] + (s32)player->bgmFile);
    track->isDrumTrack = args[2];
    if (track->unk_4D != 0) {
        track->unk_4D = 0;
        track->unk2C = 0;
        for (i = track->unk_52; i < track->unk_53; i++) {
            AlUnkVoice* temp_a0 = &player->globals->voices[i];
            if ((temp_a0->unk_45 == player->unk_234) && (temp_a0->unk_1C != 0)) {
                func_800538C4(temp_a0, i);
            }
        }
    }
    if (track->unk_4E != 0) {
        track->unk_4E = 0;
        func_80050888(player, track, player->proxMixVolume, 0x90);
    }
    track->subTrackCoarseTune = 0;
    track->subTrackFineTune = 0;
    track->unk_4C = 0;
    track->segTrackTune = 0;
    track->trackTremoloTime = 0;
    track->subTrackVolumeFadeTime = 0;
    track->unk_57 = 0;
    track->subtrackReverbType = player->defaultReverbType;
}

void snd_BGMCmd_FF(BGMPlayer* player, BGMPlayerTrack* track) {
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
                player->globals->unk_51 = player->effectIndices[arg1];
                if (arg2 != 0) {
                    temp_a3 = arg2 & 0xF;
                    temp_a1 = ((arg2 >> 4) & 1) + 1;
                    if ((player->globals->unk_52 != temp_a3) || (player->globals->unk_53 != temp_a1)) {
                        player->globals->unk_52 = temp_a3;
                        player->globals->unk_53 = temp_a1;
                        player->globals->unk_50 = 1;
                    }
                } else {
                    if (player->globals->unk_53 != 0) {
                        player->globals->unk_53 = 0;
                        player->globals->unk_50 = 1;
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
                for (i = 0; i < ARRAY_COUNT(player->soundManager->unk_90); i++) {
                    if ((player->soundManager->unk_90[i].unk_0) == 0) {
                        player->soundManager->unk_90[i].unk_0 = arg1;
                        player->soundManager->unk_90[i].volume = ((player->fadeInfo.currentVolume.u16 * player->fadeInfo.volScale.u16) + 0x7FFF) >> 0x17;
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

void snd_BGMCmd_NOP(BGMPlayer* player, BGMPlayerTrack* track) {
}

u8 func_80050568(BGMPlayer* player, u8 arg1, u8 arg2) {
    s32 temp_v0 = player->unk_50;
    s32 a = (temp_v0 >> 7);
    s32 b = (temp_v0 >> 2);
    s32 c = (a + b) & 1;
    s32 d = (temp_v0 >> 8) & 0x3F;
    s32 e = (temp_v0 << 4) & 0xC0;
    s32 f = d + e;
    s32 g = arg1;
    s32 retPan;

    if (c != 0) {
        retPan = g + ((arg2 * f) >> 8);
    } else {
        retPan = g - ((arg2 * f) >> 8);
    }
    if (retPan < 0) {
        retPan = 0;
    } else if (retPan >= 0x80) {
        retPan = 0x7F;
    }
    return retPan;
}

s16 func_800505E4(s32 arg0, s32 arg1, u8 arg2) {
    s32 a = (arg0 >> 4);
    s32 b = (arg0 >> 1);
    s32 c = (a + b) & 1;
    s32 d = (arg0 >> 6) & 0xF;
    s32 e = (arg0 << 2) & 0xF0;
    s32 f = d + e;
    s32 retVal;

    if (c != 0) {
        s32 g = arg2;
        s32 h = 5 * f;
        retVal = arg1 + ((g * h) >> 8);
    } else {
        s32 g = arg2;
        s32 h = 5 * f;
        retVal = arg1 - ((g * h) >> 8);
    }
    return retVal;
}

u8 func_80050654(s32 arg0, u8 volume, u8 arg2) {
    s32 a = (arg0 >> 8) & 0x1F; // bitmask 0x1F00
    s32 b = arg0 & 0xE0;
    s32 c = a + b;
    return (volume * (0x8000 - arg2 * (c)));
}

u8 func_8005068C(s32 arg0, u8 arg1, u8 arg2) {
    s32 a = (arg0 >> 7) & 7; // bitmask 380
    s32 b = (arg0 << 3) & 0xF8; // bitmask 1F
    s32 c = a + b;
    return (arg1 * (0x8000 - (arg2 * c)));
}

void snd_set_bgm_proximity_mix(s32 songName, u32 mix) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    s32 changed = FALSE;
    u8 mixID = mix & 0xFF;
    s32 i;

    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
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

void func_80050770(BGMPlayer* player, f32 arg1) {
    if (arg1 > 2.0) {
        arg1 = 2.0f;
    } else if (arg1 < 0.25) {
        arg1 = 0.25f;
    }

    player->unk_D0 = arg1;
    player->masterTempo = snd_bpm_to_tempo(player, player->masterTempoBPM);
    player->unkFrequency = player->masterTempo * 10;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
}

void func_80050818(BGMPlayer* player, s32 arg1) {
    if (arg1 > 1200) {
        arg1 = 1200;
    } else if (arg1 < -2400) {
        arg1 = -2400;
    }

    player->unk_20E = arg1;
}

void func_8005083C(BGMPlayer* player, s32 trackIdx, s16 arg2, u8 arg3) {
    BGMPlayerTrack* track = &player->tracks[trackIdx];

    if (track->bgmReadPos != 0) {
        player->seqCmdArgs.TrackVolumeFade.time = arg2;
        player->seqCmdArgs.TrackVolumeFade.value = arg3;
        snd_BGMCmd_F6_TrackVolumeFade(player, track);
    }
}

void func_8005087C(BGMPlayer* player, u8* arg1, s32 arg2) {
    player->trackFadeConfig = arg1;
    player->bFadeConfigSetsVolume = arg2;
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
    if (target == track->unk2C) {
        track->unk36 = 0;
        return;
    }
    track->unk36 = duration;
    track->unk34 = target;
    track->unk30 = ((target << 0x10) - track->unk2C) / duration;
}

void func_80050900(BGMPlayer* player) {
    AlUnkVoice* temp_a0;
    u8 i;

    for (i = 0; i < ARRAY_COUNT(player->globals->voices); i++) {
        temp_a0 = &player->globals->voices[i];
        if (temp_a0->unk_45 == player->unk_234) {
            func_800538C4(temp_a0, i);
        }
    }
}

MusicError func_80050970(SongUpdateEvent* arg0) {
    BGMPlayer* player;
    BGMPlayerTrack* trackA;
    BGMPlayerTrack* trackB;
    AlUnkVoice* voice;
    s32 i;
    s32 j;
    s8 oldVolume;

    s32 songName = arg0->songName;
    s32 variation = arg0->variation;
    s32 error = MUSIC_ERROR_NONE;

    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
        if (player != NULL) {
            for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
                trackA = &player->tracks[i];
                if (trackA->bgmReadPos != 0) {
                    if (trackA->unk_59 != 0) {
                        trackB = &player->tracks[trackA->unk_59 - 1];
                        if (variation != 0) {
                            if (trackA->unk_5A != 0) {
                                trackA->unk_5A = 0;
                                trackB->unk_5A = 1;
                                for (j = trackB->unk_52; j < trackB->unk_53; j++) {
                                    voice = &player->globals->voices[j];
                                    if (voice->unk_45 == player->unk_234) {
                                        voice->unk_14.unk_04 = &D_80078554;
                                        voice->unk_flags_3D |= 0x10;
                                    }
                                }
                                oldVolume = trackA->subTrackVolume >> 24;
                                snd_BGMCmd_E9_SubTrackVolume(player, trackA);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                snd_BGMCmd_F6_TrackVolumeFade(player, trackA);
                            }
                        } else {
                            if (trackA->unk_5A == 0) {
                                trackA->unk_5A = 1;
                                trackB->unk_5A = 0;
                                for (j = trackA->unk_52; j < trackA->unk_53; j++) {
                                    voice = &player->globals->voices[j];
                                    if (voice->unk_45 == player->unk_234) {
                                        voice->unk_14.unk_04 = &D_80078554;
                                        voice->unk_flags_3D |= 0x10;
                                    }
                                }
                                oldVolume = trackB->subTrackVolume >> 24;
                                snd_BGMCmd_E9_SubTrackVolume(player, trackB);
                                player->seqCmdArgs.raw[0] = 0;
                                player->seqCmdArgs.TrackVolumeFade.time = 96;
                                player->seqCmdArgs.TrackVolumeFade.value = oldVolume;
                                snd_BGMCmd_F6_TrackVolumeFade(player, trackB);
                            }
                        }
                    }
                }
            }
        } else {
            error = MUSIC_ERROR_2;
        }
    } else {
        error = MUSIC_ERROR_3;
    }

    return error;
}
