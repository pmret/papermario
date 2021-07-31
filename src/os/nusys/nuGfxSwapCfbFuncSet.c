#include "common.h"
#include "nu/nusys.h"

void nuGfxSwapCfbFuncSet(NUGfxSwapCfbFunc func) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuGfxSwapCfbFunc = func;
    osSetIntMask(mask);
}
