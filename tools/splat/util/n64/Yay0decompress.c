#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint32_t magic;
    uint32_t uncompressedLength;
    uint32_t opPtr;
    uint32_t dataPtr;
} Yay0Header;

void decompress(Yay0Header* hdr, uint8_t* srcPtr, uint8_t* dstPtr, bool isBigEndian) {
    uint8_t byte = 0, mask = 0;
    uint8_t* ctrl, * ops, * data;
    uint16_t copy, op;
    uint32_t written = 0;

    ctrl = srcPtr + sizeof(Yay0Header);
    ops = srcPtr + hdr->opPtr;
    data = srcPtr + hdr->dataPtr;

    while (written < hdr->uncompressedLength) {
        if ((mask >>= 1) == 0) {
            byte = *ctrl++;
            mask = 0x80;
        }

        if (byte & mask) {
            *dstPtr++ = *data++;
            written++;
        } else {
            op = isBigEndian ? (ops[0] << 8) | ops[1] : (ops[1] << 8) | ops[0];
            ops += 2;

            written += copy = (op >> 12) ? (2 + (op >> 12)) : (18 + *data++);

            while (copy--) {
                *dstPtr++ = dstPtr[-(op & 0xfff) - 1];
            }
        }
    }
}
