#include "audio.h"

INCLUDE_ASM(void, "28910_len_5090", func_8004D510, BGMPlayer* arg0);

// Return values are being pushed into v0 in the wrong place
// May depend on data decomp
#ifdef NON_EQUIVALENT
BGMPlayer* snd_get_player_with_song_name(s32 songString) {
    SndGlobals* temp_v1 = D_8009A664->data;

    if (songString == temp_v1->currentTrackData[0][2]) {
        return D_8009A664;
    }
    if (songString == temp_v1->currentTrackData[1][2]) {
        return D_8009A5FC;
    }
    return NULL;
}
#else
INCLUDE_ASM(BGMPlayer*, "28910_len_5090", snd_get_player_with_song_name, s32 songString);
#endif

INCLUDE_ASM(s32, "28910_len_5090", snd_dispatch_bgm_player_event);

s32 func_8004DA0C(s32 songName) {
    s32 ret = 0;

    if (songName != 0) {
        BGMPlayer* player = snd_get_player_with_song_name(songName);

        do {} while (0);

        do {
            if (player == NULL) {
                ret = 2;
            } else if (songName == player->songName) {
                func_8004DAA8(player);
                ret = 0;
            }
        } while (0);
    } else {
        ret = 3;
    }

    return ret;
}

void func_8004DA74(void) {
    func_8004DAA8(D_8009A664);
    func_8004DAA8(D_8009A5FC);
}

void func_8004DAA8(BGMPlayer* player) {
    if (player->unk_221 != 0) {
        player->unk_221 = 4;
        player->unk_10 = 1;
        player->unkFrequency = 1;
        snd_clear_bgm_fade(&player->fadeInfo);
    }
}

s32 snd_is_song_playing(s32 songName) {
    if (songName != 0) {
        BGMPlayer* player = snd_get_player_with_song_name(songName);

        if (player != NULL) {
            return songName == player->songName;
        }
        return 2;
    }
    return 3;
}

