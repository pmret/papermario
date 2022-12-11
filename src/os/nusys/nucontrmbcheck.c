#include "common.h"
#include "nu/nusys.h"

s32 nuContRmbCheck(u32 contNo) {
    NUContRmbMesg mesg;
    s32 err;
    OSIntMask mask;

    mesg.contNo = contNo;
    err = nuSiSendMesg(NU_CONT_RMB_CHECK_MSG, &mesg);
    mask = osSetIntMask(1);

    if (err == 0) {
        nuContRmbCtl[contNo].type = NU_CONT_PAK_TYPE_RUMBLE;
    } else {
        nuContRmbCtl[contNo].type = NU_CONT_PAK_TYPE_NONE;
    }
    osSetIntMask(mask);

    return err;
}
