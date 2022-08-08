#include "isk_05.h"
#include "sprite.h"

static char* N(exit_str_0) = "isk_04";
static char* N(exit_str_1) = "";

extern StoneChompBlur N(ChompBlur);

void func_80241610_97F0E0(void);

#include "world/common/enemy/StoneChompAI.inc.c"

#include "world/common/UnkFunc53.inc.c"

ApiStatus func_802411F8_97ECC8(Evt* script, s32 isInitialCall) {
    NPCBlurUnk* blurData;
    Npc* ownerNpc;
    Npc* childNpc;
    f32 posX, posY, posZ;
    f32 nextX, nextY, nextZ;
    f32 invDist;
    f32 floorY;
    s32 i;

    floorY = (f32) script->owner1.enemy->varTable[0];
    ownerNpc = get_npc_safe(script->owner2.npcID);
    blurData = (NPCBlurUnk*) ownerNpc->blurBuf;
    posX = ownerNpc->pos.x;
    posY = ownerNpc->pos.y + (ownerNpc->collisionHeight * 0.2f);
    posZ = ownerNpc->pos.z;
    add_vec2D_polar(&posX, &posZ, ownerNpc->collisionRadius * 0.3f, clamp_angle(ownerNpc->renderYaw + 180.0f));
    
    if (ownerNpc->flags & 2) {
        for (i = 0; i < 8; i++, blurData++) {
            childNpc = blurData->unk_00;
            childNpc->pos.x = posX;
            childNpc->pos.y = posY;
            childNpc->pos.z = posZ;
        }
        return ApiStatus_BLOCK;
    }
    
    for (i = 0; i < 8; i++, blurData++) {
        childNpc = blurData->unk_00;
        if (dist3D(childNpc->pos.x, childNpc->pos.y, childNpc->pos.z, posX, posY, posZ) >= 10.0) {
            invDist = 10.0 / dist3D(
                ((childNpc->pos.x - posX) * 0.8f) + posX, childNpc->pos.y, ((childNpc->pos.z - posZ) * 0.8f) + posZ,
                posX, posY,posZ);

            nextX = posX = ((childNpc->pos.x - posX) * 0.8f * invDist) + posX;
            nextY = posY = ((childNpc->pos.y - posY) * invDist) + posY;
            nextZ = posZ = ((childNpc->pos.z - posZ) * 0.8f * invDist) + posZ;

            blurData->offset.x = (nextX - childNpc->pos.x) * 0.7f;
            blurData->offset.y = (nextY - childNpc->pos.y) * 0.7f;
            blurData->offset.z = (nextZ - childNpc->pos.z) * 0.7f;
            
            childNpc->pos.x = nextX;
            childNpc->pos.y = nextY;
            childNpc->pos.z = nextZ;
            
            if (blurData->offset.y > 10.0f) {
                blurData->offset.y = 10.0f;
            }
        } else {
            blurData->offset.x = blurData->offset.x * 0.9f;
            blurData->offset.z = blurData->offset.z * 0.9f;
            childNpc->pos.x += blurData->offset.x;
            childNpc->pos.z += blurData->offset.z;
        }
        
        blurData->offset.y -= 1.0f;
        if (blurData->offset.y < -10.0f) {
            blurData->offset.y = -10.0f;
        }
        childNpc->pos.y += blurData->offset.y;
        if (childNpc->pos.y <= floorY) {
            childNpc->pos.y = floorY;
            blurData->offset.y = -blurData->offset.y * 0.5;
        }

        posX = childNpc->pos.x;
        posY = childNpc->pos.y;
        posZ = childNpc->pos.z;
        childNpc->flags = ownerNpc->flags;
    }

    return ApiStatus_BLOCK;
}


ApiStatus func_802415C0_97F090(Evt* script, s32 isInitialCall) {
    NPCBlurUnk* var_s0 = (NPCBlurUnk*) get_npc_safe(script->owner2.npcID)->blurBuf;
    s32 i;
    
    for (i = 0; i < 8; i++, var_s0++) {
        free_npc(var_s0->unk_00);
    }

    return ApiStatus_DONE2;
}

