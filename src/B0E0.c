#include "common.h"

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3);

void update_camera_mode_unused(Camera* camera);
// Issues with zero float temp?
#ifdef NON_MATCHING
void update_camera_mode_unused(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f30;
    f32 temp_f24_2;
    f32 theta;
    f32 sinTheta1;
    f32 cosTheta1;
    f32 sinTheta2;
    f32 cosTheta2;
    f32 lookXDelta;
    f32 lookYDelta;
    f32 lookZDelta;

    if (camera->unk_06 != 0 || camera->unk_08 != 0) {
        camera->unk_06 = 0;
        camera->unk_08 = 0;
        camera->unk_1C = 0;
        camera->unk_1E = 100;
        camera->unk_20 = 100;
        camera->unk_22 = 0;
        camera->unk_24 = 0;
        camera->lookAt_obj.x = camera->unk_54;
        camera->lookAt_obj.y = camera->unk_58;
        camera->lookAt_obj.z = camera->unk_5C;
    }

    if (!(playerStatus->flags & 6)) {
        camera->unk_58 = playerStatus->position.y + 60.0f;
    }

    camera->unk_54 = playerStatus->position.x;
    camera->unk_5C = playerStatus->position.z + 400.0f;

    if (camera->unk_1C == 0) {
        s32 fovTemp = 10000 / camera->unk_20;

        camera->lookAt_obj.x = camera->unk_54;
        camera->lookAt_obj.y = camera->unk_58;
        camera->lookAt_obj.z = camera->unk_5C;
        camera->trueRotation.x = (f32) camera->unk_24;
        camera->currentBoomYaw = (f32) camera->unk_22;
        camera->currentBoomLength = (f32) camera->unk_1E;

        if (fovTemp < 0) {
            fovTemp += 3;
        }
        camera->vfov = fovTemp >> 2;

        theta = (camera->currentBoomYaw * TAU) / 360.0f;
        sinTheta1 = sin_rad(theta);
        cosTheta1 = cos_rad(theta);
        temp_f30 = (cosTheta1 * 0.0f) + (camera->currentBoomLength * sinTheta1);
        temp_f24_2 = (sinTheta1 * -0.0f) + (camera->currentBoomLength * cosTheta1);

        theta = (camera->trueRotation.x * TAU) / 360.0f;
        sinTheta2 = sin_rad(theta);
        cosTheta2 = cos_rad(theta);
        camera->lookAt_eye.x = camera->lookAt_obj.x + ((cosTheta2 * 0.0f) - (temp_f24_2 * sinTheta2));
        camera->lookAt_eye.y = camera->lookAt_obj.y + temp_f30;
        camera->lookAt_eye.z = camera->lookAt_obj.z + ((sinTheta2 * 0.0f) + (temp_f24_2 * cosTheta2));
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->currentPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}
#else
INCLUDE_ASM(void, "B0E0", update_camera_mode_unused, Camera* camera);
#endif

void update_camera_mode_5(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 lookXDelta, lookYDelta, lookZDelta;

    camera->currentBoomYaw = 18.0f;
    camera->currentBoomLength = 690.0f;
    camera->currentYOffset = 47.0f;

    if (camera->unk_06 != 0) {
        camera->unk_550 = 0.0f;
        camera->unk_70 = 0.0f;
        camera->trueRotation.x = 0.0f;
        camera->unk_06 = 0;
        camera->unk_554 = 0;
        camera->lookAt_obj.x = camera->targetPos.x;
        camera->lookAt_obj.y = camera->targetPos.y + camera->currentYOffset;
        camera->lookAt_obj.z = camera->targetPos.z;
        func_80030210(camera, 0.0f, 0.0f, 0);
    } else {
        f32 temp_f22 = (playerStatus->currentSpeed * 1.5f) + 1.0f;
        f32 temp_f20 = (playerStatus->currentSpeed * 0.05f) + 0.05f;

        camera->unk_54 = camera->targetPos.x + camera->unk_550;
        camera->unk_58 = camera->targetPos.y + camera->currentYOffset;
        camera->unk_5C = camera->targetPos.z;
        func_8003034C(camera);
        if (!(camera->moveFlags & 1)) {
            func_80030210(camera, temp_f20, temp_f22, 0);
        } else {
            lookXDelta = temp_f22; // needed to match

            func_80030210(camera, temp_f20, lookXDelta, 1);
        }
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->currentPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3) {
    f32 xDelta = (camera->unk_54 - camera->lookAt_obj.x) * arg1;
    f32 theta;
    f32 cosTheta;
    f32 sinTheta;

    if (xDelta < -arg2) {
        xDelta = -arg2;
    }
    if (xDelta > arg2) {
        xDelta = arg2;
    }

    camera->lookAt_obj.x = camera->lookAt_eye.x = camera->lookAt_obj.x + xDelta;
    theta = (camera->currentBoomYaw * TAU) / 360.0f;

    cosTheta = cos_rad(theta);
    camera->lookAt_obj.z += (camera->unk_5C - camera->lookAt_obj.z) * arg1;
    camera->lookAt_eye.z = camera->lookAt_obj.z + (camera->currentBoomLength * cosTheta);

    if (arg3 << 16 == 0) {
        sinTheta = sin_rad(theta);
        camera->lookAt_obj.y += (camera->unk_58 - camera->lookAt_obj.y) * 0.125f;
        camera->lookAt_eye.y = camera->lookAt_obj.y + (camera->currentBoomLength * sinTheta);
    }
}

void func_8003034C(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (fabsf(get_clamped_angle_diff(playerStatus->currentYaw, 90.0f)) < 45.0f) {
        if (camera->unk_556 == 0) {
            if (camera->unk_554 <= 0) {
                camera->unk_550 = 35.0f;
            } else {
                camera->unk_554--;
            }
        } else {
            camera->unk_554 = 15;
            camera->unk_556 = 0;
        }
    } else if (fabsf(get_clamped_angle_diff(playerStatus->currentYaw, 270.0f)) < 45.0f) {
        if (camera->unk_556 == 1) {
            if (camera->unk_554 <= 0) {
                camera->unk_550 = -35.0f;
            } else {
                camera->unk_554--;
            }
        } else {
            camera->unk_554 = 15;
            camera->unk_556 = 1;
        }
    }
}

void func_80030450(void) {
}

s32 test_ray_zone_aabb(f32 x, f32 y, f32 z) {
    f32 hitX, hitY, hitZ;
    f32 hitDepth = 32767.0f;
    f32 nx, ny, nz;
    s32 zoneID = test_ray_zones(x, y, z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nx, &ny, &nz);

    if (zoneID < 0) {
        return 0;
    }

    return D_800D91D4[zoneID].unk_10;
}

INCLUDE_ASM(s32, "B0E0", update_camera_from_controller);

INCLUDE_ASM(s32, "B0E0", update_camera_zone_interp);
