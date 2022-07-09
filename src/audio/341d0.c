#include "common.h"
#include "audio.h"

typedef struct UnkEpsilonConfig {
    s32 count;
    s32 unk;
    s32 data[0]; // variable size
} UnkEpsilonConfig;

UnkEpsilonConfig D_8007EFE0 = {
    .count = 3,
    .unk = 11,
    .data = {
    0x00000000, 0x00000009, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000003, 0x00000007, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000A, 0x00001388, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000 }
};

UnkEpsilonConfig D_8007F048 = {
    .count = 4,
    .unk = 14,
    .data = {
    0x00000000, 0x00000009, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000006, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000009, 0x0000000C, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000D, 0x00001770, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000 }
};

// unused
UnkEpsilonConfig D_8007F0C0 = {
    .count = 4,
    .unk = 17,
    .data = {
    0x00000000, 0x0000000B, 0x00002666, 0xFFFFD99A, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0x00000009, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 
    0x0000000B, 0x0000000F, 0x00000CCC, 0xFFFFF334, 0x00003FFF, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000010, 0x00001F40, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00005000 }
};

UnkEpsilonConfig D_8007F158 = {
    .count = 1,
    .unk = 14,
    .data = {
    0x00000000, 0x0000000D, 0x00004E20, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00007FFF }
};

UnkEpsilonConfig D_8007F180 = {
    .count = 1,
    .unk = 3,
    .data = {
    0x00000000, 0x00000001, 0x00004000, 0x00000000, 0x00007FFF, 0x00001DB0, 0x000002BC, 0x00000000 }
};

UnkEpsilonConfig D_8007F1A8 = {
    .count = 1,
    .unk = 3,
    .data = {
    0x00000000, 0x00000001, 0x00000000, 0x00005FFF, 0x00007FFF, 0x0000017C, 0x000001F4, 0x00000000 }
};

UnkEpsilonConfig D_8007F1D0 = {
    .count = 0,
    .unk = 0,
    .data = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }
};

UnkEpsilonConfig* D_8007F1F8 = &D_8007F1D0;

UnkEpsilonConfig* D_8007F1FC = &D_8007F1D0;

UnkEpsilonConfig* D_8007F200 = &D_8007F1D0;

UnkEpsilonConfig* D_8007F204 = &D_8007F1D0;

// init_lpfilter
void func_80058DD0(AlUnkPhi* phi) {
    f64 attenuation;
    s16 timeConstant;
    u32 temp;
    s32 i;

    phi->unk_2C = 1;
    temp = phi->unk_00;
    timeConstant = temp;
    timeConstant = timeConstant >> 1;
    phi->unk_02 = 16384 - timeConstant;

    for (i = 0; i < 8; i++) {
        phi->arr[i] = 0;
    }

    phi->arr[8] = timeConstant;
    
    // ith value is 16384.0 * (timeConstant / 16384.0)^(i-7)
    // ex: i = 9 --> timeConstant^2 / 16384.0
    attenuation = (timeConstant / 16384.0);
    for (i = 9; i < 16; i++) {
        attenuation *= (timeConstant / 16384.0);
        phi->arr[i] = attenuation * 16384.0;
    }
}

// initialize delta at 801C9060, with eps_0C at 801C90A0
// definately AlUnkDelta, evidenced by call to func_8005904C
void func_80058E84(AlUnkDelta* delta, u8 arg1, ALHeap* heap) {
    AlUnkEpsilon* eps;
    u16 i;

    // allocate space for 4 AlUnkEpsilon
    delta->unk_eps_0C = alHeapAlloc(heap, 4, sizeof(AlUnkEpsilon));
    delta->unk_00 = alHeapAlloc(heap, 0xA10, 2);
    
    for (i = 0; i < 4; i++) {
        eps = &delta->unk_eps_0C[i];
        eps->unk_psi_2C = alHeapAlloc(heap, 1, sizeof(AlUnkPsi));
        eps->unk_psi_2C->unk_rho_00 = alHeapAlloc(heap, 1, sizeof(AlUnkRho));
        eps->unk_phi_24 = alHeapAlloc(heap, 1, sizeof(AlUnkPhi));
        eps->unk_phi_24->unk_chi_28 = alHeapAlloc(heap, 1, sizeof(AlUnkChi));
    }
    
    func_8005904C(delta, arg1);
}

