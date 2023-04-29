#include "jan_09.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o142, MODEL_o143, MODEL_o144, MODEL_o145, MODEL_o146);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o141);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -461.0f, 114.0f, -204.0f },
        { -376.0f, 114.0f, -214.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -421.0f, 0.0f, -234.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o136, MODEL_o137, MODEL_o138, MODEL_o139, MODEL_o140);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o135);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 50, 190, -420 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN09_Tree2_Coin,
        },
    }
};

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -26.0f, 204.0f, -429.0f },
        { 59.0f, 204.0f, -439.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 14.0f, 90.0f, -459.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o130, MODEL_o131, MODEL_o132, MODEL_o133, MODEL_o134);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o129);

FoliageDropList N(Tree3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_FRIGHT_JAR,
            .pos = { 390, 100, -110 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN09_Tree3_FrightJar,
        },
    }
};

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { 415.0f, 114.0f, -120.0f },
        { 500.0f, 114.0f, -130.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .drops = &N(Tree3_Drops),
    .vectors = &N(Tree3_Effects),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 455.0f, 0.0f, -150.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o218, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o219, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o220, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
