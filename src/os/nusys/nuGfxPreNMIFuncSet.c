#include "common.h"
#include "nu/nusys.h"

void nuGfxPreNMIFuncSet(NUGfxPreNMIFunc func) {
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);

    nuGfxPreNMIFunc = func;
    osSetIntMask(intMask);
}
