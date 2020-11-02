#include "common.h"
#include "map.h"

void transition_music_volume_to(s16 volume);

/// If the given song ID is present in gSongsUsingVariationFlag, returns the current
/// map's `songVariation & 1` value. Otherwise, returns -1.
///
/// @see gSongsUsingVariationFlag
/// @returns -1: no override; 0: override to variation 0; 1 override to variation 1
s32 get_song_variation_override_for_cur_map(SongID songID) {
    u32 i = 0;
    Area* areas = gAreas;
    SongID* allowed = gSongsUsingVariationFlag;

    for (i = 0; i < ARRAY_COUNT(gSongsUsingVariationFlag); i++) {
        if (allowed[i] == songID) {
            Map* map = &areas[GAME_STATUS->areaID].maps[GAME_STATUS->mapID];

            return map->songVariation & 1;
        }
    }

    return -1;
}

void func_8014A498(void) {
    MusicPlayer* src; // TODO: remove this temp when .data section for this file (incl. D_8014F6F0) is set up
    s32 i;

    for (i = 0; i < 2; i++) {
        MusicPlayer* musicPlayers = gMusicPlayers;
        musicPlayers[i] = *(src = &D_8014F6F0);
    }

    gMusicTargetVolume = 8;
    gMusicUnkVolume2 = 8;
    gMusicCurrentVolume = 8;
    func_800561A4(8);
}

void func_8014A52C(void) {
    gMusicTargetVolume = 8;
    gMusicUnkVolume2 = 8;
}

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014A548);

s32 _set_music_track(s32 playerIndex, SongID songID, s32 variation, s32 fadeOutTime, s16 volume) {
    GameStatus* gameStatus = GAME_STATUS;

    if (gameStatus->demoState != 0) {
        return 1;
    } else {
        // TODO: these two lines likely a MUSIC_PLAYER(idx) macro
        MusicPlayer* musicPlayers = gMusicPlayers;
        MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

        if (!gameStatus->musicEnabled) {
            func_800559C4(musicPlayer->unk_18);
            musicPlayer->flags &= ~1;

            return 1;
        } else {
            s32 override = get_song_variation_override_for_cur_map(songID);
            if (override >= 0) {
                variation = override;
            }

            if (musicPlayer->songID == songID && musicPlayer->variation == variation) {
                transition_music_volume_to(volume);

                if (musicPlayer->flags & 4) {
                    func_80055B80(musicPlayer->unk_18);
                    musicPlayer->flags &= ~4;
                }

                return 2;
            }

            gMusicUnkVolume = volume;
            musicPlayer->songID = songID;
            musicPlayer->variation = variation;
            musicPlayer->fadeOutTime = fadeOutTime;
            musicPlayer->unk_02 = 1;
            musicPlayer->flags &= ~2;

            return 1;
        }
    }
}

s32 set_music_track(s32 playerIndex, SongID songID, s32 variation, s32 fadeOutTime, s16 volume) {
    MusicPlayer* musicPlayers = gMusicPlayers;

    musicPlayers[playerIndex].flags &= ~8;

    return _set_music_track(playerIndex, songID, variation, fadeOutTime, volume);
}

s32 func_8014A964(s32 playerIndex, SongID songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5) {
    GameStatus* gameStatus = GAME_STATUS;

    if (gameStatus->demoState != 0) {
        return 1;
    } else {
        MusicPlayer* musicPlayers = gMusicPlayers;
        MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

        if (!gameStatus->musicEnabled) {
            func_800559C4(musicPlayer->unk_18);
            musicPlayer->flags &= ~1;

            return 1;
        } else {
            s32 defaultVariation = get_song_variation_override_for_cur_map(songID);
            if (defaultVariation >= 0) {
                variation = defaultVariation;
            }

            musicPlayer->fadeInTime = fadeInTime;
            musicPlayer->unk_0C = arg4;
            musicPlayer->unk_0E = arg5;
            musicPlayer->songID = songID;
            musicPlayer->variation = variation;
            musicPlayer->flags |= 0x20;
            musicPlayer->unk_02 = 1;
            musicPlayer->flags &= ~2;

            return 1;
        }
    }
}

s32 func_8014AA54(s32 playerIndex, s32 arg1, s16 arg2) {
    MusicPlayer* musicPlayers = gMusicPlayers;
    MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

    if (!(musicPlayer->flags & 1)) {
        return 0;
    }

    if (!(musicPlayer->flags & 2)) {
        return 0;
    }

    switch (arg2) {
        case 0:
            func_80056028(musicPlayer->unk_18, arg1);
            break;
        case 1:
            func_80056044(musicPlayer->unk_18, arg1);
            break;
        case 2:
            func_80056068(musicPlayer->unk_18, arg1);
            break;
    }

    return 1;
}

s32 func_8014AB0C(s32 playerIndex, s16 arg1) {
    MusicPlayer* musicPlayers = gMusicPlayers;
    MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

    if (!(musicPlayer->flags & 1)) {
        return 0;
    }

    return func_80055DDC(musicPlayer->unk_18, arg1);
}

s32 func_8014AB60(s32 playerIndex, s16 arg1) {
    MusicPlayer* musicPlayers = gMusicPlayers;
    MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

    if (!(musicPlayer->flags & 1)) {
        return 0;
    }

    return func_80055E48(musicPlayer->unk_18, arg1);
}

s32 func_8014ABB4(s32 playerIndex, s16 arg1) {
    MusicPlayer* musicPlayers = gMusicPlayers;
    MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

    if (!(musicPlayer->flags & 1)) {
        return 0;
    }

    return func_80055CC4(musicPlayer->unk_18, arg1);
}

s32 func_8014AC08(void) {
    set_music_track(0, -1, 0, 250, 8);
    set_music_track(1, -1, 0, 250, 8);

    return 1;
}

void func_8014AC5C(void) {
    gMusicUnkVolume2 = 4;
}

void func_8014AC70(void) {
    gMusicUnkVolume2 = 8;
}

void transition_music_volume_to(s16 volume) {
    gMusicTargetVolume = volume;
}

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AC94);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AD40);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014ADA4);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014ADF8);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AE6C);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AEF8);

void func_8014AF8C(s32 arg0, s32 arg1) {
    MusicPlayer* musicPlayer = &gMusicPlayers[0];
    musicPlayer->unk_1C = arg0;
    musicPlayer->unk_20 = arg1;
}

void func_8014AFA0(void) {
}
