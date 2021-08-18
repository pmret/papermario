#include "common.h"
#include "ld_addrs.h"
#include "nu/nusys.h"
#include "camera.h"

s32 D_80077980[] = { &D_8038F800, &D_803B5000, &D_803DA800, };

NUPiOverlaySegment D_8007798C = {
    .romStart = _163400_ROM_START,
    .romEnd = _163400_ROM_END,
    .ramStart = _163400_VRAM,
    .textStart = _163400_TEXT_START,
    .textEnd = _163400_TEXT_END,
    .dataStart = _163400_DATA_START,
    .dataEnd = _163400_DATA_END,
    .bssStart = _163400_BSS_START,
    .bssEnd = _163400_BSS_END,
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
    set_hud_element_nonworld_cache(0, 0);
    clear_hud_element_cache();
    load_model_textures(0, 0, 0);
    gCameras[0].mode = 6;
    gCameras[0].unk_06 = 1;
    gCameras[0].nearClip = 16;
    gCameras[0].farClip = 4096;
    gCameras[0].flags |= CAM_FLAG_ENABLED;
    gCurrentCameraID = 0;
    gCameras[1].flags |= CAM_FLAG_ENABLED;
    gCameras[2].flags |= CAM_FLAG_ENABLED;
    gCameras[3].flags |= CAM_FLAG_ENABLED;
    gCameras[0].vfov = 25.0f;
    set_cam_viewport(0, 12, 28, 296, 184);
    gCameras[0].unk_1E = 40;
    gCameras[0].lookAt_eye.x = 500.0f;
    gCameras[0].lookAt_eye.y = 1000.0f;
    gCameras[0].lookAt_eye.z = 1500.0f;
    gCameras[0].unk_5C = 150.0f;
    gCameras[0].bgColor[0] = 0;
    gCameras[0].bgColor[1] = 0;
    gCameras[0].bgColor[2] = 0;
    gCameras[0].unk_54 = 25.0f;
    gCameras[0].unk_58 = 25.0f;
    gCameras[0].unk_1C = 0;
    gCameras[0].unk_20 = 100;
    gCameras[0].unk_22 = 0;
    gOverrideFlags |= 0x10000;
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
            gOverrideFlags |= 8;
            break;
        case 2:
            D_800A0930--;
            if (D_800A0930 == 0) {
                nuGfxSetCfb(D_80077980, 2);
                if (nuGfxCfb[2] == nuGfxCfb_ptr) {
                    gOverrideFlags &= ~0x8;
                } else {
                    gOverrideFlags |= 8;
                    set_windows_visible(3);
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
                    allocate_hit_tables();
                    battle_heap_create();
                    sfx_clear_env_sounds(0);
                    spr_init_sprites(0);
                    clear_model_data();
                    clear_sprite_shading_data();
                    reset_background_settings();
                    clear_entity_models();
                    clear_animator_list();
                    clear_generic_entity_list();
                    set_hud_element_nonworld_cache(&D_80200000, 0x20000);
                    clear_hud_element_cache();
                    reset_status_menu();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(0);
                    clear_trigger_data();
                    nuPiReadRomOverlay(&D_8007798C);
                    filemenu_init(1);
                    gOverrideFlags &= ~0x8;
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
            set_windows_visible(3);
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
        set_screen_overlay_params_front(0, D_800A0932[0]);
    } else {
        D_800A0931 = 1;
        set_screen_overlay_params_front(0, D_800A0932[0]);
    }
    D_800A0930 = 1;
    gOverrideFlags &= ~0x40;
}

void state_init_exit_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    D_800A0930 = 0;

    if (func_80244BC4() == 0) {
        set_map_transition_effect(7);
    } else {
        set_map_transition_effect(8);
        gOverrideFlags &= ~0x0010000;
        bgm_set_song(0, -1, 0, 1000, 8);
    }
    gOverrideFlags &= ~0x40;
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
                gOverrideFlags |= 8;
            }

            if (D_800A0930 >= 0) {
                D_800A0930--;
                if (D_800A0930 == 0) {
                    MapConfig* mapConfig;
                    Map* map;
                    u32 mapShapeSize;
                    void* mapShape;
                    BackgroundHeader* bgHeader;

                    D_800A0930 = -1;
                    nuGfxSetCfb(D_80077980, ARRAY_COUNT(D_80077980));
                    filemenu_cleanup();
                    gOverrideFlags &= ~0x8;
                    mapConfig = get_current_map_header();
                    map = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
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
                    set_hud_element_nonworld_cache(0, 0);
                    init_hudElements();
                    init_item_entity_list();
                    init_script_list();
                    init_npc_list();
                    func_80110E58();
                    init_trigger_list();
                    mapShape = load_asset_by_name(&wMapShapeName, &mapShapeSize);
                    decode_yay0(mapShape, &D_80210000);
                    general_heap_free(mapShape);
                    initialize_collision();
                    load_collision();

                    if (map->dmaStart != NULL) {
                        dma_copy(map->dmaStart, map->dmaEnd, map->dmaDest);
                    }

                    load_map_bg(map->bgName);

                    bgHeader = mapConfig->background;
                    if (bgHeader != NULL) {
                        read_background_size(bgHeader);
                    } else {
                        set_background_size(296, 200, 12, 20);
                    }

                    calculate_model_sizes();
                    npc_reload_all();
                    func_800E98C4();
                    set_time_freeze_mode(1);
                }
                set_windows_visible(0);
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
            set_time_freeze_mode(0);
            update_player();
            update_npcs();
            update_encounters();
            update_effects();
            enable_player_input();
            set_game_mode(4);
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

            for (i = 44; i < ARRAY_COUNT(gUIPanels); i++) {
                UIPanel* panel = &gUIPanels[i];

                if (panel->parent == 44 || panel->parent == -1) {
                    flagSum += panel->flags & 8;
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
            set_windows_visible(FALSE);
            D_800A0931 = 3;
        case 3:
            set_time_freeze_mode(0);
            if (temp_s0 == 0) {
                set_game_mode(2);
                gOverrideFlags &= ~0x10000;
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
            set_game_mode(7);
            break;
    }
}

void state_drawUI_exit_language_select(void) {
}

void state_drawUI_exit_file_select(void) {
}
