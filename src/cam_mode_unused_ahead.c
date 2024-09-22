#include "common.h"

// implements CAM_UPDATE_UNUSED_AHEAD
// this mode is completely unused in vanilla; it doesn't even have a case in update_cameras
// seems to be based on CAM_UPDATE_NO_INTERP (the one used for battle cam)
// tracks a point 400 units ahead of player position in the z-direction and 60 units above
// defaults to a relatively short boom length and no pitch angle, resulting in a head-on direct view
//
// control parameters:
// dist -- length of the camera boom arm
// pitch -- rising angle of the boom arm, up toward the y-axis
// yaw -- yaw angle for the boom arm in the xz-plane
// skipRecalc -- do not calculate lookAt_obj and lookAt_eye from params
void update_camera_unused_ahead(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 boomYaw;

    if (camera->needsInit || camera->needsReinit) {
        camera->needsInit = FALSE;
        camera->needsReinit = FALSE;
        camera->params.basic.skipRecalc = FALSE;
        camera->params.basic.dist = 100;
        camera->params.basic.fovScale = 100;
        camera->params.basic.pitch = 0;
        camera->params.basic.yaw = 0;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    }

    if (!(playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING))) {
        camera->lookAt_obj_target.y = playerStatus->pos.y + 60.0f;
    }
    camera->lookAt_obj_target.x = playerStatus->pos.x;
    camera->lookAt_obj_target.z = playerStatus->pos.z + 400.0f;

    if (!camera->params.basic.skipRecalc) {
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        camera->curBoomYaw = camera->params.basic.yaw;
        camera->curBoomPitch = camera->params.basic.pitch;
        camera->curBoomLength = camera->params.basic.dist;
        camera->vfov = (10000 / camera->params.basic.fovScale) / 4;
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
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * boomYaw + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->curBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaZ2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY2 = deltaY;
        deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
        camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
        camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
        camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    }
    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->lookAt_yaw = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->lookAt_pitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}
