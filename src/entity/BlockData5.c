#include "common.h"
#include "ld_addrs.h"

void entity_inactive_block_hit_init(Entity*);
void entity_inactive_block_hit_anim(Entity*);
void entity_breakable_block_create_shattering_entity(Entity*);
void entity_inactive_block_recoil_anim(Entity*);
void entity_BrickBlock_idle(Entity*);
void entity_MulticoinBlock_check_if_inactive(Entity*);
void entity_MulticoinBlock_idle(Entity*);
void entity_init_Hammer1Block_normal(Entity*);
void entity_MulticoinBlock_init(Entity*);
void entity_init_HammerBlock_small(Entity*);
void entity_MulticoinBlock_spawn_coin(Entity*);

s32 D_802E9D90[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_block_hit_init_scale, 0x00000003, 0x00000006, entity_block_hit_animate_scale, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9DCC[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000, 0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9E0C[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_inactive_block_hit_init, 0x00000002, entity_start_script, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9E54[] = {
    0x00000002, entity_inactive_block_hit_init, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000001, D_802E9E0C, 0x00000000
};
s32 D_802E9E80[] = {
    0x00000006, 0x00000007, 0x00000001, 0x00000007, 0x00000020, 0x00000002, entity_breakable_block_create_shattering_entity, 0x00000003, 0x00000001, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802E9EB4[] = {
    0x00000003, 0x00000000, entity_BrickBlock_idle, 0x00000002, entity_start_script, 0x00000007, 0x00000001, 0x00000007, 0x00000020, 0x00000002, entity_breakable_block_create_shattering_entity, 0x00000009, 0x0000014E, 0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802E9F00[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9F28[] = {
    0x00000002, entity_MulticoinBlock_check_if_inactive, 0x00000005, 0x00000001, 0x00000003, 0x00000000, entity_MulticoinBlock_idle, 0x00000009, 0x0000014E, 0x00000002, entity_MulticoinBlock_spawn_coin, 0x00000002, entity_inactive_block_hit_init, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000004, 0x00000001, 0x00000000
};
s32 D_802E9F80[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004E0, 0x00000002, 0x00000000
};
s32 D_802E9F9C[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
s32 D_802E9FB8[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004A0, 0x00000002, 0x00000000
};
s32 D_802E9FD4[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004F0, 0x00000002, 0x00000000
};
s32 D_802E9FF0[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004F0, 0x00000002, 0x00000000
};
s32 D_802EA00C[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004E0, 0x00000002, 0x00000000
};
s32 D_802EA028[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000338, 0x00000002, 0x00000000
};
s32 D_802EA044[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004A0, 0x00000002, 0x00000000
};
s32 D_802EA060[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000CC8, 0x00000002, 0x00000000
};

EntityBlueprint Entity_InertYellowBlock = {
    0x4200, 0x0020, D_802E9F80, 0, entity_init_Hammer1Block_normal, D_802E9E0C, entity_block_handle_collision, E42240_ROM_START, E42240_ROM_END, ENTITY_TYPE_MULTI_TRIGGER_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_InertRedBlock = {
    0x4200, 0x0020, D_802E9F9C, 0, entity_init_Hammer1Block_normal, D_802E9E0C, entity_block_handle_collision, E42740_ROM_START, E42740_ROM_END, ENTITY_TYPE_INACTIVE_BLOCK, { 25, 25, 25 }
};
EntityBlueprint D_802EA0C4 = {
    0x4280, 0x0020, D_802EA044, 0, entity_base_block_init, D_802E9EB4, entity_block_handle_collision, E3DDB0_ROM_START, E3DDB0_ROM_END, ENTITY_TYPE_BRICK_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA0E8 = {
    0x4200, 0x0020, D_802E9FB8, 0x00000000, entity_MulticoinBlock_init, D_802E9F28, entity_block_handle_collision, E3DDB0_ROM_START, E3DDB0_ROM_END, ENTITY_TYPE_MULTI_COIN_BRICK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA10C = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 50 }
};
EntityBlueprint Entity_D_802EA130 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 100, 50, 50 }
};
EntityBlueprint Entity_D_802EA154 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 100 }
};
EntityBlueprint Entity_D_802EA178 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA19C = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 50 }
};
EntityBlueprint D_802EA1C0 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 100, 50, 50 }
};
EntityBlueprint D_802EA1E4 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 100 }
};
EntityBlueprint D_802EA208 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint D_802EA22C = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 50 }
};
EntityBlueprint D_802EA250 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 100, 50, 50 }
};
EntityBlueprint D_802EA274 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 100 }
};
EntityBlueprint D_802EA298 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint D_802EA2BC = {
    0x4000, 0x0020, D_802EA028, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E3DA60_ROM_START, E3DA60_ROM_END, ENTITY_TYPE_PUSH_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA2E0 = {
    0x4000, 0x0020, D_802EA060, 0x00000000, entity_base_block_init, D_802E9D90, entity_block_handle_collision, E43B20_ROM_START, E43B20_ROM_END, ENTITY_TYPE_POW_BLOCK, { 30, 25, 25 },
};
