#include "common.h"

s32 D_8014C260[] = { 0x00000000, 0x00000000, 0xFFFFFF00, 0xFFFFFF00 };

s32 D_8014C270[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

extern EntityModelList gWorldEntityModelList;
extern EntityModelList gBattleEntityModelList;
extern EntityModelList* gCurrentEntityModelList;
extern s32 gEntityModelCount;
extern s32 D_8014C260[];
extern s32 entity_fog_enabled;
extern s32 entity_fog_red;
extern s32 entity_fog_green;
extern s32 entity_fog_blue;
extern s32 entity_fog_alpha;
extern s32 entity_fog_dist_min;
extern s32 entity_fog_dist_max;

s32 step_entity_model_commandlist(EntityModel* entityModel);
void free_entity_model_by_ref(EntityModel* entityModel);

void clear_entity_models(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentEntityModelList = &gWorldEntityModelList;
    } else {
        gCurrentEntityModelList = &gBattleEntityModelList;
    }

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        (*gCurrentEntityModelList)[i] = NULL;
    }

    entity_fog_red = 10;
    entity_fog_green = 10;
    entity_fog_blue = 10;
    entity_fog_alpha = 10;
    entity_fog_dist_min = 800;
    gEntityModelCount = 0;
    entity_fog_enabled = 0;
    entity_fog_dist_max = 1000;
}

void init_entity_models(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentEntityModelList = &gWorldEntityModelList;
    } else {
        gCurrentEntityModelList = &gBattleEntityModelList;
    }

    entity_fog_red = 10;
    entity_fog_green = 10;
    entity_fog_blue = 10;
    entity_fog_alpha = 10;
    entity_fog_dist_min = 800;
    gEntityModelCount = 0;
    entity_fog_enabled = 0;
    entity_fog_dist_max = 1000;
}

