#include "common.h"
#include "hud_element.h"
#include "sprite.h"

SHIFT_BSS s32 D_800A0950;
SHIFT_BSS s16 D_800A0954;
SHIFT_BSS s16 D_800A0956;
SHIFT_BSS s16 D_800A0958;
SHIFT_BSS s16 D_800A095A;
SHIFT_BSS s16 D_800A095C;
SHIFT_BSS s16 D_800A095E;
SHIFT_BSS s32 D_800A0960;
SHIFT_BSS s32 D_800A0964;

void state_init_intro(void) {
    s8 unk_A8;

    gGameStatusPtr->introState = INTRO_STATE_0;

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
            D_800A095A = 208;
            D_800A095C = 208;
            D_800A095E = 208;
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

    set_screen_overlay_params_back(D_800A0960, D_800A0954);
    set_screen_overlay_color(SCREEN_LAYER_BACK, D_800A095A, D_800A095C, D_800A095E);

    intro_logos_update_fade();
}

void state_step_intro(void) {
    PlayerData* playerData = &gPlayerData;
    u32 pressedButtons = gGameStatusPtr->pressedButtons[0];
    s32 i;

    if (gGameStatusPtr->creditsViewportMode != -1) {
        if (D_800A0964 == 0 && pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_START | BUTTON_Z)) {
            D_800A0964 = 1;
        }

        if (D_800A0964 == 1 && (gGameStatusPtr->introState == INTRO_STATE_0 ||
                                gGameStatusPtr->introState == INTRO_STATE_1 ||
                                gGameStatusPtr->introState == INTRO_STATE_4))
        {
            gGameStatusPtr->creditsViewportMode = 100;
            state_init_intro();
            return;
        }

        if (D_800A0964 == 2 && (gGameStatusPtr->introState == INTRO_STATE_0 ||
                                gGameStatusPtr->introState == INTRO_STATE_1 ||
                                gGameStatusPtr->introState == INTRO_STATE_4))
        {
            gGameStatusPtr->creditsViewportMode++;
            state_init_intro();
            return;
        }
    }

    switch (gGameStatusPtr->introState) {
        case INTRO_STATE_0:
            update_effects();
            update_cameras();
            if (gGameStatusPtr->creditsViewportMode == -1) {
                set_curtain_fade_goal(0.0f);
                if (intro_logos_fade_out(D_800A0956)) {
                    gGameStatusPtr->introState = INTRO_STATE_1;
                    set_curtain_draw_callback(NULL);
                }
            } else {
                D_800A0954 += D_800A0956;
                if (D_800A0954 >= 0xFF) {
                    D_800A0954 = 0xFF;
                    gGameStatusPtr->introState = INTRO_STATE_1;
                    set_curtain_draw_callback(NULL);
                }
            }
            break;
        case INTRO_STATE_1:
            D_800A0950 = 4;
            gOverrideFlags |= GLOBAL_OVERRIDES_8;
            if (D_800A0960 != 0xE) {
                gGameStatusPtr->introState = INTRO_STATE_2;
            }
            break;
        case INTRO_STATE_15:
            D_800A0950--;
            if (D_800A0950 <= 0) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                gGameStatusPtr->introState = INTRO_STATE_2;
            }
            break;
        case INTRO_STATE_2:
            set_curtain_draw_callback(NULL);
            gGameStatusPtr->isBattle = FALSE;
            gGameStatusPtr->unk_76 = 0;
            gGameStatusPtr->disableScripts = FALSE;
            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;

            if (gGameStatusPtr->creditsViewportMode == -1) {
                general_heap_create();
                clear_render_tasks();
                clear_worker_list();
                clear_script_list();
                create_cameras_a();
                spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
                clear_entity_models();
                clear_animator_list();
                clear_model_data();
                clear_sprite_shading_data();
                reset_background_settings();
                hud_element_clear_cache();
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
                set_game_mode(GAME_MODE_TITLE_SCREEN);
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

            playerData->curPartner = PARTNER_NONE;
            load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
            gGameStatusPtr->introState = INTRO_STATE_3;
            disable_player_input();
            break;
        case INTRO_STATE_3:
            if (D_800A0960 == 0xE) {
                D_800A0960 = 0xF;
            }
            D_800A0954 = 255 - D_800A0958;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
            gCameras[CAM_DEFAULT].flags &= ~0x2;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
            update_player();
            update_encounters();
            update_npcs();
            update_effects();
            update_cameras();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
                gGameStatusPtr->introState = INTRO_STATE_4;
                break;
            }
            return;
        case INTRO_STATE_4:
            update_effects();
            update_cameras();
            update_npcs();
            if (D_800A0954 == 0) {
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                set_screen_overlay_params_back(OVERLAY_NONE, -1.0f);
            } else {
                D_800A0954 -= D_800A0958;
                if (D_800A0954 < 0) {
                    D_800A0954 = 0;
                }
            }
            break;
    }

    set_screen_overlay_params_back(D_800A0960, D_800A0954);
    set_screen_overlay_color(SCREEN_LAYER_BACK, D_800A095A, D_800A095C, D_800A095E);
    intro_logos_update_fade();
}

void state_drawUI_intro(void) {
}
