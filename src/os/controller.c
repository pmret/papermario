#include "common.h"

u32 __osContinitialized = 0;

INCLUDE_ASM(s32, "controller", osContInit, OSMesgQueue* arg0, u8* arg1, OSContStatus* arg2);

INCLUDE_ASM(s32, "controller", osContGetInitData);

INCLUDE_ASM(s32, "controller", osPackRequestData);
