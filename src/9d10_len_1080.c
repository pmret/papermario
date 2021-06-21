#include "common.h"
#include "camera.h"

void do_camera_type_0(Camera*);

INCLUDE_ASM(void, "9d10_len_1080", do_camera_type_4, Camera* camera);

INCLUDE_ASM(void, "9d10_len_1080", do_camera_type_2, Camera* camera);

INCLUDE_ASM(void, "9d10_len_1080", do_camera_type_1, Camera* camera);

void do_camera_type_0(Camera* camera) {
    f32 xTemp;
    f32 yTemp;
    f32 zTemp;

    if (camera->unk_06 != 0) {
        camera->lookAt_obj.x = 0.0f;
        camera->lookAt_obj.y = 0.0f;
        camera->lookAt_obj.z = 0.0f;
        camera->unk_06 = 0;
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
