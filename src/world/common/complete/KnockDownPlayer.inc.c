#include "common.h"
#include "sprite.h"

#ifndef KNOCK_DOWN_MAP_VAR
#warning KNOCK_DOWN_MAP_VAR must be defined!
#endif

void N(gfx_build_knocked_down_player)(void) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);
    FoldImageRecPart part;
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
    gSPMatrix(gMainGfxPos++,
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

    fold_appendGfx_component(temp_v0->foldID, &part, 0, sp40);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

ApiStatus N(KnockDownPlayerB)(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = heap_malloc(sizeof(*temp_v0));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    temp_v0->unk_34 = gPlayerStatus.colliderHeight;
    temp_v0->unk_38 = gPlayerStatus.colliderDiameter;
    temp_v0->pos.x = gPlayerStatus.position.x;
    temp_v0->pos.y = gPlayerStatus.position.y;
    temp_v0->pos.z = gPlayerStatus.position.z;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;
    temp_v0->scale.x = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.y = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.z = SPRITE_WORLD_SCALE_F;
    temp_v0->foldID = func_8013A704(1);
    temp_v0->entityID = create_worker_world(0, N(gfx_build_knocked_down_player));
    evt_set_variable(script, KNOCK_DOWN_MAP_VAR, (s32) temp_v0);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockDownPlayerC)) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL,KNOCK_DOWN_MAP_VAR);

    func_8013A854(temp_v0->foldID);
    free_worker(temp_v0->entityID);
    heap_free(temp_v0);
    evt_set_variable(script, KNOCK_DOWN_MAP_VAR, NULL);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockDownPlayerD)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    temp_v0->pos.x = x;
    temp_v0->pos.y = y;
    temp_v0->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockDownPlayerE)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    temp_v0->rot.x = x;
    temp_v0->rot.y = y;
    temp_v0->rot.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockDownPlayerF)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    temp_v0->scale.x = x;
    temp_v0->scale.y = y;
    temp_v0->scale.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(KnockDownPlayerG)) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, KNOCK_DOWN_MAP_VAR);

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    return ApiStatus_DONE2;
}
