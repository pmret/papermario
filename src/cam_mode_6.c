#include "common.h"

// implementation for CAM_UPDATE_MODE_6
void update_camera_mode_6(Camera* camera) {
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 boomYaw;
    f32 new_var;
    f32 planarDist;

    if (camera->needsInit || camera->isChangingMap) {
        camera->needsInit = FALSE;
        camera->isChangingMap = FALSE;
        camera->auxPitch = 0;
        camera->auxBoomLength = 100;
        camera->lookAt_dist = 100;
        camera->auxBoomPitch = 0;
        camera->auxBoomYaw = 0;
        camera->auxBoomZOffset = 0;
        camera->targetPos.x = 0.0f;
        camera->targetPos.y = 0.0f;
        camera->targetPos.z = 0.0f;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    }
    if (camera->auxPitch == 0) {
        camera->lookAt_obj.x = camera->lookAt_obj_target.x + camera->targetPos.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->targetPos.y + camera->auxBoomZOffset / 256.0;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z + camera->targetPos.z;
        camera->trueRot.x = camera->auxBoomYaw;
        camera->curBoomYaw = camera->auxBoomPitch;
        camera->curBoomLength = camera->auxBoomLength;
        camera->vfov = (10000 / camera->lookAt_dist) / 4;
        boomYaw = DEG_TO_RAD(camera->curBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->curBoomLength;
        deltaX2 = 0.0f;
        deltaY2 = 0.0f;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = camera->curBoomLength;
        new_var = boomYaw;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->trueRot.x);
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
    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    planarDist = sqrtf(SQ(deltaX) + SQ(deltaZ));
    camera->curPitch = atan2(0.0f, 0.0f, deltaY, -planarDist);
    gBattleStatus.camLookatObjPos.x = camera->lookAt_obj.x;
    gBattleStatus.camLookatObjPos.y = camera->lookAt_obj.y;
    gBattleStatus.camLookatObjPos.z = camera->lookAt_obj.z;
}
