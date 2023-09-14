#include "common.h"
#include "nu/nusys.h"
#include "game_modes.h"

SHIFT_BSS s16 gMapTransitionAlpha;
SHIFT_BSS s16 gMapTransitionFadeRate;
SHIFT_BSS s16 gMapTransitionState;
SHIFT_BSS s16 gMapTransitionStateTime;
SHIFT_BSS s16 gLoadedFromFileSelect;

void set_map_change_fade_rate(s16 fadeRate) {
    gMapTransitionFadeRate = fadeRate;
}

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
    gMapTransitionState = 0;
    gMapTransitionStateTime = 4;
    gGameStatusPtr->exitTangent = 0.0f;
    gMapTransitionAlpha = 255;
    nuContRmbForceStopEnd();
    update_exit_map_screen_overlay(&gMapTransitionAlpha);

    gOverrideFlags |= GLOBAL_OVERRIDES_8;

    evt_set_variable(NULL, GB_Unused_EVT_01, gGameStatusPtr->unk_A9);
    timeFreezeMode = 0;
}

void state_step_enter_world(void) {
    switch (gMapTransitionState) {
        case 0:
            if (gMapTransitionStateTime == 0) {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;

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
            } else {
                gMapTransitionStateTime--;
            }
            break;
        case 1:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                gMapTransitionState++;
            }
            break;
        case 2:
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
    if (gGameStatusPtr->introState == INTRO_STATE_2) {
        draw_status_ui();
    }
}

void state_init_change_map(void) {
    gMapTransitionAlpha = 0x00;
    gMapTransitionFadeRate = 20;
    gMapTransitionState = 0;

    if (gGameStatusPtr->prevArea != gGameStatusPtr->areaID) {
        gGameStatusPtr->didAreaChange = TRUE;
        gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
    } else {
        gGameStatusPtr->didAreaChange = FALSE;
    }
}

void state_step_change_map(void) {
    switch (gMapTransitionState) {
        case 0:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if (update_exit_map_screen_overlay(&gMapTransitionAlpha) != 0) {
                gMapTransitionState++;
            }
            break;
        case 1:
            gOverrideFlags |= GLOBAL_OVERRIDES_8;
            nuContRmbForceStop();
            gMapTransitionStateTime = 4;
            gMapTransitionState++;
            break;
        case 2:
            if (gGameStatusPtr->demoState != DEMO_STATE_NONE) {
                set_game_mode(GAME_MODE_DEMO);
            }

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
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
        case 3:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                gMapTransitionState++;
            }
            break;
        case 4:
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
    if (gMapTransitionState == 4 || gMapTransitionState == 0) {
        draw_status_ui();
    }
}

void state_init_game_over(void) {
    gMapTransitionAlpha = 255;
    gMapTransitionFadeRate = 20;
    gMapTransitionState = 0x01;
    gPlayerStatus.flags |= PS_FLAG_NO_STATIC_COLLISION;
}

void state_step_game_over(void) {
    switch (gMapTransitionState) {
        case 1:
            gOverrideFlags |= GLOBAL_OVERRIDES_8;
            nuContRmbForceStop();
            gMapTransitionStateTime = 4;
            gMapTransitionState++;
            break;
        case 2:
            if (gMapTransitionStateTime != 0) {
                gMapTransitionStateTime--;
            } else {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
                nuContRmbForceStopEnd();
                gMapTransitionState++;
            }
            break;
        case 3:
            update_encounters();
            update_npcs();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                gMapTransitionState++;
                break;
            }
            return;
        case 4:
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
