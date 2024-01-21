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
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_1)
    EndThread
    Thread
        Call(MakeLerp, 0, 150, 45, EASING_COS_IN_OUT)
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
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(LoadPath, 45, Ref(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_COS_IN_OUT)
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
    SetF(LVar4, LVar1)
    SetF(LVar5, LVar2)
    SetF(LVar6, LVar3)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_1)
    EndThread
    Call(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
    Label(1)
        Call(UpdateLerp)
        SetF(LVar7, Float(-1.0))
        SetF(LVar8, Float(-1.7315))
        SetF(LVar9, Float(0.0))
        MulF(LVar7, LVar0)
        MulF(LVar8, LVar0)
        MulF(LVar9, LVar0)
        AddF(LVar7, LVar4)
        AddF(LVar8, LVar5)
        AddF(LVar9, LVar6)
        Call(N(SetFallingSpritePos), LVar7, LVar8, LVar9)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(SetPlayerPos, LVar7, LVar8, LVar9)
    Return
    End
};

EvtScript N(EVS_PartnerFalling) = {
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_2)
    EndThread
    Thread
        Call(MakeLerp, 0, -135, 45, EASING_COS_IN_OUT)
        Label(10)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_PARTNER, Float(0.0), Float(0.0), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Wait(1)
    Call(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    Call(LoadPath, 45, Ref(N(FallPath)), ARRAY_COUNT(N(FallPath)), EASING_COS_IN_OUT)
    Label(0)
    Call(GetNextPathPos)
    MulF(LVar1, Float(-1.0))
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    AddF(LVar3, LVar6)
    Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_PAPER_GLIDE_2)
    EndThread
    Call(GetNpcPos, NPC_PARTNER, LVar4, LVar5, LVar6)
    Call(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
    Label(1)
    Call(UpdateLerp)
    SetF(LVar7, Float(1.0))
    SetF(LVar8, Float(-2.0))
    SetF(LVar9, Float(0.0))
    MulF(LVar7, LVar0)
    MulF(LVar8, LVar0)
    MulF(LVar9, LVar0)
    AddF(LVar7, LVar4)
    AddF(LVar8, LVar5)
    AddF(LVar9, LVar6)
    Call(SetNpcPos, NPC_PARTNER, LVar7, LVar8, LVar9)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(SetNpcPos, NPC_PARTNER, LVar7, LVar8, LVar9)
    Return
    End
};

EvtScript N(EVS_OnHitTrapTrigger) = {
    Call(DisablePlayerInput, TRUE)
    Label(10)
        Call(GetPlayerActionState, LVar0)
        Wait(1)
        IfNe(LVar0, ACTION_STATE_IDLE)
            Goto(10)
        EndIf
    Loop(0)
        Call(GetPartnerInUse, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Thread
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, -10)
        Add(LVar2, -5)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Wait(10)
    Call(EnableModel, MODEL_o101, FALSE)
    Call(EnableModel, MODEL_o95, TRUE)
    Call(EnableModel, MODEL_o96, TRUE)
    Call(SetGroupVisibility, MODEL_kesu, MODEL_GROUP_VISIBLE)
    Call(PlaySound, SOUND_OPEN_TRAPDOOR)
    Call(MakeLerp, 0, 90, 30, EASING_COS_SLOW_OVERSHOOT)
    Label(0)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o95, LVar0, 0, 0, -1)
    Call(RotateModel, MODEL_o96, LVar0, 0, 0, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 270, 1)
    Wait(10)
    Call(InterpPlayerYaw, 90, 1)
    Wait(15)
    Call(InterpPlayerYaw, 270, 1)
    Wait(3)
    Call(InterpPlayerYaw, 90, 1)
    Wait(3)
    Call(InterpPlayerYaw, 270, 1)
    Wait(3)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
    Wait(5)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_HURT)
    Wait(15)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Wait(5)
    Thread
        Call(N(InitializeFallingSprite))
        ExecWait(N(EVS_PlayerFalling))
    EndThread
    Thread
        Wait(10)
        ExecWait(N(EVS_PartnerFalling))
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o82, COLLIDER_FLAGS_UPPER_MASK)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
    Set(LVar5, LVar3)
    Sub(LVar5, 200)
    Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar5, LVar4)
    Call(PanToTarget, CAM_DEFAULT, Float(0.5), 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    IfLt(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        Wait(60)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(N(DeleteFallingSprite))
        Call(SetNpcPos, NPC_KoopaBros_01, -250, 240, -25)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
        Call(SetNpcSpeed, NPC_KoopaBros_01, Float(3.0))
        Call(NpcMoveTo, NPC_KoopaBros_01, -150, -25, 0)
        Wait(5)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_ThumbsUp)
        Wait(20)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
        Wait(5)
        Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 5, MSG_CH1_00D7)
        Thread
            Wait(10)
            Call(SetNpcSpeed, NPC_KoopaBros_01, Float(2.5))
            Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
            Call(NpcMoveTo, NPC_KoopaBros_01, -200, -25, 0)
        EndThread
        Wait(20)
        Set(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
    Else
        Wait(20)
    EndIf
    Call(GotoMap, Ref("trd_06"), trd_06_ENTRY_0)
    Wait(100)
    Return
    End
};
