#include "common.h"
#include "effects.h"

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

void draw_item_entities(void);
void func_80132D94(void);

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

INCLUDE_ASM(s32, "C50A0", make_item_entity_at_player);

INCLUDE_ASM(s32, "C50A0", item_entity_update);

INCLUDE_ASM(s32, "C50A0", update_item_entities);

INCLUDE_ASM(s32, "C50A0", appendGfx_item_entity);
void appendGfx_item_entity(ItemEntity* itemEntity);

void draw_item_entities(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    RenderTask* retTask;
    s32 i;

    for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
        ItemEntity* itemEntity = D_801565A0[i];

        if (itemEntity != NULL && itemEntity->flags != 0 && !(itemEntity->flags & 0x40) &&
            (itemEntity->flags & (1 << gCurrentCamID)) && !(itemEntity->flags & 0x100000) &&
            !(itemEntity->unk_1D != -1 && D_80155D88 != itemEntity->unk_1D))
        {
            if (!(itemEntity->flags & 0x80000)) {
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

void func_80132D94(void) {
    if (!(gOverrideFlags & 0xC000)) {
        s32 i;

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = D_801565A0[i];

            if (itemEntity != NULL && itemEntity->flags != 0) {
                switch (itemEntity->type) {
                    case 0:
                        func_801356C4();
                        break;
                    case 1:
                    case 2:
                        func_801356D4();
                        break;
                    case 3:
                    case 12:
                    case 16:
                    case 20:
                    case 23:
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

s32 test_item_entity_position(f32 x, f32 y, f32 z, f32 dist) {
    ItemEntity* item;
    f32 dx, dy, dz;
    s32 i;

    if (is_starting_conversation() || D_801565A4 || get_time_freeze_mode() != 0 ||
        gOverrideFlags & GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    {
        return -1;
    }

    for (i = 0; i < MAX_ITEM_ENTITIES; i++){
        item = D_801565A0[i];

        if (item == NULL) {
            continue;
        }

        if (!item->flags) {
            continue;
        }

        if (item->type == ENTITY_TYPE_SHADOW) {
            continue;
        }

        if (item->type == ENTITY_TYPE_2) {
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

extern s32 D_80155D80;

INCLUDE_ASM(s32, "C50A0", update_item_entity_collectable);
// void update_item_entity_collectable(ItemEntity* itemEntity) {
//     PlayerStatus* playerStatus = &gPlayerStatus;
//     PlayerData* playerData = &gPlayerData;
//     f32 sp20;
//     f32 sp24;
//     f32 sp28;
//     f32 sp2C;
//     ItemEntityPhysicsData* temp_s1;
//     ItemEntityPhysicsData* temp_s1_2;
//     ItemEntityPhysicsData* temp_v0_2;
//     f32 temp_f0;
//     f32 temp_f0_3;
//     f32 temp_f0_4;
//     f32 temp_f0_5;
//     f32 temp_f20;
//     f32 temp_f22;
//     f32 temp_f22_2;
//     f32 temp_f24;
//     f32 temp_f2;
//     f32 temp_f2_2;
//     f32 temp_f4;
//     f32 temp_f4_2;
//     f32* temp_v0_10;
//     f64 temp_f0_2;
//     s16 temp_v0_3;
//     s16 temp_v0_6;
//     s32 temp_s0;
//     s32 temp_v0_9;
//     s32 temp_v1_2;
//     s32 temp_v1_8;
//     s8 temp_a0;
//     s8 temp_v0_4;
//     s8 temp_v0_5;
//     s8 temp_v0_8;
//     s8 temp_v1;
//     s8 temp_v1_10;
//     s8 temp_v1_7;
//     s8 temp_v1_9;
//     u16 temp_v1_11;
//     u16 temp_v1_3;
//     u16 temp_v1_5;
//     u32 temp_v0_7;
//     s32 phi_v0;
//     s32 phi_v0_2;
//     s32 phi_v0_3;
//     s32 phi_a0;
//     f32 phi_f0;
//     f32 phi_f12;
//     s32 phi_v0_4;
//     f32 phi_f12_2;
//     f32 phi_f20;
//     f32 phi_f24;
//     s32 phi_v0_5;
//     u8 phi_v0_6;
//     s32 phi_a0_2;
//     s32 phi_a0_3;
//     s8 phi_v1_2;
//     f32 phi_f12_3;
//     s32 phi_v0_7;

//     if (D_801565A4 == 0) {
//         if (itemEntity->pickupDelay != 0) {
//             itemEntity->pickupDelay--;
//             return;
//         }
//         temp_v1 = itemEntity->type;
//         temp_a0 = itemEntity->state;
//         temp_s0 = temp_v1 == 0x17;
//         switch (temp_a0) {                          /* irregular */
//             case 0:
//                 item_entity_enable_shadow(itemEntity);
//                 temp_v0_2 = heap_malloc(0x24);
//                 temp_s1 = temp_v0_2;
//                 itemEntity->physicsData = temp_s1;
//                 if (temp_s1 == 0) {
//     loop_7:
//                     goto loop_7;
//                 }
//                 temp_v1_2 = itemEntity->flags;
//                 if ((temp_v1_2 & 0x01000000) != 0) {
//                     phi_f0 = 16.0f;
//                 } else if ((temp_v1_2 & 0x10000) == 0) {
//                     phi_f0 = 12.0f;
//                 } else {
//                     phi_f0 = 14.0f;
//                 }
//                 temp_s1->verticalVelocity = phi_f0;
//                 temp_s1->gravity = 2.0f;
//                 temp_s1->unk_08 = 24.0f;
//                 temp_s1->constVelocity = 24.0f;
//                 temp_v0_3 = itemEntity->wsFaceAngle;
//                 if ((s32) temp_v0_3 < 0) {
//                     temp_v1_3 = (u16) itemEntity->itemID;
//                     if ((u32) (temp_v1_3 - 0x10) < 0xCBU) {
//                         if (rand_int(0x2710) < 0x1388) {
//                             phi_f12 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) + 105.0f;
//                             phi_v0_4 = rand_int(0x1E);
//                         } else {
//                             phi_f12 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) - 105.0f;
//                             phi_v0_4 = rand_int(0x1E);
//                         }
//                         temp_s1->moveAngle = clamp_angle((phi_f12 + (f32) phi_v0_4) - 15.0f);
//                         temp_s1->verticalVelocity += 4.0f;
//                     } else if ((s16) temp_v1_3 != 0x158) {
//                         if ((s32) (s16) temp_v1_3 < 0x159) {
//                             if ((s16) temp_v1_3 != 0x156) {
//                                 if ((s32) (s16) temp_v1_3 < 0x157) {
//                                     if ((s16) temp_v1_3 != 0x10) {
//                                         temp_s1->moveAngle = 0.0f;
//                                     } else {
//                                         if (rand_int(0x2710) >= 0x1388) {
//                                             phi_f12_3 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f;
//                                             phi_v0_7 = rand_int(0x78);
//                                         } else {
//                                             goto block_43;
//                                         }
//                                         goto block_44;
//                                     }
//                                 } else {
//                                     if (rand_int(0x2710) >= 0x1388) {
//                                         phi_f12_3 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f;
//                                         phi_v0_7 = rand_int(0x78);
//                                     } else {
//                                         goto block_43;
//                                     }
//                                     goto block_44;
//                                 }
//                             } else {
//                                 goto block_43;
//                             }
//                         } else if ((s16) temp_v1_3 != 0x15A) {
//                             if ((s32) (s16) temp_v1_3 >= 0x15A) {
//                                 if ((s16) temp_v1_3 != 0x15B) {
//                                     if ((s16) temp_v1_3 != 0x15C) {
//                                         temp_s1->moveAngle = 0.0f;
//                                     } else {
//                                         if (rand_int(0x2710) < 0x1388) {
//                                             phi_f12_2 = (*(&gCameras->currentYaw + (temp_s0 * 0x558)) + 90.0f + (f32) rand_int(0x3C)) - 30.0f;
//                                         } else {
//                                             phi_f12_2 = ((*(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f) + (f32) rand_int(0x3C)) - 30.0f;
//                                         }
//                                         goto block_45;
//                                     }
//                                 } else {
//                                     phi_f12_2 = (*(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f) + (f32) rand_int(0x78) + 60.0f;
//                                     goto block_45;
//                                 }
//                             } else {
//                                 if (itemEntity->type != 0x17) {
//                                     phi_f12_3 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f;
//                                     phi_v0_7 = rand_int(0x78);
//                                     goto block_44;
//                                 }
//                                 if (rand_int(0x2710) < 0x1388) {
//                                     phi_f12_2 = (*(&gCameras->currentYaw + (temp_s0 * 0x558)) + 90.0f + (f32) rand_int(0x3C)) - 30.0f;
//                                 } else {
//                                     phi_f12_2 = ((*(&gCameras->currentYaw + (temp_s0 * 0x558)) - 90.0f) + (f32) rand_int(0x3C)) - 30.0f;
//                                 }
//                                 goto block_45;
//                             }
//                         } else {
//                             goto block_43;
//                         }
//                     } else {
//     block_43:
//                         phi_f12_3 = *(&gCameras->currentYaw + (temp_s0 * 0x558)) + 90.0f;
//                         phi_v0_7 = rand_int(0x78);
//     block_44:
//                         phi_f12_2 = (phi_f12_3 + (f32) phi_v0_7) - 60.0f;
//     block_45:
//                         temp_s1->moveAngle = clamp_angle(phi_f12_2);
//                     }
//                     if ((itemEntity->flags & 0x01000000) == 0) {
//                         phi_f20 = (temp_s1->moveAngle * 6.28318f) / 360.0f;
//                         phi_f24 = (f32) ((f64) ((f32) rand_int(0x7D0) / 1000.0f) + 1.5);
//                     } else {
//                         phi_f20 = (temp_s1->moveAngle * 6.28318f) / 360.0f;
//                         phi_f24 = (f32) ((f64) ((f32) rand_int(0x7D0) / 1000.0f) + 2.0);
//                     }
//                 } else {
//                     temp_s1->moveAngle = clamp_angle((f32) temp_v0_3);
//                     if ((itemEntity->flags & 0x40000000) == 0) {
//                         phi_f24 = (f32) (((f64) (s16) (itemEntity->wsFaceAngle / 360) * 0.6) + 1.5);
//                     } else {
//                         phi_f24 = 2.1f;
//                     }
//                     phi_f20 = (temp_s1->moveAngle * 6.28318f) / 360.0f;
//                 }
//                 temp_f22 = sin_rad(phi_f20);
//                 temp_f2 = -phi_f24 * cos_rad(phi_f20);
//                 temp_s1->velx = phi_f24 * temp_f22;
//                 temp_s1->velz = temp_f2;
//                 if (itemEntity->type != 0x17) {
//                     temp_s1->unk_1C = 180;
//                     temp_s1->unk_20 = 0;
//                 } else {
//                     phi_v0_5 = 0x14;
//                     if ((itemEntity->flags & 0x400000) == 0) {
//                         phi_v0_5 = 0x11;
//                     }
//                     temp_s1->unk_1C = phi_v0_5;
//                     temp_s1->unk_20 = 0;
//                     temp_s1->verticalVelocity = 15.0f;
//                     temp_s1->gravity = 1.6f;
//                 }
//                 if (itemEntity->type == 0x14) {
//                     temp_s1->unk_1C = 0x3C;
//                     temp_s1->unk_20 = 0;
//                     temp_s1->velx = 0.0f;
//                     temp_s1->velz = 0.0f;
//                 }
//                 phi_v0_6 = (u8) 1;
//                 if (itemEntity->type == 0xC) {
//                     temp_s1->verticalVelocity = 0.0f;
//                     temp_s1->velx = 0.0f;
//                     temp_s1->velz = 0.0f;
//                     temp_s1->unk_20 = 1;
//                 }
//                 if (itemEntity->type == 0x10) {
//                     temp_s1->verticalVelocity = 0.0f;
//                     temp_s1->velx = 0.0f;
//                     temp_s1->velz = 0.0f;
//                     temp_s1->unk_20 = 1;
//                 }
//                 if ((itemEntity->flags & 0x800) != 0) {
//                     set_global_flag((s32) itemEntity->boundVar);
//                 }
//     block_139:
//                 itemEntity->state = phi_v0_6;
//             case 1:
//                 temp_s1_2 = itemEntity->physicsData;
//                 if ((temp_v1 == 0x14) || (temp_v1 == 0x17) || (temp_s1_2->unk_20 == 0) || (phi_v0_6 = 3U, (test_item_player_collision(itemEntity) == 0))) {
//                     temp_v1_8 = itemEntity->flags;
//                     phi_v0 = temp_v1_8 & 0x2000;
//                     if ((temp_v1_8 & 0x200) == 0) {
//                         phi_v0 = temp_v1_8 & 0x2000;
//                         if ((gOverrideFlags & 0x300) == 0) {
//                             phi_v0 = temp_v1_8 & 0x2000;
//                             if ((temp_v1_8 & 0x200000) == 0) {
//                                 temp_v0_9 = temp_s1_2->unk_1C - 1;
//                                 temp_s1_2->unk_1C = temp_v0_9;
//                                 if (temp_v0_9 >= 0) {
//                                     phi_v0 = itemEntity->flags & 0x2000;
//                                     goto block_75;
//                                 }
//                                 goto block_138;
//                             }
//                         }
//                     }
//     block_75:
//                     if ((phi_v0 == 0) && ((itemEntity->flags & 0x200000) == 0)) {
//                         temp_f4 = temp_s1_2->verticalVelocity - temp_s1_2->gravity;
//                         temp_s1_2->verticalVelocity = temp_f4;
//                         if ((f64) temp_f4 < -16.0) {
//                             temp_s1_2->verticalVelocity = -16.0f;
//                         }
//                         itemEntity->position.y += temp_s1_2->verticalVelocity;
//                         itemEntity->position.x += temp_s1_2->velx;
//                         itemEntity->position.z += temp_s1_2->velz;
//                     }
//                     if ((itemEntity->type != 0x14) || (phi_v0_6 = 3U, !(temp_s1_2->verticalVelocity <= 0.0f))) {
//                         if ((itemEntity->flags & 0x30000000) == 0) {
//                             temp_v1_9 = itemEntity->type;
//                             if ((temp_v1_9 != 0x14) && (temp_v1_9 != 0x17)) {
//                                 temp_v0_10 = &sp2C;
//                                 if (temp_s1_2->verticalVelocity > 0.0f) {
//                                     temp_f24 = temp_s1_2->constVelocity;
//                                     sp20 = itemEntity->position.x;
//                                     sp24 = itemEntity->position.y;
//                                     sp28 = itemEntity->position.z;
//                                     sp2C = temp_f24 + temp_s1_2->verticalVelocity;
//                                     if ((npc_raycast_up(0x20000, &sp20, &sp24, &sp28, temp_v0_10) != 0) && (sp2C < temp_f24)) {
//                                         itemEntity->position.y = sp24 - temp_f24;
//                                         temp_s1_2->verticalVelocity = 0.0f;
//                                     }
//                                 }
//                             }
//                             if ((itemEntity->flags & 0x30000000) == 0) {
//                                 temp_v1_10 = itemEntity->type;
//                                 if ((temp_v1_10 != 0x14) && (temp_v1_10 != 0x17) && ((temp_s1_2->velx != 0.0f) || (temp_s1_2->velz != 0.0f))) {
//                                     sp20 = itemEntity->position.x;
//                                     sp24 = itemEntity->position.y;
//                                     sp28 = itemEntity->position.z;
//                                     if (temp_s1_2->unk_20 == 0) {
//                                         phi_v0_2 = npc_test_move_complex_with_slipping(0x20000, &sp20, &sp24, &sp28, 0.0f, temp_s1_2->moveAngle, temp_s1_2->constVelocity, temp_s1_2->unk_08);
//                                     } else {
//                                         phi_v0_2 = npc_test_move_simple_with_slipping(0x20000, &sp20, &sp24, &sp28, 0.0f, temp_s1_2->moveAngle, temp_s1_2->constVelocity, temp_s1_2->unk_08);
//                                     }
//                                     if (phi_v0_2 != 0) {
//                                         itemEntity->position.x = sp20;
//                                         itemEntity->position.y = sp24;
//                                         itemEntity->position.z = sp28;
//                                         temp_f0 = clamp_angle(temp_s1_2->moveAngle + 180.0f);
//                                         temp_f2_2 = temp_f0 * TAU;
//                                         temp_s1_2->moveAngle = temp_f0;
//                                         temp_f20 = temp_f2_2 / 360.0f;
//                                         temp_f22_2 = sin_rad(temp_f20);
//                                         temp_f0_2 = (f64) cos_rad(temp_f20) * -2.0;
//                                         temp_s1_2->velx = (f32) (2.0 * (f64) temp_f22_2);
//                                         temp_s1_2->velz = (f32) temp_f0_2;
//                                     }
//                                 }
//                             }
//                         }
//                         if (!(itemEntity->flags & 0x10000000) && itemEntity->type != 0x14) {
//                             phi_v0_3 = 1;
//                             if (temp_s1_2->verticalVelocity <= 0.0) {
//                                 temp_s1_2->unk_20 = 1;
//                                 if (itemEntity->type != 0x17) {
//                                     sp20 = itemEntity->position.x;
//                                     sp28 = itemEntity->position.z;
//                                     sp2C = -temp_s1_2->verticalVelocity + 12.0f;
//                                     sp24 = (itemEntity->position.y - temp_s1_2->verticalVelocity) + 12.0f;
//                                     if (temp_s1_2->unk_20 == 0) {
//                                         phi_v0_3 = npc_raycast_down_sides(0x20000, &sp20, &sp24, &sp28, &sp2C);
//                                     } else {
//                                         phi_v0_3 = npc_raycast_down_around(0x20000, &sp20, &sp24, &sp28, &sp2C, 180.0f, 20.0f);
//                                     }
//                                 } else {
//                                     temp_f0_3 = temp_s1_2->verticalVelocity;
//                                     temp_f0_4 = -temp_f0_3 + 12.0f;
//                                     sp20 = itemEntity->position.x;
//                                     temp_f4_2 = (itemEntity->position.y - temp_f0_3) + 12.0f;
//                                     sp2C = temp_f0_4;
//                                     sp28 = itemEntity->position.z;
//                                     sp24 = temp_f4_2;
//                                     if (temp_f4_2 < (temp_f0_4 + 0.0f)) {
//                                         sp24 = 0.0f;
//                                     } else {
//                                         phi_v0_3 = 0;
//                                     }
//                                 }
//                                 if (phi_v0_3 != 0) {
//                                     itemEntity->position.y = sp24;
//                                     temp_f0_5 = (f32) ((f64) -temp_s1_2->verticalVelocity / 1.25);
//                                     temp_s1_2->verticalVelocity = temp_f0_5;
//                                     if ((f64) temp_f0_5 < 3.0) {
//                                         temp_s1_2->verticalVelocity = 0.0f;
//                                         temp_s1_2->velx = 0.0f;
//                                         temp_s1_2->velz = 0.0f;
//                                         itemEntity->flags |= 0x20000000;
//                                     } else {
//                                         temp_v1_11 = (u16) itemEntity->itemID;
//                                         phi_a0 = 0x21B;
//                                         if ((u32) (temp_v1_11 - 0xE0) < 0x75U) {
//                                             goto block_136;
//                                         }
//                                         phi_a0 = 0x21A;
//                                         if ((u32) ((temp_v1_11 - 0x10) & 0xFFFF) < 0xCBU) {
//                                             goto block_136;
//                                         }
//                                         switch (itemEntity->itemID) {
//                                             case 0x156:
//         block_136:
//                                                 sfx_play_sound_at_position(0x214, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x157:
//                                                 sfx_play_sound_at_position(0x212, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x10:
//                                                 sfx_play_sound_at_position(0x212, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x158:
//                                                 sfx_play_sound_at_position(0x214, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x159:
//                                                 sfx_play_sound_at_position(0x212, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x15A:
//                                                 sfx_play_sound_at_position(0x214, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x15C:
//                                                 sfx_play_sound_at_position(0x219, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                             case 0x15B:
//                                                 sfx_play_sound_at_position(0x218, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                                 break;
//                                         }
//                                     }
//                                 }
//                             }
//                         }
//                         if (itemEntity->position.y < -2000.0f) {
//     block_138:
//                             phi_v0_6 = 2U;
//                             goto block_139;
//                         }
//                     } else {
//                         goto block_139;
//                     }
//                 } else {
//                     goto block_139;
//                 }
//                 goto block_140;
//             default:
//     block_140:
//                 if (itemEntity->state == 2) {
//                     remove_item_entity_by_reference(itemEntity);
//                 }
//                 if (itemEntity->state == 3) {
//                     if (itemEntity->flags & 0x400) {
//                         set_global_flag((s32) itemEntity->boundVar);
//                     }
//                     fx_small_gold_sparkle(0, itemEntity->position.x, itemEntity->position.y + 16.0f, itemEntity->position.z, 1.0f, 0);
//                     temp_v1_5 = (u16) itemEntity->itemID;
//                     if (((u32) (temp_v1_5 - 0x10) >= 0xCBU) && ((u32) ((temp_v1_5 - 0xE0) & 0xFFFF) >= 0x75U)) {
//                         if ((s16) temp_v1_5 == 0x15C) {
//                             playerData->starPiecesCollected = (u16) playerData->starPiecesCollected + 1;
//                             goto block_149;
//                         }
//                         if (itemEntity->type == 0x17) {
//                             itemEntity->itemID = -1;
//                         }

//                         switch (itemEntity->itemID) {
//                             case 0x156:
//                                 if ((s32) playerData->curHP < (s32) playerData->curMaxHP) {
//                                     fx_recover(0, playerStatus->position.x, playerStatus->position.y + (f32) playerStatus->colliderHeight, playerStatus->position.z, 1);
//                                     sfx_play_sound_at_position(0x2056, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                 }
//                                 temp_v0_4 = (u8) playerData->curHP + 1;
//                                 playerData->curHP = temp_v0_4;
//                                 if ((s32) playerData->curMaxHP < (s32) temp_v0_4) {
//                                     playerData->curHP = (s8) (u8) playerData->curMaxHP;
//                                 }
//                                 phi_a0_2 = 0x213;
//         block_173:
//                                 sfx_play_sound_at_position(phi_a0_2, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                 fx_sparkles(4, playerStatus->position.x, playerStatus->position.y + (f32) playerStatus->colliderHeight, playerStatus->position.z, 30.0f);
//                                 break;
//                             case 0x15B:
//                                 if ((s32) playerData->curFP < (s32) playerData->curMaxFP) {
//                                     fx_recover(1, playerStatus->position.x, playerStatus->position.y + (f32) playerStatus->colliderHeight, playerStatus->position.z, 1);
//                                     sfx_play_sound_at_position(0x2056, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                 }
//                                 temp_v0_5 = (u8) playerData->curFP + 1;
//                                 playerData->curFP = temp_v0_5;
//                                 if ((s32) playerData->curMaxFP < (s32) temp_v0_5) {
//                                     playerData->curFP = (s8) (u8) playerData->curMaxFP;
//                                 }
//                                 phi_a0_2 = 0x217;
//                                 goto block_173;
//                             case 0x157:
//                                 temp_v0_6 = (u16) playerData->coins + 1;
//                                 playerData->coins = temp_v0_6;
//                                 if ((s32) temp_v0_6 >= 0x3E8) {
//                                     playerData->coins = 0x3E7;
//                                 }
//                                 sfx_play_sound_at_position(0x211, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                 temp_v0_7 = playerData->totalCoinsEarned + 1;
//                                 playerData->totalCoinsEarned = temp_v0_7;
//                                 if (temp_v0_7 > 0x1869FU) {
//                                     playerData->totalCoinsEarned = 0x1869F;
//                                 }
//                                 break;
//                             case 0x10:
//                                 playerData->fortressKeyCount = (u8) playerData->fortressKeyCount + 1;
//                                 phi_a0_3 = 0x211;
//         block_185:
//                                 sfx_play_sound_at_position(phi_a0_3, 0, itemEntity->position.x, itemEntity->position.y, itemEntity->position.z);
//                                 break;
//                             case 0x159:
//                                 temp_v0_8 = (u8) playerData->starPoints + 1;
//                                 playerData->starPoints = temp_v0_8;
//                                 if ((s32) temp_v0_8 >= 0x65) {
//                                     playerData->starPoints = 0x64;
//                                 }
//                                 phi_a0_3 = 0x211;
//                                 goto block_185;
//                             case 0x15A:
//                                 playerData->curHP = (s8) (u8) playerData->curMaxHP;
//                                 playerData->curFP = (s8) (u8) playerData->curMaxFP;
//                                 phi_a0_3 = 0x213;
//                                 goto block_185;
//                         }
//                         D_801565A8 = 0;
//                         gOverrideFlags &= -0x41;
//                         remove_item_entity_by_reference(itemEntity);
//                     } else {
//     block_149:
//                         itemEntity->state = 0xA;
//                     }
//                 }
//                 temp_v1_7 = (s8) itemEntity->state;
//                 phi_v1_2 = temp_v1_7;
//                 if (temp_v1_7 == 4) {
//                     if (does_script_exist(D_80155D80) == 0) {
//                         D_801565A8 = 0;
//                         remove_item_entity_by_reference(itemEntity);
//                         resume_all_group(2);
//                     }
//                     phi_v1_2 = (s8) itemEntity->state;
//                 }
//                 if (phi_v1_2 == 0xA) {
//                     D_801565A4 = 1;
//                     itemEntity->type = 0x1C;
//                     itemEntity->state = 0;
//                     D_801565A8 = 0;
//                     gOverrideFlags |= 0x40;
//                 }
//                 break;
//         }
//     }
// }

void func_8013559C(ItemEntity* itemEntity) {
    if (itemEntity->state == 1) {
        ItemEntityPhysicsData* physicsData = itemEntity->physicsData;
        s32 flag = (itemEntity->flags & 0x20000) > 0;

        if (itemEntity->type != 0x14) {
            if (itemEntity->type != 0x17) {
                if (physicsData->unk_1C < 60) {
                    if ((itemEntity->flags & 0x200000) || ((gGameStatusPtr->frameCounter + flag) & 1)) {
                        itemEntity->flags &= ~0x40;
                    } else {
                        itemEntity->flags |= 0x40;
                    }
                }
            } else {
                if (physicsData->unk_1C < 0xA) {
                    itemEntity->unk_2F = physicsData->unk_1C * 28;
                    itemEntity->flags |= 0x80000;
                }
            }
        }
    }
}

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


extern s32 D_8014C6E4[];
extern s32 D_801568E0;
extern s32 D_801568EC;
INCLUDE_ASM(s32, "C50A0", func_8013673C);
/*void func_8013673C(ItemEntity* itemEntity, s32 posX, s32 posY) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 offsetY;
    u16 itemTypeFlags;
    u16 temp_v1_2;
    s32 msgID;
    s32 phi_a1;

    switch (itemEntity->state) {
        case 2:
        case 3:
        case 10:
        case 11:
            if (!(itemData->typeFlags & 0x40)) {
                if (itemEntity->flags & 0x04000000) {
                    if (itemEntity->unk_06 & 4) {
                        msgID = 0x1D0058;
                    } else {
                        msgID = 0x1D005A;
                    }
                } else {
                    msgID = 0x1D0058;
                }

                set_message_msg(itemData->nameMsg, 0);

                if (itemEntity->unk_06 & 0x10) {
                    msgID = 0x1D005D;
                }
                if (itemEntity->unk_06 & 0x20) {
                    msgID = 0x1D005E;
                }
                if (itemEntity->unk_06 & 0x40) {
                    msgID = 0x1D005C;
                }
            } else {
                if (itemEntity->flags & 0x04000000) {
                    if (itemEntity->unk_06 & 4) {
                        msgID = 0x1D0059;
                    } else {
                        msgID = 0x1D005B;
                    }
                } else {
                    msgID = 0x1D0059;
                }

                if (itemEntity->unk_06 & 0x10) {
                    msgID = 0x1D005D;
                }
                if (itemEntity->unk_06 & 0x20) {
                    msgID = 0x1D005E;
                }
                if (itemEntity->unk_06 & 0x40) {
                    msgID = 0x1D005C;
                }
                set_message_msg(itemData->nameMsg, 0);
            }

            offsetY = D_8014C6E4[get_msg_lines(msgID) - 1];
            itemTypeFlags = gItemTable[itemEntity->itemID].typeFlags;

            if (!(itemTypeFlags & 0x40) && !(itemTypeFlags & 8) && (itemEntity->itemID != 0x15C)) {
                if (!(itemTypeFlags & 0x20)) {
                    if (itemEntity->unk_06 & 0x30) {
                        draw_msg(msgID, posX + 15, posY + offsetY, 255, 0x2F, 0);
                    } else {
                        draw_msg(msgID, posX + 40, posY + offsetY, 255, 0x2F, 0);

                        if (!(itemEntity->unk_06 & 0x30)) {
                            set_hud_element_render_pos(D_801568E0, posX + 20, posY + 20);
                            draw_hud_element_2(D_801568E0);
                        }
                    }
                    return;
                }
            }
            draw_msg(msgID, posX + 15, posY + offsetY, 255, 0x2F, 0);
            break;
        case 13:
        case 14:
            set_message_msg(gItemTable[D_801568EC].nameMsg, 0);
            draw_msg(0x1D005F, posX + 40, posY + 4, 255, 0x2F, 0);
            set_hud_element_render_pos(D_801568E0, posX + 20, posY + 20);
            draw_hud_element_2(D_801568E0);
            break;
    }
}*/

void func_801369D0(s32 arg1, s32 x, s32 y) {
    draw_msg(0x1D0060, x + 12, y + 4, 255, 52, 0);
}

void func_80136A08(ItemEntity* itemEntity, s32 posX, s32 arg2) {
    ItemData* itemData = &gItemTable[itemEntity->itemID];
    s32 itemMsg;

    switch (itemEntity->state) {
        case 2:
        case 3:
        case 10:
        case 11:
            itemMsg = itemData->itemMsg;
            draw_msg(itemMsg, posX + 8, arg2, 255, 0xA, 0);
            break;
    }
}
