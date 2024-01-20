#include "flo_14.h"
#include "effects.h"
#include "model.h"

#include "../common/FlowerSpawnRegion.inc.c"
#include "../common/DroppingVine.inc.c"

s32 N(BlowingBubbles) = FALSE;

EvtScript N(EVS_BubbleUpdateCamera) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(MakeLerp, LVar1, 48, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, 48, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TetherParterToPlayer) = {
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

API_CALLABLE(N(SavePartnerFlags)) {
    if (gPlayerData.curPartner == PARTNER_NONE) {
        script->varTable[14] = FALSE;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = TRUE;
    evt_set_variable(NULL, MV_SavedPartnerFlags, get_npc_unsafe(NPC_PARTNER)->flags);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RestorePartnerFlags)) {
    get_npc_unsafe(NPC_PARTNER)->flags = evt_get_variable(NULL, MV_SavedPartnerFlags);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateBubbleSoundPos)) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_LRAW_BUBBLE_DRIFT, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    return ApiStatus_DONE2;
}

Vec3f N(BubbleFlightPath)[] = {
    {  531.0,    75.0,   81.0 },
    {  481.0,    80.0,   81.0 },
    {  431.0,    75.0,   81.0 },
    {  381.0,    70.0,   81.0 },
    {  331.0,    75.0,   81.0 },
    {  281.0,    80.0,   81.0 },
    {  231.0,    75.0,   81.0 },
    {  181.0,    70.0,   81.0 },
    {  131.0,    75.0,   81.0 },
    {   81.0,    80.0,   81.0 },
    {   31.0,    75.0,   81.0 },
    {  -19.0,    70.0,   81.0 },
    {  -69.0,    75.0,   81.0 },
};

EvtScript N(EVS_BubbleFollowPath) = {
    Wait(20)
    Call(PlaySound, SOUND_LOOP_BUBBLE_DRIFT)
    Call(LoadPath, 165, Ref(N(BubbleFlightPath)), ARRAY_COUNT(N(BubbleFlightPath)), EASING_COS_IN_OUT)
    Label(0)
        Call(GetNextPathPos)
        Call(TranslateModel, MODEL_o167, LVar1, LVar2, LVar3)
        Add(LVar2, -27)
        Add(LVar3, -10)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Call(N(UpdateBubbleSoundPos), LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(StopSound, SOUND_LOOP_BUBBLE_DRIFT)
    Return
    End
};

EvtScript N(EVS_RideBigBubble) = {
    Call(IsPlayerWithin, 531, 81, 30, LVar0)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetModelCenter, MODEL_o167)
    Thread
        Add(LVar2, -10)
        Call(SetPlayerJumpscale, Float(0.2))
        Call(PlayerJump, 531, 48, LVar2, 10)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
    EndThread
    Thread
        Wait(5)
        Add(LVar2, -15)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.2))
        Call(NpcJump0, NPC_PARTNER, 531, 68, LVar2, 10)
    EndThread
    ExecGetTID(N(EVS_BubbleUpdateCamera), MV_BubbleCamScript)
    Wait(15)
    Call(N(SavePartnerFlags))
    IfTrue(LVarE)
        ExecGetTID(N(EVS_TetherParterToPlayer), LVarE)
    EndIf
    ExecWait(N(EVS_BubbleFollowPath))
    IfTrue(LVarE)
        KillThread(LVarE)
        Call(N(RestorePartnerFlags))
    EndIf
    Call(GetModelCenter, MODEL_o167)
    PlayEffect(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, 2, 0)
    Call(PlaySoundAt, SOUND_BUBBLE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(EnableModel, MODEL_o167, FALSE)
    Set(AF_FLO_BigBubbleReady, FALSE)
    KillThread(MV_BubbleCamScript)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_BlowBigBubble) = {
    Call(PlaySoundAt, SOUND_FLO_BLOW_BUBBLE, SOUND_SPACE_DEFAULT, 591, 55, 121)
    Call(EnableModel, MODEL_o167, TRUE)
    SetF(LVar2, Float(1.0))
    SetF(LVar4, Float(0.0))
    SetF(LVar5, Float(0.0))
    SetF(LVar6, Float(0.0))
    Set(LVar7, -30)
    Set(LVar8, 20)
    DivF(LVar7, Float(90.0))
    DivF(LVar8, Float(90.0))
    Set(LVar9, 180)
    Loop(LVar9)
        Call(TranslateModel, MODEL_o167, 591, 55, 121)
        SetF(LVar3, LVar2)
        DivF(LVar3, 10)
        Call(ScaleModel, MODEL_o167, LVar3, LVar3, LVar3)
        Call(TranslateModel, MODEL_o167, LVar4, LVar5, LVar6)
        AddF(LVar2, Float(0.05))
        IfGt(LVar9, 90)
            AddF(LVar4, LVar7)
            AddF(LVar5, LVar8)
        EndIf
        Wait(1)
    EndLoop
    Set(LVar7, -30)
    Set(LVar8, -40)
    DivF(LVar7, Float(60.0))
    DivF(LVar8, Float(60.0))
    Loop(60)
        Call(TranslateModel, MODEL_o167, 591, 55, 121)
        Call(ScaleModel, MODEL_o167, LVar3, LVar3, LVar3)
        Call(TranslateModel, MODEL_o167, LVar4, LVar5, LVar6)
        AddF(LVar4, LVar7)
        AddF(LVar6, LVar8)
        Wait(1)
    EndLoop
    Set(AF_FLO_BlowingBigBubble, FALSE)
    Set(AF_FLO_BigBubbleReady, TRUE)
    Return
    End
};

