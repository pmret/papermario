#include "common.h"
#include "ld_addrs.h"

void entity_HeartBlockContent_reset(Entity*);
void entity_HeartBlockContent_idle(Entity*);
void func_802E4DE0(Entity*);
void entity_HeartBlock_change_render_script(Entity*);
void entity_HeartBlockContent_anim_heal(Entity*);
void entity_HeartBlock_show_tutorial_message(Entity*);
void entity_HeartBlock_wait_for_close_tutorial(Entity*);
void entity_HeartBlock_idle(Entity*);
void entity_HeartBlockContent_init(Entity*);
void entity_HeartBlock_init(Entity*);

extern s32 Entity_InertBlock_Script[];

s32 D_802EA690[] = {
    0x00000002, entity_HeartBlockContent_reset, 0x00000003, 0x00000000, entity_HeartBlockContent_idle, 0x00000002, func_802E4DE0, 0x00000002, entity_HeartBlock_change_render_script, 0x00000003, 0x00000000, entity_HeartBlockContent_anim_heal, 0x00000002, entity_HeartBlock_show_tutorial_message, 0x00000003, 0x00000000, entity_HeartBlock_wait_for_close_tutorial, 0x00000003, 0x0000003C, 0x00000000, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EA6EC[] = {
    0x00000003, 0x00000000, entity_HeartBlock_idle, 0x00000009, 0x0000014E, 0x00000002, entity_start_script, 0x00000002, entity_block_hit_init_scale, 0x00000003, 0x00000006, entity_block_hit_animate_scale, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EA728[] = {
    0x00000004, 0x0000000D, 0x00000001, 0x0000003C, 0x0A000700, 0x00000002, 0x00000000
};
s32 D_802EA744[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, 0x0A0007B0, 0x00000002, 0x00000000
};
s32 D_802EA760[] = {
    0x00000004, 0x00000016, 0x00000001, 0x0000003C, 0x0A000808, 0x00000002, 0x00000000
};
s32 D_802EA77C[] = {
    0x00000004, 0x00000022, 0x00000001, 0x0000003C, 0x0A000918, 0x00000002, 0x00000000
};
EntityBlueprint D_802EA798 = {
    0x4200, 0x0020, D_802EA77C, 0x00000000, entity_base_block_init, Entity_InertBlock_Script, entity_block_handle_collision, E431F0_ROM_START, E431F0_ROM_END, ENTITY_TYPE_HEALING_BLOCK_FRAME, { 25, 25, 25 }
};
EntityBlueprint Entity_HeartBlockContent = {
    0x0020, 0x00D8, D_802EA728, 0x00000000, entity_HeartBlockContent_init, D_802EA690, 0x00000000, E49E40_ROM_START, E49E40_ROM_END, ENTITY_TYPE_HEALING_BLOCK_CONTENT, { 18, 6, 18 }
};
EntityBlueprint Entity_HeartBlock = {
    0x4200, 0x0020, D_802EA77C, 0x00000000, entity_HeartBlock_init, D_802EA6EC, entity_block_handle_collision, E431F0_ROM_START, E431F0_ROM_END, ENTITY_TYPE_HEALING_BLOCK, { 25, 25, 25 }
};
