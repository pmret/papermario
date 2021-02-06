#include "common.h"

extern Gfx D_80074210[];
extern Gfx D_80074230[];

extern int D_000759B0[];
extern int D_000759B0_end[]; // A55D0

extern int D_000A5DD0[];
extern int D_000A5DD0_end[]; // E79B0

extern int D_000E79B0[];
extern int D_000E79B0_end[]; // FEE30

extern int D_000FEE30[];
extern int D_000FEE30_end[]; // 102610

extern int D_00102610[];
extern int D_00102610_end[]; // 10CC10

extern int D_0010CC10[];
extern int D_0010CC10_end[]; // 10F1B0

extern int D_802DBD40[];
extern int D_800DC500[];
extern int D_802C3000[];
extern int D_802E0D90[];
extern int D_8010F6D0[];
extern int D_802EB3D0[];

extern u8 D_80074021;
extern s32 D_8009A5D8;

INCLUDE_ASM(s32, "code_1b40_len_20b0", step_game_loop);

INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_task_background);

INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_draw_frame);

#ifdef NON_MATCHING
void load_engine_data(void) {
    GameStatus* phi_s0;
    s32 i;

    dma_copy(D_000FEE30, D_000FEE30_end, D_802DBD40);
    dma_copy(D_000759B0, D_000759B0_end, D_800DC500);
    dma_copy(D_000E79B0, D_000E79B0_end, D_802C3000);
    dma_copy(D_00102610, D_00102610_end, D_802E0D90);
    dma_copy(D_000A5DD0, D_000A5DD0_end, D_8010F6D0);
    dma_copy(D_0010CC10, D_0010CC10_end, D_802EB3D0);
    D_8009A650[0] = 0;
    phi_s0 = *gGameStatusPtr;
    GAME_STATUS->unk_79 = 0;
    GAME_STATUS->musicEnabled = 1;
    phi_s0->unk_148 = 0;
    GAME_STATUS->unk_7C = 1;
    GAME_STATUS->unk_A8 = -1;
    GAME_STATUS->unk_AA = 0;
    GAME_STATUS->unk_81 = 0;
    GAME_STATUS->unk_82 = -8;
    GAME_STATUS->unk_83 = 4;
    D_8009A5D8 = 0;
    GAME_STATUS->unk_75 = GAME_STATUS->unk_13C = 0;
    D_80074021 = 5;
    GAME_STATUS->unk_168 = 0;
    fio_init_flash();
    func_80028838();
    general_heap_create();
    func_8011D890();
    func_801230B8();
    clear_script_list();
    create_cameras_a();
    clear_player_status();
    func_802DD8F8(0);
    clear_entity_models();
    func_8011E224();
    clear_model_data();
    func_80148040();
    use_default_background_settings();
    clear_character_set();
    clear_printers();
    func_80112B98();
    func_800384BC();
    func_80141100();
    clear_trigger_data();
    func_80110CB8(0);
    clear_player_data();
    func_8003E338();
    clear_transition_stencil();
    clear_effect_data();
    clear_saved_variables();
    clear_item_entity_data();
    func_8014A498();
    reset_ambient_sounds();
    func_80149618();
    clear_windows();
    curtains_init();
    poll_rumble();

    phi_s0 = GAME_STATUS;
    for (i = 0; i < 4; i++) {
        phi_s0->unk_50[i] = 3;
        phi_s0->unk_48[i] = 0xC;
    }

    D_8009A650[0] |= 8;
    set_game_mode(0);
}
#else
INCLUDE_ASM(s32, "code_1b40_len_20b0", load_engine_data);
#endif

INCLUDE_ASM(void, "code_1b40_len_20b0", func_80027088, s32 arg0);

s32 func_80027190(void) {
    return D_8009A5D8;
}

#ifdef NON_MATCHING
void gfx_init_state(void) {
    gSPSegment(gMasterGfxPos++, 0x00, 0x0);
    gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(&D_80074230));
    gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(&D_80074210));
}
#else
INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_init_state);
#endif

// void gfx_init_state(void) {
//     gSPSegment(gMasterGfxPos++, 0x00, 0x00000000);
//     gSPDisplayList(gMasterGfxPos++, D_00074230);
//     gSPDisplayList(gMasterGfxPos++, D_00074210);
// }

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_800271FC);

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_8002725C);

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_80027600);

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_80027774);

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_800279B4);

INCLUDE_ASM(s32, "code_1b40_len_20b0", func_80027BAC);

INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_draw_background);
