
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
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_SET(LVar4, 600)
    EVT_DIV(LVar4, 100)
    EVT_ADD(LVar4, 27)
    EVT_CALL(RandInt, 1, LVar5)
    EVT_MUL(LVar5, 20)
    EVT_SUB(LVar5, 10)
    EVT_SET(LVar6, 0)
    EVT_SETF(LVar8, EVT_FLOAT(5.0))
    EVT_CALL(MakeLerp, LVar5, 0, LVar4, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_MULF(LVar0, EVT_FLOAT(0.40625))
        EVT_ADD(LVar6, 1)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, EVT_FLOAT(-1.0))
        EVT_CALL(N(CosInterpMinMax), LVar6, LVar7, LVar9, LVar8, 3, 0, 0)
        EVT_MULF(LVar8, EVT_FLOAT(0.90625))
        EVT_CALL(TranslateModel, LVar2, LVar7, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBranch_Hit) = {
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_SET(LVar4, 600)
    EVT_DIV(LVar4, 100)
    EVT_ADD(LVar4, 27)
    EVT_SET(LVar0, 5)
    EVT_LOOP(LVar0)
        EVT_CALL(TranslateModel, LVar2, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_SET(LVar1, LVar0)
        EVT_MUL(LVar1, -1)
        EVT_CALL(TranslateModel, LVar2, LVar1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveCam_TrackBoss) = {
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarA, LVarB, LVarC, LVarD)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, LVarD)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ShuffleFuzzyPositions) = {
    EVT_CALL(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00BE, 160, 40)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -597)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 10, -11)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 707)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 90, 0, 228)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, 3)
    EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_02, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, 3)
    // get number of jumps
    EVT_SWITCH(MV_CorrectCount)
        EVT_CASE_EQ(0)
            EVT_SET(LVarE, 10)
        EVT_CASE_EQ(1)
            EVT_SET(LVarE, 9)
        EVT_CASE_EQ(2)
            EVT_SET(LVarE, 8)
    EVT_END_SWITCH
    EVT_CALL(RandInt, 3, LVar0)
    EVT_ADD(LVarE, LVar0)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 0)
    EVT_SET(LVarF, MV_CorrectTreeIndex)
    // the shuffle
    EVT_LOOP(LVarE)
        EVT_SET(LVarA, MV_CorrectTreeIndex)
        EVT_CALL(N(EVS_ConvertTreeIndex), LVarF, MV_CorrectTreeIndex)
        EVT_SWITCH(LVarF)
            EVT_CASE_EQ(0)
                EVT_SET(LVarB, TREE_2)
                EVT_SET(LVarC, TREE_3)
            EVT_CASE_EQ(1)
                EVT_IF_EQ(LVarA, 2)
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_3)
                EVT_ELSE
                    EVT_SET(LVarB, TREE_2)
                    EVT_SET(LVarC, TREE_3)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_1)
                EVT_ELSE
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_3)
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_SET(LVarB, TREE_0)
                EVT_SET(LVarC, TREE_1)
            EVT_CASE_EQ(4)
                EVT_IF_EQ(LVarA, 1)
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_3)
                EVT_ELSE
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_1)
                EVT_END_IF
            EVT_CASE_EQ(5)
                EVT_IF_EQ(LVarA, 0)
                    EVT_SET(LVarB, TREE_2)
                    EVT_SET(LVarC, TREE_3)
                EVT_ELSE
                    EVT_SET(LVarB, TREE_0)
                    EVT_SET(LVarC, TREE_3)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(RandInt, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_ADD(LVarF, -1)
        EVT_ELSE
            EVT_ADD(LVarF, 1)
        EVT_END_IF
        EVT_IF_GE(LVarF, 6)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_IF_LT(LVarF, 0)
            EVT_SET(LVarF, 5)
        EVT_END_IF
        // get time for each jump
        EVT_SWITCH(MV_CorrectCount)
            EVT_CASE_EQ(0)
                EVT_SET(LVarD, 15)
            EVT_CASE_EQ(1)
                EVT_SET(LVarD, 10)
            EVT_CASE_EQ(2)
                EVT_SET(LVarD, 6)
        EVT_END_SWITCH
        EVT_SET(LVar0, ANIM_Fuzzy_Jump)
        EVT_CALL(RandInt, 2, LVar1)
        EVT_ADD(LVar0, LVar1)
        EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_02, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_03, LVar0)
        EVT_CALL(PlaySound, SOUND_SEQ_FUZZY_HOP)
        EVT_THREAD
            EVT_CALL(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVar0, LVar1, LVar2, LVarD)
        EVT_END_THREAD
        EVT_IF_NE(MV_CorrectTreeIndex, LVarA)
            EVT_THREAD
                EVT_CALL(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
                EVT_CALL(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_SET(LFlag0, FALSE)
            EVT_IF_EQ(LVarB, 0)
                EVT_IF_EQ(LVarC, 3)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_THREAD
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
            EVT_ELSE
                EVT_THREAD
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                    EVT_CALL(N(GetTreeHidingSpotPos), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
            EVT_END_IF
        EVT_ELSE
            EVT_THREAD
                EVT_ADD(LVarA, 1)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_THREAD
                EVT_ADD(LVarA, 2)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_02, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_THREAD
                EVT_ADD(LVarA, 3)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(GetTreeHidingSpotPos), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT(2)
        EVT_CALL(N(GetTreeHidingSpotPos), MV_CorrectTreeIndex, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 2)
        EVT_CALL(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, LVarD)
        EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_02, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_03, ANIM_Fuzzy_Still)
        EVT_CALL(N(AnimateTreeBranch), TREE_0, 0)
        EVT_CALL(N(AnimateTreeBranch), TREE_1, 0)
        EVT_CALL(N(AnimateTreeBranch), TREE_2, 0)
        EVT_CALL(N(AnimateTreeBranch), TREE_3, 0)
        EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FuzzyBoss_TauntFromTree) = {
    EVT_SET(AF_NOK04_PlayingGame, TRUE)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_WAIT(20 * DT)
            EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(N(AnimateTreeBranch), 2, 0)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
    EVT_CALL(N(GetTreeHidingSpotPos), 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetThreadAnchorPos), LVar0, LVar1, LVar2)
    EVT_CALL(N(SetThreadTargetLengthAngle), 50, 0, 0)
    EVT_CALL(GetNpcPointer, NPC_BossFuzzy, LVar0)
    EVT_CALL(GetNpcPointer, NPC_KoopersShell, LVar1)
    EVT_CALL(N(AttachThreadBackNpc), LVar0)
    EVT_CALL(N(AttachThreadFrontNpc), LVar1)
    EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_SET(LVar0, MSG_CH1_00BC)
        EVT_SET(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH1_00BD)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, LVar0)
    EVT_CALL(SetMusicTrack, 0, SONG_PLAYROOM, 0, 8)
    EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, 30 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
    EVT_CALL(N(AttachThreadFrontNpc), NULL)
    EVT_CALL(N(AttachThreadBackNpc), NULL)
    EVT_EXEC(N(EVS_Scene_ShuffleFuzzyPositions))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_HideInTree) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
            EVT_LABEL(0)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_LT(LVar0, 60)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_EXEC(N(EVS_FuzzyBoss_TauntFromTree))
            EVT_RETURN
        EVT_CASE_GE(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(17 * DT)
        EVT_CALL(DisablePlayerPhysics, TRUE)
#if VERSION_PAL
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4 / DT))
#else
        EVT_CALL(SetPlayerSpeed, 4)
