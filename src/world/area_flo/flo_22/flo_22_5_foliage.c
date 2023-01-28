#include "flo_22.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o45, MODEL_o46, MODEL_o48);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 93.0f, 0.0f, -89.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o52, MODEL_o53, MODEL_o55);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 150.0f, 0.0f, 135.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o27, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o30, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_RETURN
    EVT_END
};
