#include "audio.h"

// data
extern u16 D_80078530[];
extern f32 D_80078730[];
extern u8 D_80078580[];
extern s32 D_8007854C[2];

void func_80052E30(u8 index) {
    UnkAl48* temp = &D_8009A5C0->unk_1320[index];

    temp->unk_1C = 0;
    temp->unk_45 = 0;
}

void snd_load_audio_data(s32 frequency) {
    UnkAl19E0* temp4;
    s32* temp_v0_2;
    ALHeap* alHeap;
    u32 i;
    SBNFileEntry fileEntry;
    u8 temp6[4];
    UnkAl48* temp5;

    alHeap = D_80078E54->heap;
    D_8009A5C0 = alHeapAlloc(alHeap, 1, 0x19E0);

    D_8009A664 = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    D_8009A5FC = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    D_8009A5CC = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    D_8009A640 = alHeapAlloc(alHeap, 1, 0x6CC);
    D_8009A628 = alHeapAlloc(alHeap, 1, 0x834);
    D_8009A664->soundManager = D_8009A640;
    D_8009A628->unk_00 = D_8009A5C0;


    temp4 = D_8009A5C0;
    temp_v0_2 = alHeapAlloc(alHeap, 1, 0x8000);
    temp4->currentTrackData[0] = &temp_v0_2[0];
    temp4->currentTrackData[1] = &temp_v0_2[0x1400];
    temp4->currentTrackData[2] = &temp_v0_2[0x1C00];
    temp4->currentTrackData[3] = &temp_v0_2[0x1400];

    for (i = 0; i < 1; i++) {
        temp4->unk_6C[i].unk_0 = alHeapAlloc(alHeap, 1, sizeof(BGMPlayer));
    }

    temp4->dataSEF = alHeapAlloc(alHeap, 1, 0x5200);
    temp4->defaultInstrument = alHeapAlloc(alHeap, 1, sizeof(Instrument));
    temp4->dataPER = alHeapAlloc(alHeap, 1, 6 * sizeof(PEREntry));
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

    func_8004E158(D_8009A664, 1, 0, temp4);
    temp6[0] = 0;
    temp6[1] = 3;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(D_8009A664, temp6);
    func_8004E158(D_8009A5FC, 2, 2, temp4);
    temp6[0] = 2;
    temp6[1] = 0xff;
    temp6[2] = 0xff;
    temp6[3] = 0xff;
    func_8004E344(D_8009A5FC, temp6);
    func_8004B440(D_8009A640, 4, 1, temp4, 0x10);
    func_80050B90(D_8009A628, 6, 1, temp4);
    func_80052614(temp4);
    snd_load_BK_headers(temp4, alHeap);
    if (snd_fetch_SBN_file(temp4->mseqFileList->unk_0, 0x20, &fileEntry) == 0) {
        snd_read_rom(fileEntry.offset, temp4->dataSEF, fileEntry.data & 0xFFFFFF);
    }
    snd_load_sfx_groups_from_SEF(D_8009A640);
    if (snd_fetch_SBN_file(temp4->mseqFileList[1].unk_0, 0x40, &fileEntry) == 0) {
        snd_load_PER(temp4, fileEntry.offset);
    }
    if (snd_fetch_SBN_file(temp4->mseqFileList[2].unk_0, 0x40, &fileEntry) == 0) {
        snd_load_PRG(temp4, fileEntry.offset);
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
    arg0->unk_04 = 0x7F;
    arg0->unk_05 = 64;
    arg0->unk_06 = 0;
    arg0->unk_07 = 0;
    arg0->unk_08 = 0;
    arg0->unk_09 = 0;
    arg0->unk_0A = 0;
}

void func_800533A8(InstrumentCFG* arg0) {
    arg0->unk_00 = 8208;
    arg0->unk_02 = 0x7F;
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

    func_80053654(temp_s2);

    temp_s0->unk_0C -= temp_s0->unk_04;
    if (temp_s0->unk_0C <= 0) {
        temp_s0->unk_0C += temp_s0->unk_08;
        func_800511BC(temp_s0);
    }

    if (manager->unk_40.fadeTime != 0) {
        func_80053A28(&manager->unk_40);
        func_80053A98(manager->unk_BE, manager->unk_40.currentVolume.u16, manager->unk_5C);
    }

    manager->unkCounter -= manager->unkCounterStep;
    if (manager->unkCounter <= 0) {
        manager->unkCounter += manager->unkCounterMax;
        manager->unk_BA = func_8004C444(manager);
    }

    if (D_80078DB0 == 0) {
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
        if (D_80078DB0 == 0) {
            if (temp_s2->unk_80 != 0) {
                func_8004DFD4(temp_s2);
            }
            bgmPlayer2 = D_8009A664;
            if (bgmPlayer2->fadeInfo.unk_1A != 0) {
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

#ifdef NON_EQUIVALENT
f32 snd_tune_param_to_timescale(s32 arg0) {
    if (arg0 >= 0) {
        return D_80078730[(u32)arg0 & 0x7F] * D_80078730[128 + (((u32)arg0 >> 7) & 0x1F)];
    } else {
        arg0 = -arg0;
        return D_80078730[160 + ((u32)arg0 & 0x7F)] * D_80078730[288 + (((u32)arg0 >> 7) & 0x7F)];
    }
}
#else
INCLUDE_ASM(s32, "2e230_len_2190", snd_tune_param_to_timescale);
#endif

void snd_initialize_bgm_fade(Fade* fade, s32 time, s32 startValue, s16 endValue) {
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

void snd_clear_bgm_fade(Fade* fade) {
    fade->fadeTime = 0;
    fade->fadeStep = 0;
    fade->fpFadeCallback = NULL;
}

void func_80053A28(Fade* arg0) {
    arg0->fadeTime--;

    if ((arg0->fadeTime << 0x10) != 0) {
        arg0->currentVolume.s32 += arg0->fadeStep;
    } else {
        arg0->currentVolume.s32 = arg0->endVolume << 0x10;
        if (arg0->fpFadeCallback != 0) {
            arg0->fpFadeCallback();
            arg0->fadeStep = 0;
            arg0->fpFadeCallback = NULL;
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
        fade->endVolume = fade->currentVolume.u16;
    }
}

void func_80053AEC(Fade* fade, s16 arg1) {
    fade->unk_10.s32 = arg1 << 16;
    fade->unk_18 = arg1;
    fade->unk_1A = 0;
    fade->unk_14 = 0;
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

void func_80053BA8(Fade* arg0) {
    arg0->unk_1A--;

    if (arg0->unk_1A != 0) {
        arg0->unk_10.s32 += arg0->unk_14;
    } else {
        arg0->unk_14 = 0;
        arg0->unk_10.s32 = arg0->unk_18 << 16;
    }
}

Instrument* func_80053BE8(UnkAl19E0* arg0, u32 arg1, u32 arg2, s32** arg3) {
    void* temp_v0;
    void* phi_v0;

    Instrument* temp_a2 = (*arg0->instrumentGroups[(arg1 & 0x70) >> 4])[arg2];
    UnkAl4Plus* temp_a0 = temp_a2->unkOffset;
    u32 temp_a1 = arg1 % 4;

    if (temp_a1 < temp_a0->count) {
        arg3[0] = (s32*)(temp_a0->unk_04[temp_a1].unkOffset1 + (s32)temp_a0);
        arg3[1] = (s32*)(temp_a0->unk_04[temp_a1].unkOffset2 + (s32)temp_a0);
    } else {
        arg3[0] = &D_8007854C[0];
        arg3[1] = &D_8007854C[1];
    }
    return temp_a2;
}

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
            break;
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
            break;
    }
}

s32 snd_load_song_files(u32 arg0, UnkAlTrack* arg1, BGMPlayer* arg2) {
    SBNFileEntry fileEntry;
    SBNFileEntry fileEntry2;
    SBNFileEntry* bkFileEntry;
    UnkAl19E0* soundData;
    InitSongEntry* songEntry;
    s32 i;
    u16 bkFileIndex;
    s32 bgmFileIndex;
    u32 data;
    u32 offset;
    s32 ret;
    BGMPlayer* arg2_copy ;
    UnkAlTrack* arg1_copy;
    s32 cond;

    soundData = D_8009A5C0;

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
        arg2_copy->unk_64 = arg1;
        arg2_copy->bgmFileIndex = bgmFileIndex;
        return arg1_copy->unk_08;
    } else {
        return 151;
    }
}

s32 func_80053E58(s32 arg0, u8* arg1) {
    SBNFileEntry fileEntry;
    SBNFileEntry sp18;
    SBNFileEntry* bkFileEntry;
    UnkAl19E0* soundData;
    InitSongEntry* temp_s1;
    s32 i;
    s32 ret;
    u32 data;
    u32 offset;
    u16 bkFileIndex;

    soundData = D_8009A5C0;
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
        return D_8009A5C0->unk_6C[0].unk_0;
    }
    return NULL;
}

s32 func_80053F80(u32 arg0) {
    u32 i;
    SBNFileEntry fileEntry;
    UnkAl19E0* soundData;
    UnkAl834* temp_s2;
    s32* trackData;

    soundData = D_8009A5C0;
    temp_s2 = D_8009A628;
    if (arg0 < 16) {
        if (temp_s2->unk_24[0].unk_20 == 0 && snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0]].unk_0, 0x40, &fileEntry) == 0) {
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
        if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0]].unk_0, 0x40, &fileEntry) == 0) {
            snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
            temp_s2->unk_10[0] = trackData;

            trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
            if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 1]].unk_0, 0x40, &fileEntry) == 0) {
                snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                temp_s2->unk_10[1] = trackData;

                trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
                if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 2]].unk_0, 0x40, &fileEntry) == 0) {

                    snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                    temp_s2->unk_10[2] = trackData;

                    trackData = (s32*)((u32)trackData + ((fileEntry.data + 0x40) & 0xFFFFFF));
                    if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 3]].unk_0, 0x40, &fileEntry) == 0) {
                        snd_read_rom(fileEntry.offset, trackData, fileEntry.data & 0xFFFFFF);
                        temp_s2->unk_10[3] = trackData;

                        temp_s2->unk_20 = 4;
                        if (snd_fetch_SBN_file(soundData->mseqFileList[D_80078580[arg0 + 4]].unk_0, 0x30, &fileEntry) == 0) {
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
            return D_8009A664;
        case 2:
            return D_8009A5FC;
        case 4:
            return D_8009A640; // TODO: why return pointer to SoundManager?
        default:
            return NULL;
    }
}

