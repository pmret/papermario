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
            .pickupFlag = EVT_SAVE_FLAG(1383),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80244A40) = { 137.0f, 0.0f, -283.0f, 0.0f };

EvtSource N(80244A50) = {
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 9, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80244A40)), 1, 0)
    EVT_RETURN
    EVT_END
};
