#include "common.h"

#ifndef KMC_ASM
u32 osVirtualToPhysical(void *addr) {
    if (IS_KSEG0(addr)) {
        return K0_TO_PHYS(addr);
    } else if (IS_KSEG1(addr)) {
        return K1_TO_PHYS(addr);
    } else {
        return __osProbeTLB(addr);
    }
}
#else
INCLUDE_ASM_LIBULTRA(u32, "osVirtualToPhysical", osVirtualToPhysical, void* virt);
#endif
