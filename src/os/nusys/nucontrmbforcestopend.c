#include "common.h"
#include "nu/nusys.h"

void nuContRmbForceStopEnd(void) {
    nuSiSendMesg(NU_CONT_RMB_FORCESTOPEND_MSG, NULL);
}
