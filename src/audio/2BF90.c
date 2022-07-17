#include "audio.h"

extern s8 BlankMseqData;

void func_80050B90(AmbientSoundManager* manager, s8 arg1, s8 arg2, AuGlobals* globals) {
    AlUnkLambda* lambda;
    s32 i;

    au_memset(manager, sizeof(*manager), 0);

    for (i = 0; i < ARRAY_COUNT(manager->mseqLambda); i++) {
        lambda = &manager->mseqLambda[i];
        lambda->unk_14.u8[0] = i;
        lambda->unk_18 = 1;
        lambda->unk_38 = 0x7F000000;
    }

    manager->globals = globals;
    manager->nextUpdateStep = 1;
    manager->nextUpdateCounter = 2;
    manager->nextUpdateInterval = 2;
    manager->unk_22 = arg1;
    manager->defaultReverbType = arg2;
}

s32 func_80050C30(u32 arg0) {
    if (gAmbientSoundManager->unk_20 <= arg0) {
        return 3;
    } else {
        return 0;
    }
}

void func_80050C54(s32 arg0, s32 arg1) {
    gAmbientSoundManager->unk_21 = arg1;
}

void func_80050C64(s32 arg0, s32 arg1) {
    AmbientSoundManager* A = gAmbientSoundManager;
    AlUnkLambda* lambda = &A->mseqLambda[arg0];

    if (arg1 == 0) {
        lambda->unk_25 = 0;
    } else {
        lambda->unk_25 = 2;
    }
}

s32 func_80050CA0(s32 arg0, s32 arg1) {
    AlUnkLambda* lambda = &gAmbientSoundManager->mseqLambda[arg0];
    MSEQHeader* mseq = gAmbientSoundManager->mseqFiles[arg0];
    s32 retVal = 0;

    if (mseq != NULL) {
        if (lambda->mseqName == 0) {
            func_800510A4(gAmbientSoundManager, mseq, arg0);
            if (arg1 != 0) {
                lambda->time = arg1;
                lambda->unk_2A = 0;
                lambda->volume = 0x7F;
                lambda->unk_26 = 0;
                func_80050D50(lambda);
            }
        } else {
            retVal = 1;
        }
    } else {
        retVal = 2;
    }
    return retVal;
}

void func_80050D50(AlUnkLambda* lambda) {
    u16 time = lambda->time;

    if (lambda->unk_2A == 0xFF) {
        lambda->unk_2A = lambda->unk_38 >> 0x18;
    }

    if (time >= SND_MIN_DURATION && time <= SND_MAX_DURATION) {
        lambda->unk_38 = lambda->unk_2A << 0x18;
        lambda->unk_42 = lambda->volume;
        lambda->unk_lam_40 = (u32)(time * 10) / 115;
        lambda->unk_3C = ((lambda->volume - lambda->unk_2A) << 0x18) / ((s16)lambda->unk_lam_40 & 0xFFFF);
    }

    lambda->time = 0;
    lambda->unk_2A = 0;
    lambda->volume = 0;
}

void func_80050E18(s32 arg0, s32 arg1) {
    AlUnkLambda* temp_v1 = &gAmbientSoundManager->mseqLambda[arg0];

    if ((temp_v1->mseqReadStart != 0) && (temp_v1->mseqReadPos != NULL)) {
        if (arg1 != 0) {
            temp_v1->unk_2A = 0xFF;
            temp_v1->time = arg1;
            temp_v1->volume = 0;
            temp_v1->unk_26 = 2;
            return;
        }
        temp_v1->unk_24 = 3;
    }
}

void func_80050E84(s32 arg0, s32 arg1) {
    AlUnkLambda* temp_v1 = &gAmbientSoundManager->mseqLambda[arg0];

    if ((temp_v1->mseqReadStart != 0) && (temp_v1->mseqReadPos != NULL)) {
        temp_v1->unk_24 = 1;
        if (arg1 != 0) {
            temp_v1->time = arg1;
        } else {
            temp_v1->time = SND_MIN_DURATION;
        }
        temp_v1->unk_2A = 0;
        temp_v1->volume = SND_MAX_VOLUME_8;
        temp_v1->unk_26 = 0;
    }
}

void func_80050EF0(s32 arg0) {
    AlUnkLambda* temp_v1 = &gAmbientSoundManager->mseqLambda[arg0];

    if ((temp_v1->mseqReadStart != 0) && (temp_v1->mseqReadPos != NULL)) {
        if (temp_v1->unk_24 != 0) {
            temp_v1->mseqReadPos = NULL;
            temp_v1->mseqName = 0;
            temp_v1->unk_24 = 0;
            return;
        }
        temp_v1->mseqReadPos = &BlankMseqData;
        temp_v1->unk_18 = 1;
    }
}

