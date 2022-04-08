#include "common.h"
#include "effects.h"

extern u32* D_802EA728;
extern u32* D_802EA760;
extern EntityBlueprint Entity_HeartBlockContent;
extern u32 HeartBlockPrinterClosed;
extern s32 D_802EA744; //

f32 entity_HeartBlockContent_get_previous_yaw(HeartBlockContentData* data, s32 lagTime) {
    s32 bufIdx = data->yawBufferPos - lagTime;
    if (bufIdx < 0) {
        bufIdx += ARRAY_COUNT(data->yawBuffer);
    }
    return data->yawBuffer[bufIdx];
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent__setupGfx);

void entity_HeartBlockContent_setupGfx(s32 entityIndex) {
    entity_HeartBlockContent__setupGfx(entityIndex, &D_0A000808);
}

void entity_HeartBlockContent_set_initial_pos(Entity* entity) {
    HeartBlockContentData* temp = entity->dataBuf.heartBlockContent;
    Entity* entityTemp = get_entity_by_index(temp->parentEntityIndex);

    entity->position.x = entityTemp->position.x;
    entity->position.y = entityTemp->position.y + 14.0f;
    entity->position.z = entityTemp->position.z;
}

void entity_HeartBlockContent__reset(Entity* entity) {
    HeartBlockContentData* data;
    Entity* someEntity;

    entity->renderSetupFunc = entity_HeartBlockContent_setupGfx;
    entity->alpha = 255;
    data = entity->dataBuf.heartBlockContent;
    entity->flags |= ENTITY_FLAGS_ALWAYS_FACE_CAMERA;
    someEntity = get_entity_by_index(data->parentEntityIndex);

    if (data->unk_09 == 0) {
        data->unk_09 = 1;
        data->state = 2;
        entity->scale.x = 1.0f;
    } else {
        data->state = 0;
        entity->scale.x = 0.0f;
    }

    data->unk_0C = 0;
    data->unk_10 = 0;
    entity->rotation.x = 0.0f;
    entity->rotation.y = 0.0f;
    entity->rotation.z = 0.0f;
    entity->scale.y = entity->scale.x;
    entity->scale.z = entity->scale.x;

    entity_HeartBlockContent_set_initial_pos(entity);
}

void entity_HeartBlockContent_anim_idle(Entity* entity, s32 arg1) {
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;
    switch (data->state) {
        case 0:
            entity->scale.x = 0.0f;
            entity->scale.y = 0.0f;
            entity->scale.z = 0.0f;
            if (arg1 == 0) {
                data->state++;
                break;
            }
            return;
        case 1:
            entity->scale.x += 0.01;
            if (entity->scale.x >= 1.0) {
                entity->scale.x = 1.0f;
                data->sparkleTimer = 0;
                data->state++;
            }
            entity->scale.z = entity->scale.x;
            entity->scale.y = entity->scale.x;
            break;
        case 2:
            entity_HeartBlockContent_set_initial_pos(entity);
            data->state++;
            // fallthrough
        case 3:
            if (gOverrideFlags == 0) {
                // create an effect every 50 frames
                data->sparkleTimer--;
                if (data->sparkleTimer <= 0) {
                    data->sparkleTimer = 50;
                    fx_stars_shimmer(data->sparkleEffectType, entity->position.x, entity->position.y, entity->position.z, 22.0f, 8.0f, 4, 20);
                }
            }
            break;
    }

    if (entity_can_collide_with_jumping_player(get_entity_by_index(data->parentEntityIndex))) {
        exec_entity_commandlist(entity);
        disable_player_input();
        gPlayerStatus.currentSpeed = 0;
        gPlayerStatus.animFlags |= PLAYER_STATUS_ANIM_FLAGS_RAISED_ARMS;
        set_time_freeze_mode(1);
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }
}

void func_802E4DE0(Entity* entity) {
    HeartBlockContentData* temp = entity->dataBuf.heartBlockContent;

    temp->state = 0;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->rotation.z = 0.0f;
}

