#include "isk_14.h"
#include "sprite.h"
#include "sprite/npc/stone_chomp.h"

static char* N(exit_str_0) = "isk_10";
static char* N(exit_str_1) = "";

#include "world/common/enemy/StoneChompAI.inc.c"

#include "world/area_isk/StoneChompFX.inc.c"

typedef struct StoneChompAmbushIsk14 {
    /* 0x00 */ s32 foldID;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ s32 spriteIndex;
    /* 0x0C */ s32 rasterIndex;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
    /* 0x34 */ f32 renderYaw;
    /* 0x38 */ f32 width;
    /* 0x3C */ f32 height;
} StoneChompAmbushIsk14; // size = 0x40

static StoneChompAmbushIsk14 N(ChompAmbush);

void func_80241610_993D40(void) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);
    Camera* cam = &gCameras[gCurrentCameraID];
    FoldImageRecPart foldImg;
    SpriteRasterInfo spriteRaster;
    Matrix4f transformMtx, tempMtx;

    gSPViewport(gMasterGfxPos++, &cam->vp);
    if (!(cam->flags & CAMERA_FLAGS_10)) {
        gSPPerspNormalize(gMasterGfxPos++, cam->perspNorm);
    }
    guMtxF2L(cam->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCameraID]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
        G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING
        | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    
    guTranslateF(transformMtx, ambush->pos.x, ambush->pos.y, ambush->pos.z);
    guRotateF(tempMtx, ambush->rot.y + gCameras[gCurrentCameraID].currentYaw + ambush->renderYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, ambush->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, ambush->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF(tempMtx, ambush->scale.x, ambush->scale.y, ambush->scale.z);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    spr_get_npc_raster_info(&spriteRaster, ambush->spriteIndex, ambush->rasterIndex);
    foldImg.raster  = spriteRaster.raster;
    foldImg.palette = spriteRaster.defaultPal;
    ambush->width  = foldImg.width  = spriteRaster.width;
    ambush->height = foldImg.height = spriteRaster.height;
    foldImg.xOffset = -(spriteRaster.width / 2);
    foldImg.yOffset = spriteRaster.height;
    foldImg.opacity = 255;
    
    fold_appendGfx_component(ambush->foldID, &foldImg, 0, transformMtx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus func_80241AF0_994220(Evt* script, s32 isInitialCall) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    ambush->spriteIndex = 53; //TODO get spriteID for this constant
    ambush->rasterIndex = 0;
    spr_get_npc_raster_info(&rasterInfo, ambush->spriteIndex, ambush->rasterIndex);
    ambush->width = rasterInfo.width;
    ambush->height  = rasterInfo.height;

    ambush->pos.x = npc->pos.x;
    ambush->pos.y = npc->pos.y;
    ambush->pos.z = npc->pos.z;
    ambush->rot.x = 0;
    ambush->rot.y = 0;
    ambush->rot.z = 0;
    ambush->scale.x = SPRITE_WORLD_SCALE_F;
    ambush->scale.y = SPRITE_WORLD_SCALE_F;
    ambush->scale.z = SPRITE_WORLD_SCALE_F;
    ambush->renderYaw = 270.0f;

    ambush->foldID = 0;
    ambush->workerID = create_generic_entity_frontUI(NULL, func_80241610_993D40);
    return ApiStatus_DONE2;
}

ApiStatus func_80241BC4_9942F4(Evt* script, s32 isInitialCall) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);

    free_generic_entity(ambush->workerID);
    return ApiStatus_DONE2;
}

ApiStatus func_80241BEC_99431C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);

    ambush->pos.x = x;
    ambush->pos.y = y;
    ambush->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80241CA0_9943D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);

    ambush->rot.x = x;
    ambush->rot.y = y;
    ambush->rot.z = z;
    return ApiStatus_DONE2;
}
