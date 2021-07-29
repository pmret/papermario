#include "common.h"
#include "stdlib/stdarg.h"

// TODO: use src/is_debug.c instead as this file is identical between versions

u32 func_80025D74(void* arg0, const unsigned char* str, s32 count);

void func_80025C60(void) {
    OSPiHandle** handle = &carthandle;

    osEPiWriteIo(*handle, 0xB3FF0014, 0);
    osEPiWriteIo(*handle, 0xB3FF0004, 0);
    osEPiWriteIo(*handle, 0xB3FF0000, ASCII_TO_U32('I', 'S', '6', '4'));
}

void func_80025CC0(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(&func_80025D74, NULL, fmt, args);
}

void func_80025CFC(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(&func_80025D74, NULL, fmt, args);
}

void func_80025D38(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(&func_80025D74, NULL, fmt, args);
}

u32 func_80025D74(void* arg0, const unsigned char* str, s32 count) {
    u32 data;
    s32 pos;
    s32 start;
    s32 end;

    osEPiReadIo(carthandle, 0xB3FF0000, &data);
    if (data != ASCII_TO_U32('I', 'S', '6', '4')) {
        return 1;
    }
    osEPiReadIo(carthandle, 0xB3FF0004, &data);
    pos = data;
    osEPiReadIo(carthandle, 0xB3FF0014, &data);
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
            u32 addr = 0xB3FF0020 + (start & 0xffffffc);
            s32 shift = ((3 - (start & 3)) * 8);

            osEPiReadIo(carthandle, addr, &data);
            osEPiWriteIo(carthandle, addr, (data & ~(0xff << shift)) | (*str << shift));

            start++;
            if (start >= 0xffe0) {
                start -= 0xffe0;
            }
        }
        count--;
        str++;
    }
    osEPiWriteIo(carthandle, 0xB3FF0014, start);
    return 1;
}

extern const char D_80097D10[]; // "File:%s Line:%d  %s \n\0\0\0"
void func_80025F44(char* arg0, char* file, s32 line, char* arg3) {
    func_80025CFC(D_80097D10, file, line, arg0);
    PANIC();
}
