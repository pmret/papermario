#include "omo_04.h"

static char* N(exit_str_0) = "omo_03";
static char* N(exit_str_1) = "";

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

ApiStatus func_802402F4_DAD6F4(Evt* script, s32 isInitialCall) {
    f32 playerVx = gPlayerStatus.currentSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 playerVz = gPlayerStatus.currentSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);
    script->varTable[0] = (gPlayerStatus.position.x + playerVx);
    script->varTable[1] = (gPlayerStatus.position.z + playerVz);
    
    return ApiStatus_DONE2;
}

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/ShyGuyWanderAI.inc.c"

const s32 N(pad_8)[] = { 0, 0 };
static char* N(exit_str_2) = "omo_04";

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"
