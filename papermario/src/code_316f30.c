#include "common.h"

void func_80200000(void);
void func_80200080(void);
void func_802AE000(void);

extern s32 D_003169F0;
extern s32 D_00316A70;
extern s32 D_00316C00;
extern s32 D_00316D90;
extern s32 D_00316F30;

void func_802B2000(void) {
    dma_copy(&D_003169F0, &D_00316A70, func_80200000);
    func_80200000();
}

void func_802B203C(void) {
    dma_copy(&D_00316A70, &D_00316C00, func_80200080);
    func_80200080();
}

void func_802B2078(void) {
    dma_copy(&D_00316C00, &D_00316D90, func_802AE000);
    func_802AE000();
}

void func_802B20B4(void) {
    dma_copy(&D_00316D90, &D_00316F30, func_802AE000);
    func_802AE000();
}
