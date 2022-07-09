#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

void func_80057874(u8 arg0, u8 arg1);
s16 _getVol(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

void snd_add_sfx_output(void);
void snd_update_sequence_players(void);
Acmd* func_80058050(AuPVoice*, Acmd*);
Acmd* func_80059310(AlUnkDelta*, Acmd*, s32, s32);

AlUnkAlpha* D_80078E50 = NULL;
AlUnkAlpha* D_80078E54 = NULL;
u8 D_80078E58 = FALSE;
u16 D_80078E5A = 0x7FFF;
u8 D_80078E5C = FALSE;

#define aLoadBufferSize(pkt,s,u,b) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_LOADBUFF, 24, 8) | _SHIFTL(s, 12, 12) | _SHIFTL(u, 0, 12); \
    _a->words.w1 = (unsigned int)(b); \
    }

#define aSaveBufferSize(pkt,s,u,b) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_SAVEBUFF, 24, 8) | _SHIFTL(s, 12, 12) | _SHIFTL(u, 0, 12); \
    _a->words.w1 = (unsigned int)(b); \
    }

#define aInterleavePart(pkt) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8); \
    }

extern s16 AuEqPower[128];

#define AL_COS_MID_IDX 64
#define AL_COS_MAX_IDX 127

void func_80056250(AlUnkAlpha* globals, ALConfig* config) {
    s32 i;
    ALHeap* heap = config->heap;

    if (D_80078E50 != NULL) {
        return;
    }

    globals->num_pvoice = config->unk_num_beta;
    globals->unk_10 = config->unk_num_gamma;
    globals->unk_00 = 0;
    globals->unk_04 = 0;
    globals->frequency = config->outputRate;
    globals->dmaNew = config->dmaNew;

    D_80078E50 = globals;
    D_80078E54 = globals;
    D_80078E58 = FALSE;
    D_80078E5A = 0x7FFF;
    D_80078E5C = TRUE;

    D_80078E54->pvoices = alHeapAlloc(heap, config->unk_num_beta, sizeof(*D_80078E54->pvoices));

    // this is inlined alN_PVoiceNew
    for (i = 0; i < config->unk_num_beta; i++) {
        AuPVoice* voice = &D_80078E54->pvoices[i];
        voice->loadFilter.dc_state = alHeapAlloc(heap, 1, sizeof(*voice->loadFilter.dc_state));
        voice->loadFilter.dc_lstate = alHeapAlloc(heap, 1, sizeof(*voice->loadFilter.dc_lstate));
        voice->loadFilter.dc_dmaFunc = ((ALDMAproc (*)(NUDMAState**))(D_80078E54->dmaNew))(&voice->loadFilter.dc_dmaState);
        voice->loadFilter.unk_2C = 0;
        voice->loadFilter.unk_30 = 1;
        voice->loadFilter.wavTable = 0;
        voice->resampler.rs_state = alHeapAlloc(heap, 1, sizeof(*voice->resampler.rs_state));
        voice->resampler.unk_40 = 0;
        voice->resampler.unk_44 = 1;
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
        voice->unk_78 = 0;
        voice->unk_79 = i;
    }

    D_80078E54->al_unk_gamma = alHeapAlloc(heap, config->unk_num_gamma, sizeof(*D_80078E54->al_unk_gamma));

    for (i = 0; i < config->unk_num_gamma; i++) {
        AlUnkGamma* gamma = &D_80078E54->al_unk_gamma[i];
        gamma->unk_beta_10 = NULL;
        gamma->unk_beta_14 = NULL;
        gamma->unk_00 = 0x7FFF;
        gamma->unk_0C = 0;
        gamma->unk_delta_4 = alHeapAlloc(heap, 1, sizeof(*gamma->unk_delta_4));
        gamma->unk_delta_8 = alHeapAlloc(heap, 1, sizeof(*gamma->unk_delta_8));
        func_80058E84(gamma->unk_delta_4, gamma->unk_0C, heap);
        func_80058E84(gamma->unk_delta_8, gamma->unk_0C, heap);
    }

    D_80078E54->unk_24 = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    D_80078E54->unk_28 = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FF0 = 4;

    D_800A3FE0 = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    D_800A3FE4 = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    for (i = 0; i < 4 * AUDIO_SAMPLES; i++) {
        D_800A3FE4[i] = D_800A3FE0[i] = 0;
    }

    D_80078E54->heap = heap;
}

void func_800565A4(void) {
    if (D_80078E50 != NULL) {
        D_80078E50 = NULL;
    }
}

