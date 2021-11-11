#include "common.h"
#include "effects.h"

extern u32* D_802EA728;
extern u32* D_802EA760;
extern StaticEntityData D_802EA7BC;
extern UNK_TYPE D_802EB3C0;
extern s32 D_802EA744; //

f32 entity_HeartBlockContent_get_previous_yaw(struct802E4B10* data, s32 arg1) {
    s32 temp = data->unk_24 - arg1;
    if (temp < 0) {
        temp += 10;
    }
    return data->unk_28[temp];
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent__setupGfx);

void entity_HeartBlockContent_setupGfx(s32 entityIndex) {
    entity_HeartBlockContent__setupGfx(entityIndex, &D_0A000808);
}

void entity_HeartBlockContent_set_initial_pos(Entity* entity) {
    struct802E4B10* temp = (struct802E4B10*)entity->dataBuf;
    Entity* entityTemp = get_entity_by_index(temp->unk_00);

    entity->position.x = entityTemp->position.x;
    entity->position.y = entityTemp->position.y + 14.0f;
    entity->position.z = entityTemp->position.z;
}

void entity_HeartBlockContent__reset(Entity* entity) {
    struct802E4B10* temp_s0;
    Entity* someEntity;

    entity->renderSetupFunc = entity_HeartBlockContent_setupGfx;
    entity->alpha = 255;
    temp_s0 = (struct802E4B10*)entity->dataBuf;
    entity->flags |= ENTITY_FLAGS_ALWAYS_FACE_CAMERA;
    someEntity = get_entity_by_index(temp_s0->unk_00);

    if (temp_s0->unk_09 == 0) {
        temp_s0->unk_09 = 1;
        temp_s0->unk_01 = 2;
        entity->scale.x = 1.0f;
    } else {
        temp_s0->unk_01 = 0;
        entity->scale.x = 0.0f;
    }

    temp_s0->unk_0C = 0;
    temp_s0->unk_10 = 0;
    entity->rotation.x = 0.0f;
    entity->rotation.y = 0.0f;
    entity->rotation.z = 0.0f;
    entity->scale.y = entity->scale.x;
    entity->scale.z = entity->scale.x;

    entity_HeartBlockContent_set_initial_pos(entity);
}

void entity_HeartBlockContent_anim_idle(Entity* entity, s32 arg1) {
    struct802E4B10* temp = (struct802E4B10*)entity->dataBuf;
    switch (temp->unk_01) {
        case 0:
            entity->scale.x = 0.0f;
            entity->scale.y = 0.0f;
            entity->scale.z = 0.0f;
            if (arg1 == 0) {
                temp->unk_01++;
                break;
            }
            return;
        case 1:
            entity->scale.x += 0.01;
            if (entity->scale.x >= 1.0) {
                entity->scale.x = 1.0f;
                temp->unk_02 = 0;
                temp->unk_01++;
            }
            entity->scale.z = entity->scale.x;
            entity->scale.y = entity->scale.x;
            break;
        case 2:
            entity_HeartBlockContent_set_initial_pos(entity);
            temp->unk_01++;
            // fallthrough
        case 3:
            if (gOverrideFlags == 0) {
                // create an effect every 50 frames
                temp->unk_02--;
                if (temp->unk_02 <= 0) {
                    temp->unk_02 = 50;
                    playFX_22(temp->unk_0A, entity->position.x, entity->position.y, entity->position.z, 22.0f, 8.0f, 4, 20);
                }
            }
            break;
    }

    if (entity_can_collide_with_jumping_player(get_entity_by_index(temp->unk_00))) {
        exec_entity_commandlist(entity);
        disable_player_input();
        gPlayerStatus.currentSpeed = 0;
        gPlayerStatus.animFlags |= 0x200;
        set_time_freeze_mode(1);
        gOverrideFlags |= 0x40;
    }
}

void func_802E4DE0(Entity* entity) {
    struct802E4B10* temp = (struct802E4B10*)entity->dataBuf;

    temp->unk_01 = 0;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->rotation.z = 0.0f;
}

