#include "macros.h"
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/viint.h"
#include "PR/osint.h"

OSDevMgr __osViDevMgr = {0};
u32 __additional_scanline = 0;

static OSThread viThread;
static unsigned char viThreadStack[OS_VIM_STACKSIZE] OSALIGNED(16);
static OSMesgQueue viEventQueue OSALIGNED(8);
static OSMesg viEventBuf[5] OSALIGNED(8);
static OSIoMesg viRetraceMsg OSALIGNED(8);
static OSIoMesg viCounterMsg OSALIGNED(8);

static void viMgrMain(void *arg);

void osCreateViManager(OSPri pri) {
    u32 savedMask;
    OSPri myPri;
    OSPri oldPri;

    if (!__osViDevMgr.active) {
        __osTimerServicesInit();
        __additional_scanline = 0;
        osCreateMesgQueue(&viEventQueue, viEventBuf, ARRAY_COUNT(viEventBuf));
        viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
        viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
        viRetraceMsg.hdr.retQueue = NULL;
        viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
        viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
        viCounterMsg.hdr.retQueue = NULL;
        osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
        osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);
        oldPri = -1;
        myPri = osGetThreadPri(NULL);

        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(NULL, pri);
        }

        savedMask = __osDisableInt();
        __osViDevMgr.active = TRUE;
        __osViDevMgr.thread = &viThread;
        __osViDevMgr.cmdQueue = &viEventQueue;
        __osViDevMgr.evtQueue = &viEventQueue;
        __osViDevMgr.acsQueue = NULL;
        __osViDevMgr.dma = NULL;
        __osViDevMgr.edma = NULL;
#ifdef BBPLAYER
        osCreateThread(&viThread, 0xD49, viMgrMain, &__osViDevMgr, &viThreadStack[OS_VIM_STACKSIZE], pri);
#else
        osCreateThread(&viThread, 0, viMgrMain, &__osViDevMgr, &viThreadStack[OS_VIM_STACKSIZE], pri);
#endif
        __osViInit();
        osStartThread(&viThread);
        __osRestoreInt(savedMask);

        if (oldPri != -1) {
            osSetThreadPri(0, oldPri);
        }
    }
}

static void viMgrMain(void *arg) {
    __OSViContext *vc;
    OSDevMgr *dm;
    OSIoMesg *mb;
    static u16 retrace;
    s32 first;
    u32 count;

    mb = NULL;
    first = 0;
    vc = __osViGetCurrentContext();
    retrace = vc->retraceCount;
    if (retrace == 0)
        retrace = 1;
    dm = (OSDevMgr *)arg;

    while (TRUE) {
        osRecvMesg(dm->evtQueue, (OSMesg)&mb, OS_MESG_BLOCK);
        switch (mb->hdr.type) {
            case OS_MESG_TYPE_VRETRACE:
                __osViSwapContext();
                retrace--;

                if (retrace == 0) {
                    vc = __osViGetCurrentContext();
                    if (vc->msgq != NULL)
                        osSendMesg(vc->msgq, vc->msg, OS_MESG_NOBLOCK);
                    retrace = vc->retraceCount;
                }

                __osViIntrCount++;

                if (first) {
                    count = osGetCount();
                    __osCurrentTime = count;
                    first = 0;
                }

                count = __osBaseCounter;
                __osBaseCounter = osGetCount();
                count = __osBaseCounter - count;
                __osCurrentTime = __osCurrentTime + count;
                break;
            case OS_MESG_TYPE_COUNTER:
                __osTimerInterrupt();
                break;
        }
    }
}
