#include "common.h"
#include "ld_addrs.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"

void appendGfx_intro_logos();

// bss?
extern s8* D_800A0910;

void state_init_logos(void) {
    s8* romStart;
    s8* romEnd;
    s32* logoRam;
    s32* temp_800A0910;

    general_heap_create();
    gGameStatusPtr->introState = INTRO_STATE_0;
    gGameStatusPtr->introCounter = 0;
    gGameStatusPtr->bSkipIntro = FALSE;
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(0);

    romEnd = logos_ROM_END;
    romStart = logos_ROM_START;
    logoRam = heap_malloc(romEnd - romStart);

    temp_800A0910 = &D_800A0910;
    D_800A0910 = logoRam;

    dma_copy(romStart, romEnd, logoRam);

    // TODO probably this is not ideal
    D_800A0918 = D_800A0910 + 0x0;
    D_800A0914 = D_800A0910 + 0x7000;
    D_800A091C = D_800A0910 + 0x15000;

    nuContRmbForceStop();
    create_cameras_a();
    gCameras[CAM_DEFAULT].updateMode = 6;
    gCameras[CAM_DEFAULT].unk_06 = 1;
    gCameras[CAM_DEFAULT].nearClip = 0x10;
    gCameras[CAM_DEFAULT].farClip = 0x1000;
    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_DEFAULT].vfov = 25.0f;
    gCameras[CAM_DEFAULT].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_BATTLE].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_TATTLE].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_CAM3].flags |= CAM_FLAG_ENABLED;
    set_cam_viewport(0, 12, 28, 296, 184);
    gCameras[CAM_DEFAULT].unk_1E = 0x28;
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    gCameras[CAM_DEFAULT].unk_54 = 25.0f;
    gCameras[CAM_DEFAULT].unk_58 = 25.0f;
    gCameras[CAM_DEFAULT].unk_1C = 0;
    gCameras[CAM_DEFAULT].unk_20 = 100;
    gCameras[CAM_DEFAULT].unk_22 = 0;
    gCameras[CAM_DEFAULT].lookAt_eye.x = 500.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.y = 1000.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.z = 1500.0f;
    gCameras[CAM_DEFAULT].unk_5C = 150.0f;
    clear_script_list();
    clear_generic_entity_list();
    clear_render_tasks();
    spr_init_sprites(0);
    clear_animator_list();
    clear_entity_models();
    clear_npcs();
    hud_element_clear_cache();
    reset_background_settings();
    clear_entity_data(1);
    clear_effect_data();
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
    intro_logos_update_fade();
    gGameStatusPtr->backgroundFlags = FALSE;
}

void state_step_logos(void) {
    if (gGameStatusPtr->bSkipIntro) {
        if (intro_logos_fade_out(0xA) != 0) {
            set_curtain_scale(1.0f);
            set_curtain_fade(0.0f);
            set_game_mode(GAME_MODE_TITLE_SCREEN);
        }
    } else {
        switch (gGameStatusPtr->introState) {
            case INTRO_STATE_1:
                if (gGameStatusPtr->introCounter == 0) {
                    intro_logos_set_fade_color(208);
                    gGameStatusPtr->introState++;
                }
                gGameStatusPtr->introCounter--;
                break;
            case INTRO_STATE_2:
                if (intro_logos_fade_out(0xA)) {
                    gGameStatusPtr->introState++;
                }
                break;
            case INTRO_STATE_3:
                if (intro_logos_fade_in(0xA)) {
                    gGameStatusPtr->introState++;
                    gGameStatusPtr->introCounter = 40;
                }
                break;
            case INTRO_STATE_4:
                if (gGameStatusPtr->introCounter == 0) {
                    gGameStatusPtr->introState++;
                    intro_logos_set_fade_color(208);
                }
                gGameStatusPtr->introCounter--;
                break;
            case INTRO_STATE_5:
                if (intro_logos_fade_out(0xA)) {
                    gGameStatusPtr->introState++;
                }
                break;
            case INTRO_STATE_0:
            case INTRO_STATE_6:
                if (intro_logos_fade_in(0xA)) {
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
                if (intro_logos_fade_out(0xA) != 0) {
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
                heap_free(D_800A0910);
                D_800A0910 = 0;

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

// all sorts of issues, but I think it's mostly with D_800A0918, 1C, and 14. Those need better types so they can have
// proper array accesses. the display list macros should mostly be good
#ifdef NON_EQUIVALENT
void appendGfx_intro_logos(void) {
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
    gDPSetFillColor(gMasterGfxPos++, 0xE739E739);
    gDPFillRectangle(gMasterGfxPos++, 0, 0, 319, 239);
    gDPPipeSync(gMasterGfxPos++);

    switch (gGameStatusPtr->loadMenuState) {
        case 0:
        case 1:
        case 2:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 7; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, D_800A0918 + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 508, 60);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 508, 60);
                gSPTextureRectangle(gMasterGfxPos++, 384, 256 + i * 64, 896, 320 + i * 64, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        case 3:
        case 4:
        case 5:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 6; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, D_800A091C + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 1020, 28);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 1020, 28);
                gSPTextureRectangle(gMasterGfxPos++, 128, 356 + i * 32, 1152, 388 + i * 32, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 14; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, D_800A0914[i] + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 1020, 28);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 1020, 28);
                gSPTextureRectangle(gMasterGfxPos++, 128, 236 + i * 32, 1152, 268 + i * 32, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
    }
}
#else
INCLUDE_ASM(void, "state_logos", appendGfx_intro_logos);
#endif
