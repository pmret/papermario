#include "common.h"
#include "camera.h"

// implementation for CAM_UPDATE_MODE_INIT
// simple camera based on lookAt_eye and lookAt_obj with no blending or interpolation
void update_camera_mode_0(Camera* camera) {
    f32 dx;
    f32 dy;
    f32 dz;

    if (camera->needsInit) {
        camera->lookAt_obj.x = 0.0f;
        camera->lookAt_obj.y = 0.0f;
        camera->lookAt_obj.z = 0.0f;
        camera->needsInit = FALSE;
        camera->lookAt_eye.x = camera->lookAt_obj.x;
        camera->lookAt_eye.y = camera->lookAt_obj.y;
        camera->lookAt_eye.z = camera->lookAt_obj.z - (1000.0f / D_8009A5EC);
    }

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    dx = camera->lookAt_obj.x - camera->lookAt_eye.x;
    dy = camera->lookAt_obj.y - camera->lookAt_eye.y;
    dz = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, dx, dz);
    dx = -sqrtf(SQ(dx) + SQ(dz));
    camera->curPitch = atan2(0.0f, 0.0f, dy, dx);
}
