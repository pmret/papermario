#include "jan_00.h"
#include "effects.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o241, MODEL_o242);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o240);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COCONUT,
            .pos = { 485, 95, -145 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .spawnFlag = AF_JAN00_TreeDrop1,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(D_80247A1C_B27F5C) = {
    .pos = { 481.0f, 0.0f, -165.0f },
    .radius = 0.0f
};

EvtScript N(EVS_80247A2C) = {
    EVT_SET(AF_JAN00_TreeDrop1, FALSE)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o282, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(D_80247A1C_B27F5C)), 1, 0)
    EVT_RETURN
    EVT_END
};
