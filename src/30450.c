#include "common.h"
#include "audio.h"

s32 D_80078DB0 = 0;
u16 D_80078DB4 = 0;
u16 D_80078DB6 = 0;

// chunks of data, not sure what
s32 D_80078DB8[] = { 0x025E0350, 0x04640554, 0x00000000, };
s32 D_80078DC4[] = { 0x0264036E, 0x045A0000, };
s32 D_80078DCC[] = { 0x025F0000, };
s32 D_80078DD0[] = { 0x0546065A, 0x075A0864, 0x00000000, };
s32 D_80078DDC[] = { 0x05000600, 0x07000800, 0x09000A00, 0x0B000C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078DF8[] = { 0x05640666, 0x0758086E, 0x09000A00, 0x0B000C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078E14[] = { 0x05640666, 0x0758086E, 0x097E0A58, 0x0B640C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078E30[] = { 0x05640666, 0x0758086E, 0x097E0A58, 0x0B640C64, 0x0D6A0E64, 0x0F64106E, 0x00000000, 0x00000000, };

void func_80055050(void) {
    D_80078DB4 = 1;
    D_80078DB0 = 0;
}

void func_80055068(u32 arg0) {
    u16 temp_a0 = D_80078DB4;
    u32 temp_v1 = arg0 & 0xF;

    if (temp_a0 == 1) {
        switch (temp_v1) {
            case 2:
            case 3:
                break;
            case 4:
                snd_start_sound_with_shift(arg0 >> 4, 0, 0, 0);
                break;
            case 1:
                if (temp_v1 == temp_a0) {
                    s32 filename = snd_load_song((arg0 >> 4) & 0xFF, 0);

                    if (filename > ASCII_TO_U32('0', ' ', ' ', '\0')) {
                        func_80055970(filename, (arg0 >> 0xC) & 3);
                    }
                }
                break;
        }
    }
}

void func_80055110(BGMPlayer* player) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(player->unk_238); i++) {
        player->unk_238[i] = 0;
    }

    player->unk_25B = 0;
    player->unk_25A = 0;
    player->unk_259 = 0;
    player->unk_258 = 0;
}

void func_8005513C(u32 arg0) {
    BGMPlayer* player = NULL;
    u32 playerSwitch = arg0 & 0xF;

    if (playerSwitch != 0) {
        if (playerSwitch == 1) {
            player = D_8009A664;
        } else if (playerSwitch == 2) {
            player = D_8009A5FC;
        }

        if (player != NULL) {
            u32 temp;

            if (player->unk_258 < 8) {
                temp = player->unk_25A;

                player->unk_238[temp] = arg0 >> 4;

                temp++;
                if (temp >= 8) {
                    temp = 0;
                }
                player->unk_25A = temp;

                player->unk_258++;
            } else {
                temp = player->unk_25B + 1;

                if (temp > 99) {
                    temp = 99;
                }
                player->unk_25B = temp;
            }
        }
    }
}

void snd_start_sound(s32 soundID, u8 volume, s8 pan) {
    SoundManager* sym = D_8009A640;
    s16 a1temp = volume * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (pan < 0) {
        pan = 0x7F;
    }

    snd_enqueue_sfx_event(sym, soundID, a1temp, 0, pan);
}

void snd_start_sound_with_shift(s32 soundID, u8 volume, s8 pan, s16 pitchShift) {
    SoundManager* sym = D_8009A640;
    s16 a1temp = volume * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (pan < 0) {
        pan = 0x7F;
    }

    if (pitchShift > 0x960) {
        pitchShift = 0x960;
    } else if (pitchShift < -0x960) {
        pitchShift = -0x960;
    }

    snd_enqueue_sfx_event(sym, soundID, a1temp, pitchShift, pan);
}

void snd_adjust_sound(s32 soundID, u8 volume, s8 pan) {
    SoundManager* sym = D_8009A640;
    s16 a1temp = volume * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (pan < 0) {
        pan = 0x7F;
    }

    snd_enqueue_sfx_event(sym, soundID | 0x1000, a1temp, 0, pan);
}

void snd_adjust_sound_with_shift(s32 soundID, u8 volume, s8 pan, s16 pitchShift) {
    SoundManager* sym = D_8009A640;
    s16 a1temp = volume * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (pan < 0) {
        pan = 0x7F;
    }

    if (pitchShift > 0x960) {
        pitchShift = 0x960;
    } else if (pitchShift < -0x960) {
        pitchShift = -0x960;
    }

    snd_enqueue_sfx_event(sym, soundID | 0x1000, a1temp, pitchShift, pan);
}

void snd_stop_sound(s32 soundID) {
    snd_enqueue_sfx_event(D_8009A640, soundID | 0x8000, 0, 0, 0);
}

void func_800553F4(void) {
    D_8009A640->unk_168 = 1;
}

void snd_start_sound_raw(s32 soundID, s16 volume, s16 pitchShift, s32 pan) {
    snd_enqueue_sfx_event(D_8009A640, soundID, volume, pitchShift, pan);
}

s32 func_80055448(s32 arg0) {
    return func_80053F80(arg0);
}

s32 func_80055464(s32 arg0, s32 arg1) {
    if (func_80050C30(arg0) == 0) {
        func_80050CA0(arg0, arg1);
    }
}

s32 func_800554A4(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050EF0(arg0);
    }

    return ret;
}