#endif
        EVT_CALL(PlayerMoveTo, -300, 325, 0)
    EVT_END_THREAD
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, EVT_FLOAT(0.703))
    EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, EVT_FLOAT(0.703))
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_SET(LVarA, 58)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 227)
        EVT_SET(LVarD, 80 * DT)
        EVT_EXEC(N(EVS_MoveCam_TrackBoss))
    EVT_END_THREAD
    EVT_SET(LVarA, -260)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 290)
    EVT_SET(LVarD, 20 * DT)
    EVT_EXEC(N(EVS_BossJumpTo))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVarA, 0, 293, LVarD)
    EVT_SET(LVarA, -180)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 245)
    EVT_SET(LVarD, 15 * DT)
    EVT_EXEC(N(EVS_BossJumpTo))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 248, LVarD)
    EVT_SET(LVarA, -100)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 235)
    EVT_SET(LVarD, 15 * DT)
    EVT_EXEC(N(EVS_BossJumpTo))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 238, LVarD)
    EVT_SET(LVarA, 85)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 217)
    EVT_SET(LVarD, 30 * DT)
    EVT_EXEC(N(EVS_BossJumpTo))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVarA, LVarB, 220, LVarD)
    EVT_CALL(N(GetTreeHidingSpotPos), 2, LVar0, LVar1, LVar2)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar3)
    EVT_SET(LVarD, 30 * DT)
    EVT_EXEC(N(EVS_BossJumpTo))
    EVT_WAIT(1)
    EVT_ADD(LVarC, 3)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(EnableNpcShadow, NPC_BossFuzzy, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_KoopersShell, FALSE)
    EVT_CALL(N(AnimateTreeBranch), 2, 0)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_CALL(SetPlayerPos, -152, 0, 235)
    EVT_CALL(PlayerMoveTo, 58, 227, 60 * DT)
    EVT_SET(LFlag0, TRUE)
    EVT_EXEC(N(EVS_FuzzyBoss_TauntFromTree))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_WaitForWrongAnswer) = {
    EVT_LABEL(0)
        EVT_IF_EQ(MV_WrongAnswerBattle, 1)
            EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
            EVT_LABEL(1)
                EVT_IF_EQ(MV_WrongAnswerBattle, 1)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Unused_RandomlyReveal) = {
    EVT_CALL(RandInt, 399, LVar4)
    EVT_DIV(LVar4, 100)
    EVT_LABEL(0)
        EVT_CALL(RandInt, 300, LVar5)
        EVT_SWITCH(LVar5)
            EVT_CASE_LT(100)
                EVT_SUB(LVar4, 1)
            EVT_CASE_LT(200)
                EVT_ADD(LVar4, 1)
        EVT_END_SWITCH
        EVT_IF_LT(LVar4, 0)
            EVT_SET(LVar4, 1)
        EVT_END_IF
        EVT_IF_GT(LVar4, 3)
            EVT_SET(LVar4, 2)
        EVT_END_IF
        EVT_CALL(N(GetTreeHidingSpotPos), LVar4, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_WrongFuzzy) = {
    EVT_CALL(N(InitThreadData))
    EVT_CALL(SetNpcAnimation, NPC_AmbushFuzzy, ANIM_Fuzzy_Anim0B)
    EVT_CALL(N(GetTreeHidingSpotPos), MV_LastWrongTreeIndex, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetThreadAnchorPos), LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 50)
    EVT_CALL(GetNpcPointer, NPC_AmbushFuzzy, LVar3)
    EVT_CALL(N(AttachThreadFrontNpc), LVar3)
    EVT_CALL(N(AttachThreadBackNpc), NULL)
    EVT_CALL(N(SetThreadTargetLengthAngle), LVar1, 0, -1)
    EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, 30)
    EVT_WAIT(30)
    EVT_CALL(N(AttachThreadFrontNpc), NULL)
    EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
    EVT_SET(MV_WrongAnswerBattle, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveShellUp) = {
    EVT_SET(LVar3, LVar0)
    EVT_CALL(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, LVar3, LVar0, LVar2)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveShellDown) = {
    EVT_SET(LVar3, LVar0)
    EVT_CALL(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, LVar3, LVar0, LVar2)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_DoNothing) = {
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_StartBossBattle) = {
    EVT_IF_EQ(AF_NOK04_BattleStarted, FALSE)
        EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
        EVT_SET(AF_NOK04_BattleStarted, TRUE)
    EVT_END_IF
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_FuzzyBoss) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(AF_NOK04_BattleDone, TRUE)
            EVT_SET(AF_NOK04_CamPanDone, FALSE)
            EVT_LABEL(10)
                EVT_IF_EQ(AF_NOK04_CamPanDone, FALSE)
                    EVT_WAIT(1)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_CALL(BindNpcAI, NPC_BossFuzzy, EVT_PTR(N(EVS_NpcAI_DoNothing)))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_SET(LFlagA, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(0)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_IF_NE(LVar0, 25)
            EVT_IF_EQ(LFlagA, FALSE)
                EVT_SET(LFlagA, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C5)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C6)
            EVT_END_IF
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(N(SetShellChosen))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(ShellList)[] = {
    ITEM_KOOPER_SHELL,
    ITEM_NONE
};

