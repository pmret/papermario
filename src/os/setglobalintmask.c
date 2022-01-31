#include "PR/os_internal.h"

void __osSetGlobalIntMask(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __OSGlobalIntMask |= mask;

    __osRestoreInt(saveMask);
}
