#include "common.h"
#include "nu/nusys.h"

void nuContRmbModeSet(u32 contNo, u8 mode) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);
    s32 forceStop = nuContRmbCtl[contNo].mode & NU_CONT_RMB_MODE_PAUSE;

    switch (mode) {
        case NU_CONT_RMB_MODE_DISABLE:
            nuContRmbCtl[contNo].mode = mode | forceStop;
            break;
        case NU_CONT_RMB_MODE_ENABLE:
            if (nuContRmbCtl[contNo].type == NU_CONT_PAK_TYPE_RUMBLE) {
                nuContRmbCtl[contNo].mode = mode | forceStop;
            }
            break;
        case NU_CONT_RMB_MODE_AUTORUN:
            nuContRmbCtl[contNo].mode = mode | forceStop;
            if (nuContRmbCtl[contNo].type == NU_CONT_PAK_TYPE_RUMBLE) {
                nuContRmbCtl[contNo].autorun = NU_CONT_RMB_AUTO_FIND;
            } else {
                nuContRmbCtl[contNo].autorun = NU_CONT_RMB_AUTO_SEARCH;
            }
            break;
    }
    osSetIntMask(mask);
}
