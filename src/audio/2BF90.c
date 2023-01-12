#include "audio.h"

extern s8 BlankMseqData;

enum LambdaState24 {
    LAMBDA_24_0         = 0,
    LAMBDA_24_1         = 1,
    LAMBDA_24_2         = 2,
    LAMBDA_24_3         = 3
};

enum MseqPlayState {
    MSEQ_PLAYER_PLAYING     = 0,
    MSEQ_PLAYER_STOPPED     = 1,
    MSEQ_PLAYER_STOPPING    = 2
};

void au_mseq_manager_init(AuAmbienceManager* manager, s8 priority, s8 reverbType, AuGlobals* globals) {
    AuAmbPlayer* lambda;
    s32 i;

    au_memset(manager, sizeof(*manager), 0);

    for (i = 0; i < ARRAY_COUNT(manager->mseqPlayers); i++) {
        lambda = &manager->mseqPlayers[i];
        lambda->unk_14.u8[0] = i;
        lambda->unk_18 = 1;
        lambda->unk_38 = 0x7F000000;
    }

    manager->globals = globals;
    manager->nextUpdateStep = 1;
    manager->nextUpdateCounter = 2;
    manager->nextUpdateInterval = 2;
    manager->priority = priority;
    manager->defaultReverbType = reverbType;
}

AuResult func_80050C30(u32 arg0) {
    if (gAuAmbienceManager->unk_20 <= arg0) {
        return AU_AMBIENCE_ERROR_3;
    } else {
        return AU_RESULT_OK;
    }
}

void func_80050C54(s32 arg0, s32 arg1) {
    gAuAmbienceManager->unk_21 = arg1;
}

void au_mseq_set_disabled(s32 index, s32 disable) {
    AuAmbienceManager* manager = gAuAmbienceManager;
    AuAmbPlayer* ambPlayer = &manager->mseqPlayers[index];

    if (!disable) {
        ambPlayer->playState = MSEQ_PLAYER_PLAYING;
    } else {
        ambPlayer->playState = MSEQ_PLAYER_STOPPING;
    }
}

AuResult func_80050CA0(s32 index, s32 time) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];
    MSEQHeader* mseq = gAuAmbienceManager->mseqFiles[index];
    AuResult status = AU_RESULT_OK;

    if (mseq != NULL) {
        if (lambda->mseqName == 0) {
            func_800510A4(gAuAmbienceManager, mseq, index);
            if (time != 0) {
                lambda->time = time;
                lambda->unk_2A = 0;
                lambda->volume = 0x7F;
                lambda->unk_26 = 0;
                func_80050D50(lambda);
            }
        } else {
            status = AU_AMBIENCE_ERROR_1;
        }
    } else {
        status = AU_AMBIENCE_ERROR_2;
    }
    return status;
}

void func_80050D50(AuAmbPlayer* lambda) {
    u16 time = lambda->time;

    if (lambda->unk_2A == 0xFF) {
        lambda->unk_2A = lambda->unk_38 >> 0x18;
    }

    if (time >= SND_MIN_DURATION && time <= SND_MAX_DURATION) {
        lambda->unk_38 = lambda->unk_2A << 0x18;
        lambda->unk_42 = lambda->volume;
        lambda->volInterpTime = (u32)(time * 10) / 115;
        lambda->volInterpStep = ((lambda->volume - lambda->unk_2A) << 0x18) / ((s16)lambda->volInterpTime & 0xFFFF);
    }

    lambda->time = 0;
    lambda->unk_2A = 0;
    lambda->volume = 0;
}

void func_80050EF0_fade_out_unk(s32 index, s32 time) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        if (time != 0) {
            lambda->unk_2A = 0xFF;
            lambda->time = time;
            lambda->volume = 0;
            lambda->unk_26 = 2;
            return;
        }
        lambda->unk_24 = LAMBDA_24_3;
    }
}

void func_80050EF0_fade_in_unk(s32 index, s32 time) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        lambda->unk_24 = LAMBDA_24_1;
        if (time != 0) {
            lambda->time = time;
        } else {
            lambda->time = SND_MIN_DURATION;
        }
        lambda->unk_2A = 0;
        lambda->volume = SND_MAX_VOLUME_8;
        lambda->unk_26 = 0;
    }
}

void func_80050EF0_fade_out_quick(s32 index) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        if (lambda->unk_24 != LAMBDA_24_0) {
            lambda->mseqReadPos = NULL;
            lambda->mseqName = 0;
            lambda->unk_24 = LAMBDA_24_0;
            return;
        }
        lambda->mseqReadPos = &BlankMseqData;
        lambda->unk_18 = 1;
    }
}

