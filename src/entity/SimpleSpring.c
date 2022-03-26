#include "common.h"

extern void* D_8015A578;

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_ScriptSpring_idle);

#ifdef NON_EQUIVALENT

void entity_SimpleSpring_idle(Entity* ent) {
    int new_var;
    s32 *new_var2;
    s32 isRiding;
    s32 isColliding;

    new_var2 = ent->dataBuf.unk;
    new_var = gPlayerStatus.actionState != ACTION_STATE_RIDE && (ent->collisionFlags & 1) != 0;
    if (new_var) {
        if ((*new_var2) >= 0x46) {
            gPlayerStatus.unk_C5 = 5;
        }
        play_model_animation(ent->virtualModelIndex, 0x1E4);
        entity_start_script(ent);
        exec_entity_commandlist(ent);
        sfx_play_sound_at_position(0x2086, 0, ent->position.x, ent->position.y, ent->position.z);
        disable_player_input();
        gPlayerStatus.currentSpeed = 0;
    }
}

#else

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_SimpleSpring_idle);

#endif

void entity_SimpleSpring_set_jump_params(Entity* ent) {
    SimpleSpringData* data = ent->dataBuf.simpleSpring;

    set_action_state(ACTION_STATE_LAUNCH);
    gPlayerStatus.gravityIntegrator[1] = 0;
    gPlayerStatus.gravityIntegrator[0] = 15.0f;
    gPlayerStatus.gravityIntegrator[2] = (f32)data->launchVelocity;
    gPlayerStatus.gravityIntegrator[3] = ent->position.y;
}

void entity_SimpleSpring_enable_player_input(Entity* ent) {
    enable_player_input();
}

void entity_ScriptSpring_init(void) {
}

void entity_SimpleSpring_init(Entity* ent) {
    ent->dataBuf.simpleSpring->launchVelocity = *CreateEntityVarArgBuffer;
}

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_setupGfx);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_set_ispy_notification);

void entity_HiddenPanel_hide(Entity* ent) {
    ent->flags = (ent->flags & ~0x20) | 1;
}

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_idle);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_flip_over);

#ifdef NON_EQUIVALENT

s32 entity_HiddenPanel_is_item_on_top(Entity* entity) {
    ItemEntity* temp_v0;
    s32 entityIndex;
    s32 *args;
    s32 phi_v0;

    args = entity->dataBuf.unk;
    entityIndex = args[5];
    phi_v0 = 0;
    if ((entityIndex >= 0) &&
    ((temp_v0 = get_item_entity(entityIndex), (temp_v0 == 0))
    || (((temp_v0->flags & 0x10) != 0) && (fabs((f64) (entity->position.x - (f32) args[6])) <= 34.0)
    && (phi_v0 = 1, !(fabs((f64) (entity->position.y - (f32)args[8])) <= 34.0))))) {

    }
    return phi_v0;
}

#else

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_is_item_on_top);

#endif

#ifdef NON_EQUIVALENT

void entity_HiddenPanel_init(Entity* ent) {
    float sp58[4];
    float sp18[4];
    s32* temp_s1;
    s32 temp_a1;
    s32 temp_v1;
    s32* data;
    s32 phi_v0;

    data = ent->dataBuf.unk;
    mem_clear(&D_8015A578, 0x10);
    ent->unk3C = &entity_HiddenPanel_setupGfx;
    data->unk6 = 0xFFFF;
    data->unk24 = (?32) ent->unk4C;
    data->unk74 = (u16) CreateEntityVarArgBuffer.unk2;
    temp_v1 = CreateEntityVarArgBuffer[1];
    data->unk3 = 1;
    data->unk14 = -1;
    data->unk10 = temp_v1;
    if (temp_v1 == 0) {
        data->unk10 = 0x15C;
    }
    temp_s1 = data + 0x34;
    guMtxIdentF(temp_s1);
    guTranslateF(&sp18, ent->position.x, ent->position.y, ent->position.z);
    guRotateF(&sp58, ent->rotation.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp58, &sp18, &sp18);
    guRotateF(&sp58, ent->rotation.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(&sp58, &sp18, &sp18);
    guRotateF(&sp58, ent->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp58, &sp18, &sp18);
    guScaleF(&sp58, ent->scale.x, ent->scale.y, ent->scale.z);
    guMtxCatF(&sp58, &sp18, temp_s1);
    if ((D_8015A578.unk1 & 1) != 0) {
        entity_set_render_script(ent, &D_802EAAE0);
        phi_v0 = 0xA0001B0 & 0xFFFF;
    } else {
        phi_v0 = 0xA000180 & 0xFFFF;
    }
    temp_a1 = ent->vertexData + phi_v0;
    data->unk78 = temp_a1;
    mdl_project_tex_coords(data->unk74, temp_a1, temp_s2 + 0x34, ent->unk44);
    D_8015A578.unk1 = (u8) (D_8015A578.unk1 + 1);
}

#else

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_init);

#endif
