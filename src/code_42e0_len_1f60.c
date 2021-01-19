#include "common.h"
#include "nu/nusys.h"

// TODO: replace nustuff with defines

extern u16 D_80074260;
extern s32 D_80074264;

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

//INCLUDE_ASM(s32, "code_42e0_len_1f60", func_80028F8C);
void func_80028F8C(void) {
    s32* sym = &D_80074264;
    u16* sym2;

    if (*sym != GAME_STATUS->currentButtons) {
        *sym = GAME_STATUS->currentButtons;
        func_80028FE0();
    }

    sym2 = &D_80074260;
    if (*sym2 != 0) {
        (*sym2)--;
    }
}

// needs data
#ifdef NON_MATCHING
void func_80028FE0(void) {
    D_80074260 = 300;
}
#else
INCLUDE_ASM(void, "code_42e0_len_1f60", func_80028FE0);
#endif

f32 length2D(f32 x, f32 y) {
    return sqrtf(SQ(x) + SQ(y));
}

HeapNode* _heap_create(s32* addr, u32 size) {
    if (size < 32) {
        return (HeapNode*) - 1;
    } else {
        HeapNode* heapNode = ALIGN16((s32)addr);

        size -= ((char*)heapNode - (char*)addr);
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
        return -(s32) (0.5 - arg0);
    } else {
        return (s32) (0.5 + arg0);
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

INCLUDE_ASM(s32, "code_42e0_len_1f60", _wrap_trig_lookup_value);

INCLUDE_ASM(void, "code_42e0_len_1f60", sin_cos_rad, f32 rad, f32* outSinTheta, f32* outCosTheta);

INCLUDE_ASM(f32, "code_42e0_len_1f60", sin_rad, f32 angle);

INCLUDE_ASM(f32, "code_42e0_len_1f60", cos_rad, f32 angle);
/*
f32 cos_rad(f32 angle) {
    return (coss((u16)_wrap_trig_lookup_value(angle * 10430.378f)) * 3.051851e-05);
}
*/

INCLUDE_ASM(s32, "code_42e0_len_1f60", sin_cos_deg);

INCLUDE_ASM(f32, "code_42e0_len_1f60", sin_deg, f32 x);

INCLUDE_ASM(f32, "code_42e0_len_1f60", cos_deg, f32 x);

INCLUDE_ASM(f32, "code_42e0_len_1f60", update_lerp, Easing easing, f32 start, f32 end, s32 elapsed, s32 duration);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002A904);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AAC4);

INCLUDE_ASM(s32, "code_42e0_len_1f60", func_8002AB5C);
