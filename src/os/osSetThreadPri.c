#include "common.h"

 struct __osThreadTail
{
    OSThread *next;
    OSPri priority;
};

struct __osThreadTail __osThreadTail = {0, -1};
OSThread *__osRunQueue = (OSThread *)&__osThreadTail;
OSThread *__osActiveQueue = (OSThread *)&__osThreadTail;
OSThread *__osRunningThread = {0};
OSThread *__osFaultedThread = {0};

#ifdef MOVE_ISSUE
void osSetThreadPri(OSThread* thread, OSPri pri) {
    register u32 prevInt = __osDisableInt();

    if (thread == NULL) {
        thread = __osRunningThread;
    }

    if (thread->priority != pri) {
        thread->priority = pri;
        if (thread != __osRunningThread && thread->state != 1) {
            __osDequeueThread(thread->queue, thread);
            __osEnqueueThread(thread->queue, thread);
        }
        if (__osRunningThread->priority < __osRunQueue->priority) {
            __osRunningThread->state = 2;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }

    __osRestoreInt(prevInt);
}
#else
INCLUDE_ASM(void, "os/osSetThreadPri", osSetThreadPri, OSThread* thread, OSPri pri);
#endif
