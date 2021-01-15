#include "common.h"

#define U32_CHAR_LITERAL(a, b, c, d) ((u32)((a << 24) | (b << 16) | (c << 8) | (d << 0)))

void func_80025C60(void) {
    OSPiHandle** handle = &carthandle;

    osEPiWriteIo(*handle, 0xB3FF0014, 0);
    osEPiWriteIo(*handle, 0xB3FF0004, 0);
    osEPiWriteIo(*handle, 0xB3FF0000, U32_CHAR_LITERAL('I', 'S', '6', '4'));
}

INCLUDE_ASM(s32, "code_1060_len_310", func_80025CC0);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025CFC);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025D38);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025D74);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025F44);
