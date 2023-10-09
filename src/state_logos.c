#include "common.h"
#include "ld_addrs.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"
#include "nu/nusys.h"
#include "game_modes.h"

void appendGfx_intro_logos(void);

#if VERSION_JP
#define LOGO_1_Y 54
#define LOGO_2_Y 104
#define N64_FADE_IN_TIME 30
#else
#define LOGO_1_Y 89
#define LOGO_2_Y 59
#define N64_FADE_IN_TIME 40
#endif

enum LogoStates {
    LOGOS_STATE_N64_FADE_IN         = 0x00000000,
    LOGOS_STATE_N64_HOLD            = 0x00000001,
    LOGOS_STATE_N64_FADE_OUT        = 0x00000002,
    LOGOS_STATE_NINTENDO_FADE_IN    = 0x00000003,
    LOGOS_STATE_NINTENDO_HOLD       = 0x00000004,
    LOGOS_STATE_NINTENDO_FADE_OUT   = 0x00000005,
    LOGOS_STATE_IS_FADE_IN          = 0x00000006,
    LOGOS_STATE_IS_HOLD_1           = 0x00000007,
    LOGOS_STATE_IS_HOLD_2           = 0x00000008,
    LOGOS_STATE_IS_FADE_OUT         = 0x00000009,
    LOGOS_STATE_CURTAINS_APPEAR     = 0x0000000A,
    LOGOS_STATE_CLEANUP             = 0x0000000B,
};

s32 D_800778C0[] = { 0, 0 };

Gfx D_800778C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

Gfx D_80077908[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

SHIFT_BSS u8* gLogosImages;
SHIFT_BSS u8* gLogosImage3;
SHIFT_BSS u8* gLogosImage1;
SHIFT_BSS u8* gLogosImage2;

void state_init_logos(void) {
    s8* romStart;
    s8* romEnd;

    general_heap_create();
    gGameStatusPtr->startupState = LOGOS_STATE_N64_FADE_IN;
    gGameStatusPtr->logoTime = 0;
    gGameStatusPtr->skipLogos = FALSE;
    startup_set_fade_screen_alpha(255);
    startup_set_fade_screen_color(0);

    romEnd = logos_ROM_END;
    romStart = logos_ROM_START;
    gLogosImages = heap_malloc(romEnd - romStart);
    dma_copy(romStart, romEnd, gLogosImages);

    gLogosImage1 = gLogosImages + 0x0;
    gLogosImage3 = gLogosImages + 0x7000;
    gLogosImage2 = gLogosImages + 0x15000;

    nuContRmbForceStop();
    create_cameras_a();
    gCameras[CAM_DEFAULT].updateMode = CAM_UPDATE_MODE_6;
    gCameras[CAM_DEFAULT].needsInit = TRUE;
    gCameras[CAM_DEFAULT].nearClip = 16;
    gCameras[CAM_DEFAULT].farClip = 4096;
    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_DEFAULT].vfov = 25.0f;
    gCameras[CAM_DEFAULT].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_BATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_TATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_3].flags |= CAMERA_FLAG_DISABLED;
    set_cam_viewport(CAM_DEFAULT, 12, 28, 296, 184);
    gCameras[CAM_DEFAULT].auxBoomLength = 40;
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    gCameras[CAM_DEFAULT].lookAt_obj_target.x = 25.0f;
    gCameras[CAM_DEFAULT].lookAt_obj_target.y = 25.0f;
    gCameras[CAM_DEFAULT].auxPitch = 0;
    gCameras[CAM_DEFAULT].lookAt_dist = 100;
    gCameras[CAM_DEFAULT].auxBoomPitch = 0;
    gCameras[CAM_DEFAULT].lookAt_eye.x = 500.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.y = 1000.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.z = 1500.0f;
    gCameras[CAM_DEFAULT].lookAt_obj_target.z = 150.0f;
    clear_script_list();
    clear_worker_list();
    clear_render_tasks();
    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
    clear_animator_list();
    clear_entity_models();
    clear_npcs();
    hud_element_clear_cache();
    reset_background_settings();
    clear_entity_data(TRUE);
    clear_effect_data();
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
    startup_fade_screen_update();
    gGameStatusPtr->backgroundFlags = 0;
}

