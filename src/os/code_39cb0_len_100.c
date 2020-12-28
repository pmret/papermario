#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"

// TODO: create src/os/nusys/nuSched.h?
extern u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];

void (*D_8009A630)(void) = NULL;

void nuBoot(void) {
    osInitialize(); // __osInitialize_common
    osCreateThread(&D_800A4270, NU_IDLE_THREAD_ID, boot_idle, NULL, &nuScStack, 10);
    osStartThread(&D_800A4270);
}

void boot_idle(void) {
    D_8009A630 = NULL;

    nuPiInit();
    nuScCreateScheduler(OS_VI_NTSC_LAN1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&D_800A4420, NU_MAIN_THREAD_ID, boot_main, NULL, &D_800B8590, 10);
    osStartThread(&D_800A4420);
    osSetThreadPri(&D_800A4270, OS_PRIORITY_IDLE);

    do {
        void (*func)(void);

        do {
            func = D_8009A630;
        } while (func == NULL);

        func();
    } while (1);
}
