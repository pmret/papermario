#include "macros.h"
#include <PR/os_internal.h>

#define SI_Q_BUF_LEN 1
u32 __osSiAccessQueueEnabled = 0;

static OSMesg siAccessBuf[SI_Q_BUF_LEN] OSALIGNED(8);
OSMesgQueue __osSiAccessQueue OSALIGNED(8);

void __osSiCreateAccessQueue(void) {
    __osSiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osSiAccessQueue, siAccessBuf, SI_Q_BUF_LEN);
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg dummyMesg;
    if (!__osSiAccessQueueEnabled) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&__osSiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
