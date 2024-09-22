#include "common.h"

// implements CAM_UPDATE_NO_INTERP
// this camera uses a set of control parameters to calculate its lookAt_obj and lookAt_eye positions,
// which are only updated if skipRecalc = FALSE
// the ultimate target is given by lookAt_obj_target, with an offset given by targetPos (?!)
// in practice, this is used for CAM_BATTLE and CAM_TATTLE, with skipRecalc almost always set to FALSE
//
// control parameters:
// dist -- length of the camera boom arm
// pitch -- rising angle of the boom arm, up toward the y-axis
// yaw -- yaw angle for the boom arm in the xz-plane
// offsetY -- offset of the base of the boom arm above the target point
// fovScale -- adjusts vertical fov, with 100 being normal (=25). scales as 1/x so larger values mean smaller vfov.
// skipRecalc -- do not calculate lookAt_obj and lookAt_eye from params
void update_camera_no_interp(Camera* camera) {
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

    if (camera->needsInit || camera->needsReinit) {
        camera->needsInit = FALSE;
        camera->needsReinit = FALSE;
        camera->params.basic.skipRecalc = FALSE;
        camera->params.basic.dist = 100;
        camera->params.basic.fovScale = 100;
        camera->params.basic.pitch = 0;
        camera->params.basic.yaw = 0;
        camera->params.basic.offsetY = 0;
        camera->targetPos.x = 0.0f;
        camera->targetPos.y = 0.0f;
        camera->targetPos.z = 0.0f;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    }

    if (!camera->params.basic.skipRecalc) {
        camera->lookAt_obj.x = camera->lookAt_obj_target.x + camera->targetPos.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->targetPos.y + camera->params.basic.offsetY / 256.0;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z + camera->targetPos.z;
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
        deltaX2 = 0.0f;
        deltaY2 = 0.0f;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = camera->curBoomLength;
        new_var = boomYaw;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
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
    planarDist = sqrtf(SQ(deltaX) + SQ(deltaZ));
    camera->lookAt_pitch = atan2(0.0f, 0.0f, deltaY, -planarDist);
    gBattleStatus.camLookatObjPos.x = camera->lookAt_obj.x;
    gBattleStatus.camLookatObjPos.y = camera->lookAt_obj.y;
    gBattleStatus.camLookatObjPos.z = camera->lookAt_obj.z;
}
