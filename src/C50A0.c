#include "common.h"
#include "effects.h"
#include "hud_element.h"

#define MAX_ITEM_ENTITIES 256

extern s32 ItemEntitiesCreated;
extern s32 ItemEntityAlternatingSpawn;
extern s32 ItemEntityRenderGroup;
extern ItemEntity* WorldItemEntities[MAX_ITEM_ENTITIES];
extern ItemEntity* BattleItemEntities[MAX_ITEM_ENTITIES];
extern ItemEntity** gCurrentItemEntities;
extern s16 isPickingUpItem;
extern s16 D_801565A8;
extern s32 D_80155D80;
extern s16 D_80155D8C;
extern s16 D_80155D8E;
extern s16 D_80155D90;

extern s32* SparkleScript_Coin;

void item_entity_load(ItemEntity*);
void item_entity_update(ItemEntity*);
void appendGfx_item_entity(void*);
void draw_item_entities(void);
void draw_item_entities_UI(void);
s32 test_item_player_collision(ItemEntity*);
void update_item_entity_collectable(ItemEntity*);
void func_8013559C(ItemEntity*);
void update_item_entity_static(ItemEntity*);
void func_801356C4(void);
void func_801356CC(ItemEntity*);
void func_801356D4(void);
void update_item_entity_temp(ItemEntity*);

INCLUDE_ASM(s32, "C50A0", draw_ci_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_image_with_clipping);

INCLUDE_ASM(s32, "C50A0", draw_tiled_image);

s32 integer_log(s32 number, u32 base) {
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
    itemEntity->sparkleReadPos = state;
    itemEntity->sparkleNextUpdate = 1;
    itemEntity->sparkleSavedPos = state;
}

s32 sparkle_script_step(ItemEntity* itemEntity) {
    s32* currentState = itemEntity->sparkleReadPos;

    switch (*currentState++) {
        case 1:
            itemEntity->sparkleNextUpdate = *currentState++;
            itemEntity->sparkleUnk44 = *currentState++;
            itemEntity->sparkleReadPos = currentState;
            break;
        case 2:
            itemEntity->sparkleReadPos = itemEntity->sparkleSavedPos;
            return TRUE;
        case 3:
            itemEntity->sparkleSavedPos = currentState;
            itemEntity->sparkleReadPos = currentState;
            return TRUE;
        case 7:
            itemEntity->sparkleNextUpdate = *currentState++;
            itemEntity->sparkleRaster = *currentState++;
            itemEntity->sparklePalette = *currentState++;
            itemEntity->sparkleWidth = *currentState++;
            itemEntity->sparkleHeight = *currentState++;
            itemEntity->sparkleReadPos = currentState;
            break;
        case 4:
            itemEntity->sparkleReadPos = currentState++;
            itemEntity->sparkleReadPos = currentState++;
        case 0:
            return TRUE;
    }
    return FALSE;
}

void sparkle_script_update(ItemEntity* itemEntity) {
    itemEntity->sparkleNextUpdate--;
    if (itemEntity->sparkleNextUpdate <= 0) {
        while (sparkle_script_step(itemEntity) != 0) {}
    }
}

INCLUDE_ASM(s32, "C50A0", draw_coin_sparkles);

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return gCurrentItemEntities[itemEntityIndex];
}

void item_entity_disable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags |= ENTITY_FLAGS_CONTINUOUS_COLLISION;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags |= SHADOW_FLAGS_HIDDEN;
    }
}

void item_entity_enable_shadow(ItemEntity* itemEntity) {
    Shadow* shadow;

    itemEntity->flags &= ~ENTITY_FLAGS_CONTINUOUS_COLLISION;
    if (itemEntity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(itemEntity->shadowIndex);
        shadow->flags &= ~SHADOW_FLAGS_HIDDEN;
    }
}

void clear_item_entity_data(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        gCurrentItemEntities[i] = NULL;
    }

    ItemEntitiesCreated = 0;
    D_80155D8C = 0;
    D_80155D8E = 0;
    D_80155D90 = 0;
    ItemEntityAlternatingSpawn = 0;

    if (!gGameStatusPtr->isBattle) {
        ItemEntityRenderGroup = 0;
    }

    create_generic_entity_world(NULL, draw_item_entities);
    create_generic_entity_frontUI(NULL, draw_item_entities_UI);
    isPickingUpItem = FALSE;
    D_801565A8 = 0;
}

void init_item_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentItemEntities = WorldItemEntities;
    } else {
        gCurrentItemEntities = BattleItemEntities;
    }

    isPickingUpItem = FALSE;
    D_801565A8 = 0;
    ItemEntitiesCreated = 0;
    ItemEntityAlternatingSpawn = 0;
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

