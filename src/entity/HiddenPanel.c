#include "common.h"
#include "ld_addrs.h"

s32 entity_HiddenPanel_is_item_on_top(Entity*);
void entity_HiddenPanel_flip_over(Entity*);
void entity_HiddenPanel_setupGfx(s32 entityIndex);

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f* destMtx, Vtx* destVertices);
s32 npc_find_standing_on_entity(s32 entityIndex);

extern s32 D_802EAAE0[];

extern Gfx D_0A000180[];
extern Gfx D_0A0001B0[];

INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_setupGfx);

void entity_HiddenPanel_set_ispy_notification(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (is_ability_active(ABILITY_I_SPY) && get_global_flag(data->unk_06) == 0 && D_8015A578.unk_02 == 0) {
        D_8015A578.unk_02 = 1;
    }
}

void entity_HiddenPanel_hide(Entity* entity) {
    entity->flags &= ~ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
    entity->flags |= ENTITY_FLAGS_HIDDEN;
}

void entity_HiddenPanel_idle(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    s32 s0;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (data->unk_04 == 0) {
            data->unk_04 = 1;
            func_800EF3D4(1);
        }
    } else {
        data->unk_04 = 0;
    }

    data->unk_08 = -1;
    data->unk_0C = 0;

    if (D_8015A578.unk_00 != 0 && fabs(D_8015A578.unk_08 - entity->position.y) <= 10.0) {
        data->unk_00 = 10;
        s0 = get_xz_dist_to_player(entity->position.x, entity->position.z);
        if (s0 <= 100) {
            if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
                data->unk_28 = 0.5f;
                exec_entity_commandlist(entity);
            } else if (entity_HiddenPanel_is_item_on_top(entity)) {
                data->unk_28 = 0.5f;
                exec_entity_commandlist(entity);
            } else {
                s32 npcIndex = npc_find_standing_on_entity(entity->listIndex);
                if (npcIndex >= 0) {
                    Npc* npc = get_npc_by_index(npcIndex);
                    dist2D(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
                    data->unk_08 = npcIndex;
                    data->unk_0C = npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_ENABLE_HIT_SCRIPT);
                    npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    data->unk_28 = 0.5f;
                    exec_entity_commandlist(entity);
                } else {
                    entity->flags |= ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
                    if (s0 > 60) {
                        data->unk_28 = 0.5f;
                        exec_entity_commandlist(entity);
                    } else {
                        data->unk_00 = 0;
                        data->unk_28 = 10.0f;
                        exec_entity_commandlist(entity);
                    }

                }
            }
        }
    }

}

//INCLUDE_ASM(s32, "entity/SimpleSpring", entity_HiddenPanel_flip_over);
void entity_HiddenPanel_flip_over(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    f32 angle;
    f32 f20;
    s32 s2;

    angle = clamp_angle(gCameras[CAM_DEFAULT].currentYaw + 45.0f);
    if (angle < 90.0f || angle >= 180.0f && angle < 270.0f) {
        f20 = entity->rotation.z;
        s2 = 1;
    } else {
        f20 = entity->rotation.x;
        s2 = 0;
    }

    switch (data->unk_00) {
        case 0:
            sfx_play_sound(SOUND_20AB);
            data->unk_00 = 1;
            data->unk_02 = 1;
            data->unk_2C = 90.0f;
            data->unk_30 = 65.0f;
            set_time_freeze_mode(TIME_FREEZE_PARTIAL);
            disable_player_static_collisions();
            gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_800;
            if (data->unk_03) {
                data->unk_03 = FALSE;
                data->unk_14 = make_item_entity_nodelay(data->unk_10, entity->position.x, entity->position.y + 2.0, entity->position.z, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, data->unk_06);
            }
            entity->flags &= ~ENTITY_FLAGS_HIDDEN;
            break;
        case 1:
            entity->position.y += data->unk_28 * sin_rad(data->unk_2C * TAU / 360.0f);
            if (entity->position.y <= data->unk_24) {
                entity->position.y = data->unk_24;
                entity->rotation.x = 0.0f;
                entity->rotation.z = 0.0f;
                f20 = 0.0f;
                data->unk_01 = 10;
            }

            data->unk_2C += 10.0f;
            if (data->unk_2C >= 180.0f) {
                data->unk_2C = 180.0f;
                data->unk_01 = 7;
                data->unk_00++;
            }

            if (data->unk_2C > 110.0f) {
                f20 += data->unk_30;
                if (f20 >= 360.0f) {
                    f20 -= 360.0f;
                }
            }
            break;
        case 2:
            data->unk_30 -= 2.0f;
            if (data->unk_30 <= 0.0f) {
                data->unk_30 = 0.0f;
            }

            f20 += data->unk_30;
            if (f20 >= 360.0f) {
                f20 -= 360.0f;
            }

            if (--data->unk_01 <= 0) {
                data->unk_00++;
            }
            break;
        case 3:
            data->unk_30 -= 5.0f;
            if (data->unk_30 <= 0.0f) {
                data->unk_30 = 0.0f;
            }

            f20 += data->unk_30;
            if (f20 >= 360.0f) {
                f20 = 360.0f;
            }

            entity->position.y += data->unk_28 * sin_rad(data->unk_2C * TAU / 360.0f);
            data->unk_2C += 10.0f;
            if (data->unk_2C > 270.0f) {
                data->unk_2C = 270.0f;
            }

            if (entity->position.y <= data->unk_24) {
                data->unk_00++;

                entity->position.y = data->unk_24;
                entity->rotation.x = 0.0f;
                entity->rotation.z = 0.0f;
                f20 = 0.0f;
                data->unk_01 = 10;
                exec_ShakeCamX(CAM_DEFAULT, CAM_SHAKE_DECAYING_VERTICAL, 1, 0.2f);
                sfx_play_sound(SOUND_20AC);
            }
            break;
        case 4:
            data->unk_00++;
            break;
        case 5:
            data->unk_00 = 11;
            entity->position.y += 2.0f;
            break;
        case 10:
            entity->flags &= ~ENTITY_FLAGS_HIDDEN;
            data->unk_02 = 0;
            data->unk_00++;
            entity->position.y += 6.0f;
            break;
        case 11:
            entity->position.y -= 1.0f;
            if (entity->position.y <= data->unk_24) {
                entity->position.y = data->unk_24;
                data->unk_01 = 1;
                data->unk_00++;
                entity->flags |= ENTITY_FLAGS_HIDDEN | ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
                if (data->unk_02 != 0) {
                    enable_player_static_collisions();
                }
            }
            break;
        case 12:
            data->unk_01--;
            if (data->unk_01 < 0) {
                data->unk_00 = 0;
                exec_entity_commandlist(entity);
                if (data->unk_02) {
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    gPlayerStatusPtr->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_800;
                }
                entity->flags &= ~ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX;
                if (data->unk_08 >= 0) {
                    Npc* npc = get_npc_by_index(data->unk_08);
                    npc->flags &= ~(NPC_FLAG_GRAVITY | NPC_FLAG_ENABLE_HIT_SCRIPT);
                    npc->flags |= data->unk_0C;
                }
            }
            break;
    }

    if (s2 == 0) {
        entity->rotation.x = f20;
    } else {
        entity->rotation.z = f20;
    }

    if (data->unk_14 >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->unk_14);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAGS_10) {
                data->unk_18.x = itemEntity->position.x;
                data->unk_18.y = itemEntity->position.y;
                data->unk_18.z = itemEntity->position.z;
            } else {
                data->unk_18.x = 0x8000;
                data->unk_18.y = 0x8000;
                data->unk_18.z = 0x8000;
            }
        } else {
            data->unk_14 = -1;
        }
    }
}
//static f32 rodata_padding[] = {0.0f, 0.0f};

