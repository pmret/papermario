#include "common.h"
#include "hud_element.h"
#include "sprite.h"
#include "game_modes.h"

enum IntroStates {
    INTRO_INIT                  = 0x00000000,
    INTRO_DISABLE_DRAW_FRAME    = 0x00000001,
    INTRO_LOAD_MAP              = 0x00000002,
    INTRO_AWAIT_MAIN            = 0x00000003,
    INTRO_FADE_IN               = 0x00000004,
    INTRO_ENABLE_DRAW_FRAME      = 0x00000015, // unused
};

SHIFT_BSS s32 IntroEnableDrawFrameDelay;
SHIFT_BSS s16 IntroOverlayAlpha;
SHIFT_BSS s16 IntroFrontFadeAlpha;
SHIFT_BSS s16 IntroOverlayDelta;
SHIFT_BSS s16 IntroFadeColorR;
SHIFT_BSS s16 IntroFadeColorG;
SHIFT_BSS s16 IntroFadeColorB;
SHIFT_BSS s32 IntroOverlayType;
SHIFT_BSS s32 D_800A0964; // related to skipping the intro

void state_init_intro(void) {
    s8 viewportMode;

    gGameStatusPtr->startupState = INTRO_INIT;

    set_curtain_scale_goal(1.0f);
    set_curtain_fade_goal(0.3f);

    viewportMode = gGameStatusPtr->introPart;
    switch (viewportMode) {
        case 0:
            startup_set_fade_screen_alpha(0);

            IntroOverlayAlpha = 255;
            IntroFrontFadeAlpha = 16;
            IntroOverlayDelta = 4;
            IntroOverlayType = OVERLAY_SCREEN_COLOR;
            IntroFadeColorR = 208;
            IntroFadeColorG = 208;
            IntroFadeColorB = 208;
            D_800A0964 = 0;

            // hos_05 (Star Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 5; //TODO hard-coded map ID
            gGameStatusPtr->entryID = 3;
            break;
        case 1:
            startup_set_fade_screen_alpha(0);

            IntroOverlayAlpha = 0;
            IntroFrontFadeAlpha = 12;
            IntroOverlayDelta = 4;
            IntroOverlayType = OVERLAY_VIEWPORT_COLOR;
            IntroFadeColorR = 0;
            IntroFadeColorG = 0;
            IntroFadeColorB = 0;
            D_800A0964 = 0;

            // hos_04 (Outside the Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 4; //TODO hard-coded map ID
            gGameStatusPtr->entryID = 4;
            break;
        default:
            startup_set_fade_screen_alpha(0);
            startup_set_fade_screen_color(208);

            gGameStatusPtr->introPart = INTRO_PART_NONE;

            IntroFrontFadeAlpha = 6;
            IntroOverlayDelta = 6;

            IntroMessageIdx++;
            if (IntroMessageIdx >= 4) {
                // both hos_04 and hos_05 have an IntroMessage array of length 4
                IntroMessageIdx = 0;
            }

            D_800A0964 = 3;
            break;
    }

    set_screen_overlay_params_back(IntroOverlayType, IntroOverlayAlpha);
    set_screen_overlay_color(SCREEN_LAYER_BACK, IntroFadeColorR, IntroFadeColorG, IntroFadeColorB);

    startup_fade_screen_update();
}

