#include "audio.h"

void func_80052E30(u8 index) {
    UnkAl48* temp = &D_8009A5C0->unk_1320[index];

    temp->unk_1C = 0;
    temp->unk_45 = 0;
}

void snd_load_audio_data(s32 frequency) {
    UnkAl19E0** temp_s4 = &D_8009A5C0;
    UnkAl19E0* temp4;
    s32* temp_v0_2;
    ALHeap* alHeap;
    u32 i;
    s32 subroutine_arg7[2];
    u8 temp6[4];
    BGMPlayer** temp1 = &D_8009A664;
    BGMPlayer** temp1_1;
    SoundManager** temp2 = &D_8009A640;
    SoundManager** temp2_1;
    BGMPlayer** temp3;
    UnkAl48* temp5;

    alHeap = D_80078E54->unk_18;
    *temp_s4 = alHeapAlloc(alHeap, 1, 0x19E0);

    (*temp1) = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    D_8009A5FC = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    D_8009A5CC = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    (*temp2) = alHeapAlloc(alHeap, 1, 0x6CC);
    D_8009A628 = alHeapAlloc(alHeap, 1, 0x834);
    (*temp1)->soundManager = (*temp2);
    D_8009A628->unk_00 = *(temp_s4);


    temp4 = *temp_s4;
    temp_v0_2 = alHeapAlloc(alHeap, 1, 0x8000);
    temp4->currentTrackData[0] = &temp_v0_2[0];
    temp4->currentTrackData[1] = &temp_v0_2[0x1400];
    temp4->currentTrackData[2] = &temp_v0_2[0x1C00];
    temp4->currentTrackData[3] = &temp_v0_2[0x1400];

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_0 = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    }

    temp4->dataSEF = alHeapAlloc(alHeap, 1, 0x5200);
    temp4->defaultInstrument = alHeapAlloc(alHeap, 1, 0x30);
    temp4->dataPER = alHeapAlloc(alHeap, 1, 0x360);
    temp4->dataPRG = alHeapAlloc(alHeap, 1, 0x200);
    temp4->unk_94 = alHeapAlloc(alHeap, 1, 0x40);
    temp4->actualFrequency = frequency;
    snd_reset_instrument(temp4->defaultInstrument);
    func_80053370(&temp4->unk_08);
    func_800533A8(&temp4->defaultPRGEntry);
    func_8005610C();

    temp4->unk_A4[0] = NULL;
    temp4->unk_A4[1] = NULL;

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_4 = 0;
        temp4->unk_6C[i].unk_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        temp4->unk_40[i].unk_00 = 0;
        temp4->unk_40[i].unk_01 = 0;
    }

    for (i = 0; i < 24; i++) {
        func_80056EC0(i, 0);
        func_80057224(i, temp4->defaultInstrument);
        temp5 = &temp4->unk_1320[i];
        temp5->unk_00 = 0;
        temp5->unk_04 = 0;
        temp5->unk_0C = -1;
        temp5->unk_0E = 0xFF;
        temp5->unk_0F = 0xFF;
        temp5->unk_10 = 0;
        temp5->unk_42 = 0;
        temp5->unk_43 = 0;
        temp5->unk_44 = 0;
        temp5->unk_45 = 0;
    }

    snd_load_INIT(temp4, 0xF00000, alHeap);

    for (i = 0; i < 3; i++) {
        temp4->banks[i] = alHeapAlloc(alHeap, 1, 0x840);
    }

    temp2_1 = &D_8009A640;
    temp3 = &D_8009A5FC;
    temp1_1 = &D_8009A664;

    func_8004E158(*temp1_1, 1, 0, temp4);
    temp6[0] = 0;
    temp6[1] = 3;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(*temp1_1, &temp6);
    func_8004E158(*temp3, 2, 2, temp4);
    temp6[0] = 2;
    temp6[1] = 0xff;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(*temp3, &temp6);
    func_8004B440(*temp2_1, 4, 1, temp4, 0x10);
    func_80050B90(D_8009A628, 6, 1, temp4);
    func_80052614(temp4);
    snd_load_BK_headers(temp4, alHeap);
    if (snd_fetch_SBN_file(temp4->mseqFileList->unk_0, 0x20, subroutine_arg7) == 0) {
        snd_read_rom(subroutine_arg7[0], temp4->dataSEF, subroutine_arg7[1] & 0xFFFFFF);
    }
    snd_load_sfx_groups_from_SEF(*temp2_1);
    if (snd_fetch_SBN_file(temp4->mseqFileList->unk_2, 0x40, subroutine_arg7) == 0) {
        snd_load_PER(temp4, subroutine_arg7[0]);
    }
    if (snd_fetch_SBN_file(temp4->mseqFileList->unk_4, 0x40, subroutine_arg7) == 0) {
        snd_load_PRG(temp4, subroutine_arg7[0]);
    }

    temp4->instrumentGroups[0] = temp4->instrumentGroup1;
    temp4->instrumentGroups[1] = temp4->instrumentGroup2;
    temp4->instrumentGroups[2] = temp4->instrumentGroupX;
    temp4->instrumentGroups[3] = temp4->instrumentGroup3;
    temp4->instrumentGroups[4] = temp4->instrumentGroup4;
    temp4->instrumentGroups[5] = temp4->instrumentGroup5;
    temp4->instrumentGroups[6] = temp4->instrumentGroup6;
    temp4->instrumentGroups[7] = temp4->instrumentGroup1;
    temp4->unk_53 = 0;
    temp4->unk_52 = 0;
    temp4->unk_51 = 0;
    temp4->unk_50 = 0;

    func_80057ED0(0);
    func_80055050(alHeap);
}

