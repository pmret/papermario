#include "common.h"
#include "include_asm_libultra.h"

#ifndef KMC_ASM
char* strchr(const char* s, int c) {
    const char ch = c;
    while (*s != ch) {
        if (*s == 0)
            return NULL;
        s++;
    }
    return (char *)s;
}
#else
INCLUDE_ASM_LIBULTRA("string", strchr);
#endif

#ifndef KMC_ASM
size_t strlen(const char* s) {
    const char* sc = s;
    while (*sc) {
        sc++;
    }
    return sc - s;
}
#else
INCLUDE_ASM_LIBULTRA("string", strlen);
#endif

#ifndef KMC_ASM
void* memcpy(void* s1, const void* s2, size_t n) {
    char* su1 = (char*)s1;
    const char *su2 = (const char*)s2;
    while (n > 0) {
        *su1++ = *su2++;
        n--;
    }
    return (void*)s1;
}
#else
INCLUDE_ASM_LIBULTRA("string", memcpy);
#endif
