#include "PR/controller.h"

extern u8 __osPfsInodeCacheBank;

void __osPfsRequestOneChannel(int channel, u8 cmd);
void __osPfsGetOneChannelData(int channel, OSContStatus *data);

s32 __osPfsGetStatus(OSMesgQueue *queue, int channel) {
    s32 ret;
    OSMesg dummy;
    OSContStatus data;
    __osPfsInodeCacheBank = 0xfa;
    ret = 0;
    __osPfsRequestOneChannel(channel, 0);
    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    __osPfsGetOneChannelData(channel, &data);
    if (((data.status & CONT_CARD_ON) != 0) && ((data.status & CONT_CARD_PULL) != 0)) {
        return PFS_ERR_NEW_PACK;
    }
    if ((data.errno != 0) || ((data.status & CONT_CARD_ON) == 0)) {
        return PFS_ERR_NOPACK;
    }
    if ((data.status & CONT_ADDR_CRC_ER) != 0) {
        return PFS_ERR_CONTRFAIL;
    }
    return ret;
}

void __osPfsRequestOneChannel(int channel, u8 cmd) {
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    int i;

    __osContLastCmd = CONT_CMD_END;
    __osPfsPifRam.pifstatus = CONT_CMD_EXE;
    ptr = (u8 *)&__osPfsPifRam;

    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
    requestformat.cmd = cmd;
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;
    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }

    *(__OSContRequesFormatShort *)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormatShort);
    *ptr = CONT_CMD_END;
}

void __osPfsGetOneChannelData(int channel, OSContStatus *data) {
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    int i;
    ptr = (u8*)&__osPfsPifRam;
    for (i = 0; i < channel; i++) {
        ptr++;
    }
    requestformat = *(__OSContRequesFormatShort *)ptr;
    data->errno = CHNL_ERR(requestformat);
    if (data->errno == 0) {
        data->type = (requestformat.typel << 8) | (requestformat.typeh);
        data->status = requestformat.status;
    }
}
