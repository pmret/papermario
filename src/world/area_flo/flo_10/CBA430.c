#include "flo_10.h"

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 3,
    .models = { 33, 34, 35 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 32 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_JAMMIN_JELLY,
            .pos = { 80, 100, -240 },
            .spawnMode = 0xF,
            .pickupFlag = SI_SAVE_FLAG(1383),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80244A40) = { 137.0f, 0.0f, -283.0f, 0.0f };

Script N(80244A50) = SCRIPT({
    SI_VAR(0) = N(tree1);
    bind N(shakeTree) TRIGGER_WALL_HAMMER 9;
    bind N(shakeTree) TRIGGER_POINT_BOMB N(triggerCoord_80244A40);
});
