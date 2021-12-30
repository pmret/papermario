#include "common.h"

#ifndef KMC_ASM
s16 coss(u16 angle) {
    return sins(angle + 0x4000);
}
#else
INCLUDE_ASM_LIBULTRA(s16, "coss", coss, u16 angle);
#endif
