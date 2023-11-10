#include "audio.h"
#include "ld_addrs.h"

SHIFT_BSS AuCallback BeginSoundUpdateCallback;
SHIFT_BSS BGMPlayer* gBGMPlayerA;
SHIFT_BSS BGMPlayer* gBGMPlayerB;
SHIFT_BSS BGMPlayer* gBGMPlayerC;
SHIFT_BSS SoundManager* gSoundManager;
SHIFT_BSS AuGlobals* gSoundGlobals;
SHIFT_BSS AmbienceManager* gAuAmbienceManager;

// data
extern u16 D_80078530[9];
extern u8 EnvelopePressDefault[];
extern u8 EnvelopeReleaseDefault[];
extern f32 AlTuneScaling[];

#ifdef SHIFT
#define SBN_ROM_OFFSET (s32) audio_ROM_START
#elif VERSION_JP
#define SBN_ROM_OFFSET 0xFC0000
#else
#define SBN_ROM_OFFSET 0xF00000
#endif

void func_80052E30(u8 index) {
    AuVoice* voice = &gSoundGlobals->voices[index];

    voice->cmdPtr = NULL;
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

    for (i = 0; i < ARRAY_COUNT(globals->unk_globals_6C); i++) {
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

    for (i = 0; i < ARRAY_COUNT(globals->unk_globals_6C); i++) {
        globals->unk_globals_6C[i].unk_4 = 0;
        globals->unk_globals_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        globals->effectChanges[i].type = AU_FX_NONE;
        globals->effectChanges[i].changed = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice;
        au_pvoice_set_bus(i, 0);
        au_syn_set_wavetable(i, globals->defaultInstrument);
        voice = &globals->voices[i];
        voice->instrument = NULL;
        voice->pitchRatio = 0;
        voice->p_volume = -1;
        voice->pan = 0xFF;
        voice->reverb = 0xFF;
        voice->busId = 0;
        voice->stopPending = FALSE;
        voice->syncFlags = 0;
        voice->clientPriority = AU_PRIORITY_FREE;
        voice->priority = AU_PRIORITY_FREE;
    }

    au_load_INIT(globals, SBN_ROM_OFFSET, alHeap);

    for (i = 0; i < ARRAY_COUNT(globals->banks); i++) {
        globals->banks[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    au_bgm_player_init(gBGMPlayerA, AU_PRIORITY_BGM_PLAYER_MAIN, FX_BUS_BGMA_MAIN, globals);
    effects[0] = FX_BUS_BGMA_MAIN;
    effects[1] = FX_BUS_BGMA_AUX;
    effects[2] = -1;
    effects[3] = -1;
    au_bgm_set_effect_indices(gBGMPlayerA, effects);

    au_bgm_player_init(gBGMPlayerB, AU_PRIORITY_BGM_PLAYER_AUX, FX_BUS_BGMB, globals);
    effects[0] = FX_BUS_BGMB;
    effects[1] = -1;
    effects[2] = -1;
    effects[3] = -1;
    au_bgm_set_effect_indices(gBGMPlayerB, effects);

    au_sfx_init(gSoundManager, AU_PRIORITY_SFX_MANAGER, FX_BUS_SOUND, globals, 16);
    au_amb_manager_init(gAuAmbienceManager, AU_PRIORITY_MSEQ_MANAGER, FX_BUS_SOUND, globals);
    au_init_voices(globals);
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
    globals->channelDelaySide = 0;
    globals->channelDelayTime = 0;
    globals->channelDelayBusId = 0;
    globals->channelDelayPending = 0;

    au_delay_channel(0);
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
    instrument->envelopes = &DummyInstrumentEnvelope;
    instrument->unk_26 = 0;
    instrument->unk_27 = 0;
    instrument->unk_28 = 0;
    instrument->unk_29 = 0;
    instrument->unk_2A = 0;
    instrument->unk_2B = 0;
    instrument->pitchRatio = 0.5f;
}

static void au_reset_drum_entry(BGMDrumInfo* arg0) {
    arg0->bankPatch = 0x2010;
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
    AmbienceManager* ambManager = gAuAmbienceManager;
    BGMPlayer* bgmPlayer;

    au_syn_update(globals);

    ambManager->nextUpdateCounter -= ambManager->nextUpdateStep;
    if (ambManager->nextUpdateCounter <= 0) {
        ambManager->nextUpdateCounter += ambManager->nextUpdateInterval;
        au_amb_manager_update(ambManager);
    }

    if (sfxManager->fadeInfo.fadeTime != 0) {
        au_fade_update(&sfxManager->fadeInfo);
        au_fade_set_volume(sfxManager->busId, sfxManager->fadeInfo.curVolume.u16, sfxManager->busVolume);
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
    au_update_voices(globals);
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

void au_syn_update(AuGlobals* globals) {
    u32 i;

    if (globals->unk_130C == 2) {
        globals->unk_130C = 1;
        au_disable_channel_delay();
    }

    if (globals->channelDelayPending && (globals->unk_130C == 0)) {
        switch (globals->channelDelaySide) {
            case 1:
                au_set_delay_time(globals->channelDelayTime);
                au_delay_left_channel(globals->channelDelayBusId);
                globals->channelDelayPending = FALSE;
                break;
            case 2:
                au_set_delay_time(globals->channelDelayTime);
                au_delay_right_channel(globals->channelDelayBusId);
                globals->channelDelayPending = FALSE;
                break;
            default:
                au_disable_channel_delay();
                globals->channelDelayPending = FALSE;
                break;
        }
    }

    if (globals->effectChanges[FX_BUS_BGMA_MAIN].changed) {
        au_bus_set_effect(FX_BUS_BGMA_MAIN, globals->effectChanges[FX_BUS_BGMA_MAIN].type);
        globals->effectChanges[FX_BUS_BGMA_MAIN].changed = FALSE;
    }
    if (globals->effectChanges[FX_BUS_SOUND].changed) {
        au_bus_set_effect(FX_BUS_SOUND, globals->effectChanges[FX_BUS_SOUND].type);
        globals->effectChanges[FX_BUS_SOUND].changed = FALSE;

    } if (globals->effectChanges[FX_BUS_BGMB].changed) {
        au_bus_set_effect(FX_BUS_BGMB, globals->effectChanges[FX_BUS_BGMB].type);
        globals->effectChanges[FX_BUS_BGMB].changed = FALSE;
    }
    if (globals->effectChanges[FX_BUS_BGMA_AUX].changed) {
        au_bus_set_effect(FX_BUS_BGMA_AUX, globals->effectChanges[FX_BUS_BGMA_AUX].type);
        globals->effectChanges[FX_BUS_BGMA_AUX].changed = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice = &globals->voices[i];
        u8 voiceUpdateFlags = voice->syncFlags;

        if (voice->stopPending) {
            au_syn_stop_voice(i);
            voice->stopPending = FALSE;
            voice->cmdPtr = NULL;
            voice->priority = AU_PRIORITY_FREE;
        }

        if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_ALL) {
            au_voice_start(voice, &voice->envelope);
            au_syn_start_voice_params(i, voice->busId, voice->instrument, voice->pitchRatio, voice->p_volume, voice->pan, voice->reverb, voice->delta);
            // priority may be AU_PRIORITY_FREE if this voice was stolen and reset
            voice->priority = voice->clientPriority;
        } else {
            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_PITCH) {
                au_syn_set_pitch(i, voice->pitchRatio);
            }

            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_PARAMS) {
                au_syn_set_mixer_params(i, voice->p_volume, voice->delta, voice->pan, voice->reverb);
            } else if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_PAN_FXMIX) {
                au_syn_set_pan_fxmix(i, voice->pan, voice->reverb);
            }
        }
        voice->syncFlags = 0;
    }
}

void au_reset_nonfree_voice(AuVoice* voice, u8 index) {
    if (voice->priority != AU_PRIORITY_FREE) {
        voice->cmdPtr = NULL;
        voice->stopPending = TRUE;
        voice->syncFlags = 0;
        au_syn_set_volume_delta(index, 0, AUDIO_SAMPLES);
    }
}

// uncertain name
void au_reset_voice(AuVoice* voice, u8 voiceIdx) {
    voice->cmdPtr = NULL;
    voice->stopPending = TRUE;
    voice->syncFlags = 0;
    au_syn_set_volume_delta(voiceIdx, 0, AUDIO_SAMPLES);
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
    fade->curVolume.s32 = startValue * 0x10000;
    fade->targetVolume = endValue;

    if (time != 0) {
        fade->fadeTime = (time * 1000) / AU_5750;
        fade->fadeStep = (endValue * 0x10000 - fade->curVolume.s32) / fade->fadeTime;
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
        fade->curVolume.s32 += fade->fadeStep;
    } else {
        fade->curVolume.s32 = fade->targetVolume << 0x10;
        if (fade->onCompleteCallback != NULL) {
            fade->onCompleteCallback();
            fade->fadeStep = 0;
            fade->onCompleteCallback = NULL;
        }
    }
}

void au_fade_set_volume(u8 busId, u16 volume, s32 busVolume) {
    au_bus_set_volume(busId, (u32)(volume * busVolume) >> 15);
}

void func_80053AC8(Fade* fade) {
    if (fade->fadeTime == 0) {
        fade->fadeTime = 1;
        fade->fadeStep = 0;
        fade->targetVolume = fade->curVolume.u16;
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
Instrument* au_get_instrument(AuGlobals* globals, u32 bank, u32 patch, EnvelopeData* envData) {
    Instrument* instrument = (*globals->instrumentGroups[(bank & 0x70) >> 4])[patch];
    EnvelopePreset* preset = instrument->envelopes;
    u32 envelopeIdx = bank & 3;

    if (envelopeIdx < preset->count) {
        envData->cmdListPress = AU_FILE_RELATIVE(preset, preset->offsets[envelopeIdx].offsetPress);
        envData->cmdListRelease = AU_FILE_RELATIVE(preset, preset->offsets[envelopeIdx].offsetRelease);
    } else {
        envData->cmdListPress = EnvelopePressDefault;
        envData->cmdListRelease = &EnvelopePressDefault[4]; //EnvelopeReleaseDefault;
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

        for (i = 0; i < ARRAY_COUNT(songInfo->bkFileIndex); i++) {
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
    u16 bkFileIndex;

    soundData = gSoundGlobals;
    songInfo = &soundData->songList[songID];
    status =  au_fetch_SBN_file(songInfo[0].bgmFileIndex, AU_FMT_BGM, &sbnEntry);
    if (status == AU_RESULT_OK) {
        au_read_rom(sbnEntry.offset, bgmFile, sbnEntry.data & 0xFFFFFF);

        for (i = 0; i < ARRAY_COUNT(songInfo->bkFileIndex); i++) {
            bkFileIndex = songInfo->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &soundData->sbnFileList[bkFileIndex];

                fileEntry.offset = (bkFileEntry->offset & 0xFFFFFF) + soundData->baseRomOffset;
                fileEntry.data = bkFileEntry->data;

                if ((fileEntry.data >> 0x18) == AU_FMT_BK) {
                    snd_load_BK(fileEntry.offset, i);
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

AuResult au_ambient_load(u32 ambSoundID) {
    AmbienceManager* manager;
    SBNFileEntry fileEntry;
    AuGlobals* globals;
    MSEQHeader* mseqFile;
    u32 i;

    globals = gSoundGlobals;
    manager = gAuAmbienceManager;
    if (ambSoundID < AMBIENT_RADIO) {
        if (manager->players[0].mseqName == 0 && SBN_LOOKUP(ambSoundID, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
            au_read_rom(fileEntry.offset, globals->dataMSEQ[0], fileEntry.data & 0xFFFFFF);
            manager->mseqFiles[0] = globals->dataMSEQ[0];
            for (i = 1; i < ARRAY_COUNT(manager->mseqFiles); i++) {
                manager->mseqFiles[i] = NULL;
            }
            manager->numActivePlayers = 1;
        }
    } else if (ambSoundID == AMBIENT_RADIO
            && manager->players[0].mseqName == 0
            && manager->players[1].mseqName == 0
            && manager->players[2].mseqName == 0) {
        manager->numActivePlayers = 0;
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

                        manager->numActivePlayers = 4;
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

    au_read_rom(romAddr, &sbnHeader, sizeof(sbnHeader));
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
        au_read_rom(initBase, &initHeader, sizeof(initHeader));

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

    au_read_rom(romAddr, &header, sizeof(header));
    size = header.mdata.size - sizeof(header);
    au_read_rom(romAddr + sizeof(header), globals->dataPER, size);
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

    au_read_rom(romAddr, &header, sizeof(header));
    dataRomAddr = romAddr + sizeof(header);
    size = header.mdata.size - sizeof(header);
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

s32 snd_load_BGM(s32 arg0) {
    AuGlobals* globals = gSoundGlobals;
    InitSongEntry* song = globals->songList;
    s32 ret = 0;
    s32 i;

    while (TRUE) {
        if (song->bgmFileIndex == 0xFFFF) {
            return ret;
        }

        if (song->bgmFileIndex == arg0) {
            for (i = 0; i < ARRAY_COUNT(song->bkFileIndex); i++) {
                u16 bkFileIndex = song->bkFileIndex[i];
                if (bkFileIndex != 0) {
                    SBNFileEntry* bkFileEntry = &globals->sbnFileList[bkFileIndex];
                    SBNFileEntry fileEntry;

                    fileEntry.offset = (bkFileEntry->offset & 0xFFFFFF) + globals->baseRomOffset;
                    fileEntry.data = bkFileEntry->data;
                    if ((fileEntry.data >> 0x18) == 0x30) {
                        snd_load_BK(fileEntry.offset, i);
                    } else {
                        ret = 0x66;
                    }
                }
            }

            return ret;
        }
        song++;
    }
}

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

enum BKParseState {
    BK_READ_DONE          = 0,
    BK_READ_FETCH_HEADER  = 11,
    BK_READ_FETCH_DATA    = 21,
    BK_READ_SWIZZLE       = 31,
    BK_READ_PROCESS_CR    = 101,
    BK_READ_SWIZZLE_CR    = 111,
    BK_READ_PROCESS_DR    = 201,
    BK_READ_UNK_DR        = 211,
    BK_READ_PROCESS_SR    = 301,
    BK_READ_UNK_SR        = 311,
};

#define AL_HEADER_SIG_BK 0x424B
#define AL_HEADER_SIG_CR 0x4352
#define AL_HEADER_SIG_DR 0x4452
#define AL_HEADER_SIG_SR 0x5352

SoundBank* au_load_BK_to_bank(s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 bankGroup) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKHeader bkHeader;
    BKHeader* header = &bkHeader;
    u16 keepReading;
    u16 readState;
    InstrumentGroup* group;
    Instrument** inst;
    s32 instrumentCount;
    s32 size;
    u32 i;

    au_read_rom(bkFileOffset, header, sizeof(*header));
    readState = BK_READ_FETCH_HEADER;
    keepReading = TRUE;

    while (keepReading) {
        switch (readState) {
            case BK_READ_DONE:
                keepReading = FALSE;
                break;
            case BK_READ_FETCH_HEADER:
                if (header->signature != AL_HEADER_SIG_BK) {
                    keepReading = FALSE;
                } else if (header->size == 0) {
                    keepReading = FALSE;
                } else {
                    readState = BK_READ_FETCH_DATA;
                }
                break;
            case BK_READ_FETCH_DATA:
                if (header->format == AL_HEADER_SIG_CR) {
                    readState = BK_READ_PROCESS_CR;
                } else if (header->format == AL_HEADER_SIG_DR) {
                    readState = BK_READ_PROCESS_DR;
                } else if (header->format == AL_HEADER_SIG_SR) {
                    readState = BK_READ_PROCESS_SR;
                } else {
                    keepReading = FALSE;
                }
                break;

            case BK_READ_PROCESS_CR:
                size = ALIGN16_(header->instrumetsSize)
                    + ALIGN16_(header->unkSizeA)
                    + ALIGN16_(header->predictorsSize)
                    + ALIGN16_(header->unkSizeB)
                    + sizeof(*header);
                if (bank == NULL) {
                    bank = alHeapAlloc(heap, 1, size);
                }
                au_read_rom(bkFileOffset, bank, size);

                group = au_get_BK_instruments(bankGroup, bankIndex);
                inst = (*group);
                instrumentCount = 0;

                for (i = 0; i < ARRAY_COUNT(header->instruments); inst++, i++) {
                    u16 instOffset = header->instruments[i];
                    if (instOffset != 0) {
                        instrumentCount++;
                        *inst = AU_FILE_RELATIVE(bank, instOffset);
                    } else {
                        *inst = NULL;
                    }
                }

                if (instrumentCount != 0) {
                    readState = BK_READ_SWIZZLE_CR;
                } else {
                    keepReading = FALSE;
                }
                break;
            case BK_READ_SWIZZLE_CR:
                au_swizzle_BK_instruments(bkFileOffset, bank, *group, 16, 1);
                readState = BK_READ_DONE;
                break;

            // inferred states
            case BK_READ_PROCESS_DR:
            case BK_READ_UNK_DR:
            case BK_READ_PROCESS_SR:
            case BK_READ_UNK_SR:
            default:
                keepReading = FALSE;
                break;
        }
    }

    return bank;
}

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
                if (instrument->envelopes != NULL) {
                    instrument->envelopes = AU_FILE_RELATIVE(bank, instrument->envelopes);
                }
                instrument->unk_25 = arg4;
                instrument->pitchRatio = instrument->outputRate / outputRate;
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        sb->swizzled = 1;
    }
}

s32* func_80054AA0(s32* bkFileOffset, void* vaddr, s32 bankIndex, s32 bankGroup) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKHeader localHeader;
    void* fileData = vaddr;
    BKHeader* header = &localHeader;
    InstrumentGroup* group;
    Instrument* instruments;
    Instrument** inst;
    u32 instrCount;
    u32 readState;
    s32 keepReading;

    u32 i;
    s32 swizzleArg;
    swizzleArg = 0;
    readState = BK_READ_FETCH_HEADER;
    keepReading = TRUE;


    while (keepReading) {
        switch (readState) {
            case BK_READ_DONE:
                keepReading = FALSE;
                break;
            case BK_READ_FETCH_HEADER:
                au_read_rom(*bkFileOffset, &localHeader, sizeof(localHeader));
                if (header->signature != AL_HEADER_SIG_BK) {
                    keepReading = FALSE;
                } else if (header->size == 0) {
                    keepReading = FALSE;
                } else if (header->format != AL_HEADER_SIG_CR) {
                    keepReading = FALSE;
                } else {
                    readState = BK_READ_FETCH_DATA;
                }
                break;
            case BK_READ_FETCH_DATA:
                if (fileData == NULL) {
                    fileData = alHeapAlloc(heap, 1, header->size);
                }
                au_read_rom(*bkFileOffset, fileData, header->size);

                instrCount = 0;
                group = au_get_BK_instruments(bankGroup, bankIndex);
                inst = (*group);
                for(i = 0; i < ARRAY_COUNT(header->instruments); inst++, i++) {
                    u16 instOffset = header->instruments[i];
                    if(instOffset != 0) {
                        instrCount++;
                        *inst = AU_FILE_RELATIVE(fileData, instOffset);
                    } else {
                        *inst =  NULL;
                    }
                }

                if (instrCount != 0) {
                    readState = BK_READ_SWIZZLE;
                } else {
                    keepReading = FALSE;
                }
                break;
            case BK_READ_SWIZZLE:
                au_swizzle_BK_instruments((s32)fileData, fileData, *group, 0x10U, swizzleArg);
                readState = BK_READ_DONE;
                break;
            default:
                keepReading = FALSE;
                break;
        }
    }
    return fileData;
}

s32 snd_load_BK(s32 bkFileOffset, s32 bankIndex) {
    au_load_BK_to_bank(bkFileOffset, gSoundGlobals->banks[bankIndex], bankIndex, 1);
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
            gBGMPlayerA->busVolume = temp_s0;
            func_80053AC8(&gBGMPlayerA->fadeInfo);
            gBGMPlayerB->busVolume = temp_s0;
            func_80053AC8(&gBGMPlayerB->fadeInfo);
        }
        if (arg0 & 0x10) {
            gSoundManager->busVolume = temp_s0;
            func_80053AC8(&gSoundManager->fadeInfo);
        }
    }
}

s32 func_80054D74(s32 arg0, s32 arg1) {
    if (arg0 & 0x10) {
        return au_sfx_set_reverb_type(gSoundManager, arg1);
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
            gSoundGlobals->channelDelayPending = 1;
            gSoundGlobals->unk_130C = 0;
        }
    }
}

// probable split

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
