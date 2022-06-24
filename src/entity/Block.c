#include "common.h"
#include "effects.h"
#include "ld_addrs.h"
#include "entity_script.h"

extern Gfx Entity_InertYellowBlock_Render[];
extern Gfx Entity_InertRedBlock_Render[];
extern Gfx Entity_BrickBlock_Render[];
extern Gfx Entity_Hammer1Block_Render[];
extern Gfx Entity_Hammer2Block_Render[];
extern Gfx Entity_Hammer3Block_Render[];
extern Gfx Entity_PushBlock_Render[];
extern Gfx Entity_PowBlock_Render[];

extern s32 D_802E9E54[];
extern s32 D_802E9E80[];

void entity_BrickBlock_idle(Entity* entity);
void entity_breakable_block_create_shattering_entity(Entity* entity);

void entity_MulticoinBlock_update_timer(Entity* entity);

#define MULTICOIN_BLOCK_MAX_COINS 10

void entity_base_block_setupGfx(s32 entityIndex) {
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

void entity_base_block_play_vanish_effect(Entity* entity) {
    fx_cold_breath(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
}

f32 entity_block_hit_init_scale(Entity* entity) {
    s32 type = get_entity_type(entity->listIndex);
    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY || type == ENTITY_TYPE_HAMMER2_BLOCK_TINY || type == ENTITY_TYPE_HAMMER3_BLOCK_TINY) {
        entity->scale.y = 0.23f;
        entity->scale.x = 1.04f;
        entity->scale.z = 1.04f;
        entity->position.y += 18.0f;
    } else {
        entity->scale.y = 0.46f;
        entity->scale.x = 2.08f;
        entity->scale.z = 2.08f;
        entity->position.y += 18.0f;
    }
}

void entity_block_hit_animate_scale(Entity* entity) {
    s32 type = get_entity_type(entity->listIndex);
    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY || type == ENTITY_TYPE_HAMMER2_BLOCK_TINY || type == ENTITY_TYPE_HAMMER3_BLOCK_TINY) {
        entity->scale.x -= 0.09;
        entity->scale.z -= 0.09;
        entity->scale.y += 0.045;
        entity->position.y -= 3.0f;
    } else {
        entity->scale.x -= 0.18;
        entity->scale.z -= 0.18;
        entity->scale.y += 0.09;
        entity->position.y -= 3.0f;
    }
    entity_base_block_idle(entity);
}

void entity_base_block_update_slow_sinking(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlockData* data = entity->dataBuf.block;
    f32 f2, f4, temp;
    f32 f2x, f4x, tempx;

    if (entity->alpha < 255) {
        entity->flags &= ~ENTITY_FLAGS_200000;
        return;
    }

    if (!(data->unk_0E & 0x8000)) {
        if (data->unk_0E < 150) {
            data->unk_0E++;
            return;
        }

        if (entity->position.y < data->initialY - 25.0f) {
            temp = (entity->position.y - data->initialY + 50.0f) * 0.125f;
        } else {
            temp = (data->initialY - entity->position.y) * 0.125f;
        }

        if (temp > 1.2) {
            temp = 1.2f;
        }
        if (temp < 0.3) {
            temp = 0.3f;
        }

        entity->position.y += temp;

        if (data->initialY < entity->position.y) {
            entity->position.y = data->initialY;
            data->unk_0E = -1;
            entity->flags &= ~ENTITY_FLAGS_200000;
        }
    } else {
        if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING) {
            if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_JUMPING)) {
                Shadow* shadow = get_shadow_by_index(entity->shadowIndex);
                if (shadow != NULL) {
                    f32 temp2 = entity->position.y - shadow->position.y;

                    if (entity->position.y - temp2 <= playerStatus->colliderHeight + 1) {
                        entity->position.y = playerStatus->colliderHeight + 1;
                        data->unk_0E = 1;
                    }
                }
            } else {
                data->unk_0E = 1;
                return;
            }
            do {} while (0); // needed to match
        } else {
            Shadow* shadow = get_shadow_by_index(entity->shadowIndex);
            if (shadow != NULL) {
                if (entity->position.y <= shadow->position.y) {
                    entity->position.y = shadow->position.y;
                    data->unk_0E = 1;
                }
            }
        }

        if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING) {
            data->unk_0E = 1;
            return;
        }

        if (entity->position.y < data->initialY - 25.0f) {
            temp = (entity->position.y - data->initialY + 50.0f) * 0.125f;
        } else {
            temp = (data->initialY - entity->position.y) * 0.125f;
        }

        if (temp > 1.2) {
            temp = 1.2f;
        }
        if (temp < 0.3) {
            temp = 0.3f;
        }

        entity->position.y -= temp;

        if (entity->position.y < data->initialY - 50.0f) {
            entity->position.y = data->initialY - 50.0f;
            data->unk_0E = 1;
        }
    }
}