s32 func_800554E8(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050F64(arg0, arg1);
    }

    return ret;
}

s32 func_8005553C(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E18(arg0, arg1);
    }

    return ret;
}

s32 func_80055590(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E84(arg0, arg1);
    }

    return ret;
}

void func_800555E4(s32 arg0) {
    if (func_80050C30(arg0) == 0) {
        func_80051050(arg0);
    }
}

s32 func_80055618(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C54(arg0, arg1);
    }

    return ret;
}

s32 func_8005566C(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050FD0(arg0, arg1, arg2);
    }

    return ret;
}

s32 func_800556D0(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 1);
    }

    return ret;
}

s32 func_80055718(s32 arg0) {
    s32 ret  = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 0);
    }

    return ret;
}

void func_80055760(s32 arg0) {
    u32 i;
    s32 lim = 4;

    D_80078DB6 = 0xFF;

    for (i = 0; i < lim; i++) {
        if (func_80055464(i, 0) != 0) {
            return;
        }
    }

    func_80055848(arg0);
}

s32 func_800557CC(s32 arg0) {
    u32 i;
    s32 lim = 4;
    s32 phi_v1;

    for (i = 0; i < lim; i++) {
        if (i == D_80078DB6) {
            phi_v1 = func_800554E8(i, arg0);
        } else {
            phi_v1 = func_800554A4(i);
        }

        if (phi_v1 != 0) {
            break;
        }
    }
    return phi_v1;
}

s32 func_80055848(s32 arg0) {
    s32 lim = 4;
    s32 phi_v1 = 0;

    if (arg0 != D_80078DB6) {
        u32 i;

        for (i = 0; i < lim; i++) {
            if (i == arg0) {
                phi_v1 = func_80055718(arg0);
            } else {
                phi_v1 = func_800556D0(i);
            }

            if (phi_v1 != 0) {
                break;
            }
        }

        if (phi_v1 == 0) {
            D_80078DB6 = arg0;
        }
    }

    return phi_v1;
}

s32 snd_load_song(s32 songID, s32 playerIndex) {
    s32* currentTrackData;
    BGMPlayer* songPlayer;

    snd_get_sequence_player_and_track(playerIndex, &currentTrackData, &songPlayer);

    if (currentTrackData != NULL) {
        return snd_load_song_files(songID, currentTrackData, songPlayer);
    } else {
        return 3;
    }
}

INCLUDE_ASM(s32, "30450", func_8005591C);

INCLUDE_ASM(s32, "30450", func_80055970);

s32 func_800559C4(UNK_TYPE arg0) {
    return func_8004DA0C(arg0);
}

void func_800559E0(void) {
    func_8004DA74();
}

void func_800559FC(void) {
    func_8004DAE0();
}

INCLUDE_ASM(s32, "30450", func_80055A18);

INCLUDE_ASM(s32, "30450", func_80055A6C);

INCLUDE_ASM(s32, "30450", func_80055ABC);

INCLUDE_ASM(s32, "30450", func_80055AF0);

INCLUDE_ASM(s32, "30450", func_80055B28);

INCLUDE_ASM(s32, "30450", func_80055B80);

INCLUDE_ASM(s32, "30450", func_80055BB8);

INCLUDE_ASM(s32, "30450", func_80055BF0);

INCLUDE_ASM(s32, "30450", func_80055C2C);

INCLUDE_ASM(s32, "30450", func_80055C64);

INCLUDE_ASM(s32, "30450", func_80055C94);

INCLUDE_ASM(s32, "30450", func_80055CC4);

s32 func_80055CE8(s32 songName, s32* arg1, BGMPlayer** player);
// We need to figure out what currentTrackData is a list of
#ifdef NON_MATCHING
s32 func_80055CE8(s32 songName, s32* arg1, BGMPlayer** player) {
    UnkAl19E0* temp_a3 = D_8009A5C0;
    s32 ret = 0;

    if (songName == temp_a3->currentTrackData[0][2]) {
        *arg1 = temp_a3->currentTrackData[0];
        *player = D_8009A664;
    } else if (songName == temp_a3->currentTrackData[1][2]) {
        *arg1 = temp_a3->currentTrackData[1];
        *player = D_8009A5FC;
    } else {
        ret = 1;
    }
    return ret;
}
#else
INCLUDE_ASM(s32, "30450", func_80055CE8, s32 songName, s32* arg1, BGMPlayer** player);
#endif

