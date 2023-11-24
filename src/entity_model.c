#include "common.h"
#include "entity.h"

EntityModelScript D_8014C260 = {
    ems_End
    ems_End
};
Lights1 D_8014C268 = gdSPDefLights1(255, 255, 255, 0, 0, 0, 0, 0, 0);

SHIFT_BSS EntityModelList gWorldEntityModelList;
SHIFT_BSS EntityModelList gBattleEntityModelList;
SHIFT_BSS EntityModelList* gCurrentEntityModelList;
SHIFT_BSS s32 gEntityModelCount;

SHIFT_BSS s32 D_80154374;
SHIFT_BSS s32 entity_fog_enabled;
SHIFT_BSS s32 entity_fog_red;
SHIFT_BSS s32 entity_fog_green;
SHIFT_BSS s32 entity_fog_blue;
SHIFT_BSS s32 entity_fog_alpha;
SHIFT_BSS s32 entity_fog_dist_min;
SHIFT_BSS s32 entity_fog_dist_max;

extern Gfx Gfx_RM1_SURFACE_OPA[];
extern Gfx Gfx_RM1_DECAL_OPA[];
extern Gfx Gfx_RM1_INTERSECTING_OPA[];
extern Gfx Gfx_RM1_ALPHATEST[];
extern Gfx Gfx_RM1_SURFACE_XLU[];
extern Gfx Gfx_RM1_DECAL_XLU[];
extern Gfx Gfx_RM1_INTERSECTING_XLU[];
extern Gfx Gfx_RM1_ALPHATEST_ONESIDED[];
extern Gfx Gfx_RM1_SURFACE_XLU_NO_AA[];
extern Gfx Gfx_RM1_DECAL_XLU_NO_AA[];
extern Gfx Gfx_RM1_PASS_THROUGH[];
extern Gfx Gfx_RM1_SURFACE_OPA_NO_ZB[];
extern Gfx Gfx_RM1_ALPHATEST_NO_ZB[];
extern Gfx Gfx_RM1_SURFACE_XLU_NO_ZB[];
extern Gfx Gfx_RM1_CLOUD_NO_ZCMP[];
extern Gfx Gfx_RM3_SURFACE_OPA[];
extern Gfx Gfx_RM3_DECAL_OPA[];
extern Gfx Gfx_RM3_INTERSECTING_OPA[];
extern Gfx Gfx_RM3_ALPHATEST[];
extern Gfx Gfx_RM3_SURFACE_XLU[];
extern Gfx Gfx_RM3_DECAL_XLU[];
extern Gfx Gfx_RM3_INTERSECTING_XLU[];

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

    gEntityModelCount = 0;
    entity_fog_enabled = 0;
    entity_fog_red = 10;
    entity_fog_green = 10;
    entity_fog_blue = 10;
    entity_fog_alpha = 10; 
    entity_fog_dist_min = 800;
    entity_fog_dist_max = 1000;
}

void init_entity_models(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentEntityModelList = &gWorldEntityModelList;
    } else {
        gCurrentEntityModelList = &gBattleEntityModelList;
    }

    gEntityModelCount = 0;
    entity_fog_enabled = 0;
    entity_fog_red = 10;
    entity_fog_green = 10;
    entity_fog_blue = 10;
    entity_fog_alpha = 10;
    entity_fog_dist_min = 800;
    entity_fog_dist_max = 1000;
}

s32 load_entity_model(EntityModelScript* cmdList) {
    EntityModel* newEntityModel;
    s32* entityModelCount;
    s32 i;

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        if ((*gCurrentEntityModelList)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ENTITY_MODELS);

    (*gCurrentEntityModelList)[i] = newEntityModel = heap_malloc(sizeof(*newEntityModel));
    entityModelCount = &gEntityModelCount;
    (*entityModelCount)++;
    
    ASSERT(newEntityModel != NULL);

    newEntityModel->flags = (ENTITY_MODEL_FLAG_CAM0 | ENTITY_MODEL_FLAG_CAM1 | ENTITY_MODEL_FLAG_CAM2 | ENTITY_MODEL_FLAG_ENABLED);
    newEntityModel->renderMode = 1;
    newEntityModel->gfx.displayList = NULL;
    newEntityModel->cmdListReadPos = cmdList;
    newEntityModel->nextFrameTime = 1.0f;
    newEntityModel->timeScale = 1.0f;
    if (cmdList == NULL) {
        newEntityModel->cmdListReadPos = &D_8014C260;
    }
    newEntityModel->vertexArray = NULL;
    newEntityModel->fpSetupGfxCallback = NULL;
    newEntityModel->cmdListSavedPos = newEntityModel->cmdListReadPos;

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_BIT;
    }
    return i;
}

