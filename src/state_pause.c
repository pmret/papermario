#include "common.h"
#include "ld_addrs.h"
#include "map.h"
#include "nu/nusys.h"

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

// probably a file split
static s32 padding[] = {0, 0};

s32 D_80077950[] = { 0x8038F800, 0x803B5000, &D_803DA800 };

// TODO the gPauseMenuIconScripts should be DATA_START
// TODO the gPauseMenuHeldButtons should be BSS_START
// TODO 80278640 is BSS_END
NUPiOverlaySegment D_8007795C = {
    .romStart = pause_ROM_START,
    .romEnd = pause_ROM_END,
    .ramStart = pause_VRAM,
    .textStart = pause_VRAM,
    .textEnd = gPauseMenuIconScripts,
    .dataStart = gPauseMenuIconScripts,
    .dataEnd = &gPauseMenuHeldButtons,
    .bssStart = &gPauseMenuHeldButtons,
    .bssEnd = 0x80278640
};

void state_init_pause(void) {
    D_800A0921 = 0;
    D_800A0922 = 0;
    disable_player_input();
    set_time_freeze_mode(3);
    set_windows_visible(2);
}

void state_step_pause(void) {
    s32 oldIsBattle = D_800A0921;

    switch (D_800A0921) {
        case 0:
            update_encounters();
            update_npcs();
            update_player();
            update_effects();
            if (D_8009A658[1] == D_8009A64C) {
                D_800A0920 = 4;
                D_800A0921 = 2;
                gOverrideFlags |= 0x8;
                gGameStatusPtr->enableBackground &= ~0xF0;
                gGameStatusPtr->enableBackground |= 0x10;

            }
            break;
        case 2:
            if (D_800A0920 >= 0) {
                if (D_800A0920 != 0) {
                    (D_800A0920)--;
                }

                if (D_800A0920 == 0) {
                    D_800A0920 = -1;
                    nuGfxSetCfb(&D_80077950, 2);
                    gGameStatusPtr->unk_15E = gGameStatusPtr->unk_15C;
                    sfx_stop_env_sounds();
                    func_8003B1A8();
                    gGameStatusPtr->isBattle = oldIsBattle;
                    allocate_hit_tables();
                    battle_heap_create();
                    nuContRmbForceStop();
                    sfx_clear_env_sounds(0);
                    spr_init_sprites(0);
                    clear_model_data();
                    clear_sprite_shading_data();
                    reset_background_settings();
                    clear_entity_models();
                    clear_animator_list();
                    clear_generic_entity_list();
                    set_hud_element_nonworld_cache(_3169F0_VRAM, 0x38000);
                    clear_hud_element_cache();
                    reset_status_menu();
                    clear_item_entity_data();
                    clear_script_list();
                    clear_npcs();
                    clear_entity_data(0);
                    clear_trigger_data();
                    D_800A0924 = func_80149828();
                    func_801497FC(0);
                    bgm_quiet_max_volume();
                    nuPiReadRomOverlay(&D_8007795C);
                    pause_init();
                    gOverrideFlags &= ~0x8;
                }

                if (D_800A0920 >= 0) {
                    break;
                }
            }

            if (D_800A0920 >= -10) {
                pause_handle_input(0, 0);
                D_800A0920--;
            } else {
                pause_handle_input(gGameStatusPtr->pressedButtons, gGameStatusPtr->heldButtons);
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
                gOverrideFlags |= 0x8;
            }

            if (D_800A0920 >= 0) {
                if (D_800A0920 != 0) {
                    D_800A0920--;
                }

                if (D_800A0920 == 0) {
                    if (D_800A0920 == 0) {
                        MapConfig* mapConfig;
                        Map* map;
                        s32 assetData;
                        s32 assetSize;

                        D_800A0920 = -1;
                        nuGfxSetCfb(&D_80077950, ARRAY_COUNT(D_80077950));
                        pause_cleanup();
                        gOverrideFlags &= ~0x8;
                        mapConfig = get_current_map_header();
                        map = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
                        gGameStatusPtr->isBattle = FALSE;
                        gGameStatusPtr->enableBackground &= ~0xF0;
                        func_8005AF84();
                        func_8002ACDC();
                        nuContRmbForceStopEnd();
                        sfx_clear_env_sounds(1);
                        spr_init_sprites(gGameStatusPtr->playerSpriteSet);
                        init_model_data();
                        init_sprite_shading_data();
                        init_entity_models();
                        reset_animator_list();
                        init_generic_entity_list();
                        set_hud_element_nonworld_cache(0, 0);
                        init_hud_element_list();
                        init_item_entity_list();
                        init_script_list();
                        init_npc_list();
                        func_80110E58();
                        init_trigger_list();
                        func_801497FC(D_800A0924);
                        bgm_reset_max_volume();
                        load_map_script_lib();
                        assetData = load_asset_by_name(&D_800D9230, &assetSize);
                        decode_yay0(assetData, &D_80210000);
                        general_heap_free(assetData);
                        initialize_collision();
                        load_collision();

                        if (map->dmaStart != NULL) {
                            dma_copy(map->dmaStart, map->dmaEnd, map->dmaDest);
                        }

                        load_map_bg(map->bgName);
                        if (mapConfig->background != NULL) {
                            read_background_size(mapConfig->background);
                        } else {
                            set_background_size(296, 200, 12, 20);
                        }

                        gGameStatusPtr->unk_15C = gGameStatusPtr->unk_15E;
                        calculate_model_sizes();
                        npc_reload_all();
                        set_windows_visible(0);
                        func_800E98C4();
                        set_time_freeze_mode(1);
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
            set_time_freeze_mode(0);
            update_encounters();
            update_npcs();
            update_player();
            update_effects();
            enable_player_input();
            set_game_mode(4);
            break;
    }
}

void state_drawUI_unpause(void) {
}
