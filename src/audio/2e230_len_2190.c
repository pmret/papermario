#include "audio.h"

// data
extern u16 D_80078530[];
extern s32 D_8007854C[2];
extern u8 D_80078580[];
extern f32 AlTuneScaling[];

void func_80052E30(u8 index) {
    AlUnkVoice* temp = &gSoundGlobals->voices[index];

    temp->unk_1C = 0;
    temp->unk_45 = 0;
}

void snd_load_audio_data(s32 outputRate) {
    SndGlobals* globals;
    s32* dummyTrackData;
    ALHeap* alHeap;
    u32 i;
    SBNFileEntry fileEntry;
    u8 temp6[4];
    AlUnkVoice* temp5;

    alHeap = D_80078E54->heap;
    gSoundGlobals = alHeapAlloc(alHeap, 1, sizeof(*gSoundGlobals));

    gBGMPlayerA = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerA));
    gBGMPlayerB = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerB));
    gBGMPlayerC = alHeapAlloc(alHeap, 1, sizeof(*gBGMPlayerC));
    gSoundManager = alHeapAlloc(alHeap, 1, sizeof(*gSoundManager));
    D_8009A628 = alHeapAlloc(alHeap, 1, sizeof(*D_8009A628));
    gBGMPlayerA->soundManager = gSoundManager;
    D_8009A628->unk_00 = gSoundGlobals;


    globals = gSoundGlobals;
    dummyTrackData = alHeapAlloc(alHeap, 1, 0x8000);
    globals->currentTrackData[0] = &dummyTrackData[0];
    globals->currentTrackData[1] = &dummyTrackData[0x1400];
    globals->currentTrackData[2] = &dummyTrackData[0x1C00];
    globals->currentTrackData[3] = &dummyTrackData[0x1400];

    for (i = 0; i < 1; i++) {
        globals->unk_globals_6C[i].bgmPlayer = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    }

    globals->dataSEF = alHeapAlloc(alHeap, 1, 0x5200);
    globals->defaultInstrument = alHeapAlloc(alHeap, 1, sizeof(Instrument));
    globals->dataPER = alHeapAlloc(alHeap, 1, 6 * sizeof(PEREntry));
    globals->dataPRG = alHeapAlloc(alHeap, 1, 0x200);
    globals->unk_arr_94 = alHeapAlloc(alHeap, 1, 0x40);
    globals->outputRate = outputRate;
    snd_reset_instrument(globals->defaultInstrument);
    func_80053370(&globals->unk_08);
    func_800533A8(&globals->defaultPRGEntry);
    func_8005610C();

    globals->unk_A4[0] = NULL;
    globals->unk_A4[1] = NULL;

    for (i = 0; i < 1; i++) {
        globals->unk_globals_6C[i].unk_4 = 0;
        globals->unk_globals_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        globals->unk_globals_40[i].unk_00 = 0;
        globals->unk_globals_40[i].unk_01 = FALSE;
    }

    for (i = 0; i < 24; i++) {
        func_80056EC0(i, 0);
        func_80057224(i, globals->defaultInstrument);
        temp5 = &globals->voices[i];
        temp5->unk_00 = 0;
        temp5->unk_04 = 0;
        temp5->unk_0C = -1;
        temp5->unk_0E = 0xFF;
        temp5->reverb = 0xFF;
        temp5->unk_10 = 0;
        temp5->unk_42 = 0;
        temp5->unk_43 = 0;
        temp5->unk_44 = 0;
        temp5->unk_45 = 0;
    }

    snd_load_INIT(globals, 0xF00000, alHeap);

    for (i = 0; i < 3; i++) {
        globals->banks[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    func_8004E158(gBGMPlayerA, 1, 0, globals);
    temp6[0] = 0;
    temp6[1] = 3;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(gBGMPlayerA, temp6);
    func_8004E158(gBGMPlayerB, 2, 2, globals);
    temp6[0] = 2;
    temp6[1] = 0xff;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(gBGMPlayerB, temp6);
    func_8004B440(gSoundManager, 4, 1, globals, 0x10);
    func_80050B90(D_8009A628, 6, 1, globals);
    func_80052614(globals);
    snd_load_BK_headers(globals, alHeap);
    if (snd_fetch_SBN_file(globals->mseqFileList[0], 0x20, &fileEntry) == 0) {
        snd_read_rom(fileEntry.offset, globals->dataSEF, fileEntry.data & 0xFFFFFF);
    }
    snd_load_sfx_groups_from_SEF(gSoundManager);
    if (snd_fetch_SBN_file(globals->mseqFileList[1], 0x40, &fileEntry) == 0) {
        snd_load_PER(globals, fileEntry.offset);
    }
    if (snd_fetch_SBN_file(globals->mseqFileList[2], 0x40, &fileEntry) == 0) {
        snd_load_PRG(globals, fileEntry.offset);
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

void snd_reset_instrument(Instrument* instrument) {
    instrument->wavOffset = &D_800781D0;
    instrument->wavLength = 190;
    instrument->predictorOffset = &D_80078190;
    instrument->unk_1C = 64;
    instrument->detune = 4800;
    instrument->loopPredictorOffset = 0;
    instrument->loopStart = 0;
    instrument->loopEnd = 0;
    instrument->loopCount = 0;
    instrument->skipLoopPredictor = 0;
    instrument->unk_25 = 0;
    instrument->unkOffset = &D_80078544;
    instrument->unk_26 = 0;
    instrument->unk_27 = 0;
    instrument->unk_28 = 0;
    instrument->unk_29 = 0;
    instrument->unk_2A = 0;
    instrument->unk_2B = 0;
    instrument->sampleRate = 0.5f;
}

void func_80053370(AlUnkMu* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = 4800;
    arg0->unk_04 = 0x7F;
    arg0->unk_05 = 64;
    arg0->unk_06 = 0;
    arg0->unk_07 = 0;
    arg0->unk_08 = 0;
    arg0->unk_09 = 0;
    arg0->unk_0A = 0;
}

void func_800533A8(BGMInstrumentInfo* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = 0x7F;
    arg0->pan = 64;
    arg0->reverb = 0;
    arg0->coarseTune = 0;
    arg0->fineTune = 0;
}


void snd_update_sequence_players(void) {
    SndGlobals* temp_s2 = gSoundGlobals;
    SoundManager* sfxManager = gSoundManager;
    AmbientSoundManager* ambManager = D_8009A628;
    BGMPlayer* bgmPlayer1;
    BGMPlayer* bgmPlayer2;

    func_80053654(temp_s2);

    ambManager->nextUpdateCounter -= ambManager->nextUpdateStep;
    if (ambManager->nextUpdateCounter <= 0) {
        ambManager->nextUpdateCounter += ambManager->nextUpdateInterval;
        snd_ambient_manager_update(ambManager);
    }

    if (sfxManager->unk_40.fadeTime != 0) {
        func_80053A28(&sfxManager->unk_40);
        func_80053A98(sfxManager->unk_BE, sfxManager->unk_40.currentVolume.u16, sfxManager->unk_5C);
    }

    sfxManager->nextUpdateCounter -= sfxManager->nextUpdateStep;
    if (sfxManager->nextUpdateCounter <= 0) {
        sfxManager->nextUpdateCounter += sfxManager->nextUpdateInterval;
        sfxManager->unk_BA = snd_sound_manager_update(sfxManager);
    }

    if (!D_80078DB0) {
        bgmPlayer1 = gBGMPlayerB;
        if (bgmPlayer1->fadeInfo.fadeTime != 0) {
            snd_update_bgm_fade(bgmPlayer1);
        }
        if (bgmPlayer1->songName != 0) {
            bgmPlayer1->unk_18++;
        }

        bgmPlayer1->unk_10 -= bgmPlayer1->unkFrequency;
        if (bgmPlayer1->unk_10 <= 0) {
            bgmPlayer1->unk_10 += bgmPlayer1->unk_0C;
            bgmPlayer1->unk_5C = func_8004E4B8(bgmPlayer1);
        }
        if (!D_80078DB0) {
            if (temp_s2->unk_80 != 0) {
                func_8004DFD4(temp_s2);
            }
            bgmPlayer2 = gBGMPlayerA;
            if (bgmPlayer2->fadeInfo.volScaleTime != 0) {
                func_80053BA8(&bgmPlayer2->fadeInfo);
                if (bgmPlayer2->fadeInfo.fadeTime == 0) {
                    func_8004E444(bgmPlayer2);
                } else {
                    snd_update_bgm_fade(bgmPlayer2);
                }
            } else if (bgmPlayer2->fadeInfo.fadeTime != 0) {
                snd_update_bgm_fade(bgmPlayer2);
            }
            if (bgmPlayer2->songName != 0) {
                bgmPlayer2->unk_18++;
            }

            bgmPlayer2->unk_10 -= bgmPlayer2->unkFrequency;
            if (bgmPlayer2->unk_10 <= 0) {
                bgmPlayer2->unk_10 += bgmPlayer2->unk_0C;
                bgmPlayer2->unk_5C = func_8004E4B8(bgmPlayer2);
            }
        }
    }
    func_80052660(temp_s2);
}

void snd_add_sfx_output(void) {
    SndGlobals* globals = gSoundGlobals;
    BGMPlayer* player = gBGMPlayerA;
    SoundManager* manager = gSoundManager;

    if (globals->unk_9C != 0) {
        func_8005610C();
    }

    D_8009A5E8 = globals->unk_A4[0];
    if (D_8009A5E8 != NULL) {
        D_8009A5E8();
    }

    func_8004D510(player);

    player = gBGMPlayerB;
    func_8004D510(player);

    func_8004B748(manager);
}

void func_80053654(SndGlobals* arg0) {
    u32 i;

    if (arg0->unk_130C == 2) {
        arg0->unk_130C = 1;
        func_80057EB0();
    }

    if ((arg0->unk_50 != 0) && (arg0->unk_130C == 0)) {
        switch (arg0->unk_53) {
            case 1:
                func_80057DC8(arg0->unk_52);
                func_80057E08(arg0->unk_51);
                arg0->unk_50 = 0;
                break;
            case 2:
                func_80057DC8(arg0->unk_52);
                func_80057E5C(arg0->unk_51);
                arg0->unk_50 = 0;
                break;
            default:
                func_80057EB0();
                arg0->unk_50 = 0;
                break;
        }
    }

    if (arg0->unk_globals_40[0].unk_01) {
        func_80056DCC(0, arg0->unk_globals_40[0].unk_00);
        arg0->unk_globals_40[0].unk_01 = FALSE;
    }
    if (arg0->unk_globals_40[1].unk_01) {
        func_80056DCC(1, arg0->unk_globals_40[1].unk_00);
        arg0->unk_globals_40[1].unk_01 = FALSE;

    } if (arg0->unk_globals_40[2].unk_01) {
        func_80056DCC(2, arg0->unk_globals_40[2].unk_00);
        arg0->unk_globals_40[2].unk_01 = FALSE;
    }
    if (arg0->unk_globals_40[3].unk_01) {
        func_80056DCC(3, arg0->unk_globals_40[3].unk_00);
        arg0->unk_globals_40[3].unk_01 = FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(arg0->voices); i++) {
        AlUnkVoice* voice = &arg0->voices[i];
        u8 unk_43 = voice->unk_43;

        if (voice->unk_42 != 0) {
            func_80056EE8(i);
            voice->unk_42 = 0;
            voice->unk_1C = 0;
            voice->unk_45 = 0;
        }

        if (unk_43 & 2) {
            func_80052BF8(voice, &voice->unk_14);
            func_80056FA4(i, voice->unk_10, voice->unk_00, voice->unk_04, voice->unk_0C, voice->unk_0E, voice->reverb, voice->unk_08);
            voice->unk_45 = voice->unk_44;
        } else {
            if (unk_43 & 8) {
                func_80057344(i, voice->unk_04);
            }

            if (unk_43 & 4) {
                func_8005736C(i, voice->unk_0C, voice->unk_08, voice->unk_0E, voice->reverb);
            } else if (unk_43 & 0x10) {
                func_80057548(i, voice->unk_0E, voice->reverb);
            }
        }
        voice->unk_43 = 0;
    }
}

void func_80053888(AlUnkVoice* arg0, u8 arg1) {
    if (arg0->unk_45 != 0) {
        arg0->unk_1C = 0;
        arg0->unk_42 = 1;
        arg0->unk_43 = 0;
        func_800576EC(arg1, 0, AUDIO_SAMPLES);
    }
}

void func_800538C4(AlUnkVoice* arg0, u8 arg1) {
    arg0->unk_1C = 0;
    arg0->unk_42 = 1;
    arg0->unk_43 = 0;
    func_800576EC(arg1, 0, AUDIO_SAMPLES);
}

// array offsets into AlTuneScaling
#define TUNE_SCALING_ARR_AMPLIFY_FINE 0
#define TUNE_SCALING_ARR_AMPLIFY_COARSE 128
#define TUNE_SCALING_ARR_ATTENUATE_FINE 160
#define TUNE_SCALING_ARR_ATTENUATE_COARSE 288

f32 snd_tune_param_to_timescale(s32 arg0) {
    if (arg0 >= 0) {
        return AlTuneScaling[(arg0 & 0x7F) + TUNE_SCALING_ARR_AMPLIFY_FINE]
            * AlTuneScaling[((arg0 & 0xF80) >> 7) + TUNE_SCALING_ARR_AMPLIFY_COARSE];
    } else {
        arg0 = -arg0;
        return AlTuneScaling[(arg0 & 0x7F) + TUNE_SCALING_ARR_ATTENUATE_FINE]
            * AlTuneScaling[((arg0 & 0x3F80) >> 7) + TUNE_SCALING_ARR_ATTENUATE_COARSE];
    }
}

void snd_initialize_bgm_fade(Fade* fade, s32 time, s32 startValue, s32 endValue) {
    fade->currentVolume.s32 = startValue * 0x10000;
    fade->targetVolume = endValue;

    if (time != 0) {
        fade->fadeTime = (time * 1000) / 5750;
        fade->fadeStep = (endValue * 0x10000 - fade->currentVolume.s32) / fade->fadeTime;
    } else {
        fade->fadeTime = 1;
        fade->fadeStep = 0;
    }

    fade->onCompleteCallback = NULL;
}

void snd_clear_bgm_fade(Fade* fade) {
    fade->fadeTime = 0;
    fade->fadeStep = 0;
    fade->onCompleteCallback = NULL;
}

void func_80053A28(Fade* fade) {
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

void snd_set_fade_vol_scale(Fade* fade, s16 value) {
    fade->volScale.s32 = value << 16;
    fade->targetVolScale = value;
    fade->volScaleTime = 0;
    fade->volScaleStep = 0;
}

void func_80053B04(Fade* fade, u32 arg1, s16 target) {
    s16 time;
    s32 delta;

    if (arg1 >= 250 && arg1 <= 100000) {
        time = (s32)(arg1 * 1000) / 5750;
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
Instrument* func_80053BE8(SndGlobals* arg0, u32 arg1, u32 arg2, s32** arg3) {
    Instrument* instrument = (*arg0->instrumentGroups[(arg1 & 0x70) >> 4])[arg2];
    InstrumentEffect* temp_a0 = instrument->unkOffset;
    u32 temp_a1 = arg1 % 4;

    if (temp_a1 < temp_a0->count) {
        arg3[0] = (s32*)(temp_a0->unk_04[temp_a1].unkOffset1 + (s32)temp_a0);
        arg3[1] = (s32*)(temp_a0->unk_04[temp_a1].unkOffset2 + (s32)temp_a0);
    } else {
        arg3[0] = &D_8007854C[0];
        arg3[1] = &D_8007854C[1];
    }
    return instrument;
}

void snd_get_sequence_player_and_track(u32 playerIndex, s32** outCurrentTrackData, BGMPlayer** outPlayer) {
    SndGlobals* globals = gSoundGlobals;

    switch (playerIndex) {
        case 0:
            *outCurrentTrackData = globals->currentTrackData[0];
            *outPlayer = gBGMPlayerA;
            break;
        case 1:
            *outCurrentTrackData = globals->currentTrackData[1];
            *outPlayer = gBGMPlayerB;
            break;
        case 2:
            *outCurrentTrackData = globals->currentTrackData[0];
            *outPlayer = gBGMPlayerA;
            break;
        default:
            *outCurrentTrackData = NULL;
            *outPlayer = NULL;
            break;
    }
}

void snd_get_sequence_player(u32 playerIndex, BGMPlayer** outPlayer) {
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

s32 snd_load_song_files(u32 arg0, BGMHeader* arg1, BGMPlayer* arg2) {
    SBNFileEntry fileEntry;
    SBNFileEntry fileEntry2;
    SBNFileEntry* bkFileEntry;
    SndGlobals* soundData;
    InitSongEntry* songEntry;
    s32 i;
    u16 bkFileIndex;
    s32 bgmFileIndex;
    u32 data;
    u32 offset;
    s32 ret;
    BGMPlayer* arg2_copy ;
    BGMHeader* arg1_copy;
    s32 cond;

    soundData = gSoundGlobals;

    // needed to match
    cond = arg0 < soundData->songListLength;
    arg2_copy = arg2;
    arg1_copy = arg1;

    if (cond) {
        songEntry = &soundData->songList[arg0];
        ret = snd_fetch_SBN_file(songEntry->bgmFileIndex, 0x10, &fileEntry);
        if (ret != 0) {
            return ret;
        }

        if (func_8004DB28(arg2_copy)) {
            return 201;
        }

        snd_read_rom(fileEntry.offset, arg1_copy, fileEntry.data & 0xFFFFFF);

        for (i = 0 ; i < 3; i++) {
            bkFileIndex = songEntry->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &soundData->sbnFileList[bkFileIndex];

                offset = (bkFileEntry->offset & 0xFFFFFF) + soundData->baseRomOffset;
                fileEntry2.offset = offset;

                data = bkFileEntry->data;
                fileEntry2.data = data;

                if ((data >> 0x18) == 0x30) {
                    snd_load_BK(offset, i);
                }
            }
        }
        bgmFileIndex = songEntry->bgmFileIndex;
        arg2_copy->songID = arg0;
        arg2_copy->bgmFile = arg1;
        arg2_copy->bgmFileIndex = bgmFileIndex;
        return arg1_copy->name;
    } else {
        return 151;
    }
}

s32 func_80053E58(s32 arg0, u8* arg1) {
    SBNFileEntry fileEntry;
    SBNFileEntry sp18;
    SBNFileEntry* bkFileEntry;
    SndGlobals* soundData;
    InitSongEntry* temp_s1;
    s32 i;
    s32 ret;
    u32 data;
    u32 offset;
    u16 bkFileIndex;

    soundData = gSoundGlobals;
    temp_s1 = &soundData->songList[arg0];
    ret =  snd_fetch_SBN_file(temp_s1[0].bgmFileIndex, 0x10, &sp18);
    if (ret == 0) {
        snd_read_rom(sp18.offset, arg1, sp18.data & 0xFFFFFF);

        for (i = 0 ; i < 3; i++) {
            bkFileIndex = temp_s1->bkFileIndex[i];
            if (bkFileIndex != 0) {
                bkFileEntry = &soundData->sbnFileList[bkFileIndex];

                offset = (bkFileEntry->offset & 0xFFFFFF) + soundData->baseRomOffset;
                fileEntry.offset = offset;

                data = bkFileEntry->data;
                fileEntry.data = data;

                if ((data >> 0x18) == 0x30) {
                    snd_load_BK(offset, i);
                } else {
                    ret = 102;
                }
            }
        }
    }

    return ret;
}

BGMPlayer* func_80053F64(s32 arg0) {
    if (arg0 == 0) {
        return gSoundGlobals->unk_globals_6C[0].bgmPlayer;
    }
    return NULL;
}

s32 func_80053F80(u32 arg0) {
    u32 i;
    SBNFileEntry fileEntry;
    SndGlobals* soundData;
    AmbientSoundManager* temp_s2;
    s32* trackData;

    soundData = gSoundGlobals;
    temp_s2 = D_8009A628;
    if (arg0 < 16) {
        if (temp_s2->unk_24[0].unk_20 == 0 && snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0]], 0x40, &fileEntry) == 0) {
            snd_read_rom(fileEntry.offset, soundData->currentTrackData[2], fileEntry.data & 0xFFFFFF);
            temp_s2->unk_10[0] = soundData->currentTrackData[2];
            for (i = 1; i < 4; i++) {
                temp_s2->unk_10[i] = NULL;
            }
            temp_s2->unk_20 = 1;
        }
    } else if (arg0 == 16 && temp_s2->unk_24[0].unk_20 == 0 && temp_s2->unk_24[1].unk_20 == 0 && temp_s2->unk_24[2].unk_20 == 0) {
        temp_s2->unk_20 = 0;
        for (i = 0; i < 4; i++) {
            temp_s2->unk_10[i] = NULL;
        }

        trackData = soundData->currentTrackData[3];
        if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0]], 0x40, &fileEntry) == 0) {
            snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
            temp_s2->unk_10[0] = trackData;

            trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
            if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 1]], 0x40, &fileEntry) == 0) {
                snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                temp_s2->unk_10[1] = trackData;

                trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
                if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 2]], 0x40, &fileEntry) == 0) {

                    snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                    temp_s2->unk_10[2] = trackData;

                    trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
                    if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 3]], 0x40, &fileEntry) == 0) {
                        snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                        temp_s2->unk_10[3] = trackData;

                        temp_s2->unk_20 = 4;
                        if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 4]], 0x30, &fileEntry) == 0) {
                            snd_load_BK(fileEntry.offset, 2);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

BGMPlayer* func_80054248(u8 arg0) {
    switch (arg0) {
        case 1:
            return gBGMPlayerA;
        case 2:
            return gBGMPlayerB;
        case 4:
            return gSoundManager; // TODO: why return pointer to SoundManager?
        default:
            return NULL;
    }
}

void snd_load_INIT(SndGlobals* arg0, s32 romAddr, ALHeap* heap) {
    SBNHeader sbnHeader;
    INITHeader initHeader;
    SBNFileEntry* entry;
    s32 tableSize, initBase, size;
    s32 tblAddr, shortsAddr;
    s32* data;
    s32 numEntries;
    s32 tblOffset, shortsOffset;
    s32* romPtr = &arg0->baseRomOffset;

    snd_read_rom(romAddr, &sbnHeader, sizeof(SBNHeader));
    numEntries = sbnHeader.numEntries;
    arg0->baseRomOffset = romAddr;
    tableSize = numEntries * sizeof(SBNFileEntry);
    arg0->fileListLength = sbnHeader.numEntries;
    arg0->sbnFileList = alHeapAlloc(heap, 1, tableSize);
    snd_read_rom(arg0->baseRomOffset + sbnHeader.tableOffset, arg0->sbnFileList, tableSize);

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
        snd_read_rom(initBase, &initHeader, sizeof(INITHeader));

        tblOffset = initHeader.tblOffset;
        size = (initHeader.tblSize + 0xF) & 0xFFF0;
        tblAddr = initBase + tblOffset;
        arg0->songList = alHeapAlloc(heap, 1, size);
        snd_read_rom(tblAddr, arg0->songList, size);

        shortsOffset = initHeader.shortsOffset;
        size = (initHeader.shortsSize + 0xF) & 0xFFF0;
        shortsAddr = initBase + shortsOffset;
        arg0->mseqFileList = alHeapAlloc(heap, 1, size);
        snd_read_rom(shortsAddr, arg0->mseqFileList, size);

        arg0->bkFileListOffset = initBase + initHeader.entriesOffset;
        arg0->bkListLength = (initHeader.entriesSize + 0xF) & 0xFFF0;
        arg0->songListLength = initHeader.tblSize / sizeof(InitSongEntry) - 1;
    }
}

