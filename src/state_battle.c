#include "common.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "ld_addrs.h"
#include "sprite.h"
#include "battle/battle.h"
#include "model.h"
#include "game_modes.h"

extern u16 gFrameBuf0[];
extern u16 gFrameBuf1[];
extern u16 gFrameBuf2[];

u16* bFrameBuffers[] = {
    gFrameBuf0, gFrameBuf1, gFrameBuf2
};

s32 D_800778AC[] = {
    0x00000000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000
};

SHIFT_BSS s8 D_800A0900;
SHIFT_BSS s32 D_800A0904;
SHIFT_BSS s32 D_800A0908;

#ifdef SHIFT
#define shim_battle_heap_create_obfuscated battle_heap_create
#endif

extern ShapeFile gMapShapeData;

void state_init_battle(void) {
    D_800A0900 = 5;
}

void state_step_battle(void) {
    u32 currentBattleSelection;
    u32 currentBattleIndex;

    if (D_800A0900 == 5) {
        if (nuGfxCfb[1] != nuGfxCfb_ptr) {
            return;
        }
        D_800A0900--;
        gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
        nuContRmbForceStop();
    }

    if (D_800A0900 >= 0) {
        if (D_800A0900 > 0) {
            D_800A0900--;
            return;
        }

        D_800A0900 = -1;
        nuGfxSetCfb(bFrameBuffers, 2);
        nuContRmbForceStopEnd();
        sfx_stop_env_sounds();
        func_8003B1A8();
        gGameStatusPtr->isBattle = TRUE;
        backup_map_collision_data();

#if VERSION_IQUE
        battle_heap_create();
#else
        load_obfuscation_shims();
        shim_battle_heap_create_obfuscated();
#endif

        sfx_clear_env_sounds(0);

        currentBattleSelection = UNPACK_BTL_AREA(gCurrentBattleID);
        currentBattleIndex = UNPACK_BTL_INDEX(gCurrentBattleID);

        if (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH ||
            (currentBattleSelection == BTL_AREA_KKJ && currentBattleIndex == 0)) {
            gGameStatusPtr->peachFlags |= PEACH_FLAG_IS_PEACH;
            spr_init_sprites(PLAYER_SPRITES_PEACH_BATTLE);
        } else {
            spr_init_sprites(PLAYER_SPRITES_MARIO_BATTLE);
        }

        clear_model_data();
        clear_sprite_shading_data();
        reset_background_settings();
        clear_entity_models();
        clear_animator_list();
        clear_worker_list();
        hud_element_set_aux_cache(NULL, 0);
        hud_element_clear_cache();
        reset_status_bar();
        clear_item_entity_data();
        clear_script_list();
        clear_npcs();
        clear_entity_data(TRUE);
        clear_trigger_data();
        DMA_COPY_SEGMENT(battle_code);
        initialize_battle();
        btl_save_world_cameras();
        load_battle_section();
        D_800A0904 = gPlayerStatusPtr->animFlags;
        gPlayerStatusPtr->animFlags &= ~PA_FLAG_PULSE_STONE_VISIBLE;
        D_800A0908 = get_time_freeze_mode();
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;

        if (D_800A0900 >= 0) {
            return;
        }
    }

    update_encounters();
    btl_update();
    update_npcs();
    update_item_entities();
    update_effects();
    iterate_models();
    update_cameras();
}

void state_drawUI_battle(void) {
    draw_encounter_ui();
    if (D_800A0900 < 0) {
        btl_draw_ui();
    }
}

void state_init_end_battle(void) {
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
    nuContRmbForceStop();
    D_800A0900 = 5;
}

void state_step_end_battle(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    MapSettings* mapSettings;
    MapConfig* mapConfig;

    if (D_800A0900 >= 0) {
        D_800A0900--;
        if (D_800A0900 == 0) {
            D_800A0900 = -1;
            nuGfxSetCfb(bFrameBuffers, 3);
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            nuContRmbForceStopEnd();
            sfx_stop_env_sounds();
            mapSettings = get_current_map_settings();
            mapConfig = &gAreas[gGameStatusPtr->areaID].maps[gGameStatusPtr->mapID];
            btl_restore_world_cameras();
            gGameStatusPtr->isBattle = FALSE;
            func_8005AF84();
            func_8002ACDC();
            sfx_clear_env_sounds(1);
            gGameStatusPtr->peachFlags &= ~PEACH_FLAG_IS_PEACH;
            battle_heap_create();
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

            if (gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED) {
                npc_reload_all();
                playerStatus->animFlags = D_800A0904;
                set_game_mode(GAME_MODE_DEMO);
            } else {
                void* mapShape;
                u32 sizeTemp;

                partner_init_after_battle(playerData->curPartner);
                load_map_script_lib();
                mapShape = load_asset_by_name(wMapShapeName, &sizeTemp);
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

                mdl_load_all_textures(mapSettings->modelTreeRoot, get_asset_offset(wMapTexName, &sizeTemp), sizeTemp);
                mdl_calculate_model_sizes();
                npc_reload_all();

                playerStatus->animFlags = D_800A0904;
                if (D_800A0908 != 0) {
                    set_time_freeze_mode(D_800A0908);
                }
                set_game_mode(GAME_MODE_WORLD);
            }
        }
    }
}

void state_drawUI_end_battle(void) {
}
