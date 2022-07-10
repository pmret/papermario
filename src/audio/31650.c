#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

void func_80057874(u8 arg0, u8 arg1);
static s16 _getVol(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

void snd_add_sfx_output(void);
void snd_update_sequence_players(void);
Acmd* func_80058050(AuPVoice*, Acmd*);
Acmd* func_80059310(AuFX*, Acmd*, s32, s32);

AuSynDriver* gActiveSynDriverPtr = NULL;
AuSynDriver* gSynDriverPtr = NULL;
u8 D_80078E58 = FALSE;
u16 D_80078E5A = 0x7FFF;
u8 D_80078E5C = FALSE;

extern s16 AuEqPower[128];

#define AU_EQPOW_MID_IDX 64
#define AU_EQPOW_MAX_IDX 127

void au_driver_init(AuSynDriver* driver, ALConfig* config) {
    s32 i;
    ALHeap* heap = config->heap;

    if (gActiveSynDriverPtr != NULL) {
        return;
    }

    driver->num_pvoice = config->num_pvoice;
    driver->unk_num_gamma = config->unk_num_gamma;
    driver->curSamples = 0;
    driver->unk_04 = 0;
    driver->outputRate = config->outputRate;
    driver->dmaNew = config->dmaNew;

    gActiveSynDriverPtr = driver;
    gSynDriverPtr = driver;
    D_80078E58 = FALSE;
    D_80078E5A = 0x7FFF;
    D_80078E5C = TRUE;

    gSynDriverPtr->pvoices = alHeapAlloc(heap, config->num_pvoice, sizeof(*gSynDriverPtr->pvoices));

    // this is inlined alN_PVoiceNew
    for (i = 0; i < config->num_pvoice; i++) {
        AuPVoice* voice = &gSynDriverPtr->pvoices[i];
        voice->loadFilter.dc_state = alHeapAlloc(heap, 1, sizeof(*voice->loadFilter.dc_state));
        voice->loadFilter.dc_lstate = alHeapAlloc(heap, 1, sizeof(*voice->loadFilter.dc_lstate));
        voice->loadFilter.dc_dmaFunc = ((ALDMAproc (*)(NUDMAState**))(gSynDriverPtr->dmaNew))(&voice->loadFilter.dc_dmaState);
        voice->loadFilter.dc_lastsam = 0;
        voice->loadFilter.dc_first = 1;
        voice->loadFilter.dc_memin = 0;
        voice->resampler.rs_state = alHeapAlloc(heap, 1, sizeof(*voice->resampler.rs_state));
        voice->resampler.delta = 0;
        voice->resampler.first = 1;
        voice->resampler.rs_ratio = 1.0f;
        voice->envMixer.em_state = alHeapAlloc(heap, 1, sizeof(*voice->envMixer.em_state));
        voice->envMixer.em_first = 1;
        voice->envMixer.em_motion = 0;
        voice->envMixer.em_volume = 1;
        voice->envMixer.em_ltgt = 1;
        voice->envMixer.em_rtgt = 1;
        voice->envMixer.em_cvolL = 1;
        voice->envMixer.em_cvolR = 1;
        voice->envMixer.em_dryamt = 0;
        voice->envMixer.em_wetamt = 0;
        voice->envMixer.em_lratm = 1;
        voice->envMixer.em_lratl = 0;
        voice->envMixer.em_rratm = 1;
        voice->envMixer.em_rratl = 0;
        voice->envMixer.em_delta = 0;
        voice->envMixer.em_segEnd = 0;
        voice->envMixer.em_pan = 64;
        voice->unk_74 = 0;
        voice->next = NULL;
        voice->gammaID = 0;
        voice->unk_79 = i;
    }

    gSynDriverPtr->al_unk_gamma = alHeapAlloc(heap, config->unk_num_gamma, sizeof(*gSynDriverPtr->al_unk_gamma));

    for (i = 0; i < config->unk_num_gamma; i++) {
        AlUnkGamma* gamma = &gSynDriverPtr->al_unk_gamma[i];
        gamma->pvoice_10 = NULL;
        gamma->pvoice_14 = NULL;
        gamma->unk_00 = 0x7FFF;
        gamma->currentEffectID = 0;
        gamma->fxL = alHeapAlloc(heap, 1, sizeof(*gamma->fxL));
        gamma->fxR = alHeapAlloc(heap, 1, sizeof(*gamma->fxR));
        func_80058E84(gamma->fxL, gamma->currentEffectID, heap);
        func_80058E84(gamma->fxR, gamma->currentEffectID, heap);
    }

    gSynDriverPtr->unk_drvr_24 = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    gSynDriverPtr->unk_drvr_28 = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FF0 = 4;

    D_800A3FE0 = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    D_800A3FE4 = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    for (i = 0; i < 4 * AUDIO_SAMPLES; i++) {
        D_800A3FE4[i] = D_800A3FE0[i] = 0;
    }

    gSynDriverPtr->heap = heap;
}

void au_driver_release(void) {
    if (gActiveSynDriverPtr != NULL) {
        gActiveSynDriverPtr = NULL;
    }
}

Acmd* alAudioFrame(Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen) {
    Acmd* cmdListPos;
    AuPVoice* pvoice;
    AlUnkGamma* gamma;

    s16* bufPos;
    s16 auxOut;
    s16 mainOut;

    s32 i;
    s32 var_s7;

    cmdListPos = cmdList;
    bufPos = outBuf;
    if (gActiveSynDriverPtr == NULL) {
        *cmdLen = 0;
    } else {
        snd_add_sfx_output();
        if (D_80078E5C) {
            for (i = 0; i < gSynDriverPtr->num_pvoice; i++) {
                pvoice = &gSynDriverPtr->pvoices[i];
                if (pvoice->envMixer.em_motion == 1) {
                    func_80057874(i, pvoice->envMixer.em_pan);
                }
            }
            D_80078E5C = FALSE;
        }
        while (outLen > 0) {
            snd_update_sequence_players();
            for (i = 0; i < gSynDriverPtr->num_pvoice; i++) {
                pvoice = &gSynDriverPtr->pvoices[i];

                if ((pvoice->gammaID != 0xFF) && (pvoice->gammaID < gSynDriverPtr->unk_num_gamma)) {
                    gamma = &gSynDriverPtr->al_unk_gamma[pvoice->gammaID];
                    if (gamma->pvoice_14 != NULL) {
                        gamma->pvoice_14->next = pvoice;
                    } else {
                        gamma->pvoice_10 = pvoice;
                    }
                    gamma->pvoice_14 = pvoice;
                }
            }
            var_s7 = 1;
            for (i = 0; i < gSynDriverPtr->unk_num_gamma; i++) {
                gamma = &gSynDriverPtr->al_unk_gamma[i];
                if (gamma->pvoice_10 != NULL) {
                    aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 8 * AUDIO_SAMPLES);
                    if (gamma->pvoice_10 != NULL) {
                        AuPVoice* next;
                        do {
                            cmdListPos = func_80058050(gamma->pvoice_10, cmdListPos);
                            next = gamma->pvoice_10->next;
                            gamma->pvoice_10->next = NULL;
                            gamma->pvoice_10 = next;
                        } while (next != 0);
                        gamma->pvoice_14 = 0;
                    }
                    if (gamma->currentEffectID != 0) {
                        cmdListPos = func_80059310(gamma->fxL, cmdListPos, N_AL_AUX_L_OUT, 0);
                        cmdListPos = func_80059310(gamma->fxR, cmdListPos, N_AL_AUX_R_OUT, 0);
                    }
                    if (i == D_800A3FEC) {
                        mainOut = -1;
                        switch (D_800A3FEE) {
                            case 1:
                                mainOut = N_AL_MAIN_L_OUT;
                                auxOut = N_AL_AUX_L_OUT;
                                break;
                            case 2:
                                mainOut = N_AL_MAIN_R_OUT;
                                auxOut = N_AL_AUX_R_OUT;
                                break;
                        }
                        if (mainOut != -1) {
                            aSaveBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, mainOut, osVirtualToPhysical(D_800A3FE0 + (D_800A3FE8 % D_800A3FF0) * AUDIO_SAMPLES));
                            aLoadBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, mainOut, osVirtualToPhysical(D_800A3FE0 + ((D_800A3FE8 + 1) % D_800A3FF0) * AUDIO_SAMPLES));
                            aSaveBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, auxOut, osVirtualToPhysical(D_800A3FE4 + (D_800A3FE8 % D_800A3FF0) * AUDIO_SAMPLES));
                            aLoadBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, auxOut, osVirtualToPhysical(D_800A3FE4 + ((D_800A3FE8 + 1) % D_800A3FF0) * AUDIO_SAMPLES));

                        }
                    }
                    if (var_s7) {
                        aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                    } else {
                        aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->unk_drvr_28));
                    }
                    aMix(cmdListPos++, 0, gamma->unk_00, N_AL_AUX_L_OUT, 0);
                    aMix(cmdListPos++, 0, gamma->unk_00, N_AL_AUX_R_OUT, 2 * AUDIO_SAMPLES);
                    aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->unk_drvr_28));
                    if (var_s7) {
                        aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                        var_s7 = FALSE;
                    } else {
                        aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->unk_drvr_24));
                    }
                    aMix(cmdListPos++, 0, gamma->unk_00, N_AL_MAIN_L_OUT, 0);
                    aMix(cmdListPos++, 0, gamma->unk_00, N_AL_MAIN_R_OUT, 2 * AUDIO_SAMPLES);
                    aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->unk_drvr_24));
                }
            }
            aDMEMMove(cmdListPos++, 0, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
            aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_AUX_L_OUT, osVirtualToPhysical(gSynDriverPtr->unk_drvr_28));
            aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
            aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);
            if (D_80078E58) {
                u16 temp;
                aDMEMMove(cmdListPos++, N_AL_MAIN_L_OUT, 0, 4 * AUDIO_SAMPLES);
                aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
                temp = D_80078E5A;
                aMix(cmdListPos++, 0, temp, 0, N_AL_MAIN_L_OUT);
                aMix(cmdListPos++, 0, temp, 2 * AUDIO_SAMPLES, N_AL_MAIN_R_OUT);
            }
            outLen -= AUDIO_SAMPLES;
            aInterleavePart(cmdListPos++);
            aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, bufPos);
            bufPos += 2 * AUDIO_SAMPLES;
            D_800A3FE8++;
            gSynDriverPtr->curSamples += AUDIO_SAMPLES;
        }
        *cmdLen = (cmdListPos - cmdList);
    }
    return cmdListPos;
}

