#include "common.h"
#include "ld_addrs.h"

void entity_ItemBlock_check_if_inactive(Entity*);
void entity_ItemBlock_idle(Entity*);
void entity_HitItemBlock_play_anim(Entity*);
void entity_HitItemBlock_appear(Entity*);
void entity_TriggerBlock_disable_player_input(Entity*);
void entity_HiddenItemBlock_idle(Entity*);
void entity_ItemBlock_spawn_item(Entity*);
void entity_ItemBlock_replace_with_inactive(Entity*);
void entity_HitItemBlock_hide(Entity*);
void entity_HitItemBlock_show_inactive(Entity*);
void entity_TriggerBlock_play_vanish_effect(Entity*);
void entity_inactive_block_hit_init(Entity*);
void entity_inactive_block_hit_anim(Entity*);
void entity_inactive_block_recoil_anim(Entity*);
void entity_TriggerBlock_start_bound_script(Entity*);
void entity_TriggerBlock_enable_player_input(Entity*);
void entity_TriggerBlock_start_bound_script_2(Entity*);
void entity_HiddenItemBlock_init(Entity*);
void entity_ItemlessBlock_init(Entity*);
void entity_ItemBlock_init(Entity*);

s32 D_802EA310[] = {
    0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802EA328[] = {
    0x00000002, entity_ItemBlock_check_if_inactive, 0x00000003, 0x00000000, 0x00000000, 0x00000003, 0x00000000, entity_ItemBlock_idle, 0x00000009, 0x0000014E, 0x00000002, entity_ItemBlock_spawn_item, 0x00000002, entity_ItemBlock_replace_with_inactive, 0x00000003, 0x00000001, 0x00000000, 0x00000007, 0x00000001, 0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802EA38C[] = {
    0x00000002, entity_ItemBlock_check_if_inactive, 0x00000003, 0x00000000, 0x00000000, 0x00000003, 0x00000000, entity_HiddenItemBlock_idle, 0x00000009, 0x0000014E, 0x00000002, entity_ItemBlock_spawn_item, 0x00000002, entity_ItemBlock_replace_with_inactive, 0x00000003, 0x00000001, 0x00000000, 0x00000007, 0x00000001, 0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802EA3F0[] = {
    0x00000003, 0x00000001, 0x00000000, 0x00000002, entity_HitItemBlock_play_anim, 0x00000003, 0x0000000A, entity_HitItemBlock_appear, 0x00000002, entity_HitItemBlock_hide, 0x00000002, entity_HitItemBlock_show_inactive, 0x00000003, 0x00000001, 0x00000000, 0x00000007, 0x00000001, 0x00000007, 0x04000000, 0x00000000
};
s32 D_802EA440[] = {
    0x00000003, 0x00000000, entity_ItemBlock_idle, 0x00000002, entity_TriggerBlock_disable_player_input, 0x00000009, 0x0000014E, 0x00000002, entity_TriggerBlock_play_vanish_effect, 0x00000002, entity_inactive_block_hit_init, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000002, entity_TriggerBlock_start_bound_script, 0x00000002, entity_TriggerBlock_enable_player_input, 0x00000007, 0x00000001, 0x00000007, 0x00000020, 0x00000002, entity_TriggerBlock_start_bound_script_2, 0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x04000000, 0x00000000
};
//TODO ROM_ADDR
s32 D_802EA4C4[] = {
    0x00E459F0, 0x00E46E10, 0x00E46E10, 0x00E470B0
};
s32 D_802EA4D4[] = {
    0x00E470B0, 0x00E484F0, 0x00E484F0, 0x00E48780
};
s32 D_802EA4E4[] = {
    0x00E48780, 0x00E49BE0, 0x00E49BE0, 0x00E49E40
};
s32 D_802EA4F4[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
s32 D_802EA510[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
s32 D_802EA52C[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
s32 D_802EA548[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
EntityBlueprint Entity_D_802EA564 = {
    0x4200, 0x0020, D_802EA4F4, 0x00000000, entity_ItemBlock_init, D_802EA328, entity_block_handle_collision, E3B870_ROM_START, E3B870_ROM_END, ENTITY_TYPE_YELLOW_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA588 = {
    0x4200, 0x0020, D_802EA510, 0x00000000, entity_HiddenItemBlock_init, D_802EA38C, entity_block_handle_collision, E3B870_ROM_START, E3B870_ROM_END, ENTITY_TYPE_HIDDEN_YELLOW_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA5AC = {
    0x4200, 0x0020, D_802EA52C, 0x00000000, entity_ItemBlock_init, D_802EA328, entity_block_handle_collision, E3C320_ROM_START, E3C320_ROM_END, ENTITY_TYPE_RED_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA5D0 = {
    0x4200, 0x0020, D_802EA548, 0x00000000, entity_HiddenItemBlock_init, D_802EA38C, entity_block_handle_collision, E3C320_ROM_START, E3C320_ROM_END, ENTITY_TYPE_HIDDEN_RED_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA5F4 = {
    0xC208, 0x0020, 0x0000023C, 0x00000084, entity_ItemlessBlock_init, D_802EA440, entity_block_handle_collision, D_802EA4C4, 0x00000000, ENTITY_TYPE_SINGLE_TRIGGER_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_HitGroundedYellowBlock = {
    0x4208, 0x0020, 0x0000023C, 0x00000084, entity_ItemlessBlock_init, D_802EA3F0, 0x00000000, D_802EA4C4, 0x00000000, ENTITY_TYPE_YELLOW_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_HitFloatingYellowBlock = {
    0x4208, 0x0020, 0x0000022C, 0x00000084, entity_ItemlessBlock_init, D_802EA3F0, 0x00000000, D_802EA4D4, 0x00000000, ENTITY_TYPE_YELLOW_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_HitRedBlock = {
    0x4208, 0x0020, 0x00000094, 0x00000084, entity_ItemlessBlock_init, D_802EA3F0, 0x00000000, D_802EA4E4, 0x00000000, ENTITY_TYPE_RED_BLOCK, { 25, 25, 25 }
};