s32 make_item_entity_at_player(s32 itemID, s32 arg1, s32 pickupMsgFlags) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    ItemEntity* item;
    Shadow* shadow;
    s32 i;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 depth;
    s32 id;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        if (gCurrentItemEntities[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ITEM_ENTITIES);
    id = i;

    gCurrentItemEntities[id] = item = heap_malloc(sizeof(*item));
    ItemEntitiesCreated++;
    ASSERT(item != NULL);

    itemID &= 0xFFFF;
    item->renderGroup = -1;
    item->flags = (ITEM_ENTITY_FLAGS_CAM0 | ITEM_ENTITY_FLAGS_CAM1 | ITEM_ENTITY_FLAGS_CAM2 | ITEM_ENTITY_FLAGS_10 | ITEM_ENTITY_FLAGS_2000000);
    if (arg1 != 0) {
        item->flags |= ITEM_ENTITY_FLAGS_4000000;
    }
    item->pickupMsgFlags = pickupMsgFlags;
    item->spawnType = ITEM_SPAWN_AT_PLAYER;
    item->state = 0;
    item->boundVar = 0;
    item->position.x = playerStatus->position.x;
    item->position.y = playerStatus->position.y;
    item->position.z = playerStatus->position.z;

    item->shadowIndex = -1;
    item->nextUpdate = 1;
    item->unk_34.x = -9999;
    item->unk_34.y = -9999;
    item->unk_34.z = -9999;
    item->scale = 1.0f;
    item->itemID = itemID;
    item->physicsData = NULL;
    item->pickupDelay = 0;
    item->wsFaceAngle = 0;
    item->flags |= ITEM_ENTITY_FLAGS_TINY;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags = (item->flags | ITEM_ENTITY_FLAGS_40000) & ~ITEM_ENTITY_FLAGS_TINY;
    }
    if (ItemEntityAlternatingSpawn != 0) {
        item->flags |= ITEM_ENTITY_FLAGS_20000;
    }
    ItemEntityAlternatingSpawn = 1 - ItemEntityAlternatingSpawn;

    item->shadowIndex = create_shadow_type(0, item->position.x, item->position.y, item->position.z);
    shadow = get_shadow_by_index(item->shadowIndex);
    shadow->flags |= 1;

    posX = item->position.x;
    posY = item->position.y + 12.0f;
    posZ = item->position.z;
    depth = 1000.0f;
    npc_raycast_down_sides(0x20000, &posX, &posY, &posZ, &depth);
    shadow->position.x = posX;
    shadow->position.y = posY;
    shadow->position.z = posZ;

    shadow->rotation.x = gGameStatusPtr->playerGroundTraceAngles.x;
    shadow->rotation.y = 0.0f;
    shadow->rotation.z = gGameStatusPtr->playerGroundTraceAngles.z;
    set_standard_shadow_scale(shadow, depth * 0.5f);

    item_entity_load(item);
    if (item->itemID == ITEM_COIN) {
        sparkle_script_init(item, &SparkleScript_Coin);
        sparkle_script_update(item);
    }
    return id;
}

INCLUDE_ASM(s32, "C50A0", item_entity_update);

void update_item_entities(void) {
    ItemEntity* entity;
    ItemEntity* entity2;
    f32 x, y, z, hitDepth;
    s32 coin;
    s32 i;

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800))) {
        for (i = 0; i < 0x100; i++) {
            entity = gCurrentItemEntities[i];

            if (entity != NULL && entity->flags != 0) {
                if (entity->itemID == ITEM_COIN) {
                    if (rand_int(100) > 90) {
                        sparkle_script_init(entity, &SparkleScript_Coin);
                        D_80155D8C = rand_int(16) - 8;
                        D_80155D8E = rand_int(16) - 8;
                        D_80155D90 = 5;
                    }
                    sparkle_script_update(entity);
                }

                item_entity_update(entity);

                switch (entity->spawnType) {
                    case ITEM_SPAWN_MODE_NOTHING:
                        update_item_entity_static(entity);
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        func_801356CC(entity);
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        update_item_entity_collectable(entity);
                        break;
                    case ITEM_SPAWN_AT_PLAYER:
                        update_item_entity_temp(entity);
                        break;
                }


                entity = gCurrentItemEntities[i];
                if (entity != NULL) {
                    s32 xs, ys, zs;

                    switch (entity->spawnType) {
                        case ITEM_SPAWN_MODE_NOTHING:
                        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                        case ITEM_SPAWN_AT_PLAYER:
                            xs = entity->position.x;
                            ys = entity->position.y;
                            zs = entity->position.z;

                            if (xs != entity->unk_34.x || ys != entity->unk_34.y || zs != entity->unk_34.z) {
                                Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

                                x = entity->position.x;
                                y = entity->position.y + 12.0f;
                                z = entity->position.z;
                                hitDepth = 1000.0f;
                                npc_raycast_down_sides(0x20000, &x, &y, &z, &hitDepth);

                                shadow->position.x = x;
                                shadow->position.y = y;
                                shadow->position.z = z;
                                shadow->rotation.x = gGameStatusPtr->playerGroundTraceAngles.x;
                                shadow->rotation.y = 0.0f;
                                shadow->rotation.z = gGameStatusPtr->playerGroundTraceAngles.z;
                                set_standard_shadow_scale(shadow, hitDepth * 0.5f);
                            }
                            break;
                    }
                    entity->unk_34.x = entity->position.x;
                    entity->unk_34.y = entity->position.y;
                    entity->unk_34.z = entity->position.z;
                }
            }
            do {} while (0); // required to match
        }
    }
}

