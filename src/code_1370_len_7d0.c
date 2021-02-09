#include "common.h"
#include "nu/nusys.h"

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void func_80026164(void);

extern s32* D_80073E00;
extern s32 D_80073E04;
extern s16 D_80073E08;
extern s16 D_80073E0A;
extern s32* D_8009A680;

#ifdef NON_MATCHING
// Control flow issue w/ PANIC
void boot_main(void) {
    OSViMode* viMode;
    if (osTvType == OS_TV_NTSC) {
        viMode = &osViModeTable[OS_TV_NTSC];
    } else if (osTvType == OS_TV_MPAL) {
        viMode = &osViModeTable[OS_TV_MPAL];
    } else {
        PANIC();
    }

    osViSetMode(viMode);

    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    nuGfxDisplayOff();
    crash_create_monitor();
    func_80025C60();
    nuGfxInitEX2();
    GAME_STATUS->contBitPattern = nuContInit();
    func_8002D160();
    func_802B2000();
    func_802B203C();
    nuGfxFuncSet(gfxRetrace_Callback);
    nuGfxPreNMIFuncSet(gfxPreNMI_Callback);
    {
        // Required to match
        s32* randSeed = &gRandSeed;
        (*randSeed) += osGetCount();
    }
    nuGfxDisplayOn();

    while (TRUE) {}
}
#else
INCLUDE_ASM(void, "code_1370_len_7d0", boot_main, void);
#endif

void gfxRetrace_Callback(s32 arg0) {
    s32* temp_80073E00 = &D_80073E00;

    if (*temp_80073E00 != 0) {
        if (*temp_80073E00 == 1) {
            nuGfxTaskAllEndWait();
            if (arg0 == 0) {
                void* fb = osViGetCurrentFramebuffer();
                s32* temp_8009A680 = &D_8009A680;

                temp_8009A680[2] = fb;
                temp_8009A680[1] = fb;
                temp_8009A680[0] = fb;
                D_80073E04 = fb;
                nuGfxSetCfb(temp_8009A680, 3);
                osViSwapBuffer(*temp_8009A680);
                *temp_80073E00 = 2;
            }
        }
        if (D_80073E00 == 2) {
            func_80026164();
        }
    } else {
        s16* temp_80073E0A = &D_80073E0A;

        *temp_80073E0A ^= 1;
        if (*temp_80073E0A == 0) {
            s16* temp_80073E08;

            step_game_loop();
            temp_80073E08 = &D_80073E08;
            *temp_80073E08 = 1;

            if (arg0 < 3) {
                *temp_80073E08 = 0;
                func_800269EC();
                gfx_draw_frame();
            }
        }
    }
}

INCLUDE_ASM(void, "code_1370_len_7d0", func_80026164);

void gfxPreNMI_Callback(void) {
    D_80073E00 = 1;
    nuContRmbForceStop();
}
