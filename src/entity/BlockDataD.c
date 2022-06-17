#include "common.h"
#include "ld_addrs.h"

void entity_BlueWarpPipe_check_if_active(Entity*);
void entity_BlueWarpPipe_rise_up(Entity*);
void entity_BlueWarpPipe_wait_for_player_to_get_off(Entity*);
void entity_BlueWarpPipe_idle(Entity*);
void entity_BlueWarpPipe_set_player_move_to_center(Entity*);
void entity_BlueWarpPipe_wait_player_move_to_center(Entity*);
void entity_BlueWarpPipe_enter_pipe_init(Entity*);
void entity_BlueWarpPipe_enter_pipe_update(Entity*);
void entity_BlueWarpPipe_start_bound_script(Entity*);
void entity_init_BlueWarpPipe(Entity*);

s32 D_802EAF00[] = {
    0x00000003, 0x00000000, entity_BlueWarpPipe_check_if_active, 0x00000003, 0x00000000, entity_BlueWarpPipe_rise_up, 0x00000003, 0x00000000, entity_BlueWarpPipe_wait_for_player_to_get_off, 0x00000003, 0x00000000,
    entity_BlueWarpPipe_idle, 0x00000002, entity_BlueWarpPipe_set_player_move_to_center, 0x00000003, 0x00000000, entity_BlueWarpPipe_wait_player_move_to_center, 0x00000002, entity_BlueWarpPipe_enter_pipe_init, 0x00000003, 0x00000000, entity_BlueWarpPipe_enter_pipe_update, 0x00000002, entity_BlueWarpPipe_start_bound_script, 0x00000000
};

s32 D_802EAF64[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0006B8, 0x00000002, 0x00000000,
};
EntityBlueprint D_802EAF80 = {
    0x0000, 0x001C, D_802EAF64, 0x00000000, entity_init_BlueWarpPipe, D_802EAF00, 0x00000000, E58CD0_ROM_START, E58CD0_ROM_END, ENTITY_TYPE_BLUE_WARP_PIPE, { 40, 50, 40}
};

