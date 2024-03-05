#include "macros.h"
#include <PR/osint.h>

__OSEventState __osEventStateTab[OS_NUM_EVENTS] OSALIGNED(8);
u32 __osPreNMI = 0;

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg) {
    register u32 saveMask = __osDisableInt();
    __OSEventState *es = &__osEventStateTab[event];

    es->messageQueue = mq;
    es->message = msg;

    if (event == OS_EVENT_PRENMI) {
        if (__osShutdown && !__osPreNMI) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        __osPreNMI = TRUE;
    }

    __osRestoreInt(saveMask);
}
