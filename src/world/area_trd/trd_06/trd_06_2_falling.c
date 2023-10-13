#include "trd_06.h"
#include "sprite.h"
#include "sprite/player.h"

typedef struct FallingSprite {
    /* 0x00 */ s32 animationEnabled;
    /* 0x04 */ s32 imgfxIdx;
    /* 0x08 */ s32 workerID;
    /* 0x0C */ s32 playerSpriteID;
    /* 0x10 */ s32 rasterID;
    /* 0x14 */ Vec3f pos;
    /* 0x20 */ Vec3f rot;
    /* 0x2C */ Vec3f scale;
    /* 0x38 */ f32 width;
    /* 0x3C */ f32 height;
} FallingSprite; // size = 0x40

BSS FallingSprite N(Falling);

void N(appendGfx_FallingSprite)(void) {
    ImgFXTexture ifxImg;
    SpriteRasterInfo rasterInfo;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    u32 animFrame;
    FallingSprite* falling = &N(Falling);

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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
    guTranslateF(mtxTransform, falling->pos.x, falling->pos.y, falling->pos.z);
    guRotateF(mtxTemp, falling->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guRotateF(mtxTemp, falling->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guRotateF(mtxTemp, falling->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guScaleF(mtxTemp, falling->scale.x, falling->scale.y, falling->scale.z);
    guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    //TODO use SPR_RASTER_Mario8_XYZ here once they are defined
    if (!falling->animationEnabled) {
        falling->playerSpriteID = SPR_MarioW2;
        animFrame = gGameStatusPtr->frameCounter % 4;
        if (animFrame == 0) {
            falling->rasterID = 37;
        } else if (animFrame <= 1) {
            falling->rasterID = 38;
        } else if (animFrame <= 2) {
            falling->rasterID = 39;
        } else {
            falling->rasterID = 36;
        }
    }

    spr_get_player_raster_info(&rasterInfo, falling->playerSpriteID, falling->rasterID);
    ifxImg.raster = rasterInfo.raster;
    ifxImg.palette = rasterInfo.defaultPal;
    falling->width  = ifxImg.width = rasterInfo.width;
    falling->height = ifxImg.height = rasterInfo.height;
    ifxImg.xOffset = -(rasterInfo.width / 2);
    ifxImg.yOffset = rasterInfo.height / 2;
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(falling->imgfxIdx, &ifxImg, 0, mtxTransform);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

API_CALLABLE(N(InitializeFallingSprite)) {
    FallingSprite* falling = &N(Falling);
    falling->animationEnabled = FALSE;
    falling->rasterID = 0;
    falling->playerSpriteID = 1;
    falling->width  = gPlayerStatus.colliderHeight;
    falling->height = gPlayerStatus.colliderDiameter;
    falling->pos.x = gPlayerStatus.pos.x;
    falling->pos.y = gPlayerStatus.pos.y + (falling->height * SPRITE_WORLD_SCALE_D * 0.5);
    falling->pos.z = gPlayerStatus.pos.z;
    falling->rot.x = 0.0f;
    falling->rot.y = 0.0f;
    falling->rot.z = 0.0f;
    falling->scale.x = SPRITE_WORLD_SCALE_F;
    falling->scale.y = SPRITE_WORLD_SCALE_F;
    falling->scale.z = SPRITE_WORLD_SCALE_F;

    falling->imgfxIdx = imgfx_get_free_instances(1);
    falling->workerID = create_worker_world(0, &N(appendGfx_FallingSprite));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteFallingSprite)) {
    imgfx_release_instance(N(Falling).imgfxIdx);
    free_worker(N(Falling).workerID);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetFallingSpritePos)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    FallingSprite* falling = &N(Falling);

    falling->pos.x = x;
    falling->pos.y = y + (falling->height * SPRITE_WORLD_SCALE_D * 0.5);
    falling->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetFallingSpriteRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 add = evt_get_variable(script, *args++);
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    FallingSprite* falling = &N(Falling);

    if (!add) {
        falling->rot.x = x;
        falling->rot.y = y;
        falling->rot.z = z;
    } else {
        falling->rot.x += x;
        falling->rot.y += y;
        falling->rot.z += z;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableFallingAnimation)) {
    N(Falling).animationEnabled = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitializeFallingPartner)) {
    f32 partnerCollisionHeight = get_npc_unsafe(NPC_PARTNER)->collisionHeight;

    script->varTable[0] = ((partnerCollisionHeight * 2) / 3.0f) + 145.0f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitializeGetUp)) {
    FallingSprite* falling = &N(Falling);

    falling->playerSpriteID = SPR_Mario1;
    falling->rasterID = 0;
    return ApiStatus_DONE2;
}

Vec3f N(FallPath)[] = {
    {  0.0,         0.0,      0.0 },
    {  8.600760,  -48.39987, -1.993566 },
    { 24.998905,  -96.99983, -1.994021 },
    { 51.399390, -143.39980,  1.006466 },
};

EvtScript N(EVS_PlayerFalling) = {
    EVT_CALL(SetPlayerPos, 0, 130, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_PAPER_GLIDE_1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 180, 210, 25, EASING_QUADRATIC_IN)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetFallingSpriteRot), 0, EVT_FLOAT(0.0), EVT_FLOAT(0.0), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_QUADRATIC_IN)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_ADDF(LVar3, LVar6)
    EVT_CALL(N(SetFallingSpritePos), LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_HIT_SPIKE)
    EVT_ADD(LVar2, -1000)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PartnerFalling) = {
    EVT_CALL(N(InitializeFallingPartner))
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, LVar0, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_PAPER_GLIDE_2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 180, 150, 25, EASING_QUADRATIC_IN)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_QUADRATIC_IN)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_ADDF(LVar3, LVar6)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_HIT_SPIKE)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Unused_GetUp) = {
    EVT_CALL(N(InitializeGetUp))
    EVT_THREAD
        EVT_LOOP(11)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1000)
            EVT_CALL(N(SetFallingSpritePos), LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 210, 360, 10, EASING_COS_IN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetFallingSpriteRot), 0, EVT_FLOAT(0.0), EVT_FLOAT(0.0), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump, LVar0, -1000, LVar2, 10)
    EVT_THREAD
        EVT_CALL(MakeLerp, 150, 0, 10, EASING_COS_IN_OUT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, 0, LVar2, 10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_FallIntoCell) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 300, -500)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -100, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 360)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_CALL(SetPlayerPos, 0, 300, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, 300, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE, TRUE)
    EVT_WAIT(30)
    EVT_CALL(N(InitializeFallingSprite))
    EVT_EXEC_WAIT(N(EVS_PlayerFalling))
    EVT_CALL(InterpNpcYaw, NPC_Bombette, 90, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE | NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_EXEC_WAIT(N(EVS_PartnerFalling))
    EVT_CALL(InterpNpcYaw, NPC_Bombette, 270, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Bombette, 90, 0)
    EVT_CALL(SpeakToPlayer, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00D8)
    EVT_CALL(N(EnableFallingAnimation))
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(N(DeleteFallingSprite))
    EVT_THREAD
        EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, 0, LVar2, 10)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 1000)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, LVar0, 0, LVar2, 10)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 27, 0, 30)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -21, 47, 10)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 50, 35, 15)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 73, 22, 10)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(GetAngleToNPC, NPC_Bombette, LVar0)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
        EVT_WAIT(1)
        EVT_CALL(SpeakToPlayer, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00D9)
        EVT_THREAD
            EVT_WAIT(5 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(30 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_CALL(EndSpeech, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcVar, NPC_Bombette, 0, 1)
    EVT_END_IF
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
