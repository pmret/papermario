#include "common.h"
#include "nu/nusys.h"

void nuContDataLock(void) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuContDataLockKey = NU_CONT_DATA_LOCK;
    osSetIntMask(mask);
}

void nuContDataUnLock(void) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuContDataLockKey = NU_CONT_DATA_UNLOCK;
    osSetIntMask(mask);
}
