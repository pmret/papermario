#include "common.h"

void update_camera_mode_6(Camera* camera);
// types, floats, and other shtuff
#ifdef NON_EQUIVALENT
void update_camera_mode_6(Camera* camera) {
    f32 xDiff, yDiff, zDiff;
    f32 boomYaw;
    f32 sinBoomYaw;
    f32 cosBoomYaw;
    f32 trueRotX;
    f32 sinRotX;
    f32 cosRotX;
    f32 temp_f24_2;
    f32 temp_f30;
    s32 var_v1;

    if (camera->unk_06 != 0 || camera->changingMap) {
        camera->unk_06 = 0;
        camera->changingMap = 0;
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
        var_v1 = 10000 / camera->lookAt_dist;
        camera->trueRotation.x = camera->auxBoomYaw;
        camera->currentBoomYaw = camera->auxBoomPitch;
        camera->currentBoomLength = camera->auxBoomLength;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x + camera->targetPos.x;
        camera->lookAt_obj.y = (camera->lookAt_obj_target.y + camera->targetPos.y) + (camera->auxBoomZOffset * 0.00390625);
        camera->lookAt_obj.z = camera->lookAt_obj_target.z + camera->targetPos.z;
        if (var_v1 < 0) {
            var_v1 += 3;
        }
        camera->vfov = (var_v1 >> 2);
        boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
        sinBoomYaw = sin_rad(boomYaw);
        cosBoomYaw = cos_rad(boomYaw);
        temp_f30 = (cosBoomYaw * 0.0f) + (camera->currentBoomLength * sinBoomYaw);
        temp_f24_2 = (sinBoomYaw * -0.0f) + (camera->currentBoomLength * cosBoomYaw);
        trueRotX = DEG_TO_RAD(camera->trueRotation.x);
        sinRotX = sin_rad(trueRotX);
        cosRotX = cos_rad(trueRotX);
        camera->lookAt_eye.x = camera->lookAt_obj.x + ((cosRotX * 0.0f) - (temp_f24_2 * sinRotX));
        camera->lookAt_eye.y = camera->lookAt_obj.y + temp_f30;
        camera->lookAt_eye.z = camera->lookAt_obj.z + ((sinRotX * 0.0f) + (temp_f24_2 * cosRotX));
    }
    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    xDiff = camera->lookAt_obj.x - camera->lookAt_eye.x;
    yDiff = camera->lookAt_obj.y - camera->lookAt_eye.y;
    zDiff = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, xDiff, zDiff);
    camera->currentPitch = atan2(0.0f, 0.0f, yDiff, -sqrtf((xDiff * xDiff) + (zDiff * zDiff)));
    gBattleStatus.camLookatObjPos.x = camera->lookAt_obj.x;
    gBattleStatus.camLookatObjPos.y = camera->lookAt_obj.y;
    gBattleStatus.camLookatObjPos.z = camera->lookAt_obj.z;
}
#else
INCLUDE_ASM(void, "ad90_len_2880", update_camera_mode_6, Camera* camera);
#endif
