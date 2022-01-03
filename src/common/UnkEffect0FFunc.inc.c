#include "battle/battle.h"
#include "effects.h"

ApiStatus N(UnkEffect0FFunc)(Evt* script, s32 isInitialCall) {
    f32 yaw = gCameras[0].currentYaw / 180.0f * PI;
    f32 yawPlus = yaw + 1.570796;
    f32 yawMinus = yaw - 1.570796;
    f32 temp_f30;
    f32 var1;
    f32 var2;
    f32 rand1 = rand_int(500) - 250;
    f32 rand2 = rand_int(500) - 250;
    f32 rand3 = rand_int(100) + 600;
    f32 var3;
    f32 var4;
    f32 var5;
    f32 var6;

    temp_f30 = gPlayerStatus.position.x + (rand3 * sin_rad(yaw));
    var1 = temp_f30 + (rand1 * sin_rad(yawPlus));
    var2 = gPlayerStatus.position.y + 200.0f;
    var3 = gPlayerStatus.position.z - (rand3 * cos_rad(yaw));
    var3 = var3 - (rand1 * cos_rad(yawPlus));
    var4 = gPlayerStatus.position.x + (rand3 * sin_rad(yaw));
    var4 = var4 + (rand2 * sin_rad(yawMinus));
    var5 = gPlayerStatus.position.y;
    var6 = gPlayerStatus.position.z - (rand3 * cos_rad(yaw));
    var6 = var6 - (rand2 * cos_rad(yawMinus));
    playFX_0F(0, var1, var2, var3, var4, var5, var6, rand_int(10) + 10);
    return ApiStatus_DONE2;
}
