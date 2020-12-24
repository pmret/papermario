#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"


// TODO: create src/os/nusys/nuSched.h?
extern u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];

void (*D_8009A630)(void) = NULL;

void nuBoot(void) {
    osInitialize(); // __osInitialize_common
    osCreateThread(&D_800A4270, 1, (void*) &boot_idle, 0, &nuScStack, 10);
    osStartThread(&D_800A4270);
}

void boot_idle(void) {
    void (*temp_v0)(void);

    D_8009A630 = NULL;

    nuPiInit();
    nuScCreateScheduler(2, 1);
    osViSetSpecialFeatures(0x5A);
    osCreateThread(&D_800A4420, 3, (void*) &boot_main, 0, &D_800B8590, 10);
    osStartThread(&D_800A4420);
    osSetThreadPri(&D_800A4270, OS_PRIORITY_IDLE);
    do {
        do { /* nothing */ } while ((temp_v0 = D_8009A630) == NULL);
        temp_v0();
    } while (1);
}
