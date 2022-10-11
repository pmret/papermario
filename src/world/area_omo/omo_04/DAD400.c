#include "omo_04.h"

static char* N(exit_str_0) = "omo_03";
static char* N(exit_str_1) = "";

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

ApiStatus func_802402F4_DAD6F4(Evt* script, s32 isInitialCall) {
    f32 playerVx = gPlayerStatus.currentSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 playerVz = gPlayerStatus.currentSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);
    script->varTable[0] = (gPlayerStatus.position.x + playerVx);
    script->varTable[1] = (gPlayerStatus.position.z + playerVz);
    
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

const s32 N(pad_8)[] = { 0, 0 };
static char* N(exit_str_2) = "omo_04";

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"
