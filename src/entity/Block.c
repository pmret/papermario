#include "common.h"
#include "effects.h"
#include "ld_addrs.h"

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
    s32 bVar2;
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

    bVar2 = FALSE;
    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_JUMP || playerStatus->actionState == ACTION_STATE_ULTRA_JUMP) {
            return FALSE;
        }

        if (playerStatus->actionState == ACTION_STATE_GROUND_POUND || playerStatus->actionState == ACTION_STATE_ULTRA_POUND) {
            bVar2 = TRUE;
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
            if (bVar2) {
                if (gPlayerData.bootsLevel < 1) {
                    bVar2 = FALSE;
                }
            } else {
                if (gPlayerData.hammerLevel > -1) {
                    bVar2 = TRUE;
                }
            }
            if (!bVar2) {
                return 1;
            }
            set_entity_commandlist(entity, D_802E9E80);
            sfx_play_sound_at_position(SOUND_14F, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            if (bVar2) {
                if (gPlayerData.bootsLevel < 2) {
                    bVar2 = FALSE;
                }
            } else if (gPlayerData.hammerLevel > 0) {
                bVar2 = TRUE;
            }
            if (!bVar2) {
                return 1;
            }
            set_entity_commandlist(entity, D_802E9E80);
            sfx_play_sound_at_position(SOUND_150, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            if (gPlayerData.hammerLevel < 2) {
                return 1;
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

s32 D_802E9D90[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_block_hit_init_scale, 0x00000003, 0x00000006, entity_block_hit_animate_scale, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9DCC[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000, 0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9E0C[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_inactive_block_hit_init, 0x00000002, entity_start_script, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9E54[] = {
    0x00000002, entity_inactive_block_hit_init, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000001, D_802E9E0C, 0x00000000
};
s32 D_802E9E80[] = {
    0x00000006, 0x00000007, 0x00000001, 0x00000007, 0x00000020, 0x00000002, entity_breakable_block_create_shattering_entity, 0x00000003, 0x00000001, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802E9EB4[] = {
    0x00000003, 0x00000000, entity_BrickBlock_idle, 0x00000002, entity_start_script, 0x00000007, 0x00000001, 0x00000007, 0x00000020, 0x00000002, entity_breakable_block_create_shattering_entity, 0x00000009, 0x0000014E, 0x00000003, 0x00000002, 0x00000000, 0x00000007, 0x20000000, 0x00000000
};
s32 D_802E9F00[] = {
    0x00000003, 0x00000000, entity_base_block_idle, 0x00000009, 0x0000014E, 0x00000002, entity_start_script, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802E9F28[] = {
    0x00000002, entity_MulticoinBlock_check_if_inactive, 0x00000005, 0x00000001, 0x00000003, 0x00000000, entity_MulticoinBlock_idle, 0x00000009, 0x0000014E, 0x00000002, entity_MulticoinBlock_spawn_coin, 0x00000002, entity_inactive_block_hit_init, 0x00000003, 0x00000000, entity_inactive_block_hit_anim, 0x00000003, 0x00000000, entity_inactive_block_recoil_anim, 0x00000004, 0x00000001, 0x00000000
};
s32 D_802E9F80[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004E0, 0x00000002, 0x00000000
};
s32 D_802E9F9C[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000A90, 0x00000002, 0x00000000
};
s32 D_802E9FB8[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004A0, 0x00000002, 0x00000000
};
s32 D_802E9FD4[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004F0, 0x00000002, 0x00000000
};
s32 D_802E9FF0[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004F0, 0x00000002, 0x00000000
};
s32 D_802EA00C[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004E0, 0x00000002, 0x00000000
};
s32 D_802EA028[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000338, 0x00000002, 0x00000000
};
s32 D_802EA044[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A0004A0, 0x00000002, 0x00000000
};
s32 D_802EA060[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000CC8, 0x00000002, 0x00000000
};

EntityBlueprint Entity_InertYellowBlock = {
    0x4200, 0x0020, D_802E9F80, 0, entity_init_Hammer1Block_normal, D_802E9E0C, entity_block_handle_collision, E42240_ROM_START, E42240_ROM_END, ENTITY_TYPE_MULTI_TRIGGER_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_InertRedBlock = {
    0x4200, 0x0020, D_802E9F9C, 0, entity_init_Hammer1Block_normal, D_802E9E0C, entity_block_handle_collision, E42740_ROM_START, E42740_ROM_END, ENTITY_TYPE_INACTIVE_BLOCK, { 25, 25, 25 }
};
EntityBlueprint D_802EA0C4 = {
    0x4280, 0x0020, D_802EA044, 0, entity_base_block_init, D_802E9EB4, entity_block_handle_collision, E3DDB0_ROM_START, E3DDB0_ROM_END, ENTITY_TYPE_BRICK_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA0E8 = {
    0x4200, 0x0020, D_802E9FB8, 0x00000000, entity_MulticoinBlock_init, D_802E9F28, entity_block_handle_collision, E3DDB0_ROM_START, E3DDB0_ROM_END, ENTITY_TYPE_MULTI_COIN_BRICK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA10C = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 50 }
};
EntityBlueprint Entity_D_802EA130 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 100, 50, 50 }
};
EntityBlueprint Entity_D_802EA154 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_Hammer1Block_normal, D_802E9F00, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, { 50, 50, 100 }
};
EntityBlueprint Entity_D_802EA178 = {
    0x4280, 0x0020, D_802E9FD4, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31530_ROM_START, E31530_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA19C = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 50 }
};
EntityBlueprint D_802EA1C0 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 100, 50, 50 }
};
EntityBlueprint D_802EA1E4 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, { 50, 50, 100 }
};
EntityBlueprint D_802EA208 = {
    0x4280, 0x0020, D_802E9FF0, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31A30_ROM_START, E31A30_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint D_802EA22C = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 50 }
};
EntityBlueprint D_802EA250 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 100, 50, 50 }
};
EntityBlueprint D_802EA274 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, { 50, 50, 100 }
};
EntityBlueprint D_802EA298 = {
    0x4280, 0x0020, D_802EA00C, 0x00000000, entity_init_HammerBlock_small, D_802E9DCC, entity_block_handle_collision, E31F30_ROM_START, E31F30_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK_TINY, { 25, 25, 25 }
};
EntityBlueprint D_802EA2BC = {
    0x4000, 0x0020, D_802EA028, 0x00000000, entity_base_block_init, D_802E9DCC, entity_block_handle_collision, E3DA60_ROM_START, E3DA60_ROM_END, ENTITY_TYPE_PUSH_BLOCK, { 25, 25, 25 }
};
EntityBlueprint Entity_D_802EA2E0 = {
    0x4000, 0x0020, D_802EA060, 0x00000000, entity_base_block_init, D_802E9D90, entity_block_handle_collision, E43B20_ROM_START, E43B20_ROM_END, ENTITY_TYPE_POW_BLOCK, { 30, 25, 25 },
};
