#include "common.h"
#include "ld_addrs.h"
#include "npc.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "sprite.h"
#include "model.h"
#include "game_modes.h"

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

SHIFT_BSS s8 StepPauseDelay;
SHIFT_BSS s8 StepPauseState;
SHIFT_BSS s16 StepPauseAlpha; // effectively unused, always zero
SHIFT_BSS s32 SavedReverbMode;

void state_init_pause(void) {
    StepPauseState = 0;
    StepPauseAlpha = 0;
    disable_player_input();
    set_time_freeze_mode(TIME_FREEZE_POPUP_MENU);
    set_windows_visible(WINDOW_GROUP_PAUSE_MENU);
}

extern Addr D_80200000;

void state_step_pause(void) {
    switch (StepPauseState) {
        case 0:
            update_encounters();
            update_npcs();
            update_player();
            update_effects();
            if (nuGfxCfb[1] == nuGfxCfb_ptr) {
                StepPauseDelay = 4;
                StepPauseState = 2;
                gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
                gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_BEGIN_PAUSED;

            }
            break;
        case 2:
            if (StepPauseDelay >= 0) {
                if (StepPauseDelay != 0) {
                    StepPauseDelay--;
                }

                if (StepPauseDelay == 0) {
                    StepPauseDelay = -1;
                    nuGfxSetCfb(pause_frameBuffers, 2);
                    gGameStatusPtr->savedBackgroundDarkness = gGameStatusPtr->backgroundDarkness;
                    sfx_stop_env_sounds();
                    func_8003B1A8();
                    gGameStatusPtr->isBattle = 2;
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
                    reset_status_bar();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(FALSE);
                    clear_trigger_data();
                    SavedReverbMode = sfx_get_reverb_mode();
                    sfx_set_reverb_mode(0);
                    bgm_quiet_max_volume();
                    nuPiReadRomOverlay(&D_8007795C);
                    pause_init();
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                }

                if (StepPauseDelay >= 0) {
                    break;
                }
            }

            if (StepPauseDelay >= -10) {
                pause_handle_input(0, 0);
                StepPauseDelay--;
            } else {
                pause_handle_input(gGameStatusPtr->pressedButtons[0], gGameStatusPtr->heldButtons[0]);
            }
            StepPauseAlpha = 0;
            break;
    }
}

void state_drawUI_pause(void) {
}

void state_init_unpause(void) {
    if (StepPauseAlpha > 0) {
        StepPauseState = 0;
    } else {
        StepPauseState = 1;
    }
    StepPauseDelay = 4;
}

void state_step_unpause(void) {
    MapSettings* mapSettings;
    MapConfig* mapConfig;
    void* mapShape;
    s32 assetSize;
    
    switch (StepPauseState) {
        case 0:
        case 1:
            if (StepPauseDelay == 4) {
                gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            }

            if (StepPauseDelay >= 0) {
                if (StepPauseDelay != 0) {
                    StepPauseDelay--;
                }

                if (StepPauseDelay == 0) {
                    StepPauseDelay = -1;
                    nuGfxSetCfb(pause_frameBuffers, ARRAY_COUNT(pause_frameBuffers));
                    pause_cleanup();
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
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
                        set_background(mapSettings->background);
                    } else {
                        set_background_size(296, 200, 12, 20);
                    }

                    gGameStatusPtr->backgroundDarkness = gGameStatusPtr->savedBackgroundDarkness;
                    mdl_calculate_model_sizes();
                    npc_reload_all();
                    set_windows_visible(WINDOW_GROUP_ALL);
                    status_bar_respond_to_changes();
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                    StepPauseState = 3;
                    gPlayerStatus.prevAlpha = gPlayerStatus.curAlpha - 1;
                    D_802D9D71 = D_802D9D70 + 1;

                    update_encounters();
                    update_npcs();
                    update_player();
                    update_effects();

                    StepPauseAlpha -= 20;
                    if (StepPauseAlpha < 0) {
                        StepPauseAlpha = 0;
                    }
                }
            }
            break;
        case 3:
            update_encounters();
            update_npcs();
            update_player();
            update_effects();

            if (StepPauseAlpha == 0) {
                StepPauseState = 4;
            } else {
                StepPauseAlpha -= 20;
                if (StepPauseAlpha < 0) {
                    StepPauseAlpha = 0;
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
            set_game_mode(GAME_MODE_WORLD);
            break;
    }
}

void state_drawUI_unpause(void) {
}