s32 load_entity_model(s32* cmdList) {
    EntityModel* newEntityModel;
    s32 i;

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        if ((*gCurrentEntityModelList)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ENTITY_MODELS);

    {
        s32* entityModelCount;
        (*gCurrentEntityModelList)[i] = newEntityModel = heap_malloc(sizeof(EntityModel));
        entityModelCount = &gEntityModelCount;
        (*entityModelCount)++;
    }
    ASSERT(newEntityModel != NULL);

    newEntityModel->flags = 0x17;
    newEntityModel->renderMode = 1;
    newEntityModel->displayList = NULL;
    newEntityModel->cmdListReadPos = cmdList;
    newEntityModel->nextFrameTime = 1.0f;
    newEntityModel->timeScale = 1.0f;
    if (cmdList == NULL) {
        newEntityModel->cmdListReadPos = D_8014C260;
    }
    newEntityModel->vertexArray = NULL;
    newEntityModel->fpSetupGfxCallback = NULL;
    newEntityModel->cmdListSavedPos = newEntityModel->cmdListReadPos;

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 ALT_load_entity_model(s32* cmdList) {
    EntityModel* newEntityModel;
    Gfx* newDisplayList;
    s32 i;

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        if ((*gCurrentEntityModelList)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ENTITY_MODELS);

    {
        s32* entityModelCount;
        (*gCurrentEntityModelList)[i] = newEntityModel = heap_malloc(sizeof(EntityModel));
        entityModelCount = &gEntityModelCount;
        (*entityModelCount)++;
    }

    ASSERT(newEntityModel != NULL);

    newEntityModel->displayList = newDisplayList = heap_malloc(sizeof(Gfx) * 2);
    ASSERT(newDisplayList != NULL);

    newEntityModel->flags = 0x417;
    newEntityModel->renderMode = 1;
    newEntityModel->cmdListReadPos = cmdList;
    newEntityModel->nextFrameTime = 1.0f;
    newEntityModel->timeScale = 1.0f;
    if (cmdList == NULL) {
        newEntityModel->cmdListReadPos = D_8014C260;
    }
    newEntityModel->vertexArray = NULL;
    newEntityModel->fpSetupGfxCallback = NULL;
    newEntityModel->cmdListSavedPos = newEntityModel->cmdListReadPos;

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

void exec_entity_model_commandlist(s32 idx) {
    EntityModel* entityModel;
    void* temp_v0_2;

    if (!gGameStatusPtr->isBattle || (idx & 0x800)) {
        idx &= ~0x800;
        entityModel = (*gCurrentEntityModelList)[idx];
        if (entityModel != NULL && (entityModel->flags)) {
            if (!(entityModel->flags & 0x20)) {
                if (!(entityModel->flags & 0x20000)) {
                    entityModel->flags &= ~0x100;
                    entityModel->nextFrameTime -= entityModel->timeScale;
                    if (entityModel->nextFrameTime <= 0.0f) {
                        while (step_entity_model_commandlist(entityModel));
                    }
                }
            }
        }
    }
}

s32 step_entity_model_commandlist(EntityModel* entityModel) {
    Gfx* displayList;

    u32* curPos = entityModel->cmdListReadPos;
    switch (*curPos++) {
        case 0: // kill model
            free_entity_model_by_ref(entityModel);
            return 1;
        case 1: // set display list ptr
            entityModel->nextFrameTime = (f32) *curPos++;
            entityModel->displayList = (Gfx*) *curPos++;
            entityModel->cmdListReadPos = curPos;
            break;
        case 2: // restore saved position
            entityModel->cmdListReadPos = entityModel->cmdListSavedPos;
            return 1;
        case 3: // set saved position
            entityModel->cmdListReadPos = entityModel->cmdListSavedPos = curPos;
            return 1;
        case 4: // set render mode
            entityModel->renderMode = *curPos++;
            entityModel->cmdListReadPos = curPos;
            return 1;
        case 5: // set flags
            entityModel->flags |= *curPos++;
            entityModel->cmdListReadPos = curPos;
            return 1;
        case 6: // clear flags
            entityModel->flags &= ~*curPos++;
            entityModel->cmdListReadPos = curPos;
            return 1;
        case 7: // populate display list
            displayList = entityModel->displayList;
            entityModel->nextFrameTime = *curPos++;
            displayList[0].words.w0 = *curPos++;
            displayList[0].words.w1 = *curPos++;
            displayList[1].words.w0 = *curPos++;
            displayList[1].words.w1 = *curPos++;
            entityModel->cmdListReadPos = curPos;
            break;
    }
    return 0;
}

void make_entity_model_mtx_flipZ(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = -1.0f;
    mtx[3][3] = 1.0f;
}

INCLUDE_ASM(s32, "entity", appendGfx_entity_model);

INCLUDE_ASM(s32, "entity", draw_entity_model_A);

INCLUDE_ASM(s32, "entity", draw_entity_model_B);

INCLUDE_ASM(s32, "entity", draw_entity_model_C);

INCLUDE_ASM(s32, "entity", draw_entity_model_D);

INCLUDE_ASM(s32, "entity", draw_entity_model_E);

void set_entity_model_render_command_list(s32 idx, u32* commandList) {
    u32* phi_a1;
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    if (entityModel != NULL && entityModel->flags) {
        phi_a1 = commandList;
        if (commandList == NULL) {
            phi_a1 = D_8014C260;
        }
        entityModel->cmdListReadPos = phi_a1;
        entityModel->cmdListSavedPos = phi_a1;
        entityModel->nextFrameTime = 1.0f;
        entityModel->timeScale = 1.0f;
    }
}

EntityModel* get_entity_model(s32 listIndex) {
    return (*gCurrentEntityModelList)[listIndex & ~0x800];
}

void free_entity_model_by_index(s32 idx) {
    s32 index = idx & ~0x800;
    EntityModel* entityModel = (*gCurrentEntityModelList)[index];

    if (entityModel != NULL && entityModel->flags) {
        if (entityModel->flags & 0x400) {
            heap_free(entityModel->displayList);
        }
        {
            s32* modelCount = &gEntityModelCount;
            heap_free((*gCurrentEntityModelList)[index]);
            (*gCurrentEntityModelList)[index] = NULL;
            (*modelCount)--;
        }
    }
}

void free_entity_model_by_ref(EntityModel* entityModel) {
    s32 i;

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        if ((*gCurrentEntityModelList)[i] == entityModel) {
            break;
        }
    }

    if (i < MAX_ENTITY_MODELS) {
        free_entity_model_by_index(i);
    }
}

void set_entity_model_flags(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    if (entityModel != NULL && entityModel->flags) {
        entityModel->flags |= newFlags;
    }
}

void clear_entity_model_flags(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    if (entityModel != NULL && entityModel->flags) {
        entityModel->flags &= ~newFlags;
    }
}

void bind_entity_model_setupGfx(s32 idx, s32 setupGfxCallbackArg0, UNK_FUN_PTR(fpSetupGfxCallback)) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    entityModel->fpSetupGfxCallback = fpSetupGfxCallback;
    entityModel->setupGfxCallbackArg0 = setupGfxCallbackArg0;
}

void func_80122F8C(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    entityModel->flags |= newFlags;
}

void func_80122FB8(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~0x800];

    entityModel->flags = (entityModel->flags & ~0xF) | newFlags;
}

void enable_entity_fog(void) {
    entity_fog_enabled = 1;
}

void disable_entity_fog(void) {
    entity_fog_enabled = 0;
}

void set_entity_fog_dist(s32 min, s32 max) {
    entity_fog_dist_min = min;
    entity_fog_dist_max = max;
}

void set_entity_fog_color(s32 r, s32 g, s32 b, s32 a) {
    entity_fog_red = r;
    entity_fog_green = g;
    entity_fog_blue = b;
    entity_fog_alpha = a;
}

s32 is_entity_fog_enabled(void) {
    return entity_fog_enabled;
}

void get_entity_fog_distance(s32* start, s32* end) {
    *start = entity_fog_dist_min;
    *end = entity_fog_dist_max;
}

