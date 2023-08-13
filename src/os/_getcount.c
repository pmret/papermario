#include "ultra64.h"
#include "macros.h"
#include "PR/os_internal.h"

#ifdef BBPLAYER
u32 __osBbLastRCount;
u32 __osBbRCountWraps;
u32 __osBbLastVCount;
u32 __osBbVCountWraps;

u32 osGetCount(void) {
    u32 count;
    u32 mask;

    mask = __osDisableInt();

    __asm__("mfc0 %0, $9" : "=r"(count));

    if (count < __osBbLastRCount) {
        __osBbRCountWraps++;
    }
    __osBbLastRCount = count;

    count = (((u64)__osBbRCountWraps << 32) | count) * 125ull / 192ull;

    if (count < __osBbLastVCount) {
        __osBbVCountWraps++;
    }
    __osBbLastVCount = count;

    __osRestoreInt(mask);

    return count;
}
#endif
