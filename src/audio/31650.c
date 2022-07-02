#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

extern void snd_add_sfx_output(void);
extern void snd_update_sequence_players(void);
extern Acmd* func_80058050(AlUnkBeta*, Acmd*);
extern Acmd* func_80059310(AlUnkDelta*, Acmd*, s32, s32);

void func_80057874(u8 arg0, u8 arg1);
s16 func_80058004(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

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

// values for cosine from 0 to pi/2 multiplied by 32767
s16 AlCosineBlend[128] = { 
    32767, 32764, 32757, 32744, 32727, 32704, 32677, 32644,
    32607, 32564, 32517, 32464, 32407, 32344, 32277, 32205,
    32127, 32045, 31958, 31866, 31770, 31668, 31561, 31450,
    31334, 31213, 31087, 30957, 30822, 30682, 30537, 30388,
    30234, 30075, 29912, 29744, 29572, 29395, 29214, 29028,
    28838, 28643, 28444, 28241, 28033, 27821, 27605, 27385,
    27160, 26931, 26698, 26461, 26220, 25975, 25726, 25473,
    25216, 24956, 24691, 24423, 24151, 23875, 23596, 23313,
    23026, 22736, 22442, 22145, 21845, 21541, 21234, 20924,
    20610, 20294, 19974, 19651, 19325, 18997, 18665, 18331,
    17993, 17653, 17310, 16965, 16617, 16266, 15913, 15558,
    15200, 14840, 14477, 14113, 13746, 13377, 13006, 12633,
    12258, 11881, 11503, 11122, 10740, 10357,  9971,  9584,
     9196,  8806,  8415,  8023,  7630,  7235,  6839,  6442,
     6044,  5646,  5246,  4845,  4444,  4042,  3640,  3237,
     2833,  2429,  2025,  1620,  1216,   810,   405,     0
    };

#define AL_COS_MID_IDX 64
#define AL_COS_MAX_IDX 127

void func_80056250(AlUnkAlpha* globals, ALConfig* config) {
    s32 i;
    ALHeap* heap = config->heap;

    if (D_80078E50 != NULL) {
        return;
    }

    globals->unk_0C = config->unk_num_beta;
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

    D_80078E54->al_unk_beta = alHeapAlloc(heap, config->unk_num_beta, sizeof(*D_80078E54->al_unk_beta));

    for (i = 0; i < config->unk_num_beta; i++) {
        AlUnkBeta* beta = &D_80078E54->al_unk_beta[i];
        beta->unk_zeta_04 = alHeapAlloc(heap, 1, sizeof(*beta->unk_zeta_04));
        beta->unk_zeta_08 = alHeapAlloc(heap, 1, sizeof(*beta->unk_zeta_08));
        beta->dmaProc = ((ALDMAproc (*)(NUDMAState**))(D_80078E54->dmaNew))(&beta->dmaState);
        beta->unk_2C = 0;
        beta->unk_30 = 1;
        beta->unk_34 = 0;
        beta->unk_sigma_38 = alHeapAlloc(heap, 1, sizeof(*beta->unk_sigma_38));
        beta->unk_40 = 0;
        beta->unk_44 = 1;
        beta->unk_3C = 1.0f;
        beta->unk_eta_48 = alHeapAlloc(heap, 1, sizeof(*beta->unk_eta_48));
        beta->unk_6C = 1;
        beta->unk_70 = 0;
        beta->unk_4E = 1;
        beta->unk_5C = 1;
        beta->unk_62 = 1;
        beta->unk_50 = 1;
        beta->unk_52 = 1;
        beta->unk_54 = 0;
        beta->unk_56 = 0;
        beta->unk_5A = 1;
        beta->unk_58 = 0;
        beta->unk_60 = 1;
        beta->unk_5E = 0;
        beta->unk_64 = 0;
        beta->unk_68 = 0;
        beta->unk_4C = 64;
        beta->unk_74 = 0;
        beta->next = NULL;
        beta->unk_78 = 0;
        beta->unk_79 = i;
    }

    D_80078E54->al_unk_gamma = alHeapAlloc(heap, config->unk_num_gamma, sizeof(*D_80078E54->al_unk_gamma));

    for (i = 0; i < config->unk_num_gamma; i++) {
        AlUnkGamma* temp = &D_80078E54->al_unk_gamma[i];
        temp->unk_beta_10 = 0;
        temp->unk_beta_14 = 0;
        temp->unk_00 = 0x7FFF;
        temp->unk_0C = 0;
        temp->unk_delta_4 = alHeapAlloc(heap, 1, sizeof(*temp->unk_delta_4));
        temp->unk_delta_8 = alHeapAlloc(heap, 1, sizeof(*temp->unk_delta_8));
        func_80058E84(temp->unk_delta_4, temp->unk_0C, heap);
        func_80058E84(temp->unk_delta_8, temp->unk_0C, heap);
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
    AlUnkBeta* beta1;
    AlUnkBeta* beta2;
    AlUnkGamma* gamma3;
    
    s16* sp10;
    u16 offset2;
    s16 offset1;

    s32 i;
    s32 var_s7;
    
    cmdListPos = cmdList;
    sp10 = outBuf;
    if (D_80078E50 == NULL) {
        *cmdLen = 0;
    } else {
        snd_add_sfx_output();
        if (D_80078E5C) {
            for (i = 0; i < D_80078E54->unk_0C; i++) {
                beta2 = &D_80078E54->al_unk_beta[i];
                if (beta2->unk_70 == 1) {
                    func_80057874(i, (u8)beta2->unk_4C); //TODO cleanup
                }
            }
            D_80078E5C = FALSE;
        }
        if (outLen > 0) {
            do {
                snd_update_sequence_players();
                for (i = 0; i < D_80078E54->unk_0C; i++) {
                    beta2 = &D_80078E54->al_unk_beta[i];

                    if ((beta2->unk_78 != 0xFF) && (beta2->unk_78 < D_80078E54->unk_10)) {
                        gamma3 = &D_80078E54->al_unk_gamma[beta2->unk_78];
                        if (gamma3->unk_beta_14 != NULL) {
                            gamma3->unk_beta_14->next = beta2;
                        } else {
                            gamma3->unk_beta_10 = beta2;
                        }
                        gamma3->unk_beta_14 = beta2;
                    }
                }
                var_s7 = 1;
                for (i = 0; i < D_80078E54->unk_10; i++) {
                    gamma3 = &D_80078E54->al_unk_gamma[i];
                    if (gamma3->unk_beta_10 != NULL) {
                        aClearBuffer(cmdListPos++, 0x4E0, 8 * AUDIO_SAMPLES);
                        if (gamma3->unk_beta_10 != NULL) {
                            AlUnkBeta* next;
                            do {
                                cmdListPos = func_80058050(gamma3->unk_beta_10, cmdListPos);
                                next = gamma3->unk_beta_10->next;
                                gamma3->unk_beta_10->next = NULL;
                                gamma3->unk_beta_10 = next;
                            } while (next != 0);
                            gamma3->unk_beta_14 = 0;
                        }
                        if (gamma3->unk_0C != 0) {
                            cmdListPos = func_80059310(gamma3->unk_delta_8, func_80059310(gamma3->unk_delta_4, cmdListPos, 0x7C0, 0), 0x930, 0);
                        }
                        if (i == D_800A3FEC) {
                            offset1 = -1;
                            switch (D_800A3FEE) {
                                case 1:
                                    offset1 = 0x4E0;
                                    offset2 = 0x7C0;
                                    break;
                                case 2:
                                    offset1 = 0x650;
                                    offset2 = 0x930;
                                    break;
                            }
                            if (offset1 != -1) {
                                aSaveBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, offset1, osVirtualToPhysical(D_800A3FE0 + (D_800A3FE8 % D_800A3FF0) * AUDIO_SAMPLES));
                                aLoadBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, offset1, osVirtualToPhysical(D_800A3FE0 + ((D_800A3FE8 + 1) % D_800A3FF0) * AUDIO_SAMPLES));
                                aSaveBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, offset2, osVirtualToPhysical(D_800A3FE4 + (D_800A3FE8 % D_800A3FF0) * AUDIO_SAMPLES));                                
                                aLoadBufferSize(cmdListPos++, 2 * AUDIO_SAMPLES, offset2, osVirtualToPhysical(D_800A3FE4 + ((D_800A3FE8 + 1) % D_800A3FF0) * AUDIO_SAMPLES));
                                
                            }
                        }
                        if (var_s7) {
                            aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                        } else {
                            aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_28));
                        }
                        aMix(cmdListPos++, 0, gamma3->unk_00, 0x7C0, 0);
                        aMix(cmdListPos++, 0, gamma3->unk_00, 0x930, 2 * AUDIO_SAMPLES);
                        aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_28));
                        if (var_s7) {
                            aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                            var_s7 = FALSE;
                        } else {
                            aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_24));
                        }
                        aMix(cmdListPos++, 0, gamma3->unk_00, 0x4E0, 0);
                        aMix(cmdListPos++, 0, gamma3->unk_00, 0x650, 2 * AUDIO_SAMPLES);
                        aSaveBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(D_80078E54->unk_24));
                    }
                }
                aDMEMMove(cmdListPos++, 0, 0x4E0, 4 * AUDIO_SAMPLES);
                aLoadBufferSize(cmdListPos++, 4 * AUDIO_SAMPLES, 0x7C0, osVirtualToPhysical(D_80078E54->unk_28));
                aMix(cmdListPos++, 0, 0x7FFF, 0x7C0, 0x4E0);
                aMix(cmdListPos++, 0, 0x7FFF, 0x930, 0x650);
                if (D_80078E58) {
                    u16 temp;
                    aDMEMMove(cmdListPos++, 0x4E0, 0, 4 * AUDIO_SAMPLES);
                    aClearBuffer(cmdListPos++, 0x4E0, 4 * AUDIO_SAMPLES);
                    temp = D_80078E5A;
                    aMix(cmdListPos++, 0, temp, 0, 0x4E0);
                    aMix(cmdListPos++, 0, temp, 2 * AUDIO_SAMPLES, 0x650);
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
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[arg0];

    beta->unk_78 = arg1;
}

