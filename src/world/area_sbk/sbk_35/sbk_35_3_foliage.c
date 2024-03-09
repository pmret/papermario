#include "sbk_35.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o57);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o56);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -398, 100, 129 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_SBK35_Tree1_Coin,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -398.0f, 0.0f, 104.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o59);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o58);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -108.0f, 0.0f, -406.0f },
    .diameter = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o61);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o60);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 211.0f, 0.0f, -111.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o191, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o193, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o195, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Return
    End
};
