#include "common.h"

typedef struct struct802E3F0C {
    /* 0x00 */ char unk_00[10];
    /* 0x0A */ u16 unk_A;
    /* 0x0C */ char unk_C[4];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
} struct802E3F0C;

void func_802E3E80(Entity* entity) {
    func_802E3650(entity);
}

void func_802E3E9C(Entity* entity) {
    s32 alpha;

    alpha = entity->alpha;
    if (gPlayerStatus.animFlags & 1) {
        alpha += 32;
        if (alpha > 192) {
            alpha = 192;
        }
        entity->alpha = alpha;
        return;
    } else {
        alpha -= 32;
        if (alpha <= 0) {
            alpha = 0;
        }
        entity->alpha = alpha;
        return;
    }
}

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E3EE0);

INCLUDE_ASM(void, "code_105700_len_2130", func_802E3F0C, Entity* entity);

void func_802E4040(Entity* entity) {
    func_80110678(entity);
}

void func_802E405C(Entity* entity) {
    D_802EB3B0 = func_80072230(0, entity->position.x, entity->position.y, entity->position.z, 1.0f, 0x3C);
}

void func_802E40A0(Entity* entity) {
    s32 entityType;
    s32 virtualModelIndex;
    UNK_PTR ptr;

    entityType = get_entity_type(entity->listIndex);
    if ((entityType == 0x12) || (entityType == 0x14)) {
        play_model_animation(entity->virtualModelIndex, &D_00000094);
    } else {
        play_model_animation(entity->virtualModelIndex, &D_00000094_2);
    }
}

void func_802E4108(Entity* entity) {
    Entity* someEntity; // TODO: better var name
    Shadow* someShadow; // TODO: better var name
    struct802E3F0C* temp = entity->dataBuf;

    someEntity = get_entity_by_index(temp->unk_12);
    someEntity->flags &= ~1;
    someShadow = get_shadow_by_index(someEntity->shadowIndex);
    someShadow->flags &= ~1;
}

void func_802E4154(Entity* entity) {
    u16 temp_v1;
    UNK_PTR phi_a0;
    struct802E3F0C* temp = entity->dataBuf;

    if ((temp->unk_A != 0xFFFF) && get_global_flag(temp->unk_A)) {
        if (get_entity_type(entity->listIndex) != 0x14) {
            phi_a0 = &D_802EA07C;
        } else {
            phi_a0 = &D_802EA0A0;
        }
        create_entity(phi_a0, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y, 0x80000000);
        set_entity_updatecmd(entity, &D_802EA310);
    } else {
        exec_entity_updatecmd(entity);
    }
}

void func_802E421C(Entity* entity) {
    s32 temp_s2;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_5;
    struct802E3F0C* temp;
    Entity* entityTemp;
    Shadow* shadow;
    UNK_PTR phi_a0;

    temp_v0_2 = get_entity_type(entity->listIndex);
    phi_a0 = &D_802EA07C;
    if (temp_v0_2 < 0x15) {
        phi_a0 = &D_802EA07C;
        if (temp_v0_2 >= 0x12) {
            phi_a0 = &D_802EA0A0;
        }
    }
    temp_s2 = create_entity(phi_a0, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y,
                            0x80000000);
    entityTemp = get_entity_by_index(temp_s2);
    entityTemp->flags |= 1;

    if ((entity->flags & 0x40000) != 0) {
        entityTemp->flags |= 0x40000;
    }

    if ((entity->flags & 4) != 0) {
        entityTemp->flags |= 4;
    }

    shadow = get_shadow_by_index(entityTemp->shadowIndex);
    shadow->flags |= 0x400001;
    temp_s0 = func_80112B20(entity);
    temp_v0_5 = get_entity_type(entity->listIndex);
    if ((temp_v0_5 == 0x12) || (temp_v0_5 == 0x14)) {
        phi_a0 = &D_802EA660;
    } else if (temp_s0 != 0) {
        phi_a0 = &D_802EA618;
    } else {
        phi_a0 = &D_802EA63C;
    }
    entityTemp = get_entity_by_index(create_entity(phi_a0, entity->position.x, entity->position.y, entity->position.z,
                                     entity->rotation.y, 0x80000000));
    entityTemp->alpha = entity->alpha;
    if (((entity->flags & 1) != 0) || ((u32) entity->alpha < 0xFF)) {
        entityTemp->alpha = 0x20;
    }

    if ((entity->flags & 0x40000) != 0) {
        entityTemp->flags |= 0x40000;
    }
    temp = entityTemp->dataBuf;
    temp->unk_12 = temp_s2;

    if ((entity->flags & 4) != 0) {
        entityTemp->flags |= 4;
    }

    entity->flags &= ~0x100;
    shadow = get_shadow_by_index(entity->shadowIndex);
    shadow->flags |= 0x10000001;
    shadow = get_shadow_by_index(entityTemp->shadowIndex);
    shadow->flags |= 0x400000;
}

void func_802E4484(Entity* entity) {
    Shadow* shadow;

    entity->flags = (entity->flags | 1) & ~0x100;
    shadow = get_shadow_by_index(entity->shadowIndex);
    shadow->flags |= 0x10000001;
}

s32 func_802E44CC(Entity* entity) {
    if (entity->boundScript != NULL) {
        entity->flags |= 0x1000000;
        return TRUE;
    }
    return FALSE;
}

// TODO: new file here?
void func_802E44F8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    disable_player_input();
    playerStatus->currentSpeed = 0.0f;
    playerStatus->flags |= 0x800000;
    set_action_state(8);
    gravity_use_fall_params();
}

void func_802E4540(void) {
    enable_player_input();
}

void func_802E455C(s32 entityIndex) {
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

void func_802E464C(Entity* entity) {
    struct802E3650* temp;

    entity_init_Hammer23Block_normal(entity);
    temp = entity->dataBuf;
    temp->unk_10 = D_8015C7D2;
    temp->unk_0A = 0xFFFF;
    entity->unk_3C = func_802E455C;
}

void func_802E4694(Entity* entity) {
    func_802E464C(entity);
    entity->alpha = 0;
}

void func_802E46BC(Entity* entity) {
    AnimatedMesh* animMesh;

    entity_init_Hammer23Block_normal(entity);
    entity->unk_3C = func_802E455C;
    animMesh = get_anim_mesh(entity->virtualModelIndex);
    animMesh->renderMode = 0x11;
    animMesh->flags |= 0x10000;
}
