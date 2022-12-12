#include "common.h"
#include "nu/nusys.h"

void nuContRmbStart(u32 contNo, u16 freq, u16 frame) {
    NUContRmbCtl ctl;
    NUContRmbMesg mesg;

    if (!(nuContRmbCtl[contNo].mode & NU_CONT_RMB_MODE_PAUSE)) {
        ctl.state = NU_CONT_RMB_STATE_RUN;
        ctl.freq = freq;
        ctl.frame = frame;
        mesg.data = &ctl;
        mesg.contNo = contNo;
        nuSiSendMesg(NU_CONT_RMB_START_MSG, &mesg);
    }
}
