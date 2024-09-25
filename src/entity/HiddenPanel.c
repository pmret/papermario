#include "common.h"
#include "ld_addrs.h"
#include "entity.h"

s32 entity_HiddenPanel_is_item_on_top(Entity*);
void entity_HiddenPanel_flip_over(Entity*);

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f destMtx, void* destVertices);
s32 npc_find_standing_on_entity(s32 entityIndex);

extern s32 ERS_AltHiddenPanel[];

extern Gfx Gfx_HiddenPanel_RenderTop[];
extern Gfx Gfx_AltHiddenPanel_RenderTop[];
extern Gfx Gfx_HiddenPanel_RenderHole[];
extern Gfx Gfx_HiddenPanel_Render[];
extern Gfx Gfx_HiddenPanel_Render2[];

void entity_HiddenPanel_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    Matrix4f rotMtx;
    Matrix4f tempMtx;

    if (entity->pos.y != data->initialY) {
        guMtxIdentF(rotMtx);
        guTranslateF(tempMtx, entity->pos.x, data->initialY + 1.0f, entity->pos.z);
        guMtxCatF(tempMtx, rotMtx, tempMtx);
        guMtxF2L(tempMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, ENTITY_ADDR(entity, Gfx*, Gfx_HiddenPanel_RenderHole));
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
    mdl_project_tex_coords(data->modelID, data->renderDList, data->entityMatrix, entity->gfxBaseAddr);
    mdl_draw_hidden_panel_surface(&gMainGfxPos, data->modelID);
}

void entity_HiddenPanel_set_ispy_notification(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (is_ability_active(ABILITY_I_SPY) && !get_global_flag(data->pickupVar) && !gCurrentHiddenPanels.activateISpy) {
        gCurrentHiddenPanels.activateISpy = TRUE;
    }
}

void entity_HiddenPanel_hide(Entity* entity) {
    entity->flags &= ~ENTITY_FLAG_DISABLE_COLLISION;
    entity->flags |= ENTITY_FLAG_HIDDEN;
}

void entity_HiddenPanel_idle(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    s32 distToPlayer;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (!data->unk_04) {
            data->unk_04 = TRUE;
            func_800EF3D4(1);
        }
    } else {
        data->unk_04 = FALSE;
    }

    data->standingNpcIndex = -1;
    data->npcFlags = 0;

    if (gCurrentHiddenPanels.tryFlipTrigger && fabs(gCurrentHiddenPanels.flipTriggerPosY - entity->pos.y) <= 10.0) {
        data->state = 10;
        distToPlayer = get_xz_dist_to_player(entity->pos.x, entity->pos.z);
        if (distToPlayer <= 100) {
            if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
                data->riseVel = 0.5f;
                exec_entity_commandlist(entity);
            } else if (entity_HiddenPanel_is_item_on_top(entity)) {
                data->riseVel = 0.5f;
                exec_entity_commandlist(entity);
            } else {
                s32 npcIndex = npc_find_standing_on_entity(entity->listIndex);
                if (npcIndex >= 0) {
                    Npc* npc = get_npc_by_index(npcIndex);
                    dist2D(entity->pos.x, entity->pos.z, npc->pos.x, npc->pos.z);
                    data->standingNpcIndex = npcIndex;
                    data->npcFlags = npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_FLYING);
                    npc->flags &= ~NPC_FLAG_FLYING;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    data->riseVel = 0.5f;
                    exec_entity_commandlist(entity);
                } else {
                    entity->flags |= ENTITY_FLAG_DISABLE_COLLISION;
                    if (distToPlayer > 60) {
                        data->riseVel = 0.5f;
                        exec_entity_commandlist(entity);
                    } else {
                        data->state = 0;
                        data->riseVel = 10.0f;
                        exec_entity_commandlist(entity);
                    }
                }
            }
        }
    }
}