void get_entity_fog_color(s32* r, s32* g, s32* b, s32* a) {
    *r = entity_fog_red;
    *g = entity_fog_green;
    *b = entity_fog_blue;
    *a = entity_fog_alpha;
}

void stub_generic_entity_delegate(void) {
}

void clear_generic_entity_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentDynamicEntityListPtr = &gWorldDynamicEntityList;
    } else {
        gCurrentDynamicEntityListPtr = &gBattleDynamicEntityList;
    }

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        (*gCurrentDynamicEntityListPtr)[i] = NULL;
    }
}

void init_generic_entity_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentDynamicEntityListPtr = &gWorldDynamicEntityList;
    } else {
        gCurrentDynamicEntityListPtr = &gBattleDynamicEntityList;
    }
}

s32 create_generic_entity_world(void (*updateFunc)(void), void (*drawFunc)(void)) {
    s32 i;
    DynamicEntity* newDynEntity;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* dynEntity = (*gCurrentDynamicEntityListPtr)[i];
        if (dynEntity == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_DYNAMIC_ENTITIES);

    (*gCurrentDynamicEntityListPtr)[i] = newDynEntity = heap_malloc(sizeof(DynamicEntity));
    ASSERT(newDynEntity != NULL);

    newDynEntity->flags = 3;
    newDynEntity->update = updateFunc;
    if (updateFunc == NULL) {
        newDynEntity->update = &stub_generic_entity_delegate;
    }
    newDynEntity->draw = drawFunc;
    if (drawFunc == NULL) {
        newDynEntity->draw = &stub_generic_entity_delegate;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 create_generic_entity_frontUI(void (*updateFunc)(void), void (*drawFunc)(void)) {
    s32 i;
    DynamicEntity* newDynEntity;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* dynEntity = (*gCurrentDynamicEntityListPtr)[i];
        if (dynEntity == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_DYNAMIC_ENTITIES);

    (*gCurrentDynamicEntityListPtr)[i] = newDynEntity = heap_malloc(sizeof(DynamicEntity));
    ASSERT(newDynEntity != NULL);

    newDynEntity->flags = 7;
    newDynEntity->update = updateFunc;
    if (updateFunc == NULL) {
        newDynEntity->update = &stub_generic_entity_delegate;
    }
    newDynEntity->draw = drawFunc;
    if (drawFunc == NULL) {
        newDynEntity->draw = &stub_generic_entity_delegate;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

s32 create_generic_entity_backUI(void (*updateFunc)(void), void (*drawFunc)(void)) {
    s32 i;
    DynamicEntity* newDynEntity;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* dynEntity = (*gCurrentDynamicEntityListPtr)[i];
        if (dynEntity == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_DYNAMIC_ENTITIES);

    (*gCurrentDynamicEntityListPtr)[i] = newDynEntity = heap_malloc(sizeof(DynamicEntity));
    ASSERT(newDynEntity != NULL);

    newDynEntity->flags = 0xB;
    newDynEntity->update = updateFunc;
    if (updateFunc == NULL) {
        newDynEntity->update = &stub_generic_entity_delegate;
    }
    newDynEntity->draw = drawFunc;
    if (drawFunc == NULL) {
        newDynEntity->draw = &stub_generic_entity_delegate;
    }

    if (gGameStatusPtr->isBattle) {
        i |= 0x800;
    }
    return i;
}

void update_generic_entities(void) {
    s32 i;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* entity = (*gCurrentDynamicEntityListPtr)[i];
        if (entity != NULL) {
            entity->flags &= ~2;
            entity->update();
        }
    }
}

void render_generic_entities_world(void) {
    s32 i;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* entity = (*gCurrentDynamicEntityListPtr)[i];
        if (entity != NULL && !(entity->flags & 2)) {
            if (!(entity->flags & 4)) {
                entity->draw();
            }
        }
    }
}

void render_generic_entities_frontUI(void) {
    s32 i;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* entity = (*gCurrentDynamicEntityListPtr)[i];
        if (entity != NULL && !(entity->flags & 2)) {
            if (entity->flags & 4) {
                entity->draw();
            }
        }
    }
}

void render_generic_entities_backUI(void) {
    s32 i;

    for (i = 0; i < MAX_DYNAMIC_ENTITIES; i++) {
        DynamicEntity* entity = (*gCurrentDynamicEntityListPtr)[i];
        if (entity != NULL && !(entity->flags & 2)) {
            if (entity->flags & 8) {
                entity->draw();
            }
        }
    }
}

void free_generic_entity(s32 idx) {
    if (!gGameStatusPtr->isBattle || (idx & 0x800)) {
        DynamicEntityList** curDynEntityList = &gCurrentDynamicEntityListPtr;

        idx &= ~0x800;
        if ((**curDynEntityList)[idx] != NULL) {
            heap_free((**curDynEntityList)[idx]);
            (**curDynEntityList)[idx] = NULL;
        }
    }
}

DynamicEntity* get_generic_entity(s32 idx) {
    return (*gCurrentDynamicEntityListPtr)[idx & ~0x800];
}
