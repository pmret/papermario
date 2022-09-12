#include "trd_05.h"
#include "sprite.h"

static char* N(exit_str_0) = "trd_04";
static char* N(exit_str_1) = "trd_00";

typedef struct UnkTrdStruct {
    /* 0x00 */ s32 foldStateID;
    /* 0x04 */ s32 entityID;
    /* 0x08 */ s32 playerSpriteID;
    /* 0x0C */ s32 rasterID;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
} UnkTrdStruct; // size = 0x34

BSS UnkTrdStruct N(D_80243090);

ApiStatus func_80240000_9AE700(Evt* script, s32 isInitialCall) {
    func_80035DF0(5);
    return ApiStatus_DONE2;
}

void func_80240020_9AE720(void) {
    FoldImageRecPart recPart;
    SpriteRasterInfo sp30;
    Matrix4f sp40;
    Matrix4f sp80;
    UnkTrdStruct* unkTrd = &N(D_80243090);
    s32 frameMod4;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                         G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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

    guTranslateF(sp40, unkTrd->pos.x, unkTrd->pos.y, unkTrd->pos.z);
    guRotateF(sp80, unkTrd->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, unkTrd->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, unkTrd->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp80, sp40, sp40);
    guScaleF(sp80, unkTrd->scale.x, unkTrd->scale.y, unkTrd->scale.z);
    guMtxCatF(sp80, sp40, sp40);
    guMtxF2L(sp40, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    unkTrd->playerSpriteID = 8;

    frameMod4 = gGameStatusPtr->frameCounter % 4;
    if (frameMod4 == 0) {
        unkTrd->rasterID = 0x25;
    } else if (frameMod4 >= 2U) {
        if (frameMod4 >= 3U) {
            unkTrd->rasterID = 0x24;
        } else {
            unkTrd->rasterID = 0x27;
        }
    } else {
        unkTrd->rasterID = 0x26;
    }

    spr_get_player_raster_info(&sp30, unkTrd->playerSpriteID, unkTrd->rasterID);
    recPart.raster = sp30.raster;
    recPart.palette = sp30.defaultPal;
    recPart.width = sp30.width;
    recPart.height = sp30.height;
    recPart.xOffset = -(sp30.width / 2);
    recPart.yOffset = (sp30.height / 2);
    recPart.opacity = 255;
    fold_appendGfx_component(unkTrd->foldStateID, &recPart, 0, sp40);

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus func_80240404_9AEB04(Evt* script, s32 isInitialCall) {
    N(D_80243090).pos.x = gPlayerStatus.position.x;
    N(D_80243090).pos.y = gPlayerStatus.position.y + (gPlayerStatus.colliderHeight * SPRITE_WORLD_SCALE_D * 0.5);
    N(D_80243090).pos.z = gPlayerStatus.position.z;
    N(D_80243090).rot.x = 0.0f;
    N(D_80243090).rot.y = 0.0f;
    N(D_80243090).rot.z = 0.0f;
    N(D_80243090).scale.x = SPRITE_WORLD_SCALE_F;
    N(D_80243090).scale.y = SPRITE_WORLD_SCALE_F;
    N(D_80243090).scale.z = SPRITE_WORLD_SCALE_F;
    N(D_80243090).foldStateID = func_8013A704(1);
    N(D_80243090).entityID = create_generic_entity_world(0, func_80240020_9AE720);
    return ApiStatus_DONE2;
}

ApiStatus func_802404D0_9AEBD0(Evt* script, s32 isInitialCall) {
    func_8013A854(N(D_80243090).foldStateID);
    free_generic_entity(N(D_80243090).entityID);
    return ApiStatus_DONE2;
}

ApiStatus func_80240508_9AEC08(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);

    N(D_80243090).pos.x = x;
    N(D_80243090).pos.y = y + (gPlayerStatus.colliderHeight * SPRITE_WORLD_SCALE_D * 0.5);
    N(D_80243090).pos.z = z;
    return ApiStatus_DONE2;
}

static const char* N(exit_str_2) = "trd_06";

ApiStatus func_802405FC_9AECFC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 add = evt_get_variable(script, *args++);
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkTrdStruct* unkTrd = &N(D_80243090);

    if (!add) {
        unkTrd->rot.x = x;
        unkTrd->rot.y = y;
        unkTrd->rot.z = z;
    } else {
        unkTrd->rot.x += x;
        unkTrd->rot.y += y;
        unkTrd->rot.z += z;
    }
    return ApiStatus_DONE2;
}
