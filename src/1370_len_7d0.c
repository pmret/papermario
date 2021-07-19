#include "common.h"
#include "nu/nusys.h"

s16 D_80074010 = 8; // might be an array, could be size 1-8

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void gfx_task_main(void);

extern s32 D_80073E00;
extern u16* D_80073E04;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern s32 D_80073E10;
extern u16* D_8009A680;
extern OSViMode _osViModeNtscLan1;
extern OSViMode _osViModeMPalLan1;

void boot_main(void) {
    OSViMode* viMode;

    if (osTvType == OS_TV_NTSC) {
        osViSetMode(&_osViModeNtscLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else if (osTvType == OS_TV_MPAL) {
        osViSetMode(&_osViModeMPalLan1);
        osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    } else {
        PANIC();
    }

    nuGfxDisplayOff();
    crash_create_monitor();
    is_debug_init();
    nuGfxInit();
    gGameStatusPtr->contBitPattern = nuContInit();
    func_8002D160();
    func_802B2000();
    func_802B203C();
    nuGfxFuncSet((NUGfxFunc) gfxRetrace_Callback);
    nuGfxPreNMIFuncSet(gfxPreNMI_Callback);
    gRandSeed += osGetCount();
    nuGfxDisplayOn();

    while (TRUE) {}
}

void gfxRetrace_Callback(s32 arg0) {
    if (D_80073E00 != 0) {
        if (D_80073E00 == 1) {
            nuGfxTaskAllEndWait();
            if (arg0 == 0) {
                u16* fb = (u16*) osViGetCurrentFramebuffer();
                u16** temp_8009A680 = &D_8009A680;

                temp_8009A680[2] = fb;
                temp_8009A680[1] = fb;
                temp_8009A680[0] = fb;
                D_80073E04 = fb;
                nuGfxSetCfb(&D_8009A680, 3);
                osViSwapBuffer(D_8009A680);
                D_80073E00 = 2;
            }
        }
        if (D_80073E00 == 2) {
            gfx_task_main();
        }
    } else {
        D_80073E0A ^= 1;
        if (D_80073E0A == 0) {
            step_game_loop();
            D_80073E08 = 1;

            if (arg0 < 3) {
                D_80073E08 = 0;
                gfx_task_background();
                gfx_draw_frame();
            }
        }
    }
}

INCLUDE_ASM(void, "1370_len_7d0", gfx_task_main);

void gfxPreNMI_Callback(void) {
    D_80073E00 = 1;
    nuContRmbForceStop();
}
