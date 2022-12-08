#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"

__asm__(".set nogpopt");

extern u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];

void nuBoot(void) {
    osInitialize();
    osCreateThread(&IdleThread, NU_IDLE_THREAD_ID, boot_idle, NULL, &nuScStack, 10);
    osStartThread(&IdleThread);
}

void boot_idle(void* data) {
    nuIdleFunc = NULL;

    nuPiInit();
    nuScCreateScheduler(OS_VI_NTSC_LAN1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&MainThread, NU_MAIN_THREAD_ID, boot_main, NULL, &nuYieldBuf, NU_MAIN_THREAD_PRI);
    osStartThread(&MainThread);
    osSetThreadPri(&IdleThread, NU_IDLE_THREAD_PRI);

    while (1) {
        if (nuIdleFunc != NULL) {
            nuIdleFunc();
        }
    }
}
