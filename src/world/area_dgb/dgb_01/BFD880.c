#include "dgb_01.h"

ApiStatus func_80240000_BFD880(void) {
    dma_copy(&data_C20F40_ROM_START, &data_C20F40_ROM_END, &gBackgroundImage);
    return ApiStatus_DONE2;
}
