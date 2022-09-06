#include "ultra64.h"
#include "include_asm.h"

INCLUDE_ASM(void, "os/vimgr", osCreateViManager, OSPri pri);

INCLUDE_ASM(s32, "os/vimgr", viMgrMain);
