#include "common.h"
#include "audio.h"

s32 D_80078DB0 = FALSE;
u16 D_80078DB4 = 0;
u16 D_80078DB6 = 0;

// lists of data:
//  u8 trackIdx
//  u8 volume?
// repeated until idx = 0
u8 D_80078DB8[] = {
    2, 94,
    3, 80,
    4, 100,
    5, 84,
    0
};
u8 D_80078DC4[] = {
    2, 100,
    3, 110,
    4, 90,
    0
};
u8 D_80078DCC[] = {
    2, 95,
    0
};
u8 D_80078DD0[] = { 
    5, 70,
    6, 90,
    7, 90,
    8, 100,
    0
};
u8 D_80078DDC[] = { 
    5, 0,
    6, 0,
    7, 0,
    8, 0,
    9, 0,
    10, 0,
    11, 0,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
u8 D_80078DF8[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 0,
    10, 0,
    11, 0,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
u8 D_80078E14[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 126,
    10, 88,
    11, 100,
    12, 0,
    13, 0,
    14, 0,
    15, 0,
    16, 0,
    0
};
u8 D_80078E30[] = {
    5, 100,
    6, 102,
    7, 88,
    8, 110,
    9, 126,
    10, 88,
    11, 100,
    12, 100,
    13, 106,
    14, 100,
    15, 100,
    16, 110,
    0
};

void func_80055050(ALHeap* heap) {
    D_80078DB4 = 1;
    D_80078DB0 = FALSE;
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
                        snd_start_song_variation(filename, (arg0 >> 0xC) & 3);
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
            player = gBGMPlayerA;
        } else if (playerSwitch == 2) {
            player = gBGMPlayerB;
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

void snd_start_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    snd_enqueue_sfx_event(soundManager, soundID, vol, 0, pan);
}

void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    if (pitchShift > 2400) {
        pitchShift = 2400;
    } else if (pitchShift < -2400) {
        pitchShift = -2400;
    }

    snd_enqueue_sfx_event(soundManager, soundID, vol, pitchShift, pan);
}

void snd_adjust_sound(s32 soundID, u8 volume, u8 pan) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    snd_enqueue_sfx_event(soundManager, soundID | 0x1000, vol, 0, pan);
}

void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift) {
    SoundManager* soundManager = gSoundManager;
    s16 vol = volume << 8;

    if (vol != 0) {
        vol |= 0xFF;
    }

    if (pan > 0x7F) {
        pan = 0x7F;
    }

    if (pitchShift > 2400) {
        pitchShift = 2400;
    } else if (pitchShift < -2400) {
        pitchShift = -2400;
    }

    snd_enqueue_sfx_event(soundManager, soundID | 0x1000, vol, pitchShift, pan);
}

void snd_stop_sound(s32 soundID) {
    SoundManager* soundManager = gSoundManager;

    snd_enqueue_sfx_event(soundManager, soundID | 0x8000, 0, 0, 0);
}

void func_800553F4(void) {
    gSoundManager->unk_168 = 1;
}

void snd_start_sound_raw(s32 soundID, s16 volume, s16 pitchShift, s32 pan) {
    SoundManager* soundManager = gSoundManager;

    snd_enqueue_sfx_event(soundManager, soundID, volume, pitchShift, pan);
}

s32 snd_ambient_80055448(s32 arg0) {
    return func_80053F80(arg0);
}

s32 snd_ambient_80055464(s32 arg0, s32 arg1) {
    if (func_80050C30(arg0) == 0) {
        func_80050CA0(arg0, arg1);
    }
}

AuResult snd_ambient_quick_fade_out(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050EF0(arg0);
    }

    return ret;
}

AuResult snd_ambient_slow_fade_out(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050F64(arg0, arg1);
    }

    return ret;
}

// clears ambient sounds?
AuResult snd_ambient_8005553C(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E18(arg0, arg1);
    }

    return ret;
}

AuResult snd_ambient_80055590(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E84(arg0, arg1);
    }

    return ret;
}

AuResult snd_ambient_800555E4(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret != 0) {
        return ret;
    }

    return func_80051050(arg0);;
}

AuResult snd_ambient_80055618(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C54(arg0, arg1);
    }

    return ret;
}

AuResult snd_ambient_8005566C(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050FD0(arg0, arg1, arg2);
    }

    return ret;
}

AuResult snd_ambient_800556D0(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 1);
    }

    return ret;
}

AuResult snd_ambient_80055718(s32 arg0) {
    s32 ret  = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 0);
    }

    return ret;
}

void snd_ambient_80055760(s32 arg0) {
    u32 i;
    s32 lim = 4;

    D_80078DB6 = 0xFF;

    for (i = 0; i < lim; i++) {
        if (snd_ambient_80055464(i, 0) != 0) {
            return;
        }
    }

    snd_ambient_80055848(arg0);
}

s32 snd_ambient_800557CC(s32 arg0) {
    u32 i;
    s32 lim = 4;
    s32 error;

    for (i = 0; i < lim; i++) {
        if (i == D_80078DB6) {
            error = snd_ambient_slow_fade_out(i, arg0);
        } else {
            error = snd_ambient_quick_fade_out(i);
        }

        if (error != 0) {
            break;
        }
    }
    return error;
}

