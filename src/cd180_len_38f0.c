#include "common.h"
#include "overlay.h"

// BSS
extern s32 screen_overlay_frontType;
extern f32 screen_overlay_frontZoom;
extern s32 screen_overlay_backType;
extern f32 screen_overlay_backZoom;
extern s32 D_80156910;
extern ScreenOverlay D_8015C790[2];

s32 D_8014C6F0 = 2;

// padding?
s32 D_8014C6F4[] = { 0x00000000, 0x00000000, 0x00000000, };

#include "ui/star_silhouette.png.inc.c"

#include "ui/mario_head_silhouette.png.inc.c"

#include "ui/quarter_circle_silhouette.png.inc.c"

#include "ui/flame_thing_silhouette.png.inc.c"

s32 D_8014E500[] = {  0xFF8000A9, 0x00000000, 0x00000000, 0xFFFFFF00, 0xFF34FFBB, 0x00000000, 0x00000000, 0xFFFFFF00, 0x0000FF24, 0x00000000, 0x00000000, 0xFFFFFF00, 0x008000A9, 0x00000000, 0x00000000, 0xFFFFFF00, 0xFE88007B, 0x00000000, 0x00000000, 0xFFFFFF00, 0x0000018B, 0x00000000, 0x00000000, 0xFFFFFF00, 0xFF17FEC0, 0x00000000, 0x00000000, 0xFFFFFF00, 0x00CCFFBB, 0x00000000, 0x00000000, 0xFFFFFF00, 0x00E8FEC0, 0x00000000, 0x00000000, 0xFFFFFF00, 0x0178007A, 0x00000000, 0x00000000, 0xFFFFFF00, };

s32 D_8014E5A0[] = {  0xD7000002, 0xFFFFFFFF, 0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001201, 0x00003000, 0xE3001402, 0x00000C00, 0xE3000C00, 0x00000000, 0xE3001801, 0x00000000, 0xE3001A01, 0x00000000, 0xFCFFE7FF, 0xFFCD92C9, 0xE200001C, 0x00504340, 0xD9000000, 0x00000000, 0xD9FFFFFF, 0x00200004, 0xDF000000, 0x00000000, };

s32 D_8014E618[] = {  0xDE000000, &D_8014E5A0, 0xE3001001, 0x00000000, 0xFD88000F, ui_quarter_circle_silhouette_png, 0xF5880400, 0x070D4350, 0xE6000000, 0x00000000, 0xF4000000, 0x0703E07C, 0xE7000000, 0x00000000, 0xF5800400, 0x000D4350, 0xF2000000, 0x0007C07C, 0xF2000000, 0x000FC0FC, 0xDF000000, 0x00000000, };

s32 D_8014E670[] = {  0xDE000000, &D_8014E5A0, 0xE3001001, 0x00000000, 0xFD88001F, ui_mario_head_silhouette_png, 0xF5880800, 0x07098260, 0xE6000000, 0x00000000, 0xF4000000, 0x0707E0FC, 0xE7000000, 0x00000000, 0xF5800800, 0x00098260, 0xF2000000, 0x000FC0FC, 0xDF000000, 0x00000000, };

s32 D_8014E6C0[] = {  0xDE000000, &D_8014E5A0, 0xE3001001, 0x00000000, 0xFD88000F, ui_star_silhouette_png, 0xF5880400, 0x07098350, 0xE6000000, 0x00000000, 0xF4000000, 0x0703E0FC, 0xE7000000, 0x00000000, 0xF5800400, 0x00098350, 0xF2000000, 0x0007C0FC, 0xF2000000, 0x000FC0FC, 0xDF000000, 0x00000000, };

s32 D_8014E718[] = {  0xDE000000, &D_8014E5A0, 0xE3001001, 0x00000000, 0xFD88003F, ui_flame_thing_silhouette_png, 0xF5881000, 0x070D8360, 0xE6000000, 0x00000000, 0xF4000000, 0x070FC0FC, 0xE7000000, 0x00000000, 0xF5881000, 0x000D8360, 0xF2000000, 0x000FC0FC, 0xF2000000, 0x001FC1FC, 0xDF000000, 0x00000000, };

