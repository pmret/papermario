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
    Call(SetPlayerPos, 0, 130, 0)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_1)
    EndThread
    Thread
        Call(MakeLerp, 180, 210, 25, EASING_QUADRATIC_IN)
        Label(10)
        Call(UpdateLerp)
        Call(N(SetFallingSpriteRot), 0, Float(0.0), Float(0.0), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Wait(1)
    Call(GetPlayerPos, LVar4, LVar5, LVar6)
    Call(LoadPath, 30, Ref(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_QUADRATIC_IN)
    Label(0)
    Call(GetNextPathPos)
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    AddF(LVar3, LVar6)
    Call(N(SetFallingSpritePos), LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(PlaySound, SOUND_HIT_SPIKE)
    Add(LVar2, -1000)
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_PartnerFalling) = {
    Call(N(InitializeFallingPartner))
    Call(SetNpcPos, NPC_PARTNER, 0, LVar0, 0)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_2)
    EndThread
    Thread
        Call(MakeLerp, 180, 150, 25, EASING_QUADRATIC_IN)
        Label(10)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_PARTNER, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Wait(1)
    Call(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    Call(LoadPath, 30, Ref(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_QUADRATIC_IN)
    Label(0)
    Call(GetNextPathPos)
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    AddF(LVar3, LVar6)
    MulF(LVar1, Float(-1.0))
    Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(PlaySound, SOUND_HIT_SPIKE)
    Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_Unused_GetUp) = {
    Call(N(InitializeGetUp))
    Thread
        Loop(11)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 1000)
            Call(N(SetFallingSpritePos), LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 210, 360, 10, EASING_COS_IN_OUT)
        Label(0)
        Call(UpdateLerp)
        Call(N(SetFallingSpriteRot), 0, Float(0.0), Float(0.0), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Wait(1)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(PlayerJump, LVar0, -1000, LVar2, 10)
    Thread
        Call(MakeLerp, 150, 0, 10, EASING_COS_IN_OUT)
        Label(1)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_PARTNER, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    EndThread
    Wait(1)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_PARTNER, LVar0, 0, LVar2, 10)
    Return
    End
};

EvtScript N(EVS_Scene_FallIntoCell) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPosA, CAM_DEFAULT, 300, -500)
    Call(SetCamPosB, CAM_DEFAULT, -100, 0)
    Call(SetCamDistance, CAM_DEFAULT, 360)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(DisablePartnerAI, 0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(InterpPlayerYaw, 270, 1)
    Call(SetPlayerPos, 0, 300, 0)
    Call(SetNpcPos, NPC_PARTNER, 0, 300, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE, TRUE)
    Wait(30)
    Call(N(InitializeFallingSprite))
    ExecWait(N(EVS_PlayerFalling))
    Call(InterpNpcYaw, NPC_Bombette, 90, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE | NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    ExecWait(N(EVS_PartnerFalling))
    Call(InterpNpcYaw, NPC_Bombette, 270, 0)
    Wait(20)
    Call(InterpNpcYaw, NPC_Bombette, 90, 0)
    Call(SpeakToPlayer, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00D8)
    Call(N(EnableFallingAnimation))
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(N(DeleteFallingSprite))
    Thread
        Call(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, 0, LVar2, 10)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 1000)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, LVar0, 0, LVar2, 10)
    Wait(15)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(DisablePlayerPhysics, FALSE)
    IfLt(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        Call(SetCamSpeed, CAM_DEFAULT, 3)
        Call(SetCamDistance, CAM_DEFAULT, 300)
        Call(SetPanTarget, CAM_DEFAULT, 27, 0, 30)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(NpcMoveTo, NPC_PARTNER, -21, 47, 10)
        Call(NpcMoveTo, NPC_PARTNER, 50, 35, 15)
        Call(NpcMoveTo, NPC_PARTNER, 73, 22, 10)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(GetAngleToNPC, NPC_Bombette, LVar0)
        Call(InterpPlayerYaw, LVar0, 0)
        Call(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
        Wait(1)
        Call(SpeakToPlayer, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00D9)
        Thread
            Wait(5 * DT)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(30 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Call(EndSpeech, NPC_Bombette, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SetNpcVar, NPC_Bombette, 0, 1)
    EndIf
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