void state_step_logos(void) {
#if VERSION_JP
    int pressedButtons = gGameStatusPtr->pressedButtons[0];
#endif

    if (gGameStatusPtr->skipLogos) {
        if (startup_fade_screen_out(10)) {
            set_curtain_scale(1.0f);
            set_curtain_fade(0.0f);
            set_game_mode(GAME_MODE_TITLE_SCREEN);
        }
    } else {
#if VERSION_JP
        if ((gGameStatusPtr->startupState == LOGOS_STATE_N64_HOLD
            || gGameStatusPtr->startupState == LOGOS_STATE_N64_FADE_OUT
            || gGameStatusPtr->startupState == LOGOS_STATE_NINTENDO_FADE_IN
            || gGameStatusPtr->startupState == LOGOS_STATE_NINTENDO_HOLD
            || gGameStatusPtr->startupState == LOGOS_STATE_NINTENDO_FADE_OUT
            || gGameStatusPtr->startupState == LOGOS_STATE_IS_FADE_IN
            || gGameStatusPtr->startupState == LOGOS_STATE_IS_HOLD_1
            || gGameStatusPtr->startupState == LOGOS_STATE_IS_HOLD_2
            || gGameStatusPtr->startupState == LOGOS_STATE_IS_FADE_OUT
            || gGameStatusPtr->startupState == LOGOS_STATE_CURTAINS_APPEAR)
            && (pressedButtons & (BUTTON_START | BUTTON_Z | BUTTON_A))
        ) {
            startup_set_fade_screen_color(208);
            gGameStatusPtr->skipLogos = TRUE;
        }
#endif

        switch (gGameStatusPtr->startupState) {
            case LOGOS_STATE_N64_FADE_IN:
                if (startup_fade_screen_in(10)) {
                    gGameStatusPtr->startupState++;
                    gGameStatusPtr->logoTime = 30;
                }
                break;
            case LOGOS_STATE_N64_HOLD:
                if (gGameStatusPtr->logoTime == 0) {
                    startup_set_fade_screen_color(208);
                    gGameStatusPtr->startupState++;
                }
                gGameStatusPtr->logoTime--;
                break;
            case LOGOS_STATE_N64_FADE_OUT:
                if (startup_fade_screen_out(10)) {
                    gGameStatusPtr->startupState++;
#if VERSION_JP
                    gGameStatusPtr->startupState += 2;
#endif
                }
                break;
            case LOGOS_STATE_NINTENDO_FADE_IN:
                if (startup_fade_screen_in(10)) {
                    gGameStatusPtr->startupState++;
                    gGameStatusPtr->logoTime = N64_FADE_IN_TIME;
                }
                break;
            case LOGOS_STATE_NINTENDO_HOLD:
                if (gGameStatusPtr->logoTime == 0) {
                    gGameStatusPtr->startupState++;
#if VERSION_JP
                    startup_set_fade_screen_color(0);
#else
                    startup_set_fade_screen_color(208);
#endif
                }
                gGameStatusPtr->logoTime--;
                break;
            case LOGOS_STATE_NINTENDO_FADE_OUT:
                if (startup_fade_screen_out(10)) {
                    gGameStatusPtr->startupState++;
                }
                break;
            case LOGOS_STATE_IS_FADE_IN:
                if (startup_fade_screen_in(10)) {
                    gGameStatusPtr->startupState++;
                    gGameStatusPtr->logoTime = 30;
                }
                break;
            case LOGOS_STATE_IS_HOLD_1:
                if (gGameStatusPtr->logoTime == 0) {
                    gGameStatusPtr->startupState++;
                    startup_set_fade_screen_color(208);
                    gGameStatusPtr->logoTime = 30;
                }
                gGameStatusPtr->logoTime--;
                break;
            case LOGOS_STATE_IS_HOLD_2:
                if (gGameStatusPtr->logoTime == 0) {
                    gGameStatusPtr->startupState++;
                    set_curtain_scale_goal(1.0f);
                    set_curtain_draw_callback(NULL);
                    set_curtain_fade_goal(0.3f);
                } else {
                    gGameStatusPtr->logoTime--;
                }
                break;
            case LOGOS_STATE_IS_FADE_OUT:
                if (startup_fade_screen_out(10)) {
                    gGameStatusPtr->logoTime = 15;
                    gGameStatusPtr->startupState++;
                }
                break;
            case LOGOS_STATE_CURTAINS_APPEAR:
                if (gGameStatusPtr->logoTime == 0) {
                    gGameStatusPtr->startupState++;
                } else {
                    gGameStatusPtr->logoTime--;
                }
                break;
            case LOGOS_STATE_CLEANUP:
                heap_free(gLogosImages);
                gLogosImages = NULL;
                startup_set_fade_screen_alpha(255);
                gGameStatusPtr->introPart = INTRO_PART_0;
                set_game_mode(GAME_MODE_INTRO);
                break;
        }
    }
    update_npcs();
    update_cameras();
    startup_fade_screen_update();
}

