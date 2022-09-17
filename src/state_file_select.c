#include "common.h"
#include "ld_addrs.h"
#include "nu/nusys.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"

s32 D_80077980[] = { &D_8038F800, &D_803B5000, &heap_battleHead, };

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

u8 D_800779B0 = 0;

extern s32 D_80200000;

void state_init_language_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_FULL);
    set_screen_overlay_params_front(0, D_800A0932[0]);
}

void state_init_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_FULL);
    general_heap_create();
    hud_element_set_aux_cache(0, 0);
    hud_element_clear_cache();
    load_model_textures(0, 0, 0);
    gCameras[CAM_DEFAULT].updateMode = 6;
    gCameras[CAM_DEFAULT].unk_06 = 1;
    gCameras[CAM_DEFAULT].nearClip = 16;
    gCameras[CAM_DEFAULT].farClip = 4096;
    gCameras[CAM_DEFAULT].flags |= CAM_FLAG_ENABLED;
    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_BATTLE].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_TATTLE].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_3].flags |= CAM_FLAG_ENABLED;
    gCameras[CAM_DEFAULT].vfov = 25.0f;
    set_cam_viewport(0, 12, 28, 296, 184);
    gCameras[CAM_DEFAULT].auxBoomLength = 40;
    gCameras[CAM_DEFAULT].lookAt_eye.x = 500.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.y = 1000.0f;
    gCameras[CAM_DEFAULT].lookAt_eye.z = 1500.0f;
    gCameras[CAM_DEFAULT].auxPos.z = 150.0f;
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    gCameras[CAM_DEFAULT].auxPos.x = 25.0f;
    gCameras[CAM_DEFAULT].auxPos.y = 25.0f;
    gCameras[CAM_DEFAULT].unk_1C = 0;
    gCameras[CAM_DEFAULT].unk_20 = 100;
    gCameras[CAM_DEFAULT].auxBoomPitch = 0;
    gOverrideFlags |= GLOBAL_OVERRIDES_WINDOWS_IN_FRONT_OF_CURTAINS;
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
                set_screen_overlay_params_front(0, D_800A0932[0]);
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
            gOverrideFlags |= GLOBAL_OVERRIDES_8;
            break;
        case 2:
            D_800A0930--;
            if (D_800A0930 == 0) {
                nuGfxSetCfb(D_80077980, 2);
                if (nuGfxCfb[2] == nuGfxCfb_ptr) {
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                } else {
                    gOverrideFlags |= GLOBAL_OVERRIDES_8;
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
                    spr_init_sprites(0);
                    clear_model_data();
                    clear_sprite_shading_data();
                    reset_background_settings();
                    clear_entity_models();
                    clear_animator_list();
                    clear_generic_entity_list();
                    hud_element_set_aux_cache(&D_80200000, 0x20000);
                    hud_element_clear_cache();
                    reset_status_menu();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(0);
                    clear_trigger_data();
                    nuPiReadRomOverlay(&D_8007798C);
                    filemenu_init(TRUE);
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                    set_screen_overlay_params_front(255, 255.0f);
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
            set_screen_overlay_params_front(0, D_800A0932[0]);
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
                    filemenu_init(FALSE);
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
        set_screen_overlay_params_front(0, D_800A0932[0]);
    } else {
        D_800A0931 = 1;
        set_screen_overlay_params_front(0, D_800A0932[0]);
    }
    D_800A0930 = 1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
}

void state_init_exit_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    D_800A0930 = 0;

    if (func_80244BC4() == 0) {
        set_map_transition_effect(7);
    } else {
        set_map_transition_effect(8);
        gOverrideFlags &= ~GLOBAL_OVERRIDES_WINDOWS_IN_FRONT_OF_CURTAINS;
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
                set_screen_overlay_params_front(0, D_800A0932[0]);
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
                set_screen_overlay_params_front(0U, D_800A0932[0]);
                if (D_800A0932[0] == 255) {
                    D_800A0931 = 2;
                }
            } else {
                D_800A0931 = 2;
            }
            break;
        case 2:
            if (D_800A0930 == 3) {
                gOverrideFlags |= GLOBAL_OVERRIDES_8;
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
                    nuGfxSetCfb(D_80077980, ARRAY_COUNT(D_80077980));
                    filemenu_cleanup();
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
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
                    init_generic_entity_list();
                    hud_element_set_aux_cache(0, 0);
                    init_hud_element_list();
                    init_item_entity_list();
                    init_script_list();
                    init_npc_list();
                    init_entity_data();
                    init_trigger_list();
                    mapShape = load_asset_by_name(&wMapShapeName, &mapShapeSize);
                    decode_yay0(mapShape, &D_80210000);
                    general_heap_free(mapShape);
                    initialize_collision();
                    restore_map_collision_data();

                    if (mapConfig->dmaStart != NULL) {
                        dma_copy(mapConfig->dmaStart, mapConfig->dmaEnd, mapConfig->dmaDest);
                    }

                    load_map_bg(mapConfig->bgName);

                    bgHeader = mapSettings->background;
                    if (bgHeader != NULL) {
                        read_background_size(bgHeader);
                    } else {
                        set_background_size(296, 200, 12, 20);
                    }

                    calculate_model_sizes();
                    npc_reload_all();
                    func_800E98C4();
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
                set_screen_overlay_params_front(0, D_800A0932[0]);
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
                set_screen_overlay_params_front(0, D_800A0932[0]);
            }
            break;
        case 4:
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            update_player();
            update_npcs();
            update_encounters();
            update_effects();
            enable_player_input();
            set_game_mode(GAME_MODE_CHANGE_MAP);
            set_screen_overlay_params_front(255, -1.0f);
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

                if (window->parent == 44 || window->parent == -1) {
                    flagSum += window->flags & WINDOW_FLAGS_INITIAL_ANIMATION;
                }
            }

            if (flagSum == 0) {
                D_800A0931 = 1;
            }
            break;
        case 1:
            if (temp_s0 == 0 || (update_exit_map_screen_overlay(D_800A0932) << 0x10) != 0) {
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
                gOverrideFlags &= ~GLOBAL_OVERRIDES_WINDOWS_IN_FRONT_OF_CURTAINS;
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
            set_game_mode(GAME_MODE_WORLD);
            break;
    }
}

void state_drawUI_exit_language_select(void) {
}

void state_drawUI_exit_file_select(void) {
}
