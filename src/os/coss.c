#include "common.h"
#include "include_asm_libultra.h"

#ifndef KMC_ASM
s16 coss(u16 angle) {
    return sins(angle + 0x4000);
}
#else
INCLUDE_ASM_LIBULTRA("coss", coss);
#endif
