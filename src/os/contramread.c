#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/controller.h"
#include "PR/siint.h"

extern u32 __osBbPakAddress[4];
extern u32 __osBbPakSize;

#ifndef BBPLAYER
s32 __osPfsLastChannel = -1;
#endif

#define READFORMAT(ptr) ((__OSContRamReadFormat*)(ptr))

s32 __osContRamRead(OSMesgQueue* mq, int channel, u16 address, u8* buffer) {
#ifdef BBPLAYER
    s32 ret;

    __osSiGetAccess();

    ret = 0;
    if (__osBbPakAddress[channel] != 0) {
        if (__osBbPakSize - 0x20 >= address * 0x20) {
            int i;

            for (i = 0; i < 0x20; i++) {
                buffer[i] = *(u8*)(__osBbPakAddress[channel] + address * 0x20 + i);
            }
        }
    } else {
        ret = 1;
    }

    __osSiRelAccess();

    return ret;
#else
    s32 ret = 0;
    s32 i;
    u8* ptr;
    s32 retry = 2;

    __osSiGetAccess();

    do {
        ptr = (u8*)&__osPfsPifRam;

        if (__osContLastCmd != CONT_CMD_READ_PAK || (u32)__osPfsLastChannel != channel) {
            __osContLastCmd = CONT_CMD_READ_PAK;
            __osPfsLastChannel = channel;

            for (i = 0; i < channel; i++) { *ptr++ = CONT_CMD_REQUEST_STATUS; }

            __osPfsPifRam.pifstatus = CONT_CMD_EXE;

            READFORMAT(ptr)->dummy = CONT_CMD_NOP;
            READFORMAT(ptr)->txsize = CONT_CMD_READ_PAK_TX;
            READFORMAT(ptr)->rxsize = CONT_CMD_READ_PAK_RX;
            READFORMAT(ptr)->cmd = CONT_CMD_READ_PAK;
            READFORMAT(ptr)->datacrc = 0xFF;

            ptr[sizeof(__OSContRamReadFormat)] = CONT_CMD_END;
        } else {
            ptr += channel;
        }

        READFORMAT(ptr)->addrh = address >> 3;
        READFORMAT(ptr)->addrl = (u8)((address << 5) | __osContAddressCrc(address));

        ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ret = CHNL_ERR(*READFORMAT(ptr));

        if (!ret) {
            if (__osContDataCrc(READFORMAT(ptr)->data) != READFORMAT(ptr)->datacrc) {
                ret = __osPfsGetStatus(mq, channel);

                if (ret) {
                    break;
                } else {
                    ret = PFS_ERR_CONTRFAIL;
                }
            } else {
                bcopy(READFORMAT(ptr)->data, buffer, BLOCKSIZE);
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while ((ret == PFS_ERR_CONTRFAIL) && (retry-- >= 0));
    __osSiRelAccess();
    return ret;
#endif
}
