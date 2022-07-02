#include "audio.h"

extern s32 D_80078520;

void func_800538C4(AlUnkVoice*, u8);

void func_80050B90(AmbientSoundManager* arg0, s8 arg1, s8 arg2, SndGlobals* arg3) {
    AlUnkLambda* temp_v0;
    s32 i;

    snd_memset(arg0, sizeof(*arg0), 0);

    for (i = 0; i < ARRAY_COUNT(arg0->unk_24); i++) {
        temp_v0 = &arg0->unk_24[i];
        temp_v0->unk_14 = i;
        temp_v0->unk_18 = 1;
        temp_v0->unk_38 = 0x7F000000;
    }

    arg0->unk_00 = arg3;
    arg0->nextUpdateStep = 1;
    arg0->nextUpdateCounter = 2;
    arg0->nextUpdateInterval = 2;
    arg0->unk_22 = arg1;
    arg0->unk_23 = arg2;
}


s32 func_80050C30(u32 arg0) {
    if (D_8009A628->unk_20 <= arg0) {
        return 3;
    } else {
        return 0;
    }
}

void func_80050C54(s32 arg0, s8 arg1) {
    D_8009A628->unk_21 = arg1;
}

void func_80050C64(s32 arg0, s32 arg1) {
    AmbientSoundManager* A = D_8009A628;
    AlUnkLambda* B = &A->unk_24[arg0];

    if (arg1 == 0) {
        B->unk_25 = 0;
    } else {
        B->unk_25 = 2;
    }
}

s32 func_80050CA0(s32 arg0, s32 arg1) {
    AmbientSoundManager* temp_a0 = D_8009A628;
    AlUnkLambda* temp_s0 = &temp_a0->unk_24[arg0];
    s32* temp_a1 = temp_a0->unk_10[arg0];
    s32 retVal = 0;

    if (temp_a1 != NULL) {
        if (temp_s0->unk_20 == 0) {
            func_800510A4(temp_a0, temp_a1, arg0);
            if (arg1 != 0) {
                temp_s0->time = arg1;
                temp_s0->unk_2A = 0;
                temp_s0->volume = 0x7F;
                temp_s0->unk_26 = 0;
                func_80050D50(temp_s0);
            }
        } else {
            retVal = 1;
        }
    } else {
        retVal = 2;
    }
    return retVal;
}

void func_80050D50(AlUnkLambda* arg0) {
    u16 temp_a1 = arg0->time;

    if (arg0->unk_2A == 0xFF) {
        arg0->unk_2A = arg0->unk_38 >> 0x18;
    }

    if (temp_a1 >= SND_MIN_DURATION && temp_a1 <= SND_MAX_DURATION) {
        arg0->unk_38 = arg0->unk_2A << 0x18;
        arg0->unk_42 = arg0->volume;
        arg0->unk_40 = (u32)(temp_a1 * 10) / 115;
        arg0->unk_3C = ((arg0->volume - arg0->unk_2A) << 0x18) / (arg0->unk_40 & 0xFFFF);
    }

    arg0->time = 0;
    arg0->unk_2A = 0;
    arg0->volume = 0;
}

void func_80050E18(s32 arg0, s32 arg1) {
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];

    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
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
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];

    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
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
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];

    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != NULL)) {
        if (temp_v1->unk_24 != 0) {
            temp_v1->unk_08 = NULL;
            temp_v1->unk_20 = 0;
            temp_v1->unk_24 = 0;
            return;
        }
        temp_v1->unk_08 = &D_80078520;
        temp_v1->unk_18 = 1;
    }
}

void func_80050F64(s32 arg0, s32 arg1) {
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];

    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
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

void func_80050FD0(s32 arg0, s32 arg1, s32 arg2) {
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];
    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
        if (arg2 <= 0) {
            arg2 = 1;
        } else if (arg2 > SND_MAX_VOLUME_8) {
            arg2 = SND_MAX_VOLUME_8;
        }
        if (arg1 != 0) {
            temp_v1->time = arg1;
        } else {
            temp_v1->time = SND_MIN_DURATION;
        }
        temp_v1->unk_2A = -1;
        temp_v1->volume = arg2;
        temp_v1->unk_26 = 0;
    }
}

s32 func_80051050(s32 arg0) {
    AlUnkLambda* temp_v1 = &D_8009A628->unk_24[arg0];
    s32 var_a0 = 0;

    if ((temp_v1->unk_04 != 0) && (temp_v1->unk_08 != 0)) {
        var_a0 = 1;
        if (temp_v1->unk_24 != 0) {
            var_a0 = 2;
        }
    }
    return var_a0;
}

