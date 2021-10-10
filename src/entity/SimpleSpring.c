#include "common.h"

extern void* D_8015A578;

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_ScriptSpring_idle);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_SimpleSpring_idle);

/*void entity_SimpleSpring_idle(Entity* ent) {
    int new_var;
    s32 *new_var2;
    s32 isRiding;
    s32 isColliding;
    new_var2 = ent->dataBuf;
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
}*/

void entity_SimpleSpring_set_jump_params(Entity* ent) {
    s32* data;
    data = ent->dataBuf;
    set_action_state(6);
    gPlayerStatus.gravityIntegrator[1] = 0;
    gPlayerStatus.gravityIntegrator[0] = 15.0f;
    gPlayerStatus.gravityIntegrator[2] = (f32)*data;
    gPlayerStatus.gravityIntegrator[3] = ent->position.y;
}

void entity_SimpleSpring_enable_player_input(Entity* ent) {
    enable_player_input();
}

void entity_ScriptSpring_init(void) {
}

void entity_SimpleSpring_init(Entity* ent) {
    ent->dataBuf[0] = *D_8015C7D0;
}

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_setupGfx);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_set_ispy_notification);

void entity_HiddenPanel_hide(Entity* ent) {
    ent->flags = (ent->flags & ~0x20) | 1;
}

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_idle);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_flip_over);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_is_item_on_top);

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_init);

/*
void entity_HiddenPanel_init(Entity* ent) {
    float sp58[4];
    float sp18[4];
    s32* temp_s1;
    s32 temp_a1;
    s32 temp_v1;
    s32* data;
    s32 phi_v0;

    data = ent->dataBuf;
    mem_clear(&D_8015A578, 0x10);
    ent->unk3C = &entity_HiddenPanel_setupGfx;
    data->unk6 = 0xFFFF;
    data->unk24 = (?32) ent->unk4C;
    data->unk74 = (u16) D_8015C7D0.unk2;
    temp_v1 = D_8015C7D0[1];
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
*/
