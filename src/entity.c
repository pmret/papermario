#include "common.h"
#include "ld_addrs.h"
#include "entity.h"
#include "model.h"
#include "sprite/player.h"

#ifdef SHIFT
extern Addr WorldEntityHeapBottom;
extern Addr WorldEntityHeapBase;
#define WORLD_ENTITY_HEAP_BOTTOM (s32) WorldEntityHeapBottom
#define WORLD_ENTITY_HEAP_BASE (s32) WorldEntityHeapBase
#define entity_jan_iwa_VRAM (void*) entity_jan_iwa_VRAM
#define entity_sbk_omo_VRAM (void*) entity_sbk_omo_VRAM
#define entity_default_VRAM (void*) entity_default_VRAM
#else
#define WORLD_ENTITY_HEAP_BOTTOM 0x80250000
#define WORLD_ENTITY_HEAP_BASE 0x80267FF0
#define entity_jan_iwa_VRAM (void*) 0x802BAE00
#define entity_sbk_omo_VRAM (void*) 0x802BAE00
#define entity_default_VRAM (void*) 0x802BAE00
#endif

s32 D_8014AFB0 = 255;

SHIFT_BSS s32 CreateEntityVarArgBuffer[4];
SHIFT_BSS HiddenPanelsData gCurrentHiddenPanels;
SHIFT_BSS s32 gEntityHideMode;

SHIFT_BSS s32 D_801516FC;
SHIFT_BSS s32 D_801512BC;
SHIFT_BSS s32 D_80151304;
SHIFT_BSS s32 D_80151344;
SHIFT_BSS s32 entity_numEntities;
SHIFT_BSS s32 gEntityHeapBase;
SHIFT_BSS s32 gLastCreatedEntityIndex;

SHIFT_BSS s32 gEntityHeapBottom;
SHIFT_BSS s32 entity_numShadows;
SHIFT_BSS s32 isAreaSpecificEntityDataLoaded;
SHIFT_BSS s32 entity_updateCounter;

SHIFT_BSS s32 wEntityDataLoadedSize;
SHIFT_BSS s32 bEntityDataLoadedSize;

SHIFT_BSS EntityBlueprint* wEntityBlueprint[30];
SHIFT_BSS EntityBlueprint* bEntityBlueprint[4];

SHIFT_BSS EntityList gWorldEntityList;
SHIFT_BSS EntityList gBattleEntityList;
SHIFT_BSS EntityList* gCurrentEntityListPtr;

SHIFT_BSS ShadowList gWorldShadowList;
SHIFT_BSS ShadowList gBattleShadowList;
SHIFT_BSS ShadowList* gCurrentShadowListPtr;

extern Addr BattleEntityHeapBottom; // todo ???

void update_shadows(void);
s32 step_entity_commandlist(Entity* entity);
void entity_swizzle_anim_pointers(EntityBlueprint* entityData, void* baseAnim, void* baseGfx);
void render_shadows(void);
void update_entity_transform_matrix(Entity* entity);
void update_shadow_transform_matrix(Shadow* shadow);
void update_entity_inverse_rotation_matrix(Entity* entity);
void delete_entity(s32 entityIndex);
void delete_entity_and_unload_data(s32 entityIndex);
void _delete_shadow(s32 shadowIndex);
void reload_world_entity_data(void);
s32 entity_get_collision_flags(Entity* entity);
void entity_free_static_data(EntityBlueprint* data);
s32 create_entity_shadow(Entity* entity, f32 x, f32 y, f32 z);
void update_entity_shadow_position(Entity* entity);

void update_entities(void) {
    s32 i;

    D_801512BC = 0;
    entity_numEntities = 0;
    entity_updateCounter++;

    for (i = 0; i < MAX_ENTITIES; i++) {
        Entity* entity = get_entity_by_index(i);

        if (entity != NULL) {
            entity_numEntities++;

            if (!(entity->flags & ENTITY_FLAG_SKIP_UPDATE)) {
                if (entity->flags & ENTITY_FLAG_BOUND_SCRIPT_DIRTY) {
                    entity->flags &= ~ENTITY_FLAG_BOUND_SCRIPT_DIRTY;
                    if (!(entity->flags & ENTITY_FLAG_8000)) {
                        entity->flags |= ENTITY_FLAG_2000000;
                    }
                    entity->boundScript = start_script(entity->boundScriptBytecode, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
                }

                if (entity->flags & ENTITY_FLAG_2000000) {
                    if (does_script_exist(entity->boundScript->id)) {
                        if (entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                            update_model_animator(entity->virtualModelIndex);
                        } else {
                            exec_entity_model_commandlist(entity->virtualModelIndex);
                        }

                        if (entity->flags & ENTITY_FLAG_ALWAYS_FACE_CAMERA) {
                            entity->rot.y = -gCameras[gCurrentCameraID].curYaw;
                        }

                        if (!(entity->flags & ENTITY_FLAG_SKIP_UPDATE_TRANSFORM_MATRIX)) {
                            update_entity_transform_matrix(entity);
                        }
                        continue;
                    } else {
                        entity->flags &= ~ENTITY_FLAG_2000000;
                    }
                }

                if (entity->collisionTimer == 0) {
                    entity->collisionFlags = entity_get_collision_flags(entity);

                    if (entity->collisionFlags) {
                        EntityCallback handleCollision = entity->blueprint->fpHandleCollision;

                        if (handleCollision != NULL && handleCollision(entity) != 0) {
                            entity->collisionTimer = 10;
                            entity->flags |= ENTITY_FLAG_DETECTED_COLLISION;
                        }
                    }
                } else {
                    entity->collisionTimer--;
                    if (entity->flags & ENTITY_FLAG_CONTINUOUS_COLLISION) {
                        if (entity->collisionTimer == 0) {
                            entity->flags &= ~(ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_CONTINUOUS_COLLISION);
                        } else {
                            entity->flags |= ENTITY_FLAG_DISABLE_COLLISION;
                        }
                    } else if (entity->collisionTimer == 0) {
                        entity->flags &= ~ENTITY_FLAG_DETECTED_COLLISION;
                        entity->flags &= ~ENTITY_FLAG_PARTNER_COLLISION;
                        entity->collisionFlags = 0;
                    }
                }

                if (entity->flags & ENTITY_FLAG_ALWAYS_FACE_CAMERA) {
                    entity->rot.y = -gCameras[gCurrentCameraID].curYaw;
                }

                if (gGameStatusPtr->debugScripts == DEBUG_SCRIPTS_NONE) {
                    if (entity->updateScriptCallback != NULL) {
                        entity->updateScriptCallback(entity);
                    }

                    if (entity->scriptReadPos != NULL) {
                        if (entity->scriptDelay != 0) {
                            entity->scriptDelay--;
                            if (entity->scriptDelay == 0) {
                                while (step_entity_commandlist(entity));
                            }
                        }
                    }
                }

                if (!(entity->flags & ENTITY_FLAG_SKIP_UPDATE_TRANSFORM_MATRIX)) {
                    update_entity_transform_matrix(entity);
                }

                if (!(entity->flags & ENTITY_FLAG_DISABLE_COLLISION)) {
                    update_entity_inverse_rotation_matrix(entity);
                }

                if (entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    update_model_animator(entity->virtualModelIndex);
                } else {
                    exec_entity_model_commandlist(entity->virtualModelIndex);
                }

                if (entity->shadowIndex >= 0) {
                    update_entity_shadow_position(entity);
                }

                if (entity->flags & ENTITY_FLAG_PENDING_INSTANCE_DELETE) {
                    delete_entity(entity->listIndex);
                }

                if (entity->flags & ENTITY_FLAG_PENDING_FULL_DELETE) {
                    delete_entity_and_unload_data(entity->listIndex);
                }
            }
        }
    }

    update_shadows();
    gCurrentHiddenPanels.tryFlipTrigger = FALSE;
}

void update_shadows(void) {
    s32 i;

    entity_numShadows = 0;

    for (i = 0; i < MAX_SHADOWS; i++) {
        Shadow* shadow = get_shadow_by_index(i);

        if (shadow != NULL) {
            entity_numShadows++;

            if (!(shadow->flags & ENTITY_FLAG_SKIP_UPDATE)) {
                if (shadow->flags & ENTITY_FLAG_ALWAYS_FACE_CAMERA) {
                    shadow->rot.y = -gCameras[gCurrentCameraID].curYaw;
                }

                update_shadow_transform_matrix(shadow);

                if (shadow->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    update_model_animator(shadow->entityModelID);
                } else {
                    exec_entity_model_commandlist(shadow->entityModelID);
                }

                if (shadow->flags & ENTITY_FLAG_PENDING_INSTANCE_DELETE) {
                    _delete_shadow(shadow->listIndex);
                }
            }
        }
    }
}

void set_entity_commandlist(Entity* entity, s32* entityScript) {
    entity->scriptReadPos = entityScript;
    entity->scriptDelay = 1;
    entity->savedReadPos[0] = entity->scriptReadPos;
}

s32 step_entity_commandlist(Entity* entity) {
    s32* args = entity->scriptReadPos;
    s32 ret;
    s32 labelId;
    void (*tempfunc)(Entity*);

    switch (*args++) {
        case ENTITY_SCRIPT_OP_End:
            entity->scriptDelay = -1;
            entity->updateScriptCallback = NULL;
            entity->scriptReadPos = NULL;
            ret = FALSE;
            break;
        case ENTITY_SCRIPT_OP_Jump:
            entity->scriptReadPos = (s32*)*args;
            entity->scriptDelay = 1;
            entity->savedReadPos[0] = entity->scriptReadPos;
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_Call:
            tempfunc = (void (*)(Entity*))(*args++);
            entity->scriptReadPos = args;
            (tempfunc)(entity);
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_SetCallback:
            entity->scriptDelay = *args++;
            entity->updateScriptCallback = (s32 (*)(Entity*)) *args++;
            entity->scriptReadPos = args++;
            ret = FALSE;
            break;
        case ENTITY_SCRIPT_OP_Goto:
            entity->scriptReadPos = entity->savedReadPos[*args];
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_Label:
            labelId = *args++;
            entity->savedReadPos[labelId] = args;
            entity->scriptReadPos = args;
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_RestartBoundScript:
            if (entity->boundScriptBytecode != NULL) {
                entity->flags |= ENTITY_FLAG_BOUND_SCRIPT_DIRTY;
            }
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_SetFlags:
            entity->flags |= *args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_ClearFlags:
            entity->flags &= ~*args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        case ENTITY_SCRIPT_OP_PlaySound:
            sfx_play_sound(*args++);
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
        default:
            args++;
            entity->scriptReadPos = args++;
            ret = TRUE;
            break;
    }
    return ret;
}

void exec_entity_commandlist(Entity* entity) {
    while (step_entity_commandlist(entity));
}

void func_8010FD98(void* arg0, s32 alpha) {
    if (alpha >= 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_01, PM_CC_02);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
    }
}