void entity_HeartBlockContent__anim_heal(Entity* entity, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    struct802E4B10* data = (struct802E4B10*)entity->dataBuf;
    f32 offsetX, offsetY, offsetZ;

    switch (data->unk_01) {
        case 0:
            playFX_11(0, entity->position.x, entity->position.y, entity->position.z, 2.0f);
            data->unk_20 = 0.0f;
            data->unk_01++;
            data->unk_14 = 6.0f;
            break;
        case 1:
            entity->position.y = entity->position.y + data->unk_14;
            data->unk_14 -= 1.0f;
            if (data->unk_14 <= 2.0f) {
                data->unk_01++;
                entity->flags &= ~ENTITY_FLAGS_ALWAYS_FACE_CAMERA;
                data->unk_54 = -10.0f;
                entity_set_render_script(entity, &D_802EA744);
                entity->renderSetupFunc = &entity_HeartBlockContent_setupGfx;
            }
            break;
        case 2:
            entity->position.y += sin_rad((data->unk_20 * TAU) / 360.0f) * 0.5f;
            data->unk_20 -= 30.0f;
            if (data->unk_20 < 0.0f) {
                data->unk_20 += 360.0f;
            }
            entity->rotation.y += data->unk_54;
            data->unk_54 += 2.0f;
            if (data->unk_54 >= 0.0f) {
                data->unk_18 = 0.0f;
                data->unk_1C = 0.0f;
                data->unk_01++;
                data->unk_04 = playerStatus->colliderHeight + 5;
                data->unk_03 = 0;
                recover_hp(-1);
                recover_fp(-1);
                sfx_play_sound(0x131);
            }
            data->unk_28[data->unk_24] = entity->rotation.y;
            data->unk_24++;
            if (data->unk_24 >= 11) {
                data->unk_24 = 0;
            }
            break;
        case 3:
            data->unk_1C += 2.0;
            if (data->unk_1C >= 10.0f) {
                data->unk_1C = 10.0f;
            }
            data->unk_18 += 18.0f;
            if (data->unk_18 >= 360.0f) {
                data->unk_18 -= 360.0f;
            }
            offsetX = data->unk_1C * sin_rad((data->unk_18 * TAU) / 360.0f);
            offsetZ = data->unk_1C * cos_rad((data->unk_18 * TAU) / 360.0f);
            offsetY = data->unk_04;

            data->unk_04 -= 0.7;

            if ((data->unk_03++ & 1) != 0) {
                playFX_11(3, playerStatus->position.x + offsetX,
                        playerStatus->position.y + offsetY,
                        playerStatus->position.z - offsetZ,
                        8.0f
                );
            }
            if (data->unk_04 < 20.0f) {
                data->unk_04 = 20.0f;
                data->unk_01++;
            }
            // fallthrough
        case 4:
            entity->position.y += sin_rad((data->unk_20 * TAU) / 360.0f) * 0.5f;
            data->unk_20 -= 30.0f;
            if (data->unk_20 < 0.0f) {
                data->unk_20 += 360.0f;
            }
            data->unk_54 += 1.0;
            if (data->unk_54 > 30.0f) {
                data->unk_54 = 30.0f;
            }
            entity->rotation.y += data->unk_54;
            if (entity->rotation.y >= 360.0f) {
                entity->rotation.y -= 360.0f;
            }
            entity->alpha -= 5;
            if (entity->alpha < 7) {
                entity->alpha = 5;
                if (data->unk_01 == 4) {
                    data->unk_01++;
                }
            }
            data->unk_28[data->unk_24] = entity->rotation.y;
            data->unk_24++;
            if (data->unk_24 >= 11) {
                data->unk_24 = 0;
            }
            break;
        case 5:
            playerStatus->animFlags &= ~0x200;
            enable_player_input();
            set_time_freeze_mode(0);
            gOverrideFlags &= ~0x40;
            exec_entity_commandlist(entity);
            break;
    }
}

void entity_HeartBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent_anim_beating);

void entity_HeartBlockContent_init(Entity* entity) {
    entity_HeartBlockContent_set_initial_pos(entity);
}

void entity_HeartBlockContent_reset(Entity* entity) {
    entity_HeartBlockContent__reset(entity);
    entity_set_render_script(entity, (u32*)&D_802EA728);
}

void entity_HeartBlockContent_idle(Entity* entity) {
    entity_HeartBlockContent_anim_idle(entity, 0);
    entity_HeartBlockContent_anim_beating(entity);
}

void entity_HeartBlockContent_anim_heal(Entity* entity) {
    entity_HeartBlockContent__anim_heal(entity, 0);
}

void entity_HeartBlock_change_render_script(Entity* entity) {
    entity_set_render_script(entity, (u32*)&D_802EA760);
}

void entity_HeartBlock_show_tutorial_message(Entity* entity) {
    if ((!gPlayerData.partners[1].enabled) && get_global_flag(EVT_SAVE_FLAG(96)) == 0) {
        UNK_TYPE* ptr = &D_802EB3C0;
        *ptr = 0;
        msg_get_printer_for_msg(0x1D0001, ptr);
        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
        gOverrideFlags |= 0x40;
        disable_player_input();
        set_global_flag(EVT_SAVE_FLAG(96));
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_HeartBlock_wait_for_close_tutorial(Entity* entity) {
    if (D_802EB3C0) {
        exec_entity_commandlist(entity);
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        gOverrideFlags &= ~0x40;
        enable_player_input();
    }
}

s8 entity_HeartBlock_create_child_entity(Entity* entity, StaticEntityData* data) {
    s32 temp_s2 = D_8015C7D0[0];
    Entity* someEntity;
    struct802E4B10* temp_v1;

    entity_base_block_init(entity);
    someEntity = get_entity_by_index(create_entity(data, entity->position.x, entity->position.y, entity->position.z, 0.0f,
                                     0x80000000));
    temp_v1 = (struct802E4B10*)someEntity->dataBuf;
    temp_v1->unk_00 = entity->listIndex;

    if (temp_s2 == 0) {
        temp_v1->unk_0A = 3;
    } else {
        temp_v1->unk_0A = 6;
    }
}

void entity_HeartBlock_init(Entity* entity) {
    entity_HeartBlock_create_child_entity(entity, &D_802EA7BC);
}