void entity_HeartBlockContent__anim_heal(Entity* entity, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;
    f32 offsetX, offsetY, offsetZ;

    switch (data->state) {
        case 0:
            fx_sparkles(0, entity->position.x, entity->position.y, entity->position.z, 2.0f);
            data->bouncePhase = 0.0f;
            data->state++;
            data->riseVelocity = 6.0f;
            break;
        case 1:
            entity->position.y = entity->position.y + data->riseVelocity;
            data->riseVelocity -= 1.0f;
            if (data->riseVelocity <= 2.0f) {
                data->state++;
                entity->flags &= ~ENTITY_FLAGS_ALWAYS_FACE_CAMERA;
                data->rotationRate = -10.0f;
                entity_set_render_script(entity, &D_802EA744);
                entity->renderSetupFunc = &entity_HeartBlockContent_setupGfx;
            }
            break;
        case 2:
            entity->position.y += sin_rad((data->bouncePhase * TAU) / 360.0f) * 0.5f;
            data->bouncePhase -= 30.0f;
            if (data->bouncePhase < 0.0f) {
                data->bouncePhase += 360.0f;
            }
            entity->rotation.y += data->rotationRate;
            data->rotationRate += 2.0f;
            if (data->rotationRate >= 0.0f) {
                data->sparkleTrailAngle = 0.0f;
                data->sparkleTrailRadius = 0.0f;
                data->state++;
                data->sparkleTrailPosY = playerStatus->colliderHeight + 5;
                data->sparkleTrailTimer = 0;
                recover_hp(-1);
                recover_fp(-1);
                sfx_play_sound(0x131);
            }
            data->yawBuffer[data->yawBufferPos] = entity->rotation.y;
            data->yawBufferPos++;
            if (data->yawBufferPos > ARRAY_COUNT(data->yawBuffer)) {
                data->yawBufferPos = 0;
            }
            break;
        case 3:
            data->sparkleTrailRadius += 2.0;
            if (data->sparkleTrailRadius >= 10.0f) {
                data->sparkleTrailRadius = 10.0f;
            }
            data->sparkleTrailAngle += 18.0f;
            if (data->sparkleTrailAngle >= 360.0f) {
                data->sparkleTrailAngle -= 360.0f;
            }
            offsetX = data->sparkleTrailRadius * sin_rad((data->sparkleTrailAngle * TAU) / 360.0f);
            offsetZ = data->sparkleTrailRadius * cos_rad((data->sparkleTrailAngle * TAU) / 360.0f);
            offsetY = data->sparkleTrailPosY;

            data->sparkleTrailPosY -= 0.7;

            if ((data->sparkleTrailTimer++ & 1) != 0) {
                fx_sparkles(3, playerStatus->position.x + offsetX,
                        playerStatus->position.y + offsetY,
                        playerStatus->position.z - offsetZ,
                        8.0f
                );
            }
            if (data->sparkleTrailPosY < 20.0f) {
                data->sparkleTrailPosY = 20.0f;
                data->state++;
            }
            // fallthrough
        case 4:
            entity->position.y += sin_rad((data->bouncePhase * TAU) / 360.0f) * 0.5f;
            data->bouncePhase -= 30.0f;
            if (data->bouncePhase < 0.0f) {
                data->bouncePhase += 360.0f;
            }
            data->rotationRate += 1.0;
            if (data->rotationRate > 30.0f) {
                data->rotationRate = 30.0f;
            }
            entity->rotation.y += data->rotationRate;
            if (entity->rotation.y >= 360.0f) {
                entity->rotation.y -= 360.0f;
            }
            entity->alpha -= 5;
            if (entity->alpha < 7) {
                entity->alpha = 5;
                if (data->state == 4) {
                    data->state++;
                }
            }
            data->yawBuffer[data->yawBufferPos] = entity->rotation.y;
            data->yawBufferPos++;
            if (data->yawBufferPos > ARRAY_COUNT(data->yawBuffer)) {
                data->yawBufferPos = 0;
            }
            break;
        case 5:
            playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_RAISED_ARMS;
            enable_player_input();
            set_time_freeze_mode(0);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
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
        HeartBlockPrinterClosed = FALSE;
        msg_get_printer_for_msg(0x1D0001, &HeartBlockPrinterClosed);
        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        disable_player_input();
        set_global_flag(EVT_SAVE_FLAG(96));
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_HeartBlock_wait_for_close_tutorial(Entity* entity) {
    if (HeartBlockPrinterClosed) {
        exec_entity_commandlist(entity);
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
        enable_player_input();
    }
}

s8 entity_HeartBlock_create_child_entity(Entity* entity, EntityBlueprint* bp) {
    s32 useAltSparkleType = CreateEntityVarArgBuffer[0];
    Entity* childEntity;
    HeartBlockContentData* data;

    entity_base_block_init(entity);
    childEntity = get_entity_by_index(create_entity(bp, entity->position.x, entity->position.y, entity->position.z, 0.0f, MAKE_ENTITY_END));
    data = childEntity->dataBuf.heartBlockContent;
    data->parentEntityIndex = entity->listIndex;

    if (useAltSparkleType == FALSE) {
        data->sparkleEffectType = 3;
    } else {
        data->sparkleEffectType = 6;
    }
}

void entity_HeartBlock_init(Entity* entity) {
    entity_HeartBlock_create_child_entity(entity, &Entity_HeartBlockContent);
}