void func_8010FE44(void* arg0) {
    func_8010FD98(arg0, D_8014AFB0);
}

void entity_model_set_shadow_color(void* data) {
    s32 alpha = (s32)data;

    gDPSetCombineMode(gMainGfxPos++, PM_CC1_SHADOW, PM_CC2_SHADOW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
}

void render_entities(void) {
    s32 i;

    for (i = 0; i < MAX_ENTITIES; i++) {
        Entity* entity = get_entity_by_index(i);

        if (entity != NULL) {
            if (!gGameStatusPtr->isBattle) {
                if (gEntityHideMode != ENTITY_HIDE_MODE_0 &&
                    !(entity->flags & ENTITY_FLAG_IGNORE_DISTANCE_CULLING) &&
                    dist2D(gPlayerStatusPtr->pos.x,
                           gPlayerStatusPtr->pos.z,
                           entity->pos.x,
                           entity->pos.z) > 200.0f
                ) {
                    continue;
                }

                if (gEntityHideMode == ENTITY_HIDE_MODE_1) {
                    if (!(entity->flags & ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE1)) {
                        continue;
                    }
                } else if (gEntityHideMode == ENTITY_HIDE_MODE_2) {
                    if (!(entity->flags & ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2)) {
                        continue;
                    }
                }
            }

            if (!(entity->flags & ENTITY_FLAG_HIDDEN)) {
                if (entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    if (D_8014AFB0 == 255) {
                        if (entity->renderSetupFunc != NULL) {
                            set_animator_render_callback(
                                entity->virtualModelIndex,
                                (void*)(u32) entity->listIndex,
                                (void (*)(void*)) entity->renderSetupFunc
                            );
                        }
                    } else {
                        set_animator_render_callback(
                            entity->virtualModelIndex,
                            (void*)(u32) entity->listIndex,
                            func_8010FE44
                        );
                    }

                    if (entity->gfxBaseAddr == NULL) {
                        render_animated_model(entity->virtualModelIndex, &entity->transformMatrix);
                    } else {
                        render_animated_model_with_vertices(entity->virtualModelIndex,
                                      &entity->transformMatrix,
                                      entity->vertexSegment,
                                      entity->gfxBaseAddr);
                    }
                } else {
                    if (D_8014AFB0 == 255) {
                        if (entity->renderSetupFunc != NULL) {
                            bind_entity_model_setupGfx(
                                entity->virtualModelIndex,
                                (void*)(u32) entity->listIndex,
                                (void (*)(void*)) entity->renderSetupFunc
                            );
                        } else {
                            get_entity_model(entity->virtualModelIndex)->fpSetupGfxCallback = NULL;
                        }
                    } else {
                        bind_entity_model_setupGfx(entity->virtualModelIndex, (void*)(u32)entity->listIndex, func_8010FE44);
                    }

                    if (entity->gfxBaseAddr == NULL) {
                        draw_entity_model_A(entity->virtualModelIndex, &entity->transformMatrix);
                    } else {
                        draw_entity_model_B(entity->virtualModelIndex,
                                               &entity->transformMatrix,
                                               entity->vertexSegment,
                                               entity->gfxBaseAddr);
                    }
                }
            }
        }
    }

    render_shadows();
}

void render_shadows(void) {
    s32 i;

    for (i = 0; i < MAX_SHADOWS; i++) {
        Shadow* shadow = get_shadow_by_index(i);

        if (shadow != NULL) {
            if (shadow->flags & ENTITY_FLAG_HIDDEN) {
                if (shadow->flags & ENTITY_FLAG_FADING_AWAY) {
                    shadow->alpha -= 20;
                    if (shadow->alpha <= 20) {
                        shadow->flags |= ENTITY_FLAG_PENDING_INSTANCE_DELETE;
                    }
                }
            } else if (shadow->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                if (shadow->vertexArray == NULL) {
                    render_animated_model(shadow->entityModelID, &shadow->transformMatrix);
                } else {
                    render_animated_model_with_vertices(shadow->entityModelID,
                                  &shadow->transformMatrix,
                                  shadow->vertexSegment,
                                  shadow->vertexArray);
                }
            } else {
                if (shadow->flags & ENTITY_FLAG_FADING_AWAY) {
                    shadow->alpha -= 20;
                    if (shadow->alpha <= 20) {
                        shadow->flags |=  ENTITY_FLAG_PENDING_INSTANCE_DELETE;
                    }
                }

                bind_entity_model_setupGfx(shadow->entityModelID, (void*)(u32)shadow->alpha, entity_model_set_shadow_color);

                if (shadow->vertexArray == NULL) {
                    draw_entity_model_A(shadow->entityModelID, &shadow->transformMatrix);
                } else {
                    draw_entity_model_B(shadow->entityModelID,
                                           &shadow->transformMatrix,
                                           shadow->vertexSegment,
                                           shadow->vertexArray);
                }
            }
        }
    }
}

void update_entity_transform_matrix(Entity* entity) {
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;

    if (entity->updateMatrixOverride != NULL) {
        entity->updateMatrixOverride(entity);
        return;
    }

    guTranslateF(sp58, entity->pos.x, entity->pos.y, entity->pos.z);
    guRotateF(spD8, entity->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(sp118, entity->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp158, entity->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp158, spD8, sp18);
    guMtxCatF(sp18, sp118, sp98);
    guScaleF(sp198, entity->scale.x, entity->scale.y, entity->scale.z);
    guMtxCatF(sp198, sp98, sp18);
    guMtxCatF(sp18, sp58, sp98);
    guMtxF2L(sp98, &entity->transformMatrix);
}

void update_shadow_transform_matrix(Shadow* shadow) {
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Matrix4f spD8;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;

    guTranslateF(sp58, shadow->pos.x, shadow->pos.y, shadow->pos.z);
    guRotateF(sp118, shadow->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(spD8, shadow->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp158, shadow->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp158, sp118, sp98);
    guMtxCatF(spD8, sp98, sp98);
    guScaleF(sp198, shadow->scale.x, shadow->scale.y, shadow->scale.z);
    guMtxCatF(sp198, sp98, sp18);
    guMtxCatF(sp18, sp58, sp98);
    guMtxF2L(sp98, &shadow->transformMatrix);
}

void update_entity_inverse_rotation_matrix(Entity* entity) {
    Matrix4f sp18;
    Matrix4f sp58;

    guRotateF(sp18, -entity->rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp58, -entity->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, sp58, sp18);
    guRotateF(sp58, -entity->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp18, sp58, entity->inverseTransformMatrix);

    entity->effectiveSize = sqrtf(((SQ(entity->aabb.x) + SQ(entity->aabb.z)) * 0.25f) + SQ(entity->aabb.y));
}

Entity* get_entity_by_index(s32 index) {
    return (*gCurrentEntityListPtr)[index & 0xFFF];
}

Shadow* get_shadow_by_index(s32 index) {
    return (*gCurrentShadowListPtr)[index & 0xFFF];
}

EntityList* get_entity_list(void) {
    EntityList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldEntityList;
    } else {
        ret = &gBattleEntityList;
    }
    return ret;
}

ShadowList* get_shadow_list(void) {
    ShadowList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldShadowList;
    } else {
        ret = &gBattleShadowList;
    }
    return ret;
}

s32 entity_start_script(Entity* entity) {
    if (entity->boundScriptBytecode != NULL) {
        entity->flags |= ENTITY_FLAG_BOUND_SCRIPT_DIRTY;
        return 1;
    }
    return 0;
}

u32 get_entity_type(s32 index) {
    Entity* entity = get_entity_by_index(index);

    if (entity == NULL) {
        return -1;
    } else {
        return entity->blueprint->entityType;
    }
}

void delete_entity(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);

    if (entity->dataBuf.any != NULL) {
        heap_free(entity->dataBuf.any);
    }

    if (!(entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        delete_model_animator(get_animator_by_index(entity->virtualModelIndex));
    }

    if (entity->shadowIndex >= 0) {
        Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

        shadow->flags |= ENTITY_FLAG_FADING_AWAY;
    }

    heap_free((*gCurrentEntityListPtr)[entityIndex]);
    (*gCurrentEntityListPtr)[entityIndex] = NULL;
}

void delete_entity_and_unload_data(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);

    if (entity->dataBuf.any != NULL) {
        heap_free(entity->dataBuf.any);
    }

    if (!(entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        delete_model_animator(get_animator_by_index(entity->virtualModelIndex));
    }

    entity_free_static_data(entity->blueprint);

    if (entity->shadowIndex >= 0) {
        Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

        shadow->flags |= ENTITY_FLAG_FADING_AWAY;
    }

    heap_free((*gCurrentEntityListPtr)[entityIndex]);
    (*gCurrentEntityListPtr)[entityIndex] = NULL;
}

void _delete_shadow(s32 shadowIndex) {
    Shadow* shadow = get_shadow_by_index(shadowIndex);

    free_entity_model_by_index(shadow->entityModelID);
    heap_free((*gCurrentShadowListPtr)[shadowIndex]);
    (*gCurrentShadowListPtr)[shadowIndex] = NULL;
}

s32 entity_get_collision_flags(Entity* entity) {
    u32 listIndex = entity->listIndex;
    s32 entityFlags = 0;
    u32 flag;

    if (entity->flags & ENTITY_FLAG_PARTNER_COLLISION) {
        entityFlags = ENTITY_COLLISION_PARTNER;
        entity->flags &= ~ENTITY_FLAG_PARTNER_COLLISION;
    }

    flag = gCollisionStatus.curFloor;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag) {
        entityFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
    }

    flag = gCollisionStatus.lastTouchedFloor;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag) {
        entityFlags |= ENTITY_COLLISION_PLAYER_LAST_FLOOR;
    }

    flag = gCollisionStatus.curCeiling;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag) {
        entityFlags |= ENTITY_COLLISION_PLAYER_TOUCH_CEILING;
    }

    flag = gCollisionStatus.pushingAgainstWall;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag) {
        entityFlags |= ENTITY_COLLISION_PLAYER_PUSHING_AGAINST;
    }

    flag = gCollisionStatus.lastWallHammered;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag) {
        entityFlags |= ENTITY_COLLISION_PLAYER_HAMMER;
    }

    flag = gCollisionStatus.curWall;
    if (flag != -1 && (flag & COLLISION_WITH_ENTITY_BIT) && listIndex == (u8)flag && gPlayerStatusPtr->pressedButtons & BUTTON_A) {
        entityFlags |= ENTITY_COLLISION_PLAYER_TOUCH_WALL;
    }

    return entityFlags;
}

