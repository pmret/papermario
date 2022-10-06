#include "audio.h"

// data
extern u16 D_80078530[9];
extern s32 D_8007854C[2];
extern f32 AlTuneScaling[];

void func_80052E30(u8 index) {
    AlUnkVoice* voice = &gSoundGlobals->voices[index];

    voice->unk_1C = NULL;
    voice->priority = AU_PRIORITY_FREE;
}

void au_engine_init(s32 outputRate) {
    AuGlobals* globals;
    ALHeap* alHeap;
    SBNFileEntry fileEntry;
    s32* dummyTrackData;
    u8 effects[4];
    u32 i;

    alHeap = gSynDriverPtr->heap;
    gSoundGlobals = alHeapAlloc(alHeap, 1, sizeof(*gSoundGlobals));

    gBGMPlayerA = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerA));
    gBGMPlayerB = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerB));
    gBGMPlayerC = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerC));
    gSoundManager = alHeapAlloc(alHeap, 1, sizeof(*gSoundManager));
    gAuAmbienceManager = alHeapAlloc(alHeap, 1, sizeof(*gAuAmbienceManager));
    gBGMPlayerA->soundManager = gSoundManager;
    gAuAmbienceManager->globals = gSoundGlobals;


    globals = gSoundGlobals;
    dummyTrackData = alHeapAlloc(alHeap, 1, 0x8000);
    globals->dataBGM[0] = (BGMHeader*) &dummyTrackData[0];
    globals->dataBGM[1] = (BGMHeader*) &dummyTrackData[0x1400];
    globals->dataMSEQ[0] = (MSEQHeader*) &dummyTrackData[0x1C00];
    globals->dataMSEQ[1] = (MSEQHeader*) &dummyTrackData[0x1400];

    for (i = 0; i < 1; i++) {
        globals->unk_globals_6C[i].bgmPlayer = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    }

    globals->dataSEF = alHeapAlloc(alHeap, 1, 0x5200);
    globals->defaultInstrument = alHeapAlloc(alHeap, 1, sizeof(Instrument));
    globals->dataPER = alHeapAlloc(alHeap, 1, 6 * sizeof(PEREntry));
    globals->dataPRG = alHeapAlloc(alHeap, 1, 64 * sizeof(BGMInstrumentInfo));
    globals->musicEventQueue = alHeapAlloc(alHeap, 1, 16 * sizeof(MusicEventTrigger));
    globals->outputRate = outputRate;
    au_reset_instrument(globals->defaultInstrument);
    au_reset_drum_entry(&globals->defaultDrumEntry);
    au_reset_instrument_entry(&globals->defaultPRGEntry);
    bgm_clear_music_events();

    globals->audioThreadCallbacks[0] = NULL;
    globals->audioThreadCallbacks[1] = NULL;

    for (i = 0; i < 1; i++) {
        globals->unk_globals_6C[i].unk_4 = 0;
        globals->unk_globals_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        globals->effectChanges[i].type = AU_FX_NONE;
        globals->effectChanges[i].changed = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AlUnkVoice* voice;
        func_80056EC0(i, 0);
        au_pvoice_set_filter_wavetable(i, globals->defaultInstrument);
        voice = &globals->voices[i];
        voice->instrument = NULL;
        voice->pitchRatio = 0;
        voice->volume = -1;
        voice->pan = 0xFF;
        voice->reverbAmt = 0xFF;
        voice->reverbType = 0;
        voice->unk_42 = 0;
        voice->unk_flags_43 = 0;
        voice->priorityCopy = AU_PRIORITY_FREE;
        voice->priority = AU_PRIORITY_FREE;
    }

    au_load_INIT(globals, 0xF00000, alHeap);

    for (i = 0; i < 3; i++) {
        globals->banks[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    au_bgm_player_init(gBGMPlayerA, AU_PRIORITY_BGM_PLAYER_MAIN, AU_FX_NONE, globals);
    effects[0] = 0;
    effects[1] = 3;
    effects[2] = -1;
    effects[3] = -1;
    au_bgm_set_effect_indices(gBGMPlayerA, effects);

    au_bgm_player_init(gBGMPlayerB, AU_PRIORITY_BGM_PLAYER_AUX, AU_FX_BIGROOM, globals);
    effects[0] = 2;
    effects[1] = -1;
    effects[2] = -1;
    effects[3] = -1;
    au_bgm_set_effect_indices(gBGMPlayerB, effects);

    au_sfx_init(gSoundManager, AU_PRIORITY_SFX_MANAGER, AU_FX_SMALLROOM, globals, 16);
    au_mseq_manager_init(gAuAmbienceManager, AU_PRIORITY_MSEQ_MANAGER, AU_FX_SMALLROOM, globals);
    func_80052614(globals);
    au_load_BK_headers(globals, alHeap);
    if (au_fetch_SBN_file(globals->mseqFileList[0], AU_FMT_SEF, &fileEntry) == AU_RESULT_OK) {
        au_read_rom(fileEntry.offset, globals->dataSEF, fileEntry.data & 0xFFFFFF);
    }
    au_sfx_load_groups_from_SEF(gSoundManager);
    if (au_fetch_SBN_file(globals->mseqFileList[1], AU_FMT_PER, &fileEntry) == AU_RESULT_OK) {
        au_load_PER(globals, fileEntry.offset);
    }
    if (au_fetch_SBN_file(globals->mseqFileList[2], AU_FMT_PRG, &fileEntry) == AU_RESULT_OK) {
        au_load_PRG(globals, fileEntry.offset);
    }

    globals->instrumentGroups[0] = globals->instrumentGroup1;
    globals->instrumentGroups[1] = globals->instrumentGroup2;
    globals->instrumentGroups[2] = globals->instrumentGroupX;
    globals->instrumentGroups[3] = globals->instrumentGroup3;
    globals->instrumentGroups[4] = globals->instrumentGroup4;
    globals->instrumentGroups[5] = globals->instrumentGroup5;
    globals->instrumentGroups[6] = globals->instrumentGroup6;
    globals->instrumentGroups[7] = globals->instrumentGroup1;
    globals->unk_53 = 0;
    globals->unk_52 = 0;
    globals->unk_51 = 0;
    globals->unk_50 = 0;

    func_80057ED0(0);
    func_80055050(alHeap);
}

static void au_reset_instrument(Instrument* instrument) {
    instrument->base = DummyInstrumentBase;
    instrument->wavDataLength = sizeof(DummyInstrumentBase);
    instrument->predictor = DummyInstrumentPredictor;
    instrument->dc_bookSize = sizeof(DummyInstrumentPredictor);
    instrument->keyBase = 4800; // middle C?
    instrument->loopPredictor = NULL;
    instrument->loopStart = 0;
    instrument->loopEnd = 0;
    instrument->loopCount = 0;
    instrument->type = 0;
    instrument->unk_25 = 0;
    instrument->unkOffset = (InstrumentEffect*) &D_80078544; //TODO: fix type of data
    instrument->unk_26 = 0;
    instrument->unk_27 = 0;
    instrument->unk_28 = 0;
    instrument->unk_29 = 0;
    instrument->unk_2A = 0;
    instrument->unk_2B = 0;
    instrument->pitchRatio = 0.5f;
}

static void au_reset_drum_entry(BGMDrumInfo* arg0) {
    arg0->bankPatch = 8208;
    arg0->keyBase = 4800; // middle C?
    arg0->volume = 0x7F;
    arg0->pan = 64;
    arg0->reverb = 0;
    arg0->randTune = 0;
    arg0->randVolume = 0;
    arg0->randPan = 0;
    arg0->randReverb = 0;
}

static void au_reset_instrument_entry(BGMInstrumentInfo* arg0) {
    arg0->bankPatch = 0x2010;
    arg0->volume = 0x7F;
    arg0->pan = 64;
    arg0->reverb = 0;
    arg0->coarseTune = 0;
    arg0->fineTune = 0;
}

void au_update_clients_2(void) {
    AuGlobals* globals = gSoundGlobals;
    SoundManager* sfxManager = gSoundManager;
    AuAmbienceManager* ambManager = gAuAmbienceManager;
    BGMPlayer* bgmPlayer;

    func_80053654(globals);

    ambManager->nextUpdateCounter -= ambManager->nextUpdateStep;
    if (ambManager->nextUpdateCounter <= 0) {
        ambManager->nextUpdateCounter += ambManager->nextUpdateInterval;
        snd_ambient_manager_update(ambManager);
    }

    if (sfxManager->fadeInfo.fadeTime != 0) {
        au_fade_update(&sfxManager->fadeInfo);
        func_80053A98(sfxManager->defaultReverbType, sfxManager->fadeInfo.currentVolume.u16, sfxManager->unk_5C);
    }

    sfxManager->nextUpdateCounter -= sfxManager->nextUpdateStep;
    if (sfxManager->nextUpdateCounter <= 0) {
        sfxManager->nextUpdateCounter += sfxManager->nextUpdateInterval;
        sfxManager->unk_BA = au_sfx_manager_update(sfxManager);
    }

    // update gBGMPlayerB
    if (!PreventBGMPlayerUpdate) {
        bgmPlayer = gBGMPlayerB;
        if (bgmPlayer->fadeInfo.fadeTime != 0) {
            au_bgm_update_fade(bgmPlayer);
        }
        if (bgmPlayer->songName != 0) {
            bgmPlayer->songPlayingCounter++;
        }

        bgmPlayer->nextUpdateCounter -= bgmPlayer->nextUpdateStep;
        if (bgmPlayer->nextUpdateCounter <= 0) {
            bgmPlayer->nextUpdateCounter += bgmPlayer->nextUpdateInterval;
            bgmPlayer->unk_5C = au_bgm_player_update_main(bgmPlayer);
        }
    }

    if (!PreventBGMPlayerUpdate) {
        if (globals->unk_80 != 0) {
            func_8004DFD4(globals);
        }
        bgmPlayer = gBGMPlayerA;
        if (bgmPlayer->fadeInfo.volScaleTime != 0) {
            func_80053BA8(&bgmPlayer->fadeInfo);
            if (bgmPlayer->fadeInfo.fadeTime == 0) {
                func_8004E444(bgmPlayer);
            } else {
                au_bgm_update_fade(bgmPlayer);
            }
        } else if (bgmPlayer->fadeInfo.fadeTime != 0) {
            au_bgm_update_fade(bgmPlayer);
        }
        if (bgmPlayer->songName != 0) {
            bgmPlayer->songPlayingCounter++;
        }

        bgmPlayer->nextUpdateCounter -= bgmPlayer->nextUpdateStep;
        if (bgmPlayer->nextUpdateCounter <= 0) {
            bgmPlayer->nextUpdateCounter += bgmPlayer->nextUpdateInterval;
            bgmPlayer->unk_5C = au_bgm_player_update_main(bgmPlayer);
        }
    }
    func_80052660(globals);
}

void au_update_players_main(void) {
    AuGlobals* globals = gSoundGlobals;
    BGMPlayer* player = gBGMPlayerA;
    SoundManager* manager = gSoundManager;

    if (globals->flushMusicEventQueue) {
        bgm_clear_music_events();
    }

    BeginSoundUpdateCallback = globals->audioThreadCallbacks[0];
    if (BeginSoundUpdateCallback != NULL) {
        BeginSoundUpdateCallback();
    }

    au_bgm_update_main(player);

    player = gBGMPlayerB;
    au_bgm_update_main(player);

    au_sfx_update_main(manager);
}

void func_80053654(AuGlobals* globals) {
    u32 i;

    if (globals->unk_130C == 2) {
        globals->unk_130C = 1;
        func_80057EB0();
    }

    if ((globals->unk_50 != 0) && (globals->unk_130C == 0)) {
        switch (globals->unk_53) {
            case 1:
                func_80057DC8(globals->unk_52);
                func_80057E08(globals->unk_51);
                globals->unk_50 = 0;
                break;
            case 2:
                func_80057DC8(globals->unk_52);
                func_80057E5C(globals->unk_51);
                globals->unk_50 = 0;
                break;
            default:
                func_80057EB0();
                globals->unk_50 = 0;
                break;
        }
    }

    if (globals->effectChanges[0].changed) {
        func_80056DCC(0, globals->effectChanges[0].type);
        globals->effectChanges[0].changed = FALSE;
    }
    if (globals->effectChanges[1].changed) {
        func_80056DCC(1, globals->effectChanges[1].type);
        globals->effectChanges[1].changed = FALSE;

    } if (globals->effectChanges[2].changed) {
        func_80056DCC(2, globals->effectChanges[2].type);
        globals->effectChanges[2].changed = FALSE;
    }
    if (globals->effectChanges[3].changed) {
        func_80056DCC(3, globals->effectChanges[3].type);
        globals->effectChanges[3].changed = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AlUnkVoice* voice = &globals->voices[i];
        u8 voiceUpdateFlags = voice->unk_flags_43;

        if (voice->unk_42 != 0) {
            au_pvoice_reset_filter(i);
            voice->unk_42 = 0;
            voice->unk_1C = NULL;
            voice->priority = AU_PRIORITY_FREE;
        }

        if (voiceUpdateFlags & AU_VOICE_SYNC_FLAGS_ALL) {
            func_80052BF8(voice, &voice->unk_14);
            au_pvoice_set_filter(i, voice->reverbType, voice->instrument, voice->pitchRatio, voice->volume, voice->pan, voice->reverbAmt, voice->unk_08);
            voice->priority = voice->priorityCopy;
        } else {
            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAGS_PITCH) {
                au_pvoice_set_pitch_ratio(i, voice->pitchRatio);
            }

            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAGS_4) {
                func_8005736C(i, voice->volume, voice->unk_08, voice->pan, voice->reverbAmt);
            } else if (voiceUpdateFlags & AU_VOICE_SYNC_FLAGS_10) {
                func_80057548(i, voice->pan, voice->reverbAmt);
            }
        }
        voice->unk_flags_43 = 0;
    }
}

