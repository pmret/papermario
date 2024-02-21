#include "sbk_56.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_LEMON,
            .pos = { -304, 92, -176 },
            .spawnMode = ITEM_SPAWN_MODE_FALL,
            .pickupFlag = GF_SBK56_Tree1_Lemon,
            .spawnFlag = MF_TreeDrop_Lemon,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -259.0f, 0.0f, -160.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_LIME,
            .pos = { 230, 77, -304 },
            .spawnMode = ITEM_SPAWN_MODE_FALL,
            .pickupFlag = GF_SBK56_Tree2_Lime,
            .spawnFlag = MF_TreeDrop_Lime,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 171.0f, 0.0f, -291.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o52);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_y_miki);

FoliageDropList N(Tree3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -436, 100, 249 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK56_Tree3_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .drops = &N(Tree3_Drops),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -436.0f, 0.0f, 224.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_y_ha);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o51);

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { -320.0f, 0.0f, -21.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree5_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o54);
FoliageModelList N(Tree5_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o53);

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { -242.0f, 0.0f, 88.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree6_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o56);
FoliageModelList N(Tree6_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o55);

ShakeTreeConfig N(ShakeTree_Tree6) = {
    .leaves = &N(Tree6_LeafModels),
    .trunk = &N(Tree6_TrunkModels),
};

BombTrigger N(BombPos_Tree6) = {
    .pos = { -203.0f, 0.0f, -214.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree7_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o58);
FoliageModelList N(Tree7_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o57);

ShakeTreeConfig N(ShakeTree_Tree7) = {
    .leaves = &N(Tree7_LeafModels),
    .trunk = &N(Tree7_TrunkModels),
};

BombTrigger N(BombPos_Tree7) = {
    .pos = { -101.0f, 0.0f, -376.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree8_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o60);
FoliageModelList N(Tree8_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o59);

ShakeTreeConfig N(ShakeTree_Tree8) = {
    .leaves = &N(Tree8_LeafModels),
    .trunk = &N(Tree8_TrunkModels),
};

BombTrigger N(BombPos_Tree8) = {
    .pos = { 104.0f, 0.0f, -386.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree9_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o62);
FoliageModelList N(Tree9_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o61);

FoliageDropList N(Tree9_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 266, 100, 149 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK56_Tree9_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree9) = {
    .leaves = &N(Tree9_LeafModels),
    .trunk = &N(Tree9_TrunkModels),
    .drops = &N(Tree9_Drops),
};

BombTrigger N(BombPos_Tree9) = {
    .pos = { 266.0f, 0.0f, 124.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree10_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o64);
FoliageModelList N(Tree10_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o63);

ShakeTreeConfig N(ShakeTree_Tree10) = {
    .leaves = &N(Tree10_LeafModels),
    .trunk = &N(Tree10_TrunkModels),
};

BombTrigger N(BombPos_Tree10) = {
    .pos = { 362.0f, 0.0f, -74.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(GF_SBK56_Tree1_Lemon, FALSE)
    Set(GF_SBK56_UnusedA, FALSE)
    Set(GF_SBK56_Tree2_Lime, FALSE)
    Set(GF_SBK56_UnusedB, FALSE)
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_remon, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_rim, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_y_miki, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree4)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o67, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree4)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree5)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o68, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree5)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree6)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o69, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree6)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree7)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o70, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree7)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree8)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o71, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree8)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree9)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o72, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree9)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree10)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o73, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree10)), 1, 0)
    Return
    End
};