s32 func_80055D38(s32 songName, f32 arg1) {
    s32 ret;
    s32 unkArg1;
    BGMPlayer* bgmPlayer;

    ret = func_80055CE8(songName, &unkArg1, &bgmPlayer);

    if (ret == 0) {
        func_80050770(bgmPlayer, arg1);
    }

    return ret;
}

s32 func_80055D8C(s32 songName, s32 arg1) {
    s32 ret;
    s32 unkArg1;
    BGMPlayer* bgmPlayer;

    ret = func_80055CE8(songName, &unkArg1, &bgmPlayer);

    if (ret == 0) {
        func_80050818(bgmPlayer, arg1);
    }

    return ret;
}

s32 func_80055DDC(s32 songName, s32 arg1) {
    s32 ret;
    s32 unkArg1;
    BGMPlayer* bgmPlayer;

    ret = func_80055CE8(songName, &unkArg1, &bgmPlayer);

    if (ret == 0) {
        s32* temp_v0 = func_80055EB4(arg1);

        if (temp_v0 != NULL) {
            func_8005087C(bgmPlayer, temp_v0, 1);
        } else {
            ret = 11;
        }
    }

    return ret;
}

s32 func_80055E48(s32 songName, s32 arg1) {
    s32 ret;
    s32 unkArg1;
    BGMPlayer* bgmPlayer;

    ret = func_80055CE8(songName, &unkArg1, &bgmPlayer);

    if (ret == 0) {
        s32* temp_v0 = func_80055EB4(arg1);

        if (temp_v0 != NULL) {
            func_8005087C(bgmPlayer, temp_v0, 0);
        } else {
            ret = 11;
        }
    }

    return ret;
}

s32* func_80055EB4(s32 arg0) {
    s32* ret = NULL;

    switch (arg0) {
        case 0:
            ret = &D_80078DB8;
            break;
        case 1:
            ret = &D_80078DC4;
            break;
        case 2:
            ret = &D_80078DCC;
            break;
        case 3:
            ret = &D_80078DD0;
            break;
        case 4:
            ret = &D_80078DDC;
            break;
        case 5:
            ret = &D_80078DF8;
            break;
        case 6:
            ret = &D_80078E14;
            break;
        case 7:
            ret = &D_80078E30;
            break;
    }

    return ret;
}

s32 func_80055F58(s32 arg0, u32 arg1, u32 arg2) {
    s32* subroutine_arg4;
    s32* subroutine_arg5;
    s32 temp_s2 = func_80055CE8(arg0, &subroutine_arg4, &subroutine_arg5);

    if (temp_s2 == 0) {
        if (arg2 > 0x7F) {
            arg2 = 0x7F;
        }
        if (arg1 > 0xF) {
            arg1 = 0xF;
        }
        func_8005083C(subroutine_arg5, arg1, 0x60, (u8)arg2); // todo remove cast when func is defined
    }
    return temp_s2;
}

s32 func_80055FD4(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0);
}

s32 func_80055FF0(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0x3F);
}

s32 func_8005600C(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0x7F);
}

s32 func_80056028(s32 arg0, u8 arg1) {
    return func_800506C8(arg0, arg1);
}

s32 func_80056044(s32 arg0, u8 arg1) {
    return func_800506C8(arg0, arg1 | 0x57000000);
}

s32 func_80056068(s32 arg0, u8 arg1) {
    return func_800506C8(arg0, arg1 | 0x7F000000);
}

void func_8005608C(s32* arg0, s32* arg1) {
    UnkAl19E0* temp_v0 = D_8009A5C0;

    *arg0 = temp_v0->unk_94;
    *arg1 = temp_v0->unk_98;
}

void func_800560A8(void) {
    D_8009A5C0->unk_9C = 1;
}

INCLUDE_ASM(s32, "30450", func_800560BC);

INCLUDE_ASM(void, "30450", func_8005610C, void);

void func_80056144(UnkFuncAl arg0, s32 arg1) {
    D_8009A5C0->unk_A4[arg1] = arg0;
}

void func_8005615C(void) {
    func_80056D5C(1);
    func_80054DA8(0);
}

void func_80056180(void) {
    func_80056D5C(0);
    func_80054DA8(1);
}

void func_800561A4(s32 arg0) {
    func_80054CE0(1, arg0);
}

void func_800561C4(s32 arg0) {
    func_80054CE0(16, arg0);
}

void func_800561E4(s32 arg0) {
    func_80054D74(16, arg0);
}

void func_80056204(void) {
    func_8004BA54(D_8009A640, 0);
}

void func_80056228(void) {
    func_8004BA54(D_8009A640, 1);
}
