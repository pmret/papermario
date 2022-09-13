#include "tik_07.h"

#include "world/common/UnkPosFunc2.inc.c"

extern s32 D_802449B0_87E590[4];

ApiStatus func_80241390_87AF70(Evt* script, s32 isInitialCall) {
    PlayerStatus* player = &gPlayerStatus;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_802449B0_87E590); i++) {
        if (gCollisionStatus.currentFloor != D_802449B0_87E590[i]) {
            continue;
        }
        if ((player->actionState == ACTION_STATE_SPIN_POUND) || (player->actionState == ACTION_STATE_TORNADO_POUND)) {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/enemy/FlyingAI.inc.c"
