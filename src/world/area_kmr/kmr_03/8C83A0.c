#include "kmr_03.h"

#include "world/common/foliage.inc.c"

FoliageModelList N(treeModelList_Bush1_Bush) = {
    .count = 1,
    .models = { 64 },
};

FoliageVectorList N(treeEffectVectors_Bush1) = {
    .count = 1,
    .vectors = {
        { 143, 16, 462 },
    },
};

SearchBushConfig N(bush1) = {
    .bush = &N(treeModelList_Bush1_Bush),
    .vectors = &N(treeEffectVectors_Bush1),
};

FoliageModelList N(treeModelList_Tree1_Leaves) = {
    .count = 1,
    .models = { 62 },
};

FoliageModelList N(treeModelList_Tree1_Trunk) = {
    .count = 1,
    .models = { 61 },
};

FoliageVectorList N(treeEffectVectors_Tree1) = {
    .count = 2,
    .vectors = {
        { -80, 130, 18 },
        {  28, 130, 39 },
    },
};

EvtSource N(tree1_Callback) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(53), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_MAP_FLAG(10), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_LT(EVT_VAR(0), -30)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, -23, 100, 35, 13, EVT_SAVE_FLAG(53))
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, -85, 100, 16, 13, EVT_SAVE_FLAG(53))
    EVT_END_IF
    EVT_SET(EVT_MAP_FLAG(10), 1)
    EVT_RETURN
    EVT_END
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(treeModelList_Tree1_Leaves),
    .trunk = &N(treeModelList_Tree1_Trunk),
    .vectors = &N(treeEffectVectors_Tree1),
    .callback = &N(tree1_Callback),
};

Vec4f N(tree1Point) = { -42.0f, 0.0f, -13.0f, 0.0f };

EvtSource N(802422B8) = {
    EVT_SET(EVT_VAR(0), EVT_PTR(N(bush1)))
    EVT_BIND_TRIGGER(N(searchBush), TRIGGER_WALL_PRESS_A, 53, 1, 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 52, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(tree1Point)), 1, 0)
    EVT_RETURN
    EVT_END
};