void func_80056D34(void) {
    D_80078E58 = TRUE;
}

void func_80056D44(s16 arg0) {
    D_80078E5A = arg0;
}

s16 func_80056D50(void) {
    return D_80078E5A;
}

void func_80056D5C(u8 arg0) {
    D_80078181 = arg0;
    D_80078E5C = TRUE;
}

void func_80056D78(u8 arg0, u16 arg1) {
    AlUnkGamma* gamma = &gSynDriverPtr->al_unk_gamma[arg0];

    gamma->unk_00 = arg1 & 0x7FFF;
}

u16 func_80056DA4(u8 arg0, u16 arg1) {
    AlUnkGamma* gamma = &gSynDriverPtr->al_unk_gamma[arg0];

    return gamma->unk_00;
}

void func_80056DCC(u8 arg0, u8 effectID) {
    AlUnkGamma* gamma = &gSynDriverPtr->al_unk_gamma[arg0];

    gamma->currentEffectID = effectID;
    func_8005904C(gamma->fxL, effectID);
    func_8005904C(gamma->fxR, effectID);
}

void func_80056E34(u8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    AlUnkGamma* gamma = &gSynDriverPtr->al_unk_gamma[arg0];

    au_fx_param_hdl(gamma->fxL, arg1, arg2, arg3);
    au_fx_param_hdl(gamma->fxR, arg1, arg2, arg3);
}