void func_80053888(AlUnkVoice* voice, u8 index) {
    if (voice->priority != 0) {
        voice->unk_1C = NULL;
        voice->unk_42 = 1;
        voice->unk_flags_43 = 0;
        func_800576EC(index, 0, AUDIO_SAMPLES);
    }
}

// uncertain name
void au_reset_voice(AlUnkVoice* voice, u8 index) {
    voice->unk_1C = NULL;
    voice->unk_42 = 1;
    voice->unk_flags_43 = 0;
    func_800576EC(index, 0, AUDIO_SAMPLES);
}

// array offsets into AlTuneScaling
#define TUNE_SCALING_ARR_AMPLIFY_FINE 0
#define TUNE_SCALING_ARR_AMPLIFY_COARSE 128
#define TUNE_SCALING_ARR_ATTENUATE_FINE 160
#define TUNE_SCALING_ARR_ATTENUATE_COARSE 288

f32 au_compute_pitch_ratio(s32 pitch) {
    if (pitch >= 0) {
        return AlTuneScaling[(pitch & 0x7F) + TUNE_SCALING_ARR_AMPLIFY_FINE]
            * AlTuneScaling[((pitch & 0xF80) >> 7) + TUNE_SCALING_ARR_AMPLIFY_COARSE];
    } else {
        pitch = -pitch;
        return AlTuneScaling[(pitch & 0x7F) + TUNE_SCALING_ARR_ATTENUATE_FINE]
            * AlTuneScaling[((pitch & 0x3F80) >> 7) + TUNE_SCALING_ARR_ATTENUATE_COARSE];
    }
}

