#include "flo_22.h"

#include "world/common/foliage.inc.c"

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000003, 0x00000015, 0x00000016, 0x00000017,
};

s32 N(shakeTreeEvent_Tree1)[] = {
    0x00000000, N(treeModelList_Tree1_Trunk), 0x00000000, 0x00000000, 0x00000000,
};

s32 N(triggerCoord_80241F28)[] = {
    0x42BA0000, 0x00000000, 0xC2B20000, 0x00000000,
};

s32 N(treeModelList_Tree2_Trunk)[] = {
    0x00000003, 0x00000019, 0x0000001A, 0x0000001B,
};

s32 N(shakeTreeEvent_Tree2)[] = {
    0x00000000, N(treeModelList_Tree2_Trunk), 0x00000000, 0x00000000, 0x00000000,
};

s32 N(triggerCoord_80241F5C)[] = {
    0x43160000, 0x00000000, 0x43070000, 0x00000000,
};

Script N(80241F6C) = SCRIPT({
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 14;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80241F28);
    SI_VAR(0) = N(shakeTreeEvent_Tree2);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 16;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80241F5C);
});
