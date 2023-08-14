#include "common.h"
#include "effects.h"
#include "message_ids.h"
#include "ld_addrs.h"
#include "entity.h"

extern EntityModelScript Entity_HeartBlockContent_RenderScriptIdle;
extern EntityModelScript Entity_HeartBlockContent_RenderScriptAfterHit;
extern EntityModelScript Entity_HeartBlockContent_RenderScriptHit;

extern EntityBlueprint Entity_HeartBlockContent;

extern Gfx Entity_HeartBlock_Render[];
extern Gfx Entity_HeartBlockContent_RenderHeartSleeping[];
extern Gfx Entity_HeartBlockContent_RenderHeartAwake[];
extern Gfx Entity_HeartBlockContent_RenderHeartHappy[];

BSS u32 HeartBlockPrinterClosed;

f32 entity_HeartBlockContent_get_previous_yaw(HeartBlockContentData* data, s32 lagTime) {
    s32 bufIdx = data->yawBufferPos - lagTime;
    if (bufIdx < 0) {
        bufIdx += ARRAY_COUNT(data->yawBuffer);
    }
    return data->yawBuffer[bufIdx];
}

void entity_HeartBlockContent__setupGfx(s32 entityIndex, Gfx* arg1) {
    Entity* entity = get_entity_by_index(entityIndex);
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;
    Gfx* gfxPos = gMainGfxPos;
    s32 alpha;
    Matrix4f sp18;
    Gfx* dlist;

    dlist = ENTITY_ADDR(entity, Gfx*, arg1);

    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, entity->alpha);

    alpha = 92;
    if (entity->alpha < alpha) {
        alpha = entity->alpha;
    }

    guRotateF(sp18, entity_HeartBlockContent_get_previous_yaw(data, 2), 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp18, &data->unk_58);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_58;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gSPDisplayList(gfxPos++, dlist);
    gDPPipeSync(gfxPos++);
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    alpha = 72;
    if (entity->alpha < alpha) {
        alpha = entity->alpha;
    }

    guRotateF(sp18, entity_HeartBlockContent_get_previous_yaw(data, 3), 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp18, &data->unk_98);
    gDisplayContext->matrixStack[gMatrixListPos] = data->unk_98;
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gSPDisplayList(gfxPos++, dlist);
    gDPPipeSync(gfxPos++);
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    gMainGfxPos = gfxPos;
}

void entity_HeartBlockContent_setupGfx(s32 entityIndex) {
    entity_HeartBlockContent__setupGfx(entityIndex, Entity_HeartBlockContent_RenderHeartHappy);
}

void entity_HeartBlockContent_set_initial_pos(Entity* entity) {
    HeartBlockContentData* temp = entity->dataBuf.heartBlockContent;
    Entity* entityTemp = get_entity_by_index(temp->parentEntityIndex);

    entity->pos.x = entityTemp->pos.x;
    entity->pos.y = entityTemp->pos.y + 14.0f;
    entity->pos.z = entityTemp->pos.z;
}

void entity_HeartBlockContent__reset(Entity* entity) {
    HeartBlockContentData* data;
    Entity* blockEntity;

    entity->renderSetupFunc = entity_HeartBlockContent_setupGfx;
    entity->alpha = 255;
    data = entity->dataBuf.heartBlockContent;
    entity->flags |= ENTITY_FLAG_ALWAYS_FACE_CAMERA;
    blockEntity = get_entity_by_index(data->parentEntityIndex);

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
    entity->rot.x = 0.0f;
    entity->rot.y = 0.0f;
    entity->rot.z = 0.0f;
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
                    fx_stars_shimmer(data->sparkleEffectType, entity->pos.x, entity->pos.y, entity->pos.z, 22.0f, 8.0f, 4, 20);
                }
            }
            break;
    }

    if (entity_can_collide_with_jumping_player(get_entity_by_index(data->parentEntityIndex))) {
        exec_entity_commandlist(entity);
        disable_player_input();
        gPlayerStatus.curSpeed = 0;
        gPlayerStatus.animFlags |= PA_FLAG_RAISED_ARMS;
        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
    }
}

void entity_HeartBlockContent_reset_data(Entity* entity) {
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;

    data->state = 0;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->rot.z = 0.0f;
}

