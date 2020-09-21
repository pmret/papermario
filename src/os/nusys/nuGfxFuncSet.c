#include "common.h"
#include "nu/nusys.h"

void nuGfxFuncSet(NUGfxFunc func) {
    OSIntMask intMask;

    nuGfxTaskAllEndWait();
    intMask = osSetIntMask(OS_IM_NONE);
    nuGfxFunc = func;
    osSetIntMask(intMask);
}