EvtScript N(EVS_ChooseShell) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ShellPrompt)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(ShellList)), 0, 1)
    EVT_CALL(N(AwaitShellChoice))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KooperArrives) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, -104)
        EVT_SUB(LVar2, 241)
        EVT_MUL(LVar0, -101)
        EVT_MUL(LVar2, 35)
        EVT_ADD(LVar0, LVar2)
        EVT_IF_LE(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Kooper, -350, 0, 350)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -220, 0, 270)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -220, 0, 270)
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVarA)
    EVT_MULF(LVarA, EVT_FLOAT(0.703125))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVarA)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(PlayerMoveTo, -205, 267, 40)
        EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_RunAngry)
    EVT_CALL(NpcMoveTo, NPC_Kooper, -246, 290, 30)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_IdleAngry)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_TalkAngry, ANIM_KooperWithoutShell_IdleAngry, 0, MSG_CH1_00C3)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kooper, 0)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00C4)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    EVT_EXEC_WAIT(N(EVS_ChooseShell))
    EVT_CALL(PlayerMoveTo, -207, 268, 7)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, 1)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, -15)
            EVT_ADD(LVar1, 8)
            EVT_ADD(LVar2, 12)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C7)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    EVT_CALL(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Kooper, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_KoopersShell, TRUE)
    EVT_CALL(GetNpcPos, NPC_Kooper, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, 1)
    EVT_SET(LVar4, 6)
    EVT_EXEC(N(EVS_GetIntoShell))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, 30 * DT)
    EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Still)
    EVT_WAIT(4 * DT)
    EVT_CALL(EnableNpcBlur, NPC_KoopersShell, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    EVT_CALL(SetNpcSprite, NPC_Kooper, ANIM_WorldKooper_Celebrate)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00C8)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00C9)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 50, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00CA)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CB)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper, MSG_CH1_00CC)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper, FALSE)
    EVT_LABEL(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
        EVT_CALL(ShowChoice, MSG_Choice_000F)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CD)
            EVT_GOTO(10)
        EVT_ELSE
            EVT_CALL(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CE)
            EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Celebrate)
            EVT_WAIT(30 * DT)
            EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
            EVT_CALL(EndSpeech, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
            EVT_SET(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_END_IF
    EVT_CALL(N(ChangeNpcToPartner), NPC_Kooper, PARTNER_KOOPER)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushPartnerSong))
    EVT_WAIT(15 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018A, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerApproach, -400, 400, 100)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00CF, 160, 40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 0, 225)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 0, 225)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -250)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Walk)
    EVT_CALL(SetNpcPos, NPC_BossFuzzy, 63, 0, 212)
    EVT_CALL(EnableNpcShadow, NPC_BossFuzzy, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, EVT_FLOAT(2.0))
    EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_BossFuzzy, -100, 0, 225, 20)
    EVT_SET(AF_NOK04_TauntMsgDone, FALSE)
    EVT_SET(AF_NOK04_FleeMsgDone, FALSE)
    EVT_SET(AF_NOK04_BattleDone, FALSE)
    EVT_THREAD
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00D0, 160, 40)
        EVT_SET(AF_NOK04_TauntMsgDone, TRUE)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_BossFuzzy, LVarA, LVarB, LVarC)
    EVT_LABEL(30)
        EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 12 * DT)
        EVT_IF_EQ(AF_NOK04_TauntMsgDone, FALSE)
            EVT_GOTO(30)
        EVT_END_IF
    EVT_THREAD
        EVT_WAIT(27 * DT)
        EVT_CALL(BindNpcDefeat, NPC_BossFuzzy, EVT_PTR(N(EVS_NpcDefeat_FuzzyBoss)))
        EVT_CALL(BindNpcAI, NPC_BossFuzzy, EVT_PTR(N(EVS_NpcAI_StartBossBattle)))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, -212, 0, 237, 15 * DT)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_ADD(LVarB, 37)
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 20 * DT)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicHoverStill)
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_LABEL(21)
            EVT_IF_EQ(AF_NOK04_BattleDone, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(21)
            EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_BossFuzzy, -255, 0, 287)
        EVT_CALL(GetNpcPos, NPC_BossFuzzy, LVarA, LVarB, LVarC)
        EVT_LABEL(31)
            EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
            EVT_IF_EQ(AF_NOK04_FleeMsgDone, FALSE)
                EVT_GOTO(31)
            EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 15 * DT)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 20 * DT)
        EVT_CALL(EnableNpcShadow, NPC_BossFuzzy, FALSE)
        EVT_CALL(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 2)
