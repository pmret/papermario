#include "common.h"
#include "sprite.h"

#ifndef KNOCK_DOWN_MAP_VAR
#warning KNOCK_DOWN_MAP_VAR must be defined!
#endif

void N(gfx_build_knocked_down_player)(void) {
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);
    ImgFXTexture ifxImg;
    SpriteRasterInfo rasterInfo;
    Matrix4f sp40, sp80;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++,
                         G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                         G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);

    guTranslateF(sp40, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp80, data->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, data->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp80, sp40, sp40);
    guRotateF(sp80, data->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp40);
    guScaleF(sp80, data->scale.x, data->scale.y, data->scale.z);
    guMtxCatF(sp80, sp40, sp40);
    guMtxF2L(sp40, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++,
              OS_K0_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    spr_get_player_raster_info(&rasterInfo, data->spriteIndex, data->rasterIndex);
    ifxImg.raster = rasterInfo.raster;
    ifxImg.palette = rasterInfo.defaultPal;
    data->width = ifxImg.width = rasterInfo.width;
    data->height = ifxImg.height = rasterInfo.height;
    ifxImg.xOffset = -(s32) (rasterInfo.width * 0.5f);
    ifxImg.yOffset = rasterInfo.height;
    ifxImg.alpha = 255;

    imgfx_appendGfx_component(data->imgfxIdx, &ifxImg, 0, sp40);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus N(KnockdownCreate)(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    KnockdownData* data = heap_malloc(sizeof(*data));

    data->spriteIndex = spriteIndex;
    data->rasterIndex = rasterIndex;
    data->width = gPlayerStatus.colliderHeight;
    data->height = gPlayerStatus.colliderDiameter;
    data->pos.x = gPlayerStatus.pos.x;
    data->pos.y = gPlayerStatus.pos.y;
    data->pos.z = gPlayerStatus.pos.z;
    data->rot.x = 0.0f;
    data->rot.y = 0.0f;
    data->rot.z = 0.0f;
    data->scale.x = SPRITE_WORLD_SCALE_F;
    data->scale.y = SPRITE_WORLD_SCALE_F;
    data->scale.z = SPRITE_WORLD_SCALE_F;
    data->imgfxIdx = imgfx_get_free_instances(1);
    data->workerID = create_worker_world(0, N(gfx_build_knocked_down_player));
    evt_set_variable(script, KNOCK_DOWN_MAP_VAR, (s32) data);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockdownDestroy)) {
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    imgfx_release_instance(data->imgfxIdx);
    free_worker(data->workerID);
    heap_free(data);
    evt_set_variable(script, KNOCK_DOWN_MAP_VAR, NULL);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockdownSetPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockdownSetRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    data->rot.x = x;
    data->rot.y = y;
    data->rot.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockdownSetScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    data->scale.x = x;
    data->scale.y = y;
    data->scale.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockdownSetRaster)) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    KnockdownData* data = (KnockdownData*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    data->spriteIndex = spriteIndex;
    data->rasterIndex = rasterIndex;
    return ApiStatus_DONE2;
}
