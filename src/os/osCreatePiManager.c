#include "common.h"

OSDevMgr __osPiDevMgr = {0};
OSPiHandle* __osPiTable = NULL;

extern OSPiHandle CartRomHandle;
extern OSPiHandle LeoDiskHandle;
OSPiHandle *__osCurrentHandle[2] = {&CartRomHandle, &LeoDiskHandle};

INCLUDE_ASM(void, "os/osCreatePiManager", osCreatePiManager, OSPri prio, OSMesgQueue* queue, OSMesg* mesg, s32 unk);

INCLUDE_ASM(s32, "os/osCreatePiManager", osEPiRawStartDma, OSPiHandle *arg0, s32 dir, u32 cart_addr, void *dram_addr, u32 size);