Acmd* alAudioFrame(Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen) {
    Acmd* cmdListPos;
    AlUnkGamma* gamma1;
    AuPVoice* beta1;
    AuPVoice* pvoice;
    AlUnkGamma* gamma3;

    s16* sp10;
    u16 auxOut;
    s16 mainOut;

    s32 i;
    s32 var_s7;

    cmdListPos = cmdList;
    sp10 = outBuf;
    if (D_80078E50 == NULL) {
        *cmdLen = 0;
    } else {
        snd_add_sfx_output();
        if (D_80078E5C) {
            for (i = 0; i < D_80078E54->num_pvoice; i++) {
                pvoice = &D_80078E54->pvoices[i];
                if (pvoice->envMixer.em_motion == 1) {
                    func_80057874(i, pvoice->envMixer.em_pan);
                }
            }
            D_80078E5C = FALSE;
        }
        if (outLen > 0) {
            do {
                snd_update_sequence_players();
                for (i = 0; i < D_80078E54->num_pvoice; i++) {
                    pvoice = &D_80078E54->pvoices[i];

                    if ((pvoice->unk_78 != 0xFF) && (pvoice->unk_78 < D_80078E54->unk_10)) {
                        gamma3 = &D_80078E54->al_unk_gamma[pvoice->unk_78];
                        if (gamma3->unk_beta_14 != NULL) {
                            gamma3->unk_beta_14->next = pvoice;
                        } else {
                            gamma3->unk_beta_10 = pvoice;
                        }
                        gamma3->unk_beta_14 = pvoice;
                    }
                }
                var_s7 = 1;
                for (i = 0; i < D_80078E54->unk_10; i++) {
                    gamma3 = &D_80078E54->al_unk_gamma[i];
                    if (gamma3->unk_beta_10 != NULL) {
                        aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 8 * AUDIO_SAMPLES);
                        if (gamma3->unk_beta_10 != NULL) {
                            AuPVoice* next;
                            do {
                                cmdListPos = func_80058050(gamma3->unk_beta_10, cmdListPos);
                                next = gamma3->unk_beta_10->next;
                                gamma3->unk_beta_10->next = NULL;
                                gamma3->unk_beta_10 = next;
                            } while (next != 0);
                            gamma3->unk_beta_14 = 0;
                        }
                        if (gamma3->unk_0C != 0) {
                            cmdListPos = func_80059310(gamma3->unk_delta_8, func_80059310(gamma3->unk_delta_4, cmdListPos, N_AL_AUX_L_OUT, 0), N_AL_AUX_R_OUT, 0);
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
                            aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_28));
                        }
                        aMix(cmdListPos++, 0, gamma3->unk_00, N_AL_AUX_L_OUT, 0);
                        aMix(cmdListPos++, 0, gamma3->unk_00, N_AL_AUX_R_OUT, 2 * AUDIO_SAMPLES);
                        aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_28));
                        if (var_s7) {
                            aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                            var_s7 = FALSE;
                        } else {
                            aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_24));
                        }
                        aMix(cmdListPos++, 0, gamma3->unk_00, N_AL_MAIN_L_OUT, 0);
                        aMix(cmdListPos++, 0, gamma3->unk_00, N_AL_MAIN_R_OUT, 2 * AUDIO_SAMPLES);
                        aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_24));
                    }
                }
                aDMEMMove(cmdListPos++, 0, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
                aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_AUX_L_OUT, osVirtualToPhysical(D_80078E54->unk_28));
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
                aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, sp10);
                sp10 += 2 * AUDIO_SAMPLES;
                D_800A3FE8++;
                D_80078E54->unk_00 += AUDIO_SAMPLES;
            } while (outLen > 0);
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
    AlUnkGamma* gamma = &D_80078E54->al_unk_gamma[arg0];

    gamma->unk_00 = arg1 & 0x7FFF;
}

u16 func_80056DA4(u8 arg0, u16 arg1) {
    AlUnkGamma* gamma = &D_80078E54->al_unk_gamma[arg0];

    return gamma->unk_00;
}

void func_80056DCC(u8 arg0, u8 arg1) {
    AlUnkGamma* gamma = &D_80078E54->al_unk_gamma[arg0];

    gamma->unk_0C = arg1;
    func_8005904C(gamma->unk_delta_4, arg1);
    func_8005904C(gamma->unk_delta_8, arg1);
}

void func_80056E34(u8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    AlUnkGamma* gamma = &D_80078E54->al_unk_gamma[arg0];

    func_800598A0(gamma->unk_delta_4, arg1, arg2, arg3);
    func_800598A0(gamma->unk_delta_8, arg1, arg2, arg3);
}

void func_80056EC0(u8 arg0, s8 arg1) {
    AuPVoice* beta = &D_80078E54->pvoices[arg0];

    beta->unk_78 = arg1;
}

