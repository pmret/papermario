#include "common.h"
#include "nu/nusys.h"

void gfxRetrace_Callback(void);
void gfxPreNMI_Callback(void);

#ifdef NON_MATCHING
// Control flow issue w/ PANIC
void boot_main(void) {
    OSViMode* viMode;
    if (osTvType == OS_TV_NTSC) {
        viMode = &osViModeTable[56];
    } else if (osTvType == OS_TV_MPAL) {
        viMode = &osViModeTable[57];
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

INCLUDE_ASM(void, "code_1370_len_7d0", gfxRetrace_Callback, void);

INCLUDE_ASM(s32, "code_1370_len_7d0", gfx_task_main);

INCLUDE_ASM(void, "code_1370_len_7d0", gfxPreNMI_Callback, void);
