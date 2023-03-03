#include "common.h"
#include "camera.h"

void update_camera_mode_4(Camera* camera) {
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 boomYaw;
    f32 boomLength;
    f32 f0;
    f32 f4;
    f32 new_var;

    f0 = camera->targetPos.x;
    deltaX = camera->auxPitch;
    if (f0 > deltaX) {
        f0 = deltaX;
    }
    if (f0 < -deltaX) {
        f0 = -deltaX;
    }
    camera->lookAt_obj_target.x = f0;
    f4 = camera->targetPos.z;
    deltaZ = camera->auxBoomLength;
    if (f4 > deltaZ) {
        f4 = deltaZ;
    }
    if (f4 < -deltaZ) {
        f4 = -deltaZ;
    }
    camera->lookAt_obj_target.z = f4;
    camera->unk_70 = 0.0f;
    camera->currentBoomYaw = 0.0f;
    camera->trueRotation.x = camera->unk_70;
    camera->currentBoomLength = camera->lookAt_dist * D_8009A5EC;
    camera->currentYOffset = camera->auxBoomPitch * D_8009A5EC;
    if (camera->unk_06) {
        camera->unk_06 = FALSE;
        camera->unk_98 = 0.0f;
        camera->unk_9C = 0.0f;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->currentYOffset;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->currentBoomLength;
        deltaX2 = deltaX;
        deltaY2 = deltaY;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = deltaZ;
        new_var = boomYaw;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->unk_70);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY2 = deltaY;
        deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
        camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
        camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
        camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    }
    camera->lookAt_obj.x = camera->lookAt_obj_target.x;
    camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->currentYOffset;
    camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->currentBoomLength;
    deltaX2 = deltaX;
    deltaY2 = deltaY;
    boomYaw = deltaX = -deltaY2;
    deltaZ2 = deltaZ;
    new_var = boomYaw;
    deltaX = deltaX2;
    deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
    deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
    boomYaw = DEG_TO_RAD(camera->unk_70);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaY2 = deltaY;
    deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
    camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
    camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
    camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->currentPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

#ifdef WIP
void update_camera_mode_2(Camera* camera) {
    f32 temp_f24;
    f32 temp_f28_2;

    f32 auxBoomLength;
    f32 boomYaw;
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 unk_70;
    f32 sin_70;
    f32 cos_70;
    f32 zero;

    auxBoomLength = camera->auxBoomLength;
    camera->unk_70 = auxBoomLength;
    camera->trueRotation.x = auxBoomLength;
    camera->currentBoomYaw = camera->auxPitch;
    camera->currentBoomLength = camera->lookAt_dist * D_8009A5EC;
    camera->currentYOffset = camera->auxBoomPitch * D_8009A5EC;
    if (camera->unk_06 != 0) {
        zero = 0.0f;
        camera->unk_06 = 0;

        camera->unk_9C = camera->unk_98 = zero;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->currentYOffset;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        temp_f24 = (cosBoom * zero) + (camera->currentBoomLength * sinBoom);
        unk_70 = DEG_TO_RAD(camera->unk_70);
        temp_f28_2 = (sinBoom * -zero) + (camera->currentBoomLength * cosBoom);
        sin_70 = sin_rad(unk_70);
        cos_70 = cos_rad(unk_70);
        camera->lookAt_eye.x = ((cos_70 * zero) - (temp_f28_2 * sin_70)) + camera->lookAt_obj.x;
        camera->lookAt_eye.y = camera->lookAt_obj.y + temp_f24;
        camera->lookAt_eye.z = camera->lookAt_obj.z + ((sin_70 * zero) + (temp_f28_2 * cos_70));
    }
    deltaX = camera->lookAt_obj_target.x - camera->lookAt_obj.x;
    deltaY = (camera->lookAt_obj_target.y + camera->currentYOffset) - camera->lookAt_obj.y;
    deltaZ = camera->lookAt_obj_target.z - camera->lookAt_obj.z;
    if (fabsf(deltaX) > 16.0f) {
        if (deltaX < 0.0f) {
            deltaX = -16.0f;
        } else {
            deltaX = 16.0f;
        }
    }
    if (fabsf(deltaY) > 16.0f) {
        if (deltaY < 0.0f) {
            deltaY = -16.0f;
        } else {
            deltaY = 16.0f;
        }
    }
    if (fabsf(deltaZ) > 16.0f) {
        if (deltaZ < 0.0f) {
            deltaZ = -16.0f;
        } else {
            deltaZ = 16.0f;
        }
    }
    camera->lookAt_obj.x += deltaX * 0.5f;
    camera->lookAt_obj.y += deltaY * 0.5f;
    camera->lookAt_obj.z += deltaZ * 0.5f;
    zero = 0.0f;
    unk_70 = -zero;
    boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    temp_f24 = (cosBoom * zero) + (camera->currentBoomLength * sinBoom);
    temp_f28_2 = (sinBoom * unk_70) + (camera->currentBoomLength * cosBoom);
    unk_70 = DEG_TO_RAD(camera->unk_70);
    sin_70 = sin_rad(unk_70);
    cos_70 = cos_rad(unk_70);
    deltaX = ((camera->lookAt_obj.x + ((cos_70 * zero) - (temp_f28_2 * sin_70))) - camera->lookAt_eye.x) * 0.5f;
    deltaZ = ((camera->lookAt_obj.z + ((sin_70 * zero) + (temp_f28_2 * cos_70))) - camera->lookAt_eye.z) * 0.5f;
    deltaY = ((camera->lookAt_obj.y + temp_f24) - camera->lookAt_eye.y) * 0.5f;
    if (fabsf(deltaX) > 16.0f) {
        if (deltaX < 0.0f) {
            deltaX = -16.0f;
        } else {
            deltaX = 16.0f;
        }
    }
    if (fabsf(deltaY) > 16.0f) {
        if (deltaY < 0.0f) {
            deltaY = -16.0f;
        } else {
            deltaY = 16.0f;
        }
    }
    if (fabsf(deltaZ) > 16.0f) {
        if (deltaZ < 0.0f) {
            deltaZ = -16.0f;
        } else {
            deltaZ = 16.0f;
        }
    }
    camera->lookAt_eye.x += deltaX;
    camera->lookAt_eye.y += deltaY;
    camera->lookAt_eye.z += deltaZ;
    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->currentPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}
#else
INCLUDE_ASM(void, "9d10_len_1080", update_camera_mode_2, Camera* camera);
#endif

INCLUDE_ASM(void, "9d10_len_1080", update_camera_mode_1, Camera* camera);

void update_camera_mode_0(Camera* camera) {
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;

    if (camera->unk_06) {
        camera->lookAt_obj.x = 0.0f;
        camera->lookAt_obj.y = 0.0f;
        camera->lookAt_obj.z = 0.0f;
        camera->unk_06 = FALSE;
        camera->lookAt_eye.x = camera->lookAt_obj.x;
        camera->lookAt_eye.y = camera->lookAt_obj.y;
        camera->lookAt_eye.z = camera->lookAt_obj.z - (1000.0f / D_8009A5EC);
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    xTemp = camera->lookAt_obj.x - camera->lookAt_eye.x;
    yTemp = camera->lookAt_obj.y - camera->lookAt_eye.y;
    zTemp = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, xTemp, zTemp);
    xTemp = -sqrtf(SQ(xTemp) + SQ(zTemp));
    camera->currentPitch = atan2(0.0f, 0.0f, yTemp, xTemp);
}