// no known calls to this function
void func_80058F88(AlUnkKappa* kappa, ALHeap* heap) {
    kappa->unk_00 = alHeapAlloc(heap, 0x1420, 2);
    kappa->unk_phi_10 = alHeapAlloc(heap, 1, sizeof(AlUnkPhi));
    kappa->unk_phi_10->unk_chi_28 = alHeapAlloc(heap, 1, sizeof(AlUnkChi));
    func_80059008(kappa, 0, 0, 0x5000);
}

// no known entry point to this function, called only by func_80058F88
void func_80059008(AlUnkKappa* kappa, s16 arg1, s16 arg2, s16 arg3) {
    kappa->unk_06 = arg1;
    kappa->unk_08 = arg2;

    if (arg3 != 0) {
        kappa->unk_phi_0C = kappa->unk_phi_10;
        kappa->unk_phi_0C->unk_00 = arg3;
        func_80058DD0(kappa->unk_phi_0C);
        return;
    }

    kappa->unk_phi_0C = NULL;
}

// AlUnkDelta from D_80078E54
INCLUDE_ASM(s32, "audio/341d0", func_8005904C);

// alFxPull
// AlUnkDelta from D_80078E54
INCLUDE_ASM(s32, "audio/341d0", func_80059310);

// alFxParamHdl
s32 func_800598A0(AlUnkDelta* delta, s16 index, s16 mode, s32 value) {
    s16* temp_v0;
    s32 diff;

    switch (mode) {
    case 0:
        delta->unk_eps_0C[index].unk_00 = value & 0xFFFFFFF8;
        break;
    case 1:
        delta->unk_eps_0C[index].unk_04 = value & 0xFFFFFFF8;
        break;
    case 3:
        delta->unk_eps_0C[index].unk_08 = value;
        break;
    case 2:
        delta->unk_eps_0C[index].unk_0A = value;
        break;
    case 4:
        delta->unk_eps_0C[index].unk_0C = value;
        break;
    case 5:
        delta->unk_eps_0C[index].unk_10 = (2.0 * (value / 1000.0f)) / D_80078E50->frequency;
        break;
    case 6:
        delta->unk_eps_0C[index].unk_1C = ((f32)value / 173123.404906676)
            * (delta->unk_eps_0C[index].unk_04 - delta->unk_eps_0C[index].unk_00);
        break;
    case 7:
        temp_v0 = delta->unk_eps_0C[index].unk_phi_20;
        if (temp_v0 != 0) {
            *temp_v0 = value;
            func_80058DD0(delta->unk_eps_0C[index].unk_phi_20);
        }
        break;
    }
    return 0;
}

// from libultra reverb.c
Acmd* _saveBuffer(AlUnkDelta* delta, s16* old_pos, s32 buff, s32 count, Acmd* cmdBufPos) {
    Acmd *ptr = cmdBufPos;
    s16* new_pos = old_pos + count;
    s16* delay_end = &delta->unk_00[delta->unk_08];

    if (delay_end < new_pos) {
        s32 before_end = (delay_end - old_pos);
        s32 after_end = (new_pos - delay_end);
        n_aLoadBuffer(ptr++, before_end<<1, buff, osVirtualToPhysical(old_pos));
        n_aLoadBuffer(ptr++, after_end<<1, buff + (before_end<<1), osVirtualToPhysical(delta->unk_00));
    } else {
        n_aLoadBuffer(ptr++, count<<1, buff, osVirtualToPhysical(old_pos));
    }

    return ptr;
}

f32 func_80059BD4(AlUnkEpsilon* eps, s32 arg1) {
    f32* floatPtr = &eps->unk_14;
    f32 temp;
    f32 result;
   
    eps->unk_14 = eps->unk_14 + (eps->unk_10 * arg1);
    
    if (eps->unk_14 > 2.0) {
        temp = eps->unk_14 - 4.0;
    } else {
        temp = eps->unk_14;
    }
    *floatPtr = temp;
    
    result = eps->unk_14;
    if (result < 0.0f) {
        result = -result;
    }

    result = result - 1.0;
    
    return eps->unk_1C * result;
}