s32 ALT_load_entity_model(EntityModelScript* cmdList) {
    EntityModel* newEntityModel;
    SpriteRasterInfo* imageData;
    s32 i;

    for (i = 0; i < MAX_ENTITY_MODELS; i++) {
        if ((*gCurrentEntityModelList)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_ENTITY_MODELS);

    {
        s32* entityModelCount;
        (*gCurrentEntityModelList)[i] = newEntityModel = heap_malloc(sizeof(*newEntityModel));
        entityModelCount = &gEntityModelCount;
        (*entityModelCount)++;
    }

    ASSERT(newEntityModel != NULL);

    newEntityModel->gfx.imageData = imageData = heap_malloc(sizeof(*imageData));
    ASSERT(imageData != NULL);

    newEntityModel->flags = (ENTITY_MODEL_FLAG_CAM0 | ENTITY_MODEL_FLAG_CAM1 | ENTITY_MODEL_FLAG_CAM2 | ENTITY_MODEL_FLAG_ENABLED | ENTITY_MODEL_FLAG_USE_IMAGE);
    newEntityModel->renderMode = 1;
    newEntityModel->cmdListReadPos = cmdList;
    newEntityModel->nextFrameTime = 1.0f;
    newEntityModel->timeScale = 1.0f;
    if (cmdList == NULL) {
        newEntityModel->cmdListReadPos = &D_8014C260;
    }
    newEntityModel->vertexArray = NULL;
    newEntityModel->fpSetupGfxCallback = NULL;
    newEntityModel->cmdListSavedPos = newEntityModel->cmdListReadPos;

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_BIT;
    }
    return i;
}

