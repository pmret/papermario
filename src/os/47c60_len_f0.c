#define MOVE_ADDU

#include "common.h"

INCLUDE_ASM(s32, "os/47c60_len_f0", osContAddressCrc);

u8 osContDataCrc(u8* data) {
    s32 ret;
    u32 bit;
    u32 byte;

    ret = 0;
    for (byte = 0x20; byte; --byte, ++data) {
        for (bit = 0x80; bit; bit >>= 1) {
            ret <<= 1;
            if ((*data & bit) != 0) {
                if ((ret & 0x100) != 0) {
                    ret ^= 0x84;
                } else {
                    ++ret;
                }
            } else {
                if (ret & 0x100) {
                    ret ^= 0x85;
                }
            }
        }
    }
    do {
        ret <<= 1;
        if (ret & 0x100) {
            ret ^= 0x85;
        }
        ++byte;
    } while (byte < 8U);
    return ret;
}
