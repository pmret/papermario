#include "audio.h"
#include "ld_addrs.h"

AuCallback BeginSoundUpdateCallback;
BGMPlayer* gBGMPlayerA;
BGMPlayer* gBGMPlayerB;
BGMPlayer* gBGMPlayerC;
SoundManager* gSoundManager;
AuGlobals* gSoundGlobals;
AmbienceManager* gAuAmbienceManager;

// data
extern u16 PerceptualVolumeLevels[9];
extern u8 EnvelopePressDefault[];
extern u8 EnvelopeReleaseDefault[];
extern f32 AlTuneScaling[];

#ifdef SHIFT
#define SBN_ROM_OFFSET (s32) audio_ROM_START
#elif VERSION_JP
#define SBN_ROM_OFFSET 0xFC0000
#elif VERSION_PAL
#define SBN_ROM_OFFSET 0x13A0000
#else
#define SBN_ROM_OFFSET 0xF00000
#endif

void au_release_voice(u8 index) {
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

    for (i = 0; i < ARRAY_COUNT(globals->effectChanges); i++) {
        globals->effectChanges[i].type = AU_FX_NONE;
        globals->effectChanges[i].changed = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice;
        au_pvoice_set_bus(i, FX_BUS_BGMA_MAIN);
        au_syn_set_wavetable(i, globals->defaultInstrument);
        voice = &globals->voices[i];
        voice->instrument = NULL;
        voice->pitchRatio = 0;
        voice->volume = -1;
        voice->pan = 0xFF;
        voice->reverb = 0xFF;
        voice->busID = 0;
        voice->stopPending = FALSE;
        voice->syncFlags = 0;
        voice->clientPriority = AU_PRIORITY_FREE;
        voice->priority = AU_PRIORITY_FREE;
    }

    au_load_INIT(globals, SBN_ROM_OFFSET, alHeap);

    for (i = 0; i < ARRAY_COUNT(globals->auxBanks); i++) {
        globals->auxBanks[i] = alHeapAlloc(alHeap, 1, sizeof(BKFileBuffer));
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
    if (au_fetch_SBN_file(globals->extraFileList[0], AU_FMT_SEF, &fileEntry) == AU_RESULT_OK) {
        au_read_rom(fileEntry.offset, globals->dataSEF, fileEntry.data & 0xFFFFFF);
    }
    au_sfx_load_groups_from_SEF(gSoundManager);
    if (au_fetch_SBN_file(globals->extraFileList[1], AU_FMT_PER, &fileEntry) == AU_RESULT_OK) {
        au_load_PER(globals, fileEntry.offset);
    }
    if (au_fetch_SBN_file(globals->extraFileList[2], AU_FMT_PRG, &fileEntry) == AU_RESULT_OK) {
        au_load_PRG(globals, fileEntry.offset);
    }

    globals->bankSets[BANK_SET_IDX_0] = globals->auxBankSet;
    globals->bankSets[BANK_SET_IDX_1] = globals->bankSet2;
    globals->bankSets[BANK_SET_IDX_2] = globals->defaultBankSet;
    globals->bankSets[BANK_SET_IDX_3] = globals->musicBankSet;
    globals->bankSets[BANK_SET_IDX_4] = globals->bankSet4;
    globals->bankSets[BANK_SET_IDX_5] = globals->bankSet5;
    globals->bankSets[BANK_SET_IDX_6] = globals->bankSet6;
    globals->bankSets[BANK_SET_IDX_7] = globals->auxBankSet;

    globals->channelDelaySide = AU_DELAY_CHANNEL_NONE;
    globals->channelDelayTime = 0;
    globals->channelDelayBusID = 0;
    globals->channelDelayPending = FALSE;

    au_init_delay_channel(0);
    func_80055050(alHeap);
}

/// used to initialize the default Instrument
static void au_reset_instrument(Instrument* instrument) {
    instrument->wavData = DummyInstrumentWavData;
    instrument->wavDataLength = sizeof(DummyInstrumentWavData);
    instrument->predictor = DummyInstrumentCodebook;
    instrument->codebookSize = sizeof(DummyInstrumentCodebook);
    instrument->keyBase = DEFAULT_KEYBASE;
    instrument->loopState = NULL;
    instrument->loopStart = 0;
    instrument->loopEnd = 0;
    instrument->loopCount = 0;
    instrument->type = 0;
    instrument->useDma = FALSE;
    instrument->envelopes = &DummyInstrumentEnvelope;
    instrument->unused_26 = 0;
    instrument->unused_27 = 0;
    instrument->unused_28 = 0;
    instrument->unused_29 = 0;
    instrument->unused_2A = 0;
    instrument->unused_2B = 0;
    instrument->pitchRatio = 0.5f;
}

/// used to initialize the default BGMDrumInfo
static void au_reset_drum_entry(BGMDrumInfo* info) {
    // @bug index 0x10 will overflow defaultBankSet and choose first instrument from musicBankSet instead?
    info->bankPatch = (BANK_SET_IDX_2 << 12) | 0x10;
    info->keyBase = DEFAULT_KEYBASE;
    info->volume = AU_MAX_VOLUME_8;
    info->pan = 64;
    info->reverb = 0;
    info->randTune = 0;
    info->randVolume = 0;
    info->randPan = 0;
    info->randReverb = 0;
}

/// used to initialize the default BGMInstrumentInfo
static void au_reset_instrument_entry(BGMInstrumentInfo* info) {
    // @bug index 0x10 will overflow defaultBankSet and choose first instrument from musicBankSet instead?
    info->bankPatch = (BANK_SET_IDX_2 << 12) | 0x10;
    info->volume = AU_MAX_VOLUME_8;
    info->pan = 64;
    info->reverb = 0;
    info->coarseTune = 0;
    info->fineTune = 0;
}

/// Called exactly once per audio frame (every 5.75ms at 32kHz).
/// Updates synthesizer, ambience, SFX, and BGM players for the current audio frame.
void au_update_clients_for_audio_frame(void) {
    AuGlobals* globals = gSoundGlobals;
    SoundManager* sfxManager = gSoundManager;
    AmbienceManager* ambManager = gAuAmbienceManager;
    BGMPlayer* bgmPlayer;

    au_syn_begin_audio_frame(globals);

    // Update ambience manager every other frame
    ambManager->nextUpdateCounter -= ambManager->nextUpdateStep;
    if (ambManager->nextUpdateCounter <= 0) {
        ambManager->nextUpdateCounter += ambManager->nextUpdateInterval;
        au_amb_manager_audio_frame_update(ambManager);
    }

     // Update volume fade for SFX bus
    if (sfxManager->fadeInfo.fadeTime != 0) {
        au_fade_update(&sfxManager->fadeInfo);
        au_fade_set_volume(sfxManager->busID, sfxManager->fadeInfo.curVolume.u16, sfxManager->busVolume);
    }

    // Periodic SFX manager update
    sfxManager->nextUpdateCounter -= sfxManager->nextUpdateStep;
    if (sfxManager->nextUpdateCounter <= 0) {
        sfxManager->nextUpdateCounter += sfxManager->nextUpdateInterval;
        sfxManager->prevUpdateResult = au_sfx_manager_audio_frame_update(sfxManager);
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
            bgmPlayer->prevUpdateResult = au_bgm_player_audio_frame_update(bgmPlayer);
        }
    }

    if (!PreventBGMPlayerUpdate) {
        if (globals->unk_80 != 0) {
            func_8004DFD4(globals);
        }
        bgmPlayer = gBGMPlayerA;
        if (bgmPlayer->fadeInfo.volScaleTime != 0) {
            au_unk_80053BA8(&bgmPlayer->fadeInfo);
            if (bgmPlayer->fadeInfo.fadeTime == 0) {
                au_bgm_update_bus_volumes(bgmPlayer);
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
            bgmPlayer->prevUpdateResult = au_bgm_player_audio_frame_update(bgmPlayer);
        }
    }
    au_update_voices(globals);
}

void au_update_clients_for_video_frame(void) {
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

    au_bgm_begin_video_frame(player);

    player = gBGMPlayerB;
    au_bgm_begin_video_frame(player);

    au_sfx_begin_video_frame(manager);
}

void au_syn_begin_audio_frame(AuGlobals* globals) {
    u32 i;

    if (globals->unk_130C == 2) {
        globals->unk_130C = 1;
        au_disable_channel_delay();
    }

    if (globals->channelDelayPending && (globals->unk_130C == 0)) {
        switch (globals->channelDelaySide) {
            case AU_DELAY_CHANNEL_LEFT:
                au_set_delay_time(globals->channelDelayTime);
                au_delay_left_channel(globals->channelDelayBusID);
                globals->channelDelayPending = FALSE;
                break;
            case AU_DELAY_CHANNEL_RIGHT:
                au_set_delay_time(globals->channelDelayTime);
                au_delay_right_channel(globals->channelDelayBusID);
                globals->channelDelayPending = FALSE;
                break;
            default:
                au_disable_channel_delay();
                globals->channelDelayPending = FALSE;
                break;
        }
    }

    // handle effect bus changes
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
            au_syn_start_voice_params(i, voice->busID, voice->instrument, voice->pitchRatio, voice->volume, voice->pan, voice->reverb, voice->delta);
            // priority may be AU_PRIORITY_FREE if this voice was stolen and reset
            voice->priority = voice->clientPriority;
        } else {
            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_PITCH) {
                au_syn_set_pitch(i, voice->pitchRatio);
            }

            if (voiceUpdateFlags & AU_VOICE_SYNC_FLAG_PARAMS) {
                au_syn_set_mixer_params(i, voice->volume, voice->delta, voice->pan, voice->reverb);
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

f32 au_compute_pitch_ratio(s32 tuning) {
    if (tuning >= 0) {
        return AlTuneScaling[(tuning & 0x7F) + TUNE_SCALING_ARR_AMPLIFY_FINE]
            * AlTuneScaling[((tuning & 0xF80) >> 7) + TUNE_SCALING_ARR_AMPLIFY_COARSE];
    } else {
        tuning = -tuning;
        return AlTuneScaling[(tuning & 0x7F) + TUNE_SCALING_ARR_ATTENUATE_FINE]
            * AlTuneScaling[((tuning & 0x3F80) >> 7) + TUNE_SCALING_ARR_ATTENUATE_COARSE];
    }
}

void au_fade_init(Fade* fade, s32 time, s32 startValue, s32 endValue) {
    fade->curVolume.s32 = startValue << 16;
    fade->targetVolume = endValue;

    if (time != 0) {
        fade->fadeTime = (time * 1000) / AU_FRAME_USEC;
        fade->fadeStep = ((endValue << 16) - fade->curVolume.s32) / fade->fadeTime;
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

void au_fade_set_volume(u8 busID, u16 volume, s32 busVolume) {
    au_bus_set_volume(busID, (u32)(volume * busVolume) / AU_MAX_BUS_VOLUME);
}

void au_unk_80053AC8(Fade* fade) {
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

void au_unk_80053B04(Fade* fade, u32 arg1, s32 target) {
    s16 time;
    s32 delta;

    if (arg1 >= 250 && arg1 <= 100000) {
        time = (s32)(arg1 * 1000) / AU_FRAME_USEC;
        delta = (target << 16) - fade->volScale.s32;

        fade->targetVolScale = target;
        fade->volScaleTime = time;
        fade->volScaleStep = delta / time;
    } else {
        fade->volScaleTime = 0;
        fade->volScaleStep = 0;
    }
}

void au_unk_80053BA8(Fade* fade) {
    fade->volScaleTime--;

    if (fade->volScaleTime != 0) {
        fade->volScale.s32 += fade->volScaleStep;
    } else {
        fade->volScaleStep = 0;
        fade->volScale.s32 = fade->targetVolScale << 16;
    }
}

//TODO cleanup and documentation
/// Note that bank is supplied as BankSetIndex and not BankSet, which means it will be used to perform a raw
/// access into AuGlobals::bankSets. This does not affect values above 3, but 1 and 2 differ.
Instrument* au_get_instrument(AuGlobals* globals, BankSetIndex bank, s32 patch, EnvelopeData* envData) {
    // note that patch here can be up to 255, selecting from a maximum of 16 instruments and 16 banks per group
    Instrument* instrument = (*globals->bankSets[(bank & 0x70) >> 4])[patch];
    EnvelopePreset* envelope = instrument->envelopes;
    u32 envelopeIdx = bank & 3;

    if (envelopeIdx < envelope->count) {
        envData->cmdListPress = AU_FILE_RELATIVE(envelope, envelope->offsets[envelopeIdx].offsetPress);
        envData->cmdListRelease = AU_FILE_RELATIVE(envelope, envelope->offsets[envelopeIdx].offsetRelease);
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
    AuGlobals* globals = gSoundGlobals;
    InitSongEntry* songInfo;
    s32 i;
    u16 bkFileIndex;
    s32 bgmFileIndex;
    u32 data;
    u32 offset;
    BGMPlayer* playerCopy;
    BGMHeader* fileCopy;
    s32 cond;

    // needed to match
    cond = songID < globals->songListLength;
    playerCopy = player;
    fileCopy = bgmFile;

    if (cond) {
        songInfo = &globals->songList[songID];
        status = au_fetch_SBN_file(songInfo->bgmFileIndex, AU_FMT_BGM, &fileEntry);
        if (status != AU_RESULT_OK) {
            return status;
        }

        if (au_bgm_player_is_active(playerCopy)) {
            return AU_ERROR_201;
        }

        au_read_rom(fileEntry.offset, fileCopy, fileEntry.data & 0xFFFFFF);

        for (i = 0; i < ARRAY_COUNT(songInfo->bkFileIndex); i++) {
            bkFileIndex = songInfo->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &globals->sbnFileList[bkFileIndex];

                offset = (bkFileEntry->offset & 0xFFFFFF) + globals->baseRomOffset;
                fileEntry2.offset = offset;

                data = bkFileEntry->data;
                fileEntry2.data = data;

                if ((data >> 0x18) == AU_FMT_BK) {
                    au_load_aux_bank(offset, i);
                }
            }
        }
        bgmFileIndex = songInfo->bgmFileIndex;
        playerCopy->songID = songID;
        playerCopy->bgmFile = bgmFile;
        playerCopy->bgmFileIndex = bgmFileIndex;
        return fileCopy->name;
    } else {
        return AU_ERROR_151;
    }
}

AuResult au_unk_80053E58(s32 songID, BGMHeader* bgmFile) {
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
                    au_load_aux_bank(fileEntry.offset, i);
                } else {
                    status = AU_ERROR_SBN_FORMAT_MISMATCH;
                }
            }
        }
    }

    return status;
}

BGMPlayer* au_unk_80053F64(s32 variation) {
    if (variation == 0) {
        return gSoundGlobals->unk_globals_6C[0].bgmPlayer;
    }
    return NULL;
}

#define SBN_EXTRA_LOOKUP(i,fmt,e) (au_fetch_SBN_file(globals->extraFileList[AmbientSoundIDtoMSEQFileIndex[i]], fmt, &e))

AuResult au_ambient_load(u32 ambSoundID) {
    AmbienceManager* manager;
    SBNFileEntry fileEntry;
    AuGlobals* globals;
    MSEQHeader* mseqFile;
    u32 i;

    globals = gSoundGlobals;
    manager = gAuAmbienceManager;
    if (ambSoundID < AMBIENT_RADIO) {
        if (manager->players[0].mseqName == 0) {
            if (SBN_EXTRA_LOOKUP(ambSoundID, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                au_read_rom(fileEntry.offset, globals->dataMSEQ[0], fileEntry.data & 0xFFFFFF);
                manager->mseqFiles[0] = globals->dataMSEQ[0];
                for (i = 1; i < ARRAY_COUNT(manager->mseqFiles); i++) {
                    manager->mseqFiles[i] = NULL;
                }
                manager->numActivePlayers = 1;
            }
        }
    } else if (ambSoundID == AMBIENT_RADIO
            && manager->players[0].mseqName == 0
            && manager->players[1].mseqName == 0
            && manager->players[2].mseqName == 0
    ) {
        manager->numActivePlayers = 0;
        for (i = 0; i < ARRAY_COUNT(manager->mseqFiles); i++) {
            manager->mseqFiles[i] = NULL;
        }

        mseqFile = globals->dataMSEQ[1];
        if (SBN_EXTRA_LOOKUP(ambSoundID, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
            au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
            manager->mseqFiles[0] = mseqFile;

            mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
            if (SBN_EXTRA_LOOKUP(ambSoundID + 1, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                manager->mseqFiles[1] = mseqFile;

                mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
                if (SBN_EXTRA_LOOKUP(ambSoundID + 2, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                    au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                    manager->mseqFiles[2] = mseqFile;

                    mseqFile = AU_FILE_RELATIVE(mseqFile, (fileEntry.data + 0x40) & 0xFFFFFF);
                    if (SBN_EXTRA_LOOKUP(ambSoundID + 3, AU_FMT_MSEQ, fileEntry) == AU_RESULT_OK) {
                        au_read_rom(fileEntry.offset, mseqFile, fileEntry.data & 0xFFFFFF);
                        manager->mseqFiles[3] = mseqFile;

                        manager->numActivePlayers = 4;
                        if (SBN_EXTRA_LOOKUP(ambSoundID + 4, AU_FMT_BK, fileEntry) == AU_RESULT_OK) {
                            // @bug perhaps meant to be 3?
                            // the index here corresponds to an entry in gSoundGlobals->banks
                            // 0-2 are used for the extra banks which may be loaded for BGM files
                            // there exists an unused 4th entry this could plausibly be intended for
                            au_load_aux_bank(fileEntry.offset, 2);
                        }
                    }
                }
            }
        }
    }

    return AU_RESULT_OK;
}

BGMPlayer* au_unk_80054248(u8 arg0) {
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

void au_load_INIT(AuGlobals* globals, s32 romAddr, ALHeap* heap) {
    SBNHeader sbnHeader;
    INITHeader initHeader;
    SBNFileEntry* entry;
    s32 fileListSize, initBase, size;
    s32 songListOffset, mseqListOffset;
    s32* data;
    s32 numEntries;
    s32* romPtr = &globals->baseRomOffset;

    au_read_rom(romAddr, &sbnHeader, sizeof(sbnHeader));
    numEntries = sbnHeader.numEntries;
    fileListSize = numEntries * sizeof(SBNFileEntry);
    globals->baseRomOffset = romAddr;
    globals->fileListLength = sbnHeader.numEntries;
    globals->sbnFileList = alHeapAlloc(heap, 1, fileListSize);
    au_read_rom(globals->baseRomOffset + sbnHeader.fileListOffset, globals->sbnFileList, fileListSize);

    entry = globals->sbnFileList;
    while (sbnHeader.numEntries--) {
        if ((entry->offset & 0xFFFFFF) == 0) {
            break;
        }

        // 16-byte align size
        size = entry->data;
        entry->data = (entry->data + 0xF) & ~0xF;
        entry++;
    }

    if (sbnHeader.INIToffset != 0) {
        initBase = *romPtr + sbnHeader.INIToffset;
        au_read_rom(initBase, &initHeader, sizeof(initHeader));

        songListOffset = initBase + initHeader.songListOffset;
        size = ALIGN16_(initHeader.songListSize);
        globals->songList = alHeapAlloc(heap, 1, size);
        au_read_rom(songListOffset, globals->songList, size);

        mseqListOffset = initBase + initHeader.mseqListOffset;
        size = ALIGN16_(initHeader.mseqListSize);
        globals->extraFileList = alHeapAlloc(heap, 1, size);
        au_read_rom(mseqListOffset, globals->extraFileList, size);

        globals->bkFileListOffset = initBase + initHeader.bankListOffset;
        globals->bkListLength = ALIGN16_(initHeader.bankListSize);

        globals->songListLength = initHeader.songListSize / sizeof(InitSongEntry) - 1;
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

void au_load_PRG(AuGlobals* globals, s32 romAddr) {
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
    au_read_rom(dataRomAddr, globals->dataPRG, size);
    numItems = size / sizeof(BGMInstrumentInfo);
    numItemsLeft = 0x40 - numItems;
    if (numItemsLeft > 0) {
        end = &globals->dataPRG[numItems];
        au_copy_words(&globals->defaultPRGEntry, end, sizeof(BGMInstrumentInfo));
        au_copy_words(end, end + sizeof(BGMInstrumentInfo), numItemsLeft * sizeof(BGMInstrumentInfo) - sizeof(BGMInstrumentInfo));
    }
}

s32 snd_load_BGM(s32 arg0) {
    AuGlobals* globals = gSoundGlobals;
    InitSongEntry* song = globals->songList;
    s32 ret = AU_RESULT_OK;
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
                    if ((fileEntry.data >> 0x18) == AU_FMT_BK) {
                        au_load_aux_bank(fileEntry.offset, i);
                    } else {
                        ret = AU_ERROR_SBN_FORMAT_MISMATCH;
                    }
                }
            }

            return ret;
        }
        song++;
    }
}

InstrumentBank* au_get_BK_instruments(BankSet bankSet, u32 bankIndex) {
    InstrumentBank* ret = NULL;
    AuGlobals* globals = gSoundGlobals;

    // TODO fake match - this multiplying the bankIndex by 16 and then dividing it right after is dumb
    bankIndex *= 16;

    switch (bankSet) {
        case BANK_SET_AUX:
            ret = &globals->auxBankSet[bankIndex / 16];
            break;
        case BANK_SET_2:
            ret = &globals->bankSet2[bankIndex / 16];
            break;
        case BANK_SET_4:
            ret = &globals->bankSet4[bankIndex / 16];
            break;
        case BANK_SET_5:
            ret = &globals->bankSet5[bankIndex / 16];
            break;
        case BANK_SET_6:
            ret = &globals->bankSet6[bankIndex / 16];
            break;
        case BANK_SET_MUSIC:
            ret = &globals->musicBankSet[bankIndex / 16];
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

/// Loads an instrument bank file from ROM, allocates memory if needed, and sets up instrument pointers.
/// Instruments in the bank will be configured to use DMA streaming for sample/codebook data.
/// This is the standard loader for streamed instrument banks.
BKFileBuffer* au_load_BK_to_bank(s32 bkFileOffset, BKFileBuffer* bkFile, s32 bankIndex, BankSet bankSet) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKHeader localHeader;
    BKHeader* header = &localHeader;
    InstrumentBank* group;
    Instrument** inst;
    s32 instrumentCount;
    u16 keepReading;
    u16 readState;
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
                size = ALIGN16_(header->instrumetsLength)
                    + ALIGN16_(header->loopStatesLength)
                    + ALIGN16_(header->predictorsLength)
                    + ALIGN16_(header->envelopesLength)
                    + sizeof(*header);
                if (bkFile == NULL) {
                    bkFile = alHeapAlloc(heap, 1, size);
                }
                au_read_rom(bkFileOffset, bkFile, size);

                group = au_get_BK_instruments(bankSet, bankIndex);
                inst = (*group);
                instrumentCount = 0;

                for (i = 0; i < ARRAY_COUNT(header->instruments); inst++, i++) {
                    u16 instOffset = header->instruments[i];
                    if (instOffset != 0) {
                        instrumentCount++;
                        *inst = AU_FILE_RELATIVE(bkFile, instOffset);
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
                au_swizzle_BK_instruments(bkFileOffset, bkFile, *group, 16, TRUE);
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

    return bkFile;
}

/// Fixes up (swizzles) instrument pointers in a loaded bank, converting file-relative offsets to valid RAM pointers.
/// Sets whether each instrument uses DMA streaming or not, and updates pitch ratios to match output rate.
/// Replaces NULL instruments with a default instrument to ensure all loaded patches point to valid data.
void au_swizzle_BK_instruments(s32 bkFileOffset, BKFileBuffer* file, InstrumentBank instruments, u32 instrumentCount, u8 useDma) {
    Instrument* defaultInstrument = gSoundGlobals->defaultInstrument;
    BKHeader* header = &file->header;
    f32 outputRate = gSoundGlobals->outputRate;
    s32 i;

    if (!header->swizzled) {
        for (i = 0; i < instrumentCount; i++) {
            Instrument* instrument = instruments[i];

            if (instrument != NULL) {
                if (instrument->wavData != 0) {
                    instrument->wavData += bkFileOffset;
                }
                if (instrument->loopState != NULL) {
                    instrument->loopState = AU_FILE_RELATIVE(file, instrument->loopState);
                }
                if (instrument->predictor != NULL) {
                    instrument->predictor = AU_FILE_RELATIVE(file, instrument->predictor);
                }
                if (instrument->envelopes != NULL) {
                    instrument->envelopes = AU_FILE_RELATIVE(file, instrument->envelopes);
                }
                instrument->useDma = useDma;
                instrument->pitchRatio = instrument->sampleRate / outputRate;
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        header->swizzled = TRUE;
    }
}

/// UNUSED
/// Loads an instrument bank file from ROM to a given buffer (allocates if needed), and sets up instrument pointers.
/// Instruments are configured to always bypass DMA: sample and codebook data is assumed to be already present in RAM.
/// Use this only for banks whose sample data is guaranteed to be preloaded, not for standard streaming.
BKFileBuffer* au_load_static_BK_to_bank(s32* inAddr, void* outAddr, s32 bankIndex, BankSet bankSet) {
    ALHeap* heap = gSynDriverPtr->heap;
    BKFileBuffer* bkFile = outAddr;
    BKHeader localHeader;
    BKHeader* header = &localHeader;
    InstrumentBank* group;
    Instrument* instruments;
    Instrument** inst;
    s32 instrumentCount;
    u32 keepReading;
    u32 readState;
    u32 i;
    s32 useDma = FALSE;

    readState = BK_READ_FETCH_HEADER;
    keepReading = TRUE;

    while (keepReading) {
        switch (readState) {
            case BK_READ_DONE:
                keepReading = FALSE;
                break;
            case BK_READ_FETCH_HEADER:
                au_read_rom(*inAddr, &localHeader, sizeof(localHeader));
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
                if (bkFile == NULL) {
                    bkFile = alHeapAlloc(heap, 1, header->size);
                }
                au_read_rom(*inAddr, bkFile, header->size);

                instrumentCount = 0;
                group = au_get_BK_instruments(bankSet, bankIndex);
                inst = (*group);
                for (i = 0; i < ARRAY_COUNT(header->instruments); inst++, i++) {
                    u16 instOffset = header->instruments[i];
                    if (instOffset != 0) {
                        instrumentCount++;
                        *inst = AU_FILE_RELATIVE(bkFile, instOffset);
                    } else {
                        *inst =  NULL;
                    }
                }

                if (instrumentCount != 0) {
                    readState = BK_READ_SWIZZLE;
                } else {
                    keepReading = FALSE;
                }
                break;
            case BK_READ_SWIZZLE:
                au_swizzle_BK_instruments((s32)bkFile, bkFile, *group, 16, useDma);
                readState = BK_READ_DONE;
                break;
            default:
                keepReading = FALSE;
                break;
        }
    }
    return bkFile;
}

s32 au_load_aux_bank(s32 bkFileOffset, s32 bankIndex) {
    au_load_BK_to_bank(bkFileOffset, gSoundGlobals->auxBanks[bankIndex], bankIndex, BANK_SET_AUX);
    return AU_RESULT_OK;
}

/// unused. resets all instruments in (bankIndex, bankSet) to default
void au_clear_instrument_group(s32 bankIndex, BankSet bankSet) {
    Instrument* instrument = gSoundGlobals->defaultInstrument;
    InstrumentBank* group =  au_get_BK_instruments(bankSet, bankIndex);
    Instrument** ptr = *group;
    u32 i;

    if (group != NULL) {
        for (i = 0; i < ARRAY_COUNT(*group); i++) {
            *ptr++ = instrument;
        }
    }
}

void au_unk_80054CE0(s32 soundTypeFlags, u32 volPreset) {
    if (volPreset < ARRAY_COUNT(PerceptualVolumeLevels)) {
        s32 vol = PerceptualVolumeLevels[volPreset];
        if (soundTypeFlags & AUDIO_TYPE_BGM) {
            gBGMPlayerA->busVolume = vol;
            au_unk_80053AC8(&gBGMPlayerA->fadeInfo);
            gBGMPlayerB->busVolume = vol;
            au_unk_80053AC8(&gBGMPlayerB->fadeInfo);
        }
        if (soundTypeFlags & AUDIO_TYPE_SFX) {
            gSoundManager->busVolume = vol;
            au_unk_80053AC8(&gSoundManager->fadeInfo);
        }
    }
}

s32 au_unk_80054D74(s32 soundTypeFlags, s32 reverbType) {
    if (soundTypeFlags & AUDIO_TYPE_SFX) {
        return au_sfx_set_reverb_type(gSoundManager, reverbType);
    }
    return 0;
}

void au_unk_80054DA8(u32 bMonoSound) {
    if (bMonoSound % 2 == 1) {
        // mono sound
        if (gSoundGlobals->unk_130C == 0) {
            gSoundGlobals->unk_130C = 2;
        }
    } else {
        // stereo sound
        if (gSoundGlobals->unk_130C != 0) {
            gSoundGlobals->channelDelayPending = TRUE;
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
