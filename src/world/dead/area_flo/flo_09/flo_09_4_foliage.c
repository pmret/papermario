#include "flo_09.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_SpawnBzzap) = {
    EVT_CALL(GetNpcPos, NPC_Bzzap_02, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 0)
        EVT_CALL(GetModelCenter, LVar9)
        EVT_ADD(LVar2, 35)
        EVT_CALL(SetNpcPos, NPC_Bzzap_02, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree1) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, FALSE)
        EVT_IF_EQ(AB_FLO_TreePuzzle_SecondCorrect, 1)
            EVT_CALL(MakeItemEntity, ITEM_HAPPY_FLOWER_B, -250, 100, 0, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO09_Item_HappyFlowerB)
        EVT_ELSE
            EVT_SET(LVar9, MODEL_o10)
            EVT_EXEC(N(EVS_SpawnBzzap))
        EVT_END_IF
        EVT_SET(AB_FLO_TreePuzzle_FirstCorrect, 0)
        EVT_SET(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree2) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, FALSE)
        EVT_SET(AB_FLO_TreePuzzle_FirstCorrect, 1)
        EVT_SET(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree3) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, FALSE)
        EVT_IF_EQ(AB_FLO_TreePuzzle_FirstCorrect, 1)
            EVT_IF_EQ(AB_FLO_TreePuzzle_SecondCorrect, 0)
                EVT_SET(AB_FLO_TreePuzzle_SecondCorrect, 1)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_SET(LVar9, MODEL_o13)
        EVT_EXEC(N(EVS_SpawnBzzap))
        EVT_SET(AB_FLO_TreePuzzle_FirstCorrect, 0)
        EVT_SET(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o11, MODEL_o12);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o10);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -200.0f, 0.0f, 1.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o4, MODEL_o5);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o3);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .callback = &N(EVS_OnShakeTree2),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 0.0f, 0.0f, 1.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o14, MODEL_o15);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o13);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .callback = &N(EVS_OnShakeTree3),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 200.0f, 0.0f, 1.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(AB_FLO_TreePuzzle_FirstCorrect, 0)
    EVT_SET(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o10, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o13, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
