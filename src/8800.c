#include "common.h"
#include "camera.h"

// D_8009A5EC bss here

void initialize_next_camera(CameraInitData* data);

//INCLUDE_ASM(s32, "8800", update_cameras);
void update_cameras(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        Camera* cam = &gCameras[i];

        if (cam->flags != 0 && !(cam->flags & 2)) {
            s32 sx;
            s32 sy;
            s32 sz;

            gCurrentCamID = i;

            switch (cam->mode) {
                case 3:
                    update_camera_zone_interp(cam);
                    break;
                case 0:
                    update_camera_mode_0(cam);
                    break;
                case 1:
                    update_camera_mode_1(cam);
                    break;
                case 2:
                    update_camera_mode_2(cam);
                    break;
                case 4:
                    update_camera_mode_4(cam);
                    break;
                case 5:
                    update_camera_mode_5(cam);
                    break;
                case 6:
                default:
                    update_camera_mode_6(cam);
                    break;
            }

            guLookAtReflectF(cam->viewMtxPlayer, &gDisplayContext->lookAt[0],  cam->lookAt_eye.x, cam->lookAt_eye.y, cam->lookAt_eye.z, cam->lookAt_obj.x, cam->lookAt_obj.y, cam->lookAt_obj.z, 0, 1.0f, 0);

            if (!(cam->flags & 0x10)) { // TODO: 'ortho' flag
                if (cam->flags & 4) { // TODO: 'leadplayer' flag
                    create_camera_leadplayer_matrix(cam);
                }

                guPerspectiveF(cam->perspectiveMatrix, &cam->perspNorm, cam->vfov, (f32) cam->viewportW / (f32) cam->viewportH, (f32) cam->nearClip, (f32) cam->farClip, 1.0f);

                if (cam->flags & 8) { // TODO: 'shaking' flag
                    guMtxCatF(cam->viewMtxShaking, cam->perspectiveMatrix, cam->perspectiveMatrix);
                }

                if (cam->flags & 4) { // TODO: 'leadplayer' flag
                    guMtxCatF(cam->viewMtxLeading, cam->perspectiveMatrix, cam->perspectiveMatrix);
                }

                guMtxCatF(cam->viewMtxPlayer, cam->perspectiveMatrix, cam->perspectiveMatrix);
            } else {
                f32 w = cam->viewportW;
                f32 h = cam->viewportH;

                guOrthoF(cam->perspectiveMatrix, -w * 0.5, w * 0.5, -h * 0.5, h * 0.5, -1000.0f, 1000.0f, 1.0f);
            }

            get_screen_coords(0, cam->targetPos.x, cam->targetPos.y, cam->targetPos.z, &sx, &sy, &sz);
            cam->targetScreenCoords[0] = sx;
            cam->targetScreenCoords[1] = sy;
            cam->targetScreenCoords[2] = sz;
        }
    }

    gCurrentCamID = 0;
}

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
