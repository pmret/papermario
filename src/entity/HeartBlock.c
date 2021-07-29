#include "common.h"

extern u32* D_802EA728;
extern u32* D_802EA760;
extern StaticEntityData D_802EA7BC;
extern UNK_TYPE D_802EB3C0;

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent_get_previous_yaw);

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent__setupGfx);

void entity_HeartBlockContent_setupGfx(s32 entityIndex) {
    entity_HeartBlockContent__setupGfx(entityIndex, &D_0A000808);
}

void entity_HeartBlockContent_set_initial_pos(Entity* entity) {
    struct802E4B10* temp = entity->dataBuf;
    Entity* entityTemp = get_entity_by_index(temp->unk_00);

    entity->position.x = entityTemp->position.x;
    entity->position.y = entityTemp->position.y + 14.0f;
    entity->position.z = entityTemp->position.z;
}

void entity_HeartBlockContent__reset(Entity* entity) {
    struct802E4B10* temp_s0;
    Entity* someEntity;

    entity->renderSetupFunc = entity_HeartBlockContent_setupGfx;
    entity->alpha = 255;
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

    entity_HeartBlockContent_set_initial_pos(entity);
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent_anim_idle);

void func_802E4DE0(Entity* entity) {
    struct802E4B10* temp = entity->dataBuf;

    temp->unk_01 = 0;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->rotation.z = 0.0f;
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent__anim_heal);

void entity_HeartBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

INCLUDE_ASM(s32, "entity/HeartBlock", entity_HeartBlockContent_anim_beating);

void entity_HeartBlockContent_init(Entity* entity) {
    entity_HeartBlockContent_set_initial_pos(entity);
}

void entity_HeartBlockContent_reset(Entity* entity) {
    entity_HeartBlockContent__reset(entity);
    entity_set_render_script(entity, &D_802EA728);
}

void entity_HeartBlockContent_idle(Entity* entity) {
    entity_HeartBlockContent_anim_idle(entity, 0);
    entity_HeartBlockContent_anim_beating(entity);
}

void entity_HeartBlockContent_anim_heal(Entity* entity) {
    entity_HeartBlockContent__anim_heal(entity, 0);
}

void entity_HeartBlock_change_render_script(Entity* entity) {
    entity_set_render_script(entity, &D_802EA760);
}

void entity_HeartBlock_show_tutorial_message(Entity* entity) {
    if ((!gPlayerData.partners[1].enabled) && get_global_flag(SI_SAVE_FLAG(96)) == 0) {
        UNK_TYPE* ptr = &D_802EB3C0;
        *ptr = 0;
        msg_get_printer_for_string(0x1D0001, ptr);
        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
        gOverrideFlags |= 0x40;
        disable_player_input();
        set_global_flag(SI_SAVE_FLAG(96));
        return;
    }
    exec_entity_commandlist(entity);
}

void entity_HeartBlock_wait_for_close_tutorial(Entity* entity) {
    if (D_802EB3C0) {
        exec_entity_commandlist(entity);
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        gOverrideFlags &= ~0x40;
        enable_player_input();
    }
}

s8 entity_HeartBlock_create_child_entity(Entity* entity, StaticEntityData* data) {
    s32 temp_s2 = D_8015C7D0[0];
    Entity* someEntity;
    struct802E4B10* temp_v1;

    entity_base_block_init(entity);
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

void entity_HeartBlock_init(Entity* entity) {
    entity_HeartBlock_create_child_entity(entity, &D_802EA7BC);
}