void func_80056EE8(u8 arg0) {
    AuPVoice* beta = &D_80078E54->pvoices[arg0];
    AuLoadFilter* zeta = &beta->loadFilter;

    beta->envMixer.em_motion = 0;
    beta->envMixer.em_first = 1;
    beta->envMixer.em_volume = 1;
    beta->resampler.unk_40 = 0;
    beta->resampler.unk_44 = 1;
    beta->loadFilter.unk_2C = 0;
    beta->loadFilter.unk_30 = 1;
    beta->loadFilter.unk_28 = 0;
    if (beta->loadFilter.instrument != NULL) {
        beta->loadFilter.wavTable = zeta->instrument->wavOffset;
        if (zeta->instrument->skipLoopPredictor == 0) {
            if (zeta->instrument->loopEnd != 0){
                beta->loadFilter.dc_loopCount = zeta->instrument->loopCount;
            }
        } else if (zeta->instrument->skipLoopPredictor == 1) {
            if (zeta->instrument->loopEnd != 0){
                beta->loadFilter.dc_loopCount = zeta->instrument->loopCount;
            }
        }
    }
}

void func_80056F78(u8 index) {
    AuPVoice* beta = (AuPVoice*)&D_80078E54->pvoices[index];

    beta->envMixer.em_motion = 1;
}

void func_80056FA4(u8 index, u8 arg1, Instrument* instrument, f32 arg3, s16 arg4, u8 arg5, u8 arg6, s32 arg7) {
    AuPVoice* beta = &D_80078E54->pvoices[index];
    AuLoadFilter* sub04 = &beta->loadFilter;
    AuEnvMixer* sub48 = &beta->envMixer;
    AuResampler* sub38 = &beta->resampler;

    beta->unk_78 = arg1;
    sub04->instrument = instrument;

    beta->loadFilter.wavTable = sub04->instrument->wavOffset;
    beta->loadFilter.unk_28 = 0;

    switch (sub04->instrument->skipLoopPredictor) {
        case 0:
            sub04->instrument->wavDataLength = (sub04->instrument->wavDataLength / 9) * 9;
            beta->loadFilter.dc_bookSize = sub04->instrument->unk_1C;
            if (sub04->instrument->loopEnd == 0) {
                sub04->dc_loopCount = 0;
                sub04->dc_loopEnd = 0;
                sub04->dc_loopStart = 0;
            } else {
                sub04->dc_loopStart = sub04->instrument->loopStart;
                sub04->dc_loopEnd = sub04->instrument->loopEnd;
                sub04->dc_loopCount = sub04->instrument->loopCount;
                alCopy(sub04->instrument->loopPredictorOffset, sub04->dc_lstate, sizeof(AlUnkZeta));
            }
            break;
        case 1:
            if (sub04->instrument->loopEnd != 0) {
                sub04->dc_loopStart = sub04->instrument->loopStart;
                sub04->dc_loopEnd = sub04->instrument->loopEnd;
                sub04->dc_loopCount = sub04->instrument->loopCount;
            } else {
                sub04->dc_loopCount = 0;
                sub04->dc_loopEnd = 0;
                sub04->dc_loopStart = 0;
            }
            break;
    }

    sub48->em_motion = 1;
    sub48->em_first = 1;
    sub48->em_delta = 0;
    sub48->em_segEnd = arg7;
    sub48->em_pan = arg5;
    sub48->em_volume = SQ(arg4) >> 0xF;
    sub48->em_dryamt = (AuEqPower[arg6]);
    sub48->em_wetamt = (AuEqPower[AL_COS_MAX_IDX - arg6]);
    if (sub48->em_segEnd != 0) {
        sub48->em_cvolL = 1;
        sub48->em_cvolR = 1;
    } else {
        if (D_80078181 == 0) {
            sub48->em_cvolL = (sub48->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            sub48->em_cvolR = (sub48->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            sub48->em_cvolL = (sub48->em_volume * AuEqPower[sub48->em_pan]) >> 0xF;
            sub48->em_cvolR = (sub48->em_volume * AuEqPower[AL_COS_MAX_IDX - sub48->em_pan]) >> 0xF;
        }
    }
    sub38->rs_ratio = arg3;
}

void func_80057224(u8 voiceIdx, Instrument* instrument) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuLoadFilter* filter = &pvoice->loadFilter;

    pvoice->loadFilter.instrument = instrument;
    pvoice->loadFilter.wavTable = filter->instrument->wavOffset;
    pvoice->loadFilter.unk_28 = 0;

    switch (filter->instrument->skipLoopPredictor) {
        case 0:
            filter->instrument->wavDataLength = (filter->instrument->wavDataLength / 9) * 9;
            pvoice->loadFilter.dc_bookSize = filter->instrument->unk_1C;
            if (filter->instrument->loopEnd == 0) {
                pvoice->loadFilter.dc_loopCount = 0;
                pvoice->loadFilter.dc_loopEnd = 0;
                pvoice->loadFilter.dc_loopStart = 0;
            } else {
                pvoice->loadFilter.dc_loopStart = filter->instrument->loopStart;
                pvoice->loadFilter.dc_loopEnd = filter->instrument->loopEnd;
                pvoice->loadFilter.dc_loopCount = filter->instrument->loopCount;
                alCopy(filter->instrument->loopPredictorOffset, pvoice->loadFilter.dc_lstate, sizeof(AlUnkZeta));
            }
            break;
        case 1:
            if (filter->instrument->loopEnd != 0) {
                pvoice->loadFilter.dc_loopStart = filter->instrument->loopStart;
                pvoice->loadFilter.dc_loopEnd = filter->instrument->loopEnd;
                pvoice->loadFilter.dc_loopCount = filter->instrument->loopCount;
            } else {
                pvoice->loadFilter.dc_loopCount = 0;
                pvoice->loadFilter.dc_loopEnd = 0;
                pvoice->loadFilter.dc_loopStart = 0;
            }
            break;
    }
}

void func_80057344(u8 voiceIdx, f32 arg1) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];

    pvoice->resampler.rs_ratio = arg1;
}

