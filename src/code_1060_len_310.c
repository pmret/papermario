#include "common.h"

void func_80025C60(void) {
    OSPiHandle** handle = &carthandle;

    osEPiWriteIo(*handle, 0xB3FF0014, 0);
    osEPiWriteIo(*handle, 0xB3FF0004, 0);
    osEPiWriteIo(*handle, 0xB3FF0000, ASCII_TO_U32('I', 'S', '6', '4'));
}

INCLUDE_ASM(s32, "code_1060_len_310", func_80025CC0);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025CFC);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025D38);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025D74);

INCLUDE_ASM(s32, "code_1060_len_310", func_80025F44);
