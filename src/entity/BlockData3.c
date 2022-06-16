#include "common.h"
#include "ld_addrs.h"

extern UNK_TYPE D_0A000740;
extern UNK_TYPE D_0A000EE8;
extern UNK_TYPE D_0A000EF8;

s32 D_802E9A40[18] = {
    0x00000003, 0x00000000, (s32)entity_small_switch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_RedSwitch_animate_scale,
    0x00000003, 0x00000000, (s32)entity_RedSwitch_wait_and_reset, 0x00000004,
    0x00000000, 0x00000000,
};

s32 D_802E9A88[15] = {
    0x00000003, 0x00000000, (s32)entity_HugeBlueSwitch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_base_switch_animate_scale,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9AC4[15] = {
    0x00000003, 0x00000000, (s32)entity_small_switch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_base_switch_animate_scale,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9B00[16] = {
    0x00000003, 0x00000000, (s32)entity_GreenStompSwitch_idle, 0x00000003,
    0x00000000, (s32)entity_GreenStompSwitch_retract, 0x00000009, 0x00000152,
    0x00000003, 0x00000080, 0x00000000, 0x00000003,
    0x00000000, (s32)entity_GreenStompSwitch_extend, 0x00000004, 0x00000000,
};

s32 D_802E9B40[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    &D_0A000EF8, 0x00000002, 0x00000000,
};

s32 D_802E9B5C[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_0A000EF8, 0x00000002, 0x00000000,
};

s32 D_802E9B78[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_0A000EE8, 0x00000002, 0x00000000
};

s32 D_802E9B94[7] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C,
    (s32) &D_0A000740, 0x00000002, 0x00000000,
};

EntityBlueprint Entity_RedSwitch = {
    0xA000, 0x002C, &D_802E9B78, {0, 0, 0, 0}, entity_base_switch_init,    &D_802E9A40, NULL, E62AC0_ROM_START, E62AC0_ROM_END, ENTITY_TYPE_RED_SWITCH, {0x16, 0x17, 0x16}
};
EntityBlueprint Entity_BlueSwitch = {
    0xAA04, 0x002C, &D_802E9B40, {0, 0, 0, 0}, entity_BlueSwitch_init,     &D_802E9AC4, NULL, E639C0_ROM_START, E639C0_ROM_END, ENTITY_TYPE_BLUE_SWITCH, {0x16, 0x17, 0x16}
};
EntityBlueprint Entity_HugeBlueSwitch = {
    0xAA04, 0x002C, &D_802E9B5C, {0, 0, 0, 0}, entity_HugeBlueSwitch_init, &D_802E9A88, NULL, E639C0_ROM_START, E639C0_ROM_END, ENTITY_TYPE_HUGE_BLUE_SWITCH, {0x42, 0x4B, 0x42}
};
EntityBlueprint Entity_GreenStompSwitch = {
    0xC000, 0x002C, &D_802E9B94, {0, 0, 0, 0}, entity_base_switch_init,    &D_802E9B00, NULL, E62370_ROM_START, E62370_ROM_END, ENTITY_TYPE_GREEN_STOMP_SWITCH, {0x32, 0x0F, 0x32}
};
