#include "common.h"
#include "ld_addrs.h"
#include "nu/nusys.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"
#include "model.h"
#include "game_modes.h"

#if VERSION_JP
// TODO: split the filemenu segment
extern Addr filemenu_ROM_START;
extern Addr filemenu_ROM_END;
extern Addr filemenu_VRAM;
extern Addr filemenu_TEXT_START;
extern Addr filemenu_TEXT_END;
extern Addr filemenu_DATA_START;
extern Addr filemenu_RODATA_END;
extern Addr filemenu_BSS_START;
extern Addr filemenu_BSS_END;
#endif

extern u16 gFrameBuf0[];
extern u16 gFrameBuf1[];
extern u16 gFrameBuf2[];
u16* fsFrameBuffers[] = { gFrameBuf0, gFrameBuf1, gFrameBuf2 };

NUPiOverlaySegment D_8007798C = {
    .romStart = filemenu_ROM_START,
    .romEnd = filemenu_ROM_END,
    .ramStart = filemenu_VRAM,
    .textStart = filemenu_TEXT_START,
    .textEnd = filemenu_TEXT_END,
    .dataStart = filemenu_DATA_START,
    .dataEnd = filemenu_RODATA_END,
    .bssStart = filemenu_BSS_START,
    .bssEnd = filemenu_BSS_END,
};

u8 IntroMessageIdx = 0;

extern s32 D_80200000;
extern ShapeFile gMapShapeData;

SHIFT_BSS s8 D_800A0930;
SHIFT_BSS s8 D_800A0931;
SHIFT_BSS s16 D_800A0932[1];

void state_init_language_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_FULL);
    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
}

void state_init_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_FULL);
    general_heap_create();
    hud_element_set_aux_cache(0, 0);
    hud_element_clear_cache();
    mdl_load_all_textures(NULL, 0, 0);
    gCameras[CAM_DEFAULT].updateMode = CAM_UPDATE_MODE_6;
    gCameras[CAM_DEFAULT].needsInit = TRUE;
    gCameras[CAM_DEFAULT].nearClip = 16;
    gCameras[CAM_DEFAULT].farClip = 4096;
    gCameras[CAM_DEFAULT].flags |= CAMERA_FLAG_DISABLED;
    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_BATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_TATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_3].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_DEFAULT].vfov = 25.0f;
    set_cam_viewport(CAM_DEFAULT, 12, 28, 296, 184);
    gCameras[CAM_DEFAULT].auxBoomLength = 40;
    gCameras[CAM_DEFAULT].lookAt_eye.x = 500.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.y = 1000.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.z = 1500.0f;
    gCameras[CAM_DEFAULT].lookAt_obj_target.z = 150.0f;
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    gCameras[CAM_DEFAULT].lookAt_obj_target.x = 25.0f;
    gCameras[CAM_DEFAULT].lookAt_obj_target.y = 25.0f;
    gCameras[CAM_DEFAULT].auxPitch = 0;
    gCameras[CAM_DEFAULT].lookAt_dist = 100;
    gCameras[CAM_DEFAULT].auxBoomPitch = 0;
    gOverrideFlags |= GLOBAL_OVERRIDES_WINDOWS_OVER_CURTAINS;
}

