#include "ultra64.h"

void* memset(void* dest, int ch, size_t n) {
    unsigned char* p = dest;
    size_t i;

    for (i = 0; i < n; i++) {
        p[i] = ch;
    }
    return dest;
}

// these functions below should be separate in libultra_rom, however they aren't aligned in proper

int memcmp(const void* str1, const void* str2, size_t n) {
    const unsigned char* s1 = str1;
    const unsigned char* s2 = str2;
    unsigned char u1, u2;

    while (n-- > 0) {
        u2 = *s2++;
        u1 = *s1++;
        if (u1 != u2) {
            return u1 - u2;
        }
    }
    return 0;
}

// n should be size_t but can't be
int strncmp(const char* str1, const char* str2, int n) {
    int i;

    for (i = 0; (*str1 == *str2) && (i < n); i++) {
        if (*str1 == 0) {
            if (*str2 == 0) {
                return 0;
            }
            break;
        }
        if (*str2 == 0) {
            break;
        }
        str1++;
        str2++;
    }
    return (i != n) ? *str1 - *str2 : 0;
}