void exec_entity_model_commandlist(s32 idx) {
    EntityModel* entityModel;

    if (!gGameStatusPtr->isBattle || (idx & BATTLE_ENTITY_ID_BIT)) {
        idx &= ~BATTLE_ENTITY_ID_BIT;
        entityModel = (*gCurrentEntityModelList)[idx];
        if (entityModel != NULL && (entityModel->flags)) {
            if (!(entityModel->flags & ENTITY_MODEL_FLAG_HIDDEN)) {
                if (!(entityModel->flags & ENTITY_MODEL_FLAG_DISABLE_SCRIPT)) {
                    entityModel->flags &= ~ENTITY_MODEL_FLAG_100;
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
    SpriteRasterInfo* imageData;

    u32* curPos = *entityModel->cmdListReadPos;
    switch (*curPos++) {
        case ENTITY_MODEL_SCRIPT_OP_End: // kill model
            free_entity_model_by_ref(entityModel);
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_Draw: // set display list ptr
            entityModel->nextFrameTime = (f32) *curPos++;
            entityModel->gfx.displayList = (Gfx*) *curPos++;
            entityModel->cmdListReadPos = (EntityModelScript*) curPos;
            break;
        case ENTITY_MODEL_SCRIPT_OP_Restart: // restore saved position
            entityModel->cmdListReadPos = entityModel->cmdListSavedPos;
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_Loop: // set saved position
            entityModel->cmdListReadPos = entityModel->cmdListSavedPos = (EntityModelScript*) curPos;
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_SetRenderMode: // set render mode
            entityModel->renderMode = *curPos++;
            entityModel->cmdListReadPos = (EntityModelScript*) curPos;
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_SetFlags: // set flags
            entityModel->flags |= *curPos++;
            entityModel->cmdListReadPos = (EntityModelScript*) curPos;
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_ClearFlags: // clear flags
            entityModel->flags &= ~*curPos++;
            entityModel->cmdListReadPos = (EntityModelScript*) curPos;
            return 1;
        case ENTITY_MODEL_SCRIPT_OP_DrawImage: // set image data
            imageData = entityModel->gfx.imageData;
            entityModel->nextFrameTime = *curPos++;
            imageData->raster = (u8*)*curPos++;
            imageData->defaultPal = (PAL_PTR) *curPos++;
            imageData->width = *curPos++;
            imageData->height = *curPos++;
            entityModel->cmdListReadPos = (EntityModelScript*) curPos;
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

void appendGfx_entity_model(EntityModel* model) {
    Matrix4f mtx;
    Matrix4f mtx2;
    ImgFXTexture ifxImg;
    Matrix4f imgfxMtx;

    gDisplayContext->matrixStack[gMatrixListPos] = model->transform;
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (!(model->flags & ENTITY_MODEL_FLAG_USE_IMAGE)) {
        if (!(model->flags & ENTITY_MODEL_FLAG_10000)) {
            gDPPipeSync(gMainGfxPos++);
            gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, 255);
            gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
            gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE);

            switch (entity_fog_enabled && !(model->flags & ENTITY_MODEL_FLAG_FOG_DISABLED)) {
                case FALSE:
                    switch (model->renderMode) {
                        case RENDER_MODE_SURFACE_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_OPA);
                            break;
                        case RENDER_MODE_DECAL_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_OPA);
                            break;
                        case RENDER_MODE_INTERSECTING_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_OPA);
                            break;
                        case RENDER_MODE_ALPHATEST:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST);
                            break;
                        case RENDER_MODE_SURFACE_XLU_LAYER1:
                        case RENDER_MODE_SURFACE_XLU_LAYER2:
                        case RENDER_MODE_SURFACE_XLU_LAYER3:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU);
                            break;
                        case RENDER_MODE_SURFACE_XLU_NO_AA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU_NO_AA);
                            break;
                        case RENDER_MODE_DECAL_XLU:
                        case RENDER_MODE_DECAL_XLU_AHEAD:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_XLU);
                            break;
                        case RENDER_MODE_DECAL_XLU_NO_AA:
                        case RENDER_MODE_SHADOW:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_XLU_NO_AA);
                            break;
                        case RENDER_MODE_INTERSECTING_XLU:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_XLU);
                            break;
                        case RENDER_MODE_PASS_THROUGH:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_PASS_THROUGH);
                            break;
                        case RENDER_MODE_ALPHATEST_ONESIDED:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST_ONESIDED);
                            break;
                        case RENDER_MODE_SURFACE_OPA_NO_ZB:
                        case RENDER_MODE_SURFACE_OPA_NO_ZB_BEHIND:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_OPA_NO_ZB);
                            break;
                        case RENDER_MODE_ALPHATEST_NO_ZB:
                        case RENDER_MODE_ALPHATEST_NO_ZB_BEHIND:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST_NO_ZB);
                            break;
                        case RENDER_MODE_SURFACE_XLU_NO_ZB:
                        case RENDER_MODE_SURFACE_XLU_NO_ZB_BEHIND:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU_NO_ZB);
                            break;
                        case RENDER_MODE_CLOUD_NO_ZCMP:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM1_CLOUD_NO_ZCMP);
                            break;
                    }
                    break;
                case TRUE:
                    switch (model->renderMode) {
                        case RENDER_MODE_SURFACE_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_OPA);
                            break;
                        case RENDER_MODE_DECAL_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_OPA);
                            break;
                        case RENDER_MODE_INTERSECTING_OPA:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_OPA);
                            break;
                        case RENDER_MODE_ALPHATEST:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_ALPHATEST);
                            break;
                        case RENDER_MODE_SURFACE_XLU_LAYER1:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_XLU);
                            break;
                        case RENDER_MODE_DECAL_XLU:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_XLU);
                            break;
                        case RENDER_MODE_INTERSECTING_XLU:
                            gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_XLU);
                            break;
                    }
                    gDPSetFogColor(gMainGfxPos++, entity_fog_red, entity_fog_green, entity_fog_blue, entity_fog_alpha);
                    gSPFogPosition(gMainGfxPos++, entity_fog_dist_min, entity_fog_dist_max);
                    break;
            }
            gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
            if (!entity_fog_enabled || (model->flags & ENTITY_MODEL_FLAG_FOG_DISABLED)) {
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
            } else {
                gDPSetCombineMode(gMainGfxPos++, PM_CC_42, PM_CC_18);
            }
        }
        if (model->vertexArray != NULL) {
            gSPSegment(gMainGfxPos++, D_80154374, VIRTUAL_TO_PHYSICAL(model->vertexArray));
        }
        gDPPipeSync(gMainGfxPos++);

        if (model->fpSetupGfxCallback != NULL) {
            model->fpSetupGfxCallback(model->setupGfxCallbackArg0);
        }
        gDPPipeSync(gMainGfxPos++);

        gSPDisplayList(gMainGfxPos++, model->gfx.displayList);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMainGfxPos++);

        if (!(model->flags & ENTITY_MODEL_FLAG_REFLECT)) {
            return;
        }

        guMtxL2F(mtx, &model->transform);
        make_entity_model_mtx_flipZ(mtx2);
        guMtxCatF(mtx, mtx2, mtx);
        guMtxF2L(mtx, &model->transform);
        gDisplayContext->matrixStack[gMatrixListPos] = model->transform;
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, model->gfx.displayList);
    } else {
        SpriteRasterInfo* imageData;

        gDPPipeSync(gMainGfxPos++);
        gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
        gSPSetLights1(gMainGfxPos++, D_8014C268);
        gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
        gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

        imageData = model->gfx.imageData;
        ifxImg.raster = imageData->raster;
        ifxImg.palette = imageData->defaultPal;
        ifxImg.width = imageData->width;
        ifxImg.height = imageData->height;
        ifxImg.xOffset = -imageData->width / 2;
        ifxImg.yOffset = imageData->height / 2;
        ifxImg.alpha = 255;
        guMtxL2F(imgfxMtx, &model->transform);
        imgfx_appendGfx_component(0, &ifxImg, 0, imgfxMtx);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}


