#include "common.h"
#include "nu/nusys.h"

u8 nuContInit(void) {
    u8 contBits = nuSiMgrInit();

    nuContMgrInit();
    nuContPakMgrInit();
    nuContRmbMgrInit();
    return contBits;
}
