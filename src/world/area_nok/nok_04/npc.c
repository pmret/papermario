
#include "nok_04.h"
#include "effects.h"
#include "sprite/player.h"

#define NUM_THREAD_SEGMENTS 16

typedef struct FuzzyThread {
    /* 0x00 */ Vec3f anchorPos;
    /* 0x0C */ f32 targetLength;
    /* 0x10 */ f32 curLength;
    /* 0x14 */ f32 overshootVel;
    /* 0x18 */ f32 targetAngle;
    /* 0x1C */ f32 overshootAngleVel;
    /* 0x20 */ f32 curAngle;
    /* 0x24 */ Vec3f endPoint;
    /* 0x30 */ f32 duration;
    /* 0x34 */ f32 time;
    /* 0x38 */ f32 lengthStep;
    /* 0x3C */ f32 angleStep;
    /* 0x40 */ Npc* frontNpc;
    /* 0x44 */ Npc* backNpc;
} FuzzyThread; //size = 0x48

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/Koopa.inc.c"

#include "../common/GetIntoShell.inc.c"

FuzzyThread N(ThreadData) = {};

s32 N(TreeHidingSpotPositions)[] = {
    -82, 101, 130,
    38, 164, 130,
    158, 135, 157,
    281, 156, 202,
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_AnimBranch_JumpTo) = {
    Set(LVar2, LVar0)
    Set(LVar3, LVar1)
    Set(LVar4, 600)
    Div(LVar4, 100)
    Add(LVar4, 27)
    Call(RandInt, 1, LVar5)
    Mul(LVar5, 20)
    Sub(LVar5, 10)
    Set(LVar6, 0)
    SetF(LVar8, Float(5.0))
    Call(MakeLerp, LVar5, 0, LVar4, EASING_COS_FAST_OVERSHOOT)
    Label(0)
        Call(UpdateLerp)
        MulF(LVar0, Float(0.40625))
        Add(LVar6, 1)
        SetF(LVar9, LVar8)
        MulF(LVar9, Float(-1.0))
        Call(N(CosInterpMinMax), LVar6, LVar7, LVar9, LVar8, 3, 0, 0)
        MulF(LVar8, Float(0.90625))
        Call(TranslateModel, LVar2, LVar7, LVar0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_AnimBranch_Hit) = {
    Set(LVar2, LVar0)
    Set(LVar3, LVar1)
    Set(LVar4, 600)
    Div(LVar4, 100)
    Add(LVar4, 27)
    Set(LVar0, 5)
    Loop(LVar0)
        Call(TranslateModel, LVar2, LVar0, 0, 0)
        Wait(1)
        Set(LVar1, LVar0)
        Mul(LVar1, -1)
        Call(TranslateModel, LVar2, LVar1, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MoveCam_TrackBoss) = {
    Call(InterpCamTargetPos, 0, 1, LVarA, LVarB, LVarC, LVarD)
    Return
    End
};

Vtx N(ThreadSegmentVertices)[] = {
    {{{  -2,   0,     0 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{   1,   0,     0 }, 0, {   512,     0 }, { 255, 255, 255, 255 }}},
};

Gfx N(ThreadGfx)[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

API_CALLABLE(N(SetThreadAnchorPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    f32 temp_f6 = evt_get_variable(script, *args++);

    N(ThreadData).anchorPos.x = temp_s2;
    N(ThreadData).anchorPos.y = temp_s0_3 + 4.0f;
    N(ThreadData).anchorPos.z = temp_f6;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetThreadTargetLengthAngle)) {
    Bytecode* args = script->ptrReadPos;
    s32 goal = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    FuzzyThread* thread = &N(ThreadData); //needed to match
    N(ThreadData).targetAngle = temp_s0_3 / NUM_THREAD_SEGMENTS;
    N(ThreadData).targetLength = (f32)goal / NUM_THREAD_SEGMENTS;
    N(ThreadData).duration = duration;
    N(ThreadData).time = 0.0f;

    if (0.0f < N(ThreadData).duration) {
        N(ThreadData).lengthStep = (N(ThreadData).targetLength - N(ThreadData).curLength) / N(ThreadData).duration;
        N(ThreadData).angleStep = (N(ThreadData).targetAngle - N(ThreadData).curAngle) / N(ThreadData).duration;
    }

    if (N(ThreadData).duration < 0.0f) {
        N(ThreadData).curLength = N(ThreadData).targetLength;
        N(ThreadData).curAngle = N(ThreadData).targetAngle;
        N(ThreadData).duration = 0.0f;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitThreadData)) {
    N(ThreadData).anchorPos.x = 0;
    N(ThreadData).anchorPos.y = 0;
    N(ThreadData).anchorPos.z = 0;
    N(ThreadData).curLength = 0;
    N(ThreadData).targetLength = 0;
    N(ThreadData).overshootVel = 0;
    N(ThreadData).targetAngle = 0;
    N(ThreadData).curAngle = 0;
    N(ThreadData).overshootAngleVel = 0;
    N(ThreadData).frontNpc = NULL;
    N(ThreadData).backNpc = NULL;
    N(ThreadData).time = 0;
    N(ThreadData).duration = 0;
    N(ThreadData).lengthStep = 0;
    N(ThreadData).angleStep = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AttachThreadFrontNpc)) {
    Bytecode* args = script->ptrReadPos;
    N(ThreadData).frontNpc = (Npc*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AttachThreadBackNpc)) {
    Bytecode* args = script->ptrReadPos;
    N(ThreadData).backNpc = (Npc*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTreeHidingSpotPos)) {
    Bytecode *args = script->ptrReadPos;
    s32 treeIdx = evt_get_variable(script, *args++) * 3;
    s32 outVarX = *args++;
    s32 outVarY = *args++;
    s32 outVarZ = *args++;

    evt_set_variable(script, outVarX, N(TreeHidingSpotPositions)[treeIdx + 0]);
    evt_set_variable(script, outVarY, N(TreeHidingSpotPositions)[treeIdx + 1]);
    evt_set_variable(script, outVarZ, N(TreeHidingSpotPositions)[treeIdx + 2]);
    return ApiStatus_DONE2;
}

// get pattern from counter: 0, 1, 2, 3, 2, 1, (begin repeat) 0, 1, 2, 3, ...
API_CALLABLE(N(EVS_ConvertTreeIndex)) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIdx = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;

    treeIdx %= 6;

    if (treeIdx < 4) {
        evt_set_variable(script, outVar, treeIdx);
    } else {
        evt_set_variable(script, outVar, 6 - treeIdx);
    }

    return ApiStatus_DONE2;
}

// args: tree index, animation type (0 = jump to, 1 = hit)
API_CALLABLE(N(AnimateTreeBranch)) {
    Bytecode* args = script->ptrReadPos;
    s32 treeIdx = evt_get_variable(script, *args++);
    s32 temp_s2 = evt_get_variable(script, *args++);
    Evt* animScript;
    EvtScript* animSrc;

    // get pattern: 0, 1, 2, 3, 2, 1, (begin repeat) 0, 1, 2, 3, ...
    treeIdx %= 6;

    if (treeIdx >= 4) {
        treeIdx = 6 - treeIdx;
    }

    if (does_script_exist(script->varTable[treeIdx + 6])) {
        kill_script_by_ID(script->varTable[treeIdx + 6]);
    }

    animSrc = &N(EVS_AnimBranch_JumpTo);

    switch (temp_s2) {
        case 0:
            animSrc = &N(EVS_AnimBranch_JumpTo);
            break;
        case 1:
            animSrc = &N(EVS_AnimBranch_Hit);
            break;
    }

    animScript = start_script(animSrc, EVT_PRIORITY_1, 0);
    script->varTable[treeIdx + 6] = animScript->id;

    switch (treeIdx) {
        case 0:
            animScript->varTable[0] = MODEL_o177;
            break;
        case 1:
            animScript->varTable[0] = MODEL_o178;
            break;
        case 2:
            animScript->varTable[0] = MODEL_o181;
            break;
        case 3:
            animScript->varTable[0] = MODEL_o180;
            break;
    }

    return ApiStatus_DONE2;
}

void N(build_gfx_thread)(void) {
    f32 x = N(ThreadData).anchorPos.x;
    f32 y = N(ThreadData).anchorPos.y;
    f32 z = N(ThreadData).anchorPos.z;
    s32 i;
    f32 segAngle, segLength, fs3;

    N(ThreadData).overshootVel += 0.2;
    if (N(ThreadData).duration != 0.0f) {
        // thread extension/retraction
        N(ThreadData).curLength += N(ThreadData).lengthStep;
        if (N(ThreadData).curLength > N(ThreadData).targetLength) {
            N(ThreadData).overshootVel += (N(ThreadData).targetLength - N(ThreadData).curLength) * 0.5f;
        }
        N(ThreadData).time += 1.0f;
        N(ThreadData).overshootAngleVel = (N(ThreadData).overshootAngleVel + (N(ThreadData).targetAngle - N(ThreadData).curAngle) / 10.0f) * 0.92;
        N(ThreadData).curAngle += N(ThreadData).angleStep;
        if (N(ThreadData).duration <= N(ThreadData).time) {
            N(ThreadData).duration = 0.0f;
        }
    } else {
        // thread overshoot
        N(ThreadData).curLength += N(ThreadData).overshootVel;
        if (N(ThreadData).targetLength < N(ThreadData).curLength) {
            N(ThreadData).overshootVel += (N(ThreadData).targetLength - N(ThreadData).curLength) * 0.5f;
        }
        N(ThreadData).overshootAngleVel = (N(ThreadData).overshootAngleVel + (N(ThreadData).targetAngle - N(ThreadData).curAngle) / 10.0f) * 0.92;
        N(ThreadData).curAngle += N(ThreadData).overshootAngleVel;
    }
    N(ThreadData).overshootVel *= 0.5;

    gSPDisplayList(gMainGfxPos++, N(ThreadGfx));
    guTranslate(&gDisplayContext->matrixStack[gMatrixListPos], N(ThreadData).anchorPos.x, N(ThreadData).anchorPos.y, N(ThreadData).anchorPos.z);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    segAngle = N(ThreadData).curAngle;
    segLength = -N(ThreadData).curLength;
    x += -segLength * sin_rad(N(ThreadData).curAngle * 0 / 180.0f * PI);
    y +=  segLength * cos_rad(N(ThreadData).curAngle * 0 / 180.0f * PI);

    guPosition(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, segAngle, 1.0f, 0.0f, segLength, 0.0f);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    for (i = 1; i < NUM_THREAD_SEGMENTS; i++) {
        segAngle = N(ThreadData).curAngle;
        segLength = -N(ThreadData).curLength;
        x += -segLength * sin_rad(N(ThreadData).curAngle * i / 180.0f * PI);
        y +=  segLength * cos_rad(N(ThreadData).curAngle * i / 180.0f * PI);
        gSPVertex(gMainGfxPos++, N(ThreadSegmentVertices), 2, 0);
        guPosition(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, segAngle, 1.0f, 0.0f, segLength, 0.0f);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMainGfxPos++, N(ThreadSegmentVertices), 2, 2);
        gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 2, 3, 1, 0);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    N(ThreadData).endPoint.x = x;
    N(ThreadData).endPoint.y = y;
    N(ThreadData).endPoint.z = z;

    if (N(ThreadData).frontNpc != NULL) {
        N(ThreadData).frontNpc->pos.x = x;
        N(ThreadData).frontNpc->pos.y = y - 4.0f;
        N(ThreadData).frontNpc->pos.z = z + 6.0f;
    }

    if (N(ThreadData).backNpc != NULL) {
        N(ThreadData).backNpc->pos.x = x;
        N(ThreadData).backNpc->pos.y = y - 4.0f;
        N(ThreadData).backNpc->pos.z = z + 3.0f;
    }
}

EvtScript N(EVS_BossJumpTo) = {
    Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, LVarD)
    Return
    End
};