void func_80056EE8(u8 arg0) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[arg0];
    AlUnkZeta* zeta = &beta->unk_zeta_04; // TODO seems wrong!

    beta->unk_70 = 0;
    beta->unk_6C = 1;
    beta->unk_4E = 1;
    beta->unk_40 = 0;
    beta->unk_44 = 1;
    beta->unk_2C = 0;
    beta->unk_30 = 1;
    beta->unk_28 = 0;
    if (beta->instrument != NULL) {
        beta->unk_34 = zeta->unk_tau_14->unk_00;
        if (zeta->unk_tau_14->unk_24 == 0) {
            if (zeta->unk_tau_14->unk_10 != 0){
                beta->unk_14 = zeta->unk_tau_14->unk_14;
            }
        } else if (zeta->unk_tau_14->unk_24 == 1) {
            if (zeta->unk_tau_14->unk_10 != 0){
                beta->unk_14 = zeta->unk_tau_14->unk_14;
            }
        }
    }
}

void func_80056F78(u8 arg0) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[arg0];

    beta->unk_70 = 1;
}

#ifdef NONMATCHING
void func_80056FA4(u8 index, u8 arg1, Instrument* instrument, f32 arg3, s16 arg4, u8 arg5, u8 arg6, s32 arg7) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[index];
    AlUnkZeta* zeta = &beta->unk_zeta_04;
    AlUnkEta* pi = &beta->unk_48;
    AlUnkSigma* sigma = &beta->unk_38;
    
    beta->unk_78 = arg1;
    beta->instrument = instrument;
    
    beta->unk_34 = zeta->unk_tau_14->unk_00;
    beta->unk_28 = 0;
    
    switch (zeta->unk_tau_14->unk_24) {
        case 0:
            zeta->unk_tau_14->unk_04 = (zeta->unk_tau_14->unk_04 / 9) * 9;
            beta->unk_1C = zeta->unk_tau_14->unk_1C;
            if (zeta->unk_tau_14->unk_10 == 0) {
                beta->unk_14 = NULL;
                beta->unk_10 = 0;
                beta->unk_0C = 0;
            } else {
                beta->unk_0C = zeta->unk_tau_14->unk_0C;
                beta->unk_10 = zeta->unk_tau_14->unk_10;
                beta->unk_14 = zeta->unk_tau_14->unk_14;
                alCopy(zeta->unk_tau_14->unk_zeta_08, beta->unk_zeta_08, sizeof(AlUnkZeta));
            }
            break;
        case 1:
            if (zeta->unk_tau_14->unk_10 != 0) {
                beta->unk_0C = zeta->unk_tau_14->unk_0C;
                beta->unk_10 = zeta->unk_tau_14->unk_10;
                beta->unk_14 = zeta->unk_tau_14->unk_14;
            } else {
                beta->unk_14 = NULL;
                beta->unk_10 = 0;
                beta->unk_0C = 0;
            }
            break;
    }
    
    pi->unk_28 = 1;
    pi->unk_24 = 1;
    pi->unk_1C = 0;
    pi->unk_20 = arg7;
    pi->unk_04 = arg5;
    pi->unk_06 = SQ(arg4) >> 0xF;
    pi->unk_0C = (AlCosineBlend[arg6]);
    pi->unk_0E = (AlCosineBlend[AL_COS_MAX_IDX - arg6]);
    if (pi->unk_20 != 0) {
        pi->unk_08 = 1;
        pi->unk_0A = 1;
    } else {
        if (D_80078181 == 0) {
            pi->unk_08 = (pi->unk_06 * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
            pi->unk_0A = (pi->unk_06 * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            pi->unk_08 = (pi->unk_06 * AlCosineBlend[pi->unk_04]) >> 0xF;
            pi->unk_0A = (pi->unk_06 * AlCosineBlend[AL_COS_MAX_IDX - pi->unk_04]) >> 0xF;
        }
    }
    sigma->unk_04 = arg3;
}
#else
INCLUDE_ASM(void, "audio/31650", func_80056FA4, u8 arg0, u8 arg1, s32 arg2, f32 arg3, s16 arg4, u8 arg5, u8 arg6, s32 arg7);
#endif

void func_80057224(u8 index, Instrument* instrument) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[index];
    AlUnkZeta* zeta = &beta->unk_zeta_04;
    
    beta->instrument = instrument;
    beta->unk_34 = zeta->unk_tau_14->unk_00;
    beta->unk_28 = 0;
    
    switch (zeta->unk_tau_14->unk_24) {
        case 0:
            zeta->unk_tau_14->unk_04 = (zeta->unk_tau_14->unk_04 / 9) * 9;
            beta->unk_1C = zeta->unk_tau_14->unk_1C;
            if (zeta->unk_tau_14->unk_10 == 0) {
                beta->unk_14 = NULL;
                beta->unk_10 = 0;
                beta->unk_0C = 0;
            } else {
                beta->unk_0C = zeta->unk_tau_14->unk_0C;
                beta->unk_10 = zeta->unk_tau_14->unk_10;
                beta->unk_14 = zeta->unk_tau_14->unk_14;
                alCopy(zeta->unk_tau_14->unk_zeta_08, beta->unk_zeta_08, sizeof(AlUnkZeta));
            }
            break;
        case 1:
            if (zeta->unk_tau_14->unk_10 != 0) {
                beta->unk_0C = zeta->unk_tau_14->unk_0C;
                beta->unk_10 = zeta->unk_tau_14->unk_10;
                beta->unk_14 = zeta->unk_tau_14->unk_14;
            } else {
                beta->unk_14 = NULL;
                beta->unk_10 = 0;
                beta->unk_0C = 0;
            }
            break;
    }
}


