#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "entity.h"

extern Gfx Entity_InertYellowBlock_Render[];
extern Gfx Entity_InertRedBlock_Render[];
extern Gfx Entity_BrickBlock_Render[];
extern Gfx Entity_Hammer1Block_Render[];
extern Gfx Entity_Hammer2Block_Render[];
extern Gfx Entity_Hammer3Block_Render[];
extern Gfx Entity_PushBlock_Render[];
extern Gfx Entity_PowBlock_Render[];

extern EntityScript Entity_CreatedInertBlock_Script;
extern EntityScript Entity_BreakingBlock_Script;

extern EntityBlueprint Entity_ShatteringHammer1Block;
extern EntityBlueprint Entity_ShatteringHammer2Block;
extern EntityBlueprint Entity_ShatteringHammer3Block;
extern EntityBlueprint Entity_ShatteringHammer1BlockTiny;
extern EntityBlueprint Entity_ShatteringHammer2BlockTiny;
extern EntityBlueprint Entity_ShatteringHammer3BlockTiny;
extern EntityBlueprint Entity_ShatteringBrickBlock;

void entity_BrickBlock_idle(Entity* entity);
void entity_breakable_block_create_shattering_entity(Entity* entity);

void entity_MulticoinBlock_update_timer(Entity* entity);

#define MULTICOIN_BLOCK_MAX_COINS 10

void entity_base_block_setupGfx(s32 entityIndex) {
    Gfx* gfx = gMainGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);

    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPTexture(gfx++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    if (entity->alpha >= 255) {
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineMode(gfx++, PM_CC_01, PM_CC_02);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, entity->alpha);
    }

    gMainGfxPos = gfx;
}

void entity_base_block_play_vanish_effect(Entity* entity) {
    fx_cold_breath(0, entity->pos.x, entity->pos.y, entity->pos.z, 1.0f, 0x3C);
}

f32 entity_block_hit_init_scale(Entity* entity) {
    s32 type = get_entity_type(entity->listIndex);
    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY || type == ENTITY_TYPE_HAMMER2_BLOCK_TINY || type == ENTITY_TYPE_HAMMER3_BLOCK_TINY) {
        entity->scale.y = 0.23f;
        entity->scale.x = 1.04f;
        entity->scale.z = 1.04f;
        entity->pos.y += 18.0f;
    } else {
        entity->scale.y = 0.46f;
        entity->scale.x = 2.08f;
        entity->scale.z = 2.08f;
        entity->pos.y += 18.0f;
    }
}

void entity_block_hit_animate_scale(Entity* entity) {
    s32 type = get_entity_type(entity->listIndex);
    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY || type == ENTITY_TYPE_HAMMER2_BLOCK_TINY || type == ENTITY_TYPE_HAMMER3_BLOCK_TINY) {
        entity->scale.x -= 0.09;
        entity->scale.z -= 0.09;
        entity->scale.y += 0.045;
        entity->pos.y -= 3.0f;
    } else {
        entity->scale.x -= 0.18;
        entity->scale.z -= 0.18;
        entity->scale.y += 0.09;
        entity->pos.y -= 3.0f;
    }
    entity_base_block_idle(entity);
}