void entity_HiddenPanel_flip_over(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    f32 yaw;
    f32 rotAngle;
    s32 flipAxis;

    yaw = clamp_angle(gCameras[CAM_DEFAULT].curYaw + 45.0f);
    if (yaw < 90.0f || yaw >= 180.0f && yaw < 270.0f) {
        rotAngle = entity->rot.z;
        flipAxis = 1;
    } else {
        rotAngle = entity->rot.x;
        flipAxis = 0;
    }

    switch (data->state) {
        case 0:
            sfx_play_sound(SOUND_FLIP_PANEL);
            data->state = 1;
            data->unk_02 = TRUE;
            data->riseInterpPhase = 90.0f;
            data->rotSpeed = 65.0f;
            set_time_freeze_mode(TIME_FREEZE_PARTIAL);
            disable_player_static_collisions();
            gPlayerStatusPtr->animFlags |= PA_FLAG_OPENED_HIDDEN_PANEL;
            if (data->needSpawnItem) {
                data->needSpawnItem = FALSE;
                data->spawnedItemIndex = make_item_entity_nodelay(data->itemID,
                    entity->pos.x, entity->pos.y + 2.0, entity->pos.z,
                    ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, data->pickupVar);
            }
            entity->flags &= ~ENTITY_FLAG_HIDDEN;
            break;
        case 1:
            entity->pos.y += data->riseVel * sin_rad(DEG_TO_RAD(data->riseInterpPhase));
            if (entity->pos.y <= data->initialY) {
                entity->pos.y = data->initialY;
                entity->rot.x = 0.0f;
                entity->rot.z = 0.0f;
                rotAngle = 0.0f;
                data->timer = 10;
            }

            data->riseInterpPhase += 10.0f;
            if (data->riseInterpPhase >= 180.0f) {
                data->riseInterpPhase = 180.0f;
                data->timer = 7;
                data->state++;
            }

            if (data->riseInterpPhase > 110.0f) {
                rotAngle += data->rotSpeed;
                if (rotAngle >= 360.0f) {
                    rotAngle -= 360.0f;
                }
            }
            break;
        case 2:
            data->rotSpeed -= 2.0f;
            if (data->rotSpeed <= 0.0f) {
                data->rotSpeed = 0.0f;
            }

            rotAngle += data->rotSpeed;
            if (rotAngle >= 360.0f) {
                rotAngle -= 360.0f;
            }

            if (--data->timer <= 0) {
                data->state++;
            }
            break;
        case 3:
            data->rotSpeed -= 5.0f;
            if (data->rotSpeed <= 0.0f) {
                data->rotSpeed = 0.0f;
            }

            rotAngle += data->rotSpeed;
            if (rotAngle >= 360.0f) {
                rotAngle = 360.0f;
            }

            entity->pos.y += data->riseVel * sin_rad(DEG_TO_RAD(data->riseInterpPhase));
            data->riseInterpPhase += 10.0f;
            if (data->riseInterpPhase > 270.0f) {
                data->riseInterpPhase = 270.0f;
            }

            if (entity->pos.y <= data->initialY) {
                data->state++;

                entity->pos.y = data->initialY;
                entity->rot.x = 0.0f;
                entity->rot.z = 0.0f;
                rotAngle = 0.0f;
                data->timer = 10;
                exec_ShakeCamX(CAM_DEFAULT, CAM_SHAKE_DECAYING_VERTICAL, 1, 0.2f);
                sfx_play_sound(SOUND_CLOSE_PANEL);
            }
            break;
        case 4:
            data->state++;
            break;
        case 5:
            data->state = 11;
            entity->pos.y += 2.0f;
            break;
        case 10:
            entity->flags &= ~ENTITY_FLAG_HIDDEN;
            data->unk_02 = FALSE;
            data->state++;
            entity->pos.y += 6.0f;
            break;
        case 11:
            entity->pos.y -= 1.0f;
            if (entity->pos.y <= data->initialY) {
                entity->pos.y = data->initialY;
                data->timer = 1;
                data->state++;
                entity->flags |= ENTITY_FLAG_HIDDEN | ENTITY_FLAG_DISABLE_COLLISION;
                if (data->unk_02) {
                    enable_player_static_collisions();
                }
            }
            break;
        case 12:
            data->timer--;
            if (data->timer < 0) {
                data->state = 0;
                exec_entity_commandlist(entity);
                if (data->unk_02) {
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    gPlayerStatusPtr->animFlags &= ~PA_FLAG_OPENED_HIDDEN_PANEL;
                }
                entity->flags &= ~ENTITY_FLAG_DISABLE_COLLISION;
                if (data->standingNpcIndex >= 0) {
                    Npc* npc = get_npc_by_index(data->standingNpcIndex);
                    npc->flags &= ~(NPC_FLAG_GRAVITY | NPC_FLAG_FLYING);
                    npc->flags |= data->npcFlags;
                }
            }
            break;
    }

    if (flipAxis == 0) {
        entity->rot.x = rotAngle;
    } else {
        entity->rot.z = rotAngle;
    }

    if (data->spawnedItemIndex >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->spawnedItemIndex);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAG_10) {
                data->spawnedItemPos.x = itemEntity->pos.x;
                data->spawnedItemPos.y = itemEntity->pos.y;
                data->spawnedItemPos.z = itemEntity->pos.z;
            } else {
                data->spawnedItemPos.x = 0x8000;
                data->spawnedItemPos.y = 0x8000;
                data->spawnedItemPos.z = 0x8000;
            }
        } else {
            data->spawnedItemIndex = -1;
        }
    }
}

