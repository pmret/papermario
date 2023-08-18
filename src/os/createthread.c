#include "PR/R4300.h"
#include "PR/osint.h"

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri p) {
    register u32 saveMask;
    OSIntMask mask;
    t->id = id;
    t->priority = p;
    t->next = NULL;
    t->queue = NULL;
    t->context.pc = (u32)entry;
    t->context.a0 = (s64)(s32)arg; // Double cast gets rid of compiler warning
    t->context.sp = (s64)(s32)sp - 16;
    t->context.ra = (u64)__osCleanupThread;
    mask = OS_IM_ALL;
#if VERSION_IQUE
    t->context.sr = (mask & (SR_IMASK | SR_IE)) | SR_EXL;
#else
    t->context.sr = SR_IMASK | SR_EXL | SR_IE;
#endif
    t->context.rcp = (mask & RCP_IMASK) >> RCP_IMASKSHIFT;
    t->context.fpcsr = (u32)(FPCSR_FS | FPCSR_EV);
    t->fp = 0;
    t->state = OS_STATE_STOPPED;
    t->flags = 0;
    saveMask = __osDisableInt();
    t->tlnext = __osActiveQueue;
    __osActiveQueue = t;
    __osRestoreInt(saveMask);
}
