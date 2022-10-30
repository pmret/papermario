#include "jan_02.h"
#include "effects.h"
#include "mapfs/jan_02_hit.h"

#include "world/common/atomic/TexturePan.inc.c"

extern s32 D_80242BD8_B2F048;

ApiStatus func_8024033C_B2C7AC(Evt* script, s32 isInitialCall) {
    bgm_clear_track_volumes(0, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_80240360_B2C7D0(Evt* script, s32 isInitialCall) {
    u16 currentFloor = gCollisionStatus.currentFloor;

    if (D_80242BD8_B2F048 != 0) {
        if (currentFloor == COLLIDER_o327 || currentFloor == COLLIDER_o330) {
            func_8011B7C0(9, 2, 0);
            D_80242BD8_B2F048 = 0;
        }
    } else {
        if (currentFloor == COLLIDER_o319 || currentFloor == COLLIDER_o316) {
            func_8011B7C0(9, 2, 1);
            D_80242BD8_B2F048 = 1;
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802403F8_B2C868(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