s32 D_8014E770[] = {  0x000000F0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x014000F0, 0x00000000, 0x28000000, 0xFFFFFFFF, 0x000000DA, 0x00000000, 0x000002C0, 0xFFFFFFFF, 0x014000DA, 0x00000000, 0x280002C0, 0xFFFFFFFF, 0x000000C4, 0x00000000, 0x00000580, 0xFFFFFFFF, 0x014000C4, 0x00000000, 0x28000580, 0xFFFFFFFF, 0x000000AE, 0x00000000, 0x00000840, 0xFFFFFFFF, 0x014000AE, 0x00000000, 0x28000840, 0xFFFFFFFF, 0x00000098, 0x00000000, 0x00000B00, 0xFFFFFFFF, 0x01400098, 0x00000000, 0x28000B00, 0xFFFFFFFF, 0x00000082, 0x00000000, 0x00000DC0, 0xFFFFFFFF, 0x01400082, 0x00000000, 0x28000DC0, 0xFFFFFFFF, 0x0000006C, 0x00000000, 0x00001080, 0xFFFFFFFF, 0x0140006C, 0x00000000, 0x28001080, 0xFFFFFFFF, 0x00000056, 0x00000000, 0x00001340, 0xFFFFFFFF, 0x01400056, 0x00000000, 0x28001340, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00001600, 0xFFFFFFFF, 0x01400040, 0x00000000, 0x28001600, 0xFFFFFFFF, 0x0000002A, 0x00000000, 0x000018C0, 0xFFFFFFFF, 0x0140002A, 0x00000000, 0x280018C0, 0xFFFFFFFF, 0x00000014, 0x00000000, 0x00001B80, 0xFFFFFFFF, 0x01400014, 0x00000000, 0x28001B80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00001E00, 0xFFFFFFFF, 0x01400000, 0x00000000, 0x28001E00, 0xFFFFFFFF, };

s32 D_8014E8F0[] = {  0xD7000000, 0x80008000, 0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xE2001D00, 0x00000004, 0xEE000000, 0x00000000, 0xE200001C, 0x50504360, 0xFCFFE7FF, 0xFFCE7F3F, 0xE3000C00, 0x00080000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xD9DDF9FF, 0x00000000, 0xD9FFFFFF, 0x00000405, 0x0100A014, D_8014E500, 0x06000204, 0x00060004, 0x06000802, 0x00060A00, 0x06020C04, 0x000E0604, 0x06100E04, 0x000E1206, 0xE7000000, 0x00000000, 0xE2001D00, 0x00000000, 0xDF000000, 0x00000000, };

s32 D_8014E9A8[] = {  0xE7000000, 0x00000000, 0xE2001D00, 0x00000004, 0xEE000000, 0x00140000, 0xE200001C, 0x00504A50, 0xFCFFE7FF, 0xFFCE7F3F, 0xD9DDF9FF, 0x00000000, 0xD9FFFFFF, 0x00000005, 0xE3001801, 0x00000000, 0xE3000A01, 0x00000000, 0xE3001201, 0x00002000, 0xE3000C00, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3000D01, 0x00000000, 0xE3001402, 0x00000C00, 0xF65003C0, 0x00000000, 0xE3001801, 0x000000C0, 0xE7000000, 0x00000000, 0xE2001D00, 0x00000000, 0xDF000000, 0x00000000, };

s32 D_8014EA48[] = {  0xE2001D00, 0x00000004, 0xEE000000, 0x00140000, 0xE200001C, 0x00552210, 0xD9FDF9FF, 0x00000000, 0xD9DFFFFF, 0x00000000, 0xD7000002, 0x80008000, 0xE7000000, 0x00000000, 0xFC121824, 0xFF33FFFF, 0xE3000C00, 0x00080000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0x01018030, &D_8014E770, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000000, 0x0727C02C, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000000, 0x0027C02C, 0x06000402, 0x00060204, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF400002C, 0x0727C058, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF200002C, 0x0027C058, 0x06040806, 0x000A0608, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000058, 0x0727C084, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000058, 0x0027C084, 0x06080C0A, 0x000E0A0C, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000084, 0x0727C0B0, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000084, 0x0027C0B0, 0x060C100E, 0x00120E10, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF40000B0, 0x0727C0DC, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF20000B0, 0x0027C0DC, 0x06101412, 0x00161214, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF40000DC, 0x0727C108, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF20000DC, 0x0027C108, 0x06141816, 0x001A1618, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000108, 0x0727C134, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000108, 0x0027C134, 0x06181C1A, 0x001E1A1C, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000134, 0x0727C160, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000134, 0x0027C160, 0x061C201E, 0x00221E20, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF4000160, 0x0727C18C, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF2000160, 0x0027C18C, 0x06202422, 0x00262224, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF400018C, 0x0727C1B8, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF200018C, 0x0027C1B8, 0x06242826, 0x002A2628, 0xFD10009F, &D_80156910, 0xF5105000, 0x07090280, 0xE6000000, 0x00000000, 0xF40001B8, 0x0727C1DC, 0xE7000000, 0x00000000, 0xF5105000, 0x00090280, 0xF20001B8, 0x0027C1DC, 0x06282C2A, 0x002E2A2C, 0xE7000000, 0x00000000, 0xE2001D00, 0x00000000, };