s32 snd_ambient_80055848(s32 arg0) {
    s32 lim = 4;
    s32 error = 0;

    if (arg0 != D_80078DB6) {
        u32 i;

        for (i = 0; i < lim; i++) {
            if (i == arg0) {
                error = snd_ambient_80055718(arg0);
            } else {
                error = snd_ambient_800556D0(i);
            }

            if (error != 0) {
                break;
            }
        }

        if (error == 0) {
            D_80078DB6 = arg0;
        }
    }

    return error;
}

s32 snd_load_song(s32 songID, s32 playerIndex) {
    s32* currentTrackData;
    BGMPlayer* songPlayer;

    snd_get_sequence_player_and_track(playerIndex, &currentTrackData, &songPlayer);

    if (currentTrackData != NULL) {
        return snd_load_song_files(songID, currentTrackData, songPlayer);
    } else {
        return AU_ERROR_NULL_SONG_NAME;
    }
}

AuResult snd_start_song(s32 songName) {
    AuResult error;
    SongUpdateEvent s;

    D_80078DB0 = TRUE;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 127;
    s.finalVolume = 127;
    s.variation = 0;
    s.unk14 = 0;
    error = snd_dispatch_bgm_player_event(&s);
    D_80078DB0 = FALSE;

    return error;
}

AuResult snd_start_song_variation(s32 songName, s32 variation) {
    AuResult error;
    SongUpdateEvent s;

    D_80078DB0 = TRUE;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 127;
    s.finalVolume = 127;
    s.variation = variation;
    s.unk14 = 0;
    error = snd_dispatch_bgm_player_event(&s);
    D_80078DB0 = FALSE;

    return error;
}

AuResult func_800559C4(s32 songName) {
    return func_8004DA0C(songName);
}

void func_800559E0(void) {
    func_8004DA74();
}

AuResult func_800559FC(s32 songName) {
    return snd_is_song_playing(songName);
}

AuResult snd_set_song_variation_fade(s32 songName, s32 variation, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult error;
    SongUpdateEvent s;

    D_80078DB0 = TRUE;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = variation;
    s.unk14 = 0;
    error = snd_dispatch_bgm_player_event(&s);
    D_80078DB0 = FALSE;

    return error;
}

AuResult snd_set_song_fade(s32 songName, s32 fadeInTime, s32 startVolume, s32 endVolume) {
    AuResult error;
    SongUpdateEvent s;

    D_80078DB0 = TRUE;
    s.songName = songName;
    s.duration = fadeInTime;
    s.startVolume = startVolume;
    s.finalVolume = endVolume;
    s.variation = 0;
    s.unk14 = 0;
    error = snd_dispatch_bgm_player_event(&s);
    D_80078DB0 = FALSE;

    return error;
}

AuResult snd_set_song_variation_fade_time(s32 songName, s32 fadeTime, s32 variation) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = fadeTime;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = variation;
    s.unk14 = 0;
    return func_8004DB4C(&s);
}

AuResult func_80055AF0(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 0);
}

AuResult func_80055B28(s32 songName) {
    AuResult error;
    SongUpdateEvent s;

    D_80078DB0 = TRUE;
    s.songName = songName;
    s.duration = 2000;
    s.startVolume = 1;
    s.finalVolume = 127;
    s.variation = 0;
    s.unk14 = 0;
    error = func_8004DE2C(&s);
    D_80078DB0 = FALSE;

    return error;
}

AuResult func_80055B80(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 0;
    return func_8004DCB8(&s, 1);
}

AuResult func_80055BB8(s32 songName, s32 fadeTime) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = fadeTime;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DB4C(&s);
}

AuResult func_80055BF0(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DCB8(&s, 0);
}

AuResult func_80055C2C(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 0;
    s.startVolume = 0;
    s.finalVolume = 0;
    s.variation = 0;
    s.unk14 = 1;
    return func_8004DE2C(&s);
}

AuResult func_80055C64(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 500;
    s.finalVolume = 0x2000;
    return func_8004E0F4(&s);
}

AuResult func_80055C94(s32 songName) {
    SongUpdateEvent s;
    s.songName = songName;
    s.duration = 500;
    s.finalVolume = 0x7FFF;
    return func_8004E0F4(&s);
}

AuResult snd_set_song_variation(s32 songName, s32 variation) {
    SongUpdateEvent s;
    s.songName = songName;
    s.variation = variation;
    return func_80050970(&s);
}

AuResult func_80055CE8(s32 songName, s32** outTrackData, BGMPlayer** outPlayer) {
    AuGlobals* globals = gSoundGlobals;
    s32* trackData;
    s32 error;

    error = AU_RESULT_OK;
    trackData = globals->currentTrackData[0];
    if (songName == trackData[2]) {
        *outPlayer = gBGMPlayerA;
        *outTrackData = trackData;
    } else {
        trackData = globals->currentTrackData[1];
        if (songName == trackData[2]) {
            *outPlayer = gBGMPlayerB;
            *outTrackData = trackData;
        } else {
            error = AU_ERROR_1;
        }
    }
    return error;
}