s32 entity_try_partner_interaction_trigger(s32 entityIdx) {
    s32 interacted = FALSE;
    u32 entityType = get_entity_type(entityIdx);
    s32 partnerID = get_current_partner_id();
    Entity* entity;

    switch (partnerID) {
        case PARTNER_BOMBETTE:
            switch (entityType) {
                default:
                    return FALSE;
                case ENTITY_TYPE_BLUE_SWITCH:
                case ENTITY_TYPE_RED_SWITCH:
                case ENTITY_TYPE_MULTI_TRIGGER_BLOCK:
                case ENTITY_TYPE_BRICK_BLOCK:
                case ENTITY_TYPE_MULTI_COIN_BRICK:
                case ENTITY_TYPE_YELLOW_BLOCK:
                case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
                case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
                case ENTITY_TYPE_HIDDEN_RED_BLOCK:
                case ENTITY_TYPE_RED_BLOCK:
                case ENTITY_TYPE_HAMMER1_BLOCK:
                case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
                case ENTITY_TYPE_SUPER_BLOCK:
                case ENTITY_TYPE_BOMBABLE_ROCK:
                    entity = get_entity_by_index(entityIdx);
                    entity->flags |= ENTITY_FLAG_PARTNER_COLLISION;
                    interacted = TRUE;
            }
            break;
        case PARTNER_KOOPER:
             switch (entityType) {
                default:
                    return FALSE;
                case ENTITY_TYPE_BLUE_SWITCH:
                case ENTITY_TYPE_RED_SWITCH:
                case ENTITY_TYPE_MULTI_TRIGGER_BLOCK:
                case ENTITY_TYPE_BRICK_BLOCK:
                case ENTITY_TYPE_MULTI_COIN_BRICK:
                case ENTITY_TYPE_YELLOW_BLOCK:
                case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
                case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
                case ENTITY_TYPE_HIDDEN_RED_BLOCK:
                case ENTITY_TYPE_RED_BLOCK:
                case ENTITY_TYPE_HEALING_BLOCK:
                case ENTITY_TYPE_1C:
                case ENTITY_TYPE_SAVE_POINT:
                case ENTITY_TYPE_SUPER_BLOCK:
                    entity = get_entity_by_index(entityIdx);
                    entity->flags |= ENTITY_FLAG_PARTNER_COLLISION;
                    interacted = TRUE;
            }
            break;
    }
    return interacted;
}

