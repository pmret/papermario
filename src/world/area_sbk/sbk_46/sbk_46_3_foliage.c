#include "sbk_46.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o62,
    }
};

FoliageModelList N(Tree1_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o61,
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -228.0f, 0.0f, -306.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o64,
    }
};

FoliageModelList N(Tree2_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o63,
    }
};

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -178, 100, 189 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK46_Tree2_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -178.0f, 0.0f, 164.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o60,
    }
};

FoliageModelList N(Tree3_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o59,
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 351.0f, 0.0f, -101.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o193, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o195, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o191, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(shakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
