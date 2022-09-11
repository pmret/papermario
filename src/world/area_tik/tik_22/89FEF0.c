#include "tik_22.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/atomic/Pipe.inc.c"

s32 bgm_clear_track_volumes(s32, s16);

ApiStatus func_8024061C_8A04DC(Evt* script, s32 isInitialCall) {
    bgm_clear_track_volumes(0, 2);
    return ApiStatus_DONE2;
}

#include "world/common/UnkPosFunc2.inc.c"
