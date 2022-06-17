#include "common.h"
#include "ld_addrs.h"

void entity_upgrade_block_check_if_inactive(Entity*);
void entity_upgrade_block_idle(Entity*);
void entity_SuperBlockContent_idle(Entity*);
void entity_SuperBlock_init(Entity*);
void entity_init_SuperBlockContent1(Entity*);
void entity_UltraBlock_init(Entity*);
void entity_init_SuperBlockContent2(Entity*);

extern Gfx D_802E9828[];

s32 D_802EA810[] = {
 0x00000002, entity_upgrade_block_check_if_inactive, 0x00000005, 0x00000001, 0x00000003,
 0x00000000, entity_upgrade_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_block_hit_init_scale, 0x00000003, 0x00000006, entity_block_hit_animate_scale,
  0x00000002, entity_start_script, 0x00000004, 0x00000001, 0x00000000, 0x00000000,
};
s32 D_802EA860[] = {
0x0A000200, 0x0A000220, 0x0A000240, 0x0A000260
};
s8 D_802EA870[] = {
    0x14, 0x00, 0x02, 0x01, 0x02, 0x02, 0x14, 0x03, 0x02, 0x02, 0x01, 0x02, 0xFF, 0xFF, 0x00, 0x00
};
s32 D_802EA880[] = {
    0x00000003, 0x00000000, entity_SuperBlockContent_idle, 0x00000000
};
s32 D_802EA890[] = {
    0x00000003, 0x00000000, entity_SuperBlockContent_idle, 0x00000000
};
s32 D_802EA8A0[] = {
    0x00000004, 0x0000000D, 0x00000001, 0x0000003C, 0x0A0008F8, 0x00000002, 0x00000000
};
s32 D_802EA8BC[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, D_802E9828, 0x00000002, 0x00000000
};
s32 D_802EA8D8[] = {
    0x00000004, 0x0000000D, 0x00000001, 0x0000003C, 0x0A0008C8, 0x00000002, 0x00000000
};
s32 D_802EA8F4[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, D_802E9828, 0x00000002, 0x00000000
};
EntityBlueprint D_802EA910 = {
    0x4200, 0x0020, D_802EA8A0, 0x00000000, entity_SuperBlock_init, D_802EA810, entity_block_handle_collision, E44800_ROM_START, E44800_ROM_END, ENTITY_TYPE_SUPER_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_SuperBlockContent = {
    0x0020, 0x0130, D_802EA8BC, 0x00000000, entity_init_SuperBlockContent1, D_802EA880, 0x00000000, E4A6A0_ROM_START, E4A6A0_ROM_END, ENTITY_TYPE_SUPER_BLOCK_HIT_EFFECT, { 18, 6, 18 }
};
EntityBlueprint D_802EA958 = {
    0x4200, 0x0020, D_802EA8D8, 0x00000000, entity_UltraBlock_init, D_802EA810, entity_block_handle_collision, E45110_ROM_START, E45110_ROM_END, ENTITY_TYPE_ULTRA_BLOCK, { 25, 25, 25 }
};
EntityBlueprint D_802EA97C = {
    0x0020, 0x0130, D_802EA8F4, 0x00000000, entity_init_SuperBlockContent2, D_802EA890, 0x00000000, E4AA80_ROM_START, E4AA80_ROM_END, ENTITY_TYPE_ULTRA_BLOCK_HIT_EFFECT, { 18, 6, 18 }
};