s32 func_8004DB28(BGMPlayer* player) {
    if (player->songName != NULL && player->unk_221 != 0) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_8004DB4C(SongUpdateEvent* s) {
    BGMPlayer* player;
    u32 temp_s0 = s->songName;
    u32 temp_s1 = s->duration;
    s16 temp_s4 = s->finalVolume;
    s32 retVal = 0;
    if (temp_s0 != 0) {
        if ((temp_s1 - 0xFA) < 0x2617) { 
            player = snd_get_player_with_song_name(temp_s0);
            if (player != NULL) {
                if (player->songName == temp_s0) {
                    if (player->unk_221 != 0) {
                        if (player->unk_220 == 0) {
                            player->fadeInfo.endVolume = temp_s4;
                            player->fadeInfo.fadeTime = (temp_s1 * 1000) / 5750;
                            player->fadeInfo.fadeStep = (s32) ((temp_s4 << 0x10) - player->fadeInfo.currentVolume.u32) / player->fadeInfo.fadeTime;
                            player->fadeInfo.fpFadeCallback = (void (*)()) s->variation;
                            if (s->unk14 == 1) {
                                player->fadeSongName = temp_s0;
                            }
                        }
                    }
                }
            } else {
                retVal = 2;
            }
        } else {
            retVal = 4;
        }
    } else {
        retVal = 3;
    }
    return retVal;
}

void func_8004DC80(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    func_8004DCB8(&s, 0);
}

INCLUDE_ASM(s32, "28910_len_5090", func_8004DCB8);

INCLUDE_ASM(s32, "28910_len_5090", func_8004DE2C);

INCLUDE_ASM(void, "28910_len_5090", func_8004DFD4, SndGlobals* arg0);

s32 func_8004E0F4(SongUpdateEvent* update) {
    BGMPlayer* player;
    s32 retVal = 0;

    if (update->songName != 0) {
        player = snd_get_player_with_song_name(update->songName);
        if (player != NULL) {
            func_80053B04(&player->fadeInfo, update->duration, update->finalVolume);
        }
        else {
            retVal = 2;
        }
    } else {
        retVal = 3;
    }
    return retVal;
}

void func_8004E158(BGMPlayer* player, s32 arg1, s32 arg2, SndGlobals* arg3) {
    s16 i;

    player->data = arg3;
    func_8004E880(player, 0x2625A, 0x30);
    player->unk_48 = 0x8000;
    player->masterTempo = 0x3CF0;
    player->masterVolume = 0x7F000000;
    player->unk_22B = 1;
    player->unk_14 = 0;
    player->unk_18 = 0;
    player->songName = 0;
    player->fadeSongName = 0;
    player->unk_58 = 0;
    player->unk_5A = 0;
    player->unk_68 = 0;
    player->unk_6C = 0;
    player->unk_70 = 0;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->masterTranspose = 0;
    player->unk_20E = 0;
    player->unk_220 = 0;
    player->unk_204 = 0;
    player->unk_232 = 0;
    player->unk_221 = 0;
    player->unk_234 = arg1;
    player->unk_235 = arg2;
    player->unk_168 = 0;
    player->unk_222 = 0;
    player->unk_223 = 0;
    player->unk_22A = 0;
    player->unk_22C = 0;
    player->unk_D0 = 1.0f;
    player->unk_22D = 0;
    player->unk_22F = 2;
    player->unk_230 = 3;
    player->unk_22E = 0;
    player->unk_231 = 4;

    for (i = 0; i < ARRAY_COUNT(player->unk_25C); i++) {
        BGMPlayerTrack* temp = &player->unk_25C[i];

        temp->subTrackVolume = 0;
        temp->unk_28 = 0;
        temp->subTrackCoarseTune = 0;
        temp->subTrackFineTune = 0;
        temp->subTrackPan = 0;
        temp->subTrackReverb = 0;
        temp->unk_44 = 0;
        temp->unk_58 = 0;
        temp->segTrackVolume = 0x7F;
        temp->unk_4C = 0;

        if (i < ARRAY_COUNT(player->unk_238)) {
            player->unk_238[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(player->unk_85C); i++) {
        UnkAl24* temp = &player->unk_85C[i];

        temp->unk_08 = 0;
        temp->unk_0A = 0;
        temp->unk_0C = 0;
        temp->unk_14 = 0;
        temp->unk_16 = 0;
        temp->unk_17 = 0;
    }

    func_80053AEC(&player->fadeInfo, 0x7FFF);
    func_80055110(player);
}

INCLUDE_ASM(s32, "28910_len_5090", func_8004E344);

void snd_update_bgm_fade(BGMPlayer* player) {
    player->fadeInfo.fadeTime--;

    if (player->fadeInfo.fadeTime != 0) {
        player->fadeInfo.currentVolume.s32 += player->fadeInfo.fadeStep;
    } else {
        player->fadeInfo.currentVolume.s32 = player->fadeInfo.endVolume << 16;

        if (player->fadeInfo.fpFadeCallback != NULL) {
            player->fadeInfo.fpFadeCallback();
        }

        if (player->fadeSongName != 0) {
            func_8004DC80(player->fadeSongName);
        } else if (player->fadeInfo.currentVolume.s32 == 0) {
            func_8004DAA8(player);
        }
    }
    func_8004E444(player);
}

void func_8004E444(BGMPlayer* arg0) {
    u16 mult = (arg0->fadeInfo.currentVolume.u16 * arg0->fadeInfo.unk_10.u16) >> 15;
    s32 i;

    for (i = 0; i < 4; i++) {
        s8 temp = arg0->unk_4C[i];

        if (temp < 0) {
            return;
        }
        func_80053A98(temp, mult, arg0->unk_48);
    }
}

INCLUDE_ASM(s16, "28910_len_5090", func_8004E4B8, BGMPlayer* player);

INCLUDE_ASM(s32, "28910_len_5090", snd_initialize_bgm_player, BGMPlayer* player);

INCLUDE_ASM(s32, "28910_len_5090", func_8004E844);

void func_8004E880(BGMPlayer* player, s32 freq, s32 framerate) {
    u32 A;

    A = 10434782 / (u32)framerate;

    if (A > 500000) {
        A = 500000;
    } else if (A < 80000) {
        A = 80000;
    }    
    if (A < freq) {
        freq = A;
    }
    player->unkFrequency = freq;
    player->unk_0C = A;
    player->unk_10 = A;
    player->bgmKhz = A / 1000;
}

void func_8004E904(BGMPlayer* player) {
    u16 continueReading = TRUE;
    u32 cmd;

    player->masterTempoFadeDelta = 0;
    player->masterTempoFadeTime = 0;
    while (continueReading) {
        cmd = *player->unk_68++;
        if(cmd == 0) {
            player->unk_221 = 4;
            continueReading = FALSE;
        } else {
            switch(cmd >> 0xC) {
                case 0x10000:
                    func_8004EAD4(player, cmd);
                    player->unk_221 = 1;
                    continueReading = FALSE;
                    break;
                case 0x30000:
                    break;
                case 0x40000:
                    continueReading = FALSE;
                    break;
                case 0x50000:
                    func_8004EA34(player, cmd);
                    break;
                case 0x60000:
                    if (!(player->unk_223 & 1)) {
                        func_8004EA34(player, cmd);
                    }
                    break;
                case 0x70000:
                    if (player->unk_223 & 1) {
                        func_8004EA34(player, cmd);
                    }
                    break;
                default:
                    continueReading = FALSE;
                    break;
            }
        }
    }
}

INCLUDE_ASM(s32, "28910_len_5090", func_8004EA34);

INCLUDE_ASM(s32, "28910_len_5090", func_8004EAD4);

INCLUDE_ASM(s32, "28910_len_5090", func_8004EC04);

INCLUDE_ASM(s32, "28910_len_5090", func_8004EC68);

void snd_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 unk_D4 = player->seqCmdArgs.u16[0];
    s32 temp_v0;

    player->masterTempoBPM = unk_D4;
    temp_v0 = snd_bpm_to_tempo(player, unk_D4);
    player->masterTempo = temp_v0;
    player->unkFrequency = temp_v0 * 10;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
}

s32 snd_bpm_to_tempo(BGMPlayer* player, u32 tempo) {
    u32 unk_20A = player->bgmKhz;
    u32 ret = tempo;

    ret *= player->unk_D0;

    if (unk_20A < ret) {
        ret = unk_20A;
    } else if (ret == 0) {
        ret = 1;
    }

    return ret * 100;
}

void snd_BGMCmd_E1_MasterVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 volume = player->seqCmdArgs.u8[0] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    player->masterVolume = volume;
    player->masterVolumeFadeTime = 0;
    player->masterVolumeFadeVolume = 0;
    player->masterVolumeFadeDelta = 0;
    player->unk_21A = 1;
    track->volumeChanged = 1;
}

void snd_BGMCmd_E2_MasterTranspose(BGMPlayer* player, BGMPlayerTrack* track) {
    player->masterTranspose = (s8)player->seqCmdArgs.u8[0] * 100;
}

void snd_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->data->unk_40[player->unk_235].unk_00 = player->seqCmdArgs.u8[0];
    player->data->unk_40[player->unk_235].unk_01 = 1;
}

