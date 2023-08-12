#include "ultra64.h"
#include "PR/osint.h"

struct __osThreadTail __osThreadTail = {0, -1};
OSThread* __osRunQueue = (OSThread*) &__osThreadTail;
OSThread* __osActiveQueue = (OSThread*) &__osThreadTail;
OSThread* __osRunningThread = NULL;
OSThread* __osFaultedThread = NULL;

void __osDequeueThread(register OSThread **queue, register OSThread *t) {
    register OSThread *pred;
    register OSThread *succ;

    pred = (OSThread *) queue;
    succ = pred->next;

    while (succ != NULL) {
        if (succ == t) {
            pred->next = t->next;
            return;
        }
        pred = succ;
        succ = pred->next;
    }
}
