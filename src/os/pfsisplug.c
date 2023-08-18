#include "macros.h"
#include "PR/os_internal.h"
#include "PR/controller.h"
#include "PR/siint.h"

extern u32 __osBbIsBb;
extern u32 __osBbHackFlags;
extern u32 __osBbPakAddress[4];

OSPifRam __osPfsPifRam BBALIGNED(16);

s32 osPfsIsPlug(OSMesgQueue* mq, u8* pattern) {
    s32 ret = 0;
    OSMesg dummy;
    u8 bitpattern;
    OSContStatus data[MAXCONTROLLERS];
    int channel;
#ifdef BBPLAYER
    int crc_error_cnt = 3;
    u8 bits = 0;
#else
    u8 bits = 0;
    s32 crc_error_cnt = 3;
#endif

    __osSiGetAccess();

    do {
        __osPfsRequestData(CONT_CMD_REQUEST_STATUS);

        ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
        osRecvMesg(mq, &dummy, OS_MESG_BLOCK);

        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, &dummy, OS_MESG_BLOCK);

        __osPfsGetInitData(&bitpattern, &data[0]);

        for (channel = 0; channel < __osMaxControllers; channel++) {
            if ((data[channel].status & CONT_ADDR_CRC_ER) == 0) {
                crc_error_cnt--;
                break;
            }
        }

        if (channel == __osMaxControllers) {
            crc_error_cnt = 0;
        }
    } while (crc_error_cnt > 0);

    for (channel = 0; channel < __osMaxControllers; channel++) {
        if ((data[channel].errno == 0) && ((data[channel].status & CONT_CARD_ON) != 0)) {
            bits |= (1 << channel);
        }
    }
    __osSiRelAccess();
    *pattern = bits;
    return ret;
}

void __osPfsRequestData(u8 cmd) {
    u8* ptr = (u8*)&__osPfsPifRam;
    __OSContRequesFormat requestformat;
    int i;

    __osContLastCmd = cmd;
    __osPfsPifRam.pifstatus = CONT_CMD_EXE;
    requestformat.dummy = CONT_CMD_NOP;
    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
    requestformat.cmd = cmd;
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;
    requestformat.dummy1 = CONT_CMD_NOP;

    for (i = 0; i < __osMaxControllers; i++) {
        *((__OSContRequesFormat*)ptr) = requestformat;
        ptr += sizeof(__OSContRequesFormat);
    }

    *ptr = CONT_CMD_END;
}

void __osPfsGetInitData(u8* pattern, OSContStatus* data) {
    u8* ptr;
    __OSContRequesFormat requestformat;
    int i;
    u8 bits = 0;

    ptr = (u8*)&__osPfsPifRam;

    for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(requestformat), data++) {
        requestformat = *((__OSContRequesFormat*)ptr);
        data->errno = CHNL_ERR(requestformat);

        if (data->errno != 0) {
            continue;
        }

        data->type = ((requestformat.typel << 8) | requestformat.typeh);
#ifdef BBPLAYER
        data->status = __osBbPakAddress[i] != 0;
#else
        data->status = requestformat.status;
#endif
        bits |= (1 << i);
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
