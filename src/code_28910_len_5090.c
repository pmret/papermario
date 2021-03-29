#include "audio.h"

INCLUDE_ASM(void, "code_28910_len_5090", func_8004D510, BGMPlayer* arg0);

// Return values are being pushed into v0 in the wrong place
// May depend on data decomp
#ifdef NON_MATCHING
UnkAlA9C* snd_get_player_with_song_name(s32 songString) {
    UnkAl19E0* temp_v1 = D_8009A664->unk_00;

    if (songString == temp_v1->unk_5C[2]) {
        return D_8009A664;
    }
    if (songString == temp_v1->unk_60[2]) {
        return D_8009A5FC;
    }
    return NULL;
}
#else
INCLUDE_ASM(BGMPlayer*, "code_28910_len_5090", snd_get_player_with_song_name, s32 songString);
#endif

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004D7E0);

s32 func_8004DA0C(UNK_TYPE arg0) {
    s32 ret = 0;

    if (arg0 != 0) {
        BGMPlayer* unknown;

        do {
            unknown = snd_get_player_with_song_name(arg0);
        } while (0);

        do {
            if (unknown == NULL) {
                ret = 2;
            } else if (arg0 == unknown->songName) {
                func_8004DAA8(unknown);
                ret = 0;
            }
        } while (0);
    } else {
        ret = 3;
    }

    return ret;
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DA74);

void func_8004DAA8(BGMPlayer* arg0) {
    if (arg0->unk_221 != 0) {
        arg0->unk_221 = 4;
        arg0->unk_10 = 1;
        arg0->unkFrequency = 1;
        func_80053A18(&arg0->fadeInfo);
    }
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DAE0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DB28);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DB4C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DC80);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DCB8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DE2C);

INCLUDE_ASM(void, "code_28910_len_5090", func_8004DFD4, UnkAl19E0* arg0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E0F4);

void func_8004E158(BGMPlayer* arg0, s32 arg1, s32 arg2, UnkAl19E0* arg3) {
    s16 i;

    arg0->data = arg3;
    func_8004E880(arg0, 0x2625A, 0x30);
    arg0->unk_48 = 0x8000;
    arg0->unk_B0 = 0x3CF0;
    arg0->unk_C0 = 0x7F000000;
    arg0->unk_22B = 1;
    arg0->unk_14 = 0;
    arg0->unk_18 = 0;
    arg0->songName = 0;
    arg0->fadeSongName = 0;
    arg0->unk_58 = 0;
    arg0->unk_5A = 0;
    arg0->unk_68 = 0;
    arg0->unk_6C = 0;
    arg0->unk_70 = 0;
    arg0->unk_BC = 0;
    arg0->unk_B8 = 0;
    arg0->unk_B4 = 0;
    arg0->unk_CC = 0;
    arg0->unk_C8 = 0;
    arg0->unk_C4 = 0;
    arg0->unk_20C = 0;
    arg0->unk_20E = 0;
    arg0->unk_220 = 0;
    arg0->unk_204 = 0;
    arg0->unk_232 = 0;
    arg0->unk_221 = 0;
    arg0->unk_234 = arg1;
    arg0->unk_235 = arg2;
    arg0->unk_168 = 0;
    arg0->unk_222 = 0;
    arg0->unk_223 = 0;
    arg0->unk_22A = 0;
    arg0->unk_22C = 0;
    arg0->unk_D0 = 1.0f;
    arg0->unk_22D = 0;
    arg0->unk_22F = 2;
    arg0->unk_230 = 3;
    arg0->unk_22E = 0;
    arg0->unk_231 = 4;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_25C); i++) {
        BGMPlayerTrack* temp = &arg0->unk_25C[i];

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

        if (i < ARRAY_COUNT(arg0->unk_238)) {
            arg0->unk_238[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(arg0->unk_85C); i++) {
        UnkAl24* temp = &arg0->unk_85C[i];

        temp->unk_08 = 0;
        temp->unk_0A = 0;
        temp->unk_0C = 0;
        temp->unk_14 = 0;
        temp->unk_16 = 0;
        temp->unk_17 = 0;
    }

    func_80053AEC(&arg0->fadeInfo, 0x7FFF);
    func_80055110(arg0);
}


INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E344);

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

