#include "ultra64.h"
#include "include_asm.h"

u32 __osContinitialized = 0;

INCLUDE_ASM(s32, "os/controller", osContInit, OSMesgQueue* arg0, u8* arg1, OSContStatus* arg2);

INCLUDE_ASM(s32, "os/controller", osContGetInitData);

INCLUDE_ASM(s32, "os/controller", osPackRequestData);
