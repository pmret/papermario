#include "common.h"
#include "nu/nusys.h"

void nuContRmbForceStop(void) {
    nuSiSendMesg(NU_CONT_RMB_FORCESTOP_MSG, NULL);
}