s32 entity_base_block_idle(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    s32 ret = 0;

    if (is_block_on_ground(entity) != 0) {
        if (entity->flags & ENTITY_FLAGS_200000) {
            ret = 1;
            entity_base_block_update_slow_sinking(entity);
            if (data->itemEntityIndex != -1) {
                ItemEntity* itemEntity = get_item_entity(data->itemEntityIndex);
                itemEntity->position.y = entity->position.y + 4.0f;
            }
        }
    }

    return ret;
}

void entity_base_block_init(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->itemEntityIndex = -1;
    data->initialY = entity->position.y;
    data->unk_0E = -1;
    entity->flags &= ~ENTITY_FLAGS_200000;
}

void entity_inactive_block_hit_init(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->recoilInterpPhase = 90.0f;
}

void entity_inactive_block_hit_anim(Entity* entity) {
    BlockData* data = entity->dataBuf.block;
    f64 currentY;

    entity_MulticoinBlock_update_timer(entity);
    currentY = entity->position.y;
    entity->position.y = currentY + ((f64)sin_rad((data->recoilInterpPhase * 6.28318f) / 360.0f) * 2);
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
    currentY = entity->position.y;
    entity->position.y = currentY + ((f64)sin_rad((data->recoilInterpPhase * 6.28318f) / 360.0f));
    data->recoilInterpPhase += 60.0f;
    if (data->recoilInterpPhase >= 360.0f) {
        data->recoilInterpPhase = 0.0f;
        entity->position.y = data->initialY;
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
        make_item_entity_nodelay(ITEM_COIN, entity->position.x, entity->position.y + 28.0, entity->position.z, itemSpawnMode, flagIndex);
        data->coinsLeft -= 1;
    }

    if ((data->coinsLeft == 0) || (data->timeLeft == 0)) {
        data->empty = TRUE;
        set_entity_commandlist(get_entity_by_index(create_entity(&Entity_InertYellowBlock,
            (s32)entity->position.x, (s32)entity->position.y, (s32)entity->position.z, (s32)entity->rotation.y, MAKE_ENTITY_END)), D_802E9E54);
        entity->flags |= (ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_PENDING_INSTANCE_DELETE);
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

    if (entity->collisionFlags & ENTITY_COLLISION_BLOCK_HIT) {
        exec_entity_commandlist(entity);
        return;
    }
    entity_MulticoinBlock_update_timer(entity);
    entity_base_block_idle(entity);
    if (data->empty) {
        create_entity(&Entity_InertYellowBlock, (s32)entity->position.x, (s32)entity->position.y, (s32)entity->position.z, (s32)entity->rotation.y, MAKE_ENTITY_END);
        entity->flags |= (ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_PENDING_INSTANCE_DELETE);
    }
}

void entity_MulticoinBlock_check_if_inactive(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if (data->gameFlagIndex != 0xFFFF) {
        if (get_global_flag(data->gameFlagIndex) != 0) {
            create_entity(&Entity_InertYellowBlock, (s32)entity->position.x, (s32)entity->position.y, (s32)entity->position.z, (s32)entity->rotation.y, MAKE_ENTITY_END);
            entity->flags |= (ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_PENDING_INSTANCE_DELETE);
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

        if (playerStatus->flags & PLAYER_STATUS_FLAGS_JUMPING) {
            exec_entity_commandlist(entity);
        }
        return TRUE;
    }
    if (entity->collisionFlags & ENTITY_COLLISION_BLOCK_HIT) {
        exec_entity_commandlist(entity);
        return TRUE;
    }

    breakBlock = FALSE;
    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_JUMP || playerStatus->actionState == ACTION_STATE_ULTRA_JUMP) {
            return FALSE;
        }

        if (playerStatus->actionState == ACTION_STATE_GROUND_POUND || playerStatus->actionState == ACTION_STATE_ULTRA_POUND) {
            breakBlock = TRUE;
        } else {
            return TRUE;
        }
    } else {
        if (!(entity->collisionFlags & ENTITY_COLLISION_PLAYER_HAMMER)) {
            return TRUE;
        }
        if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_1000000)) {
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
            set_entity_commandlist(entity, D_802E9E80);
            sfx_play_sound_at_position(SOUND_14F, 0, entity->position.x, entity->position.y, entity->position.z);
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
            set_entity_commandlist(entity, D_802E9E80);
            sfx_play_sound_at_position(SOUND_150, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            if (gPlayerData.hammerLevel < 2) {
                return TRUE;
            }
            set_entity_commandlist(entity, D_802E9E80);
            sfx_play_sound_at_position(SOUND_151, 0, entity->position.x, entity->position.y, entity->position.z);
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

s32 entity_init_HammerBlock_small(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    data->itemEntityIndex = -1;
    data->initialY = entity->position.y;
    data->unk_0E = -1;
    entity->flags &= ~ENTITY_FLAGS_200000;
    entity->scale.x = 0.5f;
    entity->scale.y = 0.5f;
    entity->scale.z = 0.5f;
}

EntityScript D_802E9D90 = {
    es_SetCallback(entity_base_block_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_block_hit_init_scale)
    es_SetCallback(entity_block_hit_animate_scale, 6)
    es_Call(entity_start_script)
    es_Restart
    es_End
};
EntityScript D_802E9DCC = {
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
EntityScript D_802E9E54 = {
    es_Call(entity_inactive_block_hit_init)
    es_SetCallback(entity_inactive_block_hit_anim, 0)
    es_SetCallback(entity_inactive_block_recoil_anim, 0)
    es_Jump(Entity_InertBlock_Script)
    es_End
};
EntityScript D_802E9E80 = {
    es_RestartBoundScript
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetFlags(ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX)
    es_Call(entity_breakable_block_create_shattering_entity)
    es_SetCallback(NULL, 1)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript D_802E9EB4 = {
    es_SetCallback(entity_BrickBlock_idle, 0)
    es_Call(entity_start_script)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetFlags(ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX)
    es_Call(entity_breakable_block_create_shattering_entity)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_SetCallback(NULL, 2)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};
EntityScript D_802E9F00 = {
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

EntityModelScript Entity_InertYellowBlock_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_InertYellowBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_InertRedBlock_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_InertRedBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_MulticoinBrick_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_BrickBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_Hammer1Block_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_Hammer1Block_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_Hammer2Block_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_Hammer2Block_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_Hammer3Block_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_Hammer3Block_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_PushBlock_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_PushBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_BrickBlock_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_BrickBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_PowBlock_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_Draw(Entity_PowBlock_Render, 60)
    ems_Restart
    ems_End
};

EntityBlueprint Entity_InertYellowBlock = {
    0x4200, 0x0020, Entity_InertYellowBlock_RenderScript, 0, entity_init_Hammer1Block_normal, Entity_InertBlock_Script, entity_block_handle_collision, entity_model_InertYellowBlock_ROM_START, entity_model_InertYellowBlock_ROM_END, ENTITY_TYPE_MULTI_TRIGGER_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_InertRedBlock = {
    0x4200, 0x0020, Entity_InertRedBlock_RenderScript, 0, entity_init_Hammer1Block_normal, Entity_InertBlock_Script, entity_block_handle_collision, entity_model_InertRedBlock_ROM_START, entity_model_InertRedBlock_ROM_END, ENTITY_TYPE_INACTIVE_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_BrickBlock = {
    0x4280, 0x0020, Entity_BrickBlock_RenderScript, 0, entity_base_block_init, D_802E9EB4, entity_block_handle_collision, entity_model_BrickBlock_ROM_START, entity_model_BrickBlock_ROM_END, ENTITY_TYPE_BRICK_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_MulticoinBlock = {
    0x4200, 0x0020, Entity_MulticoinBrick_RenderScript, 0, entity_MulticoinBlock_init, Entity_MulticoinBlock_Script, entity_block_handle_collision, entity_model_BrickBlock_ROM_START, entity_model_BrickBlock_ROM_END, ENTITY_TYPE_MULTI_COIN_BRICK, { 25, 25, 25 }
};
EntityBlueprint Entity_Hammer1Block = {
    0x4280, 0x0020, Entity_Hammer1Block_RenderScript, 0, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, entity_model_Hammer1Block_ROM_START, entity_model_Hammer1Block_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 50 }
};
EntityBlueprint Entity_Hammer1Block_WideHitbox = {
    0x4280, 0x0020, Entity_Hammer1Block_RenderScript, 0, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, entity_model_Hammer1Block_ROM_START, entity_model_Hammer1Block_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 100, 50, 50 }
};
EntityBlueprint Entity_Hammer1Block_TallHitbox = {
    0x4280, 0x0020, Entity_Hammer1Block_RenderScript, 0, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, entity_model_Hammer1Block_ROM_START, entity_model_Hammer1Block_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 100 }
};
EntityBlueprint Entity_Hammer1BlockTiny = {
    0x4280, 0x0020, Entity_Hammer1Block_RenderScript, 0, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer1Block_ROM_START, entity_model_Hammer1Block_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint Entity_Hammer2Block = {
    0x4280, 0x0020, Entity_Hammer2Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer2Block_ROM_START, entity_model_Hammer2Block_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 50 }
};
EntityBlueprint Entity_Hammer2Block_WideHitbox = {
    0x4280, 0x0020, Entity_Hammer2Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer2Block_ROM_START, entity_model_Hammer2Block_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 100, 50, 50 }
};
EntityBlueprint Entity_Hammer2Block_TallHitbox = {
    0x4280, 0x0020, Entity_Hammer2Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer2Block_ROM_START, entity_model_Hammer2Block_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 100 }
};
EntityBlueprint Entity_Hammer2BlockTiny = {
    0x4280, 0x0020, Entity_Hammer2Block_RenderScript, 0, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer2Block_ROM_START, entity_model_Hammer2Block_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint Entity_Hammer3Block = {
    0x4280, 0x0020, Entity_Hammer3Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer3Block_ROM_START, entity_model_Hammer3Block_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 50 }
};
EntityBlueprint Entity_Hammer3Block_WideHitbox = {
    0x4280, 0x0020, Entity_Hammer3Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer3Block_ROM_START, entity_model_Hammer3Block_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 100, 50, 50 }
};
EntityBlueprint Entity_Hammer3Block_TallHitbox = {
    0x4280, 0x0020, Entity_Hammer3Block_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer3Block_ROM_START, entity_model_Hammer3Block_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 100 }
};
EntityBlueprint Entity_Hammer3BlockTiny = {
    0x4280, 0x0020, Entity_Hammer3Block_RenderScript, 0, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, entity_model_Hammer3Block_ROM_START, entity_model_Hammer3Block_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint Entity_PushBlock = {
    0x4000, 0x0020, Entity_PushBlock_RenderScript, 0, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, entity_model_PushBlock_ROM_START, entity_model_PushBlock_ROM_END, ENTITY_TYPE_PUSH_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_PowBlock = {
    0x4000, 0x0020, Entity_PowBlock_RenderScript, 0, entity_base_block_init, D_802E9D90, entity_block_handle_collision, entity_model_PowBlock_ROM_START, entity_model_PowBlock_ROM_END, ENTITY_TYPE_POW_BLOCK, { 30, 25, 25 },
};