void au_fade_init(Fade* fade, s32 time, s32 startValue, s32 endValue) {
    fade->currentVolume.s32 = startValue * 0x10000;
    fade->targetVolume = endValue;

    if (time != 0) {
        fade->fadeTime = (time * 1000) / AU_5750;
        fade->fadeStep = (endValue * 0x10000 - fade->currentVolume.s32) / fade->fadeTime;
    } else {
        fade->fadeTime = 1;
        fade->fadeStep = 0;
    }

    fade->onCompleteCallback = NULL;
}

void au_fade_clear(Fade* fade) {
    fade->fadeTime = 0;
    fade->fadeStep = 0;
    fade->onCompleteCallback = NULL;
}

void au_fade_update(Fade* fade) {
    fade->fadeTime--;

    if ((fade->fadeTime << 0x10) != 0) {
        fade->currentVolume.s32 += fade->fadeStep;
    } else {
        fade->currentVolume.s32 = fade->targetVolume << 0x10;
        if (fade->onCompleteCallback != NULL) {
            fade->onCompleteCallback();
            fade->fadeStep = 0;
            fade->onCompleteCallback = NULL;
        }
    }
}

void func_80053A98(u8 arg0, u16 arg1, s32 arg2) {
    func_80056D78(arg0, (u32)(arg1 * arg2) >> 15);
}

