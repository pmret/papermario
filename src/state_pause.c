#include "common.h"
#include "ld_addrs.h"
#include "npc.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "sprite.h"
#include "model.h"

#if VERSION_JP
// TODO: split this segment
extern Addr pause_ROM_START;
extern Addr pause_ROM_END;
extern Addr pause_VRAM;
extern Addr pause_TEXT_START;
extern Addr pause_TEXT_END;
extern Addr pause_RODATA_END;
extern Addr pause_BSS_START;
extern Addr pause_BSS_END;
extern Addr pause_DATA_START;
#endif

extern u16 gFrameBuf0[];
extern u16 gFrameBuf1[];
extern u16 gFrameBuf2[];
u16* pause_frameBuffers[] = { gFrameBuf0, gFrameBuf1, gFrameBuf2 };

extern ShapeFile gMapShapeData;

NUPiOverlaySegment D_8007795C = {
    .romStart = pause_ROM_START,
    .romEnd = pause_ROM_END,
    .ramStart = pause_VRAM,
    .textStart = pause_TEXT_START,
    .textEnd = pause_TEXT_END,
    .dataStart = pause_DATA_START,
    .dataEnd = pause_RODATA_END,
    .bssStart = pause_BSS_START,
    .bssEnd = pause_BSS_END,
};

void state_init_pause(void) {
    D_800A0921 = 0;
    D_800A0922 = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_POPUP_MENU);
    set_windows_visible(WINDOW_GROUP_PAUSE_MENU);
}

extern Addr D_80200000;

void state_step_pause(void) {
    s32 oldIsBattle = D_800A0921;

    switch (D_800A0921) {
        case 0:
            update_encounters();
            update_npcs();
            update_player();
            update_effects();
            if (nuGfxCfb[1] == nuGfxCfb_ptr) {
                D_800A0920 = 4;
                D_800A0921 = 2;
                gOverrideFlags |= GLOBAL_OVERRIDES_8;
                gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
                gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_1;

            }
            break;
        case 2:
            if (D_800A0920 >= 0) {
                if (D_800A0920 != 0) {
                    (D_800A0920)--;
                }

                if (D_800A0920 == 0) {
                    D_800A0920 = -1;
                    nuGfxSetCfb(pause_frameBuffers, 2);
                    gGameStatusPtr->savedBackgroundDarkness = gGameStatusPtr->backgroundDarkness;
                    sfx_stop_env_sounds();
                    func_8003B1A8();
                    gGameStatusPtr->isBattle = oldIsBattle;
                    backup_map_collision_data();
                    battle_heap_create();
                    nuContRmbForceStop();
                    sfx_clear_env_sounds(0);
                    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
                    clear_model_data();
                    clear_sprite_shading_data();
                    reset_background_settings();
                    clear_entity_models();
                    clear_animator_list();
                    clear_worker_list();
                    hud_element_set_aux_cache(D_80200000, 0x38000); // TODO shiftability (what should this symbol be?)
                    hud_element_clear_cache();
                    reset_status_menu();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(0);
                    clear_trigger_data();
                    SavedReverbMode = sfx_get_reverb_mode();
                    sfx_set_reverb_mode(0);
                    bgm_quiet_max_volume();
                    nuPiReadRomOverlay(&D_8007795C);
                    pause_init();
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                }

                if (D_800A0920 >= 0) {
                    break;
                }
            }

            if (D_800A0920 >= -10) {
                pause_handle_input(0, 0);
                D_800A0920--;
            } else {
                pause_handle_input(gGameStatusPtr->pressedButtons[0], gGameStatusPtr->heldButtons[0]);
            }
            D_800A0922 = 0;
            break;
    }
}

void state_drawUI_pause(void) {
}

void state_init_unpause(void) {
    if (D_800A0922 > 0) {
        D_800A0921 = 0;
    } else {
        D_800A0921 = 1;
    }
    D_800A0920 = 4;
}

void state_step_unpause(void) {
    switch (D_800A0921) {
        case 0:
        case 1:
            if (D_800A0920 == 4) {
                gOverrideFlags |= GLOBAL_OVERRIDES_8;
            }

            if (D_800A0920 >= 0) {
                if (D_800A0920 != 0) {
                    D_800A0920--;
                }

                if (D_800A0920 == 0) {
                    if (D_800A0920 == 0) {
                        MapSettings* mapSettings;
                        MapConfig* mapConfig;
                        void* mapShape;
                        s32 assetSize;

                        D_800A0920 = -1;
                        nuGfxSetCfb(pause_frameBuffers, ARRAY_COUNT(pause_frameBuffers));
                        pause_cleanup();
                        gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                        mapSettings = get_current_map_settings();
                        mapConfig = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
                        gGameStatusPtr->isBattle = FALSE;
                        gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
                        func_8005AF84();
                        func_8002ACDC();
                        nuContRmbForceStopEnd();
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
                        sfx_set_reverb_mode(SavedReverbMode);
                        bgm_reset_max_volume();
                        load_map_script_lib();
                        mapShape = load_asset_by_name(wMapShapeName, &assetSize);
                        decode_yay0(mapShape, &gMapShapeData);
                        general_heap_free(mapShape);
                        initialize_collision();
                        restore_map_collision_data();

                        if (mapConfig->dmaStart != NULL) {
                            dma_copy(mapConfig->dmaStart, mapConfig->dmaEnd, mapConfig->dmaDest);
                        }

                        load_map_bg(mapConfig->bgName);
                        if (mapSettings->background != NULL) {
                            read_background_size(mapSettings->background);
                        } else {
                            set_background_size(296, 200, 12, 20);
                        }

                        gGameStatusPtr->backgroundDarkness = gGameStatusPtr->savedBackgroundDarkness;
                        calculate_model_sizes();
                        npc_reload_all();
                        set_windows_visible(WINDOW_GROUP_ALL);
                        status_menu_respond_to_changes();
                        set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                        D_800A0921 = 3;
                        gPlayerStatus.alpha2 = gPlayerStatus.alpha1 - 1;
                        D_802D9D71 = D_802D9D70 + 1;

                        update_encounters();
                        update_npcs();
                        update_player();
                        update_effects();

                        D_800A0922 -= 20;
                        if (D_800A0922 < 0) {
                            D_800A0922 = 0;
                        }
                    }
                }
            }
            break;
        case 3:
            update_encounters();
            update_npcs();
            update_player();
            update_effects();

            if (D_800A0922 == 0) {
                D_800A0921 = 4;
            } else {
                D_800A0922 -= 20;
                if (D_800A0922 < 0) {
                    D_800A0922 = 0;
                }
            }
            break;
        case 4:
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            update_encounters();
            update_npcs();
            update_player();
            update_effects();
            enable_player_input();
            set_game_mode(GAME_MODE_CHANGE_MAP);
            break;
    }
}

void state_drawUI_unpause(void) {
}
