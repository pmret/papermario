#include "PR/os_internal.h"
#include "PR/sptask.h"
#include "PR/rcp.h"
#include "PR/osint.h"

#define _osVirtualToPhysical(ptr)               \
    if (ptr != NULL)                            \
    {                                           \
        ptr = (void *)osVirtualToPhysical(ptr); \
    }

static OSTask tmp_task;

#if VERSION_IQUE
static OSTask* _VirtualToPhysicalTask(OSTask* intp) {
    OSTask* tp;
    tp = &tmp_task;
    bcopy(intp, tp, sizeof(OSTask));

    _osVirtualToPhysical(tp->t.ucode);
    _osVirtualToPhysical(tp->t.ucode_data);
    _osVirtualToPhysical(tp->t.dram_stack);
    _osVirtualToPhysical(tp->t.output_buff);
    _osVirtualToPhysical(tp->t.output_buff_size);
    _osVirtualToPhysical(tp->t.data_ptr);
    _osVirtualToPhysical(tp->t.yield_data_ptr);
    return tp;
}
#endif

void osSpTaskLoad(OSTask *intp) {
    OSTask *tp;

#if VERSION_IQUE
    tp = _VirtualToPhysicalTask(intp);
#else
    tp = &tmp_task;
    bcopy(intp, tp, sizeof(OSTask));
    _osVirtualToPhysical(tp->t.ucode);
    _osVirtualToPhysical(tp->t.ucode_data);
    _osVirtualToPhysical(tp->t.dram_stack);
    _osVirtualToPhysical(tp->t.output_buff);
    _osVirtualToPhysical(tp->t.output_buff_size);
    _osVirtualToPhysical(tp->t.data_ptr);
    _osVirtualToPhysical(tp->t.yield_data_ptr);
#endif

    if (tp->t.flags & OS_TASK_YIELDED) {
        tp->t.ucode_data = tp->t.yield_data_ptr;
        tp->t.ucode_data_size = tp->t.yield_data_size;
        intp->t.flags &= ~OS_TASK_YIELDED;
        if (tp->t.flags & OS_TASK_LOADABLE) {
            tp->t.ucode = (u64 *)IO_READ((u32)intp->t.yield_data_ptr + OS_YIELD_DATA_SIZE - 4);
        }
    }
    osWritebackDCache(tp, sizeof(OSTask));
    __osSpSetStatus(SP_CLR_YIELD | SP_CLR_YIELDED | SP_CLR_TASKDONE | SP_SET_INTR_BREAK);
    while (__osSpSetPc(SP_IMEM_START) == -1) {
    }
    while (__osSpRawStartDma(1, (SP_IMEM_START - sizeof(*tp)), tp, sizeof(OSTask)) == -1) {
    }
    while (__osSpDeviceBusy()) {
    }
    while (__osSpRawStartDma(1, SP_IMEM_START, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1) {
    }
}

void osSpTaskStartGo(OSTask *tp) {
    while (__osSpDeviceBusy()) {
    }
    __osSpSetStatus(SP_SET_INTR_BREAK | SP_CLR_SSTEP | SP_CLR_BROKE | SP_CLR_HALT);
}
