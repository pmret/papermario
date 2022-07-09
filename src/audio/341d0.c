#include "common.h"
#include "audio.h"

typedef struct UnkEpsilonConfig {
    s32 count;
    s32 unk;
    s32 data[0]; // variable size
} UnkEpsilonConfig;

UnkEpsilonConfig SMALLROOM_PARAMS_N = {
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

void _init_lpfilter(AuLowPass* lp) {
    f64 attenuation;
    s16 timeConstant;
    u32 temp;
    s32 i;

    lp->first = 1;
    temp = lp->fc;
    timeConstant = temp;
    timeConstant = timeConstant >> 1;
    lp->fgain = 16384 - timeConstant;

    for (i = 0; i < 8; i++) {
        lp->fccoef[i] = 0;
    }

    lp->fccoef[8] = timeConstant;
    
    // ith value is 16384.0 * (timeConstant / 16384.0)^(i-7)
    // ex: i = 9 --> timeConstant^2 / 16384.0
    attenuation = (timeConstant / 16384.0);
    for (i = 9; i < 16; i++) {
        attenuation *= (timeConstant / 16384.0);
        lp->fccoef[i] = attenuation * 16384.0;
    }
}

// initialize delta at 801C9060, with eps_0C at 801C90A0
// definately AuFX, evidenced by call to func_8005904C
void func_80058E84(AuFX* delta, u8 arg1, ALHeap* heap) {
    AuDelay* eps;
    u16 i;

    // allocate space for 4 AuDelay
    delta->delays = alHeapAlloc(heap, 4, sizeof(AuDelay));
    delta->base = alHeapAlloc(heap, 0xA10, 2);
    
    for (i = 0; i < 4; i++) {
        eps = &delta->delays[i];
        eps->unk_psi_2C = alHeapAlloc(heap, 1, sizeof(AuResampler));
        eps->unk_psi_2C->rs_state = alHeapAlloc(heap, 1, sizeof(RESAMPLE_STATE));
        eps->lowpass_24 = alHeapAlloc(heap, 1, sizeof(AuLowPass));
        eps->lowpass_24->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    }
    
    func_8005904C(delta, arg1);
}

// no known calls to this function
void func_80058F88(AlUnkKappa* kappa, ALHeap* heap) {
    kappa->unk_00 = alHeapAlloc(heap, 0x1420, 2);
    kappa->unk_phi_10 = alHeapAlloc(heap, 1, sizeof(AuLowPass));
    kappa->unk_phi_10->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    func_80059008(kappa, 0, 0, 0x5000);
}

// no known entry point to this function, called only by func_80058F88
void func_80059008(AlUnkKappa* kappa, s16 arg1, s16 arg2, s16 arg3) {
    kappa->unk_06 = arg1;
    kappa->unk_08 = arg2;

    if (arg3 != 0) {
        kappa->unk_phi_0C = kappa->unk_phi_10;
        kappa->unk_phi_0C->fc = arg3;
        _init_lpfilter(kappa->unk_phi_0C);
        return;
    }

    kappa->unk_phi_0C = NULL;
}

// n_alFxNew
// AuFX from gSynDriver
INCLUDE_ASM(s32, "audio/341d0", func_8005904C);

// alFxPull
// AuFX from gSynDriver
INCLUDE_ASM(s32, "audio/341d0", func_80059310);

// alFxParamHdl
s32 func_800598A0(AuFX* delta, s16 index, s16 mode, s32 value) {
    s16* temp_v0;
    s32 diff;

    switch (mode) {
    case 0:
        delta->delays[index].input = value & 0xFFFFFFF8;
        break;
    case 1:
        delta->delays[index].output = value & 0xFFFFFFF8;
        break;
    case 3:
        delta->delays[index].ffcoef = value;
        break;
    case 2:
        delta->delays[index].fbcoef = value;
        break;
    case 4:
        delta->delays[index].unk_0C = value;
        break;
    case 5:
        delta->delays[index].rsinc = (2.0 * (value / 1000.0f)) / D_80078E50->outputRate;
        break;
    case 6:
        delta->delays[index].rsgain = ((f32)value / 173123.404906676)
            * (delta->delays[index].output - delta->delays[index].input);
        break;
    case 7:
        temp_v0 = delta->delays[index].lowpass_20;
        if (temp_v0 != 0) {
            *temp_v0 = value;
            _init_lpfilter(delta->delays[index].lowpass_20);
        }
        break;
    }
    return 0;
}

// from libultra reverb.c
Acmd* _saveBuffer(AuFX* delta, s16* old_pos, s32 buff, s32 count, Acmd* cmdBufPos) {
    Acmd *ptr = cmdBufPos;
    s16* new_pos = old_pos + count;
    s16* delay_end = &delta->base[delta->length];

    if (delay_end < new_pos) {
        s32 before_end = (delay_end - old_pos);
        s32 after_end = (new_pos - delay_end);
        n_aLoadBuffer(ptr++, before_end<<1, buff, osVirtualToPhysical(old_pos));
        n_aLoadBuffer(ptr++, after_end<<1, buff + (before_end<<1), osVirtualToPhysical(delta->base));
    } else {
        n_aLoadBuffer(ptr++, count<<1, buff, osVirtualToPhysical(old_pos));
    }

    return ptr;
}

f32 func_80059BD4(AuDelay* eps, s32 arg1) {
    f32* floatPtr = &eps->rsval;
    f32 temp;
    f32 result;
   
    eps->rsval = eps->rsval + (eps->rsinc * arg1);
    
    if (eps->rsval > 2.0) {
        temp = eps->rsval - 4.0;
    } else {
        temp = eps->rsval;
    }
    *floatPtr = temp;
    
    result = eps->rsval;
    if (result < 0.0f) {
        result = -result;
    }

    result = result - 1.0;
    
    return eps->rsgain * result;
}
