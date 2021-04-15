#include "common.h"
#include "ld_addrs.h"

s32 func_802B6000_E24920();
s32 func_802B6288_E23968();
s32 func_802B60B4_E240F4();
s32 func_802B6198_E241D8();
s32 func_802B6294_E242D4();
s32 func_802B6060_E27570();
s32 func_802B6348_E24388();
s32 func_802B61C0_E24AE0();
s32 func_802B6638_E29068();
s32 func_802B66A8_E25578();
s32 func_802B6350_E28D80();
s32 func_802B6508_E28F38();
s32 func_802B6230_E24800();
s32 func_802B6120_E2A7D0();
s32 func_802B63D4_E28E04();
s32 func_802B6478_E28EA8();
s32 func_802B60A4_E29514();
s32 func_802B609C_E28ACC();

f32 D_800F7B40 = 0.0f;
s32 D_800F7B44 = 0;
f32 D_800F7B48 = 0.0f;
s32 D_800F7B4C = 0;

s32 D_800F7B50[] = { 0x417C1B33, 0xC0EC5C14, 0x405C9AAA, 0xBF400000 };
f32 D_800F7B60[] = { 0.154342994094f, -0.350080013275f, -0.182262003422f, 0.0115200001746f };
f32 D_800F7B70[] = { 2.0f, 4.0f, 32.0f, -32.0f };
s16 D_800F7B80 = 0;
s32 D_800F7B84[] = { 0, 0, 0};
s32 D_800F7B90 = 0;
s32 D_800F7B94[] = { 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390008, 0x00390007, 0x00390013, 0x00390014, 0xFFFFFFFF, 0x005A0000, 0x005A0002, 0x005A0003, 0x005A0004, 0x005A0006, 0x005A0007, 0x005A0009, 0x005A000A, 0x005A000B, 0x005A001A, 0xFFFFFFFF, 0x00580000, 0x00580001, 0x00580002, 0x00580004, 0x00580005, 0x00580006, 0x00580007, 0x00580008, 0x00580009, 0x00580012, 0x00580014, 0x0058001B, 0xFFFFFFFF };
s32 D_800F7C1C[] = { 0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000 };
s32 D_800F7C30[] = { 0x0058001B, 0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B, 0x005A0003, 0x005A0006, 0x005A0009, 0x005A000B, 0x005A0000, 0x005A001A, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390000, 0x00390014 };
void* D_800F7C7C[] = { &D_800F7BE8, &D_800F7BE8, &D_800F7BBC, &D_800F7B94 };
s32 D_800F7C8C[] = {
    // TODO: struct for dma table
    // TODO: ld addrs
    (s32) &func_802B6000_E24920, &E23260_ROM_START, &E23260_ROM_END, 0x01000000,
    (s32) &func_802B6000_E24920, 0x00E236E0, 0x00E24040, 0x01000000,
    (s32) &func_802B6288_E23968, 0x00E236E0, 0x00E24040, 0x01000000,
    (s32) &func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32) &func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32) &func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32) &func_802B60B4_E240F4, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32) &func_802B6198_E241D8, 0x00E24040, 0x00E245D0, 0x00000000,
    (s32) &func_802B6294_E242D4, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32) &func_802B6348_E24388, 0x00E24040, 0x00E245D0, 0x01000000,
    (s32) &func_802B6000_E24920, 0x00E24920, 0x00E24ED0, 0x01000000,
    (s32) &func_802B61C0_E24AE0, 0x00E24920, 0x00E24ED0, 0x01000000,
    (s32) &func_802B6638_E29068, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32) &func_802B6000_E24920, 0x00E26DE0, 0x00E27510, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E26DE0, 0x00E27510, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E26710, 0x00E26DE0, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E26710, 0x00E26DE0, 0x00000000,
    (s32) &func_802B6060_E27570, 0x00E27510, 0x00E27C90, 0x00000000,
    (s32) &func_802B66A8_E25578, 0x00E24ED0, 0x00E25D60, 0x00000000,
    (s32) &func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32) &func_802B6508_E28F38, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E27C90, 0x00E27F40, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E287F0, 0x00E28A30, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E27F40, 0x00E287F0, 0x00000000,
    (s32) &func_802B6230_E24800, 0x00E245D0, 0x00E24920, 0x01000000,
    (s32) &func_802B6120_E2A7D0, 0x00E2A6B0, 0x00E2B530, 0x01000000,
    (s32) &func_802B6000_E24920, 0x00E25D60, 0x00E26710, 0x00000000,
    (s32) &func_802B63D4_E28E04, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B6478_E28EA8, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B60A4_E29514, 0x00E29470, 0x00E2A340, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E291A0, 0x00E29470, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E2A340, 0x00E2A6B0, 0x00000000,
    (s32) &func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
    (s32) &func_802B6000_E24920, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B6000_E24920, 0x00E245D0, 0x00E24920, 0x01000000,
    (s32) &func_802B609C_E28ACC, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x00000000,
    (s32) &func_802B6350_E28D80, 0x00E236E0, 0x00E24040, 0x00000000,
    (s32) &func_802B6350_E28D80, 0x00E28A30, 0x00E291A0, 0x01000000,
};