INCLUDE_ASM(void, "cd180_len_38f0", _render_transition_stencil, u8 arg0, f32 arg1, ScreenOverlay* arg2);

void set_screen_overlay_params_front(u8 type, f32 zoom) {
    screen_overlay_frontType = type;
    screen_overlay_frontZoom = zoom;
}

void set_screen_overlay_params_back(u8 type, f32 zoom) {
    screen_overlay_backType = type;
    screen_overlay_backZoom = zoom;
}

void get_screen_overlay_params(s32 idx, u8* type, f32* zoom) {
    switch (idx) {
        case 0:
            *type = screen_overlay_frontType;
            *zoom = screen_overlay_frontZoom;
            break;
        case 1:
            *type = screen_overlay_backType;
            *zoom = screen_overlay_backZoom;
            break;
    }
}

void set_screen_overlay_color(s32 idx, u8 r, u8 g, u8 b) {
    switch (idx) {
        case 0:
        case 1:
            D_8015C790[idx].color.r = r;
            D_8015C790[idx].color.g = g;
            D_8015C790[idx].color.b = b;
            break;
    }
}

void set_screen_overlay_center(s32 idx, s32 arg1, s32 arg2, s32 arg3) {
    switch (idx) {
        case 0:
        case 1:
            switch (arg1) {
                case 0:
                    D_8015C790[idx].screenPos[0][0] = arg2;
                    D_8015C790[idx].screenPos[0][1] = arg3;
                    break;
                case 1:
                    D_8015C790[idx].screenPos[1][0] = arg2;
                    D_8015C790[idx].screenPos[1][1] = arg3;
                    break;
            }
            break;
    }
}

void set_screen_overlay_center_worldpos(s32 idx, s32 posIdx, s32 x, s32 y, s32 z) {
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 tx, ty, tz, ts;

    switch (idx) {
        case 0:
        case 1:
            transform_point(camera->perspectiveMatrix[0], x, y, z, 1.0f, &tx, &ty, &tz, &ts);
            ts = 1.0f / ts;
            tx *= ts;
            ty *= -ts;
            tz *= ts;
            tx = (((tx * camera->viewportW) + camera->viewportW) * 0.5) + camera->viewportStartX;
            ty = (((ty * camera->viewportH) + camera->viewportH) * 0.5) + camera->viewportStartY;

            switch (posIdx) {
                case 0:
                    D_8015C790[idx].screenPos[0][0] = tx;
                    D_8015C790[idx].screenPos[0][1] = ty;
                    break;
                case 1:
                    D_8015C790[idx].screenPos[1][0] = tx;
                    D_8015C790[idx].screenPos[1][1] = ty;
                    break;
            }
            break;
    }
}

void set_screen_overlay_alpha(s32 idx, f32 alpha) {
    switch (idx) {
        case 0:
        case 1:
            D_8015C790[idx].alpha = alpha;
            break;
    }
}

void clear_screen_overlays(void) {
    ScreenOverlay* it;
    s32 i;

    screen_overlay_frontType = -1;
    screen_overlay_backType = -1;
    screen_overlay_frontZoom = -1.0f;
    screen_overlay_backZoom = -1.0f;

    for (it = &D_8015C790[0], i = 0; i < ARRAY_COUNT(D_8015C790); i++, it++) {
        it->color.b = 0;
        it->color.g = 0;
        it->color.r = 0;
        it->screenPos[1][1] = 0;
        it->screenPos[1][0] = 0;
        it->screenPos[0][1] = 0;
        it->screenPos[0][0] = 0;
        it->alpha = 255.0f;
    }
}

void func_80138188(void) {
    screen_overlay_backZoom = 0;
}

void func_80138198(void) {
}

void render_screen_overlay_frontUI(void) {
    if (screen_overlay_frontType != -1 && screen_overlay_frontZoom != -1.0f && gGameStatusPtr->isBattle != 2) {
        _render_transition_stencil(screen_overlay_frontType, screen_overlay_frontZoom, &D_8015C790[0]);
    }
}

