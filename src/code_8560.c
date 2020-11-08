#include "common.h"

INCLUDE_ASM(s32, "code_8560", func_8002D160);

INCLUDE_ASM(s32, "code_8560", update_cameras);

INCLUDE_ASM(s32, "code_8560", render_frame);

INCLUDE_ASM(s32, "code_8560", create_cameras_a);

INCLUDE_ASM(s32, "code_8560", create_cameras_b);

INCLUDE_ASM(s32, "code_8560", initialize_next_camera);

INCLUDE_ASM(void, "code_8560", set_cam_viewport, s16 id, s16 x, s16 y, s16 width, s16 height);

void get_cam_viewport(s32 camID, u16* x, u16* y, u16* width, u16* height) {
    *width = CAM(camID)->viewportW;
    *height = CAM(camID)->viewportH;
    *x = CAM(camID)->viewportStartX;
    *y = CAM(camID)->viewportStartY;
}

INCLUDE_ASM(void, "code_8560", get_screen_coords, Cam camID, f32 x, f32 y, f32 z, f32* outX, f32* outY,
            f32* outZ);

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

INCLUDE_ASM(s32, "code_8560", func_8002E82C);
