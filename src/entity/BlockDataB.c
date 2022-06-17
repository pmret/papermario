#include "common.h"
#include "ld_addrs.h"

void entity_Chest_check_opened(Entity*);
void entity_Chest_idle(Entity*);
void entity_Chest_adjust_camera(Entity*);
void entity_GiantChest_give_equipment(Entity*);
void entity_Chest_begin_opening(Entity*);
void entity_GiantChest_init(Entity*);
void entity_Chest_init(Entity*);
void entity_Chest_clear_item_id(Entity*);
void entity_GiantChest_open(Entity*);
void entity_Chest_start_bound_script(Entity*);
void entity_GiantChest_await_got_item(Entity*);
void entity_GiantChest_hide_effect(Entity*);
void entity_Chest_reset_camera(Entity*);
void entity_Chest_close(Entity*);
void entity_Chest_enable_player_input(Entity*);
void entity_Chest_open(Entity*);

s32 D_802EAB30[] = {
    0x00000056, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFF3D, 0xFFFFFE9A, 0xFFFFFDD5, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F0280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ACA80, 0xF24A5280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
};
s32 D_802EAC0C[] = {
    0x00000056, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000003, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
};
s32 D_802EAC40[] = {
    0x00000056, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A9A80, 0x00000000, 0xF24F2A80, 0xF24AC080, 0xF24A5480, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
};
s32 D_802EAC84[] = {
    0x00000056, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A9A80, 0x00000000, 0xF24DC280, 0xF24ACE80, 0xF24A3A80, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
};
s32 D_802EACC8[] = {
    0x00000056, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000003, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
};
s32 D_802EACFC[] = {
    0x00000002, entity_Chest_check_opened, 0x00000003, 0x00000000, entity_Chest_idle, 0x00000002, entity_Chest_adjust_camera, 0x00000002, entity_GiantChest_give_equipment, 0x00000002, entity_Chest_begin_opening, 0x00000003, 0x00000000, entity_GiantChest_open, 0x00000002, entity_Chest_start_bound_script, 0x00000003, 0x00000000, entity_GiantChest_await_got_item, 0x00000002, entity_GiantChest_hide_effect, 0x00000002, entity_Chest_reset_camera, 0x00000003, 0x00000000, entity_Chest_close, 0x00000003, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EAD7C[] = {
    0x00000003, 0x00000000, 0x00000000, 0x00000000
};
s32 D_802EAD8C[] = {
    0x00000002, entity_Chest_check_opened, 0x00000003, 0x00000000, entity_Chest_idle, 0x00000002, entity_Chest_begin_opening, 0x00000002, entity_Chest_start_bound_script, 0x00000002, entity_Chest_clear_item_id, 0x00000003, 0x00000000, entity_Chest_open, 0x00000002, entity_Chest_enable_player_input, 0x00000003, 0x00000000, entity_Chest_close, 0x00000003, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EADF0[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000EB8, 0x00000002, 0x00000000,
};
EntityBlueprint D_802EAE0C = {
    0x4000, 0x0038, D_802EADF0, 0x00000000, entity_GiantChest_init, D_802EACFC, 0x00000000, E648D0_ROM_START, E648D0_ROM_END, ENTITY_TYPE_CHEST, { 50, 45, 46 }
};
EntityBlueprint D_802EAE30 = {
    0xC000, 0x0038, D_802EADF0, 0x00000000, entity_Chest_init, D_802EAD8C, 0x00000000, E648D0_ROM_START, E648D0_ROM_END, ENTITY_TYPE_CHEST, { 28, 26, 23}
};