f32 N(BubblePhase) = 0.0f;

void N(gfx_build_big_bubble)(void) {
    Matrix4f matrix;
    Vtx* src;
    Vtx* dest;
    s32 copyCount;
    s32 new_var;

    guMtxIdentF(matrix);

    matrix[0][0] = (sin_rad(N(BubblePhase) / 11.0f) * 0.04) + 0.98;
    matrix[0][1] = (sin_rad(N(BubblePhase) / 12.0f) * 0.04);
    matrix[0][2] = (cos_rad(N(BubblePhase) / 13.0f) * 0.04);

    matrix[1][1] = (sin_rad(N(BubblePhase) / 7.0f + 1.0f) * 0.04) + 0.98;
    matrix[1][0] = (sin_rad(N(BubblePhase) / 14.0f) * 0.04);
    matrix[1][2] = (cos_rad(N(BubblePhase) / 15.0f) * 0.04);

    matrix[2][2] = (sin_rad(N(BubblePhase) * 0.25f + 2.0f)  * 0.04) + 0.98;
    matrix[2][0] = (sin_rad(N(BubblePhase) * 0.0625f) * 0.04);
    matrix[2][1] = (cos_rad(N(BubblePhase) / 17.0f) * 0.04);

    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_get_copied_vertices(VTX_COPY_0, &src, &dest, &copyCount);

    new_var = 0;
    while (new_var); // TODO required to match

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_0));

    N(BubblePhase) += 1.0f;
}

s32 N(FlowerPhase) = 90;

void N(gfx_build_bubble_flower)(void) {
    s32 i;
    Vtx* verts;
    Vtx* copied;
    s32 numCopied;
    f32 openedScale; // controls how open the flower is
    f32 lengthScale; // controls longitudinal pulsing

    mdl_get_copied_vertices(VTX_COPY_1, &verts, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        Vtx* src = &verts[i];
        Vtx* copy = &copied[i];

        if (src->v.ob[0] <= 600) {
            openedScale = 0.7 + (sin_rad((N(FlowerPhase) / 180.0f) * PI_D) * 0.3);
            lengthScale = 0.2 - (sin_rad((N(FlowerPhase) / 180.0f) * PI_D) * 0.2);
            copy->v.ob[0] = ((src->v.ob[0] - 616) * openedScale) + 616.0f + (lengthScale * -48.0f);
            copy->v.ob[1] = ((src->v.ob[1] -  44) * openedScale) +  44.0f + (lengthScale *  25.0f);
            copy->v.ob[2] = ((src->v.ob[2] - 113) * openedScale) + 113.0f + (lengthScale * -87.0f);
        }
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_1));

    if (evt_get_variable(NULL, AF_FLO_BlowingBigBubble)) {
        if (N(FlowerPhase) > 90) {
            N(FlowerPhase) -= 360;
        }
        if (N(FlowerPhase) >= -90) {
            N(FlowerPhase) += 5;
        } else {
            N(FlowerPhase) += 20;
        }
        if (N(FlowerPhase) >= 90) {
            N(FlowerPhase) = 90;
        }
    } else {
        if (N(FlowerPhase) > 140 && N(FlowerPhase) < 260) {
            N(BlowingBubbles) = TRUE;
        } else {
            N(BlowingBubbles) = FALSE;
        }
        N(FlowerPhase) += 5;
    }

    if (N(FlowerPhase) >= 360) {
        N(FlowerPhase) -= 360;
    }
}