s32 test_player_entity_aabb(Entity* entity) {
    f32 yTemp = entity->pos.y - (gPlayerStatus.pos.y + gPlayerStatus.colliderHeight);
    f32 xCollRadius;
    f32 zCollRadius;
    f32 xDist;
    f32 zDist;

    if (yTemp > 0.0f || gPlayerStatus.colliderHeight + entity->aabb.y < fabsf(yTemp)) {
        return 0;
    }

    xCollRadius = (gPlayerStatus.colliderDiameter + entity->aabb.x) * 0.5;
    xDist = fabsf(gPlayerStatus.pos.x - entity->pos.x);
    zCollRadius = ((gPlayerStatus.colliderDiameter + entity->aabb.z) * 0.5);
    zDist = fabsf(gPlayerStatus.pos.z - entity->pos.z);

    if (xCollRadius < xDist || zCollRadius < zDist) {
        return 0;
    }

    return 1;
}

s32 is_player_action_state(s8 actionState) {
    return actionState == gPlayerStatus.actionState;
}

void entity_set_render_script(Entity* entity, EntityModelScript* cmdList) {
    if (!(entity->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL)) {
        set_entity_model_render_command_list(entity->virtualModelIndex, cmdList);
    }
}

void entity_reset_collision(Entity* entity) {
    entity->collisionTimer = 0;
    entity->flags &= ~ENTITY_FLAG_DETECTED_COLLISION;
}

void load_area_specific_entity_data(void) {
    if (!isAreaSpecificEntityDataLoaded) {
        if (gGameStatusPtr->areaID == AREA_JAN || gGameStatusPtr->areaID == AREA_IWA) {
            DMA_COPY_SEGMENT(entity_jan_iwa);
        } else if (gGameStatusPtr->areaID == AREA_SBK || gGameStatusPtr->areaID == AREA_OMO) {
            DMA_COPY_SEGMENT(entity_sbk_omo);
        } else {
            DMA_COPY_SEGMENT(entity_default);
        }

        isAreaSpecificEntityDataLoaded = TRUE;
    }
}

void clear_entity_data(b32 arg0) {
    s32 i;

    D_801516FC = 1;
    entity_numEntities = 0;
    entity_numShadows = 0;
    entity_updateCounter = 0;
    D_80151304 = 0;

    if (!gGameStatusPtr->isBattle) {
        gEntityHideMode = ENTITY_HIDE_MODE_0;
    }

    isAreaSpecificEntityDataLoaded = FALSE;
    gCurrentHiddenPanels.panelsCount = 0;
    gCurrentHiddenPanels.activateISpy = FALSE;
    if (!arg0) {
        D_80151344 = 0;
    }
    D_8014AFB0 = 255;

    if (!gGameStatusPtr->isBattle) {
        wEntityDataLoadedSize = 0;
        for (i = 0; i < MAX_ENTITIES; i++) {
            wEntityBlueprint[i] = NULL;
        }
    } else {
        bEntityDataLoadedSize = 0;
        for (i = 0; i < ARRAY_COUNT(bEntityBlueprint); i++) {
            bEntityBlueprint[i] = NULL;
        }
    }

    if (!gGameStatusPtr->isBattle) {
        gEntityHeapBottom = WORLD_ENTITY_HEAP_BOTTOM;
        gEntityHeapBase = WORLD_ENTITY_HEAP_BASE;
    } else {
        gEntityHeapBottom = (s32) BattleEntityHeapBottom;
        gEntityHeapBase = gEntityHeapBottom + 0x3000;
    }

    gCurrentEntityListPtr = get_entity_list();
    gCurrentShadowListPtr = get_shadow_list();

    for (i = 0; i < MAX_ENTITIES; i++) {
        (*gCurrentEntityListPtr)[i] = NULL;
    }

    for (i = 0; i < MAX_SHADOWS; i++) {
        (*gCurrentShadowListPtr)[i] = NULL;
    }
}

void init_entity_data(void) {
    if (!gGameStatusPtr->isBattle) {
        gEntityHeapBottom = WORLD_ENTITY_HEAP_BOTTOM;
        gEntityHeapBase = WORLD_ENTITY_HEAP_BASE;
        reload_world_entity_data();
    } else {
        s32 i;

        for (i = 0; i < ARRAY_COUNT(bEntityBlueprint); i++) {
            bEntityBlueprint[i] = 0;
        }
        gEntityHeapBottom = (s32) BattleEntityHeapBottom;
        gEntityHeapBase = gEntityHeapBottom + 0x3000;
    }
    gCurrentEntityListPtr = get_entity_list();
    gCurrentShadowListPtr = get_shadow_list();
    entity_numEntities = 0;
    entity_numShadows = 0;
}

void reload_world_entity_data(void) {
    s32 i;
    s32 totalSize = 0;
    s32 temp1;
    s32 dataLength;
    void* gfxData;
    void* animData;

    for (i = 0; i < MAX_ENTITIES; i++) {
        EntityBlueprint* bp = wEntityBlueprint[i];
        if (bp == NULL) {
            break;
        }

        if (!(bp->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL)) {
            void* gfxData;

            dataLength = ((bp->dma.end - bp->dma.start) >> 2);
            gfxData = (void*)(gEntityHeapBase - totalSize * 4 - dataLength * 4);
            totalSize += dma_copy(bp->dma.start, bp->dma.end, gfxData) >> 2;
        } else {
            DmaEntry* dmaList = bp->dmaList;

            if (bp->entityType == ENTITY_TYPE_RESET_MUNCHLESIA) {
                gfxData = (void*)gEntityHeapBottom;
                temp1 = dma_copy(dmaList[0].start, dmaList[0].end, gfxData) >> 2;
                dma_copy(dmaList[1].start, dmaList[1].end, (void*)(gEntityHeapBottom + temp1 * 4)) >> 2;
                animData = (void*)(gEntityHeapBottom + temp1 * 4);
                entity_swizzle_anim_pointers(bp, animData, gfxData);
            } else {
                s32 temp5;
                s32 q;

                dataLength = ((dmaList[0].end - dmaList[0].start) >> 2);
                q = gEntityHeapBase - totalSize * 4;
                gfxData = (void*)(q - dataLength * 4);
                totalSize += dma_copy(dmaList[0].start, dmaList[0].end, gfxData) >> 2;

                dataLength = ((dmaList[1].end - dmaList[1].start) >> 2);
                q = gEntityHeapBase - totalSize * 4;
                animData = (void*)(q - dataLength * 4);
                totalSize += dma_copy(dmaList[1].start, dmaList[1].end, animData) >> 2;

                entity_swizzle_anim_pointers(bp, animData, gfxData);
            }
        }
    }
}

