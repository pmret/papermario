// #include "ultra64.h"
// #include "include_asm.h"

// OSDevMgr __osPiDevMgr = {0};
// OSPiHandle* __osPiTable = NULL;

// extern OSPiHandle __Dom1SpeedParam;
// extern OSPiHandle __Dom2SpeedParam;
// OSPiHandle* __osCurrentHandle[2] = {&__Dom1SpeedParam, &__Dom2SpeedParam};

// INCLUDE_ASM(void, "os/osCreatePiManager", osCreatePiManager, OSPri prio, OSMesgQueue* queue, OSMesg* mesg, s32 unk);

#include "macros.h"
#include "PR/os_internal.h"
#include "PR/piint.h"

OSDevMgr __osPiDevMgr = {0};
OSPiHandle *__osPiTable = NULL;
OSPiHandle __Dom1SpeedParam ALIGNED(8);
OSPiHandle __Dom2SpeedParam ALIGNED(8);
OSPiHandle *__osCurrentHandle[2] ALIGNED(8) = {&__Dom1SpeedParam, &__Dom2SpeedParam};

extern OSThread piThread;
extern char piThreadStack[OS_PIM_STACKSIZE];
extern OSMesgQueue piEventQueue;
extern OSMesg piEventBuf[1];

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (!__osPiDevMgr.active) {
        osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
        osCreateMesgQueue(&piEventQueue, (OSMesg*)piEventBuf, 1);

        if (!__osPiAccessQueueEnabled) {
            __osPiCreateAccessQueue();
        }

        osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
        oldPri = -1;
        myPri = osGetThreadPri(NULL);

        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(NULL, pri);
        }

        savedMask = __osDisableInt();
        __osPiDevMgr.active = 1;
        __osPiDevMgr.thread = &piThread;
        __osPiDevMgr.cmdQueue = cmdQ;
        __osPiDevMgr.evtQueue = &piEventQueue;
        __osPiDevMgr.acsQueue = &__osPiAccessQueue;
        __osPiDevMgr.dma = __osPiRawStartDma;
        __osPiDevMgr.edma = __osEPiRawStartDma;
        osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[OS_PIM_STACKSIZE], pri);
        osStartThread(&piThread);
        __osRestoreInt(savedMask);

        if (oldPri != -1) {
            osSetThreadPri(NULL, oldPri);
        }
    }
}
