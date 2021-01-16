#include "common.h"

INCLUDE_ASM(s32, "code_105f90", func_802E4710);

INCLUDE_ASM(s32, "code_105f90", func_802E4730);

void func_802E4AEC(s32 entityIndex) {
    func_802E4730(entityIndex, &D_0A000808);
}

void func_802E4B10(Entity* entity) {
    struct802E4B10* temp = entity->dataBuf;
    Entity* entityTemp = get_entity_by_index(temp->unk_00);

    entity->position.x = entityTemp->position.x;
    entity->position.y = entityTemp->position.y + 14.0f;
    entity->position.z = entityTemp->position.z;
}

void func_802E4B60(Entity* entity) {
    struct802E4B10* temp_s0;
    Entity* someEntity;

    entity->unk_3C = func_802E4AEC;
    entity->alpha = 0xFF;
    temp_s0 = entity->dataBuf;
    entity->flags |= 0x2000;
    someEntity = get_entity_by_index(temp_s0->unk_00);
    if (temp_s0->unk_09 == 0) {
        temp_s0->unk_09 = 1;
        temp_s0->unk_01 = 2;
        entity->scale.x = 1.0f;
    } else {
        temp_s0->unk_01 = 0;
        entity->scale.x = 0.0f;
    }

    temp_s0->unk_0C = 0;
    temp_s0->unk_10 = 0;
    entity->rotation.x = 0.0f;
    entity->rotation.y = 0.0f;
    entity->rotation.z = 0.0f;
    entity->scale.y = entity->scale.x;
    entity->scale.z = entity->scale.x;

    func_802E4B10(entity);
}

INCLUDE_ASM(s32, "code_105f90", func_802E4C10);

void func_802E4DE0(Entity* entity) {
    struct802E4B10* temp = entity->dataBuf;

    temp->unk_01 = 0;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->rotation.z = 0.0f;
}

INCLUDE_ASM(s32, "code_105f90", func_802E4E04);

void func_802E5308(Entity* entity) {
    func_802E3650(entity);
}

INCLUDE_ASM(s32, "code_105f90", func_802E5324);

void func_802E540C(Entity* entity) {
    func_802E4B10(entity);
}

extern UNK_TYPE D_802EA728;

void func_802E5428(Entity* entity) {
    func_802E4B60(entity);
    func_80110BCC(entity, &D_802EA728);
}

void func_802E545C(Entity* entity) {
    func_802E4C10(entity, 0);
    func_802E5324(entity);
}

void func_802E548C(Entity* entity) {
    func_802E4E04(entity, 0);
}

extern UNK_TYPE D_802EA760;

void func_802E54A8(Entity* entity) {
    func_80110BCC(entity, &D_802EA760);
}

extern UNK_TYPE D_802EB3C0;

void func_802E54CC(Entity* entity) {
    if ((gPlayerData.partners[1].enabled == 0) && (get_global_flag(0xF8405BE0) == 0)) {
        UNK_TYPE* ptr = &D_802EB3C0;
        *ptr = 0;
        load_string(0x1D0001, ptr);
        func_80027088(1);
        D_8009A650[0] |= 0x40;
        disable_player_input();
        set_global_flag(0xF8405BE0);
        return;
    }
    func_8010FD68(entity);
}

void func_802E555C(Entity* entity) {
    if (D_802EB3C0) {
        func_8010FD68(entity);
        func_80027088(0);
        D_8009A650[0] &= ~0x40;
        enable_player_input();
    }
}

s8 func_802E55A8(Entity* entity, StaticEntityData* data) {
    s32 temp_s2;
    Entity* someEntity;
    struct802E4B10* temp_v1;
    s8 phi_v0;

    temp_s2 = D_8015C7D0[0];
    entity_init_Hammer23Block_normal(entity);
    someEntity = get_entity_by_index(create_entity(data, entity->position.x, entity->position.y, entity->position.z, 0.0f,
                                     0x80000000));
    temp_v1 = someEntity->dataBuf;
    temp_v1->unk_00 = entity->listIndex;
    if (temp_s2 == 0) {
        temp_v1->unk_0A = 3;
    } else {
        temp_v1->unk_0A = 6;
    }
}

extern StaticEntityData D_802EA7BC;

void func_802E5648(Entity* entity) {
    func_802E55A8(entity, &D_802EA7BC);
}