void func_8004E444(BGMPlayer *arg0) {
    u16 mult = (arg0->fadeInfo.currentVolume.u16 * arg0->unk_3C) >> 15;
    s32 i;

    for (i = 0; i < 4; i++) {
        s8 temp = arg0->unk_4C[i];

        if (temp < 0) {
            return;
        }
        func_80053A98(temp, mult, arg0->unk_48);
    }
}

INCLUDE_ASM(s16, "code_28910_len_5090", func_8004E4B8, BGMPlayer* player);

INCLUDE_ASM(s32, "code_28910_len_5090", snd_initialize_bgm_player, BGMPlayer* player);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E844);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E880);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E904);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EA34);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EAD4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC04);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC68);

void snd_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track) {
    u32 unk_D4 = player->unk_D4.u16;
    s32 temp_v0;

    player->unk_208 = unk_D4;
    temp_v0 = snd_bpm_to_tempo(player, unk_D4);
    player->unk_B0 = temp_v0;
    player->unkFrequency = temp_v0 * 10;
    player->unk_BC = 0;
    player->unk_B8 = 0;
    player->unk_B4 = 0;
}

s32 snd_bpm_to_tempo(BGMPlayer* player, u32 tempo) {
    u32 unk_20A = player->unk_20A;
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
    s32 unk_D4 = player->unk_D4.u8[0] & 0x7F;

    if (unk_D4 != 0) {
        unk_D4 = unk_D4 << 0x18;
    }

    player->unk_C0 = unk_D4;
    player->unk_CC = 0;
    player->unk_C8 = 0;
    player->unk_C4 = 0;
    player->unk_21A = 1;
    track->volumeChanged = 1;
}

void snd_BGMCmd_E2_MasterTranspose(BGMPlayer* player, BGMPlayerTrack* track) {
    player->unk_20C = (s8)player->unk_D4.u8[0] * 100;
}

void snd_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track) {
    player->data->unk_40[player->unk_235].unk_00 = player->unk_D4.u8[0];
    player->data->unk_40[player->unk_235].unk_01 = 1;
}

void snd_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 unk_D4 = player->unk_D4.u8[0];
    u32 temp_v1 = player->unk_4C[unk_D4];

    if ((unk_D4 < 4) && (temp_v1 < 0x80)) {
        if (player->data->unk_40[temp_v1].unk_00 != player->unk_D4.u8[1]) {
            player->data->unk_40[temp_v1].unk_00 = player->unk_D4.u8[1];
            player->data->unk_40[temp_v1].unk_01 = 1;
        }
        player->unk_224[unk_D4] = player->unk_D4.u8[1];
    }
}

void snd_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 unk_D4 = player->unk_D4.u16;
    s32 temp_a0 = snd_bpm_to_tempo(player, player->unk_D6.u16);
    s32 temp_v0;

    if (unk_D4 <= 0) {
        unk_D4 = 1;
    }
    temp_v0 = (temp_a0 - player->unk_B0) / unk_D4;

    player->unk_BC = unk_D4;
    player->unk_B8 = temp_a0;
    player->unk_B4 = temp_v0;
}

void snd_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = player->unk_D4.u16;
    temp_a2 = player->unk_D6.u8[0] & 0x7F;

    if (temp_a2 != 0) {
        temp_a2 = temp_a2 << 0x18;
    }

    if (temp_a1 <= 0) {
        temp_a1 = 1;
    }

    player->unk_CC = temp_a1;
    player->unk_C8 = temp_a2;
    player->unk_C4 = (temp_a2 - player->unk_C0) / temp_a1;
}

// Not sure about types
#ifdef NON_MATCHING
void snd_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, UnkAl60* track) {
    u8 temp_v1 = player->unk_D4.u16;

    track->unk_44 = temp_v1;
    track->unk_0C = func_80053BE8(player->unk_00, player->unk_D4.u8[0], temp_v1, &track->unk_10);
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_E8_TrackOverridePatch, BGMPlayer* player, BGMPlayerTrack* track);
#endif

void snd_BGMCmd_E9_SubTrackVolume(BGMPlayer* arg0, BGMPlayerTrack* track) {
    u32 unk_D4 = arg0->unk_D4.u8[0] & 0x7F;

    if (unk_D4 != 0) {
        unk_D4 = unk_D4 << 0x18;
    }

    track->subTrackVolume = unk_D4;
    track->volumeChanged = 1;
}

