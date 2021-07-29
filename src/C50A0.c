#include "common.h"

extern s32 D_801512F8;
extern s32 D_80155D84;
extern s32 D_80155D88;
extern ItemEntity* D_80155DA0;
extern ItemEntity* D_801561A0;
extern ItemEntity** D_801565A0; // item entity list
extern s16 D_801565A4;
extern s16 D_801565A8;

INCLUDE_ASM(s32, "C50A0", draw_ci_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_tiled_image);

INCLUDE_ASM(s32, "C50A0", integer_log);

INCLUDE_ASM(s32, "C50A0", draw_adjustable_tiled_image);

INCLUDE_ASM(s32, "C50A0", sparkle_script_init);

s32 sparkle_script_step(ItemEntity* itemEntity) {
    s32* currentState = itemEntity->currentState;

    switch (*currentState++) {
        case 1:
            itemEntity->framesLeft = *currentState++;
            itemEntity->unk_44 = *currentState++;
            itemEntity->currentState = currentState;
            break;

        case 2:
            itemEntity->currentState = itemEntity->sequenceStart;
            return 1;

        case 3:
            itemEntity->sequenceStart = currentState;
            itemEntity->currentState = currentState;
            return 1;

        case 7:
            itemEntity->framesLeft = *currentState++;
            itemEntity->unk_4C = *currentState++;
            itemEntity->unk_50 = *currentState++;
            itemEntity->unk_54 = *currentState++;
            itemEntity->unk_58 = *currentState++;
            itemEntity->currentState = currentState;
            break;

        case 4:
            itemEntity->currentState = currentState++;
            itemEntity->currentState = currentState++;

        case 0:
            return 1;
    }

    return 0;
}

void sparkle_script_update(ItemEntity* itemEntity) {
    itemEntity->framesLeft--;
    if (itemEntity->framesLeft <= 0) {
        while (sparkle_script_step(itemEntity) != 0) {

        }
    }
}

INCLUDE_ASM(s32, "C50A0", draw_coin_sparkles);

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return D_801565A0[itemEntityIndex];
}

INCLUDE_ASM(s32, "C50A0", item_entity_disable_shadow);

INCLUDE_ASM(s32, "C50A0", item_entity_enable_shadow);

INCLUDE_ASM(s32, "C50A0", clear_item_entity_data);

void init_item_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        D_801565A0 = &D_80155DA0;
    } else {
        D_801565A0 = &D_801561A0;
    }

    D_801565A4 = 0;
    D_801565A8 = 0;
    D_801512F8 = 0;
    D_80155D84 = 0;
}

INCLUDE_ASM(s32, "C50A0", item_entity_load);

s32 make_item_entity(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 facingAngleSign,
                     s32 pickupVar);
INCLUDE_ASM(s32, "C50A0", make_item_entity, s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay,
            s32 facingAngleSign, s32 pickupVar);

s32 make_item_entity_nodelay(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, 0, -1, pickupVar);
}

s32 make_item_entity_delayed(s32 itemID, f32 x, f32 y, f32 z, s32 itemSpawnMode, s32 pickupDelay, s32 pickupVar) {
    return make_item_entity(itemID, x, y, z, itemSpawnMode, pickupDelay, -1, pickupVar);
}

INCLUDE_ASM(s32, "C50A0", init_got_item);

INCLUDE_ASM(s32, "C50A0", item_entity_update);

INCLUDE_ASM(s32, "C50A0", update_item_entities);

INCLUDE_ASM(s32, "C50A0", appendGfx_item_entity);

INCLUDE_ASM(s32, "C50A0", draw_item_entities);

INCLUDE_ASM(s32, "C50A0", func_80132D94);

INCLUDE_ASM(s32, "C50A0", render_item_entities);

INCLUDE_ASM(s32, "C50A0", remove_item_entity_by_reference);

INCLUDE_ASM(s32, "C50A0", remove_item_entity_by_index);

INCLUDE_ASM(s32, "C50A0", func_80133A94);

INCLUDE_ASM(s32, "C50A0", test_item_player_collision);

INCLUDE_ASM(s32, "C50A0", test_item_entity_position);

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
    gOverrideFlags |= 0x40;
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

INCLUDE_ASM(s32, "C50A0", update_item_entity_collectable);

INCLUDE_ASM(s32, "C50A0", func_8013559C);

INCLUDE_ASM(s32, "C50A0", update_item_entity_static);

void func_801356C4(void) {
}

void func_801356CC(void) {
}

void func_801356D4(void) {
}

INCLUDE_ASM(s32, "C50A0", update_item_entity_temp);

INCLUDE_ASM(s32, "C50A0", func_801363A0);

INCLUDE_ASM(s32, "C50A0", func_8013673C);

INCLUDE_ASM(s32, "C50A0", func_801369D0);

INCLUDE_ASM(s32, "C50A0", func_80136A08);
