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
        if ((player->actionState == 0xE) || (player->actionState == 0x10)) {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}


#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

#include "world/common/SixFloatsFunc.inc.c"

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

#include "world/common/UnkNpcAIMainFunc9.inc.c"
