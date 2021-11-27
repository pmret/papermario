#include "common.h"

#define MAX_ITEM_ENTITIES 256

extern s32 D_801512F8;
extern s32 D_80155D84;
extern s32 D_80155D88;
extern ItemEntity* D_80155DA0[MAX_ITEM_ENTITIES];
extern ItemEntity* D_801561A0[MAX_ITEM_ENTITIES];
extern ItemEntity** D_801565A0; // item entity list
extern s16 D_801565A4;
extern s16 D_801565A8;
extern s16 D_80155D8C;
extern s16 D_80155D8E;
extern s16 D_80155D90;

void delete_shadow(s16);
void draw_item_entities(void);
void func_80132D94(void);

INCLUDE_ASM(s32, "C50A0", draw_ci_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_tiled_image);

s32 integer_log(s32 number, u32 base) {
    f64 temp_f0;
    f32 fNumber = number;
    s32 ret = 1;

    while (TRUE) {
        fNumber /= base;
        if (fNumber <= 1.0) {
            return ret;
        }

        ret++;
    }
}

INCLUDE_ASM(s32, "C50A0", draw_adjustable_tiled_image);

void sparkle_script_init(ItemEntity* itemEntity, s32* state) {
    itemEntity->currentState = state;
    itemEntity->framesLeft = 1;
    itemEntity->sequenceStart = state;
}

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

void item_entity_disable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags |= ENTITY_FLAGS_CONTINUOUS_COLLISION;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags |= SHADOW_FLAGS_1;
    }
}

void item_entity_enable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags &= ~ENTITY_FLAGS_CONTINUOUS_COLLISION;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags &= ~SHADOW_FLAGS_1;
    }
}

void clear_item_entity_data(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        D_801565A0 = D_80155DA0;
    } else {
        D_801565A0 = D_801561A0;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        D_801565A0[i] = NULL;
    }

    D_801512F8 = 0;
    D_80155D8C = 0;
    D_80155D8E = 0;
    D_80155D90 = 0;
    D_80155D84 = 0;

    if (!gGameStatusPtr->isBattle) {
        D_80155D88 = 0;
    }

    create_generic_entity_world(NULL, draw_item_entities);
    create_generic_entity_frontUI(NULL, func_80132D94);
    D_801565A4 = 0;
    D_801565A8 = 0;
}

void init_item_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        D_801565A0 = D_80155DA0;
    } else {
        D_801565A0 = D_801561A0;
    }

    D_801565A4 = 0;
    D_801565A8 = 0;
    D_801512F8 = 0;
    D_80155D84 = 0;
}

INCLUDE_ASM(s32, "C50A0", item_entity_load);

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
void appendGfx_item_entity(ItemEntity* itemEntity);

INCLUDE_ASM(s32, "C50A0", draw_item_entities);

INCLUDE_ASM(s32, "C50A0", func_80132D94);

INCLUDE_ASM(s32, "C50A0", render_item_entities);

void remove_item_entity_by_reference(ItemEntity* entity) {
    s32 index;

    for (index = 0; index < MAX_ITEM_ENTITIES; index++) {
        if (D_801565A0[index] == entity) {
            break;
        }
    }

    if (index < MAX_ITEM_ENTITIES) {
        if (entity->physicsData != NULL) {
            heap_free(entity->physicsData);
        }

        switch (entity->type) {
            case 0:
            case 3:
            case 12:
            case 16:
            case 20:
            case 28:
                delete_shadow(entity->shadowIndex);
                break;
        }

        heap_free(D_801565A0[index]);
        D_801565A4 = 0;
        D_801565A0[index] = NULL;
    }
}

void remove_item_entity_by_index(s32 index) {
    ItemEntity* itemEntity = D_801565A0[index];

    switch (itemEntity->type) {
        case 0:
        case 3:
        case 12:
        case 16:
        case 20:
        case 28:
            delete_shadow(itemEntity->shadowIndex);
            break;
    }

    heap_free(D_801565A0[index]);
    D_801565A0[index] = NULL;
    D_801565A4 = 0;
}

void func_80133A94(s32 idx, s32 itemID) {
    ItemEntity* item = D_801565A0[idx];

    item->itemID = itemID;

    item->flags |= ENTITY_FLAGS_4000;
    item->flags &= ~ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;

    if (gItemTable[itemID].typeFlags & 0x1000) {
        item->flags |= ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;
        item->flags &= ~ENTITY_FLAGS_4000;
    }

    item_entity_load(item);
}

s32 test_item_player_collision(ItemEntity* itemEntity);
INCLUDE_ASM(s32, "C50A0", test_item_player_collision);

INCLUDE_ASM(s32, "C50A0", test_item_entity_position);

void set_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = D_801565A0[index];

    itemEntity->flags |= flags;
    if (itemEntity->flags & ENTITY_FLAGS_200000) {
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
    itemEntity->flags |= ENTITY_FLAGS_100;
}

/// @returns TRUE when "you got X" popup is on-screen
s32 is_picking_up_item(void) {
    s32 ret = D_801565A8 != 0;

    if (D_801565A4 != 0) {
        ret = TRUE;
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

void update_item_entity_static(ItemEntity* itemEntity) {
    if ((s8)itemEntity->state == 0 && test_item_player_collision(itemEntity)) {
        D_801565A4 = 1;
        itemEntity->type = 28;
        itemEntity->state = 0;
        D_801565A8 = 0;
        gOverrideFlags |= 0x40;
    }
}

void func_801356C4(void) {
}

void func_801356CC(void) {
}

void func_801356D4(void) {
}

INCLUDE_ASM(s32, "C50A0", update_item_entity_temp);

INCLUDE_ASM(s32, "C50A0", func_801363A0);

INCLUDE_ASM(s32, "C50A0", func_8013673C);

void func_801369D0(s32 arg1, s32 x, s32 y) {
    draw_msg(0x1D0060, x + 12, y + 4, 255, 52, 0);
}

INCLUDE_ASM(s32, "C50A0", func_80136A08);
