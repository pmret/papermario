#include "common.h"

void set_curtain_scale_goal(f32 arg0);
void set_curtain_fade_goal(f32 arg0);
void intro_logos_set_fade_alpha(s16 new_alpha);
void intro_logos_set_fade_color(s16 arg0);

#ifdef NON_MATCHING
void begin_state_intro(void) {
    s8 unk_A8;

    GAME_STATUS->loadMenuState = 0;

    set_curtain_scale_goal(1.0f);
    set_curtain_fade_goal(0.3f);

    unk_A8 = GAME_STATUS->unk_A8;
    switch (unk_A8) {
        case 0:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0xFF;
            D_800A0956 = 0x10;
            D_800A0958 = 4;
            D_800A0960 = 0;
            D_800A095A = 0xD0;
            D_800A095C = 0xD0;
            D_800A095E = 0xD0;
            D_800A0964 = 0;

            do {
                GameStatus* gameStatus = GAME_STATUS;

                // hos_05 (Star Sanctuary)
                gameStatus->areaID = 5;
                gameStatus->mapID = 5;
                gameStatus->entryID = 3;
            } while (0);

            break;
        case 1:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0;
            D_800A0956 = 0xC;
            D_800A0958 = 4;
            D_800A0960 = unk_A8;
            D_800A095A = 0;
            D_800A095C = 0;
            D_800A095E = 0;
            D_800A0964 = 0;

            // FIXME: regalloc issues
            do {
                GameStatus* gameStatus = GAME_STATUS;

                // hos_04 (Outside the Sanctuary)
                gameStatus->areaID = 5;
                gameStatus->mapID = 4;
                gameStatus->entryID = 4;
            } while (0);

            break;
        default:
            intro_logos_set_fade_alpha(0);
            intro_logos_set_fade_color(0xD0);

            {
                GameStatus* gameStatus = GAME_STATUS;
                u8* mystery = &D_800779B0;

                gameStatus->unk_A8 = -1;

                D_800A0956 = 6;
                D_800A0958 = 6;

                ++*mystery;
                if (*mystery >= 4) {
                    *mystery = 0;
                }

                D_800A0964 = 3;
            }
    }

    func_80137DA4(D_800A0963, (f32)D_800A0954);
    func_80137E10(1, D_800A095B, D_800A095D, D_800A095F);

    intro_logos_update_fade();
}
#else
INCLUDE_ASM(s32, "code_11a50_len_7a0", begin_state_intro);
#endif

INCLUDE_ASM(s32, "code_11a50_len_7a0", step_intro);

INCLUDE_ASM(s32, "code_11a50_len_7a0", func_80036DE0);
