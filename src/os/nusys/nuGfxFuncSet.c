#include "common.h"
#include "nu/nusys.h"

NUGfxFunc nuGfxFunc = NULL;

void nuGfxFuncSet(NUGfxFunc func) {
    OSIntMask intMask;

    nuGfxTaskAllEndWait();
    intMask = osSetIntMask(OS_IM_NONE);
    nuGfxFunc = func;
    osSetIntMask(intMask);
}
