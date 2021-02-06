#include "common.h"
#include "nu/nusys.h"

// TODO: replace nustuff with defines

u16 D_80074260 = 0;
s32 D_80074264 = 0;

// probably padding
s32 D_80074268[2] = {0, 0};

s32 D_80074270 = 0;

f32 D_80074274[] = {
    0.0f, 0.017452f, 0.034899f, 0.052336f, 0.069756f, 0.087156f, 0.104528f, 0.121869f, 0.139173f,
    0.156434f, 0.173648f, 0.190809f, 0.207912f, 0.224951f, 0.241922f, 0.258819f, 0.275637f, 0.292372f, 0.309017f,
    0.325568f, 0.34202f, 0.358368f, 0.374607f, 0.390731f, 0.406737f, 0.422618f, 0.438371f, 0.45399f, 0.469472f,
    0.48481f, 0.5f, 0.515038f, 0.529919f, 0.544639f, 0.559193f, 0.573576f, 0.587785f, 0.601815f, 0.615661f, 0.62932f,
    0.642788f, 0.656059f, 0.669131f, 0.681998f, 0.694658f, 0.707107f, 0.71934f, 0.731354f, 0.743145f, 0.75471f,
    0.766044f, 0.777146f, 0.788011f, 0.798636f, 0.809017f, 0.819152f, 0.829038f, 0.838671f, 0.848048f, 0.857167f,
    0.866025f, 0.87462f, 0.882948f, 0.891007f, 0.898794f, 0.906308f, 0.913545f, 0.920505f, 0.927184f, 0.93358f,
    0.939693f, 0.945519f, 0.951057f, 0.956305f, 0.961262f, 0.965926f, 0.970296f, 0.97437f, 0.978148f, 0.981627f,
    0.984808f, 0.987688f, 0.990268f, 0.992546f, 0.994522f, 0.996195f, 0.997564f, 0.99863f, 0.999391f, 0.999848f, 1.0f
};