void func_80057344(u8 arg0, f32 arg1) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[arg0];

    beta->unk_3C = arg1;
}

void func_8005736C(u8 arg0, s16 arg1, s32 arg2, u8 arg3, u8 arg4) {
    AlUnkBeta* beta = &D_80078E54->al_unk_beta[arg0];
    AlUnkEta* eta = &beta->unk_eta_48;
    
    if (beta->unk_64 >= beta->unk_68) {
        beta->unk_64 = beta->unk_68;
        if (D_80078181 == 0) {
            beta->unk_50 = (beta->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
            beta->unk_52 = (beta->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            beta->unk_50 = (beta->unk_4E * AlCosineBlend[beta->unk_4C]) >> 0xF;
            beta->unk_52 = (beta->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - beta->unk_4C]) >> 0xF;
        }
    } else {
        beta->unk_50 = func_80058004(beta->unk_50, beta->unk_64, beta->unk_5A, beta->unk_58);
        beta->unk_52 = func_80058004(beta->unk_52, beta->unk_64, beta->unk_60, beta->unk_5E);
    }
    if (eta->unk_08 == 0) {
        eta->unk_08 = 1;
    }
    if (eta->unk_0A == 0) {
        eta->unk_0A = 1;
    }
    
    eta->unk_1C = 0;
    eta->unk_20 = arg2;
    eta->unk_04 = arg3;
    eta->unk_06 = SQ(arg1) >> 0xF;
    eta->unk_0C = AlCosineBlend[arg4];
    eta->unk_0E = AlCosineBlend[AL_COS_MAX_IDX - arg4];
    eta->unk_24 = 1;
}

void func_80057548(u8 arg0, u8 arg1, u8 arg2) {
    AlUnkBeta* temp_s0 = &D_80078E54->al_unk_beta[arg0];
    AlUnkEta* temp_s1 = &temp_s0->unk_eta_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_04 = arg1;
    temp_s1->unk_0C = AlCosineBlend[arg2];
    temp_s1->unk_0E = AlCosineBlend[AL_COS_MAX_IDX - arg2];
    temp_s1->unk_24 = 1;
}

void func_800576EC(u8 arg0, s16 arg1, s32 arg2) {
    AlUnkBeta* temp_s0 = &D_80078E54->al_unk_beta[arg0];
    AlUnkEta* temp_s1 = &temp_s0->unk_eta_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
        
    }

    temp_s1->unk_06 = SQ(arg1) >> 0xF;
    temp_s1->unk_1C = 0;
    temp_s1->unk_20 = arg2;
    temp_s1->unk_24 = 1;
}