void func_80050EF0_fade_out_slow(s32 index, s32 time) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        if (time != 0) {
            lambda->time = time;
        } else {
            lambda->time = SND_MIN_DURATION;
        }
        lambda->unk_2A = -1;
        lambda->volume = 0;
        lambda->unk_26 = 1;
    }
}

void au_mseq_set_volume(s32 index, s32 time, s32 volume) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[index];
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

AuResult func_80051050(s32 arg0) {
    AuAmbPlayer* lambda = &gAuAmbienceManager->mseqPlayers[arg0];
    AuResult status = AU_RESULT_OK;

    if ((lambda->mseqReadStart != NULL) && (lambda->mseqReadPos != NULL)) {
        status = AU_AMBIENCE_ERROR_1;
        if (lambda->unk_24 != LAMBDA_24_0) {
            status = AU_AMBIENCE_ERROR_2;
        }
    }
    return status;
}

void func_800510A4(AuAmbienceManager* manager, MSEQHeader* mseqFile, s32 index) {
    AuAmbPlayer* lambda;
    AlUnkXi* xi;
    AuFilePos readPos;
    s32 i;

    lambda = &manager->mseqPlayers[index];
    au_memset(lambda, sizeof(*lambda), 0);

    lambda->mseqFile = mseqFile;
    readPos = AU_FILE_RELATIVE(mseqFile->dataStart, mseqFile);
    lambda->unk_14.u8[0] = index;
    lambda->mseqReadPos = readPos;
    lambda->unk_10 = readPos;
    lambda->unk_0C = readPos;
    lambda->mseqReadStart = readPos;

    lambda->unk_18 = 1;
    lambda->unk_38 = 0x7F000000;
    lambda->unk_42 = 0x7F;

    lambda->mseqName = lambda->mseqFile->name;
    lambda->firstVoiceIdx = lambda->mseqFile->first_iota;
    lambda->lastVoiceIdx = lambda->firstVoiceIdx + 16;
    if (lambda->lastVoiceIdx > 24) {
        lambda->lastVoiceIdx = 24;
    }
    for (i = 0; i < 10; i++) {
        xi = &lambda->unk_44[i];
        xi->instrument = manager->globals->defaultInstrument;
        xi->unk_18.full = 0x7FFFFFFF;
        xi->pan = 0x40;
    }
    lambda->unk_43 = 1;
}

void snd_ambient_manager_update(AuAmbienceManager* manager) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(manager->mseqVoiceStates); i++) {
        AlUnkIota* temp = &manager->mseqVoiceStates[i];

        if ((temp->unk_00.u8[3] == 1) && (manager->globals->voices[i].priority != manager->priority)) {
            temp->unk_00.s32 = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(manager->mseqPlayers); j++) {
        AuAmbPlayer* lambda = &manager->mseqPlayers[j];
        s32 var;

        if (lambda->mseqReadPos != NULL) {
            if (manager->unk_21) {
                // not usually taken
                func_80051334(manager, lambda);
            }

            var = lambda->unk_24;
            if (var != LAMBDA_24_0) {
                if (var == LAMBDA_24_3) {
                    lambda->unk_24 = LAMBDA_24_2;
                    func_800522A8(manager, lambda);
                    au_mseq_player_stop(manager, lambda);
                } else if (lambda->unk_24 == LAMBDA_24_1) {
                    lambda->unk_24 = LAMBDA_24_0;
                    if (lambda->time != 0) {
                        func_80050D50(lambda);
                    }
                    func_8005232C(manager, lambda);
                }
            } else {
                if (lambda->time != 0) {
                    func_80050D50(lambda);
                }
                if (lambda->playState == MSEQ_PLAYER_STOPPING) {
                    au_mseq_player_stop(manager, lambda);
                    lambda->playState = MSEQ_PLAYER_STOPPED;
                }
                func_80051434(manager, lambda);
            }
        }
    }

    manager->unk_21 = FALSE;
}

