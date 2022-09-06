#include "gcc/string.h"

int strcmp(const char* str1, const char* str2) {
    unsigned char c1 = *str1;
    unsigned char c2 = *str2;

    while (1) {
        c1 = *str1++;
        c2 = *str2++;
        if (c1 != c2) {
            break;
        }
        if (c1 == 0) {
            return 0;
        }
    }
    return c1 - c2;
}