void func_80050F64(s32 arg0, s32 arg1) {
    AlUnkLambda* temp_v1 = &gAmbientSoundManager->mseqLambda[arg0];

    if ((temp_v1->mseqReadStart != 0) && (temp_v1->mseqReadPos != 0)) {
        if (arg1 != 0) {
            temp_v1->time = arg1;
        } else {
            temp_v1->time = SND_MIN_DURATION;
        }
        temp_v1->unk_2A = -1;
        temp_v1->volume = 0;
        temp_v1->unk_26 = 1;
    }
}

void au_mseq_set_volume(s32 index, s32 time, s32 volume) {
    AlUnkLambda* lambda = &gAmbientSoundManager->mseqLambda[index];
    if ((lambda->mseqReadStart != 0) && (lambda->mseqReadPos != 0)) {
        if (volume <= 0) {
            volume = 1;
        } else if (volume > SND_MAX_VOLUME_8) {
            volume = SND_MAX_VOLUME_8;
        }
        if (time != 0) {
            lambda->time = time;
        } else {
            lambda->time = SND_MIN_DURATION;
        }
        lambda->unk_2A = -1;
        lambda->volume = volume;
        lambda->unk_26 = 0;
    }
}

s32 func_80051050(s32 arg0) {
    AlUnkLambda* lambda = &gAmbientSoundManager->mseqLambda[arg0];
    s32 var_a0 = 0;

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        var_a0 = 1;
        if (lambda->unk_24 != 0) {
            var_a0 = 2;
        }
    }
    return var_a0;
}

void func_800510A4(AmbientSoundManager* manager, MSEQHeader* mseqFile, s32 index) {
    AlUnkLambda* lambda;
    AlUnkXi* xi;
    AuFilePos readPos;
    s32 i;

    lambda = &manager->mseqLambda[index];
    au_memset(lambda, sizeof(*lambda), 0);

    lambda->mseqFile = mseqFile;
    readPos = (AuFilePos)((s32)mseqFile + mseqFile->dataStart);
    lambda->unk_14.u8[0] = index;
    lambda->mseqReadPos = readPos;
    lambda->unk_10 = readPos;
    lambda->unk_0C = readPos;
    lambda->mseqReadStart = readPos;

    lambda->unk_18 = 1;
    lambda->unk_38 = 0x7F000000;
    lambda->unk_42 = 0x7F;

    lambda->mseqName = lambda->mseqFile->name;
    lambda->first_iota = lambda->mseqFile->first_iota;
    lambda->last_iota = lambda->first_iota + 16;
    if (lambda->last_iota > 24) {
        lambda->last_iota = 24;
    }
    for (i = 0; i < 10; i++) {
        xi = &lambda->unk_44[i];
        xi->instrument = manager->globals->defaultInstrument;
        xi->unk_18.full = 0x7FFFFFFF;
        xi->pan = 0x40;
    }
    lambda->unk_43 = 1;
}

void snd_ambient_manager_update(AmbientSoundManager* manager) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(manager->unk_7B4); i++) {
        AlUnkIota* temp = &manager->unk_7B4[i];

        if ((temp->unk_00.u8[3] == 1) && (manager->globals->voices[i].unk_45 != manager->unk_22)) {
            temp->unk_00.s32 = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(manager->mseqLambda); j++) {
        AlUnkLambda* lambda = &manager->mseqLambda[j];
        s32 var;

        if (lambda->mseqReadPos != NULL) {
            if (manager->unk_21) {
                func_80051334(manager, lambda);
            }

            var = lambda->unk_24;
            if (var != 0) {
                if (var == 3) {
                    lambda->unk_24 = 2;
                    func_800522A8(manager, lambda);
                    func_800521E8(manager, lambda);
                } else if (lambda->unk_24 == 1) {
                    lambda->unk_24 = 0;
                    if (lambda->time != 0) {
                        func_80050D50(lambda);
                    }
                    func_8005232C(manager, lambda);
                }
            } else {
                if (lambda->time != 0) {
                    func_80050D50(lambda);
                }
                if (lambda->unk_25 == 2) {
                    func_800521E8(manager, lambda);
                    lambda->unk_25 = 1;
                }
                func_80051434(manager, lambda);
            }
        }
    }

    manager->unk_21 = FALSE;
}