void entity_base_block_update_slow_sinking(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlockData* data = entity->dataBuf.block;
    f32 deltaY;

    if (entity->alpha < 255) {
        entity->flags &= ~ENTITY_FLAG_200000;
        return;
    }

    if (!(data->sinkingTimer & 0x8000)) {
        if (data->sinkingTimer < 150) {
            data->sinkingTimer++;
            return;
        }

        if (entity->pos.y < data->initialY - 25.0f) {
            deltaY = (entity->pos.y - data->initialY + 50.0f) * 0.125f;
        } else {
            deltaY = (data->initialY - entity->pos.y) * 0.125f;
        }

        if (deltaY > 1.2) {
            deltaY = 1.2f;
        }
        if (deltaY < 0.3) {
            deltaY = 0.3f;
        }

        entity->pos.y += deltaY;

        if (data->initialY < entity->pos.y) {
            entity->pos.y = data->initialY;
            data->sinkingTimer = -1;
            entity->flags &= ~ENTITY_FLAG_200000;
        }
    } else {
        if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING) {
            if (!(playerStatus->flags & PS_FLAG_JUMPING)) {
                Shadow* shadow = get_shadow_by_index(entity->shadowIndex);
                if (shadow != NULL) {
                    f32 temp2 = entity->pos.y - shadow->pos.y;

                    if (entity->pos.y - temp2 <= playerStatus->colliderHeight + 1) {
                        entity->pos.y = playerStatus->colliderHeight + 1;
                        data->sinkingTimer = 1;
                    }
                }
            } else {
                data->sinkingTimer = 1;
                return;
            }
            do {} while (0); // needed to match
        } else {
            Shadow* shadow = get_shadow_by_index(entity->shadowIndex);
            if (shadow != NULL) {
                if (entity->pos.y <= shadow->pos.y) {
                    entity->pos.y = shadow->pos.y;
                    data->sinkingTimer = 1;
                }
            }
        }

        if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING) {
            data->sinkingTimer = 1;
            return;
        }

        if (entity->pos.y < data->initialY - 25.0f) {
            deltaY = (entity->pos.y - data->initialY + 50.0f) * 0.125f;
        } else {
            deltaY = (data->initialY - entity->pos.y) * 0.125f;
        }

        if (deltaY > 1.2) {
            deltaY = 1.2f;
        }
        if (deltaY < 0.3) {
            deltaY = 0.3f;
        }

        entity->pos.y -= deltaY;

        if (entity->pos.y < data->initialY - 50.0f) {
            entity->pos.y = data->initialY - 50.0f;
            data->sinkingTimer = 1;
        }
    }
}

s32 entity_base_block_idle(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    s32 ret = 0;

    if (is_block_on_ground(entity) != 0) {
        if (entity->flags & ENTITY_FLAG_200000) {
            ret = 1;
            entity_base_block_update_slow_sinking(entity);
            if (data->item != -1) {
                ItemEntity* itemEntity = get_item_entity(data->item);
                itemEntity->pos.y = entity->pos.y + 4.0f;
            }
        }
    }

    return ret;
}

void entity_base_block_init(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->item = -1;
    data->initialY = entity->pos.y;
    data->sinkingTimer = -1;
    entity->flags &= ~ENTITY_FLAG_200000;
}

void entity_inactive_block_hit_init(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->recoilInterpPhase = 90.0f;
}

void entity_inactive_block_hit_anim(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    f64 currentY;

    entity_MulticoinBlock_update_timer(entity);
    currentY = entity->pos.y;
    entity->pos.y = currentY + ((f64)sin_rad(DEG_TO_RAD(data->recoilInterpPhase)) * 2);
    data->recoilInterpPhase += 60.0f;
    if (data->recoilInterpPhase > 450.0f) {
        data->recoilInterpPhase = clamp_angle(data->recoilInterpPhase);
        exec_entity_commandlist(entity);
    }
}

void entity_inactive_block_recoil_anim(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    f64 currentY;

    entity_MulticoinBlock_update_timer(entity);
    currentY = entity->pos.y;
    entity->pos.y = currentY + ((f64)sin_rad(DEG_TO_RAD(data->recoilInterpPhase)));
    data->recoilInterpPhase += 60.0f;
    if (data->recoilInterpPhase >= 360.0f) {
        data->recoilInterpPhase = 0.0f;
        entity->pos.y = data->initialY;
        exec_entity_commandlist(entity);
    }
}

void entity_MulticoinBlock_init(Entity* entity) {
    BlockData* data;

    entity_base_block_init(entity);
    data = entity->dataBuf.block;
    data->coinsLeft = MULTICOIN_BLOCK_MAX_COINS;
    data->timeLeft = 123;
    data->gameFlagIndex = 0xFFFF;
}

