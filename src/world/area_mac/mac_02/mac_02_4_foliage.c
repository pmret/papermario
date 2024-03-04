#include "mac_02.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o417);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o213);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { 83.0f, 130.0f, -541.0f },
        { 123.0f, 130.0f, -551.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 98.0f, 20.0f, -531.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o115);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o423);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -337.0f, 104.0f, -198.0f },
        { -297.0f, 104.0f, -208.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -323.0f, 20.0f, -190.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o415);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o420);

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { 584.0f, 125.0f, -70.0f },
        { 624.0f, 125.0f, -80.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .vectors = &N(Tree3_Effects),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 598.0f, 0.0f, -67.0f },
    .diameter = 0.0f
};

FoliageModelList N(UnusedTree_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o419);
FoliageModelList N(UnusedTree_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o116);

FoliageVectorList N(UnusedTree_Effects) = {
    .count = 2,
    .vectors = {
        { -624.0f, 80.0f, -166.0f },
        { -584.0f, 80.0f, -176.0f },
    }
};

ShakeTreeConfig N(ShakeTree_UnusedTree) = {
    .leaves = &N(UnusedTree_LeafModels),
    .trunk  = &N(UnusedTree_TrunkModels),
    .vectors = &N(UnusedTree_Effects),
};

BombTrigger N(BombPos_UnusedTree) = {
    .pos = { -608.0f, 20.0f, -156.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o414);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o421);

FoliageVectorList N(Tree4_Effects) = {
    .count = 2,
    .vectors = {
        { 235.0f, 80.0f, 543.0f },
        { 275.0f, 80.0f, 533.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk  = &N(Tree4_TrunkModels),
    .vectors = &N(Tree4_Effects),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { 351.0f, 20.0f, 555.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o409, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o361, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o370, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree4)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o378, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree4)), 1, 0)
    Return
    End
};
