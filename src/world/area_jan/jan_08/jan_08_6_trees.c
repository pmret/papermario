#include "jan_08.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o144, MODEL_o145, MODEL_o146, MODEL_o147, MODEL_o148);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o143);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -397.0f, 114.0f, -240.0f },
        { -312.0f, 114.0f, -250.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -357.0f, 0.0f, -270.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o138, MODEL_o139, MODEL_o140, MODEL_o141, MODEL_o142);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o137);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -73, 76, -474 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN08_Tree2_Coin,
        },
    }
};

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -185.0f, 114.0f, -430.0f },
        { -100.0f, 114.0f, -440.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -145.0f, 0.0f, -460.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o150, MODEL_o151, MODEL_o152, MODEL_o153, MODEL_o154);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o149);

FoliageDropList N(Tree3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 380, 100, -95 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN08_Tree3_Coin,
        },
    }
};

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { 301.0f, 114.0f, -94.0f },
        { 386.0f, 114.0f, -104.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .drops = &N(Tree3_Drops),
    .vectors = &N(Tree3_Effects),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 341.0f, 0.0f, -124.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o202, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o203, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o204, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
