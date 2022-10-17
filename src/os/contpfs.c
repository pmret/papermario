#include "PR/controller.h"
#include "macros.h"

extern __OSInode __osPfsInodeCache;
s32 __osPfsInodeCacheChannel = -1;
u8 __osPfsInodeCacheBank = 250;

u16 __osSumcalc(u8 *ptr, int length) {
    int i;
    s32 sum;
    u8* tmp;
    sum = 0;
    tmp = ptr;
    for (i = 0; i < length; i++) {
        sum += *tmp++;
    }
    return sum;
}

s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum) {
    u16 data;
    u32 j;
    data = 0;
    *icsum = 0;
    *csum = *icsum;
    for (j = 0; j < 28; j += 2) {
        data = *(u16 *)((u8 *)ptr + j);
        *csum += data;
        *icsum += ~data;
    }
    return 0;
}
s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid) {
    s32 ret;
    u8 temp[BLOCKSIZE];
    u8 comp[BLOCKSIZE];
    u8 mask;
    int i;
    int j;
    u16 index[4];

    //ret = 0;
    //mask = 0;

    newid->repaired = -1;
    newid->random = osGetCount();
    newid->serial_mid = badid->serial_mid;
    newid->serial_low = badid->serial_low;
    j = 0;
    SET_ACTIVEBANK_TO_ZERO;

    do {
        ERRCK(__osPfsSelectBank(pfs, j))
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp));
        temp[0] = j | 0x80;
        for (i = 1; i < ARRAY_COUNT(temp); i++) {
            temp[i] = ~temp[i];
        }

        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, temp, FALSE));
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, comp));

        for (i = 0; i < ARRAY_COUNT(temp); i++) {
            if (comp[i] != temp[i]) {
                break;
            }
        }
        if (i != ARRAY_COUNT(temp)) {
            break;
        }
        if (j > 0) {
            ERRCK(__osPfsSelectBank(pfs, 0));
            ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)temp));
            if (temp[0] != 128) {
                break; //TODO: remove magic constant
            }
        }
        j++;
    } while (j < PFS_MAX_BANKS);

    SET_ACTIVEBANK_TO_ZERO;
    if (j > 0) {
        mask = 1;
    } else {
        mask = 0;
    }
    newid->deviceid = (badid->deviceid & (u16)~1) | mask;
    newid->banks = j;
    newid->version = badid->version;
    __osIdCheckSum((u16*)newid, &newid->checksum, &newid->inverted_checksum);
    index[0] = PFS_ID_0AREA;
    index[1] = PFS_ID_1AREA;
    index[2] = PFS_ID_2AREA;
    index[3] = PFS_ID_3AREA;
    for (i = 0; i < ARRAY_COUNT(index); i++) {
        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[i], (u8*)newid, TRUE));
    }
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
    for (i = 0; i < ARRAY_COUNT(temp); i++) {
        if (temp[i] != ((u8 *)newid)[i]) {
            return PFS_ERR_DEVICE;
        }
    }
    return 0;
}

s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp) {
    u16 index[4];
    s32 ret;
    u16 sum;
    u16 isum;
    int i;
    int j;

    ret = 0;
    SET_ACTIVEBANK_TO_ZERO;
    index[0] = PFS_ID_0AREA;
    index[1] = PFS_ID_1AREA;
    index[2] = PFS_ID_2AREA;
    index[3] = PFS_ID_3AREA;
    for (i = 1; i < ARRAY_COUNT(index); i++) {
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, index[i], (u8*)temp));
        __osIdCheckSum((u16 *)temp, &sum, &isum);
        if (temp->checksum == sum && temp->inverted_checksum == isum)
            break;
    }
    if (i == ARRAY_COUNT(index)) {
        return PFS_ERR_ID_FATAL;
    }

    for (j = 0; j < ARRAY_COUNT(index); j++) {
        if (j != i) {
            ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[j], (u8*)temp, TRUE));
        }
    }
    return 0;
}

s32 __osGetId(OSPfs *pfs) {
    int k;
    u16 sum;
    u16 isum;
    u8 temp[BLOCKSIZE];
    __OSPackId newid;
    s32 ret;
    __OSPackId *id;

    SET_ACTIVEBANK_TO_ZERO;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
    __osIdCheckSum((u16*)temp, &sum, &isum);
    id = (__OSPackId*)temp;
    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, id);
        if (ret == PFS_ERR_ID_FATAL) {
            ERRCK(__osRepairPackId(pfs, id, &newid));
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }
    if ((id->deviceid & 1) == 0) {  //TODO: remove magic constant
        ERRCK(__osRepairPackId(pfs, id, &newid));
        id = &newid;
        if ((id->deviceid & 1) == 0) {
            return PFS_ERR_DEVICE;
        }
    }
    bcopy(id, pfs->id, ARRAY_COUNT(pfs->id));
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = pfs->banks * 2 + 3; //TODO: loads of magic constants..
    pfs->dir_size = 16;
    pfs->inode_table = 8;
    pfs->minode_table = (pfs->banks + 1) * PFS_ONE_PAGE;
    pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));
    return 0;
}

s32 __osCheckId(OSPfs *pfs) {
    u8 temp[BLOCKSIZE];
    s32 ret;

    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret == PFS_ERR_NEW_PACK) {
            ret = __osPfsSelectBank(pfs, 0);
        }
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        if (ret != PFS_ERR_NEW_PACK) {
            return ret;
        } else {
            ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, temp));
        }
    }

    if (bcmp(pfs->id, temp, BLOCKSIZE) != 0) {
        return PFS_ERR_NEW_PACK;
    }

    return 0;
}

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank) {
    u8 sum;
    int j;
    s32 ret;
    int offset;
    u8 *addr;

    if (flag == PFS_READ && bank == __osPfsInodeCacheBank && pfs->channel == __osPfsInodeCacheChannel) {
        bcopy(&__osPfsInodeCache, inode, sizeof(__OSInode));
        return 0;
    }

    SET_ACTIVEBANK_TO_ZERO;

    if (bank > 0) {
        offset = 1;
    } else {
        offset = pfs->inode_start_page;
    }

    if (flag == PFS_WRITE) {
        inode->inode_page[0].inode_t.page = __osSumcalc((u8*)&inode->inode_page[offset], (128 - offset) * 2);
    }

    for (j = 0; j < PFS_ONE_PAGE; j++) {
        addr = ((u8 *)inode->inode_page + j * 32);
        if (flag == PFS_WRITE) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == PFS_READ) {
        sum = __osSumcalc((u8*)&inode->inode_page[offset], (128 - offset) * 2);
        if (sum != inode->inode_page[0].inode_t.page) {
            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr);
            }
            sum = __osSumcalc((u8*)&inode->inode_page[offset], (128 - offset) * 2);
            if (sum != inode->inode_page[0].inode_t.page) {
                return PFS_ERR_INCONSISTENT;
            }
            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
            }
        }
    }
    __osPfsInodeCacheBank = bank;
    bcopy(inode, &__osPfsInodeCache, sizeof(__OSInode));
    __osPfsInodeCacheChannel = pfs->channel;
    return 0;
}