s32 entity_HiddenPanel_is_item_on_top(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (data->spawnedItemIndex >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->spawnedItemIndex);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAG_10) {
                if (fabs(entity->pos.x - data->spawnedItemPos.x) <= 34.0)  {
                    if (fabs(entity->pos.z - data->spawnedItemPos.z) <= 34.0) {
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

    mem_clear(&gCurrentHiddenPanels, sizeof(gCurrentHiddenPanels));
    entity->renderSetupFunc = entity_HiddenPanel_setupGfx;
    data->pickupVar = 0xFFFF;
    data->initialY = entity->pos.y;
    data->modelID = CreateEntityVarArgBuffer[0];
    data->itemID = CreateEntityVarArgBuffer[1];
    data->needSpawnItem = TRUE;
    data->spawnedItemIndex = -1;

    if (data->itemID == 0) {
        data->itemID = ITEM_STAR_PIECE;
    }

    guMtxIdentF(data->entityMatrix);
    guTranslateF(sp18, entity->pos.x, entity->pos.y, entity->pos.z);
    guRotateF(sp58, entity->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, entity->scale.x, entity->scale.y, entity->scale.z);
    guMtxCatF(sp58, sp18, data->entityMatrix);

    if (gCurrentHiddenPanels.panelsCount & 1) {
        dlist = Gfx_AltHiddenPanel_RenderTop;
        entity_set_render_script(entity, &ERS_AltHiddenPanel);
    } else {
        dlist = Gfx_HiddenPanel_RenderTop;
    }
    data->renderDList = ENTITY_ADDR(entity, Gfx*, dlist);

    mdl_project_tex_coords(data->modelID, data->renderDList, data->entityMatrix, entity->gfxBaseAddr);
    gCurrentHiddenPanels.panelsCount++;
}

EntityScript Entity_HiddenPanel_Script = {
    es_Call(entity_HiddenPanel_set_ispy_notification)
    es_Label(1)
        es_Call(entity_HiddenPanel_hide)
        es_SetCallback(entity_HiddenPanel_idle, 0)
        es_SetCallback(entity_HiddenPanel_flip_over, 0)
    es_Goto(1)
    es_End
};

EntityModelScript ERS_HiddenPanel = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_SetFlags(ENTITY_MODEL_FLAG_10000)
    ems_Draw(Gfx_HiddenPanel_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript ERS_AltHiddenPanel = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_SetFlags(ENTITY_MODEL_FLAG_10000)
    ems_Draw(Gfx_HiddenPanel_Render2, 60)
    ems_Restart
    ems_End
};

EntityBlueprint Entity_HiddenPanel = {
    .flags = ENTITY_FLAG_HIDDEN,
    .typeDataSize = sizeof(HiddenPanelData),
    .renderCommandList = ERS_HiddenPanel,
    .modelAnimationNodes = 0,
    .fpInit = entity_HiddenPanel_init,
    .updateEntityScript = Entity_HiddenPanel_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(HiddenPanel) },
    .entityType = ENTITY_TYPE_HIDDEN_PANEL,
    .aabbSize = { 60, 0, 60 }
};

//TODO remove this
static const f32 rodata_alignment[] = {0.0f, 0.0f};
