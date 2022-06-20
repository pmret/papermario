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

typedef struct unk341d0 {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16* unk_0C;
    s16* unk_10;
} unk341d0;

s32* D_8007F1F8 = D_8007F1D0;

s32* D_8007F1FC = D_8007F1D0;

s32* D_8007F200 = D_8007F1D0;

s32* D_8007F204 = D_8007F1D0;

void func_80058DD0(s16* arg);
INCLUDE_ASM(s32, "341d0", func_80058DD0);

INCLUDE_ASM(s32, "341d0", func_80058E84);

INCLUDE_ASM(s32, "341d0", func_80058F88);

void func_80059008(unk341d0* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_06 = arg1;
    arg0->unk_08 = arg2;

    if (arg3 != 0) {
        arg0->unk_0C = arg0->unk_10;
        *arg0->unk_0C = arg3;
        func_80058DD0(arg0->unk_0C);
        return;
    }

    arg0->unk_0C = NULL;
}

INCLUDE_ASM(s32, "341d0", func_8005904C);

INCLUDE_ASM(s32, "341d0", func_80059310);

s32 func_800598A0(UnkAlLen14* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16* temp_v0;

    switch (arg2) {
    case 0:
        arg0->unk_0C[arg1].unk_00 = arg3 & ~7;
        break;
    case 1:
        arg0->unk_0C[arg1].unk_04 = arg3 & ~7;
        break;
    case 3:
        arg0->unk_0C[arg1].unk_08 = arg3;
        break;
    case 2:
        arg0->unk_0C[arg1].unk_0A = arg3;
        break;
    case 4:
        arg0->unk_0C[arg1].unk_0C = arg3;
        break;
    case 5:
        arg0->unk_0C[arg1].unk_10 = (2.0 * (arg3 / 1000.0f)) / D_80078E50->frequency;
        break;
    case 6:
        arg0->unk_0C[arg1].unk_1C = ((f32)arg3 / 173123.404906676) * (arg0->unk_0C[arg1].unk_04 - arg0->unk_0C[arg1].unk_00);
        break;
    case 7:
        temp_v0 = arg0->unk_0C[arg1].unk_20;
        if (temp_v0 != 0) {
            *temp_v0 = arg3;
            func_80058DD0(arg0->unk_0C[arg1].unk_20);
        }
        break;
    }
    return 0;
}

INCLUDE_ASM(s32, "341d0", func_80059AB8);

INCLUDE_ASM(s32, "341d0", func_80059BD4);
