#include "common.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "ld_addrs.h"
#include "sprite.h"

s32 D_800778A0[] = {
    &D_8038F800, &D_803B5000, &heap_battleHead,
};

s32 D_800778AC[] = {
    0x00000000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000
};

// BSS
extern s32 D_800A0904;
extern s32 D_800A0908;

void state_init_battle(void) {
    D_800A0900 = 5;
}

void state_step_battle(void) {
    u32 currentBattleSelection;
    u32 temp;

    if (D_800A0900 == 5) {
        if (nuGfxCfb[1] != nuGfxCfb_ptr) {
            return;
        }
        D_800A0900--;
        gOverrideFlags |= GLOBAL_OVERRIDES_8;
        nuContRmbForceStop();
    }

    if (D_800A0900 >= 0) {
        if (D_800A0900 > 0) {
            D_800A0900--;
            return;
        } else {
            D_800A0900 = -1;
            nuGfxSetCfb(&D_800778A0, 2);
            nuContRmbForceStopEnd();
            sfx_stop_env_sounds();
            func_8003B1A8();
            gGameStatusPtr->isBattle = TRUE;
            backup_map_collision_data();
            func_8002D160();
            func_802B20B4();
            sfx_clear_env_sounds(0);

            currentBattleSelection = gCurrentBattleSection;
            temp = D_800DC4EB;

            if (gGameStatusPtr->peachFlags & 1 || (currentBattleSelection == 0x26 && temp == 0)) {
                gGameStatusPtr->peachFlags |= 1;
                spr_init_sprites(6);
            } else {
                spr_init_sprites(5);
            }

            clear_model_data();
            clear_sprite_shading_data();
            reset_background_settings();
            clear_entity_models();
            clear_animator_list();
            clear_generic_entity_list();
            hud_element_set_aux_cache(NULL, 0);
            hud_element_clear_cache();
            reset_status_menu();
            clear_item_entity_data();
            clear_script_list();
            clear_npcs();
            clear_entity_data(1);
            clear_trigger_data();
            dma_copy(&_16C8E0_ROM_START, &_16C8E0_ROM_END, &_16C8E0_VRAM);
            initialize_battle();
            btl_save_world_cameras();
            load_battle_section();
            D_800A0904 = gPlayerStatusPtr->animFlags;
            gPlayerStatusPtr->animFlags &= ~PA_FLAGS_40;
            D_800A0908 = get_time_freeze_mode();
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_8;

            if (D_800A0900 >= 0) {
                return;
            }
        }
    }

    update_encounters();
    btl_update();
    update_npcs();
    update_item_entities();
    update_effects();
    func_80116674();
    update_cameras();
}

void state_drawUI_battle(void) {
    draw_encounter_ui();
    if (D_800A0900 < 0) {
        btl_draw_ui();
    }
}

void state_init_end_battle(void) {
    gOverrideFlags |= GLOBAL_OVERRIDES_8;
    nuContRmbForceStop();
    D_800A0900 = 5;
}

void state_step_end_battle(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (D_800A0900 >= 0) {
        D_800A0900--;
        if (D_800A0900 == 0) {
            MapSettings* mapSettings;
            MapConfig* mapConfig;

            D_800A0900 = -1;
            nuGfxSetCfb(D_800778A0, 3);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
            nuContRmbForceStopEnd();
            sfx_stop_env_sounds();
            mapSettings = get_current_map_settings();
            mapConfig = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
            btl_restore_world_cameras(gGameStatusPtr);
            gGameStatusPtr->isBattle = FALSE;
            func_8005AF84();
            func_8002ACDC();
            sfx_clear_env_sounds(1);
            gGameStatusPtr->peachFlags &= ~0x1;
            battle_heap_create();
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

            if (gGameStatusPtr->demoFlags & 1) {
                npc_reload_all();
                playerStatus->animFlags = D_800A0904;
                set_game_mode(GAME_MODE_DEMO);
            } else {
                void* mapShape;
                u32 sizeTemp;

                partner_init_after_battle(playerData->currentPartner);
                load_map_script_lib();
                mapShape = load_asset_by_name(&wMapShapeName, &sizeTemp);
                decode_yay0(mapShape, &D_80210000);
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

                load_model_textures(mapSettings->modelTreeRoot, get_asset_offset(&wMapTexName, &sizeTemp), sizeTemp);
                calculate_model_sizes();
                npc_reload_all();

                playerStatus->animFlags = D_800A0904;
                if (D_800A0908 != 0) {
                    set_time_freeze_mode(D_800A0908);
                }
                set_game_mode(GAME_MODE_CHANGE_MAP);
            }
        }
    }
}

void state_drawUI_end_battle(void) {
}