void state_step_language_select(void) {
    switch (D_800A0931) {
        case 0:
            update_player();
            update_npcs();
            update_encounters();
            update_effects();

            if (D_800A0932[0] < 255) {
                D_800A0932[0] += 20;

                if (D_800A0932[0] > 255) {
                    D_800A0932[0] = 255;
                }
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
                if (D_800A0932[0] == 255) {

                    D_800A0931 = 1;
                }
            } else {
                D_800A0931 = 1;
            }
            break;
        case 1:
            D_800A0930 = 5;
            D_800A0931 = 2;
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            break;
        case 2:
            D_800A0930--;
            if (D_800A0930 == 0) {
                nuGfxSetCfb(fsFrameBuffers, 2);
                if (nuGfxCfb[2] == nuGfxCfb_ptr) {
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                } else {
                    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                    set_windows_visible(WINDOW_GROUP_FILE_MENU);
                    D_800A0930 = 1;
                    D_800A0931 = 3;
                }
            }
            break;
        case 3:
            if (D_800A0930 >= 0) {
                D_800A0930--;
                if (D_800A0930 == 0) {
                    D_800A0930 = -1;
                    sfx_stop_env_sounds();
                    func_8003B1A8();
                    gGameStatusPtr->isBattle = 2;
                    backup_map_collision_data();
                    battle_heap_create();
                    sfx_clear_env_sounds(0);
                    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
                    clear_model_data();
                    clear_sprite_shading_data();
                    reset_background_settings();
                    clear_entity_models();
                    clear_animator_list();
                    clear_worker_list();
                    hud_element_set_aux_cache(&D_80200000, 0x20000);
                    hud_element_clear_cache();
                    reset_status_bar();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(FALSE);
                    clear_trigger_data();
                    nuPiReadRomOverlay(&D_8007798C);
                    filemenu_init(1);
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                    set_screen_overlay_params_front(OVERLAY_NONE, 255.0f);
                }
                if (D_800A0930 >= 0) {
                    break;
                }
            }

            filemenu_update();
            D_800A0932[0] -= 20;
            if (D_800A0932[0] < 0) {
                D_800A0932[0] = 0;
            }
            set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
            break;
    }
}

void state_step_file_select(void) {
    s32 temp = D_800A0931; // needed to match

    switch (D_800A0931) {
        case 1:
            set_windows_visible(WINDOW_GROUP_FILE_MENU);
            D_800A0930 = temp;
            D_800A0931 = 2;
            break;
        case 0:
            D_800A0931 = 1;
            break;
        case 2:
            if (D_800A0930 >= 0) {
                D_800A0930--;
                temp = D_800A0930;
                if (temp == 0) {
                    D_800A0930 = -1;
                    battle_heap_create();
                    nuPiReadRomOverlay(&D_8007798C);
                    filemenu_init(0);
                }
            }

            if (D_800A0930 < 0) {
                filemenu_update();
            }
            break;
    }
}

void state_drawUI_language_select(void) {
}

void state_drawUI_file_select(void) {
}

void state_init_exit_language_select(void) {
    if (D_800A0932[0] > 0) {
        D_800A0931 = 0;
        set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
    } else {
        D_800A0931 = 1;
        set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
    }
    D_800A0930 = 1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
}

void state_init_exit_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    D_800A0930 = 0;

    if (func_80244BC4() == 0) {
        set_map_transition_effect(TRANSITION_SLOW_FADE_TO_WHITE);
    } else {
        set_map_transition_effect(TRANSITION_ENTER_WORLD);
        gOverrideFlags &= ~GLOBAL_OVERRIDES_WINDOWS_OVER_CURTAINS;
        bgm_set_song(0, -1, 0, 1000, 8);
    }
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
}

