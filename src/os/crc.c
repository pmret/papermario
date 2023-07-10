#include "ultra64.h"
#include "include_asm.h"

u8 __osContAddressCrc(u16 addr) {
    u32 temp = 0;
    u32 i;

    for (i = 0x400; i != 0;) {
        temp <<= 1;

        if (addr & i) {
            if (temp & 0x20) {
                temp ^= 0x14;
            } else {
                ++temp;
            }
        } else if (temp & 0x20) {
            temp ^= 0x15;
        }

        i >>= 1;
    }

    for (i = 5; i != 0; --i) {
        temp <<= 1;
        if (temp & 0x20) {
            temp ^= 0x15;
        }
    }

    return temp & 0x1F;
}

u8 __osContDataCrc(u8* data) {
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
