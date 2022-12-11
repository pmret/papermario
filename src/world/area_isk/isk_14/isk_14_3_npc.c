#include "isk_14.h"
#include "sprite.h"

#include "world/common/enemy/complete/StoneChomp.inc.c"

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

void N(func_80241610_993D40)(void) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);
    Camera* cam = &gCameras[gCurrentCameraID];
    FoldImageRecPart foldImg;
    SpriteRasterInfo spriteRaster;
    Matrix4f transformMtx, tempMtx;

    gSPViewport(gMasterGfxPos++, &cam->vp);
    if (!(cam->flags & CAMERA_FLAGS_ORTHO)) {
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

API_CALLABLE(N(func_80241AF0_994220)) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    ambush->spriteIndex = SPR_StoneChomp;
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
    ambush->workerID = create_worker_frontUI(NULL, N(func_80241610_993D40));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyAmbushWorker)) {
    StoneChompAmbushIsk14* ambush = &N(ChompAmbush);

    free_worker(ambush->workerID);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241BEC_99431C)) {
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

API_CALLABLE(N(func_80241CA0_9943D0)) {
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

EvtScript N(EVS_NpcIdle_StoneChomp) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 1, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(5)
    EVT_CALL(SetNpcPos, NPC_SELF, -517, -780, -402)
    EVT_CALL(N(func_80241AF0_994220))
    EVT_CALL(N(func_80241BEC_99431C), -517, -780, -402)
    EVT_CALL(N(func_80241CA0_9943D0), 85, 20, 0)
    EVT_WAIT(5)
    EVT_CALL(MakeLerp, 85, 0, 20, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(func_80241CA0_9943D0), LVar0, 20, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(N(DestroyAmbushWorker))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_StoneChomp_Anim04)
    EVT_WAIT(18)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_WAIT(1)
    EVT_CALL(N(DestroyAmbushWorker))
    EVT_CALL(func_802CFD30, -1, 0, 0, 0, 0, 0)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_4 | ENEMY_FLAGS_100000, 0)
    EVT_WAIT(3)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
    EVT_ADD(LVar1, 20)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_WAIT(15)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_StoneChomp)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_StoneChomp_Override) = {
    EVT_SET(GF_ISK14_Defeated_StoneChomp, TRUE)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(AF_ISK14_StoneChompDefeated, TRUE)
            EVT_CALL(N(StoneChompFXC))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StoneChomp) = {
    EVT_IF_EQ(GF_ISK14_Defeated_StoneChomp, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_StoneChomp)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_StoneChomp_Override)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_StoneChomp) = {
    .id = NPC_StoneChomp,
    .settings = &N(NpcSettings_StoneChomp),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 218,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_800 | ENEMY_FLAGS_40000,
    .init = &N(EVS_NpcInit_StoneChomp),
    .initVarCount = 1,
    .initVar = { .value = -780 },
    .drops = STONE_CHOMP_DROPS,
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
    .animations = STONE_CHOMP_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StoneChomp), BTL_ISK_PART_1_FORMATION_07, BTL_ISK_PART_1_STAGE_0B),
    {}
};