EvtScript N(EVS_Scene_ShuffleFuzzyPositions) = {
    Call(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
    Call(ShowMessageAtScreenPos, MSG_CH1_00BE, 160, 40)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetCamType, CAM_DEFAULT, 1, FALSE)
    Call(SetCamDistance, CAM_DEFAULT, -597)
    Call(SetCamPitch, CAM_DEFAULT, 10, -11)
    Call(SetCamPosA, CAM_DEFAULT, 0, 707)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 90, 0, 228)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(60 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(SetNpcJumpscale, NPC_BossFuzzy, 3)
    Call(SetNpcJumpscale, NPC_KoopersShell, 3)
    Call(SetNpcJumpscale, NPC_Fuzzy_01, 3)
    Call(SetNpcJumpscale, NPC_Fuzzy_02, 3)
    Call(SetNpcJumpscale, NPC_Fuzzy_03, 3)
    // get number of jumps
    Switch(MV_CorrectCount)
        CaseEq(0)
            Set(LVarE, 10)
        CaseEq(1)
            Set(LVarE, 9)
        CaseEq(2)
            Set(LVarE, 8)
    EndSwitch
    Call(RandInt, 3, LVar0)
    Add(LVarE, LVar0)
    Set(LVar6, 0)
    Set(LVar7, 0)
    Set(LVar8, 0)
    Set(LVar9, 0)
    Set(LVarF, MV_CorrectTreeIndex)
    // the shuffle
    Loop(LVarE)
        Set(LVarA, MV_CorrectTreeIndex)
        Call(N(EVS_ConvertTreeIndex), LVarF, MV_CorrectTreeIndex)
        Switch(LVarF)
            CaseEq(0)
                Set(LVarB, TREE_2)
                Set(LVarC, TREE_3)
            CaseEq(1)
                IfEq(LVarA, 2)
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_3)
                Else
                    Set(LVarB, TREE_2)
                    Set(LVarC, TREE_3)
                EndIf
            CaseEq(2)
                IfEq(LVarA, 3)
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_1)
                Else
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_3)
                EndIf
            CaseEq(3)
                Set(LVarB, TREE_0)
                Set(LVarC, TREE_1)
            CaseEq(4)
                IfEq(LVarA, 1)
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_3)
                Else
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_1)
                EndIf
            CaseEq(5)
                IfEq(LVarA, 0)
                    Set(LVarB, TREE_2)
                    Set(LVarC, TREE_3)
                Else
                    Set(LVarB, TREE_0)
                    Set(LVarC, TREE_3)
                EndIf
        EndSwitch
        Call(RandInt, 1, LVar0)
        IfEq(LVar0, 0)
            Add(LVarF, -1)
        Else
            Add(LVarF, 1)
        EndIf
        IfGe(LVarF, 6)
            Set(LVarF, 0)
        EndIf
        IfLt(LVarF, 0)
            Set(LVarF, 5)
        EndIf
        // get time for each jump
        Switch(MV_CorrectCount)
            CaseEq(0)
                Set(LVarD, 15)
            CaseEq(1)
                Set(LVarD, 10)
            CaseEq(2)
                Set(LVarD, 6)
        EndSwitch
        Set(LVar0, ANIM_Fuzzy_Jump)
        Call(RandInt, 2, LVar1)
        Add(LVar0, LVar1)
        Call(SetNpcAnimation, NPC_BossFuzzy, LVar0)
        Call(SetNpcAnimation, NPC_Fuzzy_01, LVar0)
        Call(SetNpcAnimation, NPC_Fuzzy_02, LVar0)
        Call(SetNpcAnimation, NPC_Fuzzy_03, LVar0)
        Call(PlaySound, SOUND_SEQ_FUZZY_HOP)
        Thread
            Call(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
            Call(NpcJump0, NPC_BossFuzzy, LVar0, LVar1, LVar2, LVarD)
        EndThread
        IfNe(MV_CorrectTreeIndex, LVarA)
            Thread
                Call(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
                Call(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                Call(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, LVarD)
            EndThread
            Set(LFlag0, FALSE)
            IfEq(LVarB, 0)
                IfEq(LVarC, 3)
                    Set(LFlag0, TRUE)
                EndIf
            EndIf
            IfEq(LFlag0, FALSE)
                Thread
                    Call(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    Call(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                    Call(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
                EndThread
                Thread
                    Call(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    Call(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                    Call(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
                EndThread
            Else
                Thread
                    Call(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    Call(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                    Call(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
                EndThread
                Thread
                    Call(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    Call(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                    Call(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    Call(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
                EndThread
            EndIf
        Else
            Thread
                Add(LVarA, 1)
                Mod(LVarA, 4)
                Call(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
                Call(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, LVarD)
            EndThread
            Thread
                Add(LVarA, 2)
                Mod(LVarA, 4)
                Call(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                Call(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
            EndThread
            Thread
                Add(LVarA, 3)
                Mod(LVarA, 4)
                Call(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                Call(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
            EndThread
        EndIf
        Wait(2)
        Call(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
        Add(LVar2, 2)
        Call(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, LVarD)
        Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Still)
        Call(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Still)
        Call(SetNpcAnimation, NPC_Fuzzy_02, ANIM_Fuzzy_Still)
        Call(SetNpcAnimation, NPC_Fuzzy_03, ANIM_Fuzzy_Still)
        Call(N(AnimateTreeBranch), TREE_0, 0)
        Call(N(AnimateTreeBranch), TREE_1, 0)
        Call(N(AnimateTreeBranch), TREE_2, 0)
        Call(N(AnimateTreeBranch), TREE_3, 0)
        Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(30)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_FuzzyBoss_TauntFromTree) = {
    Set(AF_NOK04_PlayingGame, TRUE)
    IfEq(LFlag0, FALSE)
        Call(DisablePlayerInput, TRUE)
        Thread
            Wait(20 * DT)
            Call(DisablePlayerPhysics, TRUE)
        EndThread
    EndIf
    Call(N(AnimateTreeBranch), 2, 0)
    Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
    Call(N(GetTreeHidingSpotPos), 2, LVar0, LVar1, LVar2)
    Call(N(SetThreadAnchorPos), LVar0, LVar1, LVar2)
    Call(N(SetThreadTargetLengthAngle), 50, 0, 0)
    Call(GetNpcPointer, NPC_BossFuzzy, LVar0)
    Call(GetNpcPointer, NPC_KoopersShell, LVar1)
    Call(N(AttachThreadBackNpc), LVar0)
    Call(N(AttachThreadFrontNpc), LVar1)
    Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    IfLt(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        Set(LVar0, MSG_CH1_00BC)
        Set(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
    Else
        Set(LVar0, MSG_CH1_00BD)
    EndIf
    Call(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, LVar0)
    Call(SetMusicTrack, 0, SONG_PLAYROOM, 0, 8)
    Call(N(SetThreadTargetLengthAngle), 0, 0, 30 * DT)
    Wait(30 * DT)
    Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
    Call(N(AttachThreadFrontNpc), NULL)
    Call(N(AttachThreadBackNpc), NULL)
    Exec(N(EVS_Scene_ShuffleFuzzyPositions))
    Return
    End
};

EvtScript N(EVS_Scene_HideInTree) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
            Label(0)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(LVar0, 60)
                    Wait(1)
                    Goto(0)
                EndIf
            Set(LFlag0, FALSE)
            Exec(N(EVS_FuzzyBoss_TauntFromTree))
            Return
        CaseGe(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            Return
    EndSwitch
    Call(DisablePlayerInput, TRUE)
    Thread
        Wait(17 * DT)
        Call(DisablePlayerPhysics, TRUE)
#if VERSION_PAL
        Call(SetPlayerSpeed, Float(4 / DT))
#else
        Call(SetPlayerSpeed, 4)
#endif
        Call(PlayerMoveTo, -300, 325, 0)
    EndThread
    Wait(5 * DT)
    Call(SetNpcJumpscale, NPC_BossFuzzy, Float(0.703))
    Call(SetNpcJumpscale, NPC_KoopersShell, Float(0.703))
    Thread
        Wait(20 * DT)
        Set(LVarA, 58)
        Set(LVarB, 0)
        Set(LVarC, 227)
        Set(LVarD, 80 * DT)
        Exec(N(EVS_MoveCam_TrackBoss))
    EndThread
    Set(LVarA, -260)
    Set(LVarB, 0)
    Set(LVarC, 290)
    Set(LVarD, 20 * DT)
    Exec(N(EVS_BossJumpTo))
    Wait(1)
    Call(NpcJump0, NPC_KoopersShell, LVarA, 0, 293, LVarD)
    Set(LVarA, -180)
    Set(LVarB, 0)
    Set(LVarC, 245)
    Set(LVarD, 15 * DT)
    Exec(N(EVS_BossJumpTo))
    Wait(1)
    Call(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 248, LVarD)
    Set(LVarA, -100)
    Set(LVarB, 0)
    Set(LVarC, 235)
    Set(LVarD, 15 * DT)
    Exec(N(EVS_BossJumpTo))
    Wait(1)
    Call(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 238, LVarD)
    Set(LVarA, 85)
    Set(LVarB, 0)
    Set(LVarC, 217)
    Set(LVarD, 30 * DT)
    Exec(N(EVS_BossJumpTo))
    Wait(1)
    Call(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 220, LVarD)
    Call(N(GetTreeHidingSpotPos), 2, LVar0, LVar1, LVar2)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar3)
    Set(LVarD, 30 * DT)
    Exec(N(EVS_BossJumpTo))
    Wait(1)
    Add(LVarC, 3)
    Call(NpcJump0, NPC_KoopersShell, LVarA, LVarB, LVarC, LVarD)
    Call(EnableNpcShadow, NPC_BossFuzzy, FALSE)
    Call(EnableNpcShadow, NPC_KoopersShell, FALSE)
    Call(N(AnimateTreeBranch), 2, 0)
    Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    Call(SetPlayerPos, -152, 0, 235)
    Call(PlayerMoveTo, 58, 227, 60 * DT)
    Set(LFlag0, TRUE)
    Exec(N(EVS_FuzzyBoss_TauntFromTree))
    Return
    End
};

EvtScript N(EVS_NpcIdle_WaitForWrongAnswer) = {
    Label(0)
        IfEq(MV_WrongAnswerBattle, 1)
            Call(StartBossBattle, SONG_SPECIAL_BATTLE)
            Label(1)
                IfEq(MV_WrongAnswerBattle, 1)
                    Wait(1)
                    Goto(1)
                EndIf
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Unused_RandomlyReveal) = {
    Call(RandInt, 399, LVar4)
    Div(LVar4, 100)
    Label(0)
        Call(RandInt, 300, LVar5)
        Switch(LVar5)
            CaseLt(100)
                Sub(LVar4, 1)
            CaseLt(200)
                Add(LVar4, 1)
        EndSwitch
        IfLt(LVar4, 0)
            Set(LVar4, 1)
        EndIf
        IfGt(LVar4, 3)
            Set(LVar4, 2)
        EndIf
        Call(N(GetTreeHidingSpotPos), LVar4, LVar0, LVar1, LVar2)
        Call(RandInt, 10, LVar3)
        Add(LVar3, 20)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_WrongFuzzy) = {
    Call(N(InitThreadData))
    Call(SetNpcAnimation, NPC_AmbushFuzzy, ANIM_Fuzzy_Anim0B)
    Call(N(GetTreeHidingSpotPos), MV_LastWrongTreeIndex, LVar0, LVar1, LVar2)
    Call(N(SetThreadAnchorPos), LVar0, LVar1, LVar2)
    Sub(LVar1, 50)
    Call(GetNpcPointer, NPC_AmbushFuzzy, LVar3)
    Call(N(AttachThreadFrontNpc), LVar3)
    Call(N(AttachThreadBackNpc), NULL)
    Call(N(SetThreadTargetLengthAngle), LVar1, 0, -1)
    Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    Call(N(SetThreadTargetLengthAngle), 0, 0, 30)
    Wait(30)
    Call(N(AttachThreadFrontNpc), NULL)
    Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
    Set(MV_WrongAnswerBattle, 0)
    Return
    End
};

EvtScript N(EVS_MoveShellUp) = {
    Set(LVar3, LVar0)
    Call(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_KoopersShell, LVar3, LVar0, LVar2)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_MoveShellDown) = {
    Set(LVar3, LVar0)
    Call(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_KoopersShell, LVar3, LVar0, LVar2)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_DoNothing) = {
    Label(10)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_NpcAI_StartBossBattle) = {
    IfEq(AF_NOK04_BattleStarted, FALSE)
        Call(StartBossBattle, SONG_SPECIAL_BATTLE)
        Set(AF_NOK04_BattleStarted, TRUE)
    EndIf
    Label(10)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_FuzzyBoss) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(AF_NOK04_BattleDone, TRUE)
            Set(AF_NOK04_CamPanDone, FALSE)
            Label(10)
                IfEq(AF_NOK04_CamPanDone, FALSE)
                    Wait(1)
                    Goto(10)
                EndIf
            Call(BindNpcAI, NPC_BossFuzzy, Ref(N(EVS_NpcAI_DoNothing)))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    Return
    End
};

s32 N(ShellChoiceDone) = FALSE;

API_CALLABLE(N(AwaitShellChoice)) {
    if (isInitialCall) {
        N(ShellChoiceDone) = FALSE;
    }

    if (N(ShellChoiceDone)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(SetShellChosen)) {
    N(ShellChoiceDone) = TRUE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ShellPrompt) = {
    Set(LFlagA, FALSE)
    Call(DisablePlayerInput, TRUE)
    Label(0)
        Call(ShowKeyChoicePopup)
        Call(CloseChoicePopup)
        IfNe(LVar0, 25)
            IfEq(LFlagA, FALSE)
                Set(LFlagA, TRUE)
                Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C5)
            Else
                Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C6)
            EndIf
            Goto(0)
        EndIf
    Call(RemoveKeyItemAt, LVar1)
    Call(N(SetShellChosen))
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

s32 N(ShellList)[] = {
    ITEM_KOOPER_SHELL,
    ITEM_NONE
};

EvtScript N(EVS_ChooseShell) = {
    BindPadlock(Ref(N(EVS_ShellPrompt)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(ShellList)), 0, 1)
    Call(N(AwaitShellChoice))
    Return
    End
};

EvtScript N(EVS_Scene_KooperArrives) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, -104)
        Sub(LVar2, 241)
        Mul(LVar0, -101)
        Mul(LVar2, 35)
        Add(LVar0, LVar2)
        IfLe(LVar0, 0)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_Kooper, -350, 0, 350)
    Call(UseSettingsFrom, CAM_DEFAULT, -220, 0, 270)
    Call(SetPanTarget, CAM_DEFAULT, -220, 0, 270)
    Call(GetCamDistance, CAM_DEFAULT, LVarA)
    MulF(LVarA, Float(0.703125))
    Call(SetCamDistance, CAM_DEFAULT, LVarA)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(20 * DT)
        Call(PlayerMoveTo, -205, 267, 40)
        Call(PlayerFaceNpc, NPC_Kooper, FALSE)
    EndThread
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_RunAngry)
    Call(NpcMoveTo, NPC_Kooper, -246, 290, 30)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_IdleAngry)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_TalkAngry, ANIM_KooperWithoutShell_IdleAngry, 0, MSG_CH1_00C3)
    Call(DisablePartnerAI, 0)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Kooper, 0)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00C4)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    ExecWait(N(EVS_ChooseShell))
    Call(PlayerMoveTo, -207, 268, 7)
    Call(PlayerFaceNpc, NPC_Kooper, FALSE)
    Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    Call(SetNpcJumpscale, NPC_KoopersShell, 1)
    Thread
        Loop(30)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, -15)
            Add(LVar1, 8)
            Add(LVar2, 12)
            Call(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C7)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    Call(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
    Call(PlayerFaceNpc, NPC_Kooper, FALSE)
    Call(NpcFacePlayer, NPC_Kooper, 0)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Still)
    Call(EnableNpcBlur, NPC_KoopersShell, TRUE)
    Call(GetNpcPos, NPC_Kooper, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 20)
    Set(LVar3, 1)
    Set(LVar4, 6)
    Exec(N(EVS_GetIntoShell))
    Call(InterpNpcYaw, LVar3, 60, 0)
    Call(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, 30 * DT)
    Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    Call(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Idle)
    Call(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Still)
    Wait(4 * DT)
    Call(EnableNpcBlur, NPC_KoopersShell, TRUE)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    Call(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Celebrate)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00C8)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00C9)
    Wait(10 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, -45, 50, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
    Wait(40 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00CA)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CB)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00CC)
    Call(EnablePartnerAI)
    Call(PlayerFaceNpc, NPC_Kooper, FALSE)
    Label(10)
        Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
        Call(ShowChoice, MSG_Choice_000F)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        IfEq(LVar0, 1)
            Call(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CD)
            Goto(10)
        Else
            Call(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CE)
            Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Celebrate)
            Wait(30 * DT)
            Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
            Call(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            Set(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EndIf
    Call(N(ChangeNpcToPartner), NPC_Kooper, PARTNER_KOOPER)
    Call(N(LoadPartyImage))
    Exec(N(EVS_PushPartnerSong))
    Wait(15 * DT)
    Call(ShowMessageAtScreenPos, MSG_Menus_018A, 160, 40)
    Exec(N(EVS_PopSong))
    Wait(10 * DT)
    Call(EnablePartnerAI)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(DisablePlayerInput, FALSE)
    Call(AwaitPlayerApproach, -400, 400, 100)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH1_00CF, 160, 40)
    Call(UseSettingsFrom, CAM_DEFAULT, -100, 0, 225)
    Call(SetPanTarget, CAM_DEFAULT, -100, 0, 225)
    Call(SetCamDistance, CAM_DEFAULT, -250)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Walk)
    Call(SetNpcPos, NPC_BossFuzzy, 63, 0, 212)
    Call(EnableNpcShadow, NPC_BossFuzzy, TRUE)
    Call(SetNpcJumpscale, NPC_BossFuzzy, Float(2.0))
    Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_BossFuzzy, -100, 0, 225, 20)
    Set(AF_NOK04_TauntMsgDone, FALSE)
    Set(AF_NOK04_FleeMsgDone, FALSE)
    Set(AF_NOK04_BattleDone, FALSE)
    Thread
        Call(ShowMessageAtScreenPos, MSG_CH1_00D0, 160, 40)
        Set(AF_NOK04_TauntMsgDone, TRUE)
    EndThread
    Call(GetNpcPos, NPC_BossFuzzy, LVarA, LVarB, LVarC)
    Label(30)
        Call(SetNpcJumpscale, NPC_BossFuzzy, Float(2.0))
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 12 * DT)
        IfEq(AF_NOK04_TauntMsgDone, FALSE)
            Goto(30)
        EndIf
    Thread
        Wait(27 * DT)
        Call(BindNpcDefeat, NPC_BossFuzzy, Ref(N(EVS_NpcDefeat_FuzzyBoss)))
        Call(BindNpcAI, NPC_BossFuzzy, Ref(N(EVS_NpcAI_StartBossBattle)))
    EndThread
    Thread
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, -212, 0, 237, 15 * DT)
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Add(LVarB, 37)
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 20 * DT)
        Wait(2)
        Call(SetPlayerAnimation, ANIM_MarioW2_PanicHoverStill)
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Label(21)
            IfEq(AF_NOK04_BattleDone, FALSE)
                Wait(1)
                Goto(21)
            EndIf
        Call(SetNpcPos, NPC_BossFuzzy, -255, 0, 287)
        Call(GetNpcPos, NPC_BossFuzzy, LVarA, LVarB, LVarC)
        Label(31)
            Call(SetNpcJumpscale, NPC_BossFuzzy, Float(2.0))
            Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
            IfEq(AF_NOK04_FleeMsgDone, FALSE)
                Goto(31)
            EndIf
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 20 * DT)
        Call(EnableNpcShadow, NPC_BossFuzzy, FALSE)
        Call(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    Call(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(2 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 2)
#endif
    Thread
        Wait(5 * DT)
        Call(SetNpcPos, NPC_Fuzzy_01, 63, 0, 212)
        Call(EnableNpcShadow, NPC_Fuzzy_01, TRUE)
        Call(SetNpcJumpscale, NPC_Fuzzy_01, Float(2.0))
        Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_01, -100, 0, 225, 10 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_01, -197, 0, 227, 20 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_01, -233, 0, 285, 10 * DT)
        Label(22)
            IfEq(AF_NOK04_BattleDone, FALSE)
                Wait(1)
                Goto(22)
            EndIf
        Call(SetNpcPos, NPC_Fuzzy_01, -210, 0, 244)
        Call(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
        Label(32)
            Call(SetNpcJumpscale, NPC_Fuzzy_01, Float(2.0))
            Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 12 * DT)
            IfEq(AF_NOK04_FleeMsgDone, FALSE)
                Goto(32)
            EndIf
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 10 * DT)
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 20 * DT)
        Call(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
        Call(SetNpcPos, NPC_Fuzzy_01, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(7 * DT)
        Call(SetNpcPos, NPC_Fuzzy_02, 63, 0, 212)
        Call(EnableNpcShadow, NPC_Fuzzy_02, TRUE)
        Call(SetNpcJumpscale, NPC_Fuzzy_02, Float(2.0))
        Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_02, -122, 0, 219, 20 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_02, -177, 0, 242, 10 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_02, -213, 0, 300, 15 * DT)
        Label(23)
            IfEq(AF_NOK04_BattleDone, FALSE)
                Wait(1)
                Goto(23)
            EndIf
        Call(SetNpcPos, NPC_Fuzzy_02, -210, 0, 266)
        Call(GetNpcPos, NPC_Fuzzy_02, LVarA, LVarB, LVarC)
        Wait(2)
        Label(33)
            Call(SetNpcJumpscale, NPC_Fuzzy_02, Float(2.0))
            Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 12 * DT)
            IfEq(AF_NOK04_FleeMsgDone, FALSE)
                Goto(33)
            EndIf
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 20 * DT)
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 15 * DT)
        Call(EnableNpcShadow, NPC_Fuzzy_02, FALSE)
        Call(SetNpcPos, NPC_Fuzzy_02, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(8 * DT)
        Call(SetNpcPos, NPC_Fuzzy_03, 63, 0, 212)
        Call(EnableNpcShadow, NPC_Fuzzy_03, TRUE)
        Call(SetNpcJumpscale, NPC_Fuzzy_03, Float(2.0))
        Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_03, -100, 0, 269, 20 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_03, -217, 0, 212, 10 * DT)
        Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_03, -253, 0, 270, 10 * DT)
        Label(24)
            IfEq(AF_NOK04_BattleDone, FALSE)
                Wait(1)
                Goto(24)
            EndIf
        Call(SetNpcPos, NPC_Fuzzy_03, -183, 0, 257)
        Call(GetNpcPos, NPC_Fuzzy_03, LVarA, LVarB, LVarC)
        Wait(5 * DT)
        Label(34)
            Call(SetNpcJumpscale, NPC_Fuzzy_03, Float(2.0))
            Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 12 * DT)
            IfEq(AF_NOK04_FleeMsgDone, FALSE)
                Goto(34)
            EndIf
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 15 * DT)
        Add(LVarA, 70)
        Add(LVarC, -30)
        Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 20 * DT)
        Call(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
        Call(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
    EndThread
    Label(40)
        IfEq(AF_NOK04_BattleDone, FALSE)
            Wait(1)
            Goto(40)
        EndIf
    Call(SetPlayerPos, -305, 0, 329)
    Call(InterpPlayerYaw, 50, 0)
    Call(SetNpcPos, NPC_PARTNER, -335, 0, 355)
    Call(InterpNpcYaw, NPC_PARTNER, 50, 0)
    Call(ShowMessageAtScreenPos, MSG_CH1_00D1, 160, 40)
    Set(AF_NOK04_FleeMsgDone, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    Call(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(15 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Set(AF_NOK04_CamPanDone, TRUE)
    Wait(30 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_HitTree_Correct) = {
    Thread
        Call(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Add(LVarA, LVar0)
        Add(LVarC, LVar2)
        Div(LVarA, 2)
        Div(LVarC, 2)
        Call(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(SetCamPitch, CAM_DEFAULT, 15, -11)
        Call(SetCamSpeed, CAM_DEFAULT, 3)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
    Call(GetNpcPointer, NPC_BossFuzzy, LVarE)
    Call(GetNpcPointer, NPC_KoopersShell, LVarF)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Switch(MV_CorrectCount)
        CaseEq(0)
            Set(LVar4, LVarC)
            Sub(LVar4, 4)
            Call(N(SetThreadAnchorPos), LVarA, LVarB, LVar4)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            Set(LVar3, LVarB)
            Div(LVar3, 2)
            Set(LVarD, LVarB)
            Sub(LVarD, LVar3)
            Exec(N(EVS_MoveShellDown))
            Wait(1)
            Wait(30)
            Call(N(AttachThreadFrontNpc), NULL)
            Call(N(AttachThreadBackNpc), NULL)
            Call(N(SetThreadTargetLengthAngle), 0, 0, -1)
            Call(N(SetThreadTargetLengthAngle), LVar3, 0, -1)
            Wait(1)
            Call(N(AttachThreadFrontNpc), LVarF)
            Wait(20)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            Call(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            Call(SetNpcJumpscale, NPC_BossFuzzy, 0)
            Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarD, LVarC, 30)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            Set(LVar9, LVarC)
            Call(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00BF)
            Call(N(SetThreadTargetLengthAngle), 0, 0, 30)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            Set(LVarC, LVar9)
            Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 30)
            Call(N(AttachThreadFrontNpc), NULL)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            Add(MV_CorrectCount, 1)
            Exec(N(EVS_Scene_ShuffleFuzzyPositions))
            Return
        CaseEq(1)
            Set(LVar4, LVarC)
            Sub(LVar4, 4)
            Call(N(SetThreadAnchorPos), LVarA, LVarB, LVar4)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            Set(LVar3, LVarB)
            Mul(LVar3, 2)
            Div(LVar3, 3)
            Set(LVarD, LVarB)
            Sub(LVarD, LVar3)
            Exec(N(EVS_MoveShellUp))
            Wait(1)
            Wait(30)
            Call(N(AttachThreadFrontNpc), NULL)
            Call(N(AttachThreadBackNpc), NULL)
            Call(N(SetThreadTargetLengthAngle), 0, 0, -1)
            Call(N(SetThreadTargetLengthAngle), LVar3, 0, -1)
            Wait(1)
            Call(N(AttachThreadFrontNpc), LVarF)
            Wait(20)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            Call(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            Call(SetNpcJumpscale, NPC_BossFuzzy, 0)
            Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarD, LVarC, 30)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            Set(LVar9, LVarC)
            Call(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C0)
            Call(N(SetThreadTargetLengthAngle), 0, 0, 30)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            Set(LVarC, LVar9)
            Call(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 30)
            Call(N(AttachThreadFrontNpc), NULL)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            Add(MV_CorrectCount, 1)
            Exec(N(EVS_Scene_ShuffleFuzzyPositions))
            Return
        CaseEq(2)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            Call(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            Call(N(SetThreadAnchorPos), LVarA, LVarB, LVarC)
            Call(N(SetThreadTargetLengthAngle), 0, 0, -1)
            Set(LVar0, LVarB)
            Sub(LVar0, 50)
            Call(N(SetThreadTargetLengthAngle), LVar0, 0, 0)
            Call(N(AttachThreadFrontNpc), LVarF)
            Call(N(AttachThreadBackNpc), LVarE)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            Wait(20)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            Call(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C1)
            Wait(10 * DT)
            Call(N(AttachThreadFrontNpc), NULL)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 40)
            Call(SetNpcJumpscale, NPC_KoopersShell, Float(0.6))
            Call(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, 10 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_GetItem)
            Thread
                Wait(4 * DT)
                Call(GetPlayerPos, LVar3, LVar4, LVar5)
                Add(LVar4, 50)
                Add(LVar5, 2)
                Add(LVar3, 8)
                PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
                Add(LVar3, -16)
                PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
            EndThread
            Call(PlaySound, SOUND_JINGLE_GOT_KEY)
            Call(ShowMessageAtScreenPos, MSG_Menus_GotKooperShell, 160, 40)
            Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(AddKeyItem, ITEM_KOOPER_SHELL)
            Wait(10 * DT)
            Call(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C2)
            Call(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            Call(N(SetThreadTargetLengthAngle), 0, 0, 20 * DT)
            Wait(20 * DT)
            Call(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            Call(N(AttachThreadBackNpc), 0)
            Call(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
            Call(DisablePlayerPhysics, FALSE)
            Call(DisablePlayerInput, FALSE)
            Set(AF_NOK04_PlayingGame, FALSE)
            Exec(N(EVS_Scene_KooperArrives))
    EndSwitch
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Return
    End
};

EvtScript N(EVS_HitTree_Wrong) = {
    Thread
        Call(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Add(LVarA, LVar0)
        Add(LVarC, LVar2)
        Div(LVarA, 2)
        Div(LVarC, 2)
        Call(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(SetCamPitch, CAM_DEFAULT, 15, -11)
        Call(SetCamSpeed, CAM_DEFAULT, 3)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Wait(15)
    Set(MV_LastWrongTreeIndex, LVar0)
    Call(N(GetTreeHidingSpotPos), MV_LastWrongTreeIndex, LVar0, LVar1, LVar2)
    Call(GetNpcPointer, NPC_KoopersShell, LVarF)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(RandInt, 999, LVar0)
    Switch(LVar0)
        CaseLt(200)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(MakeItemEntity, ITEM_HEART, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            Wait(30)
        CaseLt(400)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(MakeItemEntity, ITEM_COIN, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            Wait(30)
        CaseLt(1000)
            Call(SetNpcAnimation, NPC_AmbushFuzzy, ANIM_Fuzzy_Anim06)
            Call(SetNpcJumpscale, NPC_AmbushFuzzy, 1)
            Call(SetNpcPos, NPC_AmbushFuzzy, LVarA, LVarB, LVarC)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar2, 10)
            Add(LVar1, 10)
            Call(PlaySoundAtNpc, NPC_AmbushFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_AmbushFuzzy, LVar0, LVar1, LVar2, 20)
            Set(MV_WrongAnswerBattle, 1)
    EndSwitch
    Label(0)
        IfEq(MV_WrongAnswerBattle, 1)
            Wait(1)
            Goto(0)
        EndIf
    Wait(20)
    Exec(N(EVS_Scene_ShuffleFuzzyPositions))
    Return
    End
};

EvtScript N(EVS_HitTree) = {
    Call(N(AnimateTreeBranch), LVar0, 1)
    Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    IfEq(AF_NOK04_PlayingGame, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Thread
        Wait(20)
        Call(DisablePlayerPhysics, TRUE)
    EndThread
    IfEq(LVar0, MV_CorrectTreeIndex)
        Thread
            Wait(15)
            Call(PlaySound, SOUND_APPROVE)
        EndThread
        ExecWait(N(EVS_HitTree_Correct))
    Else
        Thread
            Wait(15)
            Call(PlaySound, SOUND_MENU_ERROR)
        EndThread
        ExecWait(N(EVS_HitTree_Wrong))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kooper) = {
    Return
    End
};

EvtScript N(EVS_SetupMinigame) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_HideInTree)))
    IfGe(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    Set(MV_CorrectCount, 0)
    Set(MV_CorrectTreeIndex, 2)
    Set(MV_LastCorrectTreeIndex, 2)
    Call(N(InitThreadData))
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, NULL, Ref(N(build_gfx_thread)))
    Call(SetNpcPos, NPC_BossFuzzy, -293, 0, 319)
    Call(SetNpcPos, NPC_KoopersShell, -293, 0, 322)
    Call(EnableNpcShadow, NPC_AmbushFuzzy, FALSE)
    Call(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
    Call(EnableNpcShadow, NPC_Fuzzy_02, FALSE)
    Call(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
    Call(SetModelFlags, MODEL_o177, MODEL_FLAG_DO_BOUNDS_CULLING, FALSE)
    IfGe(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        Call(N(GetTreeHidingSpotPos), LVar4, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_BossFuzzy, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
        Call(EnableNpcShadow, NPC_BossFuzzy, FALSE)
        Call(EnableNpcShadow, NPC_KoopersShell, FALSE)
    EndIf
    Wait(1)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    Return
    End
};

EvtScript N(EVS_NpcInit_WrongFuzzy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_WaitForWrongAnswer)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_WrongFuzzy)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy_Aux) = {
    Call(BindNpcIdle, NPC_SELF, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kooper) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kooper)))
    IfGe(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
            Call(InterpNpcYaw, NPC_Kooper, 225, 0)
            Call(SetNpcPos, NPC_Kooper, -275, 0, 305)
            Return
        EndIf
    EndIf
    Call(SetNpcSprite, NPC_Kooper, ANIM_KooperWithoutShell_IdleAngry)
    Return
    End
};

NpcData N(NpcData_Minigame)[] = {
    {
        .id = NPC_KoopersShell,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopersShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
    },
    {
        .id = NPC_AmbushFuzzy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_WrongFuzzy),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_Fuzzy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Fuzzy_Aux),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_Fuzzy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Fuzzy_Aux),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_Fuzzy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Fuzzy_Aux),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_Kooper,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kooper),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
    },
};

NpcData N(NpcData_Miniboss) = {
    .id = NPC_BossFuzzy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_SetupMinigame),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Minigame), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_03),
    NPC_GROUP(N(NpcData_Miniboss), BTL_NOK_FORMATION_17, BTL_NOK_STAGE_03),
    {}
};
