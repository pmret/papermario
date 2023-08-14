#include "hos_03.h"
#include "effects.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_ShakeTree_StarHaven) = {
    EVT_SET_TIMESCALE(EVT_FLOAT(2.0))
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_BUF_READ1(LVar5)
    EVT_CALL(GetPlayerPos, LVar6, LVarF, LVar8)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_IF_NE(LVar1, 0)
            EVT_WAIT(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar1)
            EVT_BUF_READ1(LVar2)
            EVT_LOOP(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_CALL(TranslateModel, LVar3, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar2, 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar2)
            EVT_BUF_READ1(LVar3)
            EVT_LOOP(LVar3)
                EVT_BUF_READ1(LVar4)
                EVT_CALL(TranslateModel, LVar4, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar3, 0)
            EVT_USE_BUF(LVar3)
            EVT_BUF_READ1(LVar4)
            EVT_LOOP(LVar4)
                EVT_BUF_READ1(LVar5)
                EVT_BUF_READ3(LVar6, LVar7, LVar8)
                EVT_BUF_READ3(LVar9, LVarA, LVarB)
                EVT_IF_EQ(LVarB, 0)
                    EVT_CALL(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                EVT_ELSE
                    EVT_CALL(GetValueByRef, LVarB, LVarC)
                    EVT_IF_EQ(LVarC, 0)
                        EVT_CALL(SetValueByRef, LVarB, 1)
                        EVT_CALL(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar4, 0)
            EVT_USE_BUF(LVar4)
            EVT_BUF_READ1(LVar5)
            EVT_LOOP(LVar5)
                EVT_BUF_READ3(LVar6, LVar7, LVar8)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, LVar6, LVar7, LVar8, 50)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, LVar6, LVar7, LVar8, 50)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_IF_NE(LVar5, 0)
        EVT_EXEC_WAIT(LVar5)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o37, MODEL_o38, MODEL_o39);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o32, MODEL_o35, MODEL_o36);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -669.0f, 60.0f, 296.0f },
        { -584.0f, 60.0f, 286.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -629.0f, 35.0f, 296.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o43, MODEL_o44, MODEL_o45);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o40, MODEL_o41, MODEL_o42);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -528.0f, 60.0f, 324.0f },
        { -443.0f, 60.0f, 314.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -488.0f, 35.0f, 324.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_StarHaven)), TRIGGER_WALL_HAMMER, COLLIDER_o35, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_StarHaven)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_StarHaven)), TRIGGER_WALL_HAMMER, COLLIDER_o32, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_StarHaven)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_RETURN
    EVT_END
};
