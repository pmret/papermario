#include "common.h"
#include "nu/nusys.h"
#include "game_modes.h"

BSS s16 gMapTransitionAlpha;
BSS s16 gMapTransitionFadeRate;
BSS s16 gMapTransitionState;
BSS s16 gMapTransitionStateTime;
BSS s16 gLoadedFromFileSelect;

void set_map_change_fade_rate(s16 fadeRate) {
    gMapTransitionFadeRate = fadeRate;
}

enum EnterWorldStates {
    ENTER_WORLD_LOAD_MAP        = 0,
    ENTER_WORLD_AWAIT_MAIN      = 1,
    ENTER_WORLD_FADE_IN         = 2,
};

void state_init_enter_demo(void) {
    gLoadedFromFileSelect = FALSE;
    init_enter_world_shared();
}

void state_init_enter_world(void) {
    gLoadedFromFileSelect = TRUE;
    set_map_transition_effect(TRANSITION_ENTER_WORLD);
    init_enter_world_shared();
}

void init_enter_world_shared(void) {
    gMapTransitionState = ENTER_WORLD_LOAD_MAP;
    gMapTransitionStateTime = 4;
    gGameStatusPtr->exitTangent = 0.0f;
    gMapTransitionAlpha = 255;
    nuContRmbForceStopEnd();
    update_exit_map_screen_overlay(&gMapTransitionAlpha);

    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;

    evt_set_variable(NULL, GB_Unused_EVT_01, gGameStatusPtr->unk_A9);
    timeFreezeMode = 0;
}

void state_step_enter_world(void) {
    switch (gMapTransitionState) {
        case ENTER_WORLD_LOAD_MAP:
            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
                break;
            }

            gGameStatusPtr->context = CONTEXT_WORLD;
            gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;

            if (!gLoadedFromFileSelect) {
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, LOAD_FROM_MAP);
            } else {
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, LOAD_FROM_FILE_SELECT);
            }

            gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
                disable_player_input();
            }
            update_cameras();
            gMapTransitionStateTime = 2;
            gMapTransitionState++;
            break;
        case ENTER_WORLD_AWAIT_MAIN:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
                break;
            }
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                gMapTransitionState++;
            }
            break;
        case ENTER_WORLD_FADE_IN:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if (update_enter_map_screen_overlay(&gMapTransitionAlpha) != 0) {
                if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
                    enable_player_input();
                }
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                set_game_mode(GAME_MODE_WORLD);
            }
            break;
    }
}

void state_drawUI_enter_world(void) {
    // startupState is being used as a timer here
    if (gGameStatusPtr->startupState == 2) {
        draw_status_ui();
    }
}

enum ChangeMapStates {
    CHANGE_MAP_INIT             = 0,
    CHANGE_MAP_DELAY            = 1,
    CHANGE_MAP_LOAD_MAP         = 2,
    CHANGE_MAP_AWAIT_MAIN       = 3,
    CHANGE_MAP_FADE_IN          = 4,
};

void state_init_change_map(void) {
    gMapTransitionAlpha = 0;
    gMapTransitionFadeRate = 20;
    gMapTransitionState = CHANGE_MAP_INIT;

    if (gGameStatusPtr->prevArea != gGameStatusPtr->areaID) {
        gGameStatusPtr->didAreaChange = TRUE;
        gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
    } else {
        gGameStatusPtr->didAreaChange = FALSE;
    }
}

void state_step_change_map(void) {
    switch (gMapTransitionState) {
        case CHANGE_MAP_INIT:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if (update_exit_map_screen_overlay(&gMapTransitionAlpha) != 0) {
                gMapTransitionState++;
            }
            break;
        case CHANGE_MAP_DELAY:
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            nuContRmbForceStop();
            gMapTransitionStateTime = 4;
            gMapTransitionState++;
            break;
        case CHANGE_MAP_LOAD_MAP:
            if (gGameStatusPtr->demoState != DEMO_STATE_NONE) {
                set_game_mode(GAME_MODE_DEMO);
            }

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else {
                gGameStatusPtr->context = CONTEXT_WORLD;
                gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, LOAD_FROM_MAP);
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                nuContRmbForceStopEnd();
                if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
                    disable_player_input();
                }
                update_cameras();
                gMapTransitionStateTime = 2;
                gMapTransitionState++;
            }
            break;
        case CHANGE_MAP_AWAIT_MAIN:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                gMapTransitionState++;
            }
            break;
        case CHANGE_MAP_FADE_IN:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if (update_enter_map_screen_overlay(&gMapTransitionAlpha) != 0) {
                if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
                    enable_player_input();
                }
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                set_game_mode(GAME_MODE_WORLD);
            }
            break;
        }
}

void state_drawUI_change_map(void) {
    if (gMapTransitionState == CHANGE_MAP_FADE_IN || gMapTransitionState == CHANGE_MAP_INIT) {
        draw_status_ui();
    }
}

enum GameOverStates {
    GAME_OVER_INIT              = 1,
    GAME_OVER_LOAD_MAP          = 2,
    GAME_OVER_AWAIT_MAIN        = 3,
    GAME_OVER_FADE_IN           = 4,
};

void state_init_game_over(void) {
    gMapTransitionAlpha = 255;
    gMapTransitionFadeRate = 20;
    gMapTransitionState = GAME_OVER_INIT;
    gPlayerStatus.flags |= PS_FLAG_NO_STATIC_COLLISION;
}

void state_step_game_over(void) {
    switch (gMapTransitionState) {
        case GAME_OVER_INIT:
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            nuContRmbForceStop();
            gMapTransitionStateTime = 4;
            gMapTransitionState++;
            break;
        case GAME_OVER_LOAD_MAP:
            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else {
                gGameStatusPtr->context = CONTEXT_WORLD;
                gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, LOAD_FROM_MAP);
                nuContRmbForceStopEnd();
                gMapTransitionState++;
            }
            break;
        case GAME_OVER_AWAIT_MAIN:
            update_encounters();
            update_npcs();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                gMapTransitionState++;
                break;
            }
            return;
        case GAME_OVER_FADE_IN:
            gMapTransitionAlpha -= gMapTransitionFadeRate;
            if (gMapTransitionAlpha < 0) {
                gMapTransitionAlpha = 0;
                gMapTransitionState++;
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                set_game_mode(GAME_MODE_WORLD);
            }
            update_npcs();
            update_player();
            update_effects();
            update_cameras();
            break;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, gMapTransitionAlpha);
}

void state_drawUI_game_over(void) {
}
