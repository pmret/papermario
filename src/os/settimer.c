#include "PR/osint.h"

int osSetTimer(OSTimer *t, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg) {
    register u32 saveMask;
    OSTime time;
    OSTimer* next;
    u32 count;
    u32 value;

    t->next = NULL;
    t->prev = NULL;
    t->value = countdown;
    t->interval = interval;

    if (countdown == 0) {
        t->value = interval;
    }

    t->mq = mq;
    t->msg = msg;

    saveMask = __osDisableInt();
    if (__osTimerList->next != __osTimerList) {
        next = __osTimerList->next;
        count = osGetCount();
        value = count - __osTimerCounter;

        if (value < next->value) {
            next->value -= value;
        } else {
            next->value = 1;
        }
    }

    time = __osInsertTimer(t);
    __osSetTimerIntr(__osTimerList->next->value);
    __osRestoreInt(saveMask);

    return 0;
}