void entity_MulticoinBlock_spawn_coin(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    s32 itemSpawnMode;
    s32 flagIndex;

    if (data->coinsLeft > 0) {
        if (data->coinsLeft == MULTICOIN_BLOCK_MAX_COINS) {
            itemSpawnMode = ITEM_SPAWN_MODE_ITEM_BLOCK_COIN;
            flagIndex = data->gameFlagIndex;
        } else {
            itemSpawnMode = ITEM_SPAWN_MODE_ITEM_BLOCK_SPAWN_ALWAYS;
            flagIndex = 0;
        }
        make_item_entity_nodelay(ITEM_COIN, entity->pos.x, entity->pos.y + 28.0, entity->pos.z,
            itemSpawnMode, flagIndex);
        data->coinsLeft -= 1;
    }

    if ((data->coinsLeft == 0) || (data->timeLeft == 0)) {
        data->empty = TRUE;
        set_entity_commandlist(get_entity_by_index(create_entity(&Entity_InertYellowBlock,
            (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z,
            (s32)entity->rot.y, MAKE_ENTITY_END)), Entity_CreatedInertBlock_Script);
        entity->flags |= (ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_PENDING_INSTANCE_DELETE);
    }
}

void entity_MulticoinBlock_update_timer(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if (entity->type == ENTITY_TYPE_MULTI_COIN_BRICK) {
        if (data->coinsLeft != MULTICOIN_BLOCK_MAX_COINS) {
            data->timeLeft -= 1;
            if (data->timeLeft < 0) {
                data->timeLeft = 0;
                data->coinsLeft = 1;
            }
        }
    }
}

void entity_MulticoinBlock_idle(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if (entity->collisionFlags & ENTITY_COLLISION_PARTNER) {
        exec_entity_commandlist(entity);
        return;
    }
    entity_MulticoinBlock_update_timer(entity);
    entity_base_block_idle(entity);
    if (data->empty) {
        create_entity(&Entity_InertYellowBlock, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y, MAKE_ENTITY_END);
        entity->flags |= (ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_PENDING_INSTANCE_DELETE);
    }
}

void entity_MulticoinBlock_check_if_inactive(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if (data->gameFlagIndex != 0xFFFF) {
        if (get_global_flag(data->gameFlagIndex) != 0) {
            create_entity(&Entity_InertYellowBlock, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y, MAKE_ENTITY_END);
            entity->flags |= (ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_PENDING_INSTANCE_DELETE);
        }
    }
}

s32 entity_block_handle_collision(Entity* entity) {
    s32 breakBlock;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->alpha == 0 && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
        return FALSE;
    }

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING) {
        s32 type = get_entity_type(entity->listIndex);
        switch (type) {
            case ENTITY_TYPE_PUSH_BLOCK:
            case ENTITY_TYPE_HAMMER1_BLOCK:
            case ENTITY_TYPE_HAMMER2_BLOCK:
            case ENTITY_TYPE_HAMMER3_BLOCK:
            case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
                return FALSE;
        }

        if (playerStatus->flags & PS_FLAG_JUMPING) {
            exec_entity_commandlist(entity);
        }
        return TRUE;
    }
    if (entity->collisionFlags & ENTITY_COLLISION_PARTNER) {
        exec_entity_commandlist(entity);
        return TRUE;
    }

    breakBlock = FALSE;
    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_JUMP || playerStatus->actionState == ACTION_STATE_TORNADO_JUMP) {
            return FALSE;
        }

        if (playerStatus->actionState == ACTION_STATE_SPIN_POUND || playerStatus->actionState == ACTION_STATE_TORNADO_POUND) {
            breakBlock = TRUE;
        } else {
            return TRUE;
        }
    } else {
        if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_HAMMER)) {
            return TRUE;
        }
        if (!(playerStatus->flags & PS_FLAG_HAMMER_CHECK)) {
            return TRUE;
        }
    }

    switch (get_entity_type(entity->listIndex)) {
        case ENTITY_TYPE_BRICK_BLOCK:
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_RED_BLOCK:
            exec_entity_commandlist(entity);
            break;
        case ENTITY_TYPE_HAMMER1_BLOCK:
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            if (breakBlock) {
                if (gPlayerData.bootsLevel < 1) {
                    breakBlock = FALSE;
                }
            } else {
                if (gPlayerData.hammerLevel > -1) {
                    breakBlock = TRUE;
                }
            }
            if (!breakBlock) {
                return TRUE;
            }
            set_entity_commandlist(entity, Entity_BreakingBlock_Script);
            sfx_play_sound_at_position(SOUND_14F, SOUND_SPACE_MODE_0, entity->pos.x, entity->pos.y, entity->pos.z);
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            if (breakBlock) {
                if (gPlayerData.bootsLevel < 2) {
                    breakBlock = FALSE;
                }
            } else if (gPlayerData.hammerLevel > 0) {
                breakBlock = TRUE;
            }
            if (!breakBlock) {
                return TRUE;
            }
            set_entity_commandlist(entity, Entity_BreakingBlock_Script);
            sfx_play_sound_at_position(SOUND_150, SOUND_SPACE_MODE_0, entity->pos.x, entity->pos.y, entity->pos.z);
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            if (gPlayerData.hammerLevel < 2) {
                return TRUE;
            }
            set_entity_commandlist(entity, Entity_BreakingBlock_Script);
            sfx_play_sound_at_position(SOUND_151, SOUND_SPACE_MODE_0, entity->pos.x, entity->pos.y, entity->pos.z);
            break;
        case ENTITY_TYPE_MULTI_TRIGGER_BLOCK:
        case ENTITY_TYPE_HEALING_BLOCK:
        case ENTITY_TYPE_1C:
        case ENTITY_TYPE_1D:
        case ENTITY_TYPE_1E:
        case ENTITY_TYPE_HEALING_BLOCK_FRAME:
            entity_start_script(entity);
            exec_entity_commandlist(entity);
            break;
        case ENTITY_TYPE_PUSH_BLOCK:
            entity_start_script(entity);
            break;
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    return TRUE;
}