void snd_load_INIT(UnkAl19E0* arg0, s32 romAddr, ALHeap* heap) {
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
    UnkAl19E0* temp = D_8009A5C0;
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

void snd_load_PER(UnkAl19E0* arg0, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    void* end;

    snd_read_rom(romAddr, &header, sizeof(PERHeader));
    size = header.totalSize - sizeof(PERHeader);
    snd_read_rom(romAddr + sizeof(PERHeader), arg0->dataPER, size);
    numItems = size / sizeof(PEREntry);
    numItemsLeft = 6 - numItems;
    if (numItemsLeft > 0) {
        end = &arg0->dataPER[numItems];
        snd_copy_words(&arg0->unk_08, end, sizeof(UnkAlC));
        snd_copy_words(end, end + sizeof(UnkAlC), numItemsLeft * sizeof(PEREntry) - sizeof(UnkAlC));
    }
}

void snd_load_PRG(UnkAl19E0* arg0, s32 romAddr) {
    PERHeader header;
    u32 size;
    s32 numItemsLeft;
    s32 numItems;
    s32 dataRomAddr;
    void* end;

    snd_read_rom(romAddr, &header, sizeof(PERHeader));
    dataRomAddr = romAddr + sizeof(PERHeader);
    size = header.totalSize - sizeof(PERHeader);
    if (size > 0x200) {
        size = 0x200;
    }
    snd_read_rom(dataRomAddr, arg0->dataPRG, size);
    numItems = size / sizeof(InstrumentCFG);
    numItemsLeft = 0x40 - numItems;
    if (numItemsLeft > 0) {
        end = &arg0->dataPRG[numItems];
        snd_copy_words(&arg0->defaultPRGEntry, end, sizeof(InstrumentCFG));
        snd_copy_words(end, end + sizeof(InstrumentCFG), numItemsLeft * sizeof(InstrumentCFG) - sizeof(InstrumentCFG));
    }
}


INCLUDE_ASM(s32, "2e230_len_2190", snd_load_BGM);

InstrumentGroup* snd_get_BK_instruments(s32 bankGroup, u32 bankIndex) {
    InstrumentGroup* ret = NULL;
    UnkAl19E0* temp = D_8009A5C0;

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
INCLUDE_ASM(s32, "2e230_len_2190", snd_load_BK_to_bank, s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 arg3);
#endif

void snd_swizzle_BK_instruments(s32 bkFileOffset, SoundBank* bank, InstrumentGroup instruments, u32 instrumentCount,
                                u8 arg4) {
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
                instrument->sampleRate = *((s32*)(&instrument->sampleRate)) / freq; // what is happening here?
            } else {
                instruments[i] = defaultInstrument;
            }
        }
        sb->swizzled = 1;
    }
}