s32 snd_fetch_SBN_file(u32 fileIdx, s32 format, SBNFileEntry* arg2) {
    SBNFileEntry fileEntry;
    SndGlobals* temp = gSoundGlobals;
    u32 data;
    s32 ret = 0;

    if (fileIdx < temp->fileListLength) {
        SBNFileEntry* entry = &temp->sbnFileList[fileIdx];
        s32 offset = (entry->offset & 0xFFFFFF) + temp->baseRomOffset;

        fileEntry.offset = offset;
        data = entry->data;
        fileEntry.data = data;
        if ((data >> 0x18) == format) {
            arg2->offset = offset;
            arg2->data = fileEntry.data;
        } else {
            ret = 102;
        }
    } else {
        ret = 101;
    }
    return ret;
}

void snd_load_PER(SndGlobals* arg0, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    void* end;

    snd_read_rom(romAddr, &header, sizeof(PERHeader));
    size = header.size - sizeof(PERHeader);
    snd_read_rom(romAddr + sizeof(PERHeader), arg0->dataPER, size);
    numItems = size / sizeof(PEREntry);
    numItemsLeft = 6 - numItems;
    if (numItemsLeft > 0) {
        end = &arg0->dataPER[numItems];
        snd_copy_words(&arg0->unk_08, end, sizeof(AlUnkMu));
        snd_copy_words(end, end + sizeof(AlUnkMu), numItemsLeft * sizeof(PEREntry) - sizeof(AlUnkMu));
    }
}

