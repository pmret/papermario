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

FoliageModelList N(tree1_Leaves) = {
    .count = 1,
    .models = { 13 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 14 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 120, 92, -18 },
            .spawnMode = 0xF,
            .pickupFlag = EVT_SAVE_FLAG(760),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_8024DD68) = { 120.0f, 0.0f, -43.0f, 0.0f };

EvtSource N(8024DD78) = {
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 11, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_8024DD68)), 1, 0)
    EVT_RETURN
    EVT_END
};
