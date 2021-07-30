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

INCLUDE_ASM(u8, "os/nusys/nuContMgr", nuContMgrInit);

INCLUDE_ASM(void, "os/nusys/nuContMgr", nuContMgrRemove);

INCLUDE_ASM(void, "os/nusys/nuContMgr", nuContDataClose);

INCLUDE_ASM(void, "os/nusys/nuContMgr", nuContDataOpen);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contRetrace);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contReadData);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contReadNW);

INCLUDE_ASM(s32, "os/nusys/nuContMgr", contQuery);

INCLUDE_ASM(void, "os/nusys/nuContMgr", nuContDataLock);

INCLUDE_ASM(void, "os/nusys/nuContMgr", nuContDataUnLock);
