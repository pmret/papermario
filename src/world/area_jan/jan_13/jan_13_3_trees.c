#include "jan_13.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o54, MODEL_o55, MODEL_o56);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o53);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -335, 100, -55 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN13_Tree1_Coin,
        },
    }
};

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
    .drops = &N(Tree1_Drops),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -348.0f, 0.0f, -107.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o50, MODEL_o51, MODEL_o52);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o49);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { 264.0f, 114.0f, -81.0f },
        { 349.0f, 114.0f, -91.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 304.0f, 0.0f, -111.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o113, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o110, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Return
    End
};