s8 D_800743E0[] = {
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
    0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 gRandSeed = 1;

f32 D_80074414[] = {
    1.0f, 1.273187f, 1.27303f, 1.272768f, 1.272402f, 1.271932f, 1.271358f, 1.270681f, 1.269902f, 1.269021f, 1.268038f,
    1.266956f, 1.265774f, 1.264494f, 1.263116f, 1.261643f, 1.260075f, 1.258413f, 1.256659f, 1.254815f, 1.252881f,
    1.250859f, 1.248752f, 1.24656f, 1.244285f, 1.241929f, 1.239494f, 1.236981f, 1.234393f, 1.231731f, 1.228997f,
    1.226192f, 1.22332f, 1.220382f, 1.217379f, 1.214315f, 1.211189f, 1.208006f, 1.204766f, 1.201471f, 1.198124f,
    1.194727f, 1.191281f, 1.187787f, 1.18425f, 1.180669f, 1.177047f, 1.173386f, 1.169687f, 1.165952f, 1.162184f,
    1.158384f, 1.154553f, 1.150693f, 1.146806f, 1.142893f, 1.138957f, 1.134998f, 1.131018f, 1.127019f, 1.123002f,
    1.118969f, 1.11492f, 1.110858f, 1.106783f, 1.102697f, 1.098601f, 1.094496f, 1.090384f, 1.086266f, 1.082142f,
    1.078014f, 1.073883f, 1.06975f, 1.065616f, 1.061482f, 1.057348f, 1.053216f, 1.049087f, 1.04496f, 1.040838f,
    1.036721f, 1.03261f, 1.028504f, 1.024406f, 1.020316f, 1.016234f, 1.01216f, 1.008097f, 1.004043f, 1.0f
};

Gfx D_80074580[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

void sin_cos_rad(f32 rad, f32* outSinTheta, f32* outCosTheta);
void func_80029860(s32 romStart, s32 vramDest, s32 length);

#define ROM_CHUNK_SIZE 0x2000

void poll_rumble(void) {
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

void start_rumble(s32 freq, s32 frame) {
    if (GAME_STATUS->demoState == 0) {
        u16* sym = &D_80074260;

        if (*sym != 0) {
            s32 symx2 = *sym * 2;

            if (frame > symx2) {
                frame = symx2;
            }

            if (nuContRmbCheck(0) == 0) {
                nuContRmbModeSet(0, 2);
                nuContRmbStart(0, freq, frame);
            }
        }
    }
}

void update_max_rumble_duration(void) {
    s32* sym = &D_80074264;
    u16* sym2;

    if (*sym != GAME_STATUS->currentButtons) {
        *sym = GAME_STATUS->currentButtons;
        reset_max_rumble_duration();
    }

    sym2 = &D_80074260;
    if (*sym2 != 0) {
        (*sym2)--;
    }
}

void reset_max_rumble_duration(void) {
    D_80074260 = 300;
}

f32 length2D(f32 x, f32 y) {
    return sqrtf(SQ(x) + SQ(y));
}

HeapNode* _heap_create(s32* addr, u32 size) {
    if (size < 32) {
        return (HeapNode*) - 1;
    } else {
        HeapNode* heapNode = ALIGN16((s32)addr);

        size -= ((s8*)heapNode - (s8*)addr);
        heapNode->next = NULL;
        heapNode->length = size - sizeof(HeapNode);
        heapNode->allocated = 0;
        heapNode->capacity = size;
        return heapNode;
    }
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_malloc);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_malloc_tail);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_free);

INCLUDE_ASM(s32, "code_42e0_len_1f60", _heap_realloc);

INCLUDE_ASM(s32, "code_42e0_len_1f60", cosine);

s32 sign(s32 val) {
    s32 sign = -1;

    if (val >= 0) {
        sign = val > 0;
    }
    return sign;
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", int_to_string);

// should maybe be called bzero
void mem_clear(s8* data, s32 numBytes) {
    while (numBytes > 0) {
        *data = 0;
        data++;
        numBytes--;
    }
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", transform_point);

void copy_matrix(Matrix4f* src, Matrix4f* dest) {
    bcopy(src, dest, sizeof(Matrix4f));
}

s32 dma_copy(s32 romStart, s32 romEnd, void* vramDest) {
    u32 length = romEnd - romStart;
    s32 i;

    osInvalICache(vramDest, length);

    for (i = 0; i + ROM_CHUNK_SIZE < length; i += ROM_CHUNK_SIZE) {
        nuPiReadRom(romStart + i, vramDest + i, ROM_CHUNK_SIZE);
    }

    if (i != length) {
        nuPiReadRom(romStart + i, vramDest + i, length - i);
    }

    return length;
}

s32 func_800297D4(s32 romStart, s32 romEnd, void* vramDest) {
    u32 length = romEnd - romStart;
    s32 i;

    for (i = 0; i + ROM_CHUNK_SIZE < length; i += ROM_CHUNK_SIZE) {
        func_80029860(romStart + i, vramDest + i, ROM_CHUNK_SIZE);
    }

    if (i != length) {
        func_80029860(romStart + i, vramDest + i, length - i);
    }

    return length;
}

INCLUDE_ASM(void, "code_42e0_len_1f60", func_80029860, s32 romStart, s32 vramDest, s32 length);

s32 _advance_rng(void) {
    s32* rngVal = &gRandSeed;

    GAME_STATUS->nextRNG = *rngVal = (*rngVal * 0x5D588B65) + 1;

    return *rngVal;
}

f32 func_80029934(void) {
    s32 temp_v0 = _advance_rng() & 0x7FFF;
    f64 temp_f2 = temp_v0;

    if (temp_v0 < 0) {
        temp_f2 += 4294967296.0;
    }

    return temp_f2 * 3.0517578125e-05;
}

s32 func_80029994(s32 arg0) {
    u32 div = -1;
    s32 plusOne = arg0 + 1;
    u32 result;

    div /= plusOne;
    if (div == 0) {
        div = 1;
    }

    do  {
        result = _advance_rng() / div;
    } while (result >= plusOne);

    return result;
}

INCLUDE_ASM(s32, "code_42e0_len_1f60", rand_int, s32 arg0);

f32 signF(f32 val) {
    f32 sign;

    if (!(val > 0.0f)) {
        sign = -1.0f;
        if (!(val < 0.0f)) {
            sign = 0.0f;
        }
    } else {
        sign = 1.0f;
    }

    return sign;
}

s32 round(f32 arg0) {
    if (!(arg0 >= 0.0f)) {
        return -(s32)(0.5 - arg0);
    } else {
        return (s32)(0.5 + arg0);
    }
}

INCLUDE_ASM(f32, "code_42e0_len_1f60", clamp_angle, f32 theta);

f32 get_clamped_angle_diff(f32 a, f32 b) {
    if (fabsf(b - a) >= 180.0f) {
        if (b < a) {
            b += 360.0f;
        } else {
            b -= 360.0f;
        }
    }
    return b - a;
}

INCLUDE_ASM(f32, "code_42e0_len_1f60", atan2, f32 startX, f32 startZ, f32 endX, f32 endZ);

f32 get_player_normal_yaw(void) {
    return atan2(0, 0, GAME_STATUS->playerTraceNormal.x, GAME_STATUS->playerTraceNormal.z);
}

f32 get_player_normal_pitch(void) {
    f32 traceNormalX = GAME_STATUS->playerTraceNormal.x;
    f32 traceNormalZ = GAME_STATUS->playerTraceNormal.z;
    f32 sqrt = sqrtf(SQ(traceNormalX) + SQ(traceNormalZ));

    return atan2(0.0f, 0.0f, sqrt, -GAME_STATUS->playerTraceNormal.y);
}

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;

    return sqrtf(SQ(xDiff) + SQ(yDiff));
}

f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;
    f32 zDiff = bz - az;

    return sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
}

void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta) {
    f32 sinTheta;
    f32 cosTheta;

    sin_cos_rad((theta * 6.28318f) / 360.0f, &sinTheta, &cosTheta);
    *x += r * sinTheta;
    *y -= r * cosTheta;
}