void func_80056EC0(u8 arg0, s8 arg1) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[arg0];

    pvoice->gammaID = arg1;
}

// n_alLoadParam case AL_FILTER_RESET
void au_pvoice_reset_filter(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* filter = &pvoice->loadFilter;

    pvoice->envMixer.em_motion = 0;
    pvoice->envMixer.em_first = 1;
    pvoice->envMixer.em_volume = 1;
    pvoice->resampler.delta = 0;
    pvoice->resampler.first = 1;
    filter->dc_lastsam = 0;
    filter->dc_first = 1;
    filter->dc_sample = 0;
    if (filter->dc_table != NULL) {
        filter->dc_memin = filter->dc_table->base;
        if (filter->dc_table->type == 0) {
            if (filter->dc_table->loopEnd != 0){
                filter->dc_loop.count = filter->dc_table->loopCount;
            }
        } else if (filter->dc_table->type == 1) {
            if (filter->dc_table->loopEnd != 0){
                filter->dc_loop.count = filter->dc_table->loopCount;
            }
        }
    }
}

void func_80056F78(u8 index) {
    AuPVoice* pvoice = (AuPVoice*)&gSynDriverPtr->pvoices[index];

    pvoice->envMixer.em_motion = 1;
}

#define ADPCMFBYTES      9

