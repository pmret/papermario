#include "common.h"
#include "controller.h"

INCLUDE_ASM(s32, "os/motor", __osMotorAccess, OSPfs* pfs, s32 unk);

INCLUDE_ASM(s32, "os/motor", osMotorInit, OSMesgQueue* queue, OSPfs* pfs, int unk);
