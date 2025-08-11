#include "flo_09.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_SpawnBzzap) = {
    Call(GetNpcPos, NPC_Bzzap_02, LVar0, LVar1, LVar2)
    IfLt(LVar1, 0)
        Call(GetModelCenter, LVar9)
        Add(LVar2, 35)
        Call(SetNpcPos, NPC_Bzzap_02, LVar0, LVar1, LVar2)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnShakeTree1) = {
    IfEq(GF_FLO09_Item_HappyFlowerB, false)
        IfEq(AB_FLO_TreePuzzle_SecondCorrect, 1)
            Call(MakeItemEntity, ITEM_HAPPY_FLOWER_B, -250, 100, 0, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO09_Item_HappyFlowerB)
        Else
            Set(LVar9, MODEL_o10)
            Exec(N(EVS_SpawnBzzap))
        EndIf
        Set(AB_FLO_TreePuzzle_FirstCorrect, 0)
        Set(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnShakeTree2) = {
    IfEq(GF_FLO09_Item_HappyFlowerB, false)
        Set(AB_FLO_TreePuzzle_FirstCorrect, 1)
        Set(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnShakeTree3) = {
    IfEq(GF_FLO09_Item_HappyFlowerB, false)
        IfEq(AB_FLO_TreePuzzle_FirstCorrect, 1)
            IfEq(AB_FLO_TreePuzzle_SecondCorrect, 0)
                Set(AB_FLO_TreePuzzle_SecondCorrect, 1)
                Return
            EndIf
        EndIf
        Set(LVar9, MODEL_o13)
        Exec(N(EVS_SpawnBzzap))
        Set(AB_FLO_TreePuzzle_FirstCorrect, 0)
        Set(AB_FLO_TreePuzzle_SecondCorrect, 0)
    EndIf
    Return
    End
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
    .diameter = 0.0f
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
    .diameter = 0.0f
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
    .diameter = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(AB_FLO_TreePuzzle_FirstCorrect, 0)
    Set(AB_FLO_TreePuzzle_SecondCorrect, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o10, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o3, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o13, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Return
    End
};
