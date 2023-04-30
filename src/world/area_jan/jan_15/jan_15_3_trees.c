#include "jan_15.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o73, MODEL_o74, MODEL_o75);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o72);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -134.0f, 114.0f, -72.0f },
        { -49.0f, 114.0f, -82.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -94.0f, 0.0f, -102.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o65, MODEL_o66, MODEL_o67);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o64);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 170, 100, -80 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN15_Tree2_Coin,
        },
    }
};

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { 164.0f, 114.0f, -71.0f },
        { 249.0f, 114.0f, -81.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 204.0f, 0.0f, -101.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o97, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o98, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_RETURN
    EVT_END
};
