#include "common.h"

extern s32 D_80155D88;
ItemEntity** D_801565A0; // item entity list
extern s16 D_801565A4;
extern s16 D_801565A8;

INCLUDE_ASM(s32, "code_C50A0", func_8012E9A0);

INCLUDE_ASM(s32, "code_C50A0", func_8012EC94);

INCLUDE_ASM(s32, "code_C50A0", func_8012F500);

INCLUDE_ASM(s32, "code_C50A0", func_8012FE10);

INCLUDE_ASM(s32, "code_C50A0", func_8012FE78);

INCLUDE_ASM(s32, "code_C50A0", func_801309F0);

INCLUDE_ASM(s32, "code_C50A0", func_80130A04);

INCLUDE_ASM(s32, "code_C50A0", func_80130ACC);

INCLUDE_ASM(s32, "code_C50A0", draw_coin_sparkles);

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return D_801565A0[itemEntityIndex];
}

INCLUDE_ASM(s32, "code_C50A0", func_80130F70);

INCLUDE_ASM(s32, "code_C50A0", func_80130FAC);

INCLUDE_ASM(s32, "code_C50A0", clear_item_entity_data);

INCLUDE_ASM(s32, "code_C50A0", init_item_entity_list);

INCLUDE_ASM(s32, "code_C50A0", func_80131128);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign,
                     s32 pickupVar);
INCLUDE_ASM(s32, "code_C50A0", make_item_entity, s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay,
            s32 facingAngleSign, s32 pickupVar);

s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, 0, -1, pickupVar);
}

s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, pickupDelay, -1, pickupVar);
}

INCLUDE_ASM(s32, "code_C50A0", init_got_item);

INCLUDE_ASM(s32, "code_C50A0", func_80131DD4);

INCLUDE_ASM(s32, "code_C50A0", update_item_entities);

INCLUDE_ASM(s32, "code_C50A0", appendGfx_item_entity);

INCLUDE_ASM(s32, "code_C50A0", draw_item_entities);

INCLUDE_ASM(s32, "code_C50A0", func_80132D94);

INCLUDE_ASM(s32, "code_C50A0", render_item_entities);

INCLUDE_ASM(s32, "code_C50A0", remove_item_entity_by_reference);

INCLUDE_ASM(s32, "code_C50A0", remove_item_entity_by_index);

INCLUDE_ASM(s32, "code_C50A0", func_80133A94);

INCLUDE_ASM(s32, "code_C50A0", test_item_player_collision);

INCLUDE_ASM(s32, "code_C50A0", func_80133FC8);

void set_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = D_801565A0[index];

    itemEntity->flags |= flags;
    if (itemEntity->flags & 0x200000) {
        D_801565A8 = 1;
    }
}

void clear_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = D_801565A0[index];

    itemEntity->flags &= ~flags;
}

void func_801341B0(s32 index) {
    ItemEntity* itemEntity = D_801565A0[index];
    OVERRIDE_FLAG_SET(0x40);
    itemEntity->flags |= 0x100;
}

/// @returns TRUE when "you got X" popup is on-screen
s32 is_picking_up_item(void) {
    s32 ret = D_801565A8 != 0;

    if (D_801565A4 != 0) {
        ret = 1;
    }
    return ret;
}

void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z) {
    ItemEntity* itemEntity = D_801565A0[itemEntityIndex];

    itemEntity->position.x = x;
    itemEntity->position.y = y;
    itemEntity->position.z = z;
}

void func_80134230(s32 arg0) {
    D_80155D88 = arg0;
}

s32 func_80134240(void) {
    return D_80155D88;
}

INCLUDE_ASM(s32, "code_C50A0", update_item_entity_collectable);

INCLUDE_ASM(s32, "code_C50A0", func_8013559C);

INCLUDE_ASM(s32, "code_C50A0", update_item_entity_static);

void func_801356C4(void) {
}

void func_801356CC(void) {
}

void func_801356D4(void) {
}

INCLUDE_ASM(s32, "code_C50A0", update_item_entity_temp);

INCLUDE_ASM(s32, "code_C50A0", func_801363A0);

INCLUDE_ASM(s32, "code_C50A0", func_8013673C);

INCLUDE_ASM(s32, "code_C50A0", func_801369D0);

INCLUDE_ASM(s32, "code_C50A0", func_80136A08);
