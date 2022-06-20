#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

s16 func_80058004(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

UnkAl0* D_80078E50 = NULL;
UnkAl0* D_80078E54 = NULL;
s8 D_80078E58 = 0;
s16 D_80078E5A = 0x7FFF;
s8 D_80078E5C = 0;

// values for cosine from 0 to pi/2 multiplied by 32767
s16 AlCosineBlend[] = { 
    32767, 32764, 32757, 32744, 32727, 32704, 32677, 32644,
    32607, 32564, 32517, 32464, 32407, 32344, 32277, 32205,
    32127, 32045, 31958, 31866, 31770, 31668, 31561, 31450,
    31334, 31213, 31087, 30957, 30822, 30682, 30537, 30388,
    30234, 30075, 29912, 29744, 29572, 29395, 29214, 29028,
    28838, 28643, 28444, 28241, 28033, 27821, 27605, 27385,
    27160, 26931, 26698, 26461, 26220, 25975, 25726, 25473,
    25216, 24956, 24691, 24423, 24151, 23875, 23596, 23313,
    23026, 22736, 22442, 22145, 21845, 21541, 21234, 20924,
    20610, 20294, 19974, 19651, 19325, 18997, 18665, 18331,
    17993, 17653, 17310, 16965, 16617, 16266, 15913, 15558,
    15200, 14840, 14477, 14113, 13746, 13377, 13006, 12633,
    12258, 11881, 11503, 11122, 10740, 10357,  9971,  9584,
     9196,  8806,  8415,  8023,  7630,  7235,  6839,  6442,
     6044,  5646,  5246,  4845,  4444,  4042,  3640,  3237,
     2833,  2429,  2025,  1620,  1216,   810,   405,     0
    };

void func_80056250(UnkAl0* globals, ALConfig* config) {
    s32 i;
    ALHeap* heap = config->heap;

    if (D_80078E50 != NULL) {
        return;
    }

    globals->unk_0C = config->unk_00;
    globals->unk_10 = config->unk_04;
    globals->unk_00 = 0;
    globals->unk_04 = 0;
    globals->frequency = config->frequency;
    globals->dmaNew = config->dmaNew;

    D_80078E50 = globals;
    D_80078E54 = globals;
    D_80078E58 = 0;
    D_80078E5A = 0x7FFF;
    D_80078E5C = 1;
    D_80078E54->unk_1C = alHeapAlloc(heap, config->unk_00, sizeof(UnkAl7C));

    for (i = 0; i < config->unk_00; i++) {
        UnkAl7C* al7C = &D_80078E54->unk_1C[i];
        al7C->unk_04 = alHeapAlloc(heap, 1, 0x20);
        al7C->unk_08 = alHeapAlloc(heap, 1, 0x20);
        al7C->dmaProc = ((ALDMAproc (*)(NUDMAState**))(D_80078E54->dmaNew))(&al7C->dmaState);
        al7C->unk_2C = 0;
        al7C->unk_30 = 1;
        al7C->unk_34 = 0;
        al7C->unk_38 = alHeapAlloc(heap, 1, 0x20);
        al7C->unk_40 = 0;
        al7C->unk_44 = 1;
        al7C->unk_3C = 1.0f;
        al7C->unk_48 = alHeapAlloc(heap, 1, 0x50);
        al7C->unk_6C = 1;
        al7C->unk_70 = 0;
        al7C->unk_4E = 1;
        al7C->unk_5C = 1;
        al7C->unk_62 = 1;
        al7C->unk_50 = 1;
        al7C->unk_52 = 1;
        al7C->unk_54 = 0;
        al7C->unk_56 = 0;
        al7C->unk_5A = 1;
        al7C->unk_58 = 0;
        al7C->unk_60 = 1;
        al7C->unk_5E = 0;
        al7C->unk_64 = 0;
        al7C->unk_68 = 0;
        al7C->unk_4C = 64;
        al7C->unk_74 = 0;
        al7C->unk_00 = 0;
        al7C->unk_78 = 0;
        al7C->unk_79 = i;
    }
    D_80078E54->unk_20 = alHeapAlloc(heap, config->unk_04, sizeof(*D_80078E54->unk_20));
    for (i = 0; i < config->unk_04; i++) {
        UnkAlLen18* temp = &D_80078E54->unk_20[i];
        temp->unk_10 = 0;
        temp->unk_14 = 0;
        temp->unk_00 = 0x7FFF;
        temp->unk_0C = 0;
        temp->unk_04 = alHeapAlloc(heap, 1, sizeof(*temp->unk_04));
        temp->unk_08 = alHeapAlloc(heap, 1, sizeof(*temp->unk_08));
        func_80058E84(temp->unk_04, temp->unk_0C, heap);
        func_80058E84(temp->unk_08, temp->unk_0C, heap);
    }


    D_80078E54->unk_24 = alHeapAlloc(heap, 0x170, 2);
    D_80078E54->unk_28 = alHeapAlloc(heap, 0x170, 2);
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FF0 = 4;

    D_800A3FE0 = alHeapAlloc(heap, 0x2E0, 2);
    D_800A3FE4 = alHeapAlloc(heap, 0x2E0, 2);
    for (i = 0; i < 0x2E0; i++) {
        D_800A3FE4[i] = D_800A3FE0[i] = 0;
    }

    D_80078E54->heap = heap;
}

void func_800565A4(void) {
    if (D_80078E50 != NULL) {
        D_80078E50 = NULL;
    }
}

INCLUDE_ASM(Acmd*, "31650", alAudioFrame, Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen);

void func_80056D34(void) {
    D_80078E58 = 1;
}

void func_80056D44(s16 arg0) {
    D_80078E5A = arg0;
}

s16 func_80056D50(void) {
    return D_80078E5A;
}

#ifdef NON_MATCHING
void func_80056D5C(s8 arg0) {
    D_80078181 = arg0;
    D_80078E5C = 1;
}
#else
INCLUDE_ASM(s32, "31650", func_80056D5C);
#endif

void func_80056D78(u8 arg0, u16 arg1) {
    UnkAlLen18* temp = &D_80078E54->unk_20[arg0];

    temp->unk_00 = arg1 & 0x7FFF;
}

u16 func_80056DA4(u8 arg0, u16 arg1) {
    UnkAlLen18* temp = &D_80078E54->unk_20[arg0];

    return temp->unk_00;
}

void func_80056DCC(u8 arg0, u8 arg1) {
    UnkAlLen18* temp = &D_80078E54->unk_20[arg0];

    temp->unk_0C = arg1;
    func_8005904C(temp->unk_04, arg1);
    func_8005904C(temp->unk_08, arg1);
}

void func_80056E34(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    UnkAlLen18* temp_s0 = &D_80078E54->unk_20[arg0 & 0xFF];
    
    func_800598A0(temp_s0->unk_04, arg1, arg2, arg3);
    func_800598A0(temp_s0->unk_08, arg1, arg2, arg3);
}

void func_80056EC0(u8 arg0, s8 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_78 = arg1;
}

INCLUDE_ASM(void, "31650", func_80056EE8, u8 arg0);

void func_80056F78(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_70 = 1;
}

INCLUDE_ASM(void, "31650", func_80056FA4, u8 arg0, u8 arg1, s32 arg2, f32 arg3, s16 arg4, u8 arg5, u8 arg6,
            s32 arg7);

INCLUDE_ASM(void, "31650", func_80057224, u8 arg0, Instrument* arg1);

void func_80057344(u8 arg0, f32 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_3C = arg1;
}

void func_8005736C(u8 arg0, s16 arg1, s32 arg2, u8 arg3, u8 arg4) {
    UnkAl7C* temp_s0 = &D_80078E54->unk_1C[arg0];
    UnkStruct80057874* temp_s1 = (UnkStruct80057874*)&temp_s0->unk_48;
    
    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[0x7F - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }
    
    temp_s1->unk_1C = 0;
    temp_s1->unk_20 = arg2;
    temp_s1->unk_04 = arg3;
    temp_s1->unk_06 = SQ(arg1) >> 0xF;
    temp_s1->unk_0C = AlCosineBlend[arg4];
    temp_s1->unk_0E = AlCosineBlend[0x7F - arg4];
    temp_s1->unk_24 = 1;
}

void func_80057548(u8 arg0, u8 arg1, u8 arg2) {
    UnkAl7C* temp_s0 = &D_80078E54->unk_1C[arg0];
    UnkStruct80057874* temp_s1 = (UnkStruct80057874*)&temp_s0->unk_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[0x7F - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_04 = arg1;
    temp_s1->unk_0C = AlCosineBlend[arg2];
    temp_s1->unk_0E = AlCosineBlend[0x7F - arg2];
    temp_s1->unk_24 = 1;
}

void func_800576EC(u8 arg0, s16 arg1, s32 arg2) {
    UnkAl7C* temp_s0 = &D_80078E54->unk_1C[arg0];
    UnkStruct80057874* temp_s1 = (UnkStruct80057874*)&temp_s0->unk_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[0x7F - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
        
    }

    temp_s1->unk_06 = SQ(arg1) >> 0xF;
    temp_s1->unk_1C = 0;
    temp_s1->unk_20 = arg2;
    temp_s1->unk_24 = 1;
}

void func_80057874(u8 arg0, u8 arg1) {
    UnkAl7C* temp_s0 = &D_80078E54->unk_1C[arg0];
    UnkStruct80057874* temp_s1 = (UnkStruct80057874*)&temp_s0->unk_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
        } else {
            temp_s0->unk_50 = (temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF;
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[127 - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_04 = arg1;
    temp_s1->unk_24 = 1;
}

void func_800579D8(u8 arg0, u8 arg1) {
    UnkAl7C* temp_s0 = &D_80078E54->unk_1C[arg0];
    UnkStruct80057874* temp_s1 = (UnkStruct80057874*)&temp_s0->unk_48;

    if (temp_s0->unk_64 >= temp_s0->unk_68) {
        temp_s0->unk_64 = temp_s0->unk_68;
        if (D_80078181 == 0) {
            temp_s0->unk_50 = ((temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF);
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[64]) >> 0xF;
        } else {
            temp_s0->unk_50 = ((temp_s0->unk_4E * AlCosineBlend[temp_s0->unk_4C]) >> 0xF);
            temp_s0->unk_52 = (temp_s0->unk_4E * AlCosineBlend[0x7F - temp_s0->unk_4C]) >> 0xF;
        }
    } else {
        temp_s0->unk_50 = func_80058004(temp_s0->unk_50, temp_s0->unk_64, temp_s0->unk_5A, temp_s0->unk_58);
        temp_s0->unk_52 = func_80058004(temp_s0->unk_52, temp_s0->unk_64, temp_s0->unk_60, temp_s0->unk_5E);
    }
    if (temp_s1->unk_08 == 0) {
        temp_s1->unk_08 = 1;
    }
    if (temp_s1->unk_0A == 0) {
        temp_s1->unk_0A = 1;
    }

    temp_s1->unk_0C = AlCosineBlend[arg1];
    temp_s1->unk_0E = AlCosineBlend[0x7F - arg1];
    temp_s1->unk_24 = 1;
}

s32 func_80057B64(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_70;
}

s32 func_80057B8C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_78;
}

f32 func_80057BB4(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_3C;
}

u8 func_80057BDC(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_4C_s.unk_4D;
}

s16 func_80057C04(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_54;
}

s16 func_80057C2C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_56;
}

s32 func_80057C54(s32 arg0) {
    UnkAl7C* temp_v1;
    u32 retVal;
    
    temp_v1 = &D_80078E54->unk_1C[arg0 & 0xFF];
    if (temp_v1->unk_64 >= temp_v1->unk_68) {
        if (D_80078181 == 0) {
            retVal = (temp_v1->unk_4E * AlCosineBlend[64] * 2) >> 0x10;
        } else {
            retVal = (temp_v1->unk_4E * AlCosineBlend[temp_v1->unk_4C] * 2) >> 0x10;
        }
    } else {
        retVal = func_80058004(temp_v1->unk_50, temp_v1->unk_64, temp_v1->unk_5A, temp_v1->unk_58);
    }
    return retVal;
}

s32 func_80057D0C(s32 arg0) {
    UnkAl7C* temp_v1;
    u32 retVal;
    
    temp_v1 = &D_80078E54->unk_1C[arg0 & 0xFF];
    if (temp_v1->unk_64 >= temp_v1->unk_68) {
        if (D_80078181 == 0) {
            retVal = (temp_v1->unk_4E * AlCosineBlend[64] * 2) >> 0x10;
        } else {
            retVal = ((temp_v1->unk_4E * AlCosineBlend[0x7F - temp_v1->unk_4C]) * 2) >> 0x10;
        }
    } else {
        retVal = func_80058004(temp_v1->unk_50, temp_v1->unk_64, temp_v1->unk_5A, temp_v1->unk_58);
    }
    return retVal;
}

void func_80057DC8(s32 arg0) {
    if (arg0 < 2) {
        D_800A3FF0 = 0;
        D_800A3FEE = 0;
    }

    D_800A3FF0 = arg0;
    if (arg0 >= 5) {
        D_800A3FF0 = 4;
    }
}

void func_80057E08(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 1;
    D_800A3FE8 = 0;
}

void func_80057E5C(u8 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0;
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = arg0;
    D_800A3FEE = 2;
    D_800A3FE8 = 0;
}

void func_80057EB0(void) {
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FE8 = 0;
}

void func_80057ED0(s16 arg0) {
    s32* phi_a1 = (s32*)D_800A3FE0; 
    s32* phi_v1 = (s32*)D_800A3FE4;
    s32 i;

    for (i = 0; i < 0x170; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    D_800A3FEC = 0;
    D_800A3FEE = arg0;
    D_800A3FE8 = 0;
}

void alHeapInit(ALHeap* hp, u8* base, s32 len) {
    u32 i;
    s32 alignBytes = 0x10 - ((s32)base & 0xF);

    if (alignBytes != 0x10) {
        hp->base = base + alignBytes;
    } else {
        hp->base = base;
    }
    hp->len = len;
    hp->count = 0;
    hp->cur = hp->base;

    for (i = 0; i < (u32)(hp->len) >> 2; i++) {
        ((u32*)hp->base)[i] = 0;
    }
}

void* alHeapAlloc(ALHeap* heap, s32 arg1, s32 size) {
    void* ret = NULL;
    u8* newCur = &heap->cur[ALIGN16(arg1 * size)];

    if (&heap->base[heap->len] >= newCur) {
        ret = heap->cur;
        heap->cur = newCur;
    }

    return ret;
}

void alCopy(void* src, void* dst, s32 size) {
    s32 i;
    u8* srcIt = src;
    u8* dstIt = dst;

    for (i = 0; i < size; i++) {
        *dstIt++ = *srcIt++;
    }
}

s16 func_80058004(s16 arg0, s32 arg1, s16 arg2, u16 arg3) {
    s32 c;
    arg1 = arg1 >> 3;
    if (arg1 == 0) {
        return arg0;
    }
    c = arg3 * arg1;
    c = c >> 0x10;
    return arg0 + (c + arg2 * arg1);
}
