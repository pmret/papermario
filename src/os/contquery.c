#include "PR/controller.h"
#include "PR/siint.h"

s32 osContStartQuery(OSMesgQueue* mq) {
    s32 ret;

    __osSiGetAccess();
    if (__osContLastCmd != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, &__osContPifRam);
        osRecvMesg(mq, NULL, 1);
    }
    ret = __osSiRawStartDma(0, &__osContPifRam);
#if VERSION_IQUE
    __osContLastCmd = 0xFD;
#else
    __osContLastCmd = 0;
#endif
    __osSiRelAccess();

    return ret;
}

void osContGetQuery(OSContStatus *data) {
    u8 pattern;
    __osContGetInitData(&pattern, data);
}