void snd_reset_instrument(Instrument* instrument) {
    instrument->wavOffset = &D_800781D0;
    instrument->wavLength = 190;
    instrument->predictorOffset = &D_80078190;
    instrument->unk_1C = 64;
    instrument->unk_1E = 4800;
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

void func_80053370(UnkAlC* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = 4800;
    arg0->unk_04 = ~0x80;
    arg0->unk_05 = 64;
    arg0->unk_06 = 0;
    arg0->unk_07 = 0;
    arg0->unk_08 = 0;
    arg0->unk_09 = 0;
    arg0->unk_0A = 0;
}

void func_800533A8(InstrumentCFG* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = ~0x80;
    arg0->unk_03 = 64;
    arg0->unk_04 = 0;
    arg0->unk_05 = 0;
    arg0->unk_06 = 0;
}


void snd_update_sequence_players(void) {
    UnkAl19E0* temp_s2 = D_8009A5C0;
    SoundManager* manager = D_8009A640;
    UnkAl834* temp_s0 = D_8009A628;
    BGMPlayer* bgmPlayer1;
    BGMPlayer* bgmPlayer2;
    s32* t1;

    func_80053654(temp_s2);

    temp_s0->unk_0C -= temp_s0->unk_04;
    if (temp_s0->unk_0C <= 0) {
        temp_s0->unk_0C += temp_s0->unk_08;
        func_800511BC(temp_s0);
    }

    if (manager->unk_40.unk_0A != 0) {
        func_80053A28(&manager->unk_40);
        func_80053A98(manager->unk_BE, manager->unk_40.unk_00.u16, manager->unk_5C);
    }

    manager->unkCounter -= manager->unkCounterStep;
    if (manager->unkCounter <= 0) {
        manager->unkCounter += manager->unkCounterMax;
        manager->unk_BA = func_8004C444(manager);
    }

    t1 = &D_80078DB0;
    if (*t1 == 0) {
        bgmPlayer1 = D_8009A5FC;
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
        if (*t1 == 0) {
            if (temp_s2->unk_80 != 0) {
                func_8004DFD4(temp_s2);
            }
            bgmPlayer2 = D_8009A664;
            if (bgmPlayer2->unk_46 != 0) {
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

void func_800535C0(void) {
    UnkAl19E0* temp_s1 = D_8009A5C0;
    BGMPlayer* player = D_8009A664;
    SoundManager* manager = D_8009A640;

    if (temp_s1->unk_9C != 0) {
        func_8005610C();
    }

    D_8009A5E8 = temp_s1->unk_A4[0];
    if (D_8009A5E8 != NULL) {
        D_8009A5E8();
    }

    func_8004D510(player);
    player = D_8009A5FC;
    func_8004D510(D_8009A5FC);
    func_8004B748(manager);
}

void func_80053654(UnkAl19E0* arg0) {
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

    if (arg0->unk_40[0].unk_01 != 0) {
        func_80056DCC(0, arg0->unk_40[0].unk_00);
        arg0->unk_40[0].unk_01 = 0;
    }
    if (arg0->unk_40[1].unk_01 != 0) {
        func_80056DCC(1, arg0->unk_40[1].unk_00);
        arg0->unk_40[1].unk_01 = 0;

    } if (arg0->unk_40[2].unk_01 != 0) {
        func_80056DCC(2, arg0->unk_40[2].unk_00);
        arg0->unk_40[2].unk_01 = 0;
    }
    if (arg0->unk_40[3].unk_01 != 0) {
        func_80056DCC(3, arg0->unk_40[3].unk_00);
        arg0->unk_40[3].unk_01 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(arg0->unk_1320); i++) {
        UnkAl48* it = &arg0->unk_1320[i];
        u8 unk_43 = it->unk_43;

        if (it->unk_42 != 0) {
            func_80056EE8(i);
            it->unk_42 = 0;
            it->unk_1C = 0;
            it->unk_45 = 0;
        }

        if (unk_43 & 2) {
            func_80052BF8(it, &it->unk_14);
            func_80056FA4(i, it->unk_10, it->unk_00, it->unk_04, it->unk_0C, it->unk_0E, it->unk_0F, it->unk_08);
            it->unk_45 = it->unk_44;
        } else {
            if (unk_43 & 8) {
                func_80057344(i, it->unk_04);
            }

            if (unk_43 & 4) {
                func_8005736C(i, it->unk_0C, it->unk_08, it->unk_0E, it->unk_0F);
            } else if (unk_43 & 0x10) {
                func_80057548(i, it->unk_0E, it->unk_0F);
            }
        }
        it->unk_43 = 0;
    }
}

void func_80053888(UnkAl48* arg0, s32 arg1) { // type may be wrong but it seems good
    if (arg0->unk_45 != 0) {
        arg0->unk_1C = 0;
        arg0->unk_42 = 1;
        arg0->unk_43 = 0;
        func_800576EC(arg1, 0, 0xB8);
    }
}

void func_800538C4(UnkAl48* arg0, s32 arg1) { // type may be wrong but it seems good
    arg0->unk_1C = 0;
    arg0->unk_42 = 1;
    arg0->unk_43 = 0;
    func_800576EC(arg1, 0, 0xB8);
}

INCLUDE_ASM(s32, "2e230_len_2190", func_800538F8);

void snd_initialize_fade(Fade* fade, s32 time, s32 startValue, s16 endValue) {
    fade->currentVolume.s32 = startValue * 0x10000;
    fade->endVolume = endValue;

    if (time != 0) {
        fade->fadeTime = (time * 1000) / 5750;
        fade->fadeStep = (endValue * 0x10000 - fade->currentVolume.s32) / fade->fadeTime;
    } else {
        fade->fadeTime = 1;
        fade->fadeStep = 0;
    }

    fade->fpFadeCallback = NULL;
}

void func_80053A18(Fade* fade) {
    fade->fadeTime = 0;
    fade->fadeStep = 0;
    fade->fpFadeCallback = NULL;
}

void func_80053A28(UnkAl1* arg0) {
    arg0->unk_0A--;

    if ((arg0->unk_0A << 0x10) != 0) {
        arg0->unk_00.s32 += arg0->unk_04;
    } else {
        arg0->unk_00.s32 = arg0->unk_08 << 0x10;
        if (arg0->unk_0C != 0) {
            arg0->unk_0C();
            arg0->unk_04 = 0;
            arg0->unk_0C = NULL;
        }
    }
}

void func_80053A98(u8 arg0, u16 arg1, s32 arg2) {
    func_80056D78(arg0, (u32)(arg1 * arg2) >> 15);
}

void func_80053AC8(UnkAl1* arg0) {
    if (arg0->unk_0A == 0) {
        arg0->unk_0A = 1;
        arg0->unk_04 = 0;
        arg0->unk_08 = arg0->unk_00.u16;
    }
}

void func_80053AEC(UnkAl1* arg0, s16 arg1) {
    arg0->unk_10.s32 = arg1 << 16;
    arg0->unk_18 = arg1;
    arg0->unk_1A = 0;
    arg0->unk_14 = 0;
}

void func_80053B04(UnkAl1* arg0, u32 arg1, s16 arg2) {
    s16 temp_a0;
    s32 temp_v1;

    if (arg1 >= 250 && arg1 <= 100000) {
        temp_a0 = (s32)(arg1 * 1000) / 5750;
        temp_v1 = (arg2 << 16) - arg0->unk_10.s32;

        arg0->unk_18 = arg2;
        arg0->unk_1A = temp_a0;
        arg0->unk_14 = temp_v1 / temp_a0;
    } else {
        arg0->unk_1A = 0;
        arg0->unk_14 = 0;
    }
}

void func_80053BA8(UnkAl1* arg0) {
    arg0->unk_1A--;

    if (arg0->unk_1A != 0) {
        arg0->unk_10.s32 += arg0->unk_14;
    } else {
        arg0->unk_14 = 0;
        arg0->unk_10.s32 = arg0->unk_18 << 16;
    }
}

INCLUDE_ASM(s32, "2e230_len_2190", func_80053BE8, UnkAl19E0* arg0, s32 arg1, s32 arg2, s32* arg3);

void snd_get_sequence_player_and_track(u32 playerIndex, s32** outCurrentTrackData, BGMPlayer** outPlayer) {
    UnkAl19E0* temp_v1 = D_8009A5C0;

    switch (playerIndex) {
        case 0:
            *outCurrentTrackData = temp_v1->currentTrackData[0];
            *outPlayer = D_8009A664;
            break;
        case 1:
            *outCurrentTrackData = temp_v1->currentTrackData[1];
            *outPlayer = D_8009A5FC;
            break;
        case 2:
            *outCurrentTrackData = temp_v1->currentTrackData[0];
            *outPlayer = D_8009A664;
            break;
        default:
            *outCurrentTrackData = NULL;
            *outPlayer = NULL;
    }
}

void snd_get_sequence_player(u32 playerIndex, BGMPlayer** outPlayer) {
     switch (playerIndex) {
        case 0:
            *outPlayer = D_8009A664;
            break;
        case 1:
            *outPlayer = D_8009A5FC;
            break;
        case 2:
            *outPlayer = D_8009A664;
            break;
        default:
            *outPlayer = NULL;
    }
}

INCLUDE_ASM(s32, "2e230_len_2190", snd_load_song_files);

INCLUDE_ASM(s32, "2e230_len_2190", func_80053E58);

BGMPlayer* func_80053F64(s32 arg0) {
    if (arg0 == 0) {
        return D_8009A5C0->unk_6C[0].unk_0;
    }
    return NULL;
}

INCLUDE_ASM(s32, "2e230_len_2190", func_80053F80);

BGMPlayer* func_80054248(u8 arg0) {
    switch (arg0) {
        case 1:
            return D_8009A664;
        case 2:
            return D_8009A5FC;
        case 4:
            return D_8009A640;
        default:
            return NULL;
    }
}

INCLUDE_ASM(void, "2e230_len_2190", snd_load_INIT, UnkAl19E0* arg0, s32 arg1, ALHeap* arg2);

INCLUDE_ASM(s32, "2e230_len_2190", snd_fetch_SBN_file, u16 arg0, s32 arg1, s32* arg2);

INCLUDE_ASM(void, "2e230_len_2190", snd_load_PER, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(void, "2e230_len_2190", snd_load_PRG, UnkAl19E0* arg0, s32* arg1);

INCLUDE_ASM(s32, "2e230_len_2190", snd_load_BGM);

InstrumentGroup* snd_get_BK_instruments(s32 bankGroup, u32 bankIndex) {
    InstrumentGroup* ret = NULL;
    UnkAl19E0* temp = D_8009A5C0;

    // TODO fake match - this multiplying the bankIndex by 16 and then dividing it right after is dumb
    bankIndex *= 16;

    switch (bankGroup) {
        case 1:
            ret = temp->instrumentGroup1[bankIndex / 16];
            break;
        case 2:
            ret = temp->instrumentGroup2[bankIndex / 16];
            break;
        case 4:
            ret = temp->instrumentGroup4[bankIndex / 16];
            break;
        case 5:
            ret = temp->instrumentGroup5[bankIndex / 16];
            break;
        case 6:
            ret = temp->instrumentGroup6[bankIndex / 16];
            break;
        case 3:
            ret = temp->instrumentGroup3[bankIndex / 16];
            break;
    }

    return ret;
}

INCLUDE_ASM(s32, "2e230_len_2190", snd_load_BK_to_bank, s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 arg3);

void snd_swizzle_BK_instruments(s32 bkFileOffset, SoundBank* bank, InstrumentGroup instruments, s32 instrumentCount, u8 arg4);
// float weirdness
#ifdef NON_MATCHING
void snd_swizzle_BK_instruments(s32 bkFileOffset, SoundBank *bank, Instruments instruments, u32 instrumentCount, u8 arg4) {
    SoundBank* sb = bank;
    Instrument* defaultInstrument = D_8009A5C0->defaultInstrument;
    f32 freq = D_8009A5C0->actualFrequency;
    s32 i;

    if (sb->swizzled == 0) {
        for (i = 0; i < instrumentCount; i++) {
            Instrument* instrument = instruments[i];

            if (instrument != NULL) {
                if (instrument->wavOffset != 0) {
                    instrument->wavOffset += bkFileOffset;
                }
                if (instrument->loopPredictorOffset != 0) {
                    instrument->loopPredictorOffset += (s32)bank;
                }
                if (instrument->predictorOffset != 0) {
                    instrument->predictorOffset += (s32)bank;
                }
                if (instrument->unkOffset != 0) {
                    instrument->unkOffset += (s32)bank;
                }
                instrument->unk_25 = arg4;
                instrument->sampleRate = (instrument->sampleRate / freq);
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        sb->swizzled = 1;
    }
}
#else
INCLUDE_ASM(void, "2e230_len_2190", snd_swizzle_BK_instruments, s32 bkFileOffset, SoundBank* bank, InstrumentGroup instruments, s32 instrumentCount, u8 arg4);
#endif


INCLUDE_ASM(s32, "2e230_len_2190", func_80054AA0);

s32 snd_load_BK(s32 arg0, s32 arg1) {
    snd_load_BK_to_bank(arg0, D_8009A5C0->banks[arg1], arg1, 1);
    return 0;
}

INCLUDE_ASM(s32, "2e230_len_2190", func_80054C84);

INCLUDE_ASM(void, "2e230_len_2190", func_80054CE0, s32 arg0, s32 arg1);

s32 func_80054D74(s32 arg0, s32 arg1) {
    if (arg0 & 0x10) {
        return func_8004B9E4(D_8009A640, arg1);
    }
    return 0;
}

INCLUDE_ASM(s32, "2e230_len_2190", func_80054DA8);

INCLUDE_ASM(void, "2e230_len_2190", snd_read_rom, s32 arg0, s32* arg1, s32 arg2);

INCLUDE_ASM(s32, "2e230_len_2190", snd_memset);

void snd_bcopy(s8* src, s8 *dest, s32 size) {
    if (size > 0) {
        while (size-- != 0) {
            *dest++ = *src++;
        }
    }
}

void snd_copy_words(s32* src, s32* dst, s32 num) {
    num /= 4;

    if (num > 0) {
        if ((((s32) src | (s32) dst) & 3) == 0) {
            s32* srcIt = src;
            s32* dstIt = dst;

            num--;
            do {
                *dstIt++ = *srcIt++;
            } while (num-- != 0);
        }
    }
}
