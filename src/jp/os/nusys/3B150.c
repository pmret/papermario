#include "common.h"
#include "nu/nusys.h"

// TODO
#define nuSiSendMesg func_800602C8

void nuContRmbForceStop(void) {
    nuSiSendMesg(NU_CONT_RMB_FORCESTOP_MSG, NULL);
}

INCLUDE_ASM(s32, "os/nusys/3B150", func_8005FD70);

INCLUDE_ASM(s32, "os/nusys/3B150", func_8005FD90);