void func_800510A4(AmbientSoundManager* arg0, MSEQHeader* mseq, s32 index) {
    AlUnkLambda* lambda;
    AlUnkXi* temp_v1;
    u8* readPos;
    s32 i;

    lambda = &arg0->unk_24[index];
    snd_memset(lambda, sizeof(*lambda), 0);

    lambda->unk_00 = mseq;
    readPos = (u8*)((s32)mseq + mseq->dataStart);
    lambda->unk_14 = index;
    lambda->unk_08 = readPos;
    lambda->unk_10 = readPos;
    lambda->unk_0C = readPos;
    lambda->unk_04 = readPos;

    lambda->unk_18 = 1;
    lambda->unk_38 = 0x7F000000;
    lambda->unk_42 = 0x7F;

    lambda->unk_20 = lambda->unk_00->name;
    lambda->unk_30 = lambda->unk_00->unk_0C;
    lambda->unk_34 = lambda->unk_30 + 16;
    if (lambda->unk_34 > 24) {
        lambda->unk_34 = 24;
    }
    for (i = 0; i < 10; i++) {
        temp_v1 = &lambda->unk_44[i];
        temp_v1->unk_00 = arg0->unk_00->defaultInstrument;
        temp_v1->unk_18 = 0x7FFFFFFF;
        temp_v1->unk_24 = 0x40;

    }
    lambda->unk_43 = 1;
}

void snd_ambient_manager_update(AmbientSoundManager* arg0) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_7B4); i++) {
        AlUnkIota* temp = &arg0->unk_7B4[i];

        if ((temp->unk_00.u8[3] == 1) && (arg0->unk_00->voices[i].unk_45 != arg0->unk_22)) {
            temp->unk_00.s32 = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(arg0->unk_24); j++) {
        AlUnkLambda* temp = &arg0->unk_24[j];
        s32 var;

        if (temp->unk_08 != 0) {
            if (arg0->unk_21 != 0) {
                func_80051334(arg0, temp);
            }

            var = temp->unk_24;
            if (var != 0) {
                if (var == 3) {
                    temp->unk_24 = 2;
                    func_800522A8(arg0, temp);
                    func_800521E8(arg0, temp);
                } else if (temp->unk_24 == 1) {
                    temp->unk_24 = 0;
                    if (temp->time != 0) {
                        func_80050D50(temp);
                    }
                    func_8005232C(arg0, temp);
                }
            } else {
                if (temp->time != 0) {
                    func_80050D50(temp);
                }
                if (temp->unk_25 == 2) {
                    func_800521E8(arg0, temp);
                    temp->unk_25 = 1;
                }
                func_80051434(arg0, temp);
            }
        }
    }

    arg0->unk_21 = 0;
}

void func_80051334(AmbientSoundManager* manager, AlUnkLambda* lambda) {
    MSEQHeader* header;
    AlUnkMSEQData* var_a0;
    AlUnkXi* xi;
    s32 offset;
    s32 count;
    s32 lim;

    header = lambda->unk_00;
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

s32 func_800521D0(AlUnkLambda* arg0) {
    u8 temp_v0 = *arg0->unk_08++;
    return temp_v0;
}

void func_800521E8(AmbientSoundManager* arg0, AlUnkLambda* arg1) {
    AlUnkVoice* voice;
    Q32* temp_s1;
    s32 i;

    for (i = arg1->unk_30; i < arg1->unk_34; i++) {
        temp_s1 = &arg0->unk_7B4[i - arg1->unk_30].unk_00;
        if (*temp_s1->u8 == arg1->unk_14) {
            voice = &arg0->unk_00->voices[i];
            if (voice->unk_45 == arg0->unk_22) {
                func_800538C4(voice, i);
            }
            temp_s1->s32 = 0;
        }
    }
}

void func_800522A8(AmbientSoundManager* arg0, AlUnkLambda* arg1) {
    s32 j;
    u32 i;
    s8* var_a2;
    AlUnkIota* iota;

    j = arg1->unk_30;
    var_a2 = arg1->unk_1D4;
    for (i = 0; j < arg1->unk_34; j++) {
        iota = &arg0->unk_7B4[j - arg1->unk_30];
        if (iota->unk_07 == 0) {
            continue;
        }
        var_a2[0] = iota->unk_00.u8[1];
        var_a2[1] = iota->unk_00.u8[2];
        var_a2[2] = iota->unk_06;
        var_a2 += 4;
        i += 1;
        if (i >= 4) {
            break;
        }
    }
}

INCLUDE_ASM(void, "audio/2BF90", func_8005232C, AmbientSoundManager* arg0, AlUnkLambda* arg1);