void snd_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 unk_D4 = player->seqCmdArgs.u8[0];
    u32 temp_v1 = player->unk_4C[unk_D4];

    if ((unk_D4 < 4) && (temp_v1 < 0x80)) {
        if (player->data->unk_40[temp_v1].unk_00 != player->seqCmdArgs.u8[1]) {
            player->data->unk_40[temp_v1].unk_00 = player->seqCmdArgs.u8[1];
            player->data->unk_40[temp_v1].unk_01 = 1;
        }
        player->unk_224[unk_D4] = player->seqCmdArgs.u8[1];
    }
}

void snd_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 tempo = snd_bpm_to_tempo(player, player->seqCmdArgs.u16[1]);

    if (time <= 0) {
        time = 1;
    }

    player->masterTempoFadeTime = time;
    player->masterTempoFadeTempo = tempo;
    player->masterTempoFadeDelta = (tempo - player->masterTempo) / time;
}

void snd_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 volume = player->seqCmdArgs.u8[2] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (time <= 0) {
        time = 1;
    }

    player->masterVolumeFadeTime = time;
    player->masterVolumeFadeVolume = volume;
    player->masterVolumeFadeDelta = (volume - player->masterVolume) / time;
}

void snd_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, BGMPlayerTrack* track) {
    track->unk_44 = player->seqCmdArgs.u8[1];
    track->unk_0C = func_80053BE8(player->data, player->seqCmdArgs.u8[0], track->unk_44, track->unk_10);
}

