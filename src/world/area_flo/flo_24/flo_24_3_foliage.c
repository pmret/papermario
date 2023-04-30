#include "flo_24.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o125, MODEL_o126, MODEL_o127, MODEL_o128, MODEL_o129, MODEL_o130);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o124);

FoliageDropList N(Tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { -38, 87, -156 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS,
            .spawnFlag = AF_FLO_TreeDrop_BubbleBerry1,
        },
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { 39, 65, -208 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS,
            .spawnFlag = AF_FLO_TreeDrop_BubbleBerry2,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 1.0f, 0.0f, -192.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(AF_FLO_TreeDrop_BubbleBerry1, FALSE)
    EVT_SET(AF_FLO_TreeDrop_BubbleBerry2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o124, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
