#include "common.h"

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
    playFX_6F(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
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
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s32 ret = 0;

    if (is_block_on_ground() != 0) {
        if (entity->flags & 0x200000) {
            ret = 1;
            entity_base_block_update_slow_sinking(entity);
            if (temp->unk_10 != -1) {
                ItemEntity* itemEntity = get_item_entity(temp->unk_10);
                itemEntity->position.y = entity->position.y + 4.0f;
            }
        }
    }

    return ret;
}

void entity_base_block_init(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    f32 posY;

    temp->unk_10 = -1;
    temp->unk_14 = entity->position.y;
    temp->unk_0E = -1;
    entity->flags &= ~0x200000;
}

void entity_inactive_block_hit_init(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    temp->unk_18 = 90.0f;
}

void entity_inactive_block_hit_anim(Entity* entity) {
    f64 temp_f20;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    entity_MulticoinBlock_update_timer(entity);
    temp_f20 = entity->position.y;
    entity->position.y = temp_f20 + ((f64)sin_rad((temp->unk_18 * 6.28318f) / 360.0f) * 2);
    temp->unk_18 += 60.0f;
    if (temp->unk_18 > 450.0f) {
        temp->unk_18 = clamp_angle(temp->unk_18);
        exec_entity_commandlist(entity);
    }
}

void entity_inactive_block_recoil_anim(Entity* entity) {
    f64 temp_f20;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    entity_MulticoinBlock_update_timer(entity);
    temp_f20 = entity->position.y;
    entity->position.y = temp_f20 + ((f64)sin_rad((temp->unk_18 * 6.28318f) / 360.0f));
    temp->unk_18 += 60.0f;
    if (temp->unk_18 >= 360.0f) {
        temp->unk_18 = 0.0f;
        entity->position.y = temp->unk_14;
        exec_entity_commandlist(entity);
    }
}

void entity_MulticoinBlock_init(Entity* entity) {
    struct802E3650* temp;

    entity_base_block_init(entity);
    temp = (struct802E3650*)entity->dataBuf;
    temp->unk_04 = 0xA;
    temp->unk_06 = 0x7B;
    temp->unk_0A = 0xFFFF;
}

extern s32 D_802E9E54;
extern StaticEntityData D_802EA07C;

void entity_MulticoinBlock_spawn_coin(Entity* entity) {
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s32 phi_v1;
    s32 phi_v0;

    if (temp->unk_04 > 0) {
        if (temp->unk_04 == 10) {
            phi_v1 = 21;
            phi_v0 = temp->unk_0A;
        } else {
            phi_v1 = 20;
            phi_v0 = 0;
        }
        make_item_entity_nodelay(0x157, entity->position.x, entity->position.y + 28.0, entity->position.z, phi_v1, phi_v0);
        temp->unk_04 -= 1;
    }

    if ((temp->unk_04 == 0) || (temp->unk_06 == 0)) {
        temp->unk_03 = 1;
        set_entity_commandlist(get_entity_by_index(create_entity(&D_802EA07C, entity->position.x, entity->position.y,
                               entity->position.z,
                               entity->rotation.y, 0x80000000)), &D_802E9E54);
        entity->flags |= 0x20000020;
    }
}

void entity_MulticoinBlock_update_timer(Entity* entity) {
    u16 temp_v0;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;
    s16 phi_return;

    if (entity->type == 0xE) {
        if (temp->unk_04 != 0xA) {
            temp->unk_06 -= 1;
            if (temp->unk_06 < 0) {
                temp->unk_06 = 0;
                temp->unk_04 = 1;
            }
        }
    }
}

void entity_MulticoinBlock_idle(Entity* entity) {
    s32 temp_v0;
    struct802E3650* temp = (struct802E3650*)entity->dataBuf;

    if ((entity->collisionFlags & 0x80) != 0) {
        exec_entity_commandlist(entity);
        return;
    }
    entity_MulticoinBlock_update_timer(entity);
    entity_base_block_idle(entity);
    if (temp->unk_03 != 0) {
        create_entity(&D_802EA07C, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
        entity->flags |= 0x20000020;
    }
}

void entity_MulticoinBlock_check_if_inactive(Entity* entity) {
    s32 temp_v0;
    u16 temp_v1;
    struct802E3650* temp = entity->dataBuf;

    if (temp->unk_0A != 0xFFFF) {
        if (get_global_flag(temp->unk_0A) != 0) {
            create_entity(&D_802EA07C, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
            entity->flags |= 0x20000020;
        }
    }
}

extern s32 D_802E9E80;

#ifdef NON_MATCHING
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
        default:
            break;
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
            sfx_play_sound_at_position(0x14f, 0, entity->position.x, entity->position.y, entity->position.z);
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
            sfx_play_sound_at_position(0x150, 0, entity->position.x, entity->position.y, entity->position.z);
            break;
        case 0x17:
        case 0x1a:
            if (gPlayerData.hammerLevel < '\x02') {
                return 1;
            }
            set_entity_commandlist(entity, &D_802E9E80);
            sfx_play_sound_at_position(0x151, 0, entity->position.x, entity->position.y, entity->position.z);
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
    s32 temp_v0;
    struct802E3650* temp = entity->dataBuf;

    temp->unk_10 = -1;
    temp->unk_14 = entity->position.y;
    temp->unk_0E = -1;
    entity->flags &= ~0x200000;
    entity->scale.x = 0.5f;
    entity->scale.y = 0.5f;
    entity->scale.z = 0.5f;
}