void func_80057874(u8 arg0, u8 arg1) {
    AlUnkBeta* temp_s0 = &D_80078E54->al_unk_beta[arg0];
    AlUnkEta* temp_s1 = &temp_s0->unk_eta_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_04 = arg1;
    temp_s1->unk_24 = 1;
}

void func_800579D8(u8 arg0, u8 arg1) {
    AlUnkBeta* temp_s0 = &D_80078E54->al_unk_beta[arg0];
    AlUnkEta* temp_s1 = &temp_s0->unk_eta_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = ((temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF);
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MID_IDX]) >> 0xF;
        } else {
            temp_s0->unk_50 = ((temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF);
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_0C = AlCosineBlend[arg1];
    temp_s1->unk_0E = AlCosineBlend[AL_COS_MAX_IDX - arg1];
    temp_s1->unk_24 = 1;
}

s32 func_80057B64(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return al7C->unk_70;
}

s32 func_80057B8C(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return al7C->unk_78;
}

f32 func_80057BB4(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return al7C->unk_3C;
}

u8 func_80057BDC(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return (u8)al7C->unk_4C;
}

s16 func_80057C04(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return al7C->unk_54;
}

s16 func_80057C2C(u8 arg0) {
    AlUnkBeta* al7C = &D_80078E54->al_unk_beta[arg0];

    return al7C->unk_56;
}

s32 func_80057C54(s32 arg0) {
    AlUnkBeta* temp_v1;
    u32 retVal;
    
    temp_v1 = &D_80078E54->al_unk_beta[arg0 & 0xFF];
    if (temp_v1->unk_64 >= temp_v1->unk_68) {
        if (D_80078181 == 0) {
            retVal = (temp_v1->unk_4E * AlCosineBlend[AL_COS_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (temp_v1->unk_4E * AlCosineBlend[temp_v1->unk_4C] * 2) >> 0x10;
        }
    } else {
        retVal = func_80058004(temp_v1->unk_50, temp_v1->unk_64, temp_v1->unk_5A, temp_v1->unk_58);
    }
    return retVal;
}

s32 func_80057D0C(s32 arg0) {
    AlUnkBeta* temp_v1;
    u32 retVal;
    
    temp_v1 = &D_80078E54->al_unk_beta[arg0 & 0xFF];
    if (temp_v1->unk_64 >= temp_v1->unk_68) {
        if (D_80078181 == 0) {
            retVal = (temp_v1->unk_4E * AlCosineBlend[AL_COS_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = ((temp_v1->unk_4E * AlCosineBlend[AL_COS_MAX_IDX - temp_v1->unk_4C]) * 2) >> 0x10;
        }
    } else {
        retVal = func_80058004(temp_v1->unk_50, temp_v1->unk_64, temp_v1->unk_5A, temp_v1->unk_58);
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

s16 func_80058004(s16 arg0, s32 arg1, s16 arg2, u16 arg3) {
    s32 c;
    arg1 = arg1 >> 3;
    if (arg1 == 0) {
        return arg0;
    }
    c = arg3 * arg1;
    c = c >> 0x10;
    return arg0 + (c + arg2 * arg1);
}
