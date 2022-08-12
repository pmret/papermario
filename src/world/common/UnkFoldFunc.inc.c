#include "common.h"
#include "sprite.h"

void N(UnkFoldFunc)(void) {
    UnkFoldStruct* temp_v0 = (UnkFoldStruct*) evt_get_variable(NULL, EVT_MAP_VAR(10));
    FoldImageRecPart part;
    SpriteRasterInfo rasterInfo;
    Matrix4f sp40, sp80;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++,
                         G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                         G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);

    guTranslateF(sp40, temp_v0->pos.x, temp_v0->pos.y, temp_v0->pos.z);
    guRotateF(sp80, temp_v0->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, temp_v0->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, temp_v0->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guScaleF(sp80, temp_v0->scale.x, temp_v0->scale.y, temp_v0->scale.z);
    guMtxCatF(sp80, sp40, sp40);
    guMtxF2L(sp40, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++,
              OS_K0_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    spr_get_player_raster_info(&rasterInfo, temp_v0->spriteIndex, temp_v0->rasterIndex);
    part.raster = rasterInfo.raster;
    part.palette = rasterInfo.defaultPal;
    temp_v0->unk_34 = part.width = rasterInfo.width;
    temp_v0->unk_38 = part.height = rasterInfo.height;
    part.xOffset = -(s32) (rasterInfo.width * 0.5f);
    part.yOffset = rasterInfo.height;
    part.opacity = 255;

    fold_appendGfx_component(temp_v0->foldID, &part, 0.0f, sp40);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