u16 _wrap_trig_lookup_value(f32 theta) {
    f32 ret = theta;

    if (theta >= 1048576.0f || theta <= -1048576.0f) {
        ret = theta * 0.0000009536743f;
        ret = theta - ((s32) ret) * 1048576.0f;
    }

    return (s32) ret;
}

void sin_cos_rad(f32 rad, f32* outSinTheta, f32* outCosTheta) {
    u16 theta = _wrap_trig_lookup_value(rad * 10430.378f);

    *outSinTheta = sins(theta) * 3.051851e-05;
    *outCosTheta = coss(theta) * 3.051851e-05;
}

f32 sin_rad(f32 angle) {
    return sins(_wrap_trig_lookup_value(angle * 10430.378f)) * 3.051851e-05;
}

f32 cos_rad(f32 angle) {
    return coss(_wrap_trig_lookup_value(angle * 10430.378f)) * 3.051851e-05;
}

void sin_cos_deg(f32 rad, f32* outSinTheta, f32* outCosTheta) {
    u16 theta = _wrap_trig_lookup_value(rad * 182.04445f);

    *outSinTheta = sins(theta) * 3.051851e-05;
    *outCosTheta = coss(theta) * 3.051851e-05;
}

f32 sin_deg(f32 angle) {
    return sins(_wrap_trig_lookup_value(angle * 182.04445f)) * 3.051851e-05;
}

f32 cos_deg(f32 angle) {
    return coss(_wrap_trig_lookup_value(angle * 182.04445f)) * 3.051851e-05;
}

INCLUDE_ASM(f32, "code_42e0_len_1f60", update_lerp, Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002A904);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AAC4);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AB5C);
