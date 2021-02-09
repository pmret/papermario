#include "common.h"
#include "nu/nusys.h"

void nuContRmbForceStop(void) {
    nuSiSendMesg(NU_CONT_RMB_FORCESTOP_MSG, NULL);
}

void nuContRmbForceStopEnd(void) {
    nuSiSendMesg(NU_CONT_RMB_FORCESTOPEND_MSG, NULL);
}

INCLUDE_ASM(void, "os/nusys/code_3B4A0", nuPiReadRomOverlay, NUPiOverlaySegment* segment);
