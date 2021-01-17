#include "common.h"

f32 func_802E5670(struct802E4B10* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk_D0 - arg1;
    if (arg0->unk_D0 - arg1 < 0) {
        temp_v0 += 0x14;
    }
    return arg0->unk_D4[temp_v0];
}

void func_802E5690(s32 entityIndex) {
    s16 temp_a0;
    Entity* someEntity;
    Entity* someOtherEntity;
    struct802E3650* temp;

    someEntity = get_entity_by_index(entityIndex);
    temp = someEntity->dataBuf;
    if (temp->unk_12 >= 0) {
        Entity* someOtherEntity = get_entity_by_index(temp->unk_12);
        struct802E4B10* temp2 = someOtherEntity->dataBuf;
        temp2->unk_0A = 1;
    }
}

s32 func_802E56D0(Entity* entity) {
    return func_802E3650(entity);
}

extern StaticEntityData D_802EA934;

void func_802E56EC(Entity* entity) {
    s16 entityIndex;
    u8 temp_v0_2;
    struct802E3650* temp_s0;

    temp_s0 = entity->dataBuf;
    if (temp_s0->unk_0A != 0xFFFF) {
        if (get_global_flag(temp_s0->unk_0A) == 0) {
            Entity* someEntity;
            struct802E3650* temp2;

            entityIndex = create_entity(&D_802EA934, entity->position.x, entity->position.y, entity->position.z, 0.0f, 0x80000000);
            temp_s0->unk_12 = entityIndex;
            someEntity = get_entity_by_index(entityIndex);
            temp2 = someEntity->dataBuf;
            temp2->unk_00 = entity->listIndex;
        }
    }
}

void func_802E578C(Entity* entity) {
    struct802E3650* temp_s1;

    temp_s1 = entity->dataBuf;
    entity_init_Hammer23Block_normal(entity);
    entity->rotation.y += 180.0f;
    temp_s1->unk_0A = 0xFFFF;
    temp_s1->unk_12 = -1;
}

void func_802E57E4(Entity* entity) {
    func_802E578C(entity);
}

void func_802E5800(Entity* entity) {
    func_802E578C(entity);
}

void func_802E581C(Entity* entity) {
    struct802E3650* temp = entity->dataBuf;
    Entity* temp_v0 = get_entity_by_index(temp->unk_00);

    entity->position.x = temp_v0->position.x;
    entity->position.y = temp_v0->position.y + 14.0f;
    entity->position.z = temp_v0->position.z;
}

// display list func
INCLUDE_ASM(s32, "code_106EF0", func_802E586C);

void func_802E5E50(Entity* entity) {
    f32 clampedAngle;
    struct802E4B10* temp_s0 = entity->dataBuf;

    func_802E581C(entity);
    if (temp_s0->unk_0A != 0) {
        entity->unk_3C = NULL;
    }

    clampedAngle = clamp_angle(entity->rotation.y + 3.0);
    entity->rotation.y = clampedAngle;
    temp_s0->unk_D4[temp_s0->unk_D0] = clampedAngle;
    if (++temp_s0->unk_D0 >= 0x15) {
        temp_s0->unk_D0 = 0;
    }

    if (temp_s0->unk_0A == 0) {
        if (D_8009A650[0] == 0) {
            if (--temp_s0->unk_02 <= 0) {
                temp_s0->unk_02 = 0x32;
                func_80070550(3, entity->position.x, entity->position.y, entity->position.z, 22.0f, 8.0f, 4, 0x14);
            }
        }
    }
}

void func_802E5F50(Entity* entity) {
    struct802E3650* temp;

    temp = entity->dataBuf;
    temp->unk_128 = &D_0A000328;
    temp->unk_12C = &D_0A000380;
    entity->unk_3C = func_802E586C;
}

void func_802E5F7C(Entity* entity) {
    struct802E3650* temp;

    temp = entity->dataBuf;
    temp->unk_128 = &D_0A000800;
    temp->unk_12C = &D_0A000750;
    entity->unk_3C = func_802E586C;
}