void func_80051334(AuAmbienceManager* manager, AuAmbPlayer* lambda) {
    MSEQHeader* mseqFile;
    AlUnkMSEQData* var_a0;
    AlUnkXi* xi;
    s32 offset;
    s32 count;
    s32 lim;

    mseqFile = lambda->mseqFile;
    count = mseqFile->unkCount;
    if (count != 0 && mseqFile->unkOffset != 0) {
        var_a0 = AU_FILE_RELATIVE(mseqFile->unkOffset, mseqFile);
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

INCLUDE_ASM(void, "audio/2BF90", func_80051434, AuAmbienceManager* arg0, AuAmbPlayer* arg1);

// could return u8?
s32 au_mseq_read_next(AuAmbPlayer* state) {
    u8 value = *state->mseqReadPos++;
    return value;
}

void au_mseq_player_stop(AuAmbienceManager* manager, AuAmbPlayer* lambda) {
    AlUnkVoice* voice;
    Q32* temp_s1;
    s32 i;

    for (i = lambda->firstVoiceIdx; i < lambda->lastVoiceIdx; i++) {
        temp_s1 = &manager->mseqVoiceStates[i - lambda->firstVoiceIdx].unk_00;
        if (*temp_s1->u8 == lambda->unk_14.u8[0]) {
            voice = &manager->globals->voices[i];
            if (voice->priority == manager->priority) {
                au_reset_voice(voice, i);
            }
            temp_s1->s32 = 0;
        }
    }
}

void func_800522A8(AuAmbienceManager* arg0, AuAmbPlayer* lambda) {
    AlUnkOmega* omega = lambda->unk_1D4;
    u32 copied = 0;
    s32 i;

    for (i = lambda->firstVoiceIdx; i < lambda->lastVoiceIdx; i++) {
        AlUnkIota* iota = &arg0->mseqVoiceStates[i - lambda->firstVoiceIdx];

        if (iota->unk_07 == 0) {
            continue;
        }

        omega->unk_00 = iota->unk_00.u8[1];
        omega->unk_01 = iota->unk_00.u8[2];
        omega->unk_02 = iota->volume;

        omega++;
        copied++;
        if (copied >= 4) {
            break;
        }
    }
}

void func_8005232C(AuAmbienceManager* manager, AuAmbPlayer* lambda) {
    AuGlobals* globals;
    AlUnkVoice* voice;
    AlUnkOmega* omega;
    AlUnkIota* iota;
    AlUnkXi* xi;
    u32 i, j;

    globals = manager->globals;
    if (lambda->playState == MSEQ_PLAYER_PLAYING) {
        for (i = 0; i < ARRAY_COUNT(lambda->unk_1D4); i++) {
            omega = &lambda->unk_1D4[i];
            if (omega->unk_01 != 0) {
                xi = &lambda->unk_44[omega->unk_00];

                // find first free voice
                for (j = lambda->firstVoiceIdx; j < lambda->lastVoiceIdx; j++) {
                    voice = &globals->voices[j];
                    if (voice->priority == AU_PRIORITY_FREE) {
                        break;
                    }
                }

                // try stealing a voice with lower priority
                if (j >= lambda->lastVoiceIdx) {
                    for (j = lambda->firstVoiceIdx; j < lambda->lastVoiceIdx; j++) {
                        voice = &globals->voices[j];
                        if (voice->priority < manager->priority) {
                            au_reset_voice(voice, j);
                            break;
                        }
                    }
                }

                if (j < lambda->lastVoiceIdx) {
                    iota = &manager->mseqVoiceStates[j - lambda->firstVoiceIdx];
                    iota->unk_00.s32 = lambda->unk_14.s32 + (omega->unk_00 << 0x10) + (omega->unk_01 << 8);
                    iota->pitch = ((omega->unk_01 & 0x7F) * 100) - xi->instrument->keyBase;
                    iota->volume = omega->unk_02 & 0x7F;
                    voice->adjustedVolume = ((lambda->unk_38 >> 0x18) * xi->unk_18.half * iota->volume) >> 0xE;
                    voice->pitchRatio = au_compute_pitch_ratio(iota->pitch + xi->pitch) * xi->instrument->pitchRatio;
                    voice->pan = xi->pan;
                    voice->reverbAmt = xi->reverb;
                    voice->instrument = xi->instrument;
                    voice->reverbType = manager->defaultReverbType;
                    voice->unk_14.unk_00 = xi->unk_04.unk_00;
                    voice->unk_14.unk_04 = xi->unk_04.unk_04;
                    voice->unk_flags_43 = AU_VOICE_SYNC_FLAG_ALL;
                    voice->priority = manager->priority;
                    voice->priorityCopy = voice->priority;
                }
            }
            omega->unk_00 = 0;
            omega->unk_01 = 0;
            omega->unk_02 = 0;
        }
    }
}
