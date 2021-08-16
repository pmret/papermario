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

INCLUDE_ASM(void, "111f0_len_860", state_step_enter_world, void);

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

INCLUDE_ASM(void, "111f0_len_860", state_step_change_map, void);

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

INCLUDE_ASM(void, "111f0_len_860", func_8003646C, void);

void func_80036640(void) {
}