void func_8005736C(u8 voiceIdx, s16 volume, s32 arg2, u8 arg3, u8 arg4) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MAX_IDX - envMixer->em_pan]) >> 0xF;
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
    envMixer->em_wetamt = AuEqPower[AL_COS_MAX_IDX - arg4];
    envMixer->em_first = 1;
}

void func_80057548(u8 voiceIdx, u8 arg1, u8 arg2) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MAX_IDX - envMixer->em_pan]) >> 0xF;
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
    envMixer->em_wetamt = AuEqPower[AL_COS_MAX_IDX - arg2];
    envMixer->em_first = 1;
}

void func_800576EC(u8 voiceIdx, s16 arg1, s32 arg2) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MAX_IDX - envMixer->em_pan]) >> 0xF;
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
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MAX_IDX - envMixer->em_pan]) >> 0xF;
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
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->em_delta >= envMixer->em_segEnd) {
        envMixer->em_delta = envMixer->em_segEnd;
        if (D_80078181 == 0) {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MID_IDX]) >> 0xF;
        } else {
            envMixer->em_cvolL = (envMixer->em_volume * AuEqPower[envMixer->em_pan]) >> 0xF;
            envMixer->em_cvolR = (envMixer->em_volume * AuEqPower[AL_COS_MAX_IDX - envMixer->em_pan]) >> 0xF;
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
    envMixer->em_wetamt = AuEqPower[AL_COS_MAX_IDX - dryAmt];
    envMixer->em_first = 1;
}

s32 func_80057B64(u8 voiceIdx) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];

    return pvoice->envMixer.em_motion;
}

s32 func_80057B8C(u8 voiceIdx) {
    AuPVoice* pvoice =  &D_80078E54->pvoices[voiceIdx];

    return pvoice->unk_78;
}

f32 func_80057BB4(u8 voiceIdx) {
    AuPVoice* pvoice =  &D_80078E54->pvoices[voiceIdx];

    return pvoice->resampler.rs_ratio;
}

u8 func_80057BDC(u8 voiceIdx) {
    AuPVoice* pvoice =  &D_80078E54->pvoices[voiceIdx];

    return pvoice->envMixer.em_pan;
}

s16 func_80057C04(u8 voiceIdx) {
    AuPVoice* pvoice =  &D_80078E54->pvoices[voiceIdx];

    return pvoice->envMixer.em_dryamt;
}

s16 func_80057C2C(u8 voiceIdx) {
    AuPVoice* beta =  &D_80078E54->pvoices[voiceIdx];

    return beta->envMixer.em_wetamt;
}

s32 func_80057C54(u8 voiceIdx) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* sub48 = &pvoice->envMixer;
    u32 retVal;

    if (sub48->em_delta >= sub48->em_segEnd) {
        if (D_80078181 == 0) {
            retVal = (sub48->em_volume * AuEqPower[AL_COS_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (sub48->em_volume * AuEqPower[sub48->em_pan] * 2) >> 0x10;
        }
    } else {
        retVal = _getVol(sub48->em_cvolL, sub48->em_delta, sub48->em_lratm, sub48->em_lratl);
    }
    return retVal;
}

s32 func_80057D0C(u8 voiceIdx) {
    AuPVoice* pvoice = &D_80078E54->pvoices[voiceIdx];
    AuEnvMixer* sub48 = &pvoice->envMixer;
    u32 retVal;

    if (sub48->em_delta >= sub48->em_segEnd) {
        if (D_80078181 == 0) {
            retVal = (sub48->em_volume * AuEqPower[AL_COS_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (sub48->em_volume * AuEqPower[AL_COS_MAX_IDX - sub48->em_pan] * 2) >> 0x10;
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