// n_alLoadParam case AL_FILTER_SET_WAVETABLE
void au_pvoice_set_filter(u8 index, u8 reverbType, Instrument* table, f32 pitchRatio, s16 arg4, u8 pan, u8 reverb, s32 arg7) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[index];
    AuLoadFilter* filter = &pvoice->loadFilter;
    AuEnvMixer* envMixer = &pvoice->envMixer;
    AuResampler* resampler = &pvoice->resampler;

//au_pvoice_set_filter(i, voice->reverbType, voice->instrument, voice->pitchRatio, voice->unk_0C, voice->pan, voice->reverb, voice->unk_08);

    pvoice->gammaID = reverbType;
    filter->dc_table = table;

    pvoice->loadFilter.dc_memin = filter->dc_table->base;
    pvoice->loadFilter.dc_sample = 0;

    switch (filter->dc_table->type) {
        case AL_ADPCM_WAVE:
            filter->dc_table->wavDataLength = (filter->dc_table->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->loadFilter.dc_bookSize = filter->dc_table->unk_1C;
            if (filter->dc_table->loopEnd == 0) {
                filter->dc_loop.count = 0;
                filter->dc_loop.end = 0;
                filter->dc_loop.start = 0;
            } else {
                filter->dc_loop.start = filter->dc_table->loopStart;
                filter->dc_loop.end = filter->dc_table->loopEnd;
                filter->dc_loop.count = filter->dc_table->loopCount;
                alCopy(filter->dc_table->loopPredictorOffset, filter->dc_lstate, sizeof(ADPCM_STATE));
            }
            break;
        case AL_RAW16_WAVE:
            if (filter->dc_table->loopEnd != 0) {
                filter->dc_loop.start = filter->dc_table->loopStart;
                filter->dc_loop.end = filter->dc_table->loopEnd;
                filter->dc_loop.count = filter->dc_table->loopCount;
            } else {
                filter->dc_loop.count = 0;
                filter->dc_loop.end = 0;
                filter->dc_loop.start = 0;
            }
            break;
    }

    envMixer->em_motion = 1;
    envMixer->em_first = 1;
    envMixer->em_delta = 0;
    envMixer->em_segEnd = arg7;
    envMixer->em_pan = pan;
    envMixer->em_volume = SQ(arg4) >> 0xF;
    envMixer->em_dryamt = AuEqPower[reverb];
    envMixer->em_wetamt = AuEqPower[AU_EQPOW_MAX_IDX - reverb];
    if (envMixer->em_segEnd != 0) {
        envMixer->em_cvolL = 1;
        envMixer->em_cvolR = 1;
    } else {
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    }
    resampler->rs_ratio = pitchRatio;
}

void au_pvoice_set_filter_wavetable(u8 voiceIdx, Instrument* table) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* filter = &pvoice->loadFilter;

    pvoice->loadFilter.dc_table = table;
    pvoice->loadFilter.dc_memin = filter->dc_table->base;
    pvoice->loadFilter.dc_sample = 0;

    switch (filter->dc_table->type) {
        case 0:
            filter->dc_table->wavDataLength = (filter->dc_table->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->loadFilter.dc_bookSize = filter->dc_table->unk_1C;
            if (filter->dc_table->loopEnd == 0) {
                pvoice->loadFilter.dc_loop.count = 0;
                pvoice->loadFilter.dc_loop.end = 0;
                pvoice->loadFilter.dc_loop.start = 0;
            } else {
                pvoice->loadFilter.dc_loop.start = filter->dc_table->loopStart;
                pvoice->loadFilter.dc_loop.end = filter->dc_table->loopEnd;
                pvoice->loadFilter.dc_loop.count = filter->dc_table->loopCount;
                alCopy(filter->dc_table->loopPredictorOffset, pvoice->loadFilter.dc_lstate, sizeof(ADPCM_STATE));
            }
            break;
        case 1:
            if (filter->dc_table->loopEnd != 0) {
                pvoice->loadFilter.dc_loop.start = filter->dc_table->loopStart;
                pvoice->loadFilter.dc_loop.end = filter->dc_table->loopEnd;
                pvoice->loadFilter.dc_loop.count = filter->dc_table->loopCount;
            } else {
                pvoice->loadFilter.dc_loop.count = 0;
                pvoice->loadFilter.dc_loop.end = 0;
                pvoice->loadFilter.dc_loop.start = 0;
            }
            break;
    }
}