AuResult func_80055D38(s32 songName, f32 arg1) {
    BGMPlayer* bgmPlayer;
    s32* trackData;
    s32 error;

    error = func_80055CE8(songName, &trackData, &bgmPlayer);

    if (error == AU_RESULT_OK) {
        func_80050770(bgmPlayer, arg1);
    }

    return error;
}

AuResult func_80055D8C(s32 songName, s32 arg1) {
    BGMPlayer* bgmPlayer;
    s32* trackData;
    s32 error;

    error = func_80055CE8(songName, &trackData, &bgmPlayer);

    if (error == AU_RESULT_OK) {
        func_80050818(bgmPlayer, arg1);
    }

    return error;
}

AuResult func_80055DDC(s32 songName, s32 arg1) {
    BGMPlayer* bgmPlayer;
    s32* trackData;
    s32 error;

    error = func_80055CE8(songName, &trackData, &bgmPlayer);

    if (error == AU_RESULT_OK) {
        u8* temp_v0 = func_80055EB4(arg1);

        if (temp_v0 != NULL) {
            func_8005087C(bgmPlayer, temp_v0, TRUE);
        } else {
            error = AU_ERROR_11;
        }
    }

    return error;
}

AuResult func_80055E48(s32 songName, s32 arg1) {
    BGMPlayer* bgmPlayer;
    s32* trackData;
    s32 error;

    error = func_80055CE8(songName, &trackData, &bgmPlayer);

    if (error == AU_RESULT_OK) {
        u8* temp_v0 = func_80055EB4(arg1);

        if (temp_v0 != NULL) {
            func_8005087C(bgmPlayer, temp_v0, FALSE);
        } else {
            error = AU_ERROR_11;
        }
    }

    return error;
}

u8* func_80055EB4(s32 arg0) {
    u8* ret = NULL;

    switch (arg0) {
        case 0:
            ret = D_80078DB8;
            break;
        case 1:
            ret = D_80078DC4;
            break;
        case 2:
            ret = D_80078DCC;
            break;
        case 3:
            ret = D_80078DD0;
            break;
        case 4:
            ret = D_80078DDC;
            break;
        case 5:
            ret = D_80078DF8;
            break;
        case 6:
            ret = D_80078E14;
            break;
        case 7:
            ret = D_80078E30;
            break;
    }

    return ret;
}

static const f32 padding[] = {0.0f};

AuResult func_80055F58(s32 arg0, u32 arg1, u32 arg2) {
    BGMPlayer* player;
    s32* trackData;
    s32 error = func_80055CE8(arg0, &trackData, &player);

    if (error == AU_RESULT_OK) {
        if (arg2 > 0x7F) {
            arg2 = 0x7F;
        }
        if (arg1 > 0xF) {
            arg1 = 0xF;
        }
        func_8005083C(player, arg1, 0x60, arg2);
    }
    return error;
}

AuResult func_80055FD4(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0);
}

AuResult func_80055FF0(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0x3F);
}

AuResult func_8005600C(s32 arg0, s32 arg1) {
    return func_80055F58(arg0, arg1, 0x7F);
}

void bgm_set_proximity_mix_far(s32 songName, s32 mix) {
    snd_set_bgm_proximity_mix(songName, (u8)mix);
}

void bgm_set_proximity_mix_near(s32 songName, s32 mix) {
    snd_set_bgm_proximity_mix(songName, (u8)mix | 0x57000000);
}

void bgm_set_proximity_mix_full(s32 songName, s32 mix) {
    snd_set_bgm_proximity_mix(songName, (u8)mix | 0x7F000000);
}

void func_8005608C(u32** arg0, s32* arg1) {
    AuGlobals* temp_v0 = gSoundGlobals;

    *arg0 = temp_v0->unk_arr_94;
    *arg1 = temp_v0->unk_98;
}

void func_800560A8(void) {
    gSoundGlobals->unk_9C = 1;
}

void func_800560BC(s32 arg0, s32 arg1, s32 arg2) {
    AuGlobals* globals = gSoundGlobals;

    if (globals->unk_98 < 16) {
        *globals->unk_90++ = ((arg0 << 0x1C) + ((arg1 & 0xF) << 0x18) + arg2);
        globals->unk_98++;
    }
}

void func_8005610C(void) {
    AuGlobals* globals = gSoundGlobals;
    s32* buf = globals->unk_arr_94;
    s32 i = 15;
    
    do {
        *buf++ = 0;
    } while(i-- != 0);

    globals->unk_98 = 0;
    globals->unk_9C = 0;
    globals->unk_90 = globals->unk_arr_94;
}

void func_80056144(UnkFuncAl arg0, s32 arg1) {
    gSoundGlobals->unk_A4[arg1] = arg0;
}

void audio_set_stereo(void) {
    func_80056D5C(1);
    func_80054DA8(0);
}

void audio_set_mono(void) {
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
    func_8004BA54(gSoundManager, 0);
}

void func_80056228(void) {
    func_8004BA54(gSoundManager, 1);
}
