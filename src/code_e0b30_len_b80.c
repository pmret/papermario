#include "common.h"


void func_8014AC84(s16 volume);

INCLUDE_ASM(s32, "code_e0b30_len_b80", get_default_variation_for_song);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014A498);

void func_8014A52C(void) {
    D_80159AE2 = 0x08;
    D_80159AE4 = 0x08;
}

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014A548);

s32 _set_music_track(s32 playerIndex, s32 songID, s32 variation, s32 unk, s16 volume) {
    GameStatus* gameStatus = GAME_STATUS;

    if (gameStatus->demoState != 0) {
        return 1;
    } else {
        MusicPlayer* musicPlayers = &gMusicPlayers;
        MusicPlayer* musicPlayer = &musicPlayers[playerIndex];

        if (!gameStatus->musicEnabled) {
            func_800559C4(musicPlayer->unk_18);
            musicPlayer->flags &= ~1;

            return 1;
        } else {
            s32 defaultVariation = get_default_variation_for_song(songID);
            if (defaultVariation >= 0) {
                variation = defaultVariation;
            }

            if (musicPlayer->songID == songID && musicPlayer->variation == variation) {
                func_8014AC84(volume); // transition volume to?

                if (musicPlayer->flags & 4) {
                    func_80055B80(musicPlayer->unk_18);
                    musicPlayer->flags &= ~4;
                }

                return 2;
            }

            gMusicVolume = volume;
            musicPlayer->songID = songID;
            musicPlayer->variation = variation;
            musicPlayer->fadeOutTime = unk;
            musicPlayer->unk_02 = 1;
            musicPlayer->flags &= ~2;

            return 1;
        }
    }
}

void set_music_track(s32 playerIndex, s32 songID, s32 variation, s32 unk, s16 volume) {
    MusicPlayer* musicPlayers = &gMusicPlayers;

    musicPlayers[playerIndex].flags &= ~8;

    _set_music_track(playerIndex, songID, variation, unk, volume);
}

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014A964);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AA54);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AB0C);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AB60);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014ABB4);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AC08);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AC5C);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AC70);

INCLUDE_ASM(void, "code_e0b30_len_b80", func_8014AC84, s16 volume);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AC94);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AD40);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014ADA4);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014ADF8);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AE6C);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AEF8);

INCLUDE_ASM(s32, "code_e0b30_len_b80", func_8014AF8C);

void func_8014AFA0(void) {
}
