#include "common.h"

extern f32 D_8009A5EC;

void initialize_next_camera(CameraInitData* data);

INCLUDE_ASM(s32, "8800", update_cameras);

INCLUDE_ASM(void, "8800", render_frame);

void create_cameras_a(void) {
    CameraInitData camData;
    CameraInitData* camDataPtr = &camData;
    s32 i;

    D_8009A5EC = 1.0f;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i].flags = 0;
    }

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);
}

void create_cameras_b(void) {
    CameraInitData camData;
    CameraInitData* camDataPtr = &camData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i].flags = 0;
    }

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = 2;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);
}

INCLUDE_ASM(void, "8800", initialize_next_camera, CameraInitData* data);

INCLUDE_ASM(void, "8800", set_cam_viewport, s16 id, s16 x, s16 y, s16 width, s16 height);

void get_cam_viewport(s32 camID, u16* x, u16* y, u16* width, u16* height) {
    *width = CAM(camID)->viewportW;
    *height = CAM(camID)->viewportH;
    *x = CAM(camID)->viewportStartX;
    *y = CAM(camID)->viewportStartY;
}

INCLUDE_ASM(void, "8800", get_screen_coords, Cam camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ);

s32 func_8002E754(s32 camID, s32 x, s32 y) {
    s32 startX = CAM(camID)->viewportStartX;
    s32 startY = CAM(camID)->viewportStartY;
    s32 endX = startX + CAM(camID)->viewportW;
    s32 endY = startY + CAM(camID)->viewportH;

    if (x < startX) {
        return TRUE;
    } else if (x > endX) {
        return TRUE;
    } else if (y < startY) {
        return TRUE;
    } else if (y > endY) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void func_8002E7CC(s32 camID, s32* x, s32* y, s32* width, s32* height) {
    *x = CAM(camID)->viewportStartX;
    *y = CAM(camID)->viewportStartY;
    *width = CAM(camID)->viewportStartX + CAM(camID)->viewportW;
    *height = CAM(camID)->viewportStartY + CAM(camID)->viewportH;
}

INCLUDE_ASM(s32, "8800", func_8002E82C);
