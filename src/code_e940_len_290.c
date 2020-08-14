#include "common.h"

void func_80033540(void) {
    D_8009A650[0] |= 8;
    (*gGameStatusPtr)->unk_AC = 3;
}

INCLUDE_ASM(code_e940_len_290, func_80033568);
/*
s8 func_80033568(void) {
    game_status* gameStatus = gGameStatusPtr;
    s8 value = gameStatus->unk_AC - 1;

    if (gameStatus->unk_AC != 0) {
        gameStatus->unk_AC = value;
    }

    D_8009A650[0] = 0;

    gameStatus->unk_86 = 0;
    gameStatus->unk_70 = 0;
    gameStatus->unk_88 = -1;
    gameStatus->mapID = 0;

    gameStatus->unk_8E[0] = 0;

    gameStatus->unk_76[0] = 0;
    gameStatus->unk_76[2] = 0;

    gameStatus->unk_7D[0] = 0;

    gameStatus->unk_A8 = -1;
    gameStatus->unk_AA = 0;
    gameStatus->unk_A9 = -1;
    gameStatus->demoState = 0;

    general_heap_create(gameStatus);
    func_8011D890();
    func_801230B8();
    clear_script_list();
    create_cameras_a();
    func_802DD8F8(0);
    func_80120BB0();
    func_8011E224();
    clear_model_data();
    func_80148040();
    func_80145DF8();
    func_801452E8(0, 0);
    func_80141100();
    clear_trigger_data();
    clear_printers();
    func_80110CB8(0);
    func_80138108();
    clear_player_status();
    func_800384BC();
    clear_player_data();
    func_80072B30();
    func_8003E338();
    func_80059C9C();
    clear_item_entity_data();
    clear_saved_variables();
    initialize_collision();
    func_8014AC08();
    func_801473F0();
    func_800EB580();
    func_80149618();
    func_8014A52C();
    func_8002BA40();

//     s32 temp_a0_2;
//     s8 temp_v0;
//     void *temp_a0;
//     void *phi_v1;
//     s32 phi_a0;

//     temp_a0 = *(void *)0x8007419C;
//     temp_v0 = (u8) temp_a0->unkAC - 1;
//     if (temp_a0->unkAC != 0) {
//         temp_a0->unkAC = temp_v0;
//         return temp_v0;
//     }
//     *(void *)0x8009A650 = 0;
//     temp_a0->unk86 = (u16)0;
//     temp_a0->unk70 = (u8)0;
//     temp_a0->unk88 = (u16)-1;
//     temp_a0->unk8C = (u16)0;
//     temp_a0->unk8E = (u16)0;
//     (*(void *)0x8007419C)->unk76 = (u8)0;
//     (*(void *)0x8007419C)->unk78 = (u8)0;
//     (*(void *)0x8007419C)->unk7D = (u8)0;
//     (*(void *)0x8007419C)->unkA8 = (s8) (u16)-1;
//     (*(void *)0x8007419C)->unkAA = (u8)0;
//     (*(void *)0x8007419C)->unkA9 = (s8) (u16)-1;
//     (*(void *)0x8007419C)->unk71 = (u8)0;
//     general_heap_create(temp_a0);
//     func_8011D890();
//     func_801230B8();
//     clear_script_list();
//     create_cameras_a();
//     func_802DD8F8(0);
//     func_80120BB0();
//     func_8011E224();
//     clear_model_data();
//     func_80148040();
//     func_80145DF8();
//     func_801452E8(0, 0);
//     func_80141100();
//     clear_trigger_data();
//     clear_printers();
//     func_80110CB8(0);
//     func_80138108();
//     clear_player_status();
//     func_800384BC();
//     clear_player_data();
//     func_80072B30();
//     func_8003E338();
//     func_80059C9C();
//     clear_item_entity_data();
//     clear_saved_variables();
//     initialize_collision();
//     func_8014AC08();
//     func_801473F0();
//     func_800EB580();
//     func_80149618();
//     func_8014A52C();
//     func_8002BA40();
//     phi_v1 = *(void *)0x8007419C;
//     phi_a0 = 0;
// loop_3:
//     phi_v1->unk50 = (u16)4;
//     phi_v1->unk48 = (u16)0xF;
//     temp_a0_2 = phi_a0 + 1;
//     phi_v1 = phi_v1 + 2;
//     phi_a0 = temp_a0_2;
//     if (temp_a0_2 < 4) {
//         goto loop_3;
//     }
//     fio_has_valid_backup(temp_a0_2, (u16)0xF, (u16)4);
//     if (*(void *)0x800D9620 == 0) {
//         (*(void *)0x8007419C)->unkAB = (u8)1;
//         func_8005615C();
//     } else {
//         (*(void *)0x8007419C)->unkAB = (u8)0;
//         func_80056180();
//     }
//     *(void *)0x8009A650 = (s32) (*(void *)0x8009A650 & -9);
//     return set_game_mode(1, -9);
}
*/

void func_80033788(void) {
    func_8002AB5C(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