void au_pvoice_set_pitch_ratio(u8 voiceIdx, f32 pitchRatio) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    pvoice->resampler.rs_ratio = pitchRatio;
}

void func_8005736C(u8 voiceIdx, s16 volume, s32 arg2, u8 arg3, u8 arg4) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    } else {
        envMixer->em_cvolL = _getVol(envMixer->em_cvolL, envMixer->em_delta, envMixer->em_lratm, envMixer->em_lratl);
        envMixer->em_cvolR = _getVol(envMixer->em_cvolR, envMixer->em_delta, envMixer->em_rratm, envMixer->em_rratl);
    }
    if (envMixer->em_cvolL == 0) {
        envMixer->em_cvolL = 1;
    }
    if (envMixer->em_cvolR == 0) {
        envMixer->em_cvolR = 1;
    }

    envMixer->em_delta = 0;
    envMixer->em_segEnd = arg2;
    envMixer->em_pan = arg3;
    envMixer->em_volume = SQ(volume) >> 0xF;
    envMixer->em_dryamt = AuEqPower[arg4];
    envMixer->em_wetamt = AuEqPower[AU_EQPOW_MAX_IDX - arg4];
    envMixer->em_first = 1;
}

void func_80057548(u8 voiceIdx, u8 arg1, u8 arg2) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    } else {
        envMixer->em_cvolL = _getVol(envMixer->em_cvolL, envMixer->em_delta, envMixer->em_lratm, envMixer->em_lratl);
        envMixer->em_cvolR = _getVol(envMixer->em_cvolR, envMixer->em_delta, envMixer->em_rratm, envMixer->em_rratl);
    }
    if (envMixer->em_cvolL == 0) {
        envMixer->em_cvolL = 1;
    }
    if (envMixer->em_cvolR == 0) {
        envMixer->em_cvolR = 1;
    }

    envMixer->em_pan = arg1;
    envMixer->em_dryamt = AuEqPower[arg2];
    envMixer->em_wetamt = AuEqPower[AU_EQPOW_MAX_IDX - arg2];
    envMixer->em_first = 1;
}

void func_800576EC(u8 voiceIdx, s16 arg1, s32 arg2) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    } else {
        envMixer->em_cvolL = _getVol(envMixer->em_cvolL, envMixer->em_delta, envMixer->em_lratm, envMixer->em_lratl);
        envMixer->em_cvolR = _getVol(envMixer->em_cvolR, envMixer->em_delta, envMixer->em_rratm, envMixer->em_rratl);
    }
    if (envMixer->em_cvolL == 0) {
        envMixer->em_cvolL = 1;
    }
    if (envMixer->em_cvolR == 0) {
        envMixer->em_cvolR = 1;
    }

    envMixer->em_volume = SQ(arg1) >> 0xF;
    envMixer->em_delta = 0;
    envMixer->em_segEnd = arg2;
    envMixer->em_first = 1;
}

void func_80057874(u8 voiceIdx, u8 pan) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    } else {
        envMixer->em_cvolL = _getVol(envMixer->em_cvolL, envMixer->em_delta, envMixer->em_lratm, envMixer->em_lratl);
        envMixer->em_cvolR = _getVol(envMixer->em_cvolR, envMixer->em_delta, envMixer->em_rratm, envMixer->em_rratl);
    }
    if (envMixer->em_cvolL == 0) {
        envMixer->em_cvolL = 1;
    }
    if (envMixer->em_cvolR == 0) {
        envMixer->em_cvolR = 1;
    }

    envMixer->em_pan = pan;
    envMixer->em_first = 1;
}