// Type shenanigans
#ifdef NON_MATCHING
void snd_BGMCmd_F6_TrackVolumeFade(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 temp_a2 = player->unk_D4.u16;
    s32 temp_a0 = player->unk_D6.u8[0] & 0x7F;
    s32 phi_a2;

    if (temp_a0 != 0) {
        temp_a0 = temp_a0 << 0x18;
    }

    if (temp_a0 != track->unk_18) {


        if (temp_a2 <= 0) {
            phi_a2 = 1;
        } else {
            phi_a2 = temp_a2;
        }
        track->unk_24[0] = phi_a2;
        track->unk_20 = temp_a0;
        track->unk_1C = (temp_a0 - track->unk_18) / phi_a2;
    }
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_F6_TrackVolumeFade, BGMPlayer* player, BGMPlayerTrack* track);
#endif

void snd_BGMCmd_EA_SubTrackPan(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->unk_D4.u8[0] & 0x7F;
    track->unk_57 = 0;
    track->panChanged = 1;
}

void snd_BGMCmd_EB_SubTrackReverb(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackReverb = player->unk_D4.u8[0] & 0x7F;
    track->reverbChanged = 1;
}

void snd_BGMCmd_EC_SegTrackVolume(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackVolume = player->unk_D4.u8[0] & 0x7F;
    track->volumeChanged = 1;
}

void snd_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackCoarseTune = (s8)player->unk_D4.u8[0] * 100;
}

void snd_BGMCmd_EE_SubTrackFineTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackFineTune = player->unk_D4.u8[0];
}

void snd_BGMCmd_EF_SegTrackTune(BGMPlayer* player, BGMPlayerTrack* track) {
    track->segTrackTune = player->unk_D4.u16;
    track->tuneChanged = 1;
}

void snd_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloAmount = player->unk_D4.u8[0];
    track->trackTremoloSpeed = player->unk_D4.u8[1];
    track->trackTremoloTime = player->unk_D6.u8[0];
}

void snd_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloSpeed = player->unk_D4.u8[0];
}

void snd_BGMCmd_F2_TrackTremoloTime(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = player->unk_D4.u8[0];
}

void snd_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track) {
    track->trackTremoloTime = 0;
}

void snd_BGMCmd_F4(BGMPlayer* player, BGMPlayerTrack* track) {
    track->subTrackPan = player->unk_D4.u8[0] & 0x7F;
    track->unk_57 = player->unk_D4.u8[1] & 0x7F;
}

INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_F5_TrackVoice, BGMPlayer* player, BGMPlayerTrack* track);

void snd_BGMCmd_F7_SubTrackReverbType(BGMPlayer* player, BGMPlayerTrack* track) {
    u8 temp_v0 = player->unk_D4.u8[0];
    u8 temp_v1 = player->unk_4C[temp_v0];

    if ((temp_v0 < 4) && ((s8)temp_v1 >= 0)) {
        track->subtrackReverbType = temp_v1;
    } else {
        track->subtrackReverbType = player->unk_235;
    }
}

// unk_D4 type shenanigans
#ifdef NON_MATCHING
void snd_BGMCmd_FD(UnkAlA9C* player, UnkAl60* track) {
    func_800560BC(player->unk_234, track->unk_5C, player->unk_D4.u16 >> 8);
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_FD, BGMPlayer* player, BGMPlayerTrack* track);
#endif

void snd_BGMCmd_FE(BGMPlayer* player, BGMPlayerTrack* track) {
    s32 temp = player->unk_D4.u16 + player->unk_64;

    track->unk_3E = player->unk_D6.u8[0];
    track->unk_04 = track->bgmReadPos;
    track->bgmReadPos = temp;
}

INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_FC_Jump, BGMPlayer* player, BGMPlayerTrack* track);

INCLUDE_ASM(void, "code_28910_len_5090", snd_BGMCmd_FF, BGMPlayer* player, BGMPlayerTrack* track);

void snd_BGMCmd_NOP(BGMPlayer* player, BGMPlayerTrack* track) {
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050568);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800505E4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050654);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005068C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800506C8, s32 arg0, s32 arg1);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050770);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050818);

void func_8005083C(BGMPlayer* arg0, s32 arg1, s16 arg2, s8 arg3) {
    BGMPlayerTrack* temp_a1 = &arg0->unk_25C[arg1];

    if (temp_a1->bgmReadPos != 0) {
        arg0->unk_D4.u16 = arg2;
        arg0->unk_D6.u8[0] = arg3;
        snd_BGMCmd_F6_TrackVolumeFade(arg0, temp_a1);
    }
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005087C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050888);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050900);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050970);
