#include "macros.h"
#include "PR/controller.h"
#include "PR/siint.h"

s32 __osPfsCheckRamArea(OSPfs *pfs);

s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel) {
    int k;
    s32 ret;
    u16 sum;
    u16 isum;
    u8 temp[BLOCKSIZE];
    __OSPackId *id;
    __OSPackId newid;
    PFS_GET_STATUS;
    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    ERRCK(__osPfsCheckRamArea(pfs));
    ERRCK(__osPfsSelectBank(pfs, 0));
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
    __osIdCheckSum((u16*)temp, &sum, &isum);
    id = (__OSPackId *)temp;
    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, id);
        if (ret != 0) {
            pfs->status |= PFS_ID_BROKEN;
            return ret;
        }
    }
    if ((id->deviceid & 1) == 0) {
        ret = __osRepairPackId(pfs, id, &newid);
        if (ret != 0) {
            if (ret == PFS_ERR_ID_FATAL) {
                pfs->status |= PFS_ID_BROKEN;
            }
            return ret;
        }
        id = &newid;
        if ((id->deviceid & 1) == 0) {
            return PFS_ERR_DEVICE;
        }
    }
    bcopy(id, pfs->id, ARRAY_COUNT(pfs->id));
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = pfs->banks * 2 + 3;
    pfs->dir_size = 0x10;
    pfs->inode_table = 8;
    pfs->minode_table = (pfs->banks + 1) * PFS_ONE_PAGE;
    pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));
    ret = osPfsChecker(pfs);
    pfs->status |= PFS_INITIALIZED;
    return ret;
}

s32 __osPfsCheckRamArea(OSPfs *pfs) {
    u8 temp1[BLOCKSIZE];
    u8 temp2[BLOCKSIZE];
    u8 temp3[BLOCKSIZE];
    s32 i;
    s32 ret;
    ERRCK(__osPfsSelectBank(pfs, 0));
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp3));
    for (i = 0; i < ARRAY_COUNT(temp1); i++) {
        temp1[i] = i;
    }
    ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, temp1, FALSE));
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp2));
    if (bcmp(temp1, temp2, ARRAY_COUNT(temp1)) != 0) {
        return PFS_ERR_DEVICE;
    }
    ret = __osContRamWrite(pfs->queue, pfs->channel, 0, temp3, FALSE);
    return ret;
}
