#include "common.h"

extern StaticEntityData D_802EA934;

f32 entity_SuperBlockContent_get_previous_yaw(struct802E4B10* arg0, s32 arg1) {
    s32 idx = arg0->unk_D0 - arg1;

    if (idx < 0) {
        idx += 20;
    }
    return arg0->unk_D4[idx];
}

void entity_upgrade_block_hide_content(s32 entityIndex) {
    Entity* someEntity = get_entity_by_index(entityIndex);
    struct802E3650* temp = someEntity->dataBuf;

    if (temp->unk_12 >= 0) {
        Entity* someOtherEntity = get_entity_by_index(temp->unk_12);
        struct802E4B10* temp2 = someOtherEntity->dataBuf;
        temp2->unk_0A = 1;
    }
}

s32 entity_upgrade_block_idle(Entity* entity) {
    return entity_base_block_idle(entity);
}

void entity_upgrade_block_check_if_inactive(Entity* entity) {
    struct802E3650* temp_s0 = entity->dataBuf;

    if (temp_s0->unk_0A != 0xFFFF && !get_global_flag(temp_s0->unk_0A)) {
        Entity* someEntity;
        struct802E3650* temp2;

        temp_s0->unk_12 = create_entity(&D_802EA934, entity->position.x, entity->position.y, entity->position.z, 0.0f,
                                        0x80000000);
        someEntity = get_entity_by_index(temp_s0->unk_12);
        temp2 = someEntity->dataBuf;
        temp2->unk_00 = entity->listIndex;
    }
}

void entity_upgrade_block_init(Entity* entity) {
    struct802E3650* temp_s1 = entity->dataBuf;

    entity_base_block_init(entity);
    entity->rotation.y += 180.0f;
    temp_s1->unk_0A = 0xFFFF;
    temp_s1->unk_12 = -1;
}

void entity_SuperBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_UltraBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_SuperBlock_HitEffect_attach_to_parent(Entity* entity) {
    struct802E3650* temp = entity->dataBuf;
    Entity* temp_v0 = get_entity_by_index(temp->unk_00);

    entity->position.x = temp_v0->position.x;
    entity->position.y = temp_v0->position.y + 14.0f;
    entity->position.z = temp_v0->position.z;
}

// display list func
INCLUDE_ASM(s32, "106EF0", entity_SuperBlock_HitEffect_setupGfx);

void entity_SuperBlock_HitEffect_idle(Entity* entity) {
    struct802E4B10* temp_s0 = entity->dataBuf;

    entity_SuperBlock_HitEffect_attach_to_parent(entity);
    if (temp_s0->unk_0A != 0) {
        entity->renderSetupFunc = NULL;
    }

    entity->rotation.y = clamp_angle(entity->rotation.y + 3.0);
    temp_s0->unk_D4[temp_s0->unk_D0] = entity->rotation.y;

    temp_s0->unk_D0++;
    if (temp_s0->unk_D0 > 20) {
        temp_s0->unk_D0 = 0;
    }

    if (temp_s0->unk_0A == 0 && gOverrideFlags == 0) {
        if (--temp_s0->unk_02 <= 0) {
            temp_s0->unk_02 = 50;
            playFX_22(3, entity->position.x, entity->position.y, entity->position.z, 22.0f, 8.0f, 4, 20);
        }
    }
}

void entity_init_SuperBlock_HitEffect1(Entity* entity) {
    struct802E3650* temp = entity->dataBuf;

    temp->unk_128 = &D_0A000328;
    temp->unk_12C = &D_0A000380;
    entity->renderSetupFunc = entity_SuperBlock_HitEffect_setupGfx;
}

void entity_init_SuperBlock_HitEffect2(Entity* entity) {
    struct802E3650* temp = entity->dataBuf;

    temp->unk_128 = &D_0A000800;
    temp->unk_12C = &D_0A000750;
    entity->renderSetupFunc = entity_SuperBlock_HitEffect_setupGfx;
}
