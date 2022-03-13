#include "macros.h"
#include "PR/controller.h"
#include "PR/siint.h"

s32 osPfsCheckRamArea(OSPfs *pfs);

s32 osPfsNumFiles(OSPfs *pfs, s32 *max_files, s32 *files_used) {
    int j;
    s32 ret;
    __OSDir dir;
    int files;
    files = 0;
    PFS_CHECK_STATUS;
    ERRCK(__osCheckId(pfs));
    SET_ACTIVEBANK_TO_ZERO;
    for (j = 0; j < pfs->dir_size; j++) {
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&dir));
        if (dir.company_code != 0 && dir.game_code != 0) {
            files++;
        }
    }
    *files_used = files;
    *max_files = pfs->dir_size;
    ret = __osPfsGetStatus(pfs->queue, pfs->channel);
    return ret;
}

s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel) {
    int k;
    s32 ret;
    u16 sum;
    u16 isum;
    u8 temp[32];
    __OSPackId *id;
    __OSPackId newid;
    PFS_GET_STATUS;
    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    ERRCK(osPfsCheckRamArea(pfs));
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

s32 osPfsCheckRamArea(OSPfs *pfs) {
    u8 temp1[32];
    u8 temp2[32];
    u8 temp3[32];
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