void draw_entity_model_A(s32 modelIdx, Mtx* transformMtx) {
    EntityModel* model;
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Camera* camera = &gCameras[gCurrentCamID];
    Matrix4f mtx;
    f32 x, y, z, w;
    f32 inX, inY, inZ;

    if ((!gGameStatusPtr->isBattle) || (modelIdx & BATTLE_ENTITY_ID_BIT)) {
        modelIdx &= ~BATTLE_ENTITY_ID_BIT;
        model = (*gCurrentEntityModelList)[modelIdx];

        if (model != NULL) {
            if (model->flags != 0) {
                if (!(model->flags & ENTITY_MODEL_FLAG_100)) {
                    if (!(model->flags & ENTITY_MODEL_FLAG_HIDDEN)) {
                        if (!(model->flags & ENTITY_MODEL_FLAG_40) && (model->flags & (1 << gCurrentCamID))) {
                            model->transform = *transformMtx;
                            model->vertexArray = NULL;
                            guMtxL2F(mtx, transformMtx);
                            inX = mtx[3][0];
                            inY = mtx[3][1];
                            inZ = mtx[3][2];
                            transform_point(camera->perspectiveMatrix, inX, inY, inZ, 1.0f, &x, &y, &z, &w);
                            rtPtr->renderMode = model->renderMode;
                            rtPtr->appendGfxArg = model;
                            rtPtr->appendGfx = (void(*)(void*))appendGfx_entity_model;
                            rtPtr->dist = ((u32)(model->flags & 0xF000) >> 8) + inZ;
                            queue_render_task(rtPtr);
                        }
                    }
                }
            }
        }
    }
}

