#include "jan_01.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o99);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o98);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 160.0f, 0.0f, -287.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o85, MODEL_o86);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o84);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { -618, 95, -75 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop2,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -628.0f, 0.0f, -95.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o79, MODEL_o80);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o78);

FoliageDropList N(Tree3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { -401, 105, -115 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop3,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .drops = &N(Tree3_Drops),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -391.0f, 0.0f, -135.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o82, MODEL_o83);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o81);

FoliageDropList N(Tree4_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { -351, 75, -95 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop4,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
    .drops = &N(Tree4_Drops),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { -341.0f, 0.0f, -115.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree5_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o88, MODEL_o89);
FoliageModelList N(Tree5_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o87);

FoliageDropList N(Tree5_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { 58, 95, -135 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop5,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
    .drops = &N(Tree5_Drops),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { 68.0f, 0.0f, -155.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree6_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o104, MODEL_o105);
FoliageModelList N(Tree6_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o103);

FoliageDropList N(Tree6_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { 261, 75, -115 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop6,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree6) = {
    .leaves = &N(Tree6_LeafModels),
    .trunk = &N(Tree6_TrunkModels),
    .drops = &N(Tree6_Drops),
};

BombTrigger N(BombPos_Tree6) = {
    .pos = { 251.0f, 0.0f, -135.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree7_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o113, MODEL_o114);
FoliageModelList N(Tree7_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o112);

FoliageDropList N(Tree7_DropsA) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_STAR_PIECE,
            .pos = { 441, 75, -135 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_NEVER_VANISH,
            .pickupFlag = GF_JAN01_Tree7_StarPiece,
            .spawnFlag = AF_JAN01_TreeDrop_StarPiece,
        },
    }
};

FoliageDropList N(Tree7_DropsB) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { 441, 75, -135 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN01_TreeDrop7,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree7A) = {
    .leaves = &N(Tree7_LeafModels),
    .trunk = &N(Tree7_TrunkModels),
    .drops = &N(Tree7_DropsA),
};

ShakeTreeConfig N(ShakeTree_Tree7B) = {
    .leaves = &N(Tree7_LeafModels),
    .trunk = &N(Tree7_TrunkModels),
    .drops = &N(Tree7_DropsB),
};

BombTrigger N(BombPos_Tree7) = {
    .pos = { 431.0f, 0.0f, -155.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(AF_JAN01_TreeDrop2, FALSE)
    Set(AF_JAN01_TreeDrop3, FALSE)
    Set(AF_JAN01_TreeDrop4, FALSE)
    Set(AF_JAN01_TreeDrop5, FALSE)
    Set(AF_JAN01_TreeDrop6, FALSE)
    Set(AF_JAN01_TreeDrop7, FALSE)
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o204, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o84, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o203, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree4)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o152, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree4)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree5)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o155, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree5)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree6)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o103, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree6)), 1, 0)
    IfEq(GF_JAN01_Tree7_StarPiece, FALSE)
        Set(LVar0, Ref(N(ShakeTree_Tree7A)))
    Else
        Set(LVar0, Ref(N(ShakeTree_Tree7B)))
    EndIf
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o205, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree7)), 1, 0)
    Return
    End
};
