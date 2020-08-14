#include "common.h"

void func_80033540(void) {
    D_8009A650[0] |= 8;
    (*gGameStatusPtr)->unk_AC = 3;
}

INCLUDE_ASM(code_e940_len_290, func_80033568);

void func_80033788(void) {
    func_8002AB5C(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
