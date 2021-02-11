#include "common.h"

extern Gfx D_80074210[];
extern Gfx D_80074230[];

s8 D_80074020 = 1;
s8 D_80074021 = 5;

GameStatus gGameStatus = {0};

GameStatus* gGameStatusPtr[1] = { &gGameStatus };

s16 D_800741A0 = 0;

s16 D_800741A2 = 0;

s32 D_800741A4 = 0;

s32 D_800741A8[] = { 0x00010000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, };

u16 gMatrixListPos = 0;

u16 D_800741F2 = 0;

u16 gCurrentDisplayContextIndex = 0;

s32 D_800741F8[] = { 0x00000000, 0x00000000, 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, 0xE200001C, 0x0F0A4000, 0xFCFFFFFF, 0xFFFE793C, 0xE3001801, 0x00000040, 0xDF000000, 0x00000000, 0xDC080008, 0x80074200, 0xD9000000, 0x00000000, 0xD9FFFFFF, 0x00200405, 0xD7000000, 0x00000000, 0xDF000000, 0x00000000, 0x00000000, 0x00000000, };


INCLUDE_ASM(void, "code_1b40_len_20b0", step_game_loop);

INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_task_background);

INCLUDE_ASM(s32, "code_1b40_len_20b0", gfx_draw_frame);

#ifdef NON_MATCHING
void load_engine_data(void) {
    GameStatus* phi_s0;
    s32 i;

    dma_copy(code_code_FEE30_ROM_START, code_code_FEE30_ROM_END, code_code_FEE30_VRAM);
    dma_copy(code_code_759B0_ROM_START, code_code_759B0_ROM_END, code_code_759B0_VRAM);
    dma_copy(code_code_E79B0_ROM_START, code_code_E79B0_ROM_END, code_code_E79B0_VRAM);
    dma_copy(code_code_102610_ROM_START, code_code_102610_ROM_END, code_code_102610_VRAM);
    dma_copy(code_code_A5DD0_ROM_START, code_code_A5DD0_ROM_END, code_code_A5DD0_VRAM);
    dma_copy(D_0010CC10, D_0010CC10_end, D_802EB3D0); // new segment required to fix this
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

//weird ordering issue
#ifdef NON_MATCHING
void func_80027088(s32 arg0) {
    switch (arg0) {
        case 0:
            D_8009A5D8 = arg0;
            *D_8009A650 &= ~0xF00;
            resume_all_group(3);
            break;
        case 1:
            D_8009A5D8 = arg0;
            *D_8009A650 &= ~0xE00;
            *D_8009A650 |= 0x100;
            suspend_all_group(1);
            break;
        case 2:
            D_8009A5D8 = arg0;
            *D_8009A650 &= ~0xC00;
            *D_8009A650 |= 0x300;
            suspend_all_group(2);
            break;
        case 3:
            D_8009A5D8 = arg0;
            *D_8009A650 &= ~0x800;
            *D_8009A650 |= 0x700;
            suspend_all_group(2);
            break;
        case 4:
            D_8009A5D8 = arg0;
            *D_8009A650 |=  0xF00;
            break;
    }
}
#else
INCLUDE_ASM(void, "code_1b40_len_20b0", func_80027088, s32 arg0);
#endif

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
