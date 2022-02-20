#include "PR/os_internal.h"

s32 osAfterPreNMI(void) {
    return __osSpSetPc(0);
}
