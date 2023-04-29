#include "mac_01.h"

#include "common/foliage.inc.c"

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_STAR_PIECE,
            .pos = { -480, 120, -174 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_NEVER_VANISH,
            .pickupFlag = GF_MAC01_Tree1_StarPiece,
            .spawnFlag = MF_SpawnFlag_Tree1,
        },
    }
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o362);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o365);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -532.0f, 135.0f, -174.0f },
        { -492.0f, 135.0f, -184.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -512.0f, 20.0f, -154.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o115);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o116);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -177.0f, 104.0f, -478.0f },
        { -137.0f, 104.0f, -488.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -157.0f, 20.0f, -458.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o393, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o237, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_RETURN
    EVT_END
};
