#include "common.h"
#include "nu/nusys.h"

NUGfxPreNMIFunc	nuGfxPreNMIFunc = NULL;
u32 D_80093D18[2] = { 0 }; // Possibly Padding

void nuGfxPreNMIFuncSet(NUGfxPreNMIFunc func) {
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);

    nuGfxPreNMIFunc = func;
    osSetIntMask(intMask);
}