void entity_HeartBlockContent__anim_heal(Entity* entity, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;
    f32 offsetX, offsetY, offsetZ;

    switch (data->state) {
        case 0:
            fx_sparkles(FX_SPARKLES_0, entity->pos.x, entity->pos.y, entity->pos.z, 2.0f);
            data->bouncePhase = 0.0f;
            data->state++;
            data->riseVel = 6.0f;
            break;
        case 1:
            entity->pos.y = entity->pos.y + data->riseVel;
            data->riseVel -= 1.0f;
            if (data->riseVel <= 2.0f) {
                data->state++;
                entity->flags &= ~ENTITY_FLAG_ALWAYS_FACE_CAMERA;
                data->rotRate = -10.0f;
                entity_set_render_script(entity, &Entity_HeartBlockContent_RenderScriptHit);
                entity->renderSetupFunc = entity_HeartBlockContent_setupGfx;
            }
            break;
        case 2:
            entity->pos.y += sin_rad(DEG_TO_RAD(data->bouncePhase)) * 0.5f;
            data->bouncePhase -= 30.0f;
            if (data->bouncePhase < 0.0f) {
                data->bouncePhase += 360.0f;
            }
            entity->rot.y += data->rotRate;
            data->rotRate += 2.0f;
            if (data->rotRate >= 0.0f) {
                data->sparkleTrailAngle = 0.0f;
                data->sparkleTrailRadius = 0.0f;
                data->state++;
                data->sparkleTrailPosY = playerStatus->colliderHeight + 5;
                data->sparkleTrailTimer = 0;
                recover_hp(-1);
                recover_fp(-1);
                sfx_play_sound(SOUND_HEART_BLOCK);
            }
            data->yawBuffer[data->yawBufferPos] = entity->rot.y;
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
            offsetX = data->sparkleTrailRadius * sin_rad(DEG_TO_RAD(data->sparkleTrailAngle));
            offsetZ = data->sparkleTrailRadius * cos_rad(DEG_TO_RAD(data->sparkleTrailAngle));
            offsetY = data->sparkleTrailPosY;

            data->sparkleTrailPosY -= 0.7;

            if ((data->sparkleTrailTimer++ & 1) != 0) {
                fx_sparkles(FX_SPARKLES_3, playerStatus->pos.x + offsetX,
                        playerStatus->pos.y + offsetY,
                        playerStatus->pos.z - offsetZ,
                        8.0f
                );
            }
            if (data->sparkleTrailPosY < 20.0f) {
                data->sparkleTrailPosY = 20.0f;
                data->state++;
            }
            // fallthrough
        case 4:
            entity->pos.y += sin_rad(DEG_TO_RAD(data->bouncePhase)) * 0.5f;
            data->bouncePhase -= 30.0f;
            if (data->bouncePhase < 0.0f) {
                data->bouncePhase += 360.0f;
            }
            data->rotRate += 1.0;
            if (data->rotRate > 30.0f) {
                data->rotRate = 30.0f;
            }
            entity->rot.y += data->rotRate;
            if (entity->rot.y >= 360.0f) {
                entity->rot.y -= 360.0f;
            }
            entity->alpha -= 5;
            if (entity->alpha < 7) {
                entity->alpha = 5;
                if (data->state == 4) {
                    data->state++;
                }
            }
            data->yawBuffer[data->yawBufferPos] = entity->rot.y;
            data->yawBufferPos++;
            if (data->yawBufferPos > ARRAY_COUNT(data->yawBuffer)) {
                data->yawBufferPos = 0;
            }
            break;
        case 5:
            playerStatus->animFlags &= ~PA_FLAG_RAISED_ARMS;
            enable_player_input();
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            exec_entity_commandlist(entity);
            break;
    }
}

void entity_HeartBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

