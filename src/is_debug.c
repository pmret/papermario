#include "common.h"
#include "stdlib/stdarg.h"
#include "nu/nusys.h"

typedef struct {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 get;
    /* 0x08 */ char unk_08[0x14-0x08];
    /* 0x14 */ u32 put;
    /* 0x18 */ char unk_18[0x20-0x18];
    /* 0x20 */ char data[0x10000-0x20];
} ISVDbg;

#define gISVDbgPrnAdrs ((ISVDbg*) 0xb3ff0000)

u32 is_debug_print(void* arg0, const unsigned char* str, s32 count);

void is_debug_init(void) {
    osEPiWriteIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->put, 0);
    osEPiWriteIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->get, 0);
    osEPiWriteIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->magic, ASCII_TO_U32('I', 'S', '6', '4'));
}

void printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(is_debug_print, NULL, fmt, args);
}

void osSyncPrintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(is_debug_print, NULL, fmt, args);
}

void rmonPrintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(is_debug_print, NULL, fmt, args);
}

u32 is_debug_print(void* arg0, const unsigned char* str, s32 count) {
    u32 data;
    s32 pos;
    s32 start;
    s32 end;

    osEPiReadIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->magic, &data);
    if (data != ASCII_TO_U32('I', 'S', '6', '4')) {
        return 1;
    }
    osEPiReadIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->get, &data);
    pos = data;
    osEPiReadIo(nuPiCartHandle, (u32) &gISVDbgPrnAdrs->put, &data);
    start = data;
    end = start + count;
    if (end >= 0xffe0) {
        end -= 0xffe0;
        if (pos < end || start < pos) {
            return 1;
        }
    } else {
        if (start < pos && pos < end) {
            return 1;
        }
    }
    while (count) {
        if (*str) {
            u32 addr = (u32) &gISVDbgPrnAdrs->data + (start & 0xffffffc);
            s32 shift = ((3 - (start & 3)) * 8);

            osEPiReadIo(nuPiCartHandle, addr, &data);
            osEPiWriteIo(nuPiCartHandle, addr, (data & ~(0xff << shift)) | (*str << shift));

            start++;
            if (start >= 0xffe0) {
                start -= 0xffe0;
            }
        }
        count--;
        str++;
    }
    osEPiWriteIo(nuPiCartHandle, (u32)&gISVDbgPrnAdrs->put, start);
    return 1;
}

// Nop issue with the rodata string
#ifdef NON_MATCHING
void func_80025F44(const char* message, char* file, s32 line) {
    osSyncPrintf("File:%s Line:%d  %s \n", file, line, message);

    while (TRUE) {
        ;
    }
}
#else
INCLUDE_ASM(void, "is_debug", func_80025F44, char* arg0, char* file, s32 line);
#endif