void entity_swizzle_anim_pointers(EntityBlueprint* entityData, void* baseAnim, void* baseGfx) {
    StaticAnimatorNode* node;
    s32* ptr = (s32*)((s32)baseAnim + (s32)entityData->modelAnimationNodes);

    while (TRUE) {
        if (*ptr == -1) {
            *ptr = 0;
            return;
        }
        node = (StaticAnimatorNode*)((s32)baseAnim + ((*ptr) & 0xFFFF));
        *ptr++ = (s32)node;

        if ((s32)node->displayList != -1) {
            node->displayList = (Gfx*)((s32)baseGfx + ((s32)(node->displayList) & 0xFFFF));
        } else {
            node->displayList = NULL;
        }

        if ((s32)node->sibling != -1) {
            node->sibling = (StaticAnimatorNode*)((s32)baseAnim + ((s32)(node->sibling) & 0xFFFF));
        } else {
            node->sibling = NULL;
        }

        if ((s32)node->child != -1) {
            node->child = (StaticAnimatorNode*)((s32)baseAnim + ((s32)(node->child) & 0xFFFF));
        } else {
            node->child = NULL;
        }

        if ((s32)node->vtxList != -1) {
            node->vtxList = (Vtx*)((s32)baseGfx + ((s32)(node->vtxList) & 0xFFFFF));
        } else {
            node->vtxList = NULL;
        }
    }
}

s32 is_entity_data_loaded(Entity* entity, EntityBlueprint* blueprint, s32* loadedStart, s32* loadedEnd) {
    EntityBlueprint** blueprints;
    s32 i;
    s32 ret;
    s32 size;
    DmaEntry* entDmaList;

    *loadedStart = 0;
    *loadedEnd = 0;
    ret = FALSE;

    if (!gGameStatusPtr->isBattle) {
        blueprints = wEntityBlueprint;
    } else {
        blueprints = bEntityBlueprint;
    }

    for (i = 0; i < MAX_ENTITIES; i++, blueprints++) {
        EntityBlueprint* bp = *blueprints;
        if (bp == NULL) {
            blueprints[0] = blueprint;
            blueprints[1] = NULL;
            ret = TRUE;
            if (blueprint->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                s32 size;
                entDmaList = blueprint->dmaList;
                size = (entDmaList[0].end - entDmaList[0].start) >> 2;
                *loadedEnd = *loadedStart + size;
            }
            break;
        } else {
            DmaEntry* bpDmaList = bp->dmaList;
            do {} while (0); // TODO find better match
            entDmaList = blueprint->dmaList;
            if (bpDmaList == entDmaList) {
                if (blueprint->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    s32 size = (bpDmaList[0].end - bpDmaList[0].start) >> 2;
                    *loadedEnd = *loadedStart + size;
                }
                break;
            } else if (bp == blueprint) {
                if (bp->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    s32 size = (entDmaList[0].end - entDmaList[0].start) >> 2;
                    *loadedEnd = *loadedStart + size;
                }
                break;
            } else {
                if (bp->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                    s32 size = (bpDmaList[0].end - bpDmaList[0].start) >> 2;
                    *loadedEnd = *loadedStart = *loadedStart + size;
                    size = (bpDmaList[1].end - bpDmaList[1].start) >> 2;
                    *loadedStart = *loadedStart + size;
                } else {
                    *loadedStart += (bp->dma.end - bp->dma.start) >> 2;
                }
            }
        }
    }

    return ret;
}

void load_simple_entity_data(Entity* entity, EntityBlueprint* bp, s32 listIndex) {
    s32 loadedStart;
    s32 loadedEnd;
    s32 entitySize;
    u32 temp;
    s32 totalSize;

    entity->vertexSegment = 0xA;
    if (!gGameStatusPtr->isBattle) {
        totalSize = wEntityDataLoadedSize;
    } else {
        totalSize = bEntityDataLoadedSize;
    }

    if (is_entity_data_loaded(entity, bp, &loadedStart, &loadedEnd)) {
        if (totalSize + ((bp->dma.end - bp->dma.start) >> 2) > 0x5FFCU) {
            get_entity_type(entity->listIndex);
            get_entity_type(entity->listIndex);
            PANIC();
        }
        entitySize = (bp->dma.end - bp->dma.start) >> 2;
        entity->gfxBaseAddr = (void*)(gEntityHeapBase - totalSize * 4 - entitySize * 4);
        totalSize += dma_copy(bp->dma.start, bp->dma.end, entity->gfxBaseAddr) >> 2;
        get_entity_type(entity->listIndex);
    } else {
        entitySize = (bp->dma.end - bp->dma.start) >> 2;
        entity->gfxBaseAddr = (void*)(gEntityHeapBase - loadedStart * 4 - entitySize * 4);
        get_entity_type(entity->listIndex);
    }

    if (!gGameStatusPtr->isBattle) {
        wEntityDataLoadedSize = totalSize;
    } else {
        bEntityDataLoadedSize = totalSize;
    }
}