EvtScript N(EVS_ManageBlownBubble) = {
    SetGroup(EVT_GROUP_00)
    Set(LVarF, LVar0)
    Label(0)
        IfEq(AF_FLO_PauseBlowingBubbles, TRUE)
            Wait(10)
            Goto(0)
        EndIf
        UseBuf(Ref(N(BlowingBubbles)))
        BufRead1(LVar0)
        IfEq(LVar0, FALSE)
            Call(RandInt, 10, LVar0)
            Add(LVar0, 1)
            Wait(LVar0)
            Goto(0)
        EndIf
        Call(EnableModel, LVarF, TRUE)
        Call(RandInt, 4, LVar0)
        AddF(LVar0, Float(4.0))
        MulF(LVar0, Float(-1.0))
        SetF(LVar1, Float(2.0))
        SetF(LVar2, LVar0)
        DivF(LVar2, Float(10.0))
        SetF(LVar3, Float(0.4))
        SetF(LVar4, Float(591.0))
        SetF(LVar5, Float(60.0))
        SetF(LVar6, Float(121.0))
        Call(RandInt, 3, LVar7)
        AddF(LVar7, Float(3.0))
        MulF(LVar7, Float(0.04))
        SetF(LVar9, LVar7)
        DivF(LVar9, Float(5.0))
        Call(RandInt, 50, LVar8)
        Add(LVar8, 50)
        Loop(LVar8)
            SetF(LVarE, LVar2)
            SubF(LVarE, LVar0)
            MulF(LVarE, Float(0.046))
            AddF(LVar0, LVarE)
            SetF(LVarE, LVar3)
            SubF(LVarE, LVar1)
            MulF(LVarE, Float(0.046))
            AddF(LVar1, LVarE)
            AddF(LVar4, LVar0)
            AddF(LVar5, LVar1)
            SetF(LVarE, LVar7)
            SubF(LVarE, LVar9)
            MulF(LVarE, Float(0.203))
            AddF(LVar9, LVarE)
            Call(TranslateModel, LVarF, LVar4, LVar5, LVar6)
            Call(ScaleModel, LVarF, LVar9, LVar9, LVar9)
            Wait(1)
        EndLoop
        Call(EnableModel, LVarF, FALSE)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupBubbles) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o129, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o155, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o156, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o157, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o158, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -730, -130, -470,  -70,  0)
    EVT_FLOWER_SPAWN_REGION( -730,   70, -470,  140,  0)
    EVT_FLOWER_SPAWN_REGION( -280,  130, -110,  -70,  0)
    EVT_FLOWER_SPAWN_REGION( -280,   70,  -10,  140,  0)
    EVT_DROPPING_VINE(ITEM_STINKY_HERB, MODEL_o92, MODEL_o93, MODEL_o94, MODEL_o95)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o82, MODEL_o83, MODEL_o84, MODEL_o85)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o78, MODEL_o79, MODEL_o80, MODEL_o81)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o88, MODEL_o89, MODEL_o90, MODEL_o91)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o113, COLLIDER_FLAGS_UPPER_MASK)
    Call(CloneModel, MODEL_o169, CLONED_MODEL(1))
    Call(CloneModel, MODEL_o169, CLONED_MODEL(2))
    Call(CloneModel, MODEL_o169, CLONED_MODEL(3))
    Call(CloneModel, MODEL_o169, CLONED_MODEL(4))
    Call(CloneModel, MODEL_o169, CLONED_MODEL(5))
    Call(EnableModel, MODEL_o167, FALSE)
    Call(EnableModel, MODEL_o169, FALSE)
    Call(EnableModel, CLONED_MODEL(1), FALSE)
    Call(EnableModel, CLONED_MODEL(2), FALSE)
    Call(EnableModel, CLONED_MODEL(3), FALSE)
    Call(EnableModel, CLONED_MODEL(4), FALSE)
    Call(EnableModel, CLONED_MODEL(5), FALSE)
    Set(LVar0, CLONED_MODEL(1))
    Exec(N(EVS_ManageBlownBubble))
    Set(LVar0, CLONED_MODEL(2))
    Exec(N(EVS_ManageBlownBubble))
    Set(LVar0, CLONED_MODEL(3))
    Exec(N(EVS_ManageBlownBubble))
    Set(LVar0, CLONED_MODEL(4))
    Exec(N(EVS_ManageBlownBubble))
    Set(LVar0, CLONED_MODEL(5))
    Exec(N(EVS_ManageBlownBubble))
    Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o167, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(gfx_build_big_bubble)), NULL)
    Call(SetModelCustomGfx, MODEL_o167, CUSTOM_GFX_1, -1)
    Call(SetModelCustomGfx, CLONED_MODEL(1), 1, -1)
    Call(SetModelCustomGfx, CLONED_MODEL(2), 1, -1)
    Call(SetModelCustomGfx, CLONED_MODEL(3), 1, -1)
    Call(SetModelCustomGfx, CLONED_MODEL(4), 1, -1)
    Call(SetModelCustomGfx, CLONED_MODEL(5), 1, -1)
    Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_o57, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_2, Ref(N(gfx_build_bubble_flower)), NULL)
    Call(SetModelCustomGfx, MODEL_o57, CUSTOM_GFX_2, -1)
    Return
    End
};