void entity_HeartBlockContent_anim_beating(Entity* entity) {
    HeartBlockContentData* data = entity->dataBuf.heartBlockContent;

    entity_HeartBlockContent_set_initial_pos(entity);

    if (entity->scale.x < 1.0) {
        return;
    }

    switch (data->heartbeatTimer) {
        case 0:
            entity->scale.x += 0.1;
            data->heartbeatTimer++;
            break;
        case 1:
            entity->scale.x -= 0.02;
            if (entity->scale.x <= 1.0) {
                entity->scale.x = 1.0f;
                data->heartbeatTimer++;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            data->heartbeatTimer++;
            break;
        default:
            data->heartbeatTimer = 0;
            break;
    }

    entity->scale.y = entity->scale.x;
}

void entity_HeartBlockContent_init(Entity* entity) {
    entity_HeartBlockContent_set_initial_pos(entity);
}

void entity_HeartBlockContent_reset(Entity* entity) {
    entity_HeartBlockContent__reset(entity);
    entity_set_render_script(entity, &Entity_HeartBlockContent_RenderScriptIdle);
}

void entity_HeartBlockContent_idle(Entity* entity) {
    entity_HeartBlockContent_anim_idle(entity, 0);
    entity_HeartBlockContent_anim_beating(entity);
}

void entity_HeartBlockContent_anim_heal(Entity* entity) {
    entity_HeartBlockContent__anim_heal(entity, 0);
}

void entity_HeartBlock_change_render_script(Entity* entity) {
    entity_set_render_script(entity, &Entity_HeartBlockContent_RenderScriptAfterHit);
}

void entity_HeartBlock_show_tutorial_message(Entity* entity) {
    if (!gPlayerData.partners[PARTNER_GOOMBARIO].enabled && !get_global_flag(GF_Tutorial_HeartBlock)) {
        HeartBlockPrinterClosed = FALSE;
        msg_get_printer_for_msg(MSG_Menus_Tutorial_HeartBlock, &HeartBlockPrinterClosed);
        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        disable_player_input();
        set_global_flag(GF_Tutorial_HeartBlock);
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
    childEntity = get_entity_by_index(create_entity(bp, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, 0, MAKE_ENTITY_END));
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

extern EntityScript Entity_InertBlock_Script;

EntityScript Entity_HeartBlockContent_Script = {
    es_Call(entity_HeartBlockContent_reset)
    es_SetCallback(entity_HeartBlockContent_idle, 0)
    es_Call(entity_HeartBlockContent_reset_data)
    es_Call(entity_HeartBlock_change_render_script)
    es_SetCallback(entity_HeartBlockContent_anim_heal, 0)
    es_Call(entity_HeartBlock_show_tutorial_message)
    es_SetCallback(entity_HeartBlock_wait_for_close_tutorial, 0)
    es_SetCallback(NULL, 60)
    es_Restart
    es_End
};
EntityScript Entity_HeartBlock_Script = {
    es_SetCallback(entity_HeartBlock_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_start_script)
    es_Call(entity_block_hit_init_scale)
    es_SetCallback(entity_block_hit_animate_scale, 6)
    es_Restart
    es_End
};

EntityModelScript Entity_HeartBlockContent_RenderScriptIdle = STANDARD_ENTITY_MODEL_SCRIPT(Entity_HeartBlockContent_RenderHeartSleeping, RENDER_MODE_ALPHATEST);
EntityModelScript Entity_HeartBlockContent_RenderScriptHit = STANDARD_ENTITY_MODEL_SCRIPT(Entity_HeartBlockContent_RenderHeartAwake, RENDER_MODE_SURFACE_XLU_LAYER2);
EntityModelScript Entity_HeartBlockContent_RenderScriptAfterHit = STANDARD_ENTITY_MODEL_SCRIPT(Entity_HeartBlockContent_RenderHeartHappy, RENDER_MODE_SURFACE_XLU_LAYER2);
EntityModelScript Entity_HeartBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_HeartBlock_Render, RENDER_MODE_SURFACE_XLU_LAYER3);

EntityBlueprint Entity_HeartBlockFrame = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HeartBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_InertBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(HeartBlock) },
    .entityType = ENTITY_TYPE_HEALING_BLOCK_FRAME,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HeartBlockContent = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .typeDataSize = sizeof(HeartBlockContentData),
    .renderCommandList = Entity_HeartBlockContent_RenderScriptIdle,
    .modelAnimationNodes = 0,
    .fpInit = entity_HeartBlockContent_init,
    .updateEntityScript = Entity_HeartBlockContent_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(HeartBlockContent) },
    .entityType = ENTITY_TYPE_HEALING_BLOCK_CONTENT,
    .aabbSize = { 18, 6, 18 }
};

EntityBlueprint Entity_HeartBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HeartBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_HeartBlock_init,
    .updateEntityScript = Entity_HeartBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(HeartBlock) },
    .entityType = ENTITY_TYPE_HEALING_BLOCK,
    .aabbSize = { 25, 25, 25 }
};
