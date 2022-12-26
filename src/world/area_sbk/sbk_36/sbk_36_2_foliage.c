#include "sbk_36.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o73,
    }
};

FoliageModelList N(Tree1_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o72,
    }
};

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -422, 100, 116 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK36_Tree1_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -422.0f, 0.0f, 91.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o71,
    }
};

FoliageModelList N(Tree2_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o70,
    }
};

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -322, 100, -86 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK36_Tree2_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -322.0f, 0.0f, -111.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o75,
    }
};

FoliageModelList N(Tree3_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o74,
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -244.0f, 0.0f, 77.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree4_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o69,
    }
};

FoliageModelList N(Tree4_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o68,
    }
};

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { -128.0f, 0.0f, -111.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree5_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o57,
    }
};

FoliageModelList N(Tree5_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o56,
    }
};

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { 58.0f, 0.0f, 101.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree6_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o59,
    }
};

FoliageModelList N(Tree6_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o58,
    }
};

FoliageDropList N(Tree6_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 158, 100, -76 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK36_Tree6_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree6) = {
    .leaves = &N(Tree6_LeafModels),
    .trunk = &N(Tree6_TrunkModels),
    .drops = &N(Tree6_Drops),
};

BombTrigger N(BombPos_Tree6) = {
    .pos = { 158.0f, 0.0f, -101.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree7_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o67,
    }
};

FoliageModelList N(Tree7_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o66,
    }
};

ShakeTreeConfig N(ShakeTree_Tree7) = {
    .leaves = &N(Tree7_LeafModels),
    .trunk = &N(Tree7_TrunkModels),
};

BombTrigger N(BombPos_Tree7) = {
    .pos = { 236.0f, 0.0f, 87.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree8_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o63,
    }
};

FoliageModelList N(Tree8_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o62,
    }
};

ShakeTreeConfig N(ShakeTree_Tree8) = {
    .leaves = &N(Tree8_LeafModels),
    .trunk = &N(Tree8_TrunkModels),
};

BombTrigger N(BombPos_Tree8) = {
    .pos = { 351.0f, 0.0f, -101.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree9_LeafModels) = {
    .count = 1,
    .models = {
        MODEL_o65,
    }
};

FoliageModelList N(Tree9_TrunkModels) = {
    .count = 1,
    .models = {
        MODEL_o64,
    }
};

FoliageDropList N(Tree9_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_LETTER03,
            .pos = { 366, 92, 101 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_NEVER_VANISH,
            .pickupFlag = GF_SBK36_Tree9_Letter03,
            .spawnFlag = MF_TreeDrop_Letter,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree9) = {
    .leaves = &N(Tree9_LeafModels),
    .trunk = &N(Tree9_TrunkModels),
    .drops = &N(Tree9_Drops),
};

BombTrigger N(BombPos_Tree9) = {
    .pos = { 438.0f, 0.0f, 101.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o205, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o203, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o207, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o201, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree4)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o199, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree5)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o197, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree6)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree7)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o191, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree7)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree8)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o195, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree8)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree9)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o193, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree9)), 1, 0)
    EVT_RETURN
    EVT_END
};