void state_step_exit_language_select(void) {
    switch (D_800A0931) {
        case 0:
            if (D_800A0932[0] != 0) {
                D_800A0932[0] -= 20;
                if (D_800A0932[0] < 0) {
                    D_800A0932[0] = 0;
                }
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
                if (D_800A0932[0] == 0) {
                    D_800A0931 = 1;
                }
            } else {
                D_800A0931 = 1;
            }
            break;
        case 1:
            if (D_800A0932[0] != 255) {
                D_800A0932[0] += 20;
                if (D_800A0932[0] > 255) {
                    D_800A0932[0] = 255;
                }
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
                if (D_800A0932[0] == 255) {
                    D_800A0931 = 2;
                }
            } else {
                D_800A0931 = 2;
            }
            break;
        case 2:
            if (D_800A0930 == 3) {
                gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            }

            if (D_800A0930 >= 0) {
                D_800A0930--;
                if (D_800A0930 == 0) {
                    MapSettings* mapSettings;
                    MapConfig* mapConfig;
                    u32 mapShapeSize;
                    void* mapShape;
                    BackgroundHeader* bgHeader;

                    D_800A0930 = -1;
                    nuGfxSetCfb(fsFrameBuffers, ARRAY_COUNT(fsFrameBuffers));
                    filemenu_cleanup();
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                    mapSettings = get_current_map_settings();
                    mapConfig = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
                    gGameStatusPtr->isBattle = FALSE;
                    func_8005AF84();
                    func_8002ACDC();
                    sfx_clear_env_sounds(1);
                    spr_init_sprites(gGameStatusPtr->playerSpriteSet);
                    init_model_data();
                    init_sprite_shading_data();
                    init_entity_models();
                    reset_animator_list();
                    init_worker_list();
                    hud_element_set_aux_cache(0, 0);
                    init_hud_element_list();
                    init_item_entity_list();
                    init_script_list();
                    init_npc_list();
                    init_entity_data();
                    init_trigger_list();
                    mapShape = load_asset_by_name(wMapShapeName, &mapShapeSize);
                    decode_yay0(mapShape, &gMapShapeData);
                    general_heap_free(mapShape);
                    initialize_collision();
                    restore_map_collision_data();

                    if (mapConfig->dmaStart != NULL) {
                        dma_copy(mapConfig->dmaStart, mapConfig->dmaEnd, mapConfig->dmaDest);
                    }

                    load_map_bg(mapConfig->bgName);

                    bgHeader = mapSettings->background;
                    if (bgHeader != NULL) {
                        set_background(bgHeader);
                    } else {
                        set_background_size(296, 200, 12, 20);
                    }

                    mdl_calculate_model_sizes();
                    npc_reload_all();
                    status_bar_respond_to_changes();
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                }
                set_windows_visible(WINDOW_GROUP_ALL);
                D_800A0931 = 3;
                update_player();
                update_npcs();
                update_encounters();
                update_effects();

                D_800A0932[0] -= 20;
                if (D_800A0932[0] < 0) {
                    D_800A0932[0] = 0;
                }
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
            }
            break;
        case 3:
            update_player();
            update_npcs();
            update_encounters();
            update_effects();

            if (D_800A0932[0] == 0) {
                D_800A0931 = 4;
            } else {
                D_800A0932[0] -= 20;
                if (D_800A0932[0] < 0) {
                    D_800A0932[0] = 0;
                }
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_800A0932[0]);
            }
            break;
        case 4:
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            update_player();
            update_npcs();
            update_encounters();
            update_effects();
            enable_player_input();
            set_game_mode(GAME_MODE_WORLD);
            set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
            break;
        }
}

void state_step_exit_file_select(void) {
    s32 temp_s0 = func_80244BC4();
    s32 flagSum;
    s32 i;

    switch (D_800A0931) {
        case 0:
            flagSum = 0;

            for (i = 44; i < ARRAY_COUNT(gWindows); i++) {
                Window* window = &gWindows[i];

                if (window->parent == WINDOW_ID_FILEMENU_MAIN || window->parent == -1) {
                    flagSum += window->flags & WINDOW_FLAG_INITIAL_ANIMATION;
                }
            }

            if (flagSum == 0) {
                D_800A0931 = 1;
            }
            break;
        case 1:
            if (temp_s0 == 0 || update_exit_map_screen_overlay(D_800A0932) != 0) {
                D_800A0931 = 2;
            }
            break;
        case 2:
            filemenu_cleanup();
            set_windows_visible(WINDOW_GROUP_ALL);
            D_800A0931 = 3;
        case 3:
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            if (temp_s0 == 0) {
                set_game_mode(GAME_MODE_TITLE_SCREEN);
                gOverrideFlags &= ~GLOBAL_OVERRIDES_WINDOWS_OVER_CURTAINS;
            } else {
                D_800A0930 = 10;
                D_800A0931 = 4;
            }
            break;
        case 4:
            if (D_800A0930 > 0) {
                D_800A0930--;
            } else {
                set_curtain_scale_goal(2.0f);
                D_800A0930 = 10;
                D_800A0931 = 5;
            }
            break;
        case 5:
            if (D_800A0930 > 0) {
                D_800A0930--;
            } else {
                D_800A0931 = 6;
            }
            break;
        case 6:
            set_game_mode(GAME_MODE_ENTER_WORLD);
            break;
    }
}

void state_drawUI_exit_language_select(void) {
}

void state_drawUI_exit_file_select(void) {
}
