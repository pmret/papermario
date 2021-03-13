#define MOVE_ADDU

#include "common.h"

s32 osEPiStartDma(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction) {
    if (!__osPiDevMgr.active) {
        return -1;
    }

    mb->piHandle = pihandle;

    if (direction == OS_READ) {
        mb->hdr.type = OS_MESG_TYPE_EDMAREAD;
    } else {
        mb->hdr.type = OS_MESG_TYPE_EDMAWRITE;
    }

    if (mb->hdr.pri != OS_MESG_PRI_HIGH) {
        return osSendMesg(osPiGetCmdQueue(), mb, 0);
    } else {
        return osJamMesg(osPiGetCmdQueue(), mb, 0);
    }
}