void func_80051334(AmbientSoundManager* manager, AlUnkLambda* lambda) {
    MSEQHeader* header;
    AlUnkMSEQData* var_a0;
    AlUnkXi* xi;
    s32 offset;
    s32 count;
    s32 lim;

    header = lambda->mseqFile;
    count = header->unkCount;
    if (count != 0 && header->unkOffset != 0) {
        var_a0 = (AlUnkMSEQData*)((s32)header + header->unkOffset);
        while (count--) {
            xi = &lambda->unk_44[var_a0->unk_00];
            if (var_a0->unk_01 == 0) {
                xi->unk_14 = var_a0->unk_02;
                xi->unk_10 = (var_a0->unk_04 << 0x10) / var_a0->unk_02;
                xi->unk_16 = var_a0->unk_06;
            } else if (var_a0->unk_01 == 1) {
                xi->unk_20 = var_a0->unk_02;
                xi->unk_1C = (var_a0->unk_04 << 0x10) / var_a0->unk_02;
                xi->unk_22 = var_a0->unk_06;
            }
            var_a0++;
        }
    }
}

INCLUDE_ASM(void, "audio/2BF90", func_80051434, AmbientSoundManager* arg0, AlUnkLambda* arg1);

// could return u8?
s32 au_mseq_read_next(AlUnkLambda* state) {
    u8 value = *state->mseqReadPos++;
    return value;
}

void func_800521E8(AmbientSoundManager* manager, AlUnkLambda* state) {
    AlUnkVoice* voice;
    Q32* temp_s1;
    s32 i;

    for (i = state->first_iota; i < state->last_iota; i++) {
        temp_s1 = &manager->unk_7B4[i - state->first_iota].unk_00;
        if (*temp_s1->u8 == state->unk_14.u8[0]) {
            voice = &manager->globals->voices[i];
            if (voice->unk_45 == manager->unk_22) {
                func_800538C4(voice, i);
            }
            temp_s1->s32 = 0;
        }
    }
}

void func_800522A8(AmbientSoundManager* arg0, AlUnkLambda* lambda) {
    AlUnkOmega* omega = lambda->unk_1D4;
    u32 k = 0;
    s32 i;
    
    for (i = lambda->first_iota; i < lambda->last_iota; i++) {
        AlUnkIota* iota = &arg0->unk_7B4[i - lambda->first_iota];

        if (iota->unk_07 == 0) {
            continue;
        }

        omega->unk_00 = iota->unk_00.u8[1];
        omega->unk_01 = iota->unk_00.u8[2];
        omega->unk_02 = iota->unk_06;

        omega++;
        k++;
        if (k >= 4) {
            break;
        }
    }
}

void func_8005232C(AmbientSoundManager* manager, AlUnkLambda* lambda) {
    AuGlobals* globals;
    AlUnkVoice* voice;
    AlUnkOmega* omega;
    AlUnkIota* iota;
    AlUnkXi* xi;
    u32 i, j;
        
    globals = manager->globals;
    if (lambda->unk_25 == 0) {
        for (i = 0; i < 4; i++) {
            omega = &lambda->unk_1D4[i];
            if (omega->unk_01 != 0) {
                xi = &lambda->unk_44[omega->unk_00];

                for (j = lambda->first_iota; j < lambda->last_iota; j++) {
                    voice = &globals->voices[j];
                    if (voice->unk_45 == 0) {
                        break;
                    }
                }

                if (j >= lambda->last_iota) {
                    for (j = lambda->first_iota; j < lambda->last_iota; j++) {
                        voice = &globals->voices[j];
                        if (voice->unk_45 < manager->unk_22) {
                            func_800538C4(voice, j & 0xFF);
                            break;
                        }
                    }
                }
                
                if (j < lambda->last_iota) {
                    iota = &manager->unk_7B4[j - lambda->first_iota];
                    iota->unk_00.s32 = lambda->unk_14.s32 + (omega->unk_00 << 0x10) + (omega->unk_01 << 8);
                    iota->unk_04 = ((omega->unk_01 & 0x7F) * 100) - xi->instrument->keyBase;
                    iota->unk_06 = omega->unk_02 & 0x7F;
                    voice->adjustedVolume = ((lambda->unk_38 >> 0x18) * xi->unk_18.half * iota->unk_06) >> 0xE;
                    voice->pitchRatio = au_compute_pitch_ratio(iota->unk_04 + xi->unk_0C) * xi->instrument->pitchRatio;
                    voice->pan = xi->pan;
                    voice->reverbAmt = xi->reverb;
                    voice->instrument = xi->instrument;
                    voice->reverbType = manager->defaultReverbType;
                    voice->unk_14.unk_00 = xi->unk_04.unk_00;
                    voice->unk_14.unk_04 = xi->unk_04.unk_04;
                    voice->unk_flags_43 = 2;
                    voice->unk_45 = manager->unk_22;
                    voice->unk_44 = voice->unk_45;
                }
            }
            omega->unk_00 = 0;
            omega->unk_01 = 0;
            omega->unk_02 = 0;
        }
    }
}
