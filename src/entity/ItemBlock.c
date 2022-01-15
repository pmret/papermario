#include "common.h"
#include "effects.h"

void entity_ItemBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

void entity_HiddenItemBlock_idle(Entity* entity) {
    s32 alpha = entity->alpha;

    if (gPlayerStatus.animFlags & 1) {
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

INCLUDE_ASM(s32, "entity/ItemBlock", entity_HitItemBlock_appear);

INCLUDE_ASM(void, "entity/ItemBlock", entity_ItemBlock_spawn_item, Entity* entity);

void entity_TriggerBlock_start_bound_script_2(Entity* entity) {
    entity_start_script(entity);
}

void entity_TriggerBlock_play_vanish_effect(Entity* entity) {
    TriggerBlockVanishEffect = playFX_6F(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
}

void entity_HitItemBlock_play_anim(Entity* entity) {
    s32 entityType = get_entity_type(entity->listIndex);

    if (entityType == ENTITY_TYPE_HIDDEN_RED_BLOCK || entityType == ENTITY_TYPE_RED_BLOCK) {
        play_model_animation(entity->virtualModelIndex, &D_00000094);
    } else {
        play_model_animation(entity->virtualModelIndex, &D_00000094_2);
    }
}

void entity_HitItemBlock_show_inactive(Entity* entity) {
    Entity* inertEntity;
    Shadow* inertShadow;
    ItemBlockData* data = entity->dataBuf.itemBlock;

    inertEntity = get_entity_by_index(data->childEntityIndex);
    inertEntity->flags &= ~ENTITY_FLAGS_HIDDEN;
    inertShadow = get_shadow_by_index(inertEntity->shadowIndex);
    inertShadow->flags &= ~SHADOW_FLAGS_HIDDEN;
}

void entity_ItemBlock_check_if_inactive(Entity* entity) {
    ItemBlockData* data = entity->dataBuf.itemBlock;

    if ((data->gameFlagIndex != 0xFFFF) && get_global_flag(data->gameFlagIndex)) {
        UNK_PTR phi_a0;

        if (get_entity_type(entity->listIndex) != ENTITY_TYPE_RED_BLOCK) {
            phi_a0 = &Entity_InertYellowBlock;
        } else {
            phi_a0 = &Entity_InertRedBlock;
        }
        create_entity(phi_a0, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
        set_entity_commandlist(entity, &D_802EA310);
    } else {
        exec_entity_commandlist(entity);
    }
}

// when an item block is hit, it spawns two subsidiary entities: a dummy item block which performs a 'hit' animation
// followed by an inert version of the block.
void entity_ItemBlock_replace_with_inactive(Entity* entity) {
    s32 entityType = get_entity_type(entity->listIndex);
    EntityBlueprint* entityBlueprint = &Entity_InertYellowBlock;
    s32 childEntityIndex;
    s32 isBlockOnGround;
    s32 parentEntityType;
    ItemBlockData* temp;
    Entity* childEntity;
    Shadow* shadow;

    if (entityType < ENTITY_TYPE_HAMMER1_BLOCK) {
        entityBlueprint = &Entity_InertYellowBlock;
        if (entityType >= ENTITY_TYPE_HIDDEN_RED_BLOCK) {
            entityBlueprint = &Entity_InertRedBlock;
        }
    }

    // this child entity is the inert block
    childEntityIndex = create_entity(entityBlueprint, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
    childEntity = get_entity_by_index(childEntityIndex);
    childEntity->flags |= ENTITY_FLAGS_HIDDEN;

    if (entity->flags & ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2) {
        childEntity->flags |= ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;
    }

    if (entity->flags & ENTITY_FLAGS_HAS_DYNAMIC_SHADOW) {
        childEntity->flags |= ENTITY_FLAGS_HAS_DYNAMIC_SHADOW;
    }

    shadow = get_shadow_by_index(childEntity->shadowIndex);
    shadow->flags |= (SHADOW_FLAGS_POSITION_DIRTY | SHADOW_FLAGS_HIDDEN);
    isBlockOnGround = is_block_on_ground(entity);

    parentEntityType = get_entity_type(entity->listIndex);
    if (parentEntityType == ENTITY_TYPE_HIDDEN_RED_BLOCK || parentEntityType == ENTITY_TYPE_RED_BLOCK) {
        entityBlueprint = &Entity_HitRedBlock;
    } else if (isBlockOnGround != 0) {
        entityBlueprint = &Entity_HitGroundedYellowBlock;
    } else {
        entityBlueprint = &Entity_HitFloatingYellowBlock;
    }

    // child entity is now the animated block which appears before it turns inert
    childEntity = get_entity_by_index(create_entity(entityBlueprint, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000));
    childEntity->alpha = entity->alpha;
    if ((entity->flags & ENTITY_FLAGS_HIDDEN) || (entity->alpha < 0xFF)) {
        childEntity->alpha = 0x20;
    }

    if (entity->flags & ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2) {
        childEntity->flags |= ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE2;
    }

    temp = childEntity->dataBuf.unk;
    temp->childEntityIndex = childEntityIndex;

    if (entity->flags & ENTITY_FLAGS_HAS_DYNAMIC_SHADOW) {
        childEntity->flags |= ENTITY_FLAGS_HAS_DYNAMIC_SHADOW;
    }

    entity->flags &= ~ENTITY_FLAGS_100;
    shadow = get_shadow_by_index(entity->shadowIndex);
    shadow->flags |= (SHADOW_FLAGS_FADING_AWAY | SHADOW_FLAGS_HIDDEN);
    shadow = get_shadow_by_index(childEntity->shadowIndex);
    shadow->flags |= SHADOW_FLAGS_POSITION_DIRTY;
}

void entity_HitItemBlock_hide(Entity* entity) {
    entity->flags |= ENTITY_FLAGS_HIDDEN;
    entity->flags &= ~ENTITY_FLAGS_100;
    get_shadow_by_index(entity->shadowIndex)->flags |= (SHADOW_FLAGS_HIDDEN | SHADOW_FLAGS_FADING_AWAY);
}

s32 entity_TriggerBlock_start_bound_script(Entity* entity) {
    if (entity->boundScriptBytecode != NULL) {
        entity->flags |= ENTITY_FLAGS_BOUND_SCRIPT_DIRTY;
        return TRUE;
    }
    return FALSE;
}

void entity_TriggerBlock_disable_player_input(void) {
    disable_player_input();
    gPlayerStatus.currentSpeed = 0.0f;
    gPlayerStatus.flags |= PLAYER_STATUS_FLAGS_800000;
    set_action_state(8);
    gravity_use_fall_parms();
}

void entity_TriggerBlock_enable_player_input(void) {
    enable_player_input();
}

void entity_ItemBlock_setupGfx(s32 entityIndex) {
    Gfx* gfx = gMasterGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);

    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPTexture(gfx++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    if (entity->alpha >= 255) {
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, entity->alpha);
    }

    gMasterGfxPos = gfx;
}

void entity_ItemBlock_init(Entity* entity) {
    ItemBlockData* data;

    entity_base_block_init(entity);
    data = entity->dataBuf.itemBlock;
    data->itemID = *CreateEntityVarArgBuffer;
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
