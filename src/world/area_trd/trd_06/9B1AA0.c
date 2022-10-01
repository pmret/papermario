#include "trd_06.h"
#include "sprite.h"

typedef struct Struct_trd_06_802451F0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
} Struct_trd_06_802451F0; // size unknown

// BSS
extern Struct_trd_06_802451F0 trd_06_802451F0;

void func_80240310_9B1AA0(void) {
    FoldImageRecPart foldImage;
    SpriteRasterInfo rasterInfo;
    Matrix4f mtx1;
    Matrix4f mtx2;
    Struct_trd_06_802451F0* unkStruct = &trd_06_802451F0;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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
    guTranslateF(mtx1, unkStruct->unk_14, unkStruct->unk_18, unkStruct->unk_1C);
    guRotateF(mtx2, unkStruct->unk_24, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtx2, mtx1, mtx1);
    guRotateF(mtx2, unkStruct->unk_28, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtx2, mtx1, mtx1);
    guRotateF(mtx2, unkStruct->unk_20, 1.0f, 0.0f, 0.0f);
    guMtxCatF(mtx2, mtx1, mtx1);
    guScaleF(mtx2, unkStruct->unk_2C, unkStruct->unk_30, unkStruct->unk_34);
    guMtxCatF(mtx2, mtx1, mtx1);
    guMtxF2L(mtx1, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (unkStruct->unk_00 == 0) {
        u32 v1;
        unkStruct->unk_0C = 8;
        v1 = gGameStatusPtr->frameCounter % 4;
        if (v1 == 0) {
            unkStruct->unk_10 = 37;
        } else if (v1 <= 1) {
            unkStruct->unk_10 = 38;
        } else if (v1 <= 2) {
            unkStruct->unk_10 = 39;
        } else {
            unkStruct->unk_10 = 36;
        }
    }
    spr_get_player_raster_info(&rasterInfo, unkStruct->unk_0C, unkStruct->unk_10);
    foldImage.raster = rasterInfo.raster;
    foldImage.palette = rasterInfo.defaultPal;
    unkStruct->unk_38 = foldImage.width = rasterInfo.width;
    unkStruct->unk_3C = foldImage.height = rasterInfo.height;
    foldImage.xOffset = -(rasterInfo.width / 2);
    foldImage.yOffset = rasterInfo.height / 2;
    foldImage.opacity = 255;
    fold_appendGfx_component(unkStruct->unk_04, &foldImage, 0, mtx1);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240724_9B1EB4);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_8024081C_9B1FAC);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240854_9B1FE4);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_8024093C_9B20CC);

ApiStatus func_80240A5C_9B21EC(void) {
    trd_06_802451F0.unk_00 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80240A70_9B2200(Evt* script, s32 isInitialCall) {
    f32 partnerCollisionHeight = get_npc_unsafe(NPC_PARTNER)->collisionHeight;

    script->varTable[0] = ((partnerCollisionHeight * 2) / 3.0f) + 145.0f;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240AD0_9B2260);
