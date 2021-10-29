#include "common.h"
#include "hud_element.h"
#include "sprite.h"

extern s32 D_800A0950;

void state_init_intro(void) {
    s8 unk_A8;

    gGameStatusPtr->loadMenuState = 0;

    set_curtain_scale_goal(1.0f);
    set_curtain_fade_goal(0.3f);

    unk_A8 = gGameStatusPtr->creditsViewportMode;
    switch (unk_A8) {
        case 0:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0xFF;
            D_800A0956 = 0x10;
            D_800A0958 = 4;
            D_800A0960 = 0;
            D_800A095A = 0xD0;
            D_800A095C = 0xD0;
            D_800A095E = 0xD0;
            D_800A0964 = 0;

            // hos_05 (Star Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 5;
            gGameStatusPtr->entryID = 3;
            break;
        case 1:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0;
            D_800A0956 = 0xC;
            D_800A0958 = 4;
            D_800A0960 = unk_A8;
            D_800A095A = 0;
            D_800A095C = 0;
            D_800A095E = 0;
            D_800A0964 = 0;

            // hos_04 (Outside the Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 4;
            gGameStatusPtr->entryID = 4;
            break;
        default:
            intro_logos_set_fade_alpha(0);
            intro_logos_set_fade_color(208);

            gGameStatusPtr->creditsViewportMode = -1;

            D_800A0956 = 6;
            D_800A0958 = 6;

            D_800779B0++;
            if (D_800779B0 >= 4) {
                D_800779B0 = 0;
            }

            D_800A0964 = 3;
            break;
    }

    set_screen_overlay_params_back(D_800A0963, D_800A0954);
    set_screen_overlay_color(1, D_800A095B, D_800A095D, D_800A095F);

    intro_logos_update_fade();
}

void state_step_intro(void) {
    PlayerData* playerData = &gPlayerData;
    u32 pressedButtons = gGameStatusPtr->pressedButtons;
    s32 i;

    if (gGameStatusPtr->creditsViewportMode != -1) {
        if (D_800A0964 == 0 && pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_START | BUTTON_Z)) {
            D_800A0964 = 1;
        }

        if (D_800A0964 == 1 && (gGameStatusPtr->loadMenuState == 0 || gGameStatusPtr->loadMenuState == 1 ||
                                gGameStatusPtr->loadMenuState == 4)) {
            gGameStatusPtr->creditsViewportMode = 100;
            state_init_intro();
            return;
        }

        if (D_800A0964 == 2 && (gGameStatusPtr->loadMenuState == 0 || gGameStatusPtr->loadMenuState == 1 ||
                                gGameStatusPtr->loadMenuState == 4)) {
            gGameStatusPtr->creditsViewportMode++;
            state_init_intro();
            return;
        }
    }

    switch (gGameStatusPtr->loadMenuState) {
        case 0:
            update_effects();
            update_cameras();
            if (gGameStatusPtr->creditsViewportMode == -1) {
                set_curtain_fade_goal(0.0f);
                if (intro_logos_fade_out(D_800A0956)) {
                    gGameStatusPtr->loadMenuState = 1;
                    set_curtain_draw_callback(NULL);
                }
            } else {
                D_800A0954 += D_800A0956;
                if (D_800A0954 >= 0xFF) {
                    D_800A0954 = 0xFF;
                    gGameStatusPtr->loadMenuState = 1;
                    set_curtain_draw_callback(NULL);
                }
            }
            break;
        case 1:
            D_800A0950 = 4;
            gOverrideFlags |= 8;
            if (D_800A0960 != 0xE) {
                gGameStatusPtr->loadMenuState = 2;
            }
            break;
        case 21:
            D_800A0950--;
            if (D_800A0950 <= 0) {
                gOverrideFlags &= -9;
                gGameStatusPtr->loadMenuState = 2;
            }
            break;
        case 2:
            set_curtain_draw_callback(NULL);
            gGameStatusPtr->isBattle = 0;
            gGameStatusPtr->unk_76 = 0;
            gGameStatusPtr->disableScripts = 0;
            gGameStatusPtr->unk_7D = 0;

            if (gGameStatusPtr->creditsViewportMode == -1) {
                general_heap_create();
                clear_render_tasks();
                clear_generic_entity_list();
                clear_script_list();
                create_cameras_a();
                spr_init_sprites(0);
                clear_entity_models();
                clear_animator_list();
                clear_model_data();
                clear_sprite_shading_data();
                reset_background_settings();
                clear_hud_element_cache();
                clear_trigger_data();
                clear_printers();
                clear_entity_data(0);
                clear_screen_overlays();
                clear_player_status();
                clear_npcs();
                clear_player_data();
                reset_battle_status();
                init_encounter_status();
                clear_effect_data();
                clear_item_entity_data();
                clear_saved_variables();
                initialize_collision();
                set_game_mode(2);
                return;
            }

            playerData->curHP = 10;
            playerData->curMaxHP = 10;
            playerData->hardMaxHP = 10;
            playerData->curFP = 5;
            playerData->curMaxFP = 5;
            playerData->hardMaxFP = 5;
            playerData->maxBP = 2;
            playerData->bootsLevel = 0;
            playerData->hammerLevel = -1;
            playerData->fortressKeyCount = 0;
            playerData->level = 0;

            for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
                playerData->partners[i].enabled = 0;
            }

            playerData->currentPartner = 0;
            load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
            gGameStatusPtr->loadMenuState = 3;
            disable_player_input();
            break;
        case 3:
            if (D_800A0960 == 0xE) {
                D_800A0960 = 0xF;
            }
            D_800A0954 = 0xFF - D_800A0958;
            gOverrideFlags &= ~0x8;
            gCameras->flags &= ~0x2;
            gOverrideFlags &= ~0x2;
            update_player();
            update_encounters();
            update_npcs();
            update_effects();
            update_cameras();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
                gGameStatusPtr->loadMenuState = 4;
                break;
            }
            return;
        case 4:
            update_effects();
            update_cameras();
            update_npcs();
            if (D_800A0954 == 0) {
                set_screen_overlay_params_front(0xFF, -1.0f);
                set_screen_overlay_params_back(0xFF, -1.0f);
            } else {
                D_800A0954 -= D_800A0958;
                if (D_800A0954 < 0) {
                    D_800A0954 = 0;
                }
            }
            break;
    }

    set_screen_overlay_params_back(D_800A0963, D_800A0954);
    set_screen_overlay_color(1, D_800A095B, D_800A095D, D_800A095F);
    intro_logos_update_fade();
}

void state_drawUI_intro(void) {
}
