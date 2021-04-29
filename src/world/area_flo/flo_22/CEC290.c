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

Script N(80241F6C) = SCRIPT({
    SI_VAR(0) = N(tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 14;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80241F28);
    SI_VAR(0) = N(tree2);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 16;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80241F5C);
});
