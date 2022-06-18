#include "common.h"
#include "audio.h"

extern s8 gBlankSEFData[12];
extern InstrumentEffect* D_800783C0[25];

void snd_SEFCmd_00_SetVolume(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_01_SetPan(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_02_SetInstrument(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_03_SetReverb(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_04(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_05(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_06(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_07(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_08(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_09_StartLoop(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0A_EndLoop(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0B(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0C(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0D(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0E(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_0F(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_10_Jump(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_SetUnkA1(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_SetUnkA2(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_SetUnkA3(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_16(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_17(SoundManager* manager, SoundPlayer* player);
void snd_SEFCmd_18(SoundManager* manager, SoundPlayer* player);

void snd_set_player_modifiers(SoundPlayer* player, SoundSFXEntry* sfxEntry);
void func_800538C4(UnkAl48* arg0, s32 arg1);

void func_8004B440(SoundManager* manager, u8 arg1, u8 arg2, SndGlobals* arg3, u8 arg4) {
    u32 i;
    s32 c = 0x6A25E;

    manager->soundData = arg3;
    manager->unkCounterStep = 312500;
    manager->unkCounterMax = manager->unkCounter = c;
    manager->unk_BC = arg1;
    manager->unk_BE = arg2;

    if (arg4 > 0x10) {
        manager->sfxPlayerSelector = 0x10;
    } else {
        manager->sfxPlayerSelector = arg4;
    }

    manager->unk_5C = 0x8000;
    manager->unk_B8 = 0x8000;
    manager->playCounter = 0;
    manager->unk_60 = 0;

    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* sub = &manager->unk_16C[i];

        sub->sefDataReadPos = 0;
        sub->sfxVolume = 0;
        sub->unk_8E = 0;
        sub->unk_90 = 0;
        sub->unk_92 = 0;
        sub->unk_94 = 0;
        sub->sfxPan = 0;
        sub->reverb = 0;
        sub->instrumentIndex = 0;
        sub->unk_9E = 0;
        sub->unk_9F = 0;
        sub->unk_99 = 0;
        sub->locatorB = 0;
        sub->locatorC = 0;
        sub->locatorD = 0;
        sub->unk_7B = 0x40;
        sub->unk_7C = 0;
        sub->unk_7D = 0xB0;
        sub->unk_7E = 0;
        sub->unk_7F = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->unk_90); i++) {
        manager->unk_90[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->unk_A0); i++) {
        manager->unk_A0[i].x = 0;
    }

    manager->unk_168 = 0;
    func_8004BA54(manager, 0);
    snd_clear_sfx_queue(manager);
    snd_initialize_bgm_fade(&manager->unk_40, 0, 0x7FFF, 0x7FFF);
    func_80053A98(manager->unk_BE, manager->unk_40.currentVolume.u16, manager->unk_5C);
    manager->unk_8C = 0xFF;

    manager->unk_64[0] = &D_80078290;
    manager->unk_64[1] = &D_800782F8;
    manager->unk_64[2] = &D_80078320;
    manager->unk_64[3] = &D_80078348;
    manager->unk_64[4] = &D_80078348;
    manager->unk_64[5] = &D_80078348;
    manager->unk_64[6] = &D_80078348;
    manager->unk_64[7] = &D_80078348;

    manager->unk_84[0] = 0x10;
    manager->unk_84[1] = 0x20;
    manager->unk_84[2] = 0x20;
    manager->unk_84[3] = 0x20;
    manager->unk_84[4] = 0x20;
    manager->unk_84[5] = 0x30;
    manager->unk_84[6] = 0x40;
    manager->unk_84[7] = 0x50;

    func_8004B9E4(manager, 0);
}

void snd_load_sfx_groups_from_SEF(SoundManager* sndMgr) {
    SEFHeader* sefData = sndMgr->soundData->dataSEF;
    s32 sections = ARRAY_COUNT(sefData->sections);
    u32 i;

    sndMgr->sefData = sefData;
    
    for (i = 0; i < sections; i++) {
        if (sefData->sections[i] != 0) {
            sndMgr->normalSounds[i] = sefData->sections[i] + (s32)sefData;
        }
    }

    if (sefData->hasExtraSection == 1) {
        if (sefData->section2000 != 0) {
            sndMgr->soundsWithBit2000 = sefData->section2000 + (s32)sefData;
        }
    }
}

void snd_clear_sfx_queue(SoundManager* manager) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->unk_C2); i++) {
        manager->unk_C2[i].soundID = 0;
        manager->unk_C2[i].upperSoundID = 0;
        manager->unk_C2[i].volume = 0;
        manager->unk_C2[i].pitchShift = 0;
        manager->unk_C2[i].pan = 0;
    }

    manager->unk_165 = 0;
    manager->sfxQueueNextPos = 0;
    manager->sfxQueuePosOffset = 0;
    manager->unk_162 = 0;
}

void snd_enqueue_sfx_event(SoundManager* manager, s32 soundID, s16 volume, s16 pitchShift, u8 pan) {
    u32 queuePos = manager->sfxQueueNextPos;
    s32 queueAmt = manager->sfxQueueNextPos - manager->sfxQueuePosOffset;

    if (queueAmt < 0) {
        queueAmt += 16;
    }

    if (queueAmt < 16) {
        u32 queueNextPos = queuePos;

        manager->unk_C2[queueNextPos].soundID = soundID & 0xBFFF;
        manager->unk_C2[queueNextPos].upperSoundID = (((u32) soundID >> 0x10) & 0x3FF);
        manager->unk_C2[queueNextPos].volume = volume;
        manager->unk_C2[queueNextPos].pitchShift = pitchShift;
        manager->unk_C2[queueNextPos].pan = pan;

        queueNextPos++;
        if (queueNextPos >= 16) {
            queueNextPos = 0;
        }

        manager->sfxQueueNextPos = queueNextPos;
    }
}

INCLUDE_ASM(void, "26840_len_20d0", func_8004B748, SoundManager* manager);

s32 func_8004B9E4(SoundManager* manager, s32 arg1) {
    s32 a1 = (u8) arg1;

    if (a1 != 0xF0) {
        if (a1 < 8) {
            if (manager->unk_8C != a1) {
                manager->unk_8C = a1;
                manager->soundData->unk_40[1].unk_00 = 6;
                manager->soundData->unk_40[1].unk_01 = 1;
                D_8007F1F8[0] = manager->unk_64[a1];
            }
            manager->unk_8D = manager->unk_84[a1];
        } else {
            manager->unk_8C = 0xFF;
            manager->unk_8D = 0;
        }
    }
    return manager->unk_8C;
}

void func_8004BA54(SoundManager* manager, s32 arg1) {
    if (arg1 == 0) {
        manager->unk_C0 = 0;
    } else if (arg1 == 1) {
        manager->unk_C0 = 1;
    }
}

INCLUDE_ASM(s32, "26840_len_20d0", func_8004BA74);

void func_8004C0E4(SoundManager* manager, SoundPlayer* player, s8* readPos, SoundSFXEntry* sfxEntry, s32 arg4, s32 arg5) {
    if (manager->unk_C0 == 0) {
        player->sefDataReadPos = readPos;
        player->sefReadStart = readPos;
        player->sfxInstrumentRef = manager->soundData->defaultInstrument;
        player->sfxPan = 0x40;
        player->sfxVolume = 0x7FFF;
        player->unk_5E = 0x7FFF;
        player->reverb = 0;
        player->instrumentIndex = 0;
        player->unk_9E = 0;
        player->unk_9F = 0x7F;
        player->unk_92 = 0;
        player->unk_94 = 0;
        player->loopStartPos = NULL;
        player->loopIterCount = 0;
        player->unk_8E = 1;
        player->unk_90 = 0;
        player->currentSoundID = sfxEntry->soundID & SOUND_ID_LOWER;
        player->unk_98 = arg4;
        player->unk_99 = arg5;
        player->unk_18 = 0;
        player->changed.all = 0;
        player->unk_A0 = 0;
        player->unk_A1 = 0;
        player->unk_A2 = 0;
        player->unk_A3 = 0;
        player->volumeLerp.current = 0x7FFFFFFF;
        player->volumeLerp.time = 0;
        player->volumeLerp.step = 0;
        player->volumeLerp.goal = 0;
        player->tuneLerp.current = 0;
        player->tuneLerp.time = 0;
        player->tuneLerp.step = 0;
        player->tuneLerp.goal = 0;
        player->unk_80 = 0;
        player->unk_84 = 0;
        player->soundC00 = 0;
        player->sfxParamsFlags = *player->sefDataReadPos++;
        switch (player->sfxParamsFlags & 3) {
            case 0:
                player->unk_A9 = 1;
                break;
            case 1:
                player->unk_A9 = 1;
                break;
            case 2:
                player->sfxParamsFlags &= 0xFC;
                player->unk_A9 = 1;
                player->locatorB = player->sefDataReadPos[0];
                player->locatorC = player->sefDataReadPos[1];
                player->locatorD = ((u8)player->sefDataReadPos[2] >> 1) | 3;
                player->unk_7E = player->sefDataReadPos[2] & 7;
                player->sefDataReadPos = &player->locatorB;
                break;
        }
        snd_set_player_modifiers(player, sfxEntry);
    }
}

void snd_set_bits_C00(SoundManager* manager, u32 soundID) {
    s32 soundUpper = (soundID & SOUND_ID_MID) >> 0xA;
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* player = &manager->unk_16C[i];
        if (player->currentSoundID == (soundID & SOUND_ID_LOWER)) {
            player->soundC00 = soundUpper;
        }
    }
}

void func_8004C2A4(SoundManager* manager, u32 soundID) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* player = &manager->unk_16C[i];
        if (player->currentSoundID == (soundID & SOUND_ID_LOWER)) {
            player->sefDataReadPos = &gBlankSEFData;
            player->unk_80 = 0;
            player->sfxParamsFlags = 1;
            player->unk_A9 = 0;
            player->unk_8E = 1;
            player->unk_98 = 0;
            player->unk_99 = 0;
        }
    }
}

void func_8004C300(SoundManager* manager, u32 soundID) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* player = &manager->unk_16C[i];
        if (soundID == player->unk_99) {
            player->sefDataReadPos = &gBlankSEFData;
            player->unk_80 = 0;
            player->sfxParamsFlags = 1;
            player->unk_A9 = 0;
            player->unk_8E = 1;
            player->unk_98 = 0;
            player->unk_99 = 0;
        }
    }
}

void snd_set_modifiers(SoundManager* manager, SoundSFXEntry* sfxEntry) {
    s32 soundID = sfxEntry->soundID & SOUND_ID_LOWER;
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* player = &manager->unk_16C[i];
        if (player->currentSoundID == soundID) {
            snd_set_player_modifiers(player, sfxEntry);
        }
    }
}

void snd_set_player_modifiers(SoundPlayer* player, SoundSFXEntry* sfxEntry) {
    if (player->sfxParamsFlags & 4) {
        player->masterVolume = 0;
    } else {
        player->masterVolume = sfxEntry->volume;
        player->changed.volume = TRUE;
    }
    if (player->sfxParamsFlags & 8) {
        player->masterPan = 0;
    } else {
        player->masterPan = sfxEntry->pan;
        player->changed.pan = TRUE;
    }
    if (player->sfxParamsFlags & 0x10) {
        player->masterPitchShift = 0;
    } else {
        player->masterPitchShift = sfxEntry->pitchShift;
        player->changed.tune = TRUE;
    }
}

void func_8004C578(SoundManager*, SoundPlayer*, UnkAl48*, u32);
void func_8004C884(SoundManager*, SoundPlayer*, UnkAl48*, u32);

s16 func_8004C444(SoundManager* manager) {
    u32 phi_a3 = manager->sfxPlayerSelector;
    u16 temp = manager->unk_60;
    u16 playCounter = manager->playCounter;
    SoundPlayer* temp_a1;
    UnkAl48* temp_a2;
    u8 i;

    manager->unk_60 = temp + playCounter;

    for (i = phi_a3, phi_a3 += 8; i < (u8)phi_a3; i++){
        temp_a1 = &manager->unk_16C[i - manager->sfxPlayerSelector];
        if (temp_a1->sefDataReadPos != 0) {
            manager->unk_04 = temp_a2 = &manager->soundData->unk_1320[i];
            if (manager->unk_04->unk_45 <= manager->unk_BC) {
                manager->unk_BF = i;
                switch (temp_a1->sfxParamsFlags & 3) {
                    case 0:
                        func_8004C578(manager, temp_a1, temp_a2, i);
                        break;
                    case 1:
                        func_8004C884(manager, temp_a1, temp_a2, i);
                        break;
                    case 2: // Yes, this is needed.
                        break;
                }
            } else {
                temp_a1->sefDataReadPos = NULL;
                temp_a1->currentSoundID = 0;
                temp_a1->unk_98 = 0;
            }
        }
    }
    return 0;
}

s32 func_8004D428(s32, s32, s32);                   /* extern */
void func_80053888(UnkAl48*, s32);                     /* extern */
void snd_SEFCmd_00_SetVolume(SoundManager*, SoundPlayer*); /* extern */
void snd_SEFCmd_01_SetPan(SoundManager*, SoundPlayer*); /* extern */
void snd_SEFCmd_02_SetInstrument(SoundManager*, SoundPlayer*); /* extern */
void snd_SEFCmd_03_SetReverb(SoundManager*, SoundPlayer*); /* extern */
s16 snd_get_scaled_volume(SoundManager*, SoundPlayer*); /* extern */
f32 snd_tune_param_to_timescale(s32);               /* extern */

void func_8004C578(SoundManager* manager, SoundPlayer* player, UnkAl48* ARG2, u32 ARG3) {
    s16 volume;
    s32 tune;
    s32 pan;
    s32 a;
    s32 b;

    switch(player->unk_A9) {
        case 0:
            if (ARG2->unk_45 != manager->unk_BC) {
                player->sefDataReadPos = NULL;
                player->currentSoundID = 0;
                player->unk_98 = 0;
            } else {
                if (!(player->sfxParamsFlags & 0x10)) {
                    player->actualSampleRate = snd_tune_param_to_timescale(
                        ((player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->unk_1E) + player->masterPitchShift) * player->sfxInstrumentRef->sampleRate;
                    if (ARG2->unk_04 != player->actualSampleRate) {
                        ARG2->unk_43 |= 8;
                        ARG2->unk_04 = player->actualSampleRate;
                    }
                }
                
                if (!(player->sfxParamsFlags & 8) && player->masterPan != 0) {
                    pan = player->masterPan;
                } else {
                    pan = player->sfxPan;
                }
                if (ARG2->unk_0E != pan) {
                    ARG2->unk_0E = pan;
                    ARG2->unk_43 |= 0x10;
                 }
                
                volume = snd_get_scaled_volume(manager, player);
                if (ARG2->unk_40 != volume) {
                    ARG2->unk_40 = volume;
                    ARG2->unk_3D |= 0x20;
                }
            }
            break;
        case 1:
            snd_SEFCmd_02_SetInstrument(manager, player);
            snd_SEFCmd_00_SetVolume(manager, player);
            snd_SEFCmd_01_SetPan(manager, player);
            snd_SEFCmd_03_SetReverb(manager, player);
            a = (*player->sefDataReadPos++ & 0x7F);
            b = (*player->sefDataReadPos & 0xF) << 3;
            tune = a * 100;
            player->unk_A1 = b;
            if ((u32)player->unk_A1 != 0) {
                player->tuneLerp.current = func_8004D428(manager->unk_60, (u8)player->unk_A1, tune) << 0x10;
            } else {
                player->tuneLerp.current = tune << 0x10;
            }
            if (player->sfxParamsFlags & 0x10) {
                tune = (player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->unk_1E;
            } else {
                tune = ((player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->unk_1E) + player->masterPitchShift;
            }
            player->actualSampleRate = snd_tune_param_to_timescale(tune) * player->sfxInstrumentRef->sampleRate;
            if (ARG2->unk_45 <= manager->unk_BC) {
                func_80053888(ARG2, ARG3 & 0xFF);
                if (!(player->sfxParamsFlags & 8) && player->masterPan != 0) {
                    ARG2->unk_0E = player->masterPan;
                } else {
                    ARG2->unk_0E = player->sfxPan;
                }
    
                ARG2->unk_0F = player->reverb;
                ARG2->unk_40 = snd_get_scaled_volume(manager, player);
                ARG2->unk_14 = (s32) player->unk10;
                ARG2->unk_18 = (s32) player->unk14;
                ARG2->unk_00 = (s32) player->sfxInstrumentRef;
                ARG2->unk_04 = player->actualSampleRate;
                ARG2->unk_43 = 2;
                ARG2->unk_45 = manager->unk_BC;
                ARG2->unk_44 = ARG2->unk_45;
                ARG2->unk_10 = manager->unk_BE;
            }
            player->unk_A9 = 0;
            break;
        default:
            player->sefDataReadPos = NULL;
            player->currentSoundID = 0;
            player->unk_98 = 0;
            break;
    }
}

s16 snd_get_scaled_volume(SoundManager* manager, SoundPlayer* player) {
    s32 outVolume;

    outVolume = (manager->unk_B8 * player->sfxVolume) >> 0xF;
    if (!(player->sfxParamsFlags & 4)) {
        if (player->masterVolume != 0) {
            outVolume = (outVolume * player->masterVolume) >> 0xF;
        }
    }
    return outVolume;
}

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C884);

void snd_set_voice_volume(UnkAl48* voice, SoundManager* manager, SoundPlayer* player) {
    s32 x = ((((manager->unk_B8
        * player->sfxVolume) >> 0xF)
        * player->unk_9F) >> 7)
        * (player->volumeLerp.current >> 0x10) >> 0xF;
    
    if (player->sfxParamsFlags & 4 || player->masterVolume == 0) {
        voice->unk_40 = x;
    } else {
        voice->unk_40 = (x * player->masterVolume) >> 0xF;
    }
}

u8 func_8004CDF8(s32 arg0, s32 arg1, s32 arg2) {

    s32 retVal;
    s32 cond;
    s32 a, b, c;

    arg1 = arg1 & 0xFF;
    cond = ((arg0 >> 5) + (arg0 >> 3)) & 1;
    
    a = (arg0 >> 8) & 0x1F;
    b = (arg0 << 3) & 0xE0;
    c = a + b;
    
    if (cond != 0) {
        retVal = arg1 + (((arg2 & 0xFF) * c) >> 8);
    } else {
        retVal = arg1 - (((arg2 & 0xFF) * c) >> 8);
    }
    if (retVal < 0) {
        retVal = 0;
    } else if (retVal > 0x7F) {
        retVal = 0x7F;
    }
    return retVal;
}

void snd_SEFCmd_00_SetVolume(SoundManager* manager, SoundPlayer* player) {
    player->sfxVolume = *(u8*)player->sefDataReadPos++;
    if (player->sfxVolume != 0) {
        player->sfxVolume = player->sfxVolume << 8 | 0xFF;
    }
    player->changed.volume = TRUE;
}

void snd_SEFCmd_01_SetPan(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 sfxPan = buf[0];
    player->sefDataReadPos = &buf[1];

    player->changed.pan = TRUE;
    player->sfxPan = sfxPan;
}

void snd_SEFCmd_02_SetInstrument(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 temp_a1 = buf[0];
    s32 temp_a2 = buf[1];
    player->sefDataReadPos = &buf[2];
    
    player->instrumentIndex = temp_a2;
    player->sfxInstrumentRef = func_80053BE8(manager->soundData, temp_a1, temp_a2, &player->unk10);
}

void snd_SEFCmd_03_SetReverb(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    u8 reverb = buf[0];
    player->sefDataReadPos = &buf[1];
    
    if ((player->sfxParamsFlags & 0x20) != 0) {
        reverb = manager->unk_8D;
    }
    player->reverb = reverb;
    player->changed.reverb = TRUE;
}

void snd_SEFCmd_04(SoundManager* manager, SoundPlayer* player) {
    Instrument* temp_a0;
    InstrumentEffect* temp_v0_2;

    u8* buf = player->sefDataReadPos;
    u8 temp_v1 = buf[0];
    player->sefDataReadPos = &buf[1];
   
    player->unk_9E = temp_v1 & 0x7F;
    temp_a0 = player->sfxInstrumentRef;
    
    player->sfxInstrument.wavOffset = temp_a0->wavOffset;
    player->sfxInstrument.wavLength = temp_a0->wavLength;
    player->sfxInstrument.loopPredictorOffset = temp_a0->loopPredictorOffset;
    player->sfxInstrument.loopStart = temp_a0->loopStart;
    player->sfxInstrument.loopEnd = temp_a0->loopEnd;
    player->sfxInstrument.loopCount = temp_a0->loopCount;
    player->sfxInstrument.predictorOffset = temp_a0->predictorOffset;
    player->sfxInstrument.unk_1C = temp_a0->unk_1C;
    player->sfxInstrument.unk_1E = temp_a0->unk_1E;
    player->sfxInstrument.sampleRate = temp_a0->sampleRate;
    player->sfxInstrument.skipLoopPredictor = temp_a0->skipLoopPredictor;
    player->sfxInstrument.unk_25 = temp_a0->unk_25;
    
    player->sfxInstrument.unkOffset = D_800783C0[player->unk_9E];
    player->sfxInstrumentRef = &player->sfxInstrument;
    
    temp_v0_2 = player->sfxInstrument.unkOffset;
    if (temp_v0_2 != NULL && temp_v0_2->count) {
        player->unk10 = (s8*)(temp_v0_2->unk_04[0].unkOffset1 + (s32)temp_v0_2);
        player->unk14 = (s8*)(temp_v0_2->unk_04[0].unkOffset2 + (s32)temp_v0_2);
    }
}

void snd_SEFCmd_05(SoundManager* manager, SoundPlayer* player) {
    //TODO buffer access different from other commands
    u32 temp_v1 = *player->sefDataReadPos;
    player->sefDataReadPos++;

    player->unk_92 = temp_v1 * 100;
}

void snd_SEFCmd_06(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 unkTemp = buf[0];
    player->sefDataReadPos = &buf[1];

    player->unk_94 = unkTemp;
}

void snd_SEFCmd_07(SoundManager* manager, SoundPlayer* player) {
    if (manager->unk_04->unk_45 == manager->unk_BC) {
        player->unk_8E = 2;
        player->sefDataReadPos--;
    }
}

void snd_SEFCmd_08(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 newValueH = buf[0];
    s32 newValueL = buf[1];
    s16 newValue = (buf[2] & 0x7F) * 100;
    s16 time = newValueL + (newValueH << 8);
    player->sefDataReadPos = &buf[3];
    
    if (time <= 0) {
        time = 1;
    }

    player->tuneLerp.time = time;
    player->tuneLerp.goal = newValue;    
    player->tuneLerp.step = ((newValue << 0x10) - player->tuneLerp.current) / time;
}

void snd_SEFCmd_09_StartLoop(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 loopIterCount = buf[0];
    player->sefDataReadPos = &buf[1];

    player->loopStartPos = player->sefDataReadPos;
    player->loopIterCount = loopIterCount;
}

void snd_SEFCmd_0A_EndLoop(SoundManager* manager, SoundPlayer* player) {
    //TODO logic is incorrect? fake match?
    if (player->loopIterCount == 0U || (--player->loopIterCount & 0xFF) != 0) {
        player->sefDataReadPos = player->loopStartPos;
    }
}

void snd_SEFCmd_0B(SoundManager* manager, SoundPlayer* player) {
    if (player->unk_90 != 0) {
        player->unk_8E = 3;
        player->sefDataReadPos--;
    }
}

void snd_SEFCmd_0C(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 vol = buf[0];
    player->sefDataReadPos = &buf[1];

    if (vol != 0) {
        vol = (vol << 0x18) | 0xFFFFFF;
    }
    player->volumeLerp.current = vol;
    player->changed.volume = 1;
}

void snd_SEFCmd_0D(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 newValueH = buf[0];
    s32 newValueL = buf[1];
    s32 newValue = buf[2];
    s16 time = newValueL + (newValueH << 8);
    player->sefDataReadPos = &buf[3];
    
    if (newValue != 0) {
        newValue = (newValue << 8) | 0xFF;
    }
    if (time <= 0) {
        time = 1;
    }

    player->volumeLerp.time = time;    
    player->volumeLerp.goal = newValue;
    player->volumeLerp.step = ((newValue << 0x10) - player->volumeLerp.current) / time;
}

void snd_SEFCmd_0E(SoundManager* manager, SoundPlayer* player) {
    s8* data = (s8*)manager->sefData;
    u8* buf = player->sefDataReadPos;
    s32 pos = (buf[1] << 8) + buf[2];
    u8 type = buf[0];
    player->sefDataReadPos = &buf[3];
    
    pos += (s32)data;
    player->unk_84 = (s32)type;
    switch(type) {
        case 1:
            player->unk_80 = pos;
            break;
        case 2:
            player->unk_80 = pos;
            break;
        case 3:
            player->unk_80 = pos;
            break;
        default:
            player->unk_80 = 0;
            break;
    }
}

void snd_SEFCmd_0F(SoundManager* manager, SoundPlayer* player) {
    UnkAl48* temp_a2 = manager->unk_04;
    if (temp_a2->unk_45 == manager->unk_BC) {
        func_800538C4(temp_a2, manager->unk_BF);
    }
}

void snd_SEFCmd_10_Jump(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    player->sefReadStart = &buf[2];
    player->sefDataReadPos = ((buf[0] << 8) + buf[1]) + (s32)manager->sefData;
}

void snd_SEFCmd_11_Restart(SoundManager* manager, SoundPlayer* player) {
    player->sefDataReadPos = player->sefReadStart;
}

void snd_SEFCmd_12_NOP(SoundManager* manager, SoundPlayer* player) {
}

void snd_SEFCmd_SetUnkA1(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 unkTemp = buf[0];
    player->sefDataReadPos = &buf[1];

    player->unk_A1 = unkTemp;
}

void snd_SEFCmd_SetUnkA2(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 unkTemp = buf[0];
    player->sefDataReadPos = &buf[1];

    player->unk_A2 = unkTemp;
}

void snd_SEFCmd_SetUnkA3(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    s32 unkTemp = buf[0];
    player->sefDataReadPos = &buf[1];

    player->unk_A3 = unkTemp;
}

void snd_SEFCmd_16(SoundManager* manager, SoundPlayer* player) {
    s8* data = manager->sefData;
    u8* buf = player->sefDataReadPos;
    s32 offset = (buf[0] << 8) + buf[1];

    if (offset != 0) {
        player->unk_18 = offset + (s32)manager->sefData;
    } else {
        player->unk_18 = NULL;
    }

    player->sefDataReadPos = &buf[2];
}

void snd_SEFCmd_17(SoundManager* manager, SoundPlayer* player) {
    u8* buf = player->sefDataReadPos;
    u32 i;
    
    for (i = 0; i < 4; i++) {
        if ((u16) manager->unk_A0[i].x == 0) {
            manager->unk_A0[i].x = buf[1] + (buf[0] << 8);
            manager->unk_A0[i].y = buf[3] + (buf[2] << 8);
            break;
        }    
    }
    player->sefDataReadPos = &buf[4];
}

void snd_SEFCmd_18(SoundManager* manager, SoundPlayer* player) {
    player->unk_5E = *(u8*)player->sefDataReadPos++;
    if (player->unk_5E != 0) {
        player->unk_5E = player->unk_5E << 8 | 0xFF;
    }
}

s32 func_8004D428(s32 arg0, s32 arg1, s32 arg2) {
    s32 a = (arg0 >> 7) & 0xF;
    s32 b = (arg0 << 3) & 0xF0;
    s32 c = (a + b);
    s32 d = (arg0 >> 5);
    s32 e = (arg0 >> 2);
    s32 f;

    if ((d + e) & 1) {
        f = c * 5;
        return arg2 + ((arg1 * f) >> 8);
    } else {
        f = c * 5;
        return arg2 - ((arg1 * f) >> 8);
    }
}

u8 func_8004D484(s32 arg0, s32 arg1, s32 arg2) {
    s32 a = (arg0 & 0xCC) >> 2;
    s32 b = (arg0 & 0x13) << 2;
    s32 c = a + b;
    
    return (arg2 * (0x8000 - (arg1 * c)) >> 0xF);
}


void func_8004D4BC(SoundManager* manager) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* temp_v0 = &manager->unk_16C[i];
        temp_v0->sefDataReadPos = &gBlankSEFData;
        temp_v0->unk_80 = 0;
        temp_v0->sfxParamsFlags = 1;
        temp_v0->unk_A9 = 0;
        temp_v0->unk_8E = 1;
        temp_v0->unk_98 = 0;
        temp_v0->unk_99 = 0;
    }
}