void snd_BGMCmd_E9_SubTrackVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    u32 volume = arg0->seqCmdArgs.u8[0] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    track->subTrackVolume = volume;
    track->volumeChanged = TRUE;
}

void snd_BGMCmd_F6_TrackVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 time = player->seqCmdArgs.u16[0];
    s32 volume = player->seqCmdArgs.u8[2] & 0x7F;

    if (volume != 0) {
        volume = volume << 0x18;
    }

    if (volume != track->subTrackVolume) {
        if (time <= 0) {
            time = 1;
        }

        track->subTrackVolumeFadeTime = time;
        track->subTrackVolumeFadeVolume = volume;
        track->subTrackVolumeFadeDelta = (volume - track->subTrackVolume) / time;
    }
}

void snd_BGMCmd_EA_SubTrackPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.u8[0] & 0x7F;
    track->unk_57 = 0;
    track->panChanged = TRUE;
}

void snd_BGMCmd_EB_SubTrackReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackReverb = player->seqCmdArgs.u8[0] & 0x7F;
    track->reverbChanged = TRUE;
}

void snd_BGMCmd_EC_SegTrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackVolume = player->seqCmdArgs.u8[0] & 0x7F;
    track->volumeChanged = TRUE;
}

void snd_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackCoarseTune = (s8)player->seqCmdArgs.u8[0] * 100;
}

void snd_BGMCmd_EE_SubTrackFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackFineTune = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_EF_SegTrackTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackTune = player->seqCmdArgs.u16[0];
    track->tuneChanged = TRUE;
}

void snd_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloAmount = player->seqCmdArgs.u8[0];
    track->trackTremoloSpeed = player->seqCmdArgs.u8[1];
    track->trackTremoloTime = player->seqCmdArgs.u8[2];
}

void snd_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloSpeed = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_F2_TrackTremoloTime(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = player->seqCmdArgs.u8[0];
}

void snd_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = 0;
}

void snd_BGMCmd_F4(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->seqCmdArgs.u8[0] & 0x7F;
    track->unk_57 = player->seqCmdArgs.u8[1] & 0x7F;
}

INCLUDE_ASM(void, "28910_len_5090", snd_BGMCmd_F5_TrackVoice, BGMPlayer* player, BGMPlayerTrack* track);

void snd_BGMCmd_F7_SubTrackReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 temp_v0 = player->seqCmdArgs.u8[0];
    u8 temp_v1 = player->unk_4C[temp_v0];

    if ((temp_v0 < 4) && ((s8)temp_v1 >= 0)) {
        track->subtrackReverbType = temp_v1;
    } else {
        track->subtrackReverbType = player->unk_235;
    }
}

void snd_BGMCmd_FD(BGMPlayer* player, BGMPlayerTrack* track) {
    func_800560BC(player->unk_234, track->unk_5C, player->seqCmdArgs.u32 >> 8);
}

void snd_BGMCmd_FE(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 temp = player->seqCmdArgs.u16[0] + (s32)player->unk_64;

    track->unk_3E = player->seqCmdArgs.u8[2];
    track->unk_04 = track->bgmReadPos;
    track->bgmReadPos = temp;
}

INCLUDE_ASM(void, "28910_len_5090", snd_BGMCmd_FC_Jump, BGMPlayer* player, BGMPlayerTrack* track);

INCLUDE_ASM(void, "28910_len_5090", snd_BGMCmd_FF, BGMPlayer* player, BGMPlayerTrack* track);

void snd_BGMCmd_NOP(BGMPlayer* player, BGMPlayerTrack* track) {
}

u8 func_80050568(BGMPlayer* player, u8 arg1, u8 arg2) {
    s32 temp_v0 = player->unk_50;
    s32 a = (temp_v0 >> 7);
    s32 b = (temp_v0 >> 2);
    s32 c = (a + b) & 1;
    s32 d = (temp_v0 >> 8) & 0x3F;
    s32 e = (temp_v0 << 4) & 0xC0;
    s32 f = d + e;
    s32 g = arg1;
    s32 retVal;
    
    if (c != 0) {
        retVal = g + ((arg2 * f) >> 8);
    } else {
        retVal = g - ((arg2 * f) >> 8);
    }
    if (retVal < 0) {
        retVal = 0;
    } else if (retVal >= 0x80) {
        retVal = 0x7F;
    }
    return retVal;
}

