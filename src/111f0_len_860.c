#include "common.h"
#include "nu/nusys.h"

void func_80035E54(void);

void func_80035DF0(s16 arg0) {
    D_800A0942 = arg0;
}

void func_80035E00(void) {
    D_800A0948 = 0;
    func_80035E54();
}

void func_80035E24(void) {
    D_800A0948 = 1;
    set_map_transition_effect(8);
    func_80035E54();
}

void func_80035E54(void) {
    D_800A0944 = 0;
    D_800A0946 = 4;
    gGameStatusPtr->exitTangent = 0.0f;
    gMapTransitionAlpha = 0xFF;
    nuContRmbForceStopEnd();
    func_801382AC(&gMapTransitionAlpha);

    gOverrideFlags |= 0x8;

    set_variable(0, SI_SAVE_VAR(1), gGameStatusPtr->unk_A9);
    timeFreezeMode = 0;
}

INCLUDE_ASM(s32, "111f0_len_860", func_80035EEC);

void func_800360FC(void) {
    if (gGameStatusPtr->loadMenuState == 2) {
        draw_status_ui();
    }
}

void func_80036130(void) {
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

INCLUDE_ASM(s32, "111f0_len_860", func_8003617C);

void func_800363FC(void) {
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

INCLUDE_ASM(s32, "111f0_len_860", func_8003646C);

void func_80036640(void) {
}
