#include "common.h"
#include "nu/nusys.h"

void nuContDataGet(OSContPad* contdata, u32 padno) {
    nuContDataClose();
    bcopy(&nuContData[padno], contdata, sizeof(OSContPad));
    nuContDataOpen();
}