void load_split_entity_data(Entity* entity, EntityBlueprint* entityData, s32 listIndex) {
    s32 swizzlePointers = FALSE;
    s32 loadedStart, loadedEnd;
    void* animBaseAddr;
    s16* animationScript;
    StaticAnimatorNode** animationNodes;
    s32 specialSize;
    s32 dma1size;
    s32 dma2size_1;
    s32 dma2size_2;
    s32 totalLoaded;

    if (entityData->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
        DmaEntry* dmaList = entityData->dmaList;
        entity->vertexSegment = 0xA;

        switch (entityData->entityType) {
            case ENTITY_TYPE_RESET_MUNCHLESIA:
            case ENTITY_TYPE_MUNCHLESIA_ENVELOP:
            case ENTITY_TYPE_MUNCHLESIA_CHEWING:
            case ENTITY_TYPE_MUNCHLESIA_RESET1:
                specialSize = 0x1000;
                break;
            case ENTITY_TYPE_MUNCHLESIA_GRAB:
            case ENTITY_TYPE_MUNCHLESIA_BEGIN_CHEW:
            case ENTITY_TYPE_MUNCHLESIA_SPIT_OUT:
            case ENTITY_TYPE_MUNCHLESIA_RESET2:
                specialSize = 0x2BC0;
                break;
            default:
                specialSize = 0;
                break;
        }

        if (specialSize != 0) {
            if (entityData->entityType == ENTITY_TYPE_RESET_MUNCHLESIA) {
                is_entity_data_loaded(entity, entityData, &loadedStart, &loadedEnd);
            }
            specialSize -= 0x1000;

            dma1size = dma_copy(dmaList[0].start, dmaList[0].end, (void*)(gEntityHeapBottom + specialSize * 4)) / 4;
            entity->gfxBaseAddr = (void*)(gEntityHeapBottom + specialSize * 4);
            dma_copy(dmaList[1].start, dmaList[1].end, (void*)(gEntityHeapBottom + specialSize * 4 + dma1size * 4));
            animBaseAddr = (void*)(gEntityHeapBottom + specialSize * 4 + dma1size * 4);
            swizzlePointers = TRUE;
        } else if (is_entity_data_loaded(entity, entityData, &loadedStart, &loadedEnd)) {
            if (!gGameStatusPtr->isBattle) {
                totalLoaded = wEntityDataLoadedSize;
            } else {
                totalLoaded = bEntityDataLoadedSize;
            }

            if ((totalLoaded + ((dmaList[0].end - dmaList[0].start) >> 2)) > 0x5FFCU) {
                get_entity_type(entity->listIndex);
                PANIC();
            }

            if ((totalLoaded + ((dmaList[1].end - dmaList[1].start) >> 2)) > 0x5FFCU) {
                get_entity_type(entity->listIndex);
                PANIC();
            }

            dma2size_1 = dma_copy(dmaList[0].start, dmaList[0].end, dmaList[0].start + ((gEntityHeapBase - totalLoaded * 4 - (s32)dmaList[0].end) >> 2) * 4) >> 2;
            entity->gfxBaseAddr = (void*)(gEntityHeapBase - totalLoaded * 4 - dma2size_1 * 4);
            totalLoaded += dma2size_1;

            dma2size_2 = dma_copy(dmaList[1].start, dmaList[1].end, dmaList[1].start + ((gEntityHeapBase - totalLoaded * 4 - (s32)dmaList[1].end) >> 2) * 4) >> 2;
            animBaseAddr = (void*)(gEntityHeapBase - totalLoaded * 4 - dma2size_2 * 4);
            totalLoaded += dma2size_2;
            get_entity_type(entity->listIndex);

            if (!gGameStatusPtr->isBattle) {
                wEntityDataLoadedSize = totalLoaded;
            } else {
                bEntityDataLoadedSize = totalLoaded;
            }
            swizzlePointers = TRUE;
        } else {
            u32 temp = (dmaList[0].end - dmaList[0].start) >> 2;
            entity->gfxBaseAddr = (void*)(gEntityHeapBase - loadedStart * 4 - temp * 4);
            temp = (dmaList[1].end - dmaList[1].start) >> 2;
            animBaseAddr = (void*)(gEntityHeapBase - loadedEnd * 4 - temp * 4);
            get_entity_type(entity->listIndex);
        }
    } else {
        entity->virtualModelIndex = create_model_animator(entityData->renderCommandList);
        load_model_animator_tree(entity->virtualModelIndex, entityData->modelAnimationNodes);
        update_model_animator(entity->virtualModelIndex);
        return;
    }
    animationScript = entityData->renderCommandList;
    animationNodes = (StaticAnimatorNode**)((s32)animBaseAddr + (s32)entityData->modelAnimationNodes);
    if (swizzlePointers) {
        entity_swizzle_anim_pointers(entityData, animBaseAddr, entity->gfxBaseAddr);
    }
    entity->virtualModelIndex = create_mesh_animator(animationScript, animBaseAddr);
    load_mesh_animator_tree(entity->virtualModelIndex, animationNodes);
    update_model_animator(entity->virtualModelIndex);
    entity->flags |= ENTITY_FLAG_HAS_ANIMATED_MODEL;
}

s32 func_80111790(EntityBlueprint* data) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentEntityListPtr); i++) {
        Entity* entity = (*gCurrentEntityListPtr)[i];

        if (entity != NULL && entity->blueprint->dma.start != NULL) {
            if (entity->blueprint->dma.start == entity->blueprint) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void entity_free_static_data(EntityBlueprint* data) {
    s32 freeSlot;
    s32 size;
    EntityBlueprint* bp;

    for (freeSlot = 0; freeSlot < MAX_ENTITIES; freeSlot++) {
        bp = wEntityBlueprint[freeSlot];
        if (bp == NULL) {
            break;
        }
    }

    if (freeSlot < MAX_ENTITIES) {
        bp = wEntityBlueprint[freeSlot - 1];
        if (bp == data) {
            if (bp->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL) {
                DmaEntry* dmaList = bp->dmaList;
                size = ((dmaList[0].end - dmaList[0].start) >> 2);
                size += ((dmaList[1].end - dmaList[1].start) >> 2);
                if (!func_80111790(bp)) {
                    wEntityBlueprint[freeSlot - 1] = NULL;
                    wEntityDataLoadedSize -= size;
                }
            } else {
                size = (bp->dma.end - bp->dma.start) >> 2;
                if (!func_80111790(bp)) {
                    wEntityBlueprint[freeSlot - 1] = NULL;
                    wEntityDataLoadedSize -= size;
                }
            }
        }
    }
}

s32 create_entity(EntityBlueprint* bp, ...) {
    va_list ap;
    EntityBlueprint** bpPtr;
    f32 x, y, z;
    f32 rotY;
    s32 listIndex;
    Entity* entity;
    s32* args;

    va_start(ap, bp);
    // needed to match
    bpPtr = &bp;
    *bpPtr = bp;

    load_area_specific_entity_data();

    x = va_arg(ap, s32);
    y = va_arg(ap, s32);
    z = va_arg(ap, s32);
    rotY = va_arg(ap, s32);

    args = &CreateEntityVarArgBuffer[2];

    *args-- = 0;
    *args-- = 0;
    *args = 0;

    for (listIndex = 3; listIndex > 0; listIndex--) {
        s32 arg = va_arg(ap, s32);

        if (arg == MAKE_ENTITY_END) {
            break;
        }
        *args++ = arg;
    }

    va_end(ap);

    for (listIndex = 0; listIndex < ARRAY_COUNT(*gCurrentEntityListPtr); listIndex++) {
        if ((*gCurrentEntityListPtr)[listIndex] == NULL) {
            break;
        }
    }

    if (listIndex >= MAX_ENTITIES) {
        return -1;
    }

    (*gCurrentEntityListPtr)[listIndex] = entity = heap_malloc(sizeof(*entity));
    mem_clear(entity, sizeof(*entity));
    entity->dataBuf.any = NULL;
    if (bp->typeDataSize != 0) {
        entity->dataBuf.any = heap_malloc(bp->typeDataSize);
        mem_clear(entity->dataBuf.any, bp->typeDataSize);
    }
    entity->type = bp->entityType;
    entity->listIndex = listIndex;
    entity->boundScript = NULL;
    entity->updateMatrixOverride = NULL;
    entity->blueprint = bp;
    entity->scriptReadPos = bp->updateEntityScript;
    entity->scriptDelay = entity->scriptReadPos != NULL ? 1 : 0;
    entity->savedReadPos[0] = bp->updateEntityScript;
    entity->updateScriptCallback = NULL;
    entity->flags = bp->flags | ENTITY_FLAG_CREATED;
    entity->collisionFlags = 0;
    entity->collisionTimer = 0;
    entity->renderSetupFunc = NULL;
    entity->pos.x = x;
    entity->pos.y = y;
    entity->pos.z = z;
    entity->rot.x = 0.0f;
    entity->rot.y = rotY;
    entity->rot.z = 0.0f;
    entity->scale.x = 1.0f;
    entity->scale.y = 1.0f;
    entity->scale.z = 1.0f;
    entity->aabb.x = bp->aabbSize[0];
    entity->aabb.y = bp->aabbSize[1];
    entity->aabb.z = bp->aabbSize[2];
    entity->unk_05 = 1;
    entity->unk_08 = -1;
    entity->alpha = 255;
    entity->virtualModelIndex = -1;
    entity->shadowIndex = -1;
    entity->gfxBaseAddr = NULL;

    if (!(bp->flags & ENTITY_FLAG_HAS_ANIMATED_MODEL)) {
        if (bp->dma.start != 0) {
            load_simple_entity_data(entity, bp, listIndex);
        }
        if (bp->renderCommandList != NULL) {
            entity->virtualModelIndex = load_entity_model(bp->renderCommandList);
            exec_entity_model_commandlist(entity->virtualModelIndex);
        }
    } else {
        load_split_entity_data(entity, bp, listIndex);
    }

    if (bp->entityType != ENTITY_TYPE_SHADOW && (entity->flags & (ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_SHADOW))) {
        create_entity_shadow(entity, x, y, z);
    }

    switch (bp->entityType) {
        case ENTITY_TYPE_BLUE_SWITCH:
        case ENTITY_TYPE_RED_SWITCH:
        case ENTITY_TYPE_SIMPLE_SPRING:
        case ENTITY_TYPE_SCRIPT_SPRING:
        case ENTITY_TYPE_STAR_BOX_LAUNCHER:
            entity->flags |= ENTITY_FLAG_4000;
            break;
    }

    if (bp->fpInit != NULL) {
        bp->fpInit(entity);
    }

    update_entity_transform_matrix(entity);
    return entity->listIndex;
}

s32 create_shadow_from_data(ShadowBlueprint* bp, f32 x, f32 y, f32 z) {
    Shadow* shadow;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentShadowListPtr); i++) {
        if ((*gCurrentShadowListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentShadowListPtr));

    shadow = heap_malloc(sizeof(*shadow));
    (*gCurrentShadowListPtr)[i] = shadow;
    mem_clear(shadow, sizeof(*shadow));
    shadow->listIndex = i;
    shadow->flags = bp->flags | ENTITY_FLAG_CREATED;
    shadow->alpha = 128;
    shadow->unk_06 = 0x80;
    shadow->pos.x = x;
    shadow->pos.y = y;
    shadow->pos.z = z;
    shadow->scale.x = 1.0f;
    shadow->scale.y = 1.0f;
    shadow->scale.z = 1.0f;

    if (bp->animModelNode != NULL) {
        shadow->flags |= ENTITY_FLAG_HAS_ANIMATED_MODEL;
        shadow->entityModelID = create_model_animator(bp->renderCommandList);
        load_model_animator_tree(shadow->entityModelID, bp->animModelNode);
    } else {
        shadow->entityModelID = load_entity_model(bp->renderCommandList);
    }

    if (bp->onCreateCallback != NULL) {
        bp->onCreateCallback(shadow);
    }
    update_shadow_transform_matrix(shadow);
    return shadow->listIndex;
}

s32 MakeEntity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EntityBlueprint* entityData;
    s32 x, y, z;
    s32 flags;
    s32 nextArg;
    s32 entityIndex;
    s32 endOfArgs;
    s32* varArgBufPos;

    if (isInitialCall != TRUE) {
        return ApiStatus_DONE2;
    }

    entityData = (EntityBlueprint*)evt_get_variable(script, *args++);
    varArgBufPos = &CreateEntityVarArgBuffer[2];
    endOfArgs = MAKE_ENTITY_END;
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    flags = evt_get_variable(script, *args++);

    *varArgBufPos-- = 0;
    *varArgBufPos-- = 0;
    *varArgBufPos = 0;

    do {
        nextArg = evt_get_variable(script, *args++);

        if (nextArg != endOfArgs) {
            *varArgBufPos++ = nextArg;
        }
    } while (nextArg != endOfArgs);

    entityIndex = create_entity(entityData, x, y, z, flags, CreateEntityVarArgBuffer[0], CreateEntityVarArgBuffer[1], CreateEntityVarArgBuffer[2], endOfArgs);
    gLastCreatedEntityIndex = entityIndex;
    script->varTable[0] = entityIndex;
    return ApiStatus_DONE2;
}

