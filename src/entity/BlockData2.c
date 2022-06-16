#include "common.h"
#include "ld_addrs.h"

extern UNK_TYPE D_0A003508;

s32 D_802E9930[51] = {
    0x00000003, 0x00000000, (s32)entity_SaveBlock_idle, 0x00000009,
    0x0000014E, 0x00000002, (s32)entity_SaveBlock_pause_game, 0x00000002,
    (s32)entity_block_hit_init_scale, 0x00000003, 0x00000006, (s32)entity_block_hit_animate_scale,
    0x00000003, 0x00000002, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_show_tutorial_message, 0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_tutorial,
    0x00000003, 0x0000000E, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_show_choice_message, 0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_choice,
    0x00000002, (s32)entity_SaveBlock_save_data, 0x00000002, (s32)entity_SaveBlock_show_result_message,
    0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_result, 0x00000002,
    (s32)entity_SaveBlock_resume_game, 0x00000003, 0x0000000C, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_resume_game, 0x00000003, 0x00000002, 0x00000000,
    0x00000001, (s32)D_802E9930, 0x00000000,
};

s32 D_802E99FC[7] = {
    0x00000004, 0x00000022, 0x00000001, 0x0000003C,
    &D_0A003508, 0x00000002, 0x00000000,
};

EntityBlueprint Entity_SavePoint = {
    0x4200, 0x0020, &D_802E99FC, {0, 0, 0, 0}, entity_SaveBlock_init, &D_802E9930, entity_block_handle_collision, E4B2E0_ROM_START, E4B2E0_ROM_END, 32, {0x19, 0x19, 0x19}
};
