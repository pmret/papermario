#include "common.h"
#include "camera.h"

// implements CAM_UPDATE_MINIMAL
// simple camera based on lookAt_eye and lookAt_obj with no blending or interpolation
// control this camera by directly setting these positions
//
// no control parameters
void update_camera_minimal(Camera* camera) {
    f32 dx, dy, dz;

    if (camera->needsInit) {
        camera->needsInit = false;

        camera->lookAt_obj.x = 0.0f;
        camera->lookAt_obj.y = 0.0f;
        camera->lookAt_obj.z = 0.0f;

        camera->lookAt_eye.x = camera->lookAt_obj.x;
        camera->lookAt_eye.y = camera->lookAt_obj.y;
        camera->lookAt_eye.z = camera->lookAt_obj.z - (1000.0f / CamLengthScale);
    }

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    dx = camera->lookAt_obj.x - camera->lookAt_eye.x;
    dy = camera->lookAt_obj.y - camera->lookAt_eye.y;
    dz = camera->lookAt_obj.z - camera->lookAt_eye.z;

    camera->lookAt_yaw = -atan2(0.0f, 0.0f, dx, dz);
    dx = sqrtf(SQ(dx) + SQ(dz));
    camera->lookAt_pitch = atan2(0.0f, 0.0f, dy, -dx);
}