void entity_init_Hammer1Block_normal(Entity* entity) {
    entity_base_block_init(entity);
    entity->renderSetupFunc = entity_base_block_setupGfx;
}

void entity_init_HammerBlock_small(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->item = -1;
    data->initialY = entity->pos.y;
    data->sinkingTimer = -1;
    entity->flags &= ~ENTITY_FLAG_200000;
    entity->scale.x = 0.5f;
    entity->scale.y = 0.5f;
    entity->scale.z = 0.5f;
}

EntityScript Entity_PowBlock_Script = {
    es_SetCallback(entity_base_block_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_block_hit_init_scale)
    es_SetCallback(entity_block_hit_animate_scale, 6)
    es_Call(entity_start_script)
    es_Restart
    es_End
};
EntityScript Entity_BaseBlock_Script = {
    es_SetCallback(entity_base_block_idle, 0)
    es_Call(entity_start_script)
    es_Restart
    es_End
};
EntityScript D_802E9DEC = {
    es_SetCallback(entity_base_block_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Restart
    es_End
};
EntityScript Entity_InertBlock_Script = {
    es_SetCallback(entity_base_block_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_inactive_block_hit_init)
    es_Call(entity_start_script)
    es_SetCallback(entity_inactive_block_hit_anim, 0)
    es_SetCallback(entity_inactive_block_recoil_anim, 0)
    es_Restart
    es_End
};
EntityScript Entity_CreatedInertBlock_Script = {
    es_Call(entity_inactive_block_hit_init)
    es_SetCallback(entity_inactive_block_hit_anim, 0)
    es_SetCallback(entity_inactive_block_recoil_anim, 0)
    es_Jump(Entity_InertBlock_Script)
    es_End
};
EntityScript Entity_BreakingBlock_Script = {
    es_RestartBoundScript
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_Call(entity_breakable_block_create_shattering_entity)
    es_SetCallback(NULL, 1)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript Entity_BrickBlock_Script = {
    es_SetCallback(entity_BrickBlock_idle, 0)
    es_Call(entity_start_script)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_Call(entity_breakable_block_create_shattering_entity)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript Entity_Hammer1Block_Script = {
    es_SetCallback(entity_base_block_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_start_script)
    es_Restart
    es_End
};
EntityScript Entity_MulticoinBlock_Script = {
    es_Call(entity_MulticoinBlock_check_if_inactive)
    es_Label(1)
        es_SetCallback(entity_MulticoinBlock_idle, 0)
        es_PlaySound(SOUND_HIT_BLOCK)
        es_Call(entity_MulticoinBlock_spawn_coin)
        es_Call(entity_inactive_block_hit_init)
        es_SetCallback(entity_inactive_block_hit_anim, 0)
        es_SetCallback(entity_inactive_block_recoil_anim, 0)
    es_Goto(1)
    es_End
};

EntityModelScript Entity_InertYellowBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_InertYellowBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_InertRedBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_InertRedBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_MulticoinBrick_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_BrickBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_Hammer1Block_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Hammer1Block_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_Hammer2Block_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Hammer2Block_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_Hammer3Block_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Hammer3Block_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_PushBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_PushBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_BrickBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_BrickBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityModelScript Entity_PowBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_PowBlock_Render, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_InertYellowBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_InertYellowBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_Hammer1Block_normal,
    .updateEntityScript = Entity_InertBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(InertYellowBlock) },
    .entityType = ENTITY_TYPE_MULTI_TRIGGER_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_InertRedBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_InertRedBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_Hammer1Block_normal,
    .updateEntityScript = Entity_InertBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(InertRedBlock) },
    .entityType = ENTITY_TYPE_INACTIVE_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_BrickBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_BrickBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BrickBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(BrickBlock) },
    .entityType = ENTITY_TYPE_BRICK_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_MulticoinBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_MulticoinBrick_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_MulticoinBlock_init,
    .updateEntityScript = Entity_MulticoinBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(BrickBlock) },
    .entityType = ENTITY_TYPE_MULTI_COIN_BRICK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_Hammer1Block = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer1Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_Hammer1Block_normal,
    .updateEntityScript = Entity_Hammer1Block_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK,
    .aabbSize = { 50, 50, 50 }
};

