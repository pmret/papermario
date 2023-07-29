#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "animation_script.h"
#include "entity.h"
#include "model.h"

extern Gfx Entity_YellowBlock_Render[];
extern Gfx Entity_RedBlock_Render[];
extern AnimScript Entity_HitYellowBlock_AnimationHit;
extern AnimScript Entity_HitYellowBlock_AnimationIdle;
extern StaticAnimatorNode* Entity_HitYellowBlock_Mesh[];
extern AnimScript Entity_HitFloatingYellowBlock_AnimationIdle;
extern StaticAnimatorNode* Entity_HitFloatingYellowBlock_Mesh[];
extern AnimScript Entity_HitRedBlock_AnimationHit;
extern StaticAnimatorNode* Entity_HitRedBlock_Mesh[];

extern s32 D_802EA310[];

extern EntityBlueprint Entity_HitGroundedYellowBlock;
extern EntityBlueprint Entity_HitFloatingYellowBlock;
extern EntityBlueprint Entity_HitRedBlock;

BSS EffectInstance* TriggerBlockVanishEffect;

f32 player_get_camera_facing_angle(void);
void entity_inactive_block_hit_init(Entity*);
void entity_inactive_block_hit_anim(Entity*);
void entity_inactive_block_recoil_anim(Entity*);

void entity_ItemBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

void entity_HiddenItemBlock_idle(Entity* entity) {
    s32 alpha = entity->alpha;

    if (gPlayerStatus.animFlags & PA_FLAG_USING_WATT) {
        alpha += 32;
        if (alpha > 192) {
            alpha = 192;
        }
        entity->alpha = alpha;
    } else {
        alpha -= 32;
        if (alpha <= 0) {
            alpha = 0;
        }
        entity->alpha = alpha;
    }
}

void entity_HitItemBlock_appear(Entity* entity) {
    if (entity->alpha < 255) {
        entity->alpha += (entity->alpha == 0 ? 31 : 32);
    }
}

void entity_ItemBlock_spawn_item(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    s32 angle;

    if (data->item == 0 || (entity->flags & ENTITY_FLAG_100000)) {
        return;
    }

    angle = player_get_camera_facing_angle();
    entity->flags |= ENTITY_FLAG_100000;

    if (data->item == ITEM_COIN) {
        make_item_entity(ITEM_COIN, entity->pos.x, entity->pos.y + 28.0, entity->pos.z,
            ITEM_SPAWN_MODE_ITEM_BLOCK_COIN, 0, angle, data->gameFlagIndex);
    } else {
        angle += 360;
        make_item_entity(data->item, entity->pos.x, entity->pos.y + 20.0, entity->pos.z,
            (gItemTable[data->item].typeFlags & ITEM_TYPE_FLAG_BADGE) ? ITEM_SPAWN_MODE_ITEM_BLOCK_BADGE : ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM,
            0, angle, data->gameFlagIndex);
    }

}

void entity_TriggerBlock_start_bound_script_2(Entity* entity) {
    entity_start_script(entity);
}

void entity_TriggerBlock_play_vanish_effect(Entity* entity) {
    TriggerBlockVanishEffect = fx_cold_breath(0, entity->pos.x, entity->pos.y, entity->pos.z, 1.0f, 0x3C);
}

void entity_HitItemBlock_play_anim(Entity* entity) {
    s32 entityType = get_entity_type(entity->listIndex);

    if (entityType == ENTITY_TYPE_HIDDEN_RED_BLOCK || entityType == ENTITY_TYPE_RED_BLOCK) {
        play_model_animation(entity->virtualModelIndex, Entity_HitRedBlock_AnimationHit);
    } else {
        play_model_animation(entity->virtualModelIndex, Entity_HitYellowBlock_AnimationHit);
    }
}

