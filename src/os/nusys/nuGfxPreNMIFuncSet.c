#include "common.h"
#include "nu/nusys.h"

NUGfxPreNMIFunc nuGfxPreNMIFunc = NULL;

void nuGfxPreNMIFuncSet(NUGfxPreNMIFunc func) {
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);

    nuGfxPreNMIFunc = func;
    osSetIntMask(intMask);
}