void state_drawUI_logos(void) {
    appendGfx_intro_logos();
}

void appendGfx_intro_logos(void) {
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
    gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(224, 224, 224, 1));
    gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gDPPipeSync(gMainGfxPos++);

    switch (gGameStatusPtr->startupState) {
        case LOGOS_STATE_N64_FADE_IN:
        case LOGOS_STATE_N64_HOLD:
        case LOGOS_STATE_N64_FADE_OUT:
            gSPDisplayList(gMainGfxPos++, D_80077908);
            for (i = 0; i < 7; i++) {
                gDPLoadTextureTile(gMainGfxPos++, gLogosImage1 + i * 0x1000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 112,
                                   0, 0, 127, 15, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gMainGfxPos++, 96 * 4, (64 + i * 16) * 4, 224 * 4, (80 + i * 16) * 4, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMainGfxPos++);
            }
            break;
        case LOGOS_STATE_NINTENDO_FADE_IN:
        case LOGOS_STATE_NINTENDO_HOLD:
        case LOGOS_STATE_NINTENDO_FADE_OUT:
#if VERSION_JP
            break;
        case LOGOS_STATE_IS_FADE_IN:
        case LOGOS_STATE_IS_HOLD_1:
        case LOGOS_STATE_IS_HOLD_2:
        case LOGOS_STATE_IS_FADE_OUT:
#endif
            gSPDisplayList(gMainGfxPos++, D_80077908);
            for (i = 0; i < 6; i++) {
                gDPLoadTextureTile(gMainGfxPos++, gLogosImage2 + i * 0x1000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 48,
                                   0, 0, 255, 7, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(
                        gMainGfxPos++,
                        32 * 4, (LOGO_1_Y + i * 8) * 4,
                        288 * 4, (LOGO_1_Y + 8 + i * 8) * 4,
                        G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMainGfxPos++);
            }
#if !VERSION_JP
            break;
        case LOGOS_STATE_IS_FADE_IN:
        case LOGOS_STATE_IS_HOLD_1:
        case LOGOS_STATE_IS_HOLD_2:
        case LOGOS_STATE_IS_FADE_OUT:
            gSPDisplayList(gMainGfxPos++, D_80077908);
#endif
            for (i = 0; i < 14; i++) {
                gDPLoadTextureTile(gMainGfxPos++, gLogosImage3 + i * 0x1000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 112,
                                   0, 0, 255, 7, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gMainGfxPos++,
                                    32 * 4, (LOGO_2_Y + i * 8) * 4,
                                    288 * 4, (LOGO_2_Y + 8 + i * 8) * 4,
                                    G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMainGfxPos++);
            }
            break;
    }
}
