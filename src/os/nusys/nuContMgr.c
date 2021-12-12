#include "common.h"
#include "nu/nusys.h"

s32 contRetrace();
s32 contReadData();
s32 contReadNW();
s32 contQuery();

u32 D_80093D20 = 0;

UNK_FUN_PTR(D_80093D24[4]) = {
    contRetrace,
    contReadData,
    contReadNW,
    contQuery,
};

s32 D_80093D34 = 0;

NUCallBackList nuContCallBack = {
    NULL,
    D_80093D24,
    0x100,
    0,
};

// BSS
extern OSMesg nuContWaitMesgBuf;
extern OSMesg nuContDataMutexBuf;
extern OSMesgQueue nuContDataMutexQ;

u8 nuContMgrInit(void) {
    s32 i;
    u8 pattern;
    u8 bitmask;

    nuContDataUnLock();
    osCreateMesgQueue(&nuContWaitMesgQ, &nuContWaitMesgBuf, 1);
    osCreateMesgQueue(&nuContDataMutexQ, &nuContDataMutexBuf, 1);
    nuSiCallBackAdd(&nuContCallBack);
    nuContQueryRead();

    nuContNum = 0;
    bitmask = 1;
    pattern = 0;

    for (i = 0; i < NU_CONT_MAXCONTROLLERS; i++) {
        if (nuContStatus[i].errno != 0) {
            continue;
        }

        if ((nuContStatus[i].type & CONT_TYPE_MASK) == CONT_TYPE_NORMAL) {
            nuContNum++;
            pattern |= bitmask;
        }
        bitmask <<= 1;
    }

    return pattern;
}

void nuContMgrRemove(void) {
    nuSiCallBackRemove(&nuContCallBack);
}

void nuContDataClose(void) {
    osSendMesg(&nuContDataMutexQ, NULL, OS_MESG_BLOCK);

}

void nuContDataOpen(void) {
    osRecvMesg(&nuContDataMutexQ, NULL, OS_MESG_BLOCK);
}

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contRetrace);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contReadData);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contReadNW);

// nuContStatus needs to be declared in this file.
#ifdef NON_MATCHING
s32 contQuery(void) {
    s32 ret = osContStartQuery(&nuSiMesgQ);

    if (ret != 0) {
        return ret;
    }

    osRecvMesg(&nuSiMesgQ, NULL, OS_MESG_BLOCK);
    osContGetQuery(nuContStatus);

    return ret;
}
#else
INCLUDE_ASM(s32, "os/nusys/nuContMgr", contQuery);
#endif