void func_80053AC8(Fade* fade) {
    if (fade->fadeTime == 0) {
        fade->fadeTime = 1;
        fade->fadeStep = 0;
        fade->targetVolume = fade->currentVolume.u16;
    }
}

void au_fade_set_vol_scale(Fade* fade, s16 value) {
    fade->volScale.s32 = value << 16;
    fade->targetVolScale = value;
    fade->volScaleTime = 0;
    fade->volScaleStep = 0;
}

void func_80053B04(Fade* fade, u32 arg1, s32 target) {
    s16 time;
    s32 delta;

    if (arg1 >= 250 && arg1 <= 100000) {
        time = (s32)(arg1 * 1000) / AU_5750;
        delta = (target << 16) - fade->volScale.s32;

        fade->targetVolScale = target;
        fade->volScaleTime = time;
        fade->volScaleStep = delta / time;
    } else {
        fade->volScaleTime = 0;
        fade->volScaleStep = 0;
    }
}

void func_80053BA8(Fade* fade) {
    fade->volScaleTime--;

    if (fade->volScaleTime != 0) {
        fade->volScale.s32 += fade->volScaleStep;
    } else {
        fade->volScaleStep = 0;
        fade->volScale.s32 = fade->targetVolScale << 16;
    }
}

//TODO cleanup and documentation
Instrument* au_get_instrument(AuGlobals* globals, u32 bank, u32 patch, AlUnkInstrumentData* arg3) {
    Instrument* instrument = (*globals->instrumentGroups[(bank & 0x70) >> 4])[patch];
    InstrumentEffect* temp_a0 = instrument->unkOffset;
    u32 sampleIdx = bank & 3;

    if (sampleIdx < temp_a0->count) {
        arg3->unk_00 = AU_FILE_RELATIVE(temp_a0, temp_a0->unk_04[sampleIdx].unkOffset1);
        arg3->unk_04 = AU_FILE_RELATIVE(temp_a0, temp_a0->unk_04[sampleIdx].unkOffset2);
    } else {
        arg3->unk_00 = &D_8007854C[0];
        arg3->unk_04 = &D_8007854C[1];
    }
    return instrument;
}

void au_get_bgm_player_and_file(u32 playerIndex, BGMHeader** outFile, BGMPlayer** outPlayer) {
    AuGlobals* globals = gSoundGlobals;

    switch (playerIndex) {
        case 0:
            *outFile = globals->dataBGM[0];
            *outPlayer = gBGMPlayerA;
            break;
        case 1:
            *outFile = globals->dataBGM[1];
            *outPlayer = gBGMPlayerB;
            break;
        case 2:
            *outFile = globals->dataBGM[0];
            *outPlayer = gBGMPlayerA;
            break;
        default:
            *outFile = NULL;
            *outPlayer = NULL;
            break;
    }
}

void au_get_bgm_player(u32 playerIndex, BGMPlayer** outPlayer) {
    switch (playerIndex) {
        case 0:
            *outPlayer = gBGMPlayerA;
            break;
        case 1:
            *outPlayer = gBGMPlayerB;
            break;
        case 2:
            *outPlayer = gBGMPlayerA;
            break;
        default:
            *outPlayer = NULL;
            break;
    }
}