void entity_HitItemBlock_show_inactive(Entity* entity) {
    Entity* inertEntity;
    Shadow* inertShadow;
    BlockData* data = entity->dataBuf.block;

    inertEntity = get_entity_by_index(data->childEntityIndex);
    inertEntity->flags &= ~ENTITY_FLAG_HIDDEN;
    inertShadow = get_shadow_by_index(inertEntity->shadowIndex);
    inertShadow->flags &= ~ENTITY_FLAG_HIDDEN;
}

void entity_ItemBlock_check_if_inactive(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if ((data->gameFlagIndex != 0xFFFF) && get_global_flag(data->gameFlagIndex)) {
        EntityBlueprint* bp;

        if (get_entity_type(entity->listIndex) != ENTITY_TYPE_RED_BLOCK) {
            bp = &Entity_InertYellowBlock;
        } else {
            bp = &Entity_InertRedBlock;
        }
        create_entity(bp, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y, MAKE_ENTITY_END);
        set_entity_commandlist(entity, D_802EA310);
    } else {
        exec_entity_commandlist(entity);
    }
}

// when an item block is hit, it spawns two subsidiary entities: a dummy item block which performs a 'hit' animation
// followed by an inert version of the block.
void entity_ItemBlock_replace_with_inactive(Entity* entity) {
    s32 entityType = get_entity_type(entity->listIndex);
    EntityBlueprint* bp = &Entity_InertYellowBlock;
    s32 childEntityIndex;
    s32 isBlockOnGround;
    s32 parentEntityType;
    BlockData* childData;
    Entity* childEntity;
    Shadow* shadow;

    if (entityType < ENTITY_TYPE_HAMMER1_BLOCK) {
        bp = &Entity_InertYellowBlock;
        if (entityType >= ENTITY_TYPE_HIDDEN_RED_BLOCK) {
            bp = &Entity_InertRedBlock;
        }
    }

    // this child entity is the inert block
    childEntityIndex = create_entity(bp, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y, MAKE_ENTITY_END);
    childEntity = get_entity_by_index(childEntityIndex);
    childEntity->flags |= ENTITY_FLAG_HIDDEN;

    if (entity->flags & ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2) {
        childEntity->flags |= ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2;
    }

    if (entity->flags & ENTITY_FLAG_HAS_DYNAMIC_SHADOW) {
        childEntity->flags |= ENTITY_FLAG_HAS_DYNAMIC_SHADOW;
    }

    shadow = get_shadow_by_index(childEntity->shadowIndex);
    shadow->flags |= (ENTITY_FLAG_SHADOW_POS_DIRTY | ENTITY_FLAG_HIDDEN);
    isBlockOnGround = is_block_on_ground(entity);

    parentEntityType = get_entity_type(entity->listIndex);
    if (parentEntityType == ENTITY_TYPE_HIDDEN_RED_BLOCK || parentEntityType == ENTITY_TYPE_RED_BLOCK) {
        bp = &Entity_HitRedBlock;
    } else if (isBlockOnGround != 0) {
        bp = &Entity_HitGroundedYellowBlock;
    } else {
        bp = &Entity_HitFloatingYellowBlock;
    }

    // child entity is now the animated block which appears before it turns inert
    childEntity = get_entity_by_index(create_entity(bp, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y, MAKE_ENTITY_END));
    childEntity->alpha = entity->alpha;
    if ((entity->flags & ENTITY_FLAG_HIDDEN) || (entity->alpha < 255)) {
        childEntity->alpha = 32;
    }

    if (entity->flags & ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2) {
        childEntity->flags |= ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2;
    }

    childData = childEntity->dataBuf.block;
    childData->childEntityIndex = childEntityIndex;

    if (entity->flags & ENTITY_FLAG_HAS_DYNAMIC_SHADOW) {
        childEntity->flags |= ENTITY_FLAG_HAS_DYNAMIC_SHADOW;
    }

    entity->flags &= ~ENTITY_FLAG_HAS_SHADOW;
    shadow = get_shadow_by_index(entity->shadowIndex);
    shadow->flags |= (ENTITY_FLAG_FADING_AWAY | ENTITY_FLAG_HIDDEN);
    shadow = get_shadow_by_index(childEntity->shadowIndex);
    shadow->flags |= ENTITY_FLAG_SHADOW_POS_DIRTY;
}