s16 func_800505E4(s32 arg0, s32 arg1, u8 arg2) {
    s32 a = (arg0 >> 4);
    s32 b = (arg0 >> 1);
    s32 c = (a + b) & 1;
    s32 d = (arg0 >> 6) & 0xF;
    s32 e = (arg0 << 2) & 0xF0;
    s32 f = d + e;
    s32 retVal;

    if (c != 0) {
        s32 g = arg2;
        s32 h = 5 * f;
        retVal = arg1 + ((g * h) >> 8);
    } else {
        s32 g = arg2;
        s32 h = 5 * f;
        retVal = arg1 - ((g * h) >> 8);
    }
    return retVal;
}

u8 func_80050654(s32 arg0, u8 arg1, u8 arg2) {
    s32 a = (arg0 >> 8) & 0x1F; // bitmask 0x1F00
    s32 b = arg0 & 0xE0;
    s32 c = a + b;
    return (arg1 * (0x8000 - arg2 * (c)));
}

u8 func_8005068C(s32 arg0, u8 arg1, u8 arg2) {
    s32 a = (arg0 >> 7) & 7; // bitmask 380
    s32 b = (arg0 << 3) & 0xF8; // bitmask 1F
    s32 c = a + b;
    return (arg1 * (0x8000 - (arg2 * c)));
}

void func_800506C8(s32 songName, u32 arg1) {
    BGMPlayer* player;
    BGMPlayerTrack* track;
    s32 changed = FALSE;
    u8 lowArg1 = arg1 & 0xFF;
    s32 i;
    
    if (songName != 0) {
        player = snd_get_player_with_song_name(songName);
        if ((player != NULL) && (player->unk_16C != arg1)) {
            player->unk_16C = arg1;
            if (player->unk_170 != lowArg1) {
                player->unk_170 = arg1;
                changed = TRUE;
            }
            player->unk_171 = (arg1 >> 0x18) & 0x7F;
            for (i = 0; i < ARRAY_COUNT(player->unk_25C); i++) {
                track = &player->unk_25C[i];
                if (changed) {
                    track->unk_4D = 1;
                }
                track->unk_4E = 1;
            }
        }
    }
}

void func_80050770(BGMPlayer* player, f32 arg1) {
    if (arg1 > 2.0) {
        arg1 = 2.0f;
    } else if (arg1 < 0.25) {
        arg1 = 0.25f;
    }

    player->unk_D0 = arg1;
    player->masterTempo = snd_bpm_to_tempo(player, player->masterTempoBPM);
    player->unkFrequency = player->masterTempo * 10;
    player->masterTempoFadeTime = 0;
    player->masterTempoFadeTempo = 0;
    player->masterTempoFadeDelta = 0;
}

void func_80050818(BGMPlayer* player, s32 arg1) {
    if (arg1 > 1200) {
        arg1 = 1200;
    } else if (arg1 < -2400) {
        arg1 = -2400;
    }

    player->unk_20E = arg1;
}

void func_8005083C(BGMPlayer* player, s32 arg1, s16 arg2, s8 arg3) {
    BGMPlayerTrack* track = &player->unk_25C[arg1];

    if (track->bgmReadPos != 0) {
        player->seqCmdArgs.u16[0] = arg2;
        player->seqCmdArgs.u8[2] = arg3;
        snd_BGMCmd_F6_TrackVolumeFade(player, track);
    }
}

void func_8005087C(BGMPlayer* player, s32* arg1, s32 arg2) {
    player->unk_204 = arg1;
    player->unk_232 = arg2;
}

void func_80050888(BGMPlayer* player, BGMPlayerTrack* track, s32 target, s32 duration) {
    if (target != 0) {
        target = (target << 8) | 0xFF;
    }
    if (duration <= 0) {
        duration = 1;
    } else if (duration > 1000) {
        duration = 1000;
    }
    if (target == track->unk2C) {
        track->unk36 = 0;
        return;
    }
    track->unk36 = duration;
    track->unk34 = target;
    track->unk30 = ((target << 0x10) - track->unk2C) / duration;
}

INCLUDE_ASM(s32, "28910_len_5090", func_80050900);

INCLUDE_ASM(s32, "28910_len_5090", func_80050970);