AuResult au_load_song_files(u32 songID, BGMHeader* bgmFile, BGMPlayer* player) {
    AuResult status;
    SBNFileEntry fileEntry;
    SBNFileEntry fileEntry2;
    SBNFileEntry* bkFileEntry;
    AuGlobals* soundData;
    InitSongEntry* songInfo;
    s32 i;
    u16 bkFileIndex;
    s32 bgmFileIndex;
    u32 data;
    u32 offset;
    BGMPlayer* arg2_copy ;
    BGMHeader* arg1_copy;
    s32 cond;

    soundData = gSoundGlobals;

    // needed to match
    cond = songID < soundData->songListLength;
    arg2_copy = player;
    arg1_copy = bgmFile;

    if (cond) {
        songInfo = &soundData->songList[songID];
        status = au_fetch_SBN_file(songInfo->bgmFileIndex, AU_FMT_BGM, &fileEntry);
        if (status != AU_RESULT_OK) {
            return status;
        }

        if (func_8004DB28(arg2_copy)) {
            return AU_ERROR_201;
        }

        au_read_rom(fileEntry.offset, arg1_copy, fileEntry.data & 0xFFFFFF);

        for (i = 0 ; i < ARRAY_COUNT(songInfo->bkFileIndex); i++) {
            bkFileIndex = songInfo->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &soundData->sbnFileList[bkFileIndex];

                offset = (bkFileEntry->offset & 0xFFFFFF) + soundData->baseRomOffset;
                fileEntry2.offset = offset;

                data = bkFileEntry->data;
                fileEntry2.data = data;

                if ((data >> 0x18) == AU_FMT_BK) {
                    snd_load_BK(offset, i);
                }
            }
        }
        bgmFileIndex = songInfo->bgmFileIndex;
        arg2_copy->songID = songID;
        arg2_copy->bgmFile = bgmFile;
        arg2_copy->bgmFileIndex = bgmFileIndex;
        return arg1_copy->name;
    } else {
        return AU_ERROR_151;
    }
}

AuResult func_80053E58(s32 songID, BGMHeader* bgmFile) {
    AuResult status;
    SBNFileEntry fileEntry;
    SBNFileEntry sbnEntry;
    SBNFileEntry* bkFileEntry;
    AuGlobals* soundData;
    InitSongEntry* songInfo;
    s32 i;
    u32 data;
    u32 offset;
    u16 bkFileIndex;

    soundData = gSoundGlobals;
    songInfo = &soundData->songList[songID];
    status =  au_fetch_SBN_file(songInfo[0].bgmFileIndex, AU_FMT_BGM, &sbnEntry);
    if (status == AU_RESULT_OK) {
        au_read_rom(sbnEntry.offset, bgmFile, sbnEntry.data & 0xFFFFFF);

        for (i = 0 ; i < ARRAY_COUNT(songInfo->bkFileIndex); i++) {
            bkFileIndex = songInfo->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &soundData->sbnFileList[bkFileIndex];

                offset = (bkFileEntry->offset & 0xFFFFFF) + soundData->baseRomOffset;
                fileEntry.offset = offset;

                data = bkFileEntry->data;
                fileEntry.data = data;

                if ((data >> 0x18) == AU_FMT_BK) {
                    snd_load_BK(offset, i);
                } else {
                    status = AU_ERROR_SBN_FORMAT_MISMATCH;
                }
            }
        }
    }

    return status;
}

BGMPlayer* func_80053F64(s32 arg0) {
    if (arg0 == 0) {
        return gSoundGlobals->unk_globals_6C[0].bgmPlayer;
    }
    return NULL;
}

#define SBN_LOOKUP(i,fmt,e) (au_fetch_SBN_file(globals->mseqFileList[AmbientSoundIDtoMSEQFileIndex[i]], fmt, &e))

