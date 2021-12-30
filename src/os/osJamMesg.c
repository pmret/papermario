#include "common.h"
#include <PR/osint.h>

#ifndef KMC_ASM
s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    register u32 saveMask = __osDisableInt();
    while (mq->validCount >= mq->msgCount)
    {
        if (flag == OS_MESG_BLOCK) {
            __osRunningThread->state = OS_STATE_WAITING;
            __osEnqueueAndYield(&mq->fullqueue);
        } else {
            __osRestoreInt(saveMask);
            return -1;
        }
    }

    mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
    mq->msg[mq->first] = msg;
    mq->validCount++;
    if (mq->mtqueue->next != NULL) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }
    __osRestoreInt(saveMask);
    return 0;
}
#else
INCLUDE_ASM_LIBULTRA(s32, "osJamMesg", osJamMesg, OSMesgQueue *mq, OSMesg msg, s32 flag);
#endif