EntityBlueprint Entity_Hammer1Block_WideX = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer1Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_Hammer1Block_normal,
    .updateEntityScript = Entity_Hammer1Block_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK,
    .aabbSize = { 100, 50, 50 }
};

EntityBlueprint Entity_Hammer1Block_WideZ = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer1Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_Hammer1Block_normal,
    .updateEntityScript = Entity_Hammer1Block_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK,
    .aabbSize = { 50, 50, 100 }
};

EntityBlueprint Entity_Hammer1BlockTiny = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer1Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_HammerBlock_small,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer1Block) },
    .entityType = ENTITY_TYPE_HAMMER1_BLOCK_TINY,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_Hammer2Block = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer2Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK,
    .aabbSize = { 50, 50, 50 }
};

EntityBlueprint Entity_Hammer2Block_WideX = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer2Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK,
    .aabbSize = { 100, 50, 50 }
};

EntityBlueprint Entity_Hammer2Block_WideZ = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer2Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK,
    .aabbSize = { 50, 50, 100 }
};

EntityBlueprint Entity_Hammer2BlockTiny = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer2Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_HammerBlock_small,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer2Block) },
    .entityType = ENTITY_TYPE_HAMMER2_BLOCK_TINY,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_Hammer3Block = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer3Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK,
    .aabbSize = { 50, 50, 50 }
};

EntityBlueprint Entity_Hammer3Block_WideX = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer3Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK,
    .aabbSize = { 100, 50, 50 }
};

EntityBlueprint Entity_Hammer3Block_WideZ = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer3Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK,
    .aabbSize = { 50, 50, 100 }
};

EntityBlueprint Entity_Hammer3BlockTiny = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_80,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_Hammer3Block_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_HammerBlock_small,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(Hammer3Block) },
    .entityType = ENTITY_TYPE_HAMMER3_BLOCK_TINY,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_PushBlock = {
    .flags = ENTITY_FLAG_4000,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_PushBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_BaseBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(PushBlock) },
    .entityType = ENTITY_TYPE_PUSH_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_PowBlock = {
    .flags = ENTITY_FLAG_4000,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_PowBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_base_block_init,
    .updateEntityScript = Entity_PowBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(PowBlock) },
    .entityType = ENTITY_TYPE_POW_BLOCK,
    .aabbSize = { 30, 25, 25 },
};
