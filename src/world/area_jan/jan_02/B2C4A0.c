#include "jan_02.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

extern s32 D_80242BD8_B2F048;

ApiStatus func_8024033C_B2C7AC(Evt* script, s32 isInitialCall) {
    bgm_clear_track_volumes(0, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_80240360_B2C7D0(Evt* script, s32 isInitialCall) {
    u16 currentFloor = gCollisionStatus.currentFloor;

    if (D_80242BD8_B2F048 != 0) {
        if (currentFloor == 0xA || currentFloor == 0xD) {
            func_8011B7C0(9, 2, 0);
            D_80242BD8_B2F048 = 0;
        }
    } else {
        if (currentFloor == 0x2E || currentFloor == 0x2B) {
            func_8011B7C0(9, 2, 1);
            D_80242BD8_B2F048 = 1;
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802403F8_B2C868(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