#endif
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, -100, 0, 225, 10 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, -197, 0, 227, 20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, -233, 0, 285, 10 * DT)
        EVT_LABEL(22)
            EVT_IF_EQ(AF_NOK04_BattleDone, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(22)
            EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, -210, 0, 244)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
        EVT_LABEL(32)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 12 * DT)
            EVT_IF_EQ(AF_NOK04_FleeMsgDone, FALSE)
                EVT_GOTO(32)
            EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 10 * DT)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 20 * DT)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(7 * DT)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_02, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_02, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_02, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, -122, 0, 219, 20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, -177, 0, 242, 10 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, -213, 0, 300, 15 * DT)
        EVT_LABEL(23)
            EVT_IF_EQ(AF_NOK04_BattleDone, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(23)
            EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_02, -210, 0, 266)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_02, LVarA, LVarB, LVarC)
        EVT_WAIT(2)
        EVT_LABEL(33)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_02, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 12 * DT)
            EVT_IF_EQ(AF_NOK04_FleeMsgDone, FALSE)
                EVT_GOTO(33)
            EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 20 * DT)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVarA, LVarB, LVarC, 15 * DT)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_02, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_02, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(8 * DT)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -100, 0, 269, 20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -217, 0, 212, 10 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -253, 0, 270, 10 * DT)
        EVT_LABEL(24)
            EVT_IF_EQ(AF_NOK04_BattleDone, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(24)
            EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, -183, 0, 257)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_03, LVarA, LVarB, LVarC)
        EVT_WAIT(5 * DT)
        EVT_LABEL(34)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 12 * DT)
            EVT_IF_EQ(AF_NOK04_FleeMsgDone, FALSE)
                EVT_GOTO(34)
            EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 15 * DT)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 20 * DT)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_LABEL(40)
        EVT_IF_EQ(AF_NOK04_BattleDone, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_CALL(SetPlayerPos, -305, 0, 329)
    EVT_CALL(InterpPlayerYaw, 50, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -335, 0, 355)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 50, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00D1, 160, 40)
    EVT_SET(AF_NOK04_FleeMsgDone, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(15 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(AF_NOK04_CamPanDone, TRUE)
    EVT_WAIT(30 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitTree_Correct) = {
    EVT_THREAD
        EVT_CALL(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, LVar0)
        EVT_ADD(LVarC, LVar2)
        EVT_DIV(LVarA, 2)
        EVT_DIV(LVarC, 2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -11)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPointer, NPC_BossFuzzy, LVarE)
    EVT_CALL(GetNpcPointer, NPC_KoopersShell, LVarF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SWITCH(MV_CorrectCount)
        EVT_CASE_EQ(0)
            EVT_SET(LVar4, LVarC)
            EVT_SUB(LVar4, 4)
            EVT_CALL(N(SetThreadAnchorPos), LVarA, LVarB, LVar4)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            EVT_SET(LVar3, LVarB)
            EVT_DIV(LVar3, 2)
            EVT_SET(LVarD, LVarB)
            EVT_SUB(LVarD, LVar3)
            EVT_EXEC(N(EVS_MoveShellDown))
            EVT_WAIT(1)
            EVT_WAIT(30)
            EVT_CALL(N(AttachThreadFrontNpc), NULL)
            EVT_CALL(N(AttachThreadBackNpc), NULL)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, -1)
            EVT_CALL(N(SetThreadTargetLengthAngle), LVar3, 0, -1)
            EVT_WAIT(1)
            EVT_CALL(N(AttachThreadFrontNpc), LVarF)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, 0)
            EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarD, LVarC, 30)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            EVT_SET(LVar9, LVarC)
            EVT_CALL(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00BF)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, 30)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            EVT_SET(LVarC, LVar9)
            EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 30)
            EVT_CALL(N(AttachThreadFrontNpc), NULL)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            EVT_ADD(MV_CorrectCount, 1)
            EVT_EXEC(N(EVS_Scene_ShuffleFuzzyPositions))
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_SET(LVar4, LVarC)
            EVT_SUB(LVar4, 4)
            EVT_CALL(N(SetThreadAnchorPos), LVarA, LVarB, LVar4)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            EVT_SET(LVar3, LVarB)
            EVT_MUL(LVar3, 2)
            EVT_DIV(LVar3, 3)
            EVT_SET(LVarD, LVarB)
            EVT_SUB(LVarD, LVar3)
            EVT_EXEC(N(EVS_MoveShellUp))
            EVT_WAIT(1)
            EVT_WAIT(30)
            EVT_CALL(N(AttachThreadFrontNpc), NULL)
            EVT_CALL(N(AttachThreadBackNpc), NULL)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, -1)
            EVT_CALL(N(SetThreadTargetLengthAngle), LVar3, 0, -1)
            EVT_WAIT(1)
            EVT_CALL(N(AttachThreadFrontNpc), LVarF)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            EVT_CALL(SetNpcJumpscale, NPC_BossFuzzy, 0)
            EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarD, LVarC, 30)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            EVT_SET(LVar9, LVarC)
            EVT_CALL(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C0)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, 30)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            EVT_SET(LVarC, LVar9)
            EVT_CALL(PlaySoundAtNpc, NPC_BossFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_BossFuzzy, LVarA, LVarB, LVarC, 30)
            EVT_CALL(N(AttachThreadFrontNpc), NULL)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            EVT_ADD(MV_CorrectCount, 1)
            EVT_EXEC(N(EVS_Scene_ShuffleFuzzyPositions))
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_BossFuzzy, FALSE)
            EVT_CALL(N(SetThreadAnchorPos), LVarA, LVarB, LVarC)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, -1)
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 50)
            EVT_CALL(N(SetThreadTargetLengthAngle), LVar0, 0, 0)
            EVT_CALL(N(AttachThreadFrontNpc), LVarF)
            EVT_CALL(N(AttachThreadBackNpc), LVarE)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim09)
            EVT_CALL(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C1)
            EVT_WAIT(10 * DT)
            EVT_CALL(N(AttachThreadFrontNpc), NULL)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetNpcJumpscale, NPC_KoopersShell, EVT_FLOAT(0.6))
            EVT_CALL(NpcJump0, NPC_KoopersShell, LVar0, LVar1, LVar2, 10 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetItem)
            EVT_THREAD
                EVT_WAIT(4 * DT)
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_ADD(LVar4, 50)
                EVT_ADD(LVar5, 2)
                EVT_ADD(LVar3, 8)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
                EVT_ADD(LVar3, -16)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
            EVT_END_THREAD
            EVT_CALL(PlaySound, SOUND_JINGLE_GOT_KEY)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_GotKooperShell, 160, 40)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(AddKeyItem, ITEM_KOOPER_SHELL)
            EVT_WAIT(10 * DT)
            EVT_CALL(SpeakToPlayer, NPC_BossFuzzy, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C2)
            EVT_CALL(SetNpcAnimation, NPC_BossFuzzy, ANIM_Fuzzy_Anim0B)
            EVT_CALL(N(SetThreadTargetLengthAngle), 0, 0, 20 * DT)
            EVT_WAIT(20 * DT)
            EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_USES_CUSTOM_GFX, FALSE)
            EVT_CALL(N(AttachThreadBackNpc), 0)
            EVT_CALL(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(AF_NOK04_PlayingGame, FALSE)
            EVT_EXEC(N(EVS_Scene_KooperArrives))
    EVT_END_SWITCH
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitTree_Wrong) = {
    EVT_THREAD
        EVT_CALL(N(GetTreeHidingSpotPos), LVar0, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, LVar0)
        EVT_ADD(LVarC, LVar2)
        EVT_DIV(LVarA, 2)
        EVT_DIV(LVarC, 2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -11)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_SET(MV_LastWrongTreeIndex, LVar0)
    EVT_CALL(N(GetTreeHidingSpotPos), MV_LastWrongTreeIndex, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPointer, NPC_KoopersShell, LVarF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(RandInt, 999, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(200)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_HEART, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            EVT_WAIT(30)
        EVT_CASE_LT(400)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            EVT_WAIT(30)
        EVT_CASE_LT(1000)
            EVT_CALL(SetNpcAnimation, NPC_AmbushFuzzy, ANIM_Fuzzy_Anim06)
            EVT_CALL(SetNpcJumpscale, NPC_AmbushFuzzy, 1)
            EVT_CALL(SetNpcPos, NPC_AmbushFuzzy, LVarA, LVarB, LVarC)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, 10)
            EVT_ADD(LVar1, 10)
            EVT_CALL(PlaySoundAtNpc, NPC_AmbushFuzzy, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_AmbushFuzzy, LVar0, LVar1, LVar2, 20)
            EVT_SET(MV_WrongAnswerBattle, 1)
    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_IF_EQ(MV_WrongAnswerBattle, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_Scene_ShuffleFuzzyPositions))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitTree) = {
    EVT_CALL(N(AnimateTreeBranch), LVar0, 1)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_IF_EQ(AF_NOK04_PlayingGame, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_END_THREAD
    EVT_IF_EQ(LVar0, MV_CorrectTreeIndex)
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_APPROVE)
        EVT_END_THREAD
        EVT_EXEC_WAIT(N(EVS_HitTree_Correct))
    EVT_ELSE
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_END_THREAD
        EVT_EXEC_WAIT(N(EVS_HitTree_Wrong))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kooper) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMinigame) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_HideInTree)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetNpcPos, NPC_BossFuzzy, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_CorrectCount, 0)
    EVT_SET(MV_CorrectTreeIndex, 2)
    EVT_SET(MV_LastCorrectTreeIndex, 2)
    EVT_CALL(N(InitThreadData))
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, NULL, EVT_PTR(N(build_gfx_thread)))
    EVT_CALL(SetNpcPos, NPC_BossFuzzy, -293, 0, 319)
    EVT_CALL(SetNpcPos, NPC_KoopersShell, -293, 0, 322)
    EVT_CALL(EnableNpcShadow, NPC_AmbushFuzzy, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_02, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
    EVT_CALL(SetModelFlags, MODEL_o177, MODEL_FLAG_DO_BOUNDS_CULLING, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_CALL(N(GetTreeHidingSpotPos), LVar4, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_BossFuzzy, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
        EVT_CALL(EnableNpcShadow, NPC_BossFuzzy, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_KoopersShell, FALSE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_WrongFuzzy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_WaitForWrongAnswer)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_WrongFuzzy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_Aux) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kooper) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kooper)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(InterpNpcYaw, NPC_Kooper, 225, 0)
            EVT_CALL(SetNpcPos, NPC_Kooper, -275, 0, 305)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_Kooper, ANIM_KooperWithoutShell_IdleAngry)
    EVT_RETURN
    EVT_END
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
