#include "common.h"
#include "ld_addrs.h"

void func_80200000(void);
void func_80200080(void);
void func_802AE000(void);

void func_802B2000(void) {
    dma_copy(&code_code_3169F0_ROM_START, &code_code_3169F0_ROM_END, &code_code_3169F0_VRAM);
    func_80200000();
}

void func_802B203C(void) {
    dma_copy(&code_code_316A70_ROM_START, &code_code_316A70_ROM_END, &code_code_316A70_VRAM);
    func_80200080();
}

void func_802B2078(void) {
    dma_copy(&code_code_316C00_ROM_START, &code_code_316C00_ROM_END, &code_code_316C00_VRAM);
    func_802AE000();
}

void func_802B20B4(void) {
    dma_copy(&code_code_316D90_ROM_START, &code_code_316D90_ROM_END, &code_code_316D90_VRAM);
    func_802AE000();
}
