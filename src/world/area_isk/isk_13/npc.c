#include "isk_13.h"
#include "sprite.h"
#include "sprite/player.h"

#include "world/common/enemy/StoneChomp.inc.c"

typedef struct StoneChompAmbushIsk13 {
    /* 0x00 */ s32 useBitingAnim;
    /* 0x04 */ s32 imgfxIdx;
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

void N(func_80241610_990DF0)(void) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(NULL, MV_AmbushPtr);
    Camera* cam = &gCameras[gCurrentCameraID];
    ImgFXTexture ifxImg;
    SpriteRasterInfo spriteRaster;
    Matrix4f transformMtx, tempMtx;

    gSPViewport(gMainGfxPos++, &cam->vp);
    if (!(cam->flags & CAMERA_FLAG_ORTHO)) {
        gSPPerspNormalize(gMainGfxPos++, cam->perspNorm);
    }
    guMtxF2L(cam->mtxPerspective, &gDisplayContext->camPerspMatrix[gCurrentCameraID]);

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

    if (ambush->useBitingAnim) {
        if ((gGameStatusPtr->frameCounter % 10) < 5) {
            ambush->rasterIndex = 0;
        } else {
            ambush->rasterIndex = 2;
        }
    }
    spr_get_npc_raster_info(&spriteRaster, ambush->spriteIndex, ambush->rasterIndex);
    ifxImg.raster  = spriteRaster.raster;
    ifxImg.palette = spriteRaster.defaultPal;
    ambush->width = ifxImg.width  = spriteRaster.width;
    ambush->height = ifxImg.height = spriteRaster.height;
    ifxImg.xOffset = -(spriteRaster.width / 2);
    ifxImg.yOffset = (spriteRaster.height / 2);
    ifxImg.alpha = 255;

    imgfx_update(ambush->imgfxIdx, IMGFX_SET_TINT, ambush->color.r, ambush->color.g, ambush->color.b, ambush->color.a, 0);
    imgfx_appendGfx_component(ambush->imgfxIdx, &ifxImg, 0, transformMtx);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

API_CALLABLE(N(func_80241BA8_991388)) {
    StoneChompAmbushIsk13* ambush;
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    ambush = heap_malloc(sizeof(*ambush));
    ambush->useBitingAnim = FALSE;
    ambush->spriteIndex = SPR_StoneChomp;
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
    ambush->imgfxIdx = 0;

    ambush->workerID = create_worker_frontUI(NULL, N(func_80241610_990DF0));
    evt_set_variable(script, MV_AmbushPtr, (s32) ambush);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyAmbushWorker)) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MV_AmbushPtr);
    free_worker(ambush->workerID);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241D38_991518)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MV_AmbushPtr);

    ambush->pos.x = x;
    ambush->pos.y = y + ambush->height * SPRITE_WORLD_SCALE_D * 0.5;
    ambush->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241E34_991614)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MV_AmbushPtr);

    ambush->rot.x = x;
    ambush->rot.y = y;
    ambush->rot.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241EF8_9916D8)) {
    Bytecode* args = script->ptrReadPos;
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MV_AmbushPtr);
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

API_CALLABLE(N(func_80242044_991824)) {
    StoneChompAmbushIsk13* ambush = (StoneChompAmbushIsk13*) evt_get_variable(script, MV_AmbushPtr);
    ambush->useBitingAnim = TRUE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_StoneChomp) = {
    Label(0)
    Wait(1)
    IfEq(GF_ISK13_Item_LunarStone, FALSE)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(N(func_80241BA8_991388))
    Call(N(func_80241EF8_9916D8), 255, 128, 255, 0)
    Thread
        SetF(LVar0, 0)
        Loop(10)
            AddF(LVar0, Float(12.796))
            Call(N(func_80241EF8_9916D8), 255, 128, 255, LVar0)
            Wait(1)
        EndLoop
        Call(N(func_80241EF8_9916D8), 255, 128, 255, 128)
        SetF(LVar0, 128)
        Loop(20)
            AddF(LVar0, Float(6.343))
            Call(N(func_80241EF8_9916D8), 255, LVar0, 255, LVar0)
            Wait(1)
        EndLoop
        Call(N(func_80241EF8_9916D8), 255, 255, 255, 255)
    EndThread
    Wait(30)
    Thread
        Wait(5)
        Call(MakeLerp, 0, 360, 10, EASING_COS_IN_OUT)
        Label(10)
        Call(UpdateLerp)
        Call(N(func_80241E34_991614), LVar0, 0, Float(90.0))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Call(GetPlayerPos, LVar5, LVar6, LVar7)
    Call(N(func_80241D38_991518), LVar2, LVar3, LVar4)
    Call(MakeLerp, LVar3, LVar6, 20, EASING_CUBIC_IN)
    Label(1)
    Call(UpdateLerp)
    Call(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
    Call(N(func_80241D38_991518), LVar2, LVar0, LVar4)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(N(func_80242044_991824))
    Thread
        Call(InterpPlayerYaw, 180, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20)
        Loop(30)
            Call(SetPlayerAnimation, ANIM_MarioW2_PanicHover)
            Wait(1)
        EndLoop
    EndThread
    Loop(20)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(N(func_80241D38_991518), LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_StoneChomp_Override) = {
    Set(GF_ISK13_Defeated_StoneChomp, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    Call(EnableNpcShadow, NPC_SELF, TRUE)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(N(DestroyAmbushWorker))
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(N(StoneChompFXC))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_StoneChomp) = {
    IfEq(GF_ISK13_Defeated_StoneChomp, TRUE)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_StoneChomp)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_StoneChomp_Override)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

NpcData N(NpcData_StoneChomp) = {
    .id = NPC_StoneChomp,
    .pos = { 440.0f, -470.0f, -300.0f },
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
    .initVar = { .value = -650 },
    .settings = &N(NpcSettings_StoneChomp),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000,
    .drops = STONE_CHOMP_DROPS,
    .animations = STONE_CHOMP_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StoneChomp), BTL_ISK_1_FORMATION_07, BTL_ISK_1_STAGE_0A),
    {}
};