INCLUDE_ASM(s32, "C50A0", appendGfx_item_entity);

void draw_item_entities(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    RenderTask* retTask;
    s32 i;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        ItemEntity* itemEntity = gCurrentItemEntities[i];

        if (itemEntity != NULL && itemEntity->flags != 0 && !(itemEntity->flags & ITEM_ENTITY_FLAGS_40) &&
            (itemEntity->flags & (1 << gCurrentCamID)) && !(itemEntity->flags & ITEM_ENTITY_FLAGS_100000) &&
            !(itemEntity->renderGroup != -1 && ItemEntityRenderGroup != itemEntity->renderGroup))
        {
            if (!(itemEntity->flags & ITEM_ENTITY_FLAGS_TRANSPARENT)) {
                rtPtr->renderMode = RENDER_MODE_ALPHATEST;
            } else {
                rtPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            }

            rtPtr->appendGfxArg = itemEntity;
            rtPtr->appendGfx = appendGfx_item_entity;
            rtPtr->distance = 0;

            retTask = queue_render_task(rtPtr);
            retTask->renderMode |= RENDER_MODE_2;
        }

        do {} while (0); // required to match
    }
}

void draw_item_entities_UI(void) {
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_4000 | GLOBAL_OVERRIDES_8000))) {
        s32 i;

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = gCurrentItemEntities[i];

            if (itemEntity != NULL && itemEntity->flags != 0) {
                switch (itemEntity->spawnType) {
                    case ITEM_SPAWN_MODE_NOTHING:
                        func_801356C4();
                        break;
                    case ITEM_SPAWN_MODE_DECORATION:
                    case ITEM_SPAWN_MODE_INVISIBLE:
                        func_801356D4();
                        break;
                    case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
                    case ITEM_SPAWN_MODE_TOSS_FADE1:
                        func_8013559C(itemEntity);
                        break;
                }
            }

            do {} while (0); // required to match
        }
    }
}

INCLUDE_ASM(s32, "C50A0", render_item_entities);

void remove_item_entity_by_reference(ItemEntity* entity) {
    s32 index;

    for (index = 0; index < MAX_ITEM_ENTITIES; index++) {
        if (gCurrentItemEntities[index] == entity) {
            break;
        }
    }

    if (index < MAX_ITEM_ENTITIES) {
        if (entity->physicsData != NULL) {
            heap_free(entity->physicsData);
        }

        switch (entity->spawnType) {
            case ITEM_SPAWN_MODE_NOTHING:
            case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
            case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
            case ITEM_SPAWN_AT_PLAYER:
                delete_shadow(entity->shadowIndex);
                break;
        }

        heap_free(gCurrentItemEntities[index]);
        isPickingUpItem = FALSE;
        gCurrentItemEntities[index] = NULL;
    }
}

void remove_item_entity_by_index(s32 index) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    switch (itemEntity->spawnType) {
        case ITEM_SPAWN_MODE_NOTHING:
        case ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS:
        case ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS:
        case ITEM_SPAWN_AT_PLAYER:
            delete_shadow(itemEntity->shadowIndex);
            break;
    }

    heap_free(gCurrentItemEntities[index]);
    gCurrentItemEntities[index] = NULL;
    isPickingUpItem = FALSE;
}

void func_80133A94(s32 idx, s32 itemID) {
    ItemEntity* item = gCurrentItemEntities[idx];

    item->itemID = itemID;

    item->flags |= ENTITY_FLAGS_4000;
    item->flags &= ~ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;

    if (gItemTable[itemID].typeFlags & ITEM_TYPE_FLAG_ENTITY_FULLSIZE) {
        item->flags |= ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;
        item->flags &= ~ENTITY_FLAGS_4000;
    }

    item_entity_load(item);
}

