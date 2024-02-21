#include "jan_12.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o6, MODEL_o62, MODEL_o63);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o35);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -245, 100, -85 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN12_Tree1_Coin,
        },
    }
};

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -254.0f, 144.0f, -81.0f },
        { -169.0f, 144.0f, -91.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -214.0f, 30.0f, -111.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels) = FOLIAGE_MODEL_LIST(MODEL_o65, MODEL_o66, MODEL_o67);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o64);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { 320.0f, 114.0f, -65.0f },
        { 405.0f, 114.0f, -75.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 360.0f, 0.0f, -95.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o96, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o97, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Return
    End
};