INCLUDE_ASM(s32, "2e230_len_2190", func_80054AA0);

s32 snd_load_BK(s32 bkFileOffset, s32 bankIndex) {
    snd_load_BK_to_bank(bkFileOffset, D_8009A5C0->banks[bankIndex], bankIndex, 1);
    return 0;
}

void func_80054C84(s32 bankIndex, s32 bankGroup) {
    u32 i;
    Instrument* instrument = D_8009A5C0->defaultInstrument;
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
            D_8009A664->unk_48 = temp_s0;
            func_80053AC8(&D_8009A664->fadeInfo);
            D_8009A5FC->unk_48 = temp_s0;
            func_80053AC8(&D_8009A5FC->fadeInfo);
        }
        if (arg0 & 0x10) {
            D_8009A640->unk_5C = temp_s0;
            func_80053AC8(&D_8009A640->unk_40);
        }
    }
}

s32 func_80054D74(s32 arg0, s32 arg1) {
    if (arg0 & 0x10) {
        return func_8004B9E4(D_8009A640, arg1);
    }
    return 0;
}

void func_80054DA8(u32 arg0) {
    if (arg0 % 2 == 1) {
        if (D_8009A5C0->unk_130C == 0) {
            D_8009A5C0->unk_130C = 2;
        }
    } else {
        if (D_8009A5C0->unk_130C != 0) {
            D_8009A5C0->unk_50 = 1;
            D_8009A5C0->unk_130C = 0;
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

#ifdef NON_MATCHING
// v0/v1 swap
void snd_memset(s8* dst, s32 size, s8 value) {
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
        count = (u32)dst % 4;
        if (count != 0) {
            count = 4 - count;
            size -= count;
            while (count--) {
                *dst++ = value;
            }
        }

        count = size >> 2;
        intValue = value & 0xFF;
        intValue = intValue * 0x01010101;
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
#else
INCLUDE_ASM(s32, "2e230_len_2190", snd_memset);
#endif

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
