#include "jan_14.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o61, MODEL_o62, MODEL_o63);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o60);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -388.0f, 114.0f, -77.0f },
        { -303.0f, 114.0f, -87.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -348.0f, 0.0f, -107.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o65, MODEL_o67);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o64);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -234.0f, 114.0f, 19.0f },
        { -149.0f, 114.0f, 9.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -194.0f, 0.0f, -11.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o69, MODEL_o70, MODEL_o71);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o68);

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { -54.0f, 114.0f, -61.0f },
        { 31.0f, 114.0f, -71.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .vectors = &N(Tree3_Effects),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 14.0f, 0.0f, -91.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o57, MODEL_o58, MODEL_o59);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o56);

FoliageVectorList N(Tree4_Effects) = {
    .count = 2,
    .vectors = {
        { 364.0f, 114.0f, -61.0f },
        { 449.0f, 114.0f, -71.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
    .vectors = &N(Tree4_Effects),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { 404.0f, 0.0f, -91.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree5_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o73, MODEL_o75);
FoliageModelList N(Tree5_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o72);

FoliageVectorList N(Tree5_Effects) = {
    .count = 2,
    .vectors = {
        { 471.0f, 114.0f, 23.0f },
        { 556.0f, 114.0f, 13.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
    .vectors = &N(Tree5_Effects),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { 511.0f, 0.0f, -7.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o117, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o103, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o118, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree4)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o119, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree4)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree5)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o120, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree5)), 1, 0)
    Return
    End
};
