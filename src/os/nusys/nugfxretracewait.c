#include "common.h"
#include "nu/nusys.h"

void nuGfxRetraceWait(u32 retrace_num) {
    NUScClient client;
    OSMesg mesgBuf;
    OSMesgQueue mesgQ;

    osCreateMesgQueue(&mesgQ, &mesgBuf, 1);

    nuScAddClient(&client, &mesgQ , NU_SC_RETRACE_MSG);

    while(retrace_num) {
        osRecvMesg(&mesgQ, NULL, OS_MESG_BLOCK);
        retrace_num--;
    }

    nuScRemoveClient(&client);
}