void entity_HitItemBlock_hide(Entity* entity) {
    entity->flags |= ENTITY_FLAG_HIDDEN;
    entity->flags &= ~ENTITY_FLAG_HAS_SHADOW;
    get_shadow_by_index(entity->shadowIndex)->flags |= (ENTITY_FLAG_HIDDEN | ENTITY_FLAG_FADING_AWAY);
}

s32 entity_TriggerBlock_start_bound_script(Entity* entity) {
    if (entity->boundScriptBytecode != NULL) {
        entity->flags |= ENTITY_FLAG_BOUND_SCRIPT_DIRTY;
        return TRUE;
    }
    return FALSE;
}

void entity_TriggerBlock_disable_player_input(void) {
    disable_player_input();
    gPlayerStatus.curSpeed = 0.0f;
    gPlayerStatus.flags |= PS_FLAG_SCRIPTED_FALL;
    set_action_state(ACTION_STATE_FALLING);
    gravity_use_fall_parms();
}

void entity_TriggerBlock_enable_player_input(void) {
    enable_player_input();
}

void entity_ItemBlock_setupGfx(s32 entityIndex) {
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

void entity_ItemBlock_init(Entity* entity) {
    BlockData* data;

    entity_base_block_init(entity);
    data = entity->dataBuf.block;
    data->item = CreateEntityVarArgBuffer[0];
    data->gameFlagIndex = 0xFFFF;
    entity->renderSetupFunc = entity_ItemBlock_setupGfx;
}

void entity_HiddenItemBlock_init(Entity* entity) {
    entity_ItemBlock_init(entity);
    entity->alpha = 0;
}

void entity_ItemlessBlock_init(Entity* entity) {
    ModelAnimator* animator;

    entity_base_block_init(entity);
    entity->renderSetupFunc = entity_ItemBlock_setupGfx;
    animator = get_animator_by_index(entity->virtualModelIndex);
    animator->renderMode = 0x11;
    animator->flags |= 0x10000;
}

EntityScript D_802EA310 = {
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_ItemBlock_Script = {
    es_Call(entity_ItemBlock_check_if_inactive)
    es_SetCallback(NULL, 0)
    es_SetCallback(entity_ItemBlock_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_ItemBlock_spawn_item)
    es_Call(entity_ItemBlock_replace_with_inactive)
    es_SetCallback(NULL, 1)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript Entity_HiddenItemBlock_Script = {
    es_Call(entity_ItemBlock_check_if_inactive)
    es_SetCallback(NULL, 0)
    es_SetCallback(entity_HiddenItemBlock_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_ItemBlock_spawn_item)
    es_Call(entity_ItemBlock_replace_with_inactive)
    es_SetCallback(NULL, 1)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript Entity_HitBlock_Script = {
    es_SetCallback(NULL, 1)
    es_Call(entity_HitItemBlock_play_anim)
    es_SetCallback(entity_HitItemBlock_appear, 10)
    es_Call(entity_HitItemBlock_hide)
    es_Call(entity_HitItemBlock_show_inactive)
    es_SetCallback(NULL, 1)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_PENDING_FULL_DELETE)
    es_End
};
EntityScript Entity_TriggerBlock_Script = {
    es_SetCallback(entity_ItemBlock_idle, 0)
    es_Call(entity_TriggerBlock_disable_player_input)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_TriggerBlock_play_vanish_effect)
    es_Call(entity_inactive_block_hit_init)
    es_SetCallback(entity_inactive_block_hit_anim, 0)
    es_SetCallback(entity_inactive_block_recoil_anim, 0)
    es_Call(entity_TriggerBlock_start_bound_script)
    es_Call(entity_TriggerBlock_enable_player_input)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_Call(entity_TriggerBlock_start_bound_script_2)
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAG_PENDING_FULL_DELETE)
    es_End
};

DmaEntry Entity_HitYellowBlock_dma[] = { ENTITY_ROM(HitYellowBlock_gfx), ENTITY_ROM(HitYellowBlock_anim) };
DmaEntry Entity_HitFloatinYellowBlock_dma[] = { ENTITY_ROM(HitFloatingYellowBlock_gfx), ENTITY_ROM(HitFloatingYellowBlock_anim) };
DmaEntry Entity_HitRedBlock_dma[] = { ENTITY_ROM(HitRedBlock_gfx), ENTITY_ROM(HitRedBlock_anim) };

EntityModelScript Entity_YellowBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_YellowBlock_Render, RENDER_MODE_SURFACE_OPA);
EntityModelScript Entity_HiddenYellowBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_YellowBlock_Render, RENDER_MODE_SURFACE_XLU_LAYER2);
EntityModelScript Entity_RedBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RedBlock_Render, RENDER_MODE_SURFACE_OPA);
EntityModelScript Entity_HiddenRedBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RedBlock_Render, RENDER_MODE_SURFACE_XLU_LAYER2);