INCLUDE_ASM(s32, "C50A0", test_item_player_collision);

s32 test_item_entity_position(f32 x, f32 y, f32 z, f32 dist) {
    ItemEntity* item;
    f32 dx, dy, dz;
    s32 i;

    if (is_starting_conversation() || isPickingUpItem || get_time_freeze_mode() != 0 ||
        gOverrideFlags & GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    {
        return -1;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++){
        item = gCurrentItemEntities[i];

        if (item == NULL) {
            continue;
        }

        if (!item->flags) {
            continue;
        }

        if (item->spawnType == ENTITY_TYPE_SHADOW) {
            continue;
        }

        if (item->spawnType == ENTITY_TYPE_2) {
            continue;
        }

        if (item->flags & ENTITY_FLAGS_CONTINUOUS_COLLISION) {
            continue;
        }

        if (item->flags & ENTITY_FLAGS_200000) {
            continue;
        }

        dx = item->position.x - x;
        dz = item->position.y - y;
        dy = item->position.z - z;
        if (sqrtf(SQ(dx) + SQ(dz) + SQ(dy)) < dist) {
            return i;
        }
    }
    return -1;
}

void set_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    itemEntity->flags |= flags;
    if (itemEntity->flags & ENTITY_FLAGS_200000) {
        D_801565A8 = 1;
    }
}

void clear_item_entity_flags(s32 index, s32 flags) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];

    itemEntity->flags &= ~flags;
}

void func_801341B0(s32 index) {
    ItemEntity* itemEntity = gCurrentItemEntities[index];
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    itemEntity->flags |= ENTITY_FLAGS_100;
}

/// @returns TRUE when "you got X" popup is on-screen
s32 is_picking_up_item(void) {
    s32 ret = D_801565A8 != 0;

    if (isPickingUpItem) {
        ret = TRUE;
    }
    return ret;
}

void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z) {
    ItemEntity* itemEntity = gCurrentItemEntities[itemEntityIndex];

    itemEntity->position.x = x;
    itemEntity->position.y = y;
    itemEntity->position.z = z;
}

void set_current_item_entity_render_group(s32 group) {
    ItemEntityRenderGroup = group;
}

s32 get_current_item_entity_render_group(void) {
    return ItemEntityRenderGroup;
}

INCLUDE_ASM(s32, "C50A0", update_item_entity_collectable);

void func_8013559C(ItemEntity* itemEntity) {
    if (itemEntity->state == 1) {
        ItemEntityPhysicsData* physicsData = itemEntity->physicsData;
        s32 flag = (itemEntity->flags & ITEM_ENTITY_FLAGS_20000) > 0;

        if (itemEntity->spawnType != ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS) {
            if (itemEntity->spawnType != ITEM_SPAWN_MODE_TOSS_FADE1) {
                if (physicsData->unk_1C < 60) {
                    if ((itemEntity->flags & ITEM_ENTITY_FLAGS_200000) || ((gGameStatusPtr->frameCounter + flag) & 1)) {
                        itemEntity->flags &= ~ITEM_ENTITY_FLAGS_40;
                    } else {
                        itemEntity->flags |= ITEM_ENTITY_FLAGS_40;
                    }
                }
            } else {
                if (physicsData->unk_1C < 10) {
                    itemEntity->alpha = physicsData->unk_1C * 28;
                    itemEntity->flags |= ITEM_ENTITY_FLAGS_TRANSPARENT;
                }
            }
        }
    }
}

void update_item_entity_static(ItemEntity* itemEntity) {
    if (itemEntity->state == 0 && test_item_player_collision(itemEntity)) {
        isPickingUpItem = TRUE;
        itemEntity->spawnType = ITEM_SPAWN_AT_PLAYER;
        itemEntity->state = 0;
        D_801565A8 = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }
}

void func_801356C4(void) {
}

void func_801356CC(ItemEntity* itemEntity) {
}

void func_801356D4(void) {
}

INCLUDE_ASM(s32, "C50A0", update_item_entity_temp);

INCLUDE_ASM(s32, "C50A0", func_801363A0);

INCLUDE_ASM(s32, "C50A0", func_8013673C);

void func_801369D0(s32 arg1, s32 x, s32 y) {
    draw_msg(MESSAGE_ID(0x1D,0x060), x + 12, y + 4, 255, 52, 0);
}

void func_80136A08(ItemEntity* itemEntity, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 itemMsg;

    switch (itemEntity->state) {
        case 2:
        case 3:
        case 10:
        case 11:
            itemMsg = itemData->shortDescMsg;
            draw_msg(itemMsg, posX + 8, posY, 255, 10, 0);
            break;
    }
}