void state_step_intro(void) {
    PlayerData* playerData = &gPlayerData;
    u32 pressedButtons = gGameStatusPtr->pressedButtons[0];
    s32 i;

    if (gGameStatusPtr->introPart != INTRO_PART_NONE) {
        if (D_800A0964 == 0 && pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_START | BUTTON_Z)) {
            D_800A0964 = 1;
        }

        if (D_800A0964 == 1 && (gGameStatusPtr->startupState == INTRO_INIT ||
                                gGameStatusPtr->startupState == INTRO_DISABLE_DRAW_FRAME ||
                                gGameStatusPtr->startupState == INTRO_FADE_IN))
        {
            gGameStatusPtr->introPart = INTRO_PART_100;
            state_init_intro();
            return;
        }

        if (D_800A0964 == 2 && (gGameStatusPtr->startupState == INTRO_INIT ||
                                gGameStatusPtr->startupState == INTRO_DISABLE_DRAW_FRAME ||
                                gGameStatusPtr->startupState == INTRO_FADE_IN))
        {
            gGameStatusPtr->introPart++;
            state_init_intro();
            return;
        }
    }

    switch (gGameStatusPtr->startupState) {
        case INTRO_INIT:
            update_effects();
            update_cameras();
            if (gGameStatusPtr->introPart == INTRO_PART_NONE) {
                set_curtain_fade_goal(0.0f);
                if (startup_fade_screen_out(IntroFrontFadeAlpha)) {
                    gGameStatusPtr->startupState = INTRO_DISABLE_DRAW_FRAME;
                    set_curtain_draw_callback(NULL);
                }
            } else {
                IntroOverlayAlpha += IntroFrontFadeAlpha;
                if (IntroOverlayAlpha >= 255) {
                    IntroOverlayAlpha = 255;
                    gGameStatusPtr->startupState = INTRO_DISABLE_DRAW_FRAME;
                    set_curtain_draw_callback(NULL);
                }
            }
            break;
        case INTRO_DISABLE_DRAW_FRAME:
            IntroEnableDrawFrameDelay = 4;
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            // this condition is always true, likely leftover from an earlier version
            if (IntroOverlayType != OVERLAY_INTRO_1) {
                gGameStatusPtr->startupState = INTRO_LOAD_MAP;
            }
            break;
        case INTRO_ENABLE_DRAW_FRAME: // unused
            IntroEnableDrawFrameDelay--;
            if (IntroEnableDrawFrameDelay <= 0) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                gGameStatusPtr->startupState = INTRO_LOAD_MAP;
            }
            break;
        case INTRO_LOAD_MAP:
            set_curtain_draw_callback(NULL);
            gGameStatusPtr->isBattle = FALSE;
            gGameStatusPtr->debugUnused1 = FALSE;
            gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;
            gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;

            if (gGameStatusPtr->introPart == INTRO_PART_NONE) {
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
                clear_entity_data(FALSE);
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
                playerData->partners[i].enabled = FALSE;
            }

            playerData->curPartner = PARTNER_NONE;
            load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, LOAD_FROM_MAP);
            gGameStatusPtr->startupState = INTRO_AWAIT_MAIN;
            disable_player_input();
            break;
        case INTRO_AWAIT_MAIN:
            if (IntroOverlayType == OVERLAY_INTRO_1) {
                IntroOverlayType = OVERLAY_INTRO_2;
            }
            IntroOverlayAlpha = 255 - IntroOverlayDelta;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            gCameras[CAM_DEFAULT].flags &= ~CAMERA_FLAG_DISABLED;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
            update_player();
            update_encounters();
            update_npcs();
            update_effects();
            update_cameras();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
                gGameStatusPtr->startupState = INTRO_FADE_IN;
                break;
            }
            return;
        case INTRO_FADE_IN:
            update_effects();
            update_cameras();
            update_npcs();
            if (IntroOverlayAlpha == 0) {
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                set_screen_overlay_params_back(OVERLAY_NONE, -1.0f);
            } else {
                IntroOverlayAlpha -= IntroOverlayDelta;
                if (IntroOverlayAlpha < 0) {
                    IntroOverlayAlpha = 0;
                }
            }
            break;
    }

    set_screen_overlay_params_back(IntroOverlayType, IntroOverlayAlpha);
    set_screen_overlay_color(SCREEN_LAYER_BACK, IntroFadeColorR, IntroFadeColorG, IntroFadeColorB);
    startup_fade_screen_update();
}

void state_drawUI_intro(void) {
}