void render_screen_overlay_backUI(void) {
    if (screen_overlay_backType != -1 && screen_overlay_backZoom != -1.0f && gGameStatusPtr->isBattle != 2) {
        _render_transition_stencil(screen_overlay_backType, screen_overlay_backZoom, &D_8015C790[1]);
    }
}

void set_map_transition_effect(s32 arg0) {
    D_8014C6F0 = arg0;
}

// r g b register ordering issues
#ifdef NON_EQUIVALENT
s32 update_exit_map_screen_overlay(s16* progress) {
    u8 overlayColor;
    u8 type;
    s32 phi_s2;
    s16 t;
    u8 r;
    u8 g;
    u8 b;

    type = 0;

    g = 0;
    b = 0;
    r = 0;

    t = 0;
    phi_s2 = 20;

    switch (D_8014C6F0) {
        case 1:
            type = 0;
            break;
        case 3:
            r = g = b = 208;
            type = 1;
            phi_s2 = 10;
            if (gGameStatusPtr->demoState == 2) {
                gGameStatusPtr->nextDemoScene = 18;
            }
            break;
        case 6:
            r = g = b = 208;
        case 0:
            type = 1;
            break;
        case 7:
            if (gGameStatusPtr->demoState == 2) {
                gGameStatusPtr->nextDemoScene = 18;
            }
        case 11:
        case 15:
            r = g = b = 208;
        case 4:
        case 5:
            type = 1;
            phi_s2 = 7;
            break;
        case 14:
            r = g = b = 208;
        case 2:
            type = 1;
            phi_s2 = 50;
            break;
        case 8:
            set_screen_overlay_alpha(0, 0.0f);
            type = 4;
            break;
        case 9:
            r = g = b = 208;
        case 10:
            set_screen_overlay_alpha(0, 0.0f);
            type = 4;
            phi_s2 = 7;
            break;
        case 12:
            set_screen_overlay_alpha(0, 160.0f);
            r = g = b = 208;
            type = 5;
            phi_s2 = 7;
            break;
        case 13:
            set_screen_overlay_alpha(0, 0.0f);
            type = 5;
            phi_s2 = 7;
            break;
        case 16:
            set_screen_overlay_center(0, 0, 15, 28);
            set_screen_overlay_center(0, 1, 305, 156);
            set_screen_overlay_params_front(12, 255.0f);
            *progress = 0xFF;
            return 1;
    }

    if (D_8014C6F0 == 5) {
        overlayColor = ((255 - *progress) * 208) / 255;
        set_screen_overlay_color(0, overlayColor, overlayColor, overlayColor);
        set_screen_overlay_params_front(type, 255.0f);
        if (*progress == 0xFF) {
            return 1;
        }

        *progress += phi_s2;
        if (*progress > 0xFF) {
            *progress = 0xFF;
        }
    } else {
        set_screen_overlay_color(t, r, g, b);

        if (t == 0) {
            set_screen_overlay_params_front(type, *progress);
        } else {
            set_screen_overlay_params_back(type, *progress);
        }

        if (*progress == 0xFF) {
            return 1;
        }

        *progress += phi_s2;
        if (*progress > 0xFF) {
            *progress = 0xFF;
        }
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "cd180_len_38f0", update_exit_map_screen_overlay);
#endif

u8 update_enter_map_screen_overlay(s16* progress) {
    u8 frontType = 0;
    s32 amt = 20;
    u8 ret = FALSE;

    switch (D_8014C6F0) {
        case 3:
            set_screen_overlay_color(0, 208, 208, 208);
            amt = 50;
            break;
        case 2:
            frontType = 1;
            amt = 50;
            break;
        case 4:
        case 5:
        case 7:
        case 9:
        case 10:
            frontType = 1;
            amt = 7;
            break;
        case 0:
        case 1:
        case 6:
        case 13:
        case 14:
            frontType = 1;
            break;
        case 8:
        case 15:
            frontType = 4;
            break;
        case 11:
            frontType = 5;
            amt = 7;
            break;
        case 12:
            frontType = 4;
            amt = 7;
            break;
        case 16:
            set_screen_overlay_center(0, 0, 15, 28);
            set_screen_overlay_center(0, 1, 305, 156);
            set_screen_overlay_params_front(12, *progress);
            amt = 2;
            break;
    }

    if (D_8014C6F0 != 0x10) {
        set_screen_overlay_params_front(frontType, *progress);
    }

    if (*progress == 0) {
        ret = TRUE;
    }

    *progress -= amt;

    if (*progress < 0) {
        *progress = 0;
    }

    return ret;
}
