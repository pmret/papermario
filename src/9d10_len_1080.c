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

void update_camera_mode_2(Camera *camera) {
    f32 cosBoom;
    f32 sinBoom;
    f32 boomYaw;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 deltaX3;
    f32 deltaY3;
    f32 deltaZ3;
    f32 tmp;

    camera->unk_70 = camera->auxBoomLength;
    camera->currentBoomLength = camera->lookAt_dist * D_8009A5EC;
    camera->currentYOffset = camera->auxBoomPitch * D_8009A5EC;
    camera->currentBoomYaw = camera->auxPitch;
    camera->trueRotation.x = camera->unk_70;
    if (camera->unk_06) {
        camera->unk_06 = 0;
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

        deltaX3 = deltaX;
        deltaY3 = -deltaY;
        tmp = -0.0f; //required to match
        deltaZ3 = deltaZ;

        deltaX = deltaX3;
        deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
        deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

        boomYaw = DEG_TO_RAD(camera->unk_70);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);

        deltaX3 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY3 = deltaY;
        deltaZ3 = sinBoom * deltaX + deltaZ * cosBoom;

        deltaX2 = camera->lookAt_obj.x + deltaX3;
        deltaY2 = camera->lookAt_obj.y + deltaY3;
        deltaZ2 = camera->lookAt_obj.z + deltaZ3;

        camera->lookAt_eye.x = deltaX2;
        camera->lookAt_eye.y = deltaY2;
        camera->lookAt_eye.z = deltaZ2;
    }

    deltaX2 = camera->lookAt_obj_target.x - camera->lookAt_obj.x;
    deltaY2 = (camera->lookAt_obj_target.y + camera->currentYOffset) - camera->lookAt_obj.y;
    deltaZ2 = camera->lookAt_obj_target.z - camera->lookAt_obj.z;

    if (fabsf(deltaX2) > 16.0f) {
        if (deltaX2 < 0.0f) {
            deltaX2 = -16.0f;
        } else {
            deltaX2 = 16.0f;
        }
    }
    if (fabsf(deltaY2) > 16.0f) {
        if (deltaY2 < 0.0f) {
            deltaY2 = -16.0f;
        } else {
            deltaY2 = 16.0f;
        }
    }
    if (fabsf(deltaZ2) > 16.0f) {
        if (deltaZ2 < 0.0f) {
            deltaZ2 = -16.0f;
        } else {
            deltaZ2 = 16.0f;
        }
    }

    camera->lookAt_obj.x += deltaX2 * 0.5f;
    camera->lookAt_obj.y += deltaY2 * 0.5f;
    camera->lookAt_obj.z += deltaZ2 * 0.5f;

    boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->currentBoomLength;

    deltaX3 = deltaX;
    deltaY3 = -deltaY;
    deltaZ3 = deltaZ;

    deltaX = deltaX3;
    deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
    deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

    boomYaw = DEG_TO_RAD(camera->unk_70);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX3 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaY3 = deltaY;
    deltaZ3 = sinBoom * deltaX + deltaZ * cosBoom;

    deltaX2 = camera->lookAt_obj.x + deltaX3;
    deltaY2 = camera->lookAt_obj.y + deltaY3;
    deltaZ2 = camera->lookAt_obj.z + deltaZ3;

    deltaX2 = (deltaX2 - camera->lookAt_eye.x) * 0.5f;
    deltaY2 = (deltaY2 - camera->lookAt_eye.y) * 0.5f;
    deltaZ2 = (deltaZ2 - camera->lookAt_eye.z) * 0.5f;

    tmp = 0.0f; //required to match

    if (fabsf(deltaX2) > 16.0f) {
        if (deltaX2 < 0.0f) {
            deltaX2 = -16.0f;
        } else {
            deltaX2 = 16.0f;
        }
    }
    if (fabsf(deltaY2) > 16.0f) {
        if (deltaY2 < 0.0f) {
            deltaY2 = -16.0f;
        } else {
            deltaY2 = 16.0f;
        }
    }
    if (fabsf(deltaZ2) > 16.0f) {
        if (deltaZ2 < 0.0f) {
            deltaZ2 = -16.0f;
        } else {
            deltaZ2 = 16.0f;
        }
    }

    camera->lookAt_eye.x += deltaX2;
    camera->lookAt_eye.y += deltaY2;
    camera->lookAt_eye.z += deltaZ2;

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);

    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;

    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->currentPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

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