AuResult func_80053F80(u32 ambSoundID) {
    AuAmbienceManager* manager;
    SBNFileEntry fileEntry;
    AuGlobals* globals;
    MSEQHeader* mseqFile;
    u32 i;

    globals = gSoundGlobals;
    manager = gAuAmbienceManager;
    if (ambSoundID < 16) {
        if (manager->mseqPlayers[0].mseqName == 0 && SBN_LOOKUP(ambSoundID, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
            au_read_rom(fileEntry.offset, globals->dataMSEQ[0], fileEntry.data & 0xFFFFFF);
            manager->mseqFiles[0] = globals->dataMSEQ[0];
            for (i = 1; i < ARRAY_COUNT(manager->mseqFiles); i++) {
                manager->mseqFiles[i] = NULL;
            }
            manager->unk_20 = 1;
        }
    } else if (ambSoundID == AMBIENT_RADIO
            && manager->mseqPlayers[0].mseqName == 0
            && manager->mseqPlayers[1].mseqName == 0
            && manager->mseqPlayers[2].mseqName == 0) {
        manager->unk_20 = 0;
        for (i = 0; i < ARRAY_COUNT(manager->mseqFiles); i++) {
            manager->mseqFiles[i] = NULL;
        }

        mseqFile = globals->dataMSEQ[1];
        if (SBN_LOOKUP(ambSoundID, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
            au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
            manager->mseqFiles[0] = mseqFile;

            mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
            if (SBN_LOOKUP(ambSoundID + 1, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                manager->mseqFiles[1] = mseqFile;

                mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
                if (SBN_LOOKUP(ambSoundID + 2, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                    au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                    manager->mseqFiles[2] = mseqFile;

                    mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
                    if (SBN_LOOKUP(ambSoundID + 3, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                        au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                        manager->mseqFiles[3] = mseqFile;

                        manager->unk_20 = 4;
                        if (SBN_LOOKUP(ambSoundID + 4, AU_FMT_BK, fileEntry) == AU_RESULT_OK) {
                            snd_load_BK(fileEntry.offset, 2);
                        }
                    }
                }
            }
        }
    }

    return AU_RESULT_OK;
}

BGMPlayer* func_80054248(u8 arg0) {
    switch (arg0) {
        case 1:
            return gBGMPlayerA;
        case 2:
            return gBGMPlayerB;
        case 4:
            return (BGMPlayer*)gSoundManager; // TODO: why return pointer to SoundManager?
        default:
            return NULL;
    }
}

void au_load_INIT(AuGlobals* arg0, s32 romAddr, ALHeap* heap) {
    SBNHeader sbnHeader;
    INITHeader initHeader;
    SBNFileEntry* entry;
    s32 tableSize, initBase, size;
    s32 tblAddr, shortsAddr;
    s32* data;
    s32 numEntries;
    s32 tblOffset, shortsOffset;
    s32* romPtr = &arg0->baseRomOffset;

    au_read_rom(romAddr, &sbnHeader, sizeof(SBNHeader));
    numEntries = sbnHeader.numEntries;
    arg0->baseRomOffset = romAddr;
    tableSize = numEntries * sizeof(SBNFileEntry);
    arg0->fileListLength = sbnHeader.numEntries;
    arg0->sbnFileList = alHeapAlloc(heap, 1, tableSize);
    au_read_rom(arg0->baseRomOffset + sbnHeader.tableOffset, arg0->sbnFileList, tableSize);

    entry = arg0->sbnFileList;
    while (sbnHeader.numEntries--) {
        if ((entry->offset & 0xFFFFFF) == 0) {
            break;
        }

        size = entry->data;
        entry->data = (size + 0xF) & ~0xF;
        entry++;
    }

    if (sbnHeader.INIToffset != 0) {
        initBase = *romPtr + sbnHeader.INIToffset;
        au_read_rom(initBase, &initHeader, sizeof(INITHeader));

        tblOffset = initHeader.tblOffset;
        size = (initHeader.tblSize + 0xF) & 0xFFF0;
        tblAddr = initBase + tblOffset;
        arg0->songList = alHeapAlloc(heap, 1, size);
        au_read_rom(tblAddr, arg0->songList, size);

        shortsOffset = initHeader.shortsOffset;
        size = (initHeader.shortsSize + 0xF) & 0xFFF0;
        shortsAddr = initBase + shortsOffset;
        arg0->mseqFileList = alHeapAlloc(heap, 1, size);
        au_read_rom(shortsAddr, arg0->mseqFileList, size);

        arg0->bkFileListOffset = initBase + initHeader.entriesOffset;
        arg0->bkListLength = (initHeader.entriesSize + 0xF) & 0xFFF0;
        arg0->songListLength = initHeader.tblSize / sizeof(InitSongEntry) - 1;
    }
}

AuResult au_fetch_SBN_file(u32 fileIdx, AuFileFormat format, SBNFileEntry* outEntry) {
    SBNFileEntry fileEntry;
    s32 status = AU_RESULT_OK;

    if (fileIdx < gSoundGlobals->fileListLength) {
        SBNFileEntry* entry = &gSoundGlobals->sbnFileList[fileIdx];
        s32 offset = (entry->offset & 0xFFFFFF) + gSoundGlobals->baseRomOffset;

        fileEntry.offset = offset;
        fileEntry.data = entry->data;
        if ((fileEntry.data >> 0x18) == format) {
            outEntry->offset = offset;
            outEntry->data = fileEntry.data;
        } else {
            status = AU_ERROR_SBN_FORMAT_MISMATCH;
        }
    } else {
        status = AU_ERROR_SBN_INDEX_OUT_OF_RANGE;
    }
    return status;
}

void au_load_PER(AuGlobals* globals, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    void* end;

    au_read_rom(romAddr, &header, sizeof(PERHeader));
    size = header.size - sizeof(PERHeader);
    au_read_rom(romAddr + sizeof(PERHeader), globals->dataPER, size);
    numItems = size / sizeof(PEREntry);
    numItemsLeft = 6 - numItems;
    if (numItemsLeft > 0) {
        end = &globals->dataPER[numItems];
        au_copy_words(&globals->defaultDrumEntry, end, sizeof(BGMDrumInfo));
        au_copy_words(end, end + sizeof(BGMDrumInfo), numItemsLeft * sizeof(PEREntry) - sizeof(BGMDrumInfo));
    }
}

void au_load_PRG(AuGlobals* arg0, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    s32 dataRomAddr;
    void* end;

    au_read_rom(romAddr, &header, sizeof(PERHeader));
    dataRomAddr = romAddr + sizeof(PERHeader);
    size = header.size - sizeof(PERHeader);
    if (size > 0x200) {
        size = 0x200;
    }
    au_read_rom(dataRomAddr, arg0->dataPRG, size);
    numItems = size / sizeof(BGMInstrumentInfo);
    numItemsLeft = 0x40 - numItems;
    if (numItemsLeft > 0) {
        end = &arg0->dataPRG[numItems];
        au_copy_words(&arg0->defaultPRGEntry, end, sizeof(BGMInstrumentInfo));
        au_copy_words(end, end + sizeof(BGMInstrumentInfo), numItemsLeft * sizeof(BGMInstrumentInfo) - sizeof(BGMInstrumentInfo));
    }
}

INCLUDE_ASM(s32, "audio/2e230_len_2190", snd_load_BGM);

InstrumentGroup* au_get_BK_instruments(s32 bankGroup, u32 bankIndex) {
    InstrumentGroup* ret = NULL;
    AuGlobals* temp = gSoundGlobals;

    // TODO fake match - this multiplying the bankIndex by 16 and then dividing it right after is dumb
    bankIndex *= 16;

    switch (bankGroup) {
        case 1:
            ret = &temp->instrumentGroup1[bankIndex / 16];
            break;
        case 2:
            ret = &temp->instrumentGroup2[bankIndex / 16];
            break;
        case 4:
            ret = &temp->instrumentGroup4[bankIndex / 16];
            break;
        case 5:
            ret = &temp->instrumentGroup5[bankIndex / 16];
            break;
        case 6:
            ret = &temp->instrumentGroup6[bankIndex / 16];
            break;
        case 3:
            ret = &temp->instrumentGroup3[bankIndex / 16];
            break;
    }

    return ret;
}

#ifdef NON_EQUIVALENT
enum BKParseState {
    EN_0 = 0,
    EN_11 = 11,
    EN_21 = 21,
    EN_101 = 101,
    EN_111 = 111,
    EN_201 = 201,
    EN_301 = 301,
};
s32 snd_load_BK_to_bank(s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 bankGroup) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKHeader bkHeader;
    BKHeader* header = &bkHeader;
    u16 s3;
    u16 s2;
    s32 size;
    u8* s4;
    InstrumentGroup* group;
    u32 i;
    s32 a2;

    au_read_rom(bkFileOffset, header, sizeof(BKHeader));
    s3 = EN_11;
    s2 = TRUE;
    do {
        switch (s3) {
            case EN_11:
                if (header->signature == 0x424B /* BK */ && header->size != 0) {
                    s3 = EN_21;
                } else {
                    s2 = FALSE;
                }
                break;
            case EN_21:
                if (header->format == 0x4352) { // CR
                    s3 = EN_101;
                } else if (header->format == 0x4452) { // DR
                    s3 = EN_201;
                } else if (header->format == 0x5352) { // SR
                    s3 = EN_301;
                } else {
                    s2 = FALSE;
                }
                break;
            case EN_101:
                size = ALIGN16_(header->instrumetsSize) + ALIGN16_(header->unkSizeA) + ALIGN16_(header->predictorsSize) + ALIGN16_(header->unkSizeB) + sizeof(BKHeader);
                if (bank == NULL) {
                    bank = alHeapAlloc(heap, 1, size);
                }
                au_read_rom(bkFileOffset, bank, size);
                group = au_get_BK_instruments(bankGroup, bankIndex);
                a2 = 0;
                for (i = 0; i < ARRAY_COUNT(*group); i++) {
                    if (header->instruments[i] != 0) {
                        (*group)[i] = (s32)bank + header->instruments[i];
                        a2++;
                    } else {
                        (*group)[i] = NULL;
                    }
                }

                if (a2 != 0) {
                    s3 = EN_111;
                } else {
                    s2 = FALSE;
                }
                break;
            case EN_111:
                au_swizzle_BK_instruments(bkFileOffset, bank, *group, 16, 1);
                s3 = 0;
                break;
            default:
                s2 = FALSE;
                break;
        }
    } while (s2);

    return bank;
}
#else
INCLUDE_ASM(s32, "audio/2e230_len_2190", snd_load_BK_to_bank, s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 arg3);
#endif

void au_swizzle_BK_instruments(s32 bkFileOffset, SoundBank* bank, InstrumentGroup instruments, u32 instrumentCount, u8 arg4) {
    Instrument* defaultInstrument = gSoundGlobals->defaultInstrument;
    SoundBank* sb = bank;
    f32 outputRate = gSoundGlobals->outputRate;
    s32 i;

    if (sb->swizzled == 0) {
        for (i = 0; i < instrumentCount; i++) {
            Instrument* instrument = instruments[i];

            if (instrument != NULL) {
                if (instrument->base != 0) {
                    instrument->base += bkFileOffset;
                }
                if (instrument->loopPredictor != NULL) {
                    instrument->loopPredictor = AU_FILE_RELATIVE(bank, instrument->loopPredictor);
                }
                if (instrument->predictor != NULL) {
                    instrument->predictor = AU_FILE_RELATIVE(bank, instrument->predictor);
                }
                if (instrument->unkOffset != NULL) {
                    instrument->unkOffset = AU_FILE_RELATIVE(bank, instrument->unkOffset);
                }
                instrument->unk_25 = arg4;
                instrument->pitchRatio = *((s32*)(&instrument->pitchRatio)) / outputRate; // what is happening here?
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        sb->swizzled = 1;
    }
}

#ifdef NON_MATCHING
enum ReadState {
    BK_READ_DONE            = 0,
    BK_READ_FETCH_HEADER    = 11,
    BK_READ_FETCH_DATA      = 21,
    BK_READ_SWIZZLE         = 31,
};

#define AL_HEADER_SIG_BK 0x424B
#define AL_HEADER_SIG_CR 0x4352

s32* func_80054AA0(s32* bkFileOffset, void* vaddr, s32 bankIndex, s32 bankGroup) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKHeader localHeader;
    BKHeader* header = &localHeader;
    Instrument** instrumentGroup;
    Instrument* instruments;
    u32 instrCount;
    u32 readState;
    s32 keepReading;
    void* fileData = vaddr;
    u32 i;

    fileData = vaddr;
    readState = BK_READ_FETCH_HEADER;
    keepReading = TRUE;

    while (keepReading) {
        switch (readState) {
            case BK_READ_DONE:
                keepReading = FALSE;
                break;
            case BK_READ_FETCH_HEADER:
                au_read_rom(*bkFileOffset, &localHeader, 0x40U);
                if ((header->signature == AL_HEADER_SIG_BK) && (header->size != 0) && (header->format == AL_HEADER_SIG_CR)) {
                    readState = BK_READ_FETCH_DATA;
                } else {
                    keepReading = FALSE;
                }
                break;
            case BK_READ_FETCH_DATA:
                if (vaddr == NULL) {
                    fileData = alHeapAlloc(heap, 1, header->size);
                }
                au_read_rom(*bkFileOffset, fileData, header->size);

                instrCount = 0;
                instrumentGroup = (Instrument**)au_get_BK_instruments(bankGroup, bankIndex);

                for (i = 0; i < 16; i++) {
                    if (header->instruments[i] != 0) {
                        instrumentGroup[i] = header->instruments[i] + fileData;
                        instrCount++;
                    } else {
                        instrumentGroup[i] = NULL;
                    }
                }

                if (instrCount != 0) {
                    readState = BK_READ_SWIZZLE;
                } else {
                    keepReading = FALSE;
                }
                break;
            case BK_READ_SWIZZLE:
                au_swizzle_BK_instruments(fileData, fileData, instrumentGroup, 0x10U, 0);
                readState = BK_READ_DONE;
                break;
            default:
                keepReading = FALSE;
                break;
        }
    }
    return fileData;
}
#else
INCLUDE_ASM(s32, "audio/2e230_len_2190", func_80054AA0);
#endif

s32 snd_load_BK(s32 bkFileOffset, s32 bankIndex) {
    snd_load_BK_to_bank(bkFileOffset, gSoundGlobals->banks[bankIndex], bankIndex, 1);
    return 0;
}

void func_80054C84(s32 bankIndex, s32 bankGroup) {
    u32 i;
    Instrument* instrument = gSoundGlobals->defaultInstrument;
    InstrumentGroup* group =  au_get_BK_instruments(bankGroup, bankIndex);
    Instrument** ptr = *group;
    if (group != NULL) {
        for (i = 0; i < ARRAY_COUNT(*group); i++) {
            *ptr++ = instrument;
        }
    }
}

void func_80054CE0(s32 arg0, u32 idx) {
    if (idx < ARRAY_COUNT(D_80078530)) {
        s32 temp_s0 = D_80078530[idx];
        if (arg0 & 1) {
            gBGMPlayerA->unk_48 = temp_s0;
            func_80053AC8(&gBGMPlayerA->fadeInfo);
            gBGMPlayerB->unk_48 = temp_s0;
            func_80053AC8(&gBGMPlayerB->fadeInfo);
        }
        if (arg0 & 0x10) {
            gSoundManager->unk_5C = temp_s0;
            func_80053AC8(&gSoundManager->fadeInfo);
        }
    }
}

s32 func_80054D74(s32 arg0, s32 arg1) {
    if (arg0 & 0x10) {
        return func_8004B9E4(gSoundManager, arg1);
    }
    return 0;
}

void func_80054DA8(u32 bMonoSound) {
    if (bMonoSound % 2 == 1) {
        // mono sound
        if (gSoundGlobals->unk_130C == 0) {
            gSoundGlobals->unk_130C = 2;
        }
    } else {
        // stereo sound
        if (gSoundGlobals->unk_130C != 0) {
            gSoundGlobals->unk_50 = 1;
            gSoundGlobals->unk_130C = 0;
        }
    }
}

void au_read_rom(s32 romAddr, void* buffer, u32 size) {
    s32 nchunks = size / 0x2000;
    s32 offset = 0;

    if (nchunks != 0) {
        while (nchunks--) {
            nuPiReadRom(romAddr + offset, buffer + offset, 0x2000);
            offset += 0x2000;
        }
    }

    size %= 0x2000;
    if (size != 0) {
        nuPiReadRom(romAddr + offset, buffer + offset, size);
    }
}

void au_memset(void* dst, s32 size, u8 value) {
    s32 count;
    s32 intValue;

    if (size == 0) {
        return;
    }

    if (size < 1024) {
        while (size--) {
            *(u8*)dst++ = value;
        }
    } else {
        count = (u32)dst & 0x3;
        if (count != 0) {
            count = 4 - count;
            size -= count;
            while (count--) {
                *(u8*)dst++ = value;
            }
        }

        count = size >> 2;
        intValue = (value << 8) + value;
        intValue = (intValue << 16) + intValue;
        while (count--) {
            *(u32*)dst = intValue;
            dst += 4;
        }

        count = size & 3;
        if (count != 0) {
            while (count--) {
                *(u8*)dst++ = value;
            }
        }
    }
}

void au_copy_bytes(s8* src, s8* dest, s32 size) {
    if (size > 0) {
        while (size-- != 0) {
            *dest++ = *src++;
        }
    }
}

void au_copy_words(void* src, void* dst, s32 size) {
    size /= 4;

    if (size > 0) {
        if (!(((s32) src | (s32) dst) & 3)) {
            s32* srcIt = src;
            s32* dstIt = dst;

            size--;
            do {
                *dstIt++ = *srcIt++;
            } while (size-- != 0);
        }
    }
}