ApiStatus SetEntityCullMode(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);

    if (mode == 0) {
        entity->flags |= ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE1;
    } else if (mode == 1) {
        entity->flags |= ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2;
    } else if (mode == 2) {
        entity->flags |= ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2 | ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE1;
    } else {
        entity->flags |= ENTITY_FLAG_IGNORE_DISTANCE_CULLING | ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE2 |
                         ENTITY_FLAG_DRAW_IF_CLOSE_HIDE_MODE1;
    }
    return ApiStatus_DONE2;
}

ApiStatus UseDynamicShadow(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);
    Bytecode* args = script->ptrReadPos;

    if (evt_get_variable(script, *args++)) {
        Shadow* shadow;

        entity->flags |= ENTITY_FLAG_HAS_DYNAMIC_SHADOW;
        shadow = get_shadow_by_index(entity->shadowIndex);
        shadow->flags |= ENTITY_FLAG_SHADOW_POS_DIRTY;
    } else {
        entity->flags &= ~ENTITY_FLAG_HAS_DYNAMIC_SHADOW;
    }

    return ApiStatus_DONE2;
}

ApiStatus AssignScript(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        EvtScript* toBind = (EvtScript*)evt_get_variable(script, *args++);

        get_entity_by_index(gLastCreatedEntityIndex)->boundScriptBytecode = toBind;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignSwitchFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        s32 areaFlag = evt_get_variable(script, *args++);
        Entity* entity = get_entity_by_index(gLastCreatedEntityIndex);
        SwitchData* data = entity->dataBuf.swtch;

        data->areaFlagIndex = areaFlag;
        if (get_area_flag(areaFlag) != 0) {
            entity->flags |= ENTITY_FLAG_PENDING_INSTANCE_DELETE;
        }
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignBlockFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        s32 index = evt_get_variable_index(script, *args++);

        BlockData* data = get_entity_by_index(gLastCreatedEntityIndex)->dataBuf.block;
        data->gameFlagIndex = index;

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignChestFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        ChestData* data = get_entity_by_index(gLastCreatedEntityIndex)->dataBuf.chest;
        data->gameFlagIndex = evt_get_variable_index(script, *args);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignPanelFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        HiddenPanelData* data = get_entity_by_index(gLastCreatedEntityIndex)->dataBuf.hiddenPanel;

        data->pickupVar = evt_get_variable_index(script, *args++);
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

ApiStatus AssignCrateFlag(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall == TRUE) {
        WoodenCrateData* data = get_entity_by_index(gLastCreatedEntityIndex)->dataBuf.crate;

        data->globalFlagIndex = evt_get_variable_index(script, *args++);
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

s32 create_entity_shadow(Entity* entity, f32 x, f32 y, f32 z) {
    u16 bpFlags = entity->blueprint->flags;
    s32 type;
    s16 shadowIndex;

    if (bpFlags & ENTITY_FLAG_FIXED_SHADOW_SIZE) {
        type = (bpFlags & ENTITY_FLAG_CIRCULAR_SHADOW) ? SHADOW_FIXED_CIRCLE : SHADOW_FIXED_SQUARE;
    } else {
        type = (bpFlags & ENTITY_FLAG_CIRCULAR_SHADOW) ? SHADOW_VARYING_CIRCLE : SHADOW_VARYING_SQUARE;
    }

    shadowIndex = create_shadow_type(type, x, y, z);
    entity->shadowIndex = shadowIndex;

    get_shadow_by_index(shadowIndex)->flags |= ENTITY_FLAG_DARK_SHADOW | ENTITY_FLAG_SHADOW_POS_DIRTY;

    return entity->shadowIndex;
}

s32 create_shadow_type(s32 type, f32 x, f32 y, f32 z) {
    s32 isFixedSize = FALSE;
    ShadowBlueprint* bp = &CircularShadowA;
    s32 shadowIndex;

    switch (type) {
        case SHADOW_FIXED_CIRCLE:
            isFixedSize = TRUE;
        case SHADOW_VARYING_CIRCLE:
            bp = &CircularShadowA;
            break;
        case SHADOW_FIXED_SQUARE:
            isFixedSize = TRUE;
        case SHADOW_VARYING_SQUARE:
            bp = &SquareShadow;
            break;
        case SHADOW_FIXED_ALT_CIRCLE:
            isFixedSize = TRUE;
        case SHADOW_VARYING_ALT_CIRCLE:
            bp = &CircularShadowB;
            break;
    }

    shadowIndex = create_shadow_from_data(bp, x, y, z);

    if (isFixedSize) {
        get_shadow_by_index(shadowIndex)->flags |= ENTITY_FLAG_FIXED_SHADOW_SIZE;
    }

    return shadowIndex;
}

void delete_shadow(s32 shadowIndex) {
    _delete_shadow(shadowIndex);
}

void update_entity_shadow_position(Entity* entity) {
    Shadow* shadow = get_shadow_by_index(entity->shadowIndex);

    if (shadow != NULL) {
        f32 rayX;
        f32 rayY;
        f32 rayZ;
        f32 hitYaw;
        f32 hitPitch;
        f32 hitLength;
        f32 origHitLength;

        if (entity->alpha < 255) {
            shadow->alpha = entity->alpha / 2;
        } else {
            u8 alphaTemp;

            if (shadow->flags & ENTITY_FLAG_DARK_SHADOW) {
                alphaTemp = 160;
            } else {
                alphaTemp = 128;
            }
            shadow->alpha = alphaTemp;
        }

        if (!(entity->flags & ENTITY_FLAG_HAS_DYNAMIC_SHADOW)) {
            if (shadow->flags & ENTITY_FLAG_SHADOW_POS_DIRTY) {
                shadow->flags &= ~ENTITY_FLAG_SHADOW_POS_DIRTY;
            } else {
                return;
            }
        }

        rayX = entity->pos.x;
        rayY = entity->pos.y;
        rayZ = entity->pos.z;

        if (!entity_raycast_down(&rayX, &rayY, &rayZ, &hitYaw, &hitPitch, &hitLength) && hitLength == 32767.0f) {
            hitLength = 0.0f;
        }

        origHitLength = hitLength;

        if (shadow->flags & ENTITY_FLAG_FIXED_SHADOW_SIZE) {
            hitLength = 212.5f;
            shadow->scale.x = entity->aabb.x / hitLength;
            shadow->scale.z = entity->aabb.z / hitLength;
        } else {
            hitLength = ((hitLength / 150.0f) + 0.95) * 250.0;
            shadow->scale.x = (entity->aabb.x / hitLength) * entity->scale.x;
            shadow->scale.z = (entity->aabb.z / hitLength) * entity->scale.z;
        }

        shadow->pos.x = entity->pos.x;
        shadow->pos.z = entity->pos.z;
        shadow->pos.y = rayY;
        entity->shadowPosY = rayY;
        shadow->rot.x = hitYaw;
        shadow->rot.z = hitPitch;
        shadow->rot.y = entity->rot.y;

        if (entity->pos.y < rayY) {
            shadow->flags |= ENTITY_FLAG_SKIP_UPDATE;
            entity->pos.y = rayY + 10.0f;
        } else {
            shadow->flags &= ~ENTITY_FLAG_SKIP_UPDATE;
        }

        shadow->flags = (shadow->flags & ~ENTITY_FLAG_HIDDEN) | ((u16)entity->flags & ENTITY_FLAG_HIDDEN);
        if (!(entity->flags & ENTITY_FLAG_400) && origHitLength == 0.0f) {
            shadow->flags |= ENTITY_FLAG_HIDDEN;
        }
    } else {
        entity->shadowPosY = 0.0f;
    }
}

s32 entity_raycast_down(f32* x, f32* y, f32* z, f32* hitYaw, f32* hitPitch, f32* hitLength) {
    f32 hitX, hitY, hitZ;
    f32 hitDepth;
    f32 hitNx, hitNy, hitNz;
    s32 entityID;
    s32 colliderID;
    s32 hitID;
    s32 ret;

    hitDepth = 32767.0f;
    *hitLength = 32767.0f;
    entityID = test_ray_entities(*x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    hitID = -1;
    ret = FALSE;

    if ((entityID >= 0) && ((get_entity_type(entityID) != ENTITY_TYPE_PUSH_BLOCK) || (hitNx == 0.0f && hitNz == 0.0f && hitNy == 1.0))) {
        hitID = entityID | COLLISION_WITH_ENTITY_BIT;
    }

    colliderID = test_ray_colliders(COLLIDER_FLAG_IGNORE_PLAYER, *x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx,
                                    &hitNy, &hitNz);
    if (colliderID >= 0) {
        hitID = colliderID;
    }

    if (hitID >= 0) {
        *hitLength = hitDepth;
        *y = hitY;
        *hitYaw = -atan2(0.0f, 0.0f, hitNz * 100.0f, hitNy * 100.0f);
        *hitPitch = -atan2(0.0f, 0.0f, hitNx * 100.0f, hitNy * 100.0f);
        ret = TRUE;
    } else {
        *hitYaw = 0.0f;
        *hitPitch = 0.0f;
    }
    return ret;
}

void set_standard_shadow_scale(Shadow* shadow, f32 height) {
    if (!gGameStatusPtr->isBattle) {
        shadow->scale.x = 0.13 - (height / 2600.0f);
    } else {
        shadow->scale.x = 0.12 - (height / 3600.0f);
    }

    if (shadow->scale.x < 0.01) {
        shadow->scale.x = 0.01f;
    }
    shadow->scale.z = shadow->scale.x;
}

void set_npc_shadow_scale(Shadow* shadow, f32 height, f32 npcRadius) {
    if (!gGameStatusPtr->isBattle) {
        shadow->scale.x = 0.13 - (height / 2600.0f);
    } else {
        shadow->scale.x = 0.12 - (height / 3600.0f);
    }

    if (shadow->scale.x < 0.01) {
        shadow->scale.x = 0.01f;
    }

    if (npcRadius > 60.0f) {
        shadow->scale.z = shadow->scale.x * 2.0f;
    } else {
        shadow->scale.z = shadow->scale.x;
    }
}

void set_peach_shadow_scale(Shadow* shadow, f32 scale) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 phi_f2 = 0.12f;

    if (!gGameStatusPtr->isBattle) {
        switch (playerStatus->anim) {
            case ANIM_Peach2_Carried:
            case ANIM_Peach2_Thrown:
            case ANIM_Peach2_Land:
            case ANIM_Peach3_TiedSideways:
                shadow->scale.x = 0.26f - (scale / 2600.0f);
                if (shadow->scale.x < 0.01) {
                    shadow->scale.x = 0.01f;
                }
                shadow->scale.z = 0.13f - (scale / 2600.0f);
                if (shadow->scale.z < 0.01) {
                    shadow->scale.z = 0.01f;
                }
                return;
        }

        phi_f2 = 0.16f;
    }

    shadow->scale.x = phi_f2 - (scale / 3600.0f);
    if (shadow->scale.x < 0.01) {
        shadow->scale.x = 0.01f;
    }
    shadow->scale.z = shadow->scale.x;
}

s32 is_block_on_ground(Entity* block) {
    f32 x = block->pos.x;
    f32 y = block->pos.y;
    f32 z = block->pos.z;
    f32 hitYaw;
    f32 hitPitch;
    f32 hitLength;
    s32 ret;

    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);

    ret = hitLength;
    if (ret == 32767) {
        ret = FALSE;
    }

    return ret;
}
