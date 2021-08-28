#include "common.h"

s32 osSiDeviceBusy(void) {
    // in oot, status is HW_REG(EVT_STATUS_REG, u32);
    // however, this macro doesn't exist in our libultra version apparently
    u32 status = *(volatile u32*)(EVT_STATUS_REG | 0xA0000000);

    if (status & (EVT_STATUS_DMA_BUSY | EVT_STATUS_RD_BUSY)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
