#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"

// TODO: create src/os/nusys/nuSched.h?
extern u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];

// probably should be at 0x8009A630, unless D_8009A630 (what's technically used in boot_idle) isn't nuIdleFunc
static void (*nuIdleFunc)(void);

void nuBoot(void) {
    osInitialize(); // osInitialize
    osCreateThread(&D_800A4270, NU_IDLE_THREAD_ID, boot_idle, NULL, &nuScStack, 10);
    osStartThread(&D_800A4270);
}

#ifdef NON_MATCHING
void boot_idle(void) {
    nuIdleFunc = NULL;

    nuPiInit();
    nuScCreateScheduler(OS_VI_NTSC_LAN1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&D_800A4420, NU_MAIN_THREAD_ID, boot_main, NULL, &nuYieldBuf, NU_MAIN_THREAD_PRI);
    osStartThread(&D_800A4420);
    osSetThreadPri(&D_800A4270, NU_IDLE_THREAD_PRI);

    while (1) {
        if (nuIdleFunc != NULL) {
            nuIdleFunc();
        }
    }
}
#else
INCLUDE_ASM(void, "os/39cb0_len_100", boot_idle, void);
#endif
