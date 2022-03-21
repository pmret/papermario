#include "PR/controller.h"
#include "macros.h"

s32 __osPfsSelectBank(OSPfs *pfs, u8 bank) {
    u8 temp[BLOCKSIZE];
    int i;
    s32 ret;
    for (i = 0; i < ARRAY_COUNT(temp); i++) {
        temp[i] = bank;
    }
    ret = __osContRamWrite(pfs->queue, pfs->channel, 1024, (u8*)temp, FALSE);
    if (ret == 0) {
        pfs->activebank = bank;
    }
    return ret;
}
