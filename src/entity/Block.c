#include "common.h"
#include "effects.h"

extern s32 D_802E9E54;

void entity_MulticoinBlock_update_timer(Entity* entity);
void entity_base_block_update_slow_sinking(Entity* entity);

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
    if ((get_entity_type(entity->listIndex) - 24) < 3) {
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
    if ((get_entity_type(entity->listIndex) - 24) < 3) {
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

INCLUDE_ASM(s32, "entity/Block", entity_base_block_update_slow_sinking);

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
            entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, MAKE_ENTITY_END)), &D_802E9E54);
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

    if ((entity->collisionFlags & ENTITY_COLLISION_BLOCK_HIT) != 0) {
        exec_entity_commandlist(entity);
        return;
    }
    entity_MulticoinBlock_update_timer(entity);
    entity_base_block_idle(entity);
    if (data->empty) {
        create_entity(&Entity_InertYellowBlock, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, MAKE_ENTITY_END);
        entity->flags |= (ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_PENDING_INSTANCE_DELETE);
    }
}

void entity_MulticoinBlock_check_if_inactive(Entity* entity) {
    BlockData* data = entity->dataBuf.block;

    if (data->gameFlagIndex != 0xFFFF) {
        if (get_global_flag(data->gameFlagIndex) != 0) {
            create_entity(&Entity_InertYellowBlock, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, MAKE_ENTITY_END);
            entity->flags |= (ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_PENDING_INSTANCE_DELETE);
        }
    }
}

extern s32 D_802E9E80;

#ifdef NON_EQUIVALENT
// tail merge + rodata
s32 entity_block_handle_collision(Entity* entity) {
    u8 bVar1;
    s32 bVar2;
    s32 iVar3;
    s32 uVar4;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->alpha == 0) && ((entity->unk_06 & 1) != 0)) {
        return 0;
    }

    bVar1 = entity->unk_06;
    if (bVar1 & 4) {
        s32 type = get_entity_type(entity->listIndex);
        if (type == 0xC) {
            return 0;
        }

        if (type >= 0xC) {
            if (type < 0x1b) {
                if (type > 0x14) {
                    return 0;
                }
            }
        }

        if (!(playerStatus->flags & 2)) {
            return 1;
        }
        exec_entity_commandlist(entity);
        return 1;
    }
    if (bVar1 & 0x80) {
        exec_entity_commandlist(entity);
        return 1;
    }

    bVar2 = FALSE;
    if (bVar1 & 1) {
        if ((playerStatus->actionState == 0xd) || (playerStatus->actionState == 0x0f)) {
            return 0;
        }

        if ((playerStatus->actionState == 0x0e) || (playerStatus->actionState == 0x10)) {
            bVar2 = TRUE;
        } else {
            return 1;
        }
    } else {
        if (!(bVar1 & 0x40)) {
            return 1;
        }
        if ((playerStatus->flags & 0x1000000) == 0) {
            return 1;
        }
    }

    switch (get_entity_type(entity->listIndex)) {
        case 0x15:
        case 0x18:
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
            set_entity_commandlist(entity, &D_802E9E80);
            sfx_play_sound_at_position(SOUND_14F, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x16:
        case 0x19:
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
            set_entity_commandlist(entity, &D_802E9E80);
            sfx_play_sound_at_position(SOUND_150, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x17:
        case 0x1a:
            if (gPlayerData.hammerLevel < '\x02') {
                return 1;
            }
            set_entity_commandlist(entity, &D_802E9E80);
            sfx_play_sound_at_position(SOUND_151, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
            entity_start_script(entity);
            exec_entity_commandlist(entity);
            return 1;
        case 0xb:
            entity_start_script(entity);
            break;
    }
    return 1;
}
#else
INCLUDE_ASM(s32, "entity/Block", entity_block_handle_collision, Entity* entity);
#endif

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