void snd_load_PRG(SndGlobals* arg0, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    s32 dataRomAddr;
    void* end;

    snd_read_rom(romAddr, &header, sizeof(PERHeader));
    dataRomAddr = romAddr + sizeof(PERHeader);
    size = header.size - sizeof(PERHeader);
    if (size > 0x200) {
        size = 0x200;
    }
    snd_read_rom(dataRomAddr, arg0->dataPRG, size);
    numItems = size / sizeof(BGMInstrumentInfo);
    numItemsLeft = 0x40 - numItems;
    if (numItemsLeft > 0) {
        end = &arg0->dataPRG[numItems];
        snd_copy_words(&arg0->defaultPRGEntry, end, sizeof(BGMInstrumentInfo));
        snd_copy_words(end, end + sizeof(BGMInstrumentInfo), numItemsLeft * sizeof(BGMInstrumentInfo) - sizeof(BGMInstrumentInfo));
    }
}


INCLUDE_ASM(s32, "audio/2e230_len_2190", snd_load_BGM);

InstrumentGroup* snd_get_BK_instruments(s32 bankGroup, u32 bankIndex) {
    InstrumentGroup* ret = NULL;
    SndGlobals* temp = gSoundGlobals;

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
    ALHeap* heap = D_80078E54->heap;
    BKHeader bkHeader;
    BKHeader* header = &bkHeader;
    u16 s3;
    u16 s2;
    s32 size;
    u8* s4;
    InstrumentGroup* group;
    u32 i;
    s32 a2;

    snd_read_rom(bkFileOffset, header, sizeof(BKHeader));
    s3 = EN_11;
    s2 = TRUE;
    do {
        switch (s3) {
            case EN_11:
                if (header->unk_00 == 0x424B /* BK */ && header->unk_04 != 0) {
                    s3 = EN_21;
                } else {
                    s2 = FALSE;
                }
                break;
            case EN_21:
                if (header->unk_0C == 0x4352) { // CR
                    s3 = EN_101;
                } else if (header->unk_0C == 0x4452) { // DR
                    s3 = EN_201;
                } else if (header->unk_0C == 0x5352) { // SR
                    s3 = EN_301;
                } else {
                    s2 = FALSE;
                }
                break;
            case EN_101:
                size = ALIGN16_(header->unk_32) + ALIGN16_(header->unk_36) + ALIGN16_(header->unk_3A) + ALIGN16_(header->unk_3E) + 0x40;
                if (bank == NULL) {
                    bank = alHeapAlloc(heap, 1, size);
                }
                snd_read_rom(bkFileOffset, bank, size);
                group = snd_get_BK_instruments(bankGroup, bankIndex);
                a2 = 0;
                for (i = 0; i < ARRAY_COUNT(*group); i++) {
                    if (header->unk_12[i] != 0) {
                        (*group)[i] = (s32)bank + header->unk_12[i];
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
                snd_swizzle_BK_instruments(bkFileOffset, bank, *group, 16, 1);
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

void snd_swizzle_BK_instruments(s32 bkFileOffset, SoundBank* bank, InstrumentGroup instruments, u32 instrumentCount, u8 arg4) {
    SoundBank* sb = bank;
    Instrument* defaultInstrument = gSoundGlobals->defaultInstrument;
    f32 freq = gSoundGlobals->outputRate;
    s32 i;

    if (sb->swizzled == 0) {
        for (i = 0; i < instrumentCount; i++) {
            Instrument* instrument = instruments[i];

            if (instrument != NULL) {
                if (instrument->wavOffset != 0) {
                    instrument->wavOffset += bkFileOffset;
                }
                if (instrument->loopPredictorOffset != NULL) {
                    instrument->loopPredictorOffset += (s32)bank;
                }
                if (instrument->predictorOffset != NULL) {
                    instrument->predictorOffset += (s32)bank;
                }
                if (instrument->unkOffset != NULL) {
                    instrument->unkOffset = (s32)instrument->unkOffset + (s32)bank;
                }
                instrument->unk_25 = arg4;
                instrument->sampleRate = *((s32*)(&instrument->sampleRate)) / freq; // what is happening here?
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        sb->swizzled = 1;
    }
}

INCLUDE_ASM(s32, "audio/2e230_len_2190", func_80054AA0);

s32 snd_load_BK(s32 bkFileOffset, s32 bankIndex) {
    snd_load_BK_to_bank(bkFileOffset, gSoundGlobals->banks[bankIndex], bankIndex, 1);
    return 0;
}

void func_80054C84(s32 bankIndex, s32 bankGroup) {
    u32 i;
    Instrument* instrument = gSoundGlobals->defaultInstrument;
    InstrumentGroup* group =  snd_get_BK_instruments(bankGroup, bankIndex);
    Instrument** ptr = *group;
    if (group != NULL) {
        for (i = 0; i < ARRAY_COUNT(*group); i++) {
            *ptr++ = instrument;
        }
    }
}

void func_80054CE0(s32 arg0, s32 arg1) {
    s32 temp_s0;

    if (arg1 < 9U) {
        temp_s0 = D_80078530[arg1];
        if (arg0 & 1) {
            gBGMPlayerA->unk_48 = temp_s0;
            func_80053AC8(&gBGMPlayerA->fadeInfo);
            gBGMPlayerB->unk_48 = temp_s0;
            func_80053AC8(&gBGMPlayerB->fadeInfo);
        }
        if (arg0 & 0x10) {
            gSoundManager->unk_5C = temp_s0;
            func_80053AC8(&gSoundManager->unk_40);
        }
    }
}

s32 func_80054D74(s32 arg0, s32 arg1) {
    if (arg0 & 0x10) {
        return func_8004B9E4(gSoundManager, arg1);
    }
    return 0;
}

void func_80054DA8(u32 arg0) {
    if (arg0 % 2 == 1) {
        if (gSoundGlobals->unk_130C == 0) {
            gSoundGlobals->unk_130C = 2;
        }
    } else {
        if (gSoundGlobals->unk_130C != 0) {
            gSoundGlobals->unk_50 = 1;
            gSoundGlobals->unk_130C = 0;
        }
    }
}

void snd_read_rom(s32 romAddr, void* buffer, u32 size) {
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

void snd_memset(s8* dst, s32 size, u8 value) {
    s32 count;
    s32 intValue;

    if (size == 0) {
        return;
    }

    if (size < 1024) {
        while (size--) {
            *dst++ = value;
        }
    } else {
        count = (u32)dst & 0x3;
        if (count != 0) {
            count = 4 - count;
            size -= count;
            while (count--) {
                *dst++ = value;
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
                *dst++ = value;
            }
        }
    }
}

void snd_bcopy(s8* src, s8* dest, s32 size) {
    if (size > 0) {
        while (size-- != 0) {
            *dest++ = *src++;
        }
    }
}

void snd_copy_words(void* src, void* dst, s32 size) {
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