s32 entity_HiddenPanel_is_item_on_top(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (data->unk_14 >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->unk_14);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAGS_10) {
                if (fabs(entity->position.x - data->unk_18.x) <= 34.0)  {
                    if (fabs(entity->position.z - data->unk_18.z) <= 34.0) {
                        return TRUE;
                    }
                }
            }
        }
    }

    return FALSE;
}

void entity_HiddenPanel_init(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* dlist;

    mem_clear(&D_8015A578, sizeof(D_8015A578));
    entity->renderSetupFunc = entity_HiddenPanel_setupGfx;
    data->unk_06 = 0xFFFF;
    data->unk_24 = entity->position.y;
    data->unk_74 = CreateEntityVarArgBuffer[0];
    data->unk_10 = CreateEntityVarArgBuffer[1];
    data->unk_03 = TRUE;
    data->unk_14 = -1;

    if (data->unk_10 == 0) {
        data->unk_10 = 0x15C;
    }

    guMtxIdentF(&data->unk_34);
    guTranslateF(sp18, entity->position.x, entity->position.y, entity->position.z);
    guRotateF(sp58, entity->rotation.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rotation.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, entity->scale.x, entity->scale.y, entity->scale.z);
    guMtxCatF(sp58, sp18, &data->unk_34);

    if (D_8015A578.unk_01 & 1) {
        dlist = D_0A0001B0;
        entity_set_render_script(entity, D_802EAAE0);
    } else {
        dlist = D_0A000180;
    }
    data->unk_78 = (s32*)((s32)entity->vertexData + (u16)dlist);

    mdl_project_tex_coords(data->unk_74, data->unk_78, &data->unk_34, entity->vertexData);
    D_8015A578.unk_01++;
}

s32 D_802EAA80[] = {
    0x00000002, entity_HiddenPanel_set_ispy_notification, 0x00000005, 0x00000001, 0x00000002, entity_HiddenPanel_hide, 0x00000003, 0x00000000, entity_HiddenPanel_idle, 0x00000003, 0x00000000, entity_HiddenPanel_flip_over, 0x00000004, 0x00000001, 0x00000000
};
s32 D_802EAABC[] = {
    0x00000004, 0x00000001, 0x00000005, 0x00010000, 0x00000001, 0x0000003C, 0x0A000280, 0x00000002, 0x00000000
};
s32 D_802EAAE0[] = {
    0x00000004, 0x00000001, 0x00000005, 0x00010000, 0x00000001, 0x0000003C, 0x0A0002A0, 0x00000002, 0x00000000,
};
EntityBlueprint D_802EAB04 = {
    0x0001, 0x007C, D_802EAABC, 0x00000000, entity_HiddenPanel_init, D_802EAA80, 0x00000000, E56BA0_ROM_START, E56BA0_ROM_END, ENTITY_TYPE_HIDDEN_PANEL, { 60, 0, 60}
};
