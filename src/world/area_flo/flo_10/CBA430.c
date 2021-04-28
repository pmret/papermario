#include "flo_10.h"

#include "world/common/foliage.inc.c"

s32 N(treeModelList_Tree1_Leaves)[] = {
    0x00000003, 0x00000021, 0x00000022, 0x00000023,
};

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000001, 0x00000020,
};

s32 N(treeDropList_Tree1)[] = {
    1,
    ITEM_JAMMIN_JELLY, 80, 100, -240, 0xF, SI_SAVE_FLAG(1383), 0,
};

s32 N(shakeTreeEvent_Tree1)[] = {
    N(treeModelList_Tree1_Leaves), N(treeModelList_Tree1_Trunk), N(treeDropList_Tree1), 0x00000000, 0x00000000,
};

s32 N(triggerCoord_80244A40)[] = {
    0x43090000, 0x00000000, 0xC38D8000, 0x00000000,
};

Script N(80244A50) = SCRIPT({
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 9;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80244A40);
});
