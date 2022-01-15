#include "common.h"
#include "effects.h"

extern EntityBlueprint Entity_SuperBlockContent;

void entity_SuperBlockContent_setupGfx();

f32 entity_SuperBlockContent_get_previous_yaw(SuperBlockContentData* data, s32 arg1) {
    s32 idx = data->yawBufferPos - arg1;

    if (idx < 0) {
        idx += 20;
    }
    return data->yawBuffer[idx];
}

void entity_upgrade_block_hide_content(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    BlockEntityData* data = entity->dataBuf;

    if (data->childEntityIndex >= 0) {
        Entity* childEntity = get_entity_by_index(data->childEntityIndex);
        SuperBlockContentData* childEntityData = childEntity->dataBuf;
        childEntityData->unk_0A = 1;
    }
}

s32 entity_upgrade_block_idle(Entity* entity) {
    return entity_base_block_idle(entity);
}

void entity_upgrade_block_check_if_inactive(Entity* entity) {
    BlockEntityData* parentData = entity->dataBuf;

    if (parentData->gameFlagIndex != 0xFFFF && !get_global_flag(parentData->gameFlagIndex)) {
        Entity* childEntity;
        BlockEntityData* childData;

        parentData->childEntityIndex = create_entity(&Entity_SuperBlockContent, entity->position.x, entity->position.y, entity->position.z, 0.0f,
                                        0x80000000);
        childEntity = get_entity_by_index(parentData->childEntityIndex);
        childData = childEntity->dataBuf;
        childData->parentEntityIndex = entity->listIndex;
    }
}

void entity_upgrade_block_init(Entity* entity) {
    BlockEntityData* data = entity->dataBuf;

    entity_base_block_init(entity);
    entity->rotation.y += 180.0f;
    data->gameFlagIndex = 0xFFFF;
    data->childEntityIndex = -1;
}

void entity_SuperBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_UltraBlock_init(Entity* entity) {
    entity_upgrade_block_init(entity);
}

void entity_SuperBlockContent_attach_to_parent(Entity* entity) {
    BlockEntityData* data = entity->dataBuf;
    Entity* childEntity = get_entity_by_index(data->parentEntityIndex);

    entity->position.x = childEntity->position.x;
    entity->position.y = childEntity->position.y + 14.0f;
    entity->position.z = childEntity->position.z;
}

// display list func
INCLUDE_ASM(s32, "entity/SuperBlock", entity_SuperBlockContent_setupGfx);

void entity_SuperBlockContent_idle(Entity* entity) {
    SuperBlockContentData* data = entity->dataBuf;

    entity_SuperBlockContent_attach_to_parent(entity);
    if (data->unk_0A != 0) {
        entity->renderSetupFunc = NULL;
    }

    entity->rotation.y = clamp_angle(entity->rotation.y + 3.0);
    data->yawBuffer[data->yawBufferPos] = entity->rotation.y;

    data->yawBufferPos++;
    if (data->yawBufferPos > ARRAY_COUNT(data->yawBuffer)) {
        data->yawBufferPos = 0;
    }

    if (data->unk_0A == 0 && gOverrideFlags == 0) {
        if (--data->unk_02 <= 0) {
            data->unk_02 = 50;
            playFX_22(3, entity->position.x, entity->position.y, entity->position.z, 22.0f, 8.0f, 4, 20);
        }
    }
}

void entity_init_SuperBlockContent1(Entity* entity) {
    BlockEntityData* data = entity->dataBuf;

    data->unk_128 = &D_0A000328;
    data->unk_12C = &D_0A000380;
    entity->renderSetupFunc = entity_SuperBlockContent_setupGfx;
}

void entity_init_SuperBlockContent2(Entity* entity) {
    BlockEntityData* data = entity->dataBuf;

    data->unk_128 = &D_0A000800;
    data->unk_12C = &D_0A000750;
    entity->renderSetupFunc = entity_SuperBlockContent_setupGfx;
}