void draw_entity_model_B(s32 modelIdx, Mtx* transformMtx, s32 vertexSegment, Vec3s* vertexArray) {
    EntityModel* model;
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Camera* camera = &gCameras[gCurrentCamID];
    Matrix4f mtx;
    f32 x, y, z, w;
    f32 inX, inY, inZ;

    if ((!gGameStatusPtr->isBattle) || (modelIdx & BATTLE_ENTITY_ID_BIT)) {
        modelIdx &= ~BATTLE_ENTITY_ID_BIT;
        model = (*gCurrentEntityModelList)[modelIdx];

        if (model != NULL) {
            if (model->flags != 0) {
                if (!(model->flags & ENTITY_MODEL_FLAG_100)) {
                    if (!(model->flags & ENTITY_MODEL_FLAG_HIDDEN)) {
                        if (model->flags & (1 << gCurrentCamID)) {
                            model->transform = *transformMtx;
                            D_80154374 = vertexSegment;
                            model->vertexArray = vertexArray;
                            guMtxL2F(mtx, transformMtx);
                            inX = mtx[3][0];
                            inY = mtx[3][1];
                            inZ = mtx[3][2];
                            transform_point(camera->perspectiveMatrix, inX, inY, inZ, 1.0f, &x, &y, &z, &w);
                            rtPtr->renderMode = model->renderMode;
                            rtPtr->appendGfxArg = model;
                            rtPtr->appendGfx = (void(*)(void*))appendGfx_entity_model;
                            rtPtr->dist = ((u32)(model->flags & 0xF000) >> 8) + inZ;
                            queue_render_task(rtPtr);
                        }
                    }
                }
            }
        }
    }
}

void draw_entity_model_C(s32 modelIdx, Mtx* transformMtx) {
    EntityModel* model;
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if ((!gGameStatusPtr->isBattle) || (modelIdx & BATTLE_ENTITY_ID_BIT)) {
        modelIdx &= ~BATTLE_ENTITY_ID_BIT;
        model = (*gCurrentEntityModelList)[modelIdx];

        if (model != NULL) {
            if (model->flags != 0) {
                if (!(model->flags & ENTITY_MODEL_FLAG_100)) {
                    if (!(model->flags & ENTITY_MODEL_FLAG_HIDDEN)) {
                        if (!(model->flags & ENTITY_MODEL_FLAG_40) && (model->flags & (1 << gCurrentCamID))) {
                            model->flags |= ENTITY_MODEL_FLAG_REFLECT;
                            model->transform = *transformMtx;
                            model->vertexArray = NULL;
                            rtPtr->renderMode = model->renderMode;
                            rtPtr->appendGfxArg = model;
                            rtPtr->appendGfx = (void(*)(void*))appendGfx_entity_model;
                            rtPtr->dist = (u32)(model->flags & 0xF000) >> 8;
                            queue_render_task(rtPtr);
                        }
                    }
                }
            }
        }
    }
}

void draw_entity_model_D(s32 modelIdx, Mtx* transformMtx, s32 arg2, Vec3s* vertexArray) {
    EntityModel* model;
    RenderTask rt;
    RenderTask* rtPtr = &rt;

    if ((!gGameStatusPtr->isBattle) || (modelIdx & BATTLE_ENTITY_ID_BIT)) {
        modelIdx &= ~BATTLE_ENTITY_ID_BIT;
        model = (*gCurrentEntityModelList)[modelIdx];

        if (model != NULL) {
            if (model->flags != 0) {
                if (!(model->flags & ENTITY_MODEL_FLAG_100)) {
                    if (!(model->flags & ENTITY_MODEL_FLAG_HIDDEN)) {
                        if (model->flags & (1 << gCurrentCamID)) {
                            model->flags |= ENTITY_MODEL_FLAG_REFLECT;
                            model->transform = *transformMtx;
                            D_80154374 = arg2;
                            model->vertexArray = vertexArray;
                            rtPtr->renderMode = model->renderMode;
                            rtPtr->appendGfxArg = model;
                            rtPtr->appendGfx = (void(*)(void*))appendGfx_entity_model;
                            rtPtr->dist = (u32)(model->flags & 0xF000) >> 8;
                            queue_render_task(rtPtr);
                        }
                    }
                }
            }
        }
    }
}

