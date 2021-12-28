#include "flo_22.h"

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Trunk) = {
    .count = 3,
    .models = { 21, 22, 23 }
};

ShakeTreeConfig N(tree1) = {
    .trunk = &N(tree1_Trunk),
};

Vec4f N(triggerCoord_80241F28) = { 93.0f, 0.0f, -89.0f, 0.0f };

FoliageModelList N(tree2_Trunk) = {
    .count = 3,
    .models = { 25, 26, 27 }
};

ShakeTreeConfig N(tree2) = {
    .trunk = &N(tree2_Trunk),
};

Vec4f N(triggerCoord_80241F5C) = { 150.0f, 0.0f, 135.0f, 0.0f };

EvtSource N(80241F6C) = {
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 14, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80241F28)), 1, 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree2)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 16, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80241F5C)), 1, 0)
    EVT_RETURN
    EVT_END
};
