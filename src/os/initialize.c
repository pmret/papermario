#include "include_asm.h"
#include "PR/os_internal.h"
#include "PR/rcp.h"

OSTime osClockRate = OS_CLOCK_RATE;
s32 osViClock = VI_NTSC_CLOCK;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;

s32 D_80095904[] = {0, 0, 0};

s32 D_80095910[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

s32 D_80095938[] = { 0x00000000, 0x00000000 };

INCLUDE_ASM(s32, "os/initialize", __createSpeedParam)

INCLUDE_ASM(void, "os/initialize", __osInitialize_common, void);

void __osInitialize_autodetect(void) {
}
