#include "dgb_01.h"
#include "ld_addrs.h"

ApiStatus N(func_80240000_BFD880)(void) {
    dma_copy(C20F40_ROM_START, C20F40_ROM_END, C20F40_VRAM);
    return ApiStatus_DONE2;
}
