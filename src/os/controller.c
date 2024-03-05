#include "macros.h"
#include "PR/os_internal.h"
#include "PR/controller.h"
#include "PR/siint.h"

extern u32 __osBbIsBb;
extern u32 __osBbHackFlags;
extern u32 __osBbPakAddress[4];

OSPifRam __osContPifRam BBALIGNED(16);
u8 __osContLastCmd;
u8 __osMaxControllers;

OSTimer __osEepromTimer;
OSMesgQueue __osEepromTimerQ OSALIGNED(8);
OSMesg __osEepromTimerMsg;

s32 __osContinitialized = 0;

s32 osContInit(OSMesgQueue* mq, u8* bitpattern, OSContStatus* data) {
    OSMesg dummy;
    s32 ret = 0;
    OSTime t;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;

    if (__osContinitialized != 0) {
        return 0;
    }

    __osContinitialized = 1;

    t = osGetTime();
    if (t < OS_USEC_TO_CYCLES(500000)) {
        osCreateMesgQueue(&timerMesgQueue, &dummy, 1);
        osSetTimer(&mytimer, OS_USEC_TO_CYCLES(500000) - t, 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
    }

    __osMaxControllers = 4;

    __osPackRequestData(CONT_CMD_REQUEST_STATUS);

    ret = __osSiRawStartDma(OS_WRITE, __osContPifRam.ramarray);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);

    ret = __osSiRawStartDma(OS_READ, __osContPifRam.ramarray);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);

    __osContGetInitData(bitpattern, data);
#ifdef BBPLAYER
    __osContLastCmd = CONT_CMD_CHANNEL_RESET;
#else
    __osContLastCmd = CONT_CMD_REQUEST_STATUS;
#endif
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&__osEepromTimerQ, &__osEepromTimerMsg, 1);

    return ret;
}

void __osContGetInitData(u8* pattern, OSContStatus* data) {
    u8* ptr;
    __OSContRequesFormat requestHeader;
    int i;
    u8 bits = 0;

    ptr = (u8*)__osContPifRam.ramarray;
    for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(requestHeader), data++) {
        requestHeader = *(__OSContRequesFormat*)ptr;
        data->errno = CHNL_ERR(requestHeader);

        if (data->errno != 0) {
            continue;
        }

        data->type = requestHeader.typel << 8 | requestHeader.typeh;
#ifdef BBPLAYER
        data->status = __osBbPakAddress[i] != 0;
#else
        data->status = requestHeader.status;
#endif
        bits |= 1 << i;
    }
#ifdef BBPLAYER
    if (__osBbIsBb && __osBbHackFlags != 0) {
        OSContStatus tmp;

        bits = (bits & ~((1 << __osBbHackFlags) | 1)) | ((bits & 1) << __osBbHackFlags) | ((bits & (1 << __osBbHackFlags)) >> __osBbHackFlags);

        data -= __osMaxControllers;

        tmp = data[0];
        data[0] = data[__osBbHackFlags];
        data[__osBbHackFlags] = tmp;
    }
#endif

    *pattern = bits;
}

void __osPackRequestData(u8 cmd) {
    u8* ptr;
    __OSContRequesFormat requestHeader;
    s32 i;

    for (i = 0; i < ARRLEN(__osContPifRam.ramarray); i++) {
        __osContPifRam.ramarray[i] = 0;
    }

    __osContPifRam.pifstatus = CONT_CMD_EXE;
    ptr = (u8*)__osContPifRam.ramarray;
    requestHeader.dummy = CONT_CMD_NOP;
    requestHeader.txsize = CONT_CMD_RESET_TX;
    requestHeader.rxsize = CONT_CMD_RESET_RX;
    requestHeader.cmd = cmd;
    requestHeader.typeh = CONT_CMD_NOP;
    requestHeader.typel = CONT_CMD_NOP;
    requestHeader.status = CONT_CMD_NOP;
    requestHeader.dummy1 = CONT_CMD_NOP;

    for (i = 0; i < __osMaxControllers; i++) {
        *(__OSContRequesFormat*)ptr = requestHeader;
        ptr += sizeof(requestHeader);
    }
    *ptr = CONT_CMD_END;
}
