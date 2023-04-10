#include "PR/controller.h"
#include "PR/osint.h"
#include "PR/siint.h"

extern int __osPfsLastChannel;

s32 __osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force) {
    s32 ret;
    u8* ptr;
    s32 i;
    int retry = 2;
    u8 crc;

    if (force != PFS_FORCE && address < PFS_LABEL_AREA && address != 0) {
        return 0;
    }

    __osSiGetAccess();
    do {
        ptr = (u8 *)(&__osPfsPifRam);

        if (__osContLastCmd != CONT_CMD_WRITE_MEMPACK || __osPfsLastChannel != channel) {
            __osContLastCmd = CONT_CMD_WRITE_MEMPACK;
            __osPfsLastChannel = channel;

            for (i = 0; i < channel; i++) {
                *ptr++ = 0;
            }

            __osPfsPifRam.pifstatus = CONT_CMD_EXE;
            ((__OSContRamReadFormat *)ptr)->dummy = 0xff;
            ((__OSContRamReadFormat *)ptr)->txsize = 35;
            ((__OSContRamReadFormat *)ptr)->rxsize = 1;
            ((__OSContRamReadFormat *)ptr)->cmd = CONT_CMD_WRITE_MEMPACK;
            ((__OSContRamReadFormat *)ptr)->datacrc = 0xff;
            ptr[sizeof(__OSContRamReadFormat)] = CONT_CMD_END;
        } else {
            ptr += channel;
        }
        ((__OSContRamReadFormat *)ptr)->addrh = address >> 3;
        ((__OSContRamReadFormat *)ptr)->addrl = (address << 5) | __osContAddressCrc(address);

        bcopy(buffer, ((__OSContRamReadFormat *)ptr)->data, BLOCKSIZE);

        ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
        crc = __osContDataCrc(buffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ret = (((__OSContRamReadFormat *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (crc != ((__OSContRamReadFormat *)ptr)->datacrc) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret != 0) {
                    break;
                } else {
                    ret = PFS_ERR_CONTRFAIL;
                }
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && retry-- >= 0);

    __osSiRelAccess();
    return ret;
}
