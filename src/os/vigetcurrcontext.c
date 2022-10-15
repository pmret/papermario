#include "PR/os_internal.h"
#include "PR/viint.h"

__OSViContext *__osViGetCurrentContext(void) {
    return __osViCurr;
}
