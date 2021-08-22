#include "common.h"
#include "nu/nusys.h"

void init_enter_world_shared(void);

void func_80035DF0(s16 arg0) {
    D_800A0942 = arg0;
}

void state_init_enter_demo(void) {
    D_800A0948 = 0;
    init_enter_world_shared();
}

void state_init_enter_world(void) {
    D_800A0948 = 1;
    set_map_transition_effect(8);
    init_enter_world_shared();
}

void init_enter_world_shared(void) {
    D_800A0944 = 0;
    D_800A0946 = 4;
    gGameStatusPtr->exitTangent = 0.0f;
    gMapTransitionAlpha = 0xFF;
    nuContRmbForceStopEnd();
    update_exit_map_screen_overlay(&gMapTransitionAlpha);

    gOverrideFlags |= 0x8;

    set_variable(NULL, SI_SAVE_VAR(1), gGameStatusPtr->unk_A9);
    timeFreezeMode = 0;
}

void state_step_enter_world(void) {
    switch (D_800A0944) {
        case 0:
            if (D_800A0946 == 0) {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;

                if (D_800A0948 == 0) {
                    load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
                } else {
                    load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 1);
                }

                gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
                set_time_freeze_mode(0);
                if (gGameStatusPtr->demoState == 0) {
                    disable_player_input();
                }
                update_cameras();
                D_800A0946 = 2;
                D_800A0944++;
            } else {
                D_800A0946--;
            }
            break;
        case 1:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (D_800A0946 != 0) {
                D_800A0946--;
            } else if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~0x8;
                D_800A0944++;
            }
            break;
        case 2:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if ((update_enter_map_screen_overlay(&gMapTransitionAlpha) << 0x10) != 0) {
                if (gGameStatusPtr->demoState == 0) {
                    enable_player_input();
                }
                set_screen_overlay_params_front(255, -1.0f);
                set_game_mode(4);
            }
            break;
    }
}

void state_drawUI_enter_world(void) {
    if (gGameStatusPtr->loadMenuState == 2) {
        draw_status_ui();
    }
}

void state_init_change_map(void) {
    gMapTransitionAlpha = 0x00;
    D_800A0942 = 0x14;
    D_800A0944 = 0x00;

    if (gGameStatusPtr->prevArea != gGameStatusPtr->areaID) {
        gGameStatusPtr->didAreaChange = TRUE;
        gGameStatusPtr->prevArea = gGameStatusPtr->areaID;
    } else {
        gGameStatusPtr->didAreaChange = FALSE;
    }
}

void state_step_change_map(void) {
    switch (D_800A0944) {
        case 0:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if ((update_exit_map_screen_overlay(&gMapTransitionAlpha) << 0x10) != 0) {
                D_800A0944++;
            }
            break;
        case 1:
            gOverrideFlags |= 8;
            nuContRmbForceStop();
            D_800A0946 = 4;
            D_800A0944++;
            break;
        case 2:
            if (gGameStatusPtr->demoState != 0) {
                set_game_mode(0x11);
            }

            if (D_800A0946 != 0) {
                D_800A0946--;
            } else {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
                set_time_freeze_mode(0);
                nuContRmbForceStopEnd();
                if (gGameStatusPtr->demoState == 0) {
                    disable_player_input();
                }
                update_cameras();
                D_800A0946 = 2;
                D_800A0944++;
            }
            break;
        case 3:
            update_encounters();
            update_npcs();
            update_player();
            update_cameras();

            if (D_800A0946 != 0) {
                D_800A0946--;
            } else if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~0x8;
                D_800A0944++;
            }
            break;
        case 4:
            update_npcs();
            update_player();
            update_effects();
            update_cameras();

            if ((update_enter_map_screen_overlay(&gMapTransitionAlpha) << 0x10) != 0) {
                if (gGameStatusPtr->demoState == 0) {
                    enable_player_input();
                }
                set_screen_overlay_params_front(255, -1.0f);
                set_game_mode(4);
            }
            break;
        }
}

void state_drawUI_change_map(void) {
    if (D_800A0944 == 4 || D_800A0944 == 0) {
        draw_status_ui();
    }
}

void func_80036430(void) {
    gMapTransitionAlpha = 0xFF;
    D_800A0942 = 0x14;
    D_800A0944 = 0x01;
    gPlayerStatus.flags |= 0x1000;
}

void func_8003646C(void) {
    switch (D_800A0944) {
        case 1:
            gOverrideFlags |= 8;
            nuContRmbForceStop();
            D_800A0946 = 4;
            D_800A0944++;
            break;
        case 2:
            if (D_800A0946 != 0) {
                D_800A0946--;
            } else {
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->disableScripts = FALSE;
                load_map_by_IDs(gGameStatusPtr->areaID, gGameStatusPtr->mapID, 0);
                nuContRmbForceStopEnd();
                D_800A0944++;
            }
            break;
        case 3:
            update_encounters();
            update_npcs();
            if (!does_script_exist(gGameStatusPtr->mainScriptID)) {
                gOverrideFlags &= ~0x8;
                D_800A0944++;
                break;
            }
            return;
        case 4:
            gMapTransitionAlpha -= D_800A0942;
            if (gMapTransitionAlpha < 0) {
                gMapTransitionAlpha = 0;
                D_800A0944++;
                set_screen_overlay_params_front(255, -1.0f);
                set_game_mode(4);
            }
            update_npcs();
            update_player();
            update_effects();
            update_cameras();
            break;
    }

    set_screen_overlay_params_front(0, gMapTransitionAlpha);
}

void func_80036640(void) {
}
