#include "isk_05.h"
#include "sprite.h"

#include "world/common/enemy/StoneChomp.inc.c"

typedef struct StoneChompAmbushIsk05 {
    /* 0x00 */ s32 imgfxIdx;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ s32 spriteIndex;
    /* 0x0C */ s32 rasterIndex;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
    /* 0x34 */ f32 renderYaw;
    /* 0x38 */ s32 alpha;
    /* 0x3C */ f32 width;
    /* 0x40 */ f32 height;
} StoneChompAmbushIsk05; // size = 0x44

StoneChompAmbushIsk05 N(ChompAmbush) = {};

void N(func_80241610_97F0E0)(void) {
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);
    Camera* cam = &gCameras[gCurrentCameraID];
    ImgFXTexture ifxImg;
    SpriteRasterInfo spriteRaster;
    Matrix4f transformMtx, tempMtx;

    gSPViewport(gMainGfxPos++, &cam->vp);
    if (!(cam->flags & CAMERA_FLAG_ORTHO)) {
        gSPPerspNormalize(gMainGfxPos++, cam->perspNorm);
    }
    guMtxF2L(cam->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCameraID]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
        G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING
        | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);

    guTranslateF(transformMtx, ambush->pos.x, ambush->pos.y, ambush->pos.z);
    guRotateF(tempMtx, ambush->rot.y + gCameras[gCurrentCameraID].curYaw + ambush->renderYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, ambush->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, ambush->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF(tempMtx, ambush->scale.x, ambush->scale.y, ambush->scale.z);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, OS_PHYSICAL_TO_K0(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    spr_get_npc_raster_info(&spriteRaster, ambush->spriteIndex, ambush->rasterIndex);
    ifxImg.raster  = spriteRaster.raster;
    ifxImg.palette = spriteRaster.defaultPal;
    ambush->width  = ifxImg.width  = spriteRaster.width;
    ambush->height = ifxImg.height = spriteRaster.height;
    ifxImg.xOffset = -(spriteRaster.width / 2);
    ifxImg.yOffset = (spriteRaster.height / 2);
    ifxImg.alpha = 255;

    imgfx_update(ambush->imgfxIdx, IMGFX_SET_ALPHA, 255, 255, 255, ambush->alpha, 0);
    imgfx_appendGfx_component(ambush->imgfxIdx, &ifxImg, 0, transformMtx);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

API_CALLABLE(N(func_80241B28_97F5F8)) {
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    ambush->spriteIndex = SPR_StoneChomp;
    ambush->rasterIndex = 0;
    spr_get_npc_raster_info(&rasterInfo, ambush->spriteIndex, ambush->rasterIndex);
    ambush->width = rasterInfo.width;
    ambush->height = rasterInfo.height;

    ambush->pos.x = npc->pos.x;
    ambush->pos.y = npc->pos.y + (ambush->height * SPRITE_WORLD_SCALE_D * 0.5);
    ambush->pos.z = npc->pos.z;
    ambush->rot.x = 0;
    ambush->rot.y = 0;
    ambush->rot.z = 0;
    ambush->scale.x = SPRITE_WORLD_SCALE_F;
    ambush->scale.y = SPRITE_WORLD_SCALE_F;
    ambush->scale.z = SPRITE_WORLD_SCALE_F;
    ambush->renderYaw = 85.0f;
    ambush->alpha = 0.0f;

    ambush->imgfxIdx = 0;
    ambush->workerID = create_worker_frontUI(NULL, N(func_80241610_97F0E0));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyAmbushWorker)) {
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);

    free_worker(ambush->workerID);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241C5C_97F72C)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);

    ambush->pos.x = x;
    ambush->pos.y = y + (ambush->height * SPRITE_WORLD_SCALE_D * 0.5);
    ambush->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241D44_97F814)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);

    ambush->rot.x = x;
    ambush->rot.y = y;
    ambush->rot.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241DF8_97F8C8)) {
    Bytecode* args = script->ptrReadPos;
    StoneChompAmbushIsk05* ambush = &N(ChompAmbush);

    ambush->alpha = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241E24_97F8F4)) {
    f32 x = evt_get_variable(script, LVar2);
    f32 y = evt_get_variable(script, LVar0);
    f32 z = evt_get_variable(script, LVar4);

    fx_landing_dust(0, x, y, z, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_StoneChomp) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
    EVT_LABEL(100)
    EVT_IF_EQ(GF_ISK05_Hammer2Block, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_A)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_266, SOUND_SPACE_MODE_0)
        EVT_CALL(MakeLerp, 65, 0, 15, EASING_QUADRATIC_IN)
        EVT_LABEL(101)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g304, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(101)
        EVT_END_IF
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_267, SOUND_SPACE_MODE_0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(5)
    EVT_CALL(N(func_80241B28_97F5F8))
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(func_80241DF8_97F8C8), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetGroupVisibility, MODEL_wan1, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_wan2, MODEL_GROUP_VISIBLE)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(MakeLerp, 0, 360, 15, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_80241D44_97F814), LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(N(func_80241C5C_97F72C), LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar3, 0, 30, EASING_QUARTIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
    EVT_CALL(N(func_80241C5C_97F72C), LVar2, LVar0, LVar4)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(N(func_80241E24_97F8F4))
    EVT_WAIT(5)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_WAIT(1)
    EVT_CALL(N(DestroyAmbushWorker))
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_StoneChomp)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_StoneChomp_Override) = {
    EVT_SET(GF_ISK05_Defeated_StoneChomp, TRUE)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_ISK05_Defeated_StoneChomp, TRUE)
            EVT_SET(AF_ISK05_StoneChompDefeated, TRUE)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_265, SOUND_SPACE_MODE_0)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(MakeLerp, 0, 65, 65, EASING_LINEAR)
                EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, MODEL_g304, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(10)
                EVT_END_IF
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_THREAD
            EVT_CALL(N(StoneChompFXC))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StoneChomp) = {
    EVT_IF_EQ(GF_ISK05_Defeated_StoneChomp, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_StoneChomp)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_StoneChomp_Override)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_StoneChomp) = {
    .id = NPC_StoneChomp,
    .pos = { 385.0f, 71.0f, -330.0f },
    .yaw = 320,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 468, 0, -378 },
            .wanderSize = { 200 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 468, 0, -378 },
            .detectSize = { 400 },
        }
    },
    .init = &N(EVS_NpcInit_StoneChomp),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_StoneChomp),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000,
    .drops = STONE_CHOMP_DROPS,
    .animations = STONE_CHOMP_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StoneChomp), BTL_ISK_1_FORMATION_07, BTL_ISK_1_STAGE_09),
    {}
};
