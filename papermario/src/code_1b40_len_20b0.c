#include "common.h"

extern Gfx D_00074210[];
extern Gfx D_00074230[];
extern Gfx* D_8009A66C[1];

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

extern s32 D_8009A650[1];

void dma_copy(void*, void*, void*);

INCLUDE_ASM(code_1b40_len_20b0, step_game_loop);

INCLUDE_ASM(code_1b40_len_20b0, func_800269EC);

INCLUDE_ASM(code_1b40_len_20b0, gfx_draw_frame);

INCLUDE_ASM(code_1b40_len_20b0, load_engine_data);
/*void load_engine_data(void) {
    game_status *phi_s0;
    s32 i;

    dma_copy(D_000FEE30, D_000FEE30_end, D_802DBD40);
    dma_copy(D_000759B0, D_000759B0_end, D_800DC500);
    dma_copy(D_000E79B0, D_000E79B0_end, D_802C3000);
    dma_copy(D_00102610, D_00102610_end, D_802E0D90);
    dma_copy(D_000A5DD0, D_000A5DD0_end, D_8010F6D0);
    dma_copy(D_0010CC10, D_0010CC10_end, D_802EB3D0);
    D_8009A650[0] = 0;
    phi_s0 = *gGameStatusPtr;
    (*gGameStatusPtr)->unk_79 = 0;
    (*gGameStatusPtr)->musicEnabled = 1;
    phi_s0->unk_148 = 0;
    (*gGameStatusPtr)->unk_7C = 1;
    (*gGameStatusPtr)->unk_A8 = -1;
    (*gGameStatusPtr)->unk_AA = 0;
    (*gGameStatusPtr)->unk_81 = 0;
    (*gGameStatusPtr)->unk_82 = -8;
    (*gGameStatusPtr)->unk_83 = 4;
    D_8009A5D8 = 0;
    (*gGameStatusPtr)->unk_75 = (*gGameStatusPtr)->unk_13C = 0;
    D_80074021 = 5;
    (*gGameStatusPtr)->unk_168 = 0;
    fio_init_flash();
    func_80028838();
    general_heap_create();
    func_8011D890();
    func_801230B8();
    clear_script_list();
    create_cameras_a();
    clear_player_status();
    func_802DD8F8(0);
    func_80120BB0();
    func_8011E224();
    clear_model_data();
    func_80148040();
    func_80145DF8();
    clear_character_set();
    clear_printers();
    func_80112B98();
    func_800384BC();
    func_80141100();
    clear_trigger_data();
    func_80110CB8(0);
    clear_player_data();
    func_8003E338();
    func_80138108();
    func_80059C9C();
    clear_saved_variables();
    clear_item_entity_data();
    func_8014A498();
    func_80147230();
    func_80149618();
    func_801473F0();
    func_8002BA40();
    poll_rumble();

    phi_s0 = *gGameStatusPtr;
    for(i = 0; i < 4; i++)
    {
        phi_s0->unk_50[i] = 3;
        phi_s0->unk_48[i] = 0xC;
    }

    D_8009A650[0] |= 8;
    set_game_mode(0);
}*/

INCLUDE_ASM(code_1b40_len_20b0, func_80027088);

s32 func_80027190(void) {
    return D_8009A5D8;
}

INCLUDE_ASM(code_1b40_len_20b0, func_800271A0);
/*void func_800271A0(void) {
    Gfx *temp = D_8009A66C[0] + 1;

    gSPSegment(D_8009A66C[0], 0x00, 0x00000000);
    D_8009A66C[0] = temp;
    gSPDisplayList(temp, &D_00074230);
    D_8009A66C[0]++;
    gSPDisplayList(D_8009A66C[0]++, &D_00074210);
}*/

INCLUDE_ASM(code_1b40_len_20b0, func_800271FC);

INCLUDE_ASM(code_1b40_len_20b0, func_8002725C);

INCLUDE_ASM(code_1b40_len_20b0, func_80027600);

INCLUDE_ASM(code_1b40_len_20b0, func_80027774);

INCLUDE_ASM(code_1b40_len_20b0, func_800279B4);

INCLUDE_ASM(code_1b40_len_20b0, func_80027BAC);

INCLUDE_ASM(code_1b40_len_20b0, func_80027E10);
