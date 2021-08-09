#include "common.h"

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_ahead);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_sides, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corner);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corners);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_general);

void npc_get_slip_vector(f32* outX, f32* outZ, f32 aX, f32 aZ, f32 bX, f32 bZ) {
    f32 dotProduct = (aX * bX) + (aZ * bZ);

    *outX = (aX - (dotProduct * bX)) * 0.5f;
    *outZ = (aZ - (dotProduct * bZ)) * 0.5f;
}

s32 npc_test_move_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius);
INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_with_slipping, s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_without_slipping, s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius);

s32 npc_test_move_taller_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                       f32 radius) {
    f32 xTemp = *x;
    f32 yTemp = *y + height - 1.0f;
    f32 zTemp = *z;
    s32 ret;

    radius *= 0.5f;
    if (npc_test_move_with_slipping(ignoreFlags, &xTemp, &yTemp, &zTemp, fabsf(length), yaw, radius) < 0) {
        xTemp = *x;
        yTemp = *y + 10.01f;
        zTemp = *z;
        ret = npc_test_move_with_slipping(ignoreFlags, &xTemp, &yTemp, &zTemp, fabsf(length), yaw, radius) >= 0;
        *x = xTemp;
        *z = zTemp;
    } else {
        ret = 1;
        *x = xTemp;
        *z = zTemp;
    }
    return ret;
}

s32 npc_test_move_simple_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                       f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_with_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}

s32 npc_test_move_simple_without_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                          f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_without_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}


INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_complex_with_slipping);
