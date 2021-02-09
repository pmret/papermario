#include "common.h"
#include "nu/nusys.h"

void nuGfxThread2(void);

extern s32 D_800AE6D0;
extern OSThread D_800B1B90;

void nuGfxThreadStart(void) {
    osCreateThread(&D_800B1B90, 4, nuGfxThread2, NULL, &D_800AE6D0, NU_GFX_THREAD_PRI);
    osStartThread(&D_800B1B90);
}

INCLUDE_ASM(void, "os/nusys/nuGfxThread", nuGfxThread2);