void draw_entity_model_E(s32 modelIdx, Mtx* transformMtx) {
    EntityModel* model = (*gCurrentEntityModelList)[modelIdx & ~BATTLE_ENTITY_ID_BIT];
    Matrix4f mtx;
    Matrix4f mtx2;
    ImgFXTexture ifxImg;
    Matrix4f imgfxMtx;

    if (model == NULL) {
        return;
    }
    if (model->flags == 0) {
        return;
    }
    if (model->flags & ENTITY_MODEL_FLAG_100) {
        return;
    }
    if (model->flags & ENTITY_MODEL_FLAG_HIDDEN) {
        return;
    }
    if (model->flags & ENTITY_MODEL_FLAG_40) {
        return;
    }
    if (!(model->flags & ENTITY_MODEL_FLAG_CAM3)) {
        return;
    }

    model->transform = *transformMtx;
    model->vertexArray = NULL;
    gDisplayContext->matrixStack[gMatrixListPos] = model->transform;
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (!(model->flags & ENTITY_MODEL_FLAG_USE_IMAGE)) {
        switch (entity_fog_enabled && !(model->flags & ENTITY_MODEL_FLAG_FOG_DISABLED)) {
            case FALSE:
                switch (model->renderMode) {
                    case RENDER_MODE_SURFACE_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_OPA);
                        break;
                    case RENDER_MODE_DECAL_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_OPA);
                        break;
                    case RENDER_MODE_INTERSECTING_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_OPA);
                        break;
                    case RENDER_MODE_ALPHATEST:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST);
                        break;
                    case RENDER_MODE_SURFACE_XLU_LAYER1:
                    case RENDER_MODE_SURFACE_XLU_LAYER2:
                    case RENDER_MODE_SURFACE_XLU_LAYER3:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU);
                        break;
                    case RENDER_MODE_SURFACE_XLU_NO_AA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU_NO_AA);
                        break;
                    case RENDER_MODE_DECAL_XLU:
                    case RENDER_MODE_DECAL_XLU_AHEAD:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_XLU);
                        break;
                    case RENDER_MODE_DECAL_XLU_NO_AA:
                    case RENDER_MODE_SHADOW:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_DECAL_XLU_NO_AA);
                        break;
                    case RENDER_MODE_INTERSECTING_XLU:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_INTERSECTING_XLU);
                        break;
                    case RENDER_MODE_PASS_THROUGH:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_PASS_THROUGH);
                        break;
                    case RENDER_MODE_ALPHATEST_ONESIDED:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST_ONESIDED);
                        break;
                    case RENDER_MODE_SURFACE_OPA_NO_ZB:
                    case RENDER_MODE_SURFACE_OPA_NO_ZB_BEHIND:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_OPA_NO_ZB);
                        break;
                    case RENDER_MODE_ALPHATEST_NO_ZB:
                    case RENDER_MODE_ALPHATEST_NO_ZB_BEHIND:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_ALPHATEST_NO_ZB);
                        break;
                    case RENDER_MODE_SURFACE_XLU_NO_ZB:
                    case RENDER_MODE_SURFACE_XLU_NO_ZB_BEHIND:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_SURFACE_XLU_NO_ZB);
                        break;
                    case RENDER_MODE_CLOUD_NO_ZCMP:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM1_CLOUD_NO_ZCMP);
                        break;
                }
                break;
            case TRUE:
                switch (model->renderMode) {
                    case RENDER_MODE_SURFACE_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_OPA);
                        break;
                    case RENDER_MODE_DECAL_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_OPA);
                        break;
                    case RENDER_MODE_INTERSECTING_OPA:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_OPA);
                        break;
                    case RENDER_MODE_ALPHATEST:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_ALPHATEST);
                        break;
                    case RENDER_MODE_SURFACE_XLU_LAYER1:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_SURFACE_XLU);
                        break;
                    case RENDER_MODE_DECAL_XLU:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_DECAL_XLU);
                        break;
                    case RENDER_MODE_INTERSECTING_XLU:
                        gSPDisplayList(gMainGfxPos++, Gfx_RM3_INTERSECTING_XLU);
                        break;
                }
                gDPSetFogColor(gMainGfxPos++, entity_fog_red, entity_fog_green, entity_fog_blue, entity_fog_alpha);
                gSPFogPosition(gMainGfxPos++, entity_fog_dist_min, entity_fog_dist_max);
                break;
        }
        gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
        if (!entity_fog_enabled || (model->flags & ENTITY_MODEL_FLAG_FOG_DISABLED)) {
            gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        } else {
            gDPSetCombineMode(gMainGfxPos++, PM_CC_42, PM_CC_18);
        }
        if (model->vertexArray != NULL) {
            gSPSegment(gMainGfxPos++, D_80154374, VIRTUAL_TO_PHYSICAL(model->vertexArray));
        }
        gSPDisplayList(gMainGfxPos++, model->gfx.displayList);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMainGfxPos++);
        if (!(model->flags & ENTITY_MODEL_FLAG_REFLECT)) {
            return;
        }

        guMtxL2F(mtx, &model->transform);
        make_entity_model_mtx_flipZ(mtx2);
        guMtxCatF(mtx, mtx2, mtx);
        guMtxF2L(mtx, &model->transform);
        gDisplayContext->matrixStack[gMatrixListPos] = model->transform;
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, model->gfx.displayList);
    } else {
        SpriteRasterInfo* imageData;

        gDPPipeSync(gMainGfxPos++);
        gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
        gSPSetLights1(gMainGfxPos++, D_8014C268);
        gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
        gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

        imageData = model->gfx.imageData;
        ifxImg.raster = imageData->raster;
        ifxImg.palette = imageData->defaultPal;
        ifxImg.width = imageData->width;
        ifxImg.height = imageData->height;
        ifxImg.xOffset = -imageData->width / 2;
        ifxImg.yOffset = imageData->height / 2;
        ifxImg.alpha = 255;
        guMtxL2F(imgfxMtx, &model->transform);
        imgfx_appendGfx_component(0, &ifxImg, 0, imgfxMtx);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

void set_entity_model_render_command_list(s32 idx, EntityModelScript* cmdList) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    if (entityModel != NULL && entityModel->flags) {
        if (cmdList == NULL) {
            cmdList = &D_8014C260;
        }
        entityModel->cmdListReadPos = cmdList;
        entityModel->cmdListSavedPos = cmdList;
        entityModel->nextFrameTime = 1.0f;
        entityModel->timeScale = 1.0f;
    }
}

