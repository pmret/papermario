#include "common.h"
#include "ld_addrs.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"
#include "nu/nusys.h"

void appendGfx_intro_logos(void);

#if VERSION_JP
#define LOGO_1_Y 54
#define LOGO_2_Y 104
#else
#define LOGO_1_Y 89
#define LOGO_2_Y 59
#endif


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

// BSS
extern u8* gLogosImages;
extern u8* gLogosImage3;
extern u8* gLogosImage1;
extern u8* gLogosImage2;

void state_init_logos(void) {
    s8* romStart;
    s8* romEnd;

    general_heap_create();
    gGameStatusPtr->introState = INTRO_STATE_0;
    gGameStatusPtr->introCounter = 0;
    gGameStatusPtr->bSkipIntro = FALSE;
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(0);

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
    gCameras[CAM_DEFAULT].unk_06 = TRUE;
    gCameras[CAM_DEFAULT].nearClip = 16;
    gCameras[CAM_DEFAULT].farClip = 4096;
    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_DEFAULT].vfov = 25.0f;
    gCameras[CAM_DEFAULT].flags |= CAMERA_FLAG_ENABLED;
    gCameras[CAM_BATTLE].flags |= CAMERA_FLAG_ENABLED;
    gCameras[CAM_TATTLE].flags |= CAMERA_FLAG_ENABLED;
    gCameras[CAM_3].flags |= CAMERA_FLAG_ENABLED;
    set_cam_viewport(0, 12, 28, 296, 184);
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
    clear_entity_data(1);
    clear_effect_data();
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
    intro_logos_update_fade();
    gGameStatusPtr->backgroundFlags = 0;
}

void state_step_logos(void) {
#if VERSION_JP
    int pressedButtons = gGameStatusPtr->pressedButtons[0];
#endif

    if (gGameStatusPtr->bSkipIntro) {
        if (intro_logos_fade_out(10)) {
            set_curtain_scale(1.0f);
            set_curtain_fade(0.0f);
            set_game_mode(GAME_MODE_TITLE_SCREEN);
        }
    } else {
#if VERSION_JP
        if ((gGameStatusPtr->introState == INTRO_STATE_1 ||
             gGameStatusPtr->introState == INTRO_STATE_2 ||
             gGameStatusPtr->introState == INTRO_STATE_3 ||
             gGameStatusPtr->introState == INTRO_STATE_4 ||
             gGameStatusPtr->introState == INTRO_STATE_5 ||
             gGameStatusPtr->introState == INTRO_STATE_6 ||
             gGameStatusPtr->introState == INTRO_STATE_7 ||
             gGameStatusPtr->introState == INTRO_STATE_8 ||
             gGameStatusPtr->introState == INTRO_STATE_9 ||
             gGameStatusPtr->introState == INTRO_STATE_A) &&
            (pressedButtons & (BUTTON_START | BUTTON_Z | BUTTON_A)))
        {
            intro_logos_set_fade_color(208);
            gGameStatusPtr->bSkipIntro = 1;
        }
#endif

        switch (gGameStatusPtr->introState) {
            case INTRO_STATE_0:
                if (intro_logos_fade_in(10)) {
                    gGameStatusPtr->introState++;
                    gGameStatusPtr->introCounter = 30;
                }
                break;
            case INTRO_STATE_1:
                if (gGameStatusPtr->introCounter == 0) {
                    intro_logos_set_fade_color(208);
                    gGameStatusPtr->introState++;
                }
                gGameStatusPtr->introCounter--;
                break;
            case INTRO_STATE_2:
                if (intro_logos_fade_out(10)) {
                    gGameStatusPtr->introState++;
#if VERSION_JP
                    gGameStatusPtr->introState += 2;
#endif
                }
                break;
            case INTRO_STATE_3:
                if (intro_logos_fade_in(10)) {
                    gGameStatusPtr->introState++;
#if VERSION_JP
                    gGameStatusPtr->introCounter = 30;
#else
                    gGameStatusPtr->introCounter = 40;
#endif
                }
                break;
            case INTRO_STATE_4:
                if (gGameStatusPtr->introCounter == 0) {
                    gGameStatusPtr->introState++;
#if VERSION_JP
                    intro_logos_set_fade_color(0);
#else
                    intro_logos_set_fade_color(208);
#endif
                }
                gGameStatusPtr->introCounter--;
                break;
            case INTRO_STATE_5:
                if (intro_logos_fade_out(10)) {
                    gGameStatusPtr->introState++;
                }
                break;
            case INTRO_STATE_6:
                if (intro_logos_fade_in(10)) {
                    gGameStatusPtr->introState++;
                    gGameStatusPtr->introCounter = 30;
                }
                break;
            case INTRO_STATE_7:
                if (gGameStatusPtr->introCounter == 0) {
                    gGameStatusPtr->introState++;
                    intro_logos_set_fade_color(208);
                    gGameStatusPtr->introCounter = 30;
                }
                gGameStatusPtr->introCounter--;
                break;
            case INTRO_STATE_8:
                if (gGameStatusPtr->introCounter == 0) {
                    gGameStatusPtr->introState++;
                    set_curtain_scale_goal(1.0f);
                    set_curtain_draw_callback(NULL);
                    set_curtain_fade_goal(0.3f);
                } else {
                    gGameStatusPtr->introCounter--;
                }
                break;
            case INTRO_STATE_9:
                if (intro_logos_fade_out(10)) {
                    gGameStatusPtr->introCounter = 15;
                    gGameStatusPtr->introState++;
                }
                break;
            case INTRO_STATE_A:
                if (gGameStatusPtr->introCounter == 0) {
                    gGameStatusPtr->introState++;
                } else {
                    gGameStatusPtr->introCounter--;
                }
                break;
            case INTRO_STATE_B:
                heap_free(gLogosImages);
                gLogosImages = NULL;
                intro_logos_set_fade_alpha(255);
                gGameStatusPtr->creditsViewportMode = 0;
                set_game_mode(GAME_MODE_INTRO);
                break;
        }
    }
    update_npcs();
    update_cameras();
    intro_logos_update_fade();
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

    switch (gGameStatusPtr->introState) {
        case INTRO_STATE_0:
        case INTRO_STATE_1:
        case INTRO_STATE_2:
            gSPDisplayList(gMainGfxPos++, D_80077908);
            for (i = 0; i < 7; i++) {
                gDPLoadTextureTile(gMainGfxPos++, gLogosImage1 + i * 0x1000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 112,
                                   0, 0, 127, 15, 0,
                                   G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gMainGfxPos++, 96 * 4, (64 + i * 16) * 4, 224 * 4, (80 + i * 16) * 4, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMainGfxPos++);
            }
            break;
        case INTRO_STATE_3:
        case INTRO_STATE_4:
        case INTRO_STATE_5:
#if VERSION_JP
            break;
        case INTRO_STATE_6:
        case INTRO_STATE_7:
        case INTRO_STATE_8:
        case INTRO_STATE_9:
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
        case INTRO_STATE_6:
        case INTRO_STATE_7:
        case INTRO_STATE_8:
        case INTRO_STATE_9:
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
