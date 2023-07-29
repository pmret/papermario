#include "trd_05.h"
#include "sprite.h"
#include "sprite/player.h"

typedef struct FallingSprite {
    /* 0x00 */ s32 imgfxIdx;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ s32 playerSpriteID;
    /* 0x0C */ s32 rasterID;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
} FallingSprite; // size = 0x34

BSS FallingSprite N(Falling);

void N(appendGfx_FallingSprite)(void) {
    FallingSprite* falling = &N(Falling);
    ImgFXTexture ifxImg;
    SpriteRasterInfo info;
    Matrix4f transformMtx;
    Matrix4f tempMtx;
    u32 animFrame;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                         G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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

    guTranslateF(transformMtx, falling->pos.x, falling->pos.y, falling->pos.z);
    guRotateF(tempMtx, falling->rot.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, falling->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, falling->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guScaleF(tempMtx, falling->scale.x, falling->scale.y, falling->scale.z);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]),
        G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    //TODO use SPR_RASTER_Mario8_XYZ here once they are defined
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

    spr_get_player_raster_info(&info, falling->playerSpriteID, falling->rasterID);
    ifxImg.raster  = info.raster;
    ifxImg.palette = info.defaultPal;
    ifxImg.width   = info.width;
    ifxImg.height  = info.height;
    ifxImg.xOffset = -(info.width / 2);
    ifxImg.yOffset = (info.height / 2);
    ifxImg.alpha = 255;
    imgfx_appendGfx_component(falling->imgfxIdx, &ifxImg, 0, transformMtx);

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

API_CALLABLE(N(InitializeFallingSprite)) {
    FallingSprite* falling = &N(Falling);
    falling->pos.x = gPlayerStatus.pos.x;
    falling->pos.y = gPlayerStatus.pos.y + (gPlayerStatus.colliderHeight * SPRITE_WORLD_SCALE_D * 0.5);
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
    falling->pos.y = y + (gPlayerStatus.colliderHeight * SPRITE_WORLD_SCALE_D * 0.5);
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

Vec3f N(FallPath)[] = {
    {    0.0,     0.0,    0.0 },
    {   20.0,  -150.0,    0.0 },
    {   50.0,  -170.0,    0.0 },
    {   80.0,  -160.0,    0.0 },
};

Vec3f N(UnusedPath)[] = {
    {    0.0,     0.0,    0.0 },
    {   25.0,   -80.0,    0.0 },
    {   50.0,  -100.0,    0.0 },
    {   70.0,  -100.0,    0.0 },
};

EvtScript N(EVS_PlayerFalling) = {
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_175)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 150, 45, EASING_COS_IN_OUT)
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
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_COS_IN_OUT)
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
    EVT_SETF(LVar4, LVar1)
    EVT_SETF(LVar5, LVar2)
    EVT_SETF(LVar6, LVar3)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_175)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar7, EVT_FLOAT(-1.0))
        EVT_SETF(LVar8, EVT_FLOAT(-1.7315))
        EVT_SETF(LVar9, EVT_FLOAT(0.0))
        EVT_MULF(LVar7, LVar0)
        EVT_MULF(LVar8, LVar0)
        EVT_MULF(LVar9, LVar0)
        EVT_ADDF(LVar7, LVar4)
        EVT_ADDF(LVar8, LVar5)
        EVT_ADDF(LVar9, LVar6)
        EVT_CALL(N(SetFallingSpritePos), LVar7, LVar8, LVar9)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(SetPlayerPos, LVar7, LVar8, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PartnerFalling) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_176)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -135, 45, EASING_COS_IN_OUT)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_PARTNER, EVT_FLOAT(0.0), EVT_FLOAT(0.0), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_ADDF(LVar3, LVar6)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySound, SOUND_176)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    EVT_CALL(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_SETF(LVar7, EVT_FLOAT(1.0))
    EVT_SETF(LVar8, EVT_FLOAT(-2.0))
    EVT_SETF(LVar9, EVT_FLOAT(0.0))
    EVT_MULF(LVar7, LVar0)
    EVT_MULF(LVar8, LVar0)
    EVT_MULF(LVar9, LVar0)
    EVT_ADDF(LVar7, LVar4)
    EVT_ADDF(LVar8, LVar5)
    EVT_ADDF(LVar9, LVar6)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar7, LVar8, LVar9)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar7, LVar8, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnHitTrapTrigger) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(10)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_LOOP(0)
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -10)
        EVT_ADD(LVar2, -5)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o101, FALSE)
    EVT_CALL(EnableModel, MODEL_o95, TRUE)
    EVT_CALL(EnableModel, MODEL_o96, TRUE)
    EVT_CALL(SetGroupVisibility, MODEL_kesu, MODEL_GROUP_VISIBLE)
    EVT_CALL(PlaySound, SOUND_2091)
    EVT_CALL(MakeLerp, 0, 90, 30, EASING_COS_SLOW_OVERSHOOT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o95, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o96, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(15)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(3)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(3)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(3)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_HURT)
    EVT_WAIT(15)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(N(InitializeFallingSprite))
        EVT_EXEC_WAIT(N(EVS_PlayerFalling))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(EVS_PartnerFalling))
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o82, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
    EVT_SET(LVar5, LVar3)
    EVT_SUB(LVar5, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar5, LVar4)
    EVT_CALL(PanToTarget, CAM_DEFAULT, EVT_FLOAT(0.5), 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        EVT_WAIT(60)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(N(DeleteFallingSprite))
        EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -250, 240, -25)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
        EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -150, -25, 0)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_ThumbsUp)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
        EVT_WAIT(5)
        EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 5, MSG_CH1_00D7)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(2.5))
            EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
            EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -200, -25, 0)
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_SET(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
    EVT_ELSE
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("trd_06"), trd_06_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