EntityBlueprint Entity_YellowBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_YellowBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_ItemBlock_init,
    .updateEntityScript = Entity_ItemBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(YellowBlock) },
    .entityType = ENTITY_TYPE_YELLOW_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HiddenYellowBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HiddenYellowBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_HiddenItemBlock_init,
    .updateEntityScript = Entity_HiddenItemBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(YellowBlock) },
    .entityType = ENTITY_TYPE_HIDDEN_YELLOW_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_RedBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_RedBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_ItemBlock_init,
    .updateEntityScript = Entity_ItemBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(RedBlock) },
    .entityType = ENTITY_TYPE_RED_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HiddenRedBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HiddenRedBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_HiddenItemBlock_init,
    .updateEntityScript = Entity_HiddenItemBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(RedBlock) },
    .entityType = ENTITY_TYPE_HIDDEN_RED_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_TriggerBlock = {
    .flags = ENTITY_FLAG_8000 | ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HitYellowBlock_AnimationIdle,
    .modelAnimationNodes = Entity_HitYellowBlock_Mesh,
    .fpInit = entity_ItemlessBlock_init,
    .updateEntityScript = Entity_TriggerBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dmaList = Entity_HitYellowBlock_dma },
    .entityType = ENTITY_TYPE_SINGLE_TRIGGER_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HitGroundedYellowBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HitYellowBlock_AnimationIdle,
    .modelAnimationNodes = Entity_HitYellowBlock_Mesh,
    .fpInit = entity_ItemlessBlock_init,
    .updateEntityScript = Entity_HitBlock_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_HitYellowBlock_dma },
    .entityType = ENTITY_TYPE_YELLOW_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HitFloatingYellowBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HitFloatingYellowBlock_AnimationIdle,
    .modelAnimationNodes = Entity_HitFloatingYellowBlock_Mesh,
    .fpInit = entity_ItemlessBlock_init,
    .updateEntityScript = Entity_HitBlock_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_HitFloatinYellowBlock_dma },
    .entityType = ENTITY_TYPE_YELLOW_BLOCK,
    .aabbSize = { 25, 25, 25 }
};

EntityBlueprint Entity_HitRedBlock = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(BlockData),
    .renderCommandList = Entity_HitRedBlock_AnimationHit,
    .modelAnimationNodes = Entity_HitRedBlock_Mesh,
    .fpInit = entity_ItemlessBlock_init,
    .updateEntityScript = Entity_HitBlock_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_HitRedBlock_dma },
    .entityType = ENTITY_TYPE_RED_BLOCK,
    .aabbSize = { 25, 25, 25 }
};
