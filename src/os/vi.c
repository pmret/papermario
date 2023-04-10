#include "ultra64.h"
#include "include_asm.h"
#include "macros.h"
#include "PR/os_internal.h"
#include "PR/os_vi.h"
#include "PR/R4300.h"
#include "PR/rcp.h"
#include "PR/viint.h"

static __OSViContext vi[2] ALIGNED(8) = {{0}, {0}};
__OSViContext *__osViCurr = &vi[0];
__OSViContext *__osViNext = &vi[1];

s32 meowp12345[] = {0, 0};

OSViMode osViModePalLan1 = {
    0x10,
    { 0x0000311E, 0x00000140, 0x04541E3A, 0x00000271, 0x00170C69, 0x0C6F0C6D, 0x00800300, 0x00000200, 0x00000000 },
    {
        { 0x00000280, 0x00000400, 0x005F0239, 0x0009026B, 0x00000002 },
        { 0x00000280, 0x00000400, 0x005F0239, 0x0009026B, 0x00000002 }
    }
};

void __osViInit(void) {
    bzero(vi, sizeof(vi));
    __osViCurr = &vi[0];
    __osViNext = &vi[1];
    __osViNext->retraceCount = 1;
    __osViCurr->retraceCount = 1;
    __osViNext->framep = (void*)K0BASE;
    __osViCurr->framep = (void*)K0BASE;

    if (osTvType == OS_TV_TYPE_PAL) {
        __osViNext->modep = &osViModePalLan1;
    } else if (osTvType == OS_TV_TYPE_MPAL) {
        __osViNext->modep = &osViModeMpalLan1;
    } else {
        __osViNext->modep = &osViModeNtscLan1;
    }
    
    __osViNext->state = VI_STATE_BLACK;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    
    while (IO_READ(VI_CURRENT_REG) > 10) { //wait for vsync?
    }

    IO_WRITE(VI_CONTROL_REG, 0); //pixel size blank (no data, no sync)
    __osViSwapContext();
}
