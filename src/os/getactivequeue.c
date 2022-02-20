#include "PR/osint.h"

OSThread *__osGetActiveQueue(void) {
    return __osActiveQueue;
}
