#include "common.h"
#include "audio.h"

s32 D_8007EFE0[] = {
    0x00000003, 0x0000000B, 0x00000000, 0x00000009, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000003, 0x00000007, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000A, 0x00001388, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000
};

s32 D_8007F048[] = {
    0x00000004, 0x0000000E, 0x00000000, 0x00000009, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00000006, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000009, 0x0000000C, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000D, 0x00001770, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000, 0x00000004, 0x00000011,
    0x00000000, 0x0000000B, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004,
    0x00000009, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 0x0000000B, 0x0000000F,
    0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0x00001F40,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000
};

s32 D_8007F158[] = {
    0x00000001, 0x0000000E, 0x00000000, 0x0000000D, 0x00004E20, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000,
    0x00007FFF
};

s32 D_8007F180[] = {
    0x00000001, 0x00000003, 0x00000000, 0x00000001, 0x00004000, 0x00000000, 0x00007FFF, 0x00001DB0, 0x000002BC,
    0x00000000
};

s32 D_8007F1A8[] = {
    0x00000001, 0x00000003, 0x00000000, 0x00000001, 0x00000000, 0x00005FFF, 0x00007FFF, 0x0000017C, 0x000001F4,
    0x00000000
};

s32 D_8007F1D0[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000
};

typedef struct unk341d0_sub10 {
    /* 0x00 */ s16 unk_00;
    /* 0x00 */ char unk_02[0x26];
    /* 0x28 */ s32* unk_28;
    /* 0x00 */ char unk_2C[0x4];
} unk341d0_sub10; // size 0x30

// perhaps this could be UnkAlLen14?
typedef struct unk341d0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ unk341d0_sub10* unk_0C;
    /* 0x10 */ unk341d0_sub10* unk_10;
} unk341d0;

s32* D_8007F1F8 = D_8007F1D0;

s32* D_8007F1FC = D_8007F1D0;

s32* D_8007F200 = D_8007F1D0;

s32* D_8007F204 = D_8007F1D0;

void func_80058DD0(s16* arg);
INCLUDE_ASM(s32, "audio/341d0", func_80058DD0);

void func_80058E84(AlUnkDelta* delta, u8 arg1, ALHeap* heap) {
    AlUnkEpsilon* temp_s0;
    u16 i;

    delta->unk_eps_C = alHeapAlloc(heap, 4, sizeof(*delta->unk_eps_C));
    delta->unk_00 = alHeapAlloc(heap, 0xA10, 2);
    
    for (i = 0; i < 4; i++) {
        temp_s0 = &delta->unk_eps_C[i];
        temp_s0->unk_2C = alHeapAlloc(heap, 1, 0x10);
        temp_s0->unk_2C[0] = alHeapAlloc(heap, 1, 0x20); // unk_2C->unk_00
        temp_s0->unk_24 = alHeapAlloc(heap, 1, 0x30);
        temp_s0->unk_24[10] = alHeapAlloc(heap, 1, 8); // unk_24->unk_28
    }
    
    func_8005904C(delta, arg1);
}

void func_80058F88(unk341d0* arg0, ALHeap* arg1) {
    arg0->unk_00 = alHeapAlloc(arg1, 0x1420, 2);
    arg0->unk_10 = alHeapAlloc(arg1, 1, 0x30);
    arg0->unk_10->unk_28 = alHeapAlloc(arg1, 1, 8);
    func_80059008(arg0, 0, 0, 0x5000);
}

void func_80059008(unk341d0* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_06 = arg1;
    arg0->unk_08 = arg2;

    if (arg3 != 0) {
        arg0->unk_0C = arg0->unk_10;
        arg0->unk_0C->unk_00 = arg3;
        func_80058DD0(arg0->unk_0C);
        return;
    }

    arg0->unk_0C = NULL;
}

INCLUDE_ASM(s32, "audio/341d0", func_8005904C);

INCLUDE_ASM(s32, "audio/341d0", func_80059310);

s32 func_800598A0(AlUnkDelta* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16* temp_v0;

    switch (arg2) {
    case 0:
        arg0->unk_eps_C[arg1].unk_00 = arg3 & ~7;
        break;
    case 1:
        arg0->unk_eps_C[arg1].unk_04 = arg3 & ~7;
        break;
    case 3:
        arg0->unk_eps_C[arg1].unk_08 = arg3;
        break;
    case 2:
        arg0->unk_eps_C[arg1].unk_0A = arg3;
        break;
    case 4:
        arg0->unk_eps_C[arg1].unk_0C = arg3;
        break;
    case 5:
        arg0->unk_eps_C[arg1].unk_10 = (2.0 * (arg3 / 1000.0f)) / D_80078E50->frequency;
        break;
    case 6:
        arg0->unk_eps_C[arg1].unk_1C = ((f32)arg3 / 173123.404906676) * (arg0->unk_eps_C[arg1].unk_04 - arg0->unk_eps_C[arg1].unk_00);
        break;
    case 7:
        temp_v0 = arg0->unk_eps_C[arg1].unk_20;
        if (temp_v0 != 0) {
            *temp_v0 = arg3;
            func_80058DD0(arg0->unk_eps_C[arg1].unk_20);
        }
        break;
    }
    return 0;
}

INCLUDE_ASM(s32, "audio/341d0", func_80059AB8);

INCLUDE_ASM(s32, "audio/341d0", func_80059BD4);
