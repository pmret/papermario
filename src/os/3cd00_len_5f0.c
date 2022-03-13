#define MOVE_ADDU

#include "common.h"
#include "PR/controller.h"
#include "PR/siint.h"

extern s32 D_800B0ED0;

s32 osContStartQuery(OSMesgQueue* mq) {
    s32 ret;

    __osSiGetAccess();
    if (__osContLastCmd != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, &D_800B0ED0);
        osRecvMesg(mq, NULL, 1);
    }
    ret = __osSiRawStartDma(0, &D_800B0ED0);
    __osContLastCmd = 0;
    __osSiRelAccess();

    return ret;
}

INCLUDE_ASM(void, "os/3cd00_len_5f0", osContGetQuery, OSContStatus* status);

INCLUDE_ASM(s32, "os/3cd00_len_5f0", osContStartReadData, OSMesgQueue* queue);

INCLUDE_ASM(void, "os/3cd00_len_5f0", osContGetReadData, OSContPad* pad);

INCLUDE_ASM(s32, "os/3cd00_len_5f0", osPackReadData);
