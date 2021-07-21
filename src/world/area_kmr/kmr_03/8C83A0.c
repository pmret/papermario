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

Script N(tree1_Callback) = SCRIPT({
    if (SI_SAVE_FLAG(53) == TRUE) {
        return;
    }
    if (SI_MAP_FLAG(10) == TRUE) {
        return;
    }
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(0) < -30) {
        MakeItemEntity(ITEM_MUSHROOM, -23, 100, 35, 13, SI_SAVE_FLAG(53));
    } else {
        MakeItemEntity(ITEM_MUSHROOM, -85, 100, 16, 13, SI_SAVE_FLAG(53));
    }
    SI_MAP_FLAG(10) = 1;
});

ShakeTreeConfig N(tree1) = {
    .leaves = &N(treeModelList_Tree1_Leaves),
    .trunk = &N(treeModelList_Tree1_Trunk),
    .vectors = &N(treeEffectVectors_Tree1),
    .callback = &N(tree1_Callback),
};

Vec4f N(tree1Point) = { -42.0f, 0.0f, -13.0f, 0.0f };

Script N(802422B8) = SCRIPT({
    SI_VAR(0) = N(bush1);
    bind N(searchBush) TRIGGER_WALL_PRESS_A 53;

    SI_VAR(0) = N(tree1);
    bind N(shakeTree) TRIGGER_WALL_HAMMER 52;
    bind N(shakeTree) TRIGGER_POINT_BOMB N(tree1Point);
});

