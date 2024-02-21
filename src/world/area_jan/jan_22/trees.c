#include "jan_22.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o133);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o134);

FoliageVectorList N(Tree1_Effects) = {
    .count = 1,
    .vectors = {
        { 343.0f, 410.0f, 100.0f },
    }
};

//@bug last part of a FoliageDropList
s32 N(InvalidTreepDrop)[] = {
    -30,
    ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
    GF_JAN_30,
    0,
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -385.0f, 0.0f, -39.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o93);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o78);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -328.0f, 0.0f, -123.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o286, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o287, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Return
    End
};
