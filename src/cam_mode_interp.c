#include "common.h"
#include "camera.h"

// implements CAM_UPDATE_UNUSED_CONFINED
// this camera tracks targetPos, clamped within the rectangular region given by +/- xLimit and +/- zLimit
// y-position is drawn from lookAt_obj_target
// does not use easing or interpolation
// uses a boom arm, but pitch and yaw are always zero
//
// control parameters:
// dist -- length of the camera boom arm
// offsetY -- offset of the base of the boom arm above the target point
// xLimit -- confine x position of target from -xLimit to +xLimit
// zLimit -- confine z position of target from -zLimit to +zLimit
void update_camera_unused_confined(Camera* camera) {
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
    deltaX = camera->params.confined.xLimit;
    if (f0 > deltaX) {
        f0 = deltaX;
    }
    if (f0 < -deltaX) {
        f0 = -deltaX;
    }
    camera->lookAt_obj_target.x = f0;
    f4 = camera->targetPos.z;
    deltaZ = camera->params.confined.zLimit;
    if (f4 > deltaZ) {
        f4 = deltaZ;
    }
    if (f4 < -deltaZ) {
        f4 = -deltaZ;
    }
    camera->lookAt_obj_target.z = f4;
    camera->interpYaw = 0.0f;
    camera->curBoomPitch = 0.0f;
    camera->curBoomYaw = camera->interpYaw;
    camera->curBoomLength = camera->params.confined.dist * CamLengthScale;
    camera->targetOffsetY = camera->params.confined.offsetY * CamLengthScale;
    if (camera->needsInit) {
        camera->needsInit = FALSE;
        camera->unk_98 = 0.0f;
        camera->unk_9C = 0.0f;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->targetOffsetY;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        boomYaw = DEG_TO_RAD(camera->curBoomPitch);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->curBoomLength;
        deltaX2 = deltaX;
        deltaY2 = deltaY;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = deltaZ;
        new_var = boomYaw;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->interpYaw);
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
    camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->targetOffsetY;
    camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    boomYaw = DEG_TO_RAD(camera->curBoomPitch);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->curBoomLength;
    deltaX2 = deltaX;
    deltaY2 = deltaY;
    boomYaw = deltaX = -deltaY2;
    deltaZ2 = deltaZ;
    new_var = boomYaw;
    deltaX = deltaX2;
    deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
    deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
    boomYaw = DEG_TO_RAD(camera->interpYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaY2 = deltaY;
    deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
    camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
    camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
    camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->lookAt_yaw = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->lookAt_pitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

// implements CAM_UPDATE_INTERP_POS
// this camera uses a set of control parameters to calculate its target lookAt_obj and lookAt_eye positions,
// then interpolates current positions toward those targets, moving up to half the remaining distance each frame
// position of the camera is determined with a boom and the ultimate target is given by lookAt_obj_target
//
// control parameters:
// dist -- length of the camera boom arm
// pitch -- rising angle of the boom arm, up toward the y-axis
// yaw -- yaw angle for the boom arm in the xz-plane
// offsetY -- offset of the base of the boom arm above the target point
void update_camera_interp_pos(Camera *camera) {
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

    camera->interpYaw = camera->params.interp.yaw;
    camera->curBoomLength = camera->params.interp.dist * CamLengthScale;
    camera->targetOffsetY = camera->params.interp.offsetY * CamLengthScale;
    camera->curBoomPitch = camera->params.interp.pitch;
    camera->curBoomYaw = camera->interpYaw;
    if (camera->needsInit) {
        camera->needsInit = FALSE;
        camera->unk_98 = 0.0f;
        camera->unk_9C = 0.0f;

        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->targetOffsetY;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;

        boomYaw = DEG_TO_RAD(camera->curBoomPitch);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);

        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->curBoomLength;

        deltaX3 = deltaX;
        deltaY3 = -deltaY;
        tmp = -0.0f; //required to match
        deltaZ3 = deltaZ;

        deltaX = deltaX3;
        deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
        deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

        boomYaw = DEG_TO_RAD(camera->interpYaw);
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
    deltaY2 = (camera->lookAt_obj_target.y + camera->targetOffsetY) - camera->lookAt_obj.y;
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

    boomYaw = DEG_TO_RAD(camera->curBoomPitch);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->curBoomLength;

    deltaX3 = deltaX;
    deltaY3 = -deltaY;
    deltaZ3 = deltaZ;

    deltaX = deltaX3;
    deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
    deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

    boomYaw = DEG_TO_RAD(camera->interpYaw);
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

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);

    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;

    camera->lookAt_yaw = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->lookAt_pitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}
