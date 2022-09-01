#include "gcc/memory.h"

void* memset(void* dest, int val, size_t len) {
    unsigned char* ptr = dest;

    while (len--) {
        *ptr++ = val;
    }
    return dest;
}