void func_800579D8(u8 voiceIdx, u8 dryAmt) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->em_pan]) >> 0xF;
        }
    } else {
        envMixer->em_cvolL = _getVol(envMixer->em_cvolL, envMixer->em_delta, envMixer->em_lratm, envMixer->em_lratl);
        envMixer->em_cvolR = _getVol(envMixer->em_cvolR, envMixer->em_delta, envMixer->em_rratm, envMixer->em_rratl);
    }
    if (envMixer->em_cvolL == 0) {
        envMixer->em_cvolL = 1;
    }
    if (envMixer->em_cvolR == 0) {
        envMixer->em_cvolR = 1;
    }

    envMixer->em_dryamt = AuEqPower[dryAmt];
    envMixer->em_wetamt = AuEqPower[AU_EQPOW_MAX_IDX - dryAmt];
    envMixer->em_first = 1;
}

s32 func_80057B64(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.em_motion;
}

s32 func_80057B8C(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->gammaID;
}

f32 func_80057BB4(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->resampler.rs_ratio;
}

u8 func_80057BDC(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.em_pan;
}

s16 func_80057C04(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.em_dryamt;
}

s16 func_80057C2C(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.em_wetamt;
}

s32 func_80057C54(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* sub48 = &pvoice->envMixer;
    u32 retVal;

    if (sub48->em_delta >= sub48->em_segEnd) {
        if (D_80078181 == 0) {
            retVal = (sub48->em_volume * AuEqPower[AU_EQPOW_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (sub48->em_volume * AuEqPower[sub48->em_pan] * 2) >> 0x10;
        }
    } else {
        retVal = _getVol(sub48->em_cvolL, sub48->em_delta, sub48->em_lratm, sub48->em_lratl);
    }
    return retVal;
}

s32 func_80057D0C(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* sub48 = &pvoice->envMixer;
    u32 retVal;

    if (sub48->em_delta >= sub48->em_segEnd) {
        if (D_80078181 == 0) {
            retVal = (sub48->em_volume * AuEqPower[AU_EQPOW_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (sub48->em_volume * AuEqPower[AU_EQPOW_MAX_IDX - sub48->em_pan] * 2) >> 0x10;
        }
    } else {
        retVal = _getVol(sub48->em_cvolL, sub48->em_delta, sub48->em_lratm, sub48->em_lratl);
    }
    return retVal;
}

void func_80057DC8(s32 arg0) {
    if (arg0 < 2) {
        D_800A3FF0 = 0;
        D_800A3FEE = 0;
    }

    D_800A3FF0 = arg0;
    if (arg0 >= 5) {
        D_800A3FF0 = 4;
    }
}

void func_80057E08(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 1;
    D_800A3FE8 = 0;
}

void func_80057E5C(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 2;
    D_800A3FE8 = 0;
}

void func_80057EB0(void) {
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FE8 = 0;
}

void func_80057ED0(s16 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = 0;
    D_800A3FEE = arg0;
    D_800A3FE8 = 0;
}

void alHeapInit(ALHeap* hp, u8* base, s32 len) {
    u32 i;
    s32 alignBytes = 0x10 - ((s32)base & 0xF);

    if (alignBytes != 0x10) {
        hp->base = base + alignBytes;
    } else {
        hp->base = base;
    }
    hp->len = len;
    hp->count = 0;
    hp->cur = hp->base;

    for (i = 0; i < (u32)(hp->len) >> 2; i++) {
        ((u32*)hp->base)[i] = 0;
    }
}

void* alHeapAlloc(ALHeap* heap, s32 count, s32 size) {
    void* ret = NULL;
    u8* newCur = &heap->cur[ALIGN16(count * size)];

    if (&heap->base[heap->len] >= newCur) {
        ret = heap->cur;
        heap->cur = newCur;
    }

    return ret;
}

void alCopy(void* src, void* dst, s32 size) {
    s32 i;
    u8* srcIt = src;
    u8* dstIt = dst;

    for (i = 0; i < size; i++) {
        *dstIt++ = *srcIt++;
    }
}

static s16 _getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel) {
    s32 tmpl;
    samples = samples >> 3;
    if (samples == 0) {
        return ivol;
    }
    tmpl = ratel * samples;
    tmpl = tmpl >> 16;
    tmpl += ratem * samples;
    return ivol + tmpl;
}