void func_80241610_97F0E0(void) {
    StoneChompBlur* blurPtr = &N(ChompBlur);
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
    
    guTranslateF(transformMtx, blurPtr->pos.x, blurPtr->pos.y, blurPtr->pos.z);
    guRotateF(tempMtx, blurPtr->rot.y + gCameras[gCurrentCameraID].currentYaw + blurPtr->unk_34, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, blurPtr->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, blurPtr->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF(tempMtx, blurPtr->scale.x, blurPtr->scale.y, blurPtr->scale.z);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    spr_get_npc_raster_info(&spriteRaster, blurPtr->unk_08, blurPtr->unk_0C);

    foldImg.raster  = spriteRaster.raster;
    foldImg.palette = spriteRaster.defaultPal;
    blurPtr->width  = foldImg.width  = spriteRaster.width;
    blurPtr->height = foldImg.height = spriteRaster.height;
    foldImg.xOffset = -(spriteRaster.width / 2);
    foldImg.yOffset = (spriteRaster.height / 2);
    foldImg.opacity = 255;
    
    fold_update(blurPtr->unk_00, FOLD_TYPE_7, 255, 255, 255, blurPtr->unk_38, 0);
    fold_appendGfx_component(blurPtr->unk_00, &foldImg, 0, transformMtx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus func_80241B28_97F5F8(Evt* script, s32 isInitialCall) {
    StoneChompBlur* blurPtr = &N(ChompBlur);
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    blurPtr->unk_08 = 53; //TODO get spriteID for this constant
    blurPtr->unk_0C = 0;
    spr_get_npc_raster_info(&rasterInfo, 53, 0); //TODO get spriteID for this constant
    blurPtr->width = rasterInfo.width;
    blurPtr->height = rasterInfo.height;
    blurPtr->pos.x = npc->pos.x;
    blurPtr->pos.y = npc->pos.y + (blurPtr->height * SPRITE_WORLD_SCALE_D * 0.5);
    blurPtr->pos.z = npc->pos.z;
    blurPtr->rot.x = 0;
    blurPtr->rot.y = 0;
    blurPtr->rot.z = 0;
    blurPtr->scale.x = SPRITE_WORLD_SCALE;
    blurPtr->scale.y = SPRITE_WORLD_SCALE;
    blurPtr->scale.z = SPRITE_WORLD_SCALE;
    blurPtr->unk_34 = 85.0f;
    blurPtr->unk_38 = 0;
    blurPtr->unk_00 = 0;
    blurPtr->workerID = create_generic_entity_frontUI(NULL, func_80241610_97F0E0);
    
    return ApiStatus_DONE2;
}

ApiStatus func_80241C34_97F704(Evt* script, s32 isInitialCall) {
    StoneChompBlur* blurPtr = &N(ChompBlur);

    free_generic_entity(blurPtr->workerID);
    return ApiStatus_DONE2;
}

ApiStatus func_80241C5C_97F72C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompBlur* blurPtr = &N(ChompBlur);

    blurPtr->pos.x = x;
    blurPtr->pos.y = y + (blurPtr->height * SPRITE_WORLD_SCALE_D * 0.5);
    blurPtr->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80241D44_97F814(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompBlur* blurPtr = &N(ChompBlur);

    blurPtr->rot.x = x;
    blurPtr->rot.y = y;
    blurPtr->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80241DF8_97F8C8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    StoneChompBlur* blurPtr = &N(ChompBlur);

    blurPtr->unk_38 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80241E24_97F8F4(Evt* script, s32 isInitialCall) {
    f32 x = evt_get_variable(script, LW(2));
    f32 y = evt_get_variable(script, LW(0));
    f32 z = evt_get_variable(script, LW(4));

    fx_landing_dust(0, x, y, z, 0.0f);
    return ApiStatus_DONE2;
}
