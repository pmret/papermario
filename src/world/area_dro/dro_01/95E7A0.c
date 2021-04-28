#include "dro_01.h"

#define NAMESPACE dro_01_dup
#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetCurrentFloor.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/UnkFunc25.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetEntryPos.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetCurrentCameraYawClamped180.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/SomeXYZFunc2.inc.c"
#define NAMESPACE dro_01

#include "world/common/foliage.inc.c"

s32 N(treeModelList_Tree1_Leaves)[] = {
    0x00000001, 0x0000000D,
};

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000001, 0x0000000E,
};

s32 N(treeDropList_Tree1)[] = {
    1, 
    ITEM_COIN, 120, 92, -18, 0xF, SI_SAVE_FLAG(760), 0,
};

s32 N(shakeTreeEvent_Tree1)[] = {
    N(treeModelList_Tree1_Leaves), N(treeModelList_Tree1_Trunk), N(treeDropList_Tree1), 0x00000000, 0x00000000,
};

s32 N(triggerCoord_8024DD68)[] = {
    0x42F00000, 0x00000000, 0xC22C0000, 0x00000000,
};

Script N(8024DD78) = SCRIPT({
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 11;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_8024DD68);
});
