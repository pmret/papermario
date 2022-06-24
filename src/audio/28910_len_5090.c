#include "audio.h"

extern s32 D_80078554;
extern u8 D_80078510[8];
extern u8 D_80078558[40];

BGMPlayer* func_80053F64(s32);
void func_8004EA34(BGMPlayer*, u32);
void func_80050900(BGMPlayer*);

INCLUDE_ASM(void, "audio/28910_len_5090", func_8004D510, BGMPlayer* arg0);

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
                if (duration > 10000) {
                    duration = 10000;
                } else if (duration < 250) {
                    duration = 250;
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
            player->fadeInfo.unk_18 = 0x7FFF;
            player->fadeInfo.unk_1A = 1;
            func_8004E880(player, BGM_SAMPLE_RATE, D_80078510[fileInfo->numSegments & 7]);
            
            if (variation < 0 || variation >= 4 || fileInfo->segments[variation] == 0) {
                variation = 0;
            }
            player->curSegmentID = variation;
            
            player->segmentsInfo = (s32*)(4 * fileInfo->segments[variation] + (s32)player->bgmFile);
            player->segmentReadPos = player->segmentsInfo;
            
            if (fileInfo->drums != 0) {
                player->drumsInfo = (BGMDrumInfo*)(4 * fileInfo->drums + (s32)player->bgmFile);
                player->bgmDrumCount = fileInfo->drumCount;
                
                for(i = 0; i < player->bgmDrumCount; i++) {
                    BGMDrumInfo* drum = &player->drumsInfo[i];
                    player->drums[i] = drum;
                }
                for(; i < ARRAY_COUNT(player->drums); i++) {
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
    if (player->unk_221 != 0) {
        player->unk_221 = 4;
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
    if (player->songName != NULL && player->unk_221 != 0) {
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
        if (duration >= 250 && duration <= 10000) {
            player = snd_get_player_with_song_name(songName);
            if (player != NULL) {
                if (player->songName == songName) {
                    if (player->unk_221 != 0) {
                        if (player->unk_220 == 0) {
                            player->fadeInfo.endVolume = volume;
                            player->fadeInfo.fadeTime = (duration * 1000) / 5750;
                            player->fadeInfo.fadeStep = (s32) ((volume << 0x10) - player->fadeInfo.currentVolume.u32) / player->fadeInfo.fadeTime;
                            player->fadeInfo.fpFadeCallback = (void (*)()) s->variation; //TODO seems wrong
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
                        playerA->globals->unk_6C[variation].unk_5 = playerA->unk_234;
                        playerA->globals->unk_6C[variation].unk_4 = 1;
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
                    if (playerA->unk_221 != 0) {
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
            if (playerA != NULL && playerA->globals->unk_6C[variation].unk_4 == 1) {
                playerB = func_80054248(playerA->globals->unk_6C[variation].unk_5);
                if (playerB != NULL) {
                    if (func_8004DB28(playerB) == 0) {
                        error = func_80053E58(playerA->songID, (u8*)playerA->bgmFile);
                        duration = update->duration;
                        if (duration != 0) {
                            if (duration > BGM_MAX_FADE_DURATION) {
                                duration = BGM_MAX_FADE_DURATION;
                            } else if (duration < BGM_MIN_FADE_DURATION) {
                                duration = BGM_MIN_FADE_DURATION;
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

void func_8004DFD4(SndGlobals* globals) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    UnkAl24* unkTemp;
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
                    unkTemp = &player->unk_85C[j];
                    unkTemp->unk_0C = 0;
                }
            }
        }
        for (k = 0; k < ARRAY_COUNT(player->unk_4C); k++) {
            if (player->unk_4C[k] != 0xFF) {
                player->seqCmdArgs.u8[0] = player->unk_4C[k];
                player->seqCmdArgs.u8[1] = player->unk_224[k];
                snd_BGMCmd_E6_MasterEffect(player, track);
            }
        };
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

void func_8004E158(BGMPlayer* player, s32 arg1, s32 arg2, SndGlobals* arg3) {
    s16 i;

    player->globals = arg3;
    func_8004E880(player, BGM_SAMPLE_RATE, 0x30);
    player->unk_48 = 0x8000;
    player->masterTempo = BGM_DEFAULT_TEMPO;
    player->masterVolume = 0x7F000000;
    player->unk_22B = 1;
    player->unk_14 = 0;
    player->unk_18 = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    player->segmentReadPos = 0;
    player->segmentsInfo = 0;
    player->unk_70 = 0;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->masterTranspose = 0;
    player->unk_20E = 0;
    player->unk_220 = 0;
    player->unk_204 = 0;
    player->unk_232 = 0;
    player->unk_221 = 0;
    player->unk_234 = arg1;
    player->unk_235 = arg2;
    player->unk_168.s32 = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->unk_22A = 0;
    player->unk_22C = 0;
    player->unk_D0 = 1.0f;
    player->unk_22D = 0;
    player->unk_22F = 2;
    player->unk_230 = 3;
    player->unk_22E = 0;
    player->unk_231 = 4;

    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        BGMPlayerTrack* temp = &player->tracks[i];

        temp->subTrackVolume = 0;
        temp->unk_28 = 0;
        temp->subTrackCoarseTune = 0;
        temp->subTrackFineTune = 0;
        temp->subTrackPan = 0;
        temp->subTrackReverb = 0;
        temp->unk_44 = 0;
        temp->unk_58 = 0;
        temp->segTrackVolume = 0x7F;
        temp->unk_4C = 0;

        if (i < ARRAY_COUNT(player->unk_238)) {
            player->unk_238[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(player->unk_85C); i++) {
        UnkAl24* temp = &player->unk_85C[i];

        temp->unk_08 = 0;
        temp->unk_0A = 0;
        temp->unk_0C = 0;
        temp->unk_14 = 0;
        temp->unk_16 = 0;
        temp->unk_17 = 0;
    }

    func_80053AEC(&player->fadeInfo, 0x7FFF);
    func_80055110(player);
}

void func_8004E344(BGMPlayer* arg0, u8* arg1) {
    s32 i;
    s32 j;
    
    for (i = 0; i < 4; i++) {
        s8 b = *arg1++;
        
        if (b < 0) {
            break;
        }
        arg0->unk_4C[i] = b;
    }

    j = 4 - i;
    if (j > 0) {
        while (j-- != 0) {
            arg0->unk_4C[i++] = 0xFF;
        }
    }
}

void snd_update_bgm_fade(BGMPlayer* player) {
    player->fadeInfo.fadeTime--;

    if (player->fadeInfo.fadeTime != 0) {
        player->fadeInfo.currentVolume.s32 += player->fadeInfo.fadeStep;
    } else {
        player->fadeInfo.currentVolume.s32 = player->fadeInfo.endVolume << 16;

        if (player->fadeInfo.fpFadeCallback != NULL) {
            player->fadeInfo.fpFadeCallback();
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
    u16 mult = (arg0->fadeInfo.currentVolume.u16 * arg0->fadeInfo.unk_10.u16) >> 15;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_4C); i++) {
        s8 temp = arg0->unk_4C[i];

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
        switch (player->unk_221) {
        case 0:
            hasMore = FALSE;
            break;
        case 1:
            if (player->unk_220 == 0) {
                func_8004EC68(player);
                if (player->unk_221 == 1) {
                    hasMore = FALSE;
                }
            } else {
                hasMore = FALSE;
            }
            break;
        case 2:
            func_8004E904(player);
            break;
        case 3:
            snd_initialize_bgm_player(player);
            hasMore = FALSE;
            break;
        case 4:
            func_8004EC04(player);
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

    for(i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        BGMPlayerTrack* track = &player->tracks[i];
        track->unk_0C = -1;
        track->subTrackVolume = 0x7FFF0000;
        track->subTrackPan = 0x40;
        track->subTrackReverb = 0;
        track->unk_44 = 0;
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
        track->unk_58 = 0;
        track->unk_59 = 0;
        track->unk_5A = 0;
        track->subtrackReverbType = player->unk_235;
        track->unk_5C = i;
    }

    for(i = 0; i < ARRAY_COUNT(player->unk_85C); i++) {
        UnkAl24* temp_v0_2 = &player->unk_85C[i];
        temp_v0_2->unk_00 = -1;
        temp_v0_2->unk_04 = 2.0f;
        temp_v0_2->unk_14 = 0;
        temp_v0_2->unk_16 = 0;
        temp_v0_2->unk_0C = 0;
        temp_v0_2->unk_12 = 0;
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
    player->masterTranspose = 0;
    player->unk_20E = 0;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->unk_16C = 0;
    player->unk_170 = 0;
    player->unk_171 = 0;
    player->unk_158[3] = 0;
    player->unk_158[2] = 0;
    player->unk_158[1] = 0;
    player->unk_158[0] = 0;
    player->unk_168.s32 = 0;
    player->unk_210 = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->unk_204 = NULL;
    player->unk_232 = 0;
    player->unk_233 = 1;
    player->unk_211 = 0;
    player->unk_D0 = 1.0f;

    for(i = 0; i < 8; i++) {
        func_8004E844(player, i);
    }

    for(i = 0; i < ARRAY_COUNT(player->unk_224); i++) {
        player->unk_224[i] = 0;
    }

    player->unk_220 = 0;
    player->unk_18 = 0;
    for(i = 0; i < ARRAY_COUNT(player->unk_D8); i++) {
        player->unk_D8[i] = player->segmentReadPos;
    }

    // find labels?
    buf = player->segmentReadPos;
    keepReading = TRUE;
    while (keepReading) {
        cmd = *buf++;
        if (cmd == 0) {
            keepReading = FALSE;
        } else if ((cmd & 0xF0000000) == 0x30000000) {
            player->unk_D8[cmd & 0x1F] = buf;
        }
    }
    
    player->unk_221 = 2;
}

void func_8004E844(BGMPlayer* player, s32 arg1) {
    s32 i;
    u16* temp = player->unk_174[arg1];
    player->unk_212[arg1] = 0;
   
    for (i = 0; i < 9; i++) {
        *temp++ = 0xFF00;
    }
}

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
    player->bgmKhz = A / 1000;
}

void func_8004E904(BGMPlayer* player) {
    u16 continueReading = TRUE;
    u32 cmd;

    player->masterTempoFadeDelta = 0;
    player->masterTempoFadeTime = 0;
    while (continueReading) {
        cmd = *player->segmentReadPos++;
        if (cmd == 0) {
            player->unk_221 = 4;
            continueReading = FALSE;
        } else {
            switch(cmd >> 0xC) {
                case 0x10000:
                    func_8004EAD4(player, cmd);
                    player->unk_221 = 1;
                    continueReading = FALSE;
                    break;
                case 0x30000:
                    break;
                case 0x40000:
                    continueReading = FALSE;
                    break;
                case 0x50000:
                    func_8004EA34(player, cmd);
                    break;
                case 0x60000:
                    if (!(player->unk_223 & 1)) {
                        func_8004EA34(player, cmd);
                    }
                    break;
                case 0x70000:
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
    s32 a = cmd & 0x1F;
    s32 b = (cmd >> 5) & 0x7F;
    u32 i;
    
    i = player->unk_210;
    if (player->unk_158[i] != NULL) {
        if (player->unk_158[i] == player->segmentReadPos) {
            if (player->unk_168.u8[i] != 0) {
                player->unk_168.u8[i]--;
                if ((player->unk_168.u8[i]) == 0) {
                    player->unk_158[i] = NULL;
                    if (i > 0) {
                        i--;
                    }
                } else {
                    player->segmentReadPos = player->unk_D8[a];
                }
            } else {
                player->segmentReadPos = player->unk_D8[a];
            }
        } else if (i < 4) {
            i++;
            player->unk_158[i] = player->segmentReadPos;
            player->unk_168.u8[i] = b;
            player->segmentReadPos = player->unk_D8[a];
        }
    } else {
        player->unk_158[i] = player->segmentReadPos;
        player->unk_168.u8[i] = b;
        player->segmentReadPos = player->unk_D8[a];
    }
    player->unk_210 = i;
}

INCLUDE_ASM(s32, "audio/28910_len_5090", func_8004EAD4);

void func_8004EC04(BGMPlayer* player) {
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
    player->unk_221 = 0;
    player->unkFrequency = BGM_SAMPLE_RATE;
}

INCLUDE_ASM(s32, "audio/28910_len_5090", func_8004EC68);

static const f32 padding[] = {0.0f}; // at least after func_8004E4B8

void snd_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 bpm = player->seqCmdArgs.u16[0];
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
    u32 unk_20A = player->bgmKhz;
    u32 ret = tempo;

    ret *= player->unk_D0;

    if (unk_20A < ret) {
        ret = unk_20A;
    } else if (ret == 0) {
        ret = 1;
    }

    return ret * 100;
}

void snd_BGMCmd_E1_MasterVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 volume = player->seqCmdArgs.u8[0] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    player->masterVolume = volume;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->unk_21A = 1;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_E2_MasterTranspose(BGMPlayer* player, BGMPlayerTrack* track) {
    player->masterTranspose = (s8)player->seqCmdArgs.u8[0] * 100;
}

void snd_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->globals->unk_40[player->unk_235].unk_00 = player->seqCmdArgs.u8[0];
    player->globals->unk_40[player->unk_235].unk_01 = 1;
}

void snd_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 unk_D4 = player->seqCmdArgs.u8[0];
    u32 temp_v1 = player->unk_4C[unk_D4];

    if ((unk_D4 < 4) && (temp_v1 < 0x80)) {
        if (player->globals->unk_40[temp_v1].unk_00 != player->seqCmdArgs.u8[1]) {
            player->globals->unk_40[temp_v1].unk_00 = player->seqCmdArgs.u8[1];
            player->globals->unk_40[temp_v1].unk_01 = 1;
        }
        player->unk_224[unk_D4] = player->seqCmdArgs.u8[1];
    }
}

void snd_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 tempo = snd_bpm_to_tempo(player, player->seqCmdArgs.u16[1]);

    if (time <= 0) {
        time = 1;
    }

    player->masterTempoFadeTime = time;
    player->masterTempoFadeTempo = tempo;
    player->masterTempoFadeDelta = (tempo - player->masterTempo) / time;
}

void snd_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 volume = player->seqCmdArgs.u8[2] & 0x7F;

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
    track->unk_44 = player->seqCmdArgs.u8[1];
    track->unk_0C = func_80053BE8(player->globals, player->seqCmdArgs.u8[0], track->unk_44, track->unk_10);
}

void snd_BGMCmd_E9_SubTrackVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    u32 volume = arg0->seqCmdArgs.u8[0] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    track->subTrackVolume = volume;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_F6_TrackVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 volume = player->seqCmdArgs.u8[2] & 0x7F;

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
    track->subTrackPan = player->seqCmdArgs.u8[0] & 0x7F;
    track->unk_57 = 0;
    track->changed.pan = TRUE;
}

void snd_BGMCmd_EB_SubTrackReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackReverb = player->seqCmdArgs.u8[0] & 0x7F;
    track->changed.reverb = TRUE;
}

void snd_BGMCmd_EC_SegTrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackVolume = player->seqCmdArgs.u8[0] & 0x7F;
    track->changed.volume = TRUE;
}

void snd_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackCoarseTune = (s8)player->seqCmdArgs.u8[0] * 100;
}

void snd_BGMCmd_EE_SubTrackFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackFineTune = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_EF_SegTrackTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackTune = player->seqCmdArgs.u16[0];
    track->changed.tune = TRUE;
}

void snd_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloAmount = player->seqCmdArgs.u8[0];
    track->trackTremoloSpeed = player->seqCmdArgs.u8[1];
    track->trackTremoloTime = player->seqCmdArgs.u8[2];
}

void snd_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloSpeed = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_F2_TrackTremoloTime(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = 0;
}

void snd_BGMCmd_F4(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.u8[0] & 0x7F;
    track->unk_57 = player->seqCmdArgs.u8[1] & 0x7F;
}

void snd_BGMCmd_F5_TrackVoice(BGMPlayer* player, BGMPlayerTrack* track) {
    BGMInstrumentInfo* instrument;
    s32 var_s0;
    u32 voiceIndex;
    u32 temp_a2;
    u32 a;

    voiceIndex = player->seqCmdArgs.u8[0];
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
    a = instrument->unk_00;
    temp_a2 = (u8)instrument->unk_00;
    var_s0 = instrument->unk_02 & 0x7F;
    track->unk_44 = (u16) temp_a2;
    track->unk_0C = func_80053BE8(player->globals, a >> 8, temp_a2, track->unk_10);
    if (var_s0 != 0) {
        var_s0 <<= 0x18;
    }
    track->subTrackVolume = var_s0;
    track->subTrackPan = instrument->pan & 0x7F;
    track->subTrackReverb = instrument->reverb & 0x7F;
    track->subTrackCoarseTune = instrument->coarseTune * 100;
    track->subTrackFineTune = instrument->fineTune;
    track->changed.all |= 0x10101;
}

void snd_BGMCmd_F7_SubTrackReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 temp_v0 = player->seqCmdArgs.u8[0];
    u8 temp_v1 = player->unk_4C[temp_v0];

    if ((temp_v0 < 4) && ((s8)temp_v1 >= 0)) {
        track->subtrackReverbType = temp_v1;
    } else {
        track->subtrackReverbType = player->unk_235;
    }
}

void snd_BGMCmd_FD(BGMPlayer* player, BGMPlayerTrack* track) {
    func_800560BC(player->unk_234, track->unk_5C, player->seqCmdArgs.u32 >> 8);
}

void snd_BGMCmd_FE(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 temp = player->seqCmdArgs.u16[0] + (s32)player->bgmFile;

    track->unk_3E = player->seqCmdArgs.u8[2];
    track->unk_04 = track->bgmReadPos;
    track->bgmReadPos = temp;
}


void snd_BGMCmd_FC_Jump(BGMPlayer* player, BGMPlayerTrack* arg1) {
    AlUnkVoice* temp_a0;
    u32 i;
    u8* var_a1;

    var_a1 = (u8*)(player->seqCmdArgs.u16[0] + (s32)player->bgmFile);
    if (player->unk_170 < player->seqCmdArgs.u8[2]) {
        var_a1 += player->unk_170 * 3;
    }
    arg1->prevReadPos = arg1->bgmReadPos;
    arg1->bgmReadPos = (var_a1[0] << 8) + var_a1[1] + (s32)player->bgmFile;
    arg1->unk_58 = var_a1[2];
    if (arg1->unk_4D != 0) {
        arg1->unk_4D = 0;
        arg1->unk2C = 0;
        for (i = arg1->unk_52; i < arg1->unk_53; i++) {
            temp_a0 = &player->globals->voices[i];
            if ((temp_a0->unk_45 == player->unk_234) && (temp_a0->unk_1C != 0)) {
                func_800538C4(temp_a0, (u8)i);
            }
        }
    }
    if (arg1->unk_4E != 0) {
        arg1->unk_4E = 0;
        func_80050888(player, arg1, player->unk_171, 0x90);
    }
    arg1->subTrackCoarseTune = 0;
    arg1->subTrackFineTune = 0;
    arg1->unk_4C = 0;
    arg1->segTrackTune = 0;
    arg1->trackTremoloTime = 0;
    arg1->subTrackVolumeFadeTime = 0;
    arg1->unk_57 = 0;
    arg1->subtrackReverbType = player->unk_235;
}

void snd_BGMCmd_FF(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 i;
    u32 j;
    u8 temp_a1;
    u8 temp_a3;
    
    u32 arg0 = player->seqCmdArgs.u8[0];
    u32 arg1 = player->seqCmdArgs.u8[1];
    u32 arg2 = player->seqCmdArgs.u8[2];
    
    switch (arg0) {
        case 1:
            if ((arg1 < ARRAY_COUNT(player->unk_4C)) && ((s8)player->unk_4C[arg1] >= 0)) {
                player->globals->unk_51 = player->unk_4C[arg1];
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
                    if ((player->soundManager->unk_90[i].u8[0]) == 0) {
                        player->soundManager->unk_90[i].u8[0] = arg1;
                        player->soundManager->unk_90[i].u8[3]= (((player->fadeInfo.currentVolume.u16 * player->fadeInfo.unk_10.u16) + 0x7FFF) >> 0x17);
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
                        if (player->unk_171 == 0x7F) {
                            if (otherTrack->unk_4F != 0) {
                                otherTrack->unk_4E = 0;
                                func_80050888(player, otherTrack, otherTrack->unk_4F, 0x48);
                            }
                        } else {
                            if (otherTrack->unk_50 != 0) {
                                otherTrack->unk_4E = 0;
                                func_80050888(player, otherTrack, otherTrack->unk_50, 0x48);
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
    s32 retVal;
    
    if (c != 0) {
        retVal = g + ((arg2 * f) >> 8);
    } else {
        retVal = g - ((arg2 * f) >> 8);
    }
    if (retVal < 0) {
        retVal = 0;
    } else if (retVal >= 0x80) {
        retVal = 0x7F;
    }
    return retVal;
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

u8 func_80050654(s32 arg0, u8 arg1, u8 arg2) {
    s32 a = (arg0 >> 8) & 0x1F; // bitmask 0x1F00
    s32 b = arg0 & 0xE0;
    s32 c = a + b;
    return (arg1 * (0x8000 - arg2 * (c)));
}

u8 func_8005068C(s32 arg0, u8 arg1, u8 arg2) {
    s32 a = (arg0 >> 7) & 7; // bitmask 380
    s32 b = (arg0 << 3) & 0xF8; // bitmask 1F
    s32 c = a + b;
    return (arg1 * (0x8000 - (arg2 * c)));
}

void func_800506C8(s32 songName, u32 arg1) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    s32 changed = FALSE;
    u8 lowArg1 = arg1 & 0xFF;
    s32 i;
    
    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
        if ((player != NULL) && (player->unk_16C != arg1)) {
            player->unk_16C = arg1;
            if (player->unk_170 != lowArg1) {
                player->unk_170 = arg1;
                changed = TRUE;
            }
            player->unk_171 = (arg1 >> 0x18) & 0x7F;
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

void func_8005083C(BGMPlayer* player, s32 arg1, s16 arg2, s8 arg3) {
    BGMPlayerTrack* track = &player->tracks[arg1];

    if (track->bgmReadPos != 0) {
        player->seqCmdArgs.u16[0] = arg2;
        player->seqCmdArgs.u8[2] = arg3;
        snd_BGMCmd_F6_TrackVolumeFade(player, track);
    }
}

void func_8005087C(BGMPlayer* player, s32* arg1, s32 arg2) {
    player->unk_204 = arg1;
    player->unk_232 = arg2;
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
    AlUnkVoice* temp_a0;
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
                                    temp_a0 = &player->globals->voices[j];
                                    if (temp_a0->unk_45 == player->unk_234) {
                                        temp_a0->unk_18 = &D_80078554;
                                        temp_a0->unk_3D |= 0x10;
                                    }
                                }
                                oldVolume = trackA->subTrackVolume >> 24;
                                snd_BGMCmd_E9_SubTrackVolume(player, trackA);
                                player->seqCmdArgs.u8[0] = 0;
                                player->seqCmdArgs.u16[0] = 0x60;
                                player->seqCmdArgs.u8[2] = oldVolume;
                                snd_BGMCmd_F6_TrackVolumeFade(player, trackA);
                            }
                        } else {
                            if (trackA->unk_5A == 0) {
                                trackA->unk_5A = 1;
                                trackB->unk_5A = 0;
                                for (j = trackA->unk_52; j < trackA->unk_53; j++) {
                                    temp_a0 = &player->globals->voices[j];
                                    if (temp_a0->unk_45 == player->unk_234) {
                                        temp_a0->unk_18 = &D_80078554;
                                        temp_a0->unk_3D |= 0x10;
                                    }
                                }
                                oldVolume = trackB->subTrackVolume >> 24;
                                snd_BGMCmd_E9_SubTrackVolume(player, trackB);
                                player->seqCmdArgs.u8[0] = 0;
                                player->seqCmdArgs.u16[0] = 0x60;
                                player->seqCmdArgs.u8[2] = oldVolume;
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
