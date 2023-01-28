#include "sbk_55.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o56);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o55);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 77, 100, -101 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK55_Tree1_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 77.0f, 0.0f, -126.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o191, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
