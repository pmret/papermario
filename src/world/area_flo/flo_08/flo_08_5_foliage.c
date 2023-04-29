#include "flo_08.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o133);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o132);

FoliageDropList N(Tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 340, 102, -89 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS,
            .spawnFlag = AF_FLO_TreeDrop_BlueBerry1,
        },
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 440, 102, -89 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS,
            .spawnFlag = AF_FLO_TreeDrop_BlueBerry2,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 391.0f, 0.0f, -102.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(AF_FLO_TreeDrop_BlueBerry1, FALSE)
    EVT_SET(AF_FLO_TreeDrop_BlueBerry2, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o172, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
