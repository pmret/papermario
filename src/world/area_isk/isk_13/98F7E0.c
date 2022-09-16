#include "isk_13.h"
#include "sprite.h"
#include "sprite/npc/stone_chomp.h"

static char* N(exit_str_0) = "isk_12";
static char* N(exit_str_1) = "";

#include "world/common/enemy/StoneChompAI.inc.c"

#include "world/area_isk/StoneChompFX.inc.c"

typedef struct StoneChompAmbushIsk13 {
    /* 0x00 */ s32 useBitingAnim;
    /* 0x04 */ s32 foldID;
    /* 0x08 */ s32 workerID;
    /* 0x0C */ s32 spriteIndex;
    /* 0x10 */ s32 rasterIndex;
    /* 0x14 */ Vec3f pos;
    /* 0x20 */ Vec3f rot;
    /* 0x2C */ Vec3f scale;
    /* 0x38 */ f32 renderYaw;
    /* 0x3C */ Color4f color;
    /* 0x4C */ f32 width;
    /* 0x50 */ f32 height;
} StoneChompAmbushIsk13; // size = 0x54

void func_80241610_990DF0(void) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(NULL, MapVar(10));
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
    
    if (ambush->useBitingAnim) {
        if ((gGameStatusPtr->frameCounter % 10) < 5) {
            ambush->rasterIndex = 0;
        } else {
            ambush->rasterIndex = 2;
        }
    }
    spr_get_npc_raster_info(&spriteRaster, ambush->spriteIndex, ambush->rasterIndex);
    foldImg.raster  = spriteRaster.raster;
    foldImg.palette = spriteRaster.defaultPal;
    ambush->width = foldImg.width  = spriteRaster.width;
    ambush->height = foldImg.height = spriteRaster.height;
    foldImg.xOffset = -(spriteRaster.width / 2);
    foldImg.yOffset = (spriteRaster.height / 2);
    foldImg.opacity = 255;
    
    fold_update(ambush->foldID, FOLD_TYPE_8, ambush->color.r, ambush->color.g, ambush->color.b, ambush->color.a, 0);
    fold_appendGfx_component(ambush->foldID, &foldImg, 0, transformMtx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus func_80241BA8_991388(Evt* script, s32 isInitialCall) {
    StoneChompAmbushIsk13* ambush;
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    ambush = heap_malloc(sizeof(*ambush));
    ambush->useBitingAnim = FALSE;
    ambush->spriteIndex = 0x35; //TODO get spriteID for this constant
    ambush->rasterIndex = 0;
    spr_get_npc_raster_info(&rasterInfo, ambush->spriteIndex, ambush->rasterIndex);
    ambush->width = rasterInfo.width;
    ambush->height = rasterInfo.height;

    ambush->pos.x = npc->pos.x;
    ambush->pos.y = npc->pos.y + (ambush->height * SPRITE_WORLD_SCALE_D * 0.5);
    ambush->pos.z = npc->pos.z;
    ambush->rot.x = 0.0f;
    ambush->rot.y = 0.0f;
    ambush->rot.z = 90.0f;
    ambush->scale.x = SPRITE_WORLD_SCALE_F;
    ambush->scale.y = SPRITE_WORLD_SCALE_F;
    ambush->scale.z = SPRITE_WORLD_SCALE_F;
    ambush->renderYaw = 60.0f;
    ambush->color.r = 255.0f;
    ambush->color.g = 128.0f;
    ambush->color.b = 255.0f;
    ambush->color.a = 0.0f;
    ambush->foldID = 0;
    
    ambush->workerID = create_generic_entity_frontUI(NULL, func_80241610_990DF0);
    evt_set_variable(script, MapVar(10), (s32) ambush);
    return ApiStatus_DONE2;
}

ApiStatus func_80241D08_9914E8(Evt* script, s32 isInitialCall) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MapVar(10));
    free_generic_entity(ambush->workerID);
    return ApiStatus_DONE2;
}

ApiStatus func_80241D38_991518(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MapVar(10));
    
    ambush->pos.x = x;
    ambush->pos.y = y + ambush->height * SPRITE_WORLD_SCALE_D * 0.5;
    ambush->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80241E34_991614(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MapVar(10));
    
    ambush->rot.x = x;
    ambush->rot.y = y;
    ambush->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80241EF8_9916D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MapVar(10));
    f32 r = evt_get_float_variable(script, *args++);
    f32 g = evt_get_float_variable(script, *args++);
    f32 b = evt_get_float_variable(script, *args++);
    f32 a = evt_get_float_variable(script, *args++);
    
    if (r < 0.0f) {
        r = 0.0f;
    }
    if (g < 0.0f) {
        g = 0.0f;
    }
    if (b < 0.0f) {
        b = 0.0f;
    }
    if (a < 0.0f) {
        a = 0.0f;
    }
    if (r > 255.0f) {
        r = 255.0f;
    }
    if (g > 255.0f) {
        g = 255.0f;
    }
    if (b > 255.0f) {
        b = 255.0f;
    }
    if (a > 255.0f) {
        a = 255.0f;
    }
    ambush->color.r = r;
    ambush->color.g = g;
    ambush->color.b = b;
    ambush->color.a = a;
    return ApiStatus_DONE2;
}

ApiStatus func_80242044_991824(Evt* script, s32 isInitialCall) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MapVar(10));
    ambush->useBitingAnim = TRUE;
    return ApiStatus_DONE2;
}