EntityModel* get_entity_model(s32 listIndex) {
    return (*gCurrentEntityModelList)[listIndex & ~BATTLE_ENTITY_ID_BIT];
}

void free_entity_model_by_index(s32 idx) {
    s32 index = idx & ~BATTLE_ENTITY_ID_BIT;
    EntityModel* entityModel = (*gCurrentEntityModelList)[index];

    if (entityModel != NULL && entityModel->flags) {
        if (entityModel->flags & ENTITY_MODEL_FLAG_USE_IMAGE) {
            heap_free(entityModel->gfx.imageData);
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
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    if (entityModel != NULL && entityModel->flags) {
        entityModel->flags |= newFlags;
    }
}

void clear_entity_model_flags(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    if (entityModel != NULL && entityModel->flags) {
        entityModel->flags &= ~newFlags;
    }
}

void bind_entity_model_setupGfx(s32 idx, void* setupGfxCallbackArg0, void (*fpSetupGfxCallback)(void*)) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    entityModel->fpSetupGfxCallback = fpSetupGfxCallback;
    entityModel->setupGfxCallbackArg0 = setupGfxCallbackArg0;
}

void func_80122F8C(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    entityModel->flags |= newFlags;
}

void func_80122FB8(s32 idx, s32 newFlags) {
    EntityModel* entityModel = (*gCurrentEntityModelList)[idx & ~BATTLE_ENTITY_ID_BIT];

    entityModel->flags = (entityModel->flags & ~(ENTITY_MODEL_FLAG_CAM0 | ENTITY_MODEL_FLAG_CAM1 | ENTITY_MODEL_FLAG_CAM2 | ENTITY_MODEL_FLAG_CAM3)) | newFlags;
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
