#include "common.h"

void update_camera_mode_6(Camera*);

// types, floats, and other shtuff
#ifdef NON_EQUIVALENT
void update_camera_mode_6(Camera* camera) {
    f32 cosBoom;
    f32 cosRotation;
    f32 deltaX;
    f32 temp_f24_2;
    f32 deltaZ;
    f32 boomYaw;
    f32 rotation;
    f32 sinBoom;
    f32 sinRotation;
    f32 temp_f30;
    f32 deltaY;
    s32 temp_lo;

    if (camera->unk_06 != 0 || camera->unk_08 != 0) {
        camera->unk_06 = 0;
        camera->unk_08 = 0;
        camera->unk_1C = 0;
        camera->unk_1E = 100;
        camera->unk_20 = 100;
        camera->unk_22 = 0;
        camera->unk_24 = 0;
        camera->unk_26 = 0;
        camera->targetPos.x = 0.0f;
        camera->targetPos.y = 0.0f;
        camera->targetPos.z = 0.0f;
        camera->lookAt_obj.x = camera->unk_54;
        camera->lookAt_obj.y = camera->unk_58;
        camera->lookAt_obj.z = camera->unk_5C;
    }

    if (camera->unk_1C == 0) {
        temp_lo = 10000 / camera->unk_20;
        camera->trueRotation.x = camera->unk_24;
        camera->lookAt_obj.x = camera->unk_54 + camera->targetPos.x;
        camera->currentBoomYaw = camera->unk_22;
        camera->currentBoomLength = camera->unk_1E;
        camera->lookAt_obj.z = camera->unk_5C + camera->targetPos.z;
        camera->lookAt_obj.y = (camera->unk_58 + camera->targetPos.y) + (camera->unk_26 * 0.00390625);

        if (temp_lo < 0) {
            temp_lo += 3;
        }
        camera->vfov = (f32) (temp_lo >> 2);

        boomYaw = (camera->currentBoomYaw * TAU) / 360.0f;
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        temp_f30 = (cosBoom * 0.0f) + (camera->currentBoomLength * sinBoom);
        temp_f24_2 = (sinBoom * -0.0f) + (camera->currentBoomLength * cosBoom);

        rotation = (camera->trueRotation.x * TAU) / 360.0f;
        sinRotation = sin_rad(rotation);
        cosRotation = cos_rad(rotation);

        camera->lookAt_eye.y = camera->lookAt_obj.y + temp_f30;
        camera->lookAt_eye.x = camera->lookAt_obj.x + ((cosRotation * 0.0f) - (temp_f24_2 * sinRotation));
        camera->lookAt_eye.z = camera->lookAt_obj.z + ((sinRotation * 0.0f) + (temp_f24_2 * cosRotation));
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->currentPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf((deltaX * deltaX) + (deltaZ * deltaZ)));
    gBattleStatus.unk_CC.x = camera->lookAt_obj.x;
    gBattleStatus.unk_CC.y = camera->lookAt_obj.y;
    gBattleStatus.unk_CC.z = camera->lookAt_obj.z;
}
#else
INCLUDE_ASM(void, "ad90_len_2880", update_camera_mode_6, Camera* camera);
#endif
